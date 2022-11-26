# stm32f030
A bare-bones firmware project for an STM32F030F4P6 microcontroller.

## Introduction
The sole purpose of this repo is to provide a (somewhat) easily usable
framework written in nonstandard C[^cstd] to create applications for
STM32F030 microcontrollers (MCUs). Nevertheless, it can be ported to
other ARM Cortex-M0/Cortex-M0+ based MCUs (or to any architecture in
the M family for that matter) with a couple of small modifications. The
most significant task is the rewrite of the linker script for the new
memory layout (flash, RAM, peripherals, etc.) and the update of the
hardware abstraction layer (HAL) include files which contain the
register layout of the peripherals. Fortunately this is only a matter
of good ol' RTFM.

It is important to note that this project is completely freestanding
which means there is not a single piece of code which is hidden from
the programmer, even those available without including system header
files (e.g memcpy, or crt0.o functions). This of course leaves the
responsibility of runtime initialization to the programmer (see
[Handler_Reset](./src/handler/Handler_Reset.c) for an example). Lucky
for us C is not demanding too much in that regard.

Another aspect of the project is that it is free from assembly source
files (but they can be added easily if needed). This can be achieved
because the Cortex-M architecture was (partly) built with C
compatibility in mind. For example the stack is ready for use right
from the beginning. For a little more insight read the following
section.

## Linker script
The heart of the project is the [linker script](./layout.ld), which is
heavily relied on by other parts of the firmware. Firstly, it is
responsible for creating the interrupt service routine (ISR) vector,
which contains all of the addresses of the ISRs and the stack. It uses
a somewhat special feature of ld called ``PROVIDE`` which can be used
to detect all of the implemented ISR handler functions. If the
implementation is missing then it will assign the default handler which
is usually a simple infinite loop. For more information on the ISR
vector see the relevant docs[^pm0215]. Be aware that the ISR addresses
must have their least significant bits (LSB) set to one to signal that
the Thumb instruction set architecture (ISA) is used to implement the
body of the functions (which is the only available one in the case of
Cortex-M0/Cortex-M0+)[^isa].

Aside from that it contains all the necessary information to avoid
explicit addresses in the code. This means that the relevant memory
areas are created (flash, RAM, peripherals) and the sections written to
them. If one would like to use peripherals then variables with matching
layout should be linked to special sections defined by the script. The
usual sections (i.e ``.text``, ``.rodata``, ``.data``, ``.bss``) are
present and in the case of the ``.data`` and ``.bss`` sections some
addresses are made visible for the source code to make their
initialization possible (see
[Handler_Reset](./src/handler/Handler_Reset.c) for an example). It is
necessary to link initialized variables into the RAM (where their
virtual memory address (VMA) is), but they must be loaded into the
flash (where their load memory address (LMA) is), so their values can
be retained between resets. The sections are aligned at 4 byte (word)
boundaries, which makes the copying more efficient.

To ensure that the size of the stack is sufficient a portion of the RAM
is reserved for that exact purpose in the ``.user_stack`` section. The
size can be chosen for the given application or left out altogether by
setting it to zero. There is no space allocated for a heap because
there is no standard library available. To circumvent this issue one
could create a large static array and write corresponding ``malloc``
and ``free`` functions which manages this array as a heap.

[^cstd]: The language features used are specified in C11, but for low
    level details and to avoid explicit addresses (and the standard C
    runtime) GCC attributes were used.

[^pm0215]: [PM0215](https://www.st.com/resource/en/programming_manual/pm0215-stm32f0xxx-cortexm0-programming-manual-stmicroelectronics.pdf)
    STM32F0xxx Cortex-M0 programming manual.

[^isa]: Cortex-M0/Cortex-M0+ processors use the ARMv6-M Thumb ISA.

## Build system
The build process is orchestrated by a [makefile](./Makefile). It was written with a
comfortable user experience in mind, so it explores the filesystem and
collects the source files and their dependencies automatically. This
gives a flexible way of organizing the project as one sees fit, and
refactoring can be done without touching the makefile.

There are a few restrictions on the directory structure though. All of
the source files should reside in a directory given by ``SRCDIR =
src``, and all of the header files in ``INCDIR = inc``. Furthermore all
of the build artifacts are generated in ``OBJDIR = build``, so only
this folder needs to be excluded from version control. Inside ``src``
the files must not be deeper in the directory tree than one, so for
example the path from the project root ``./src/main.c`` and
``./src/app/main.c`` is valid, but ``./src/hal/rcc/main.c`` is not.

The output files are the final binary in ELF and Intel HEX formats as
well as the map file generated by the linker (it might serve a great
help during debugging). The user might want to change the flags related
to compilation and linking, these are collected into ``CFLAGS`` and
``LDFLAGS``. As previously mentioned, the makefile searches for ASM
sources as well, but there are no flags given during their compilation,
but based on the C sources it is easy to extend the script.

For future reference and for completeness this section details the
flags needed for dependency generation. The first is ``-MMD`` which
ensures that the dependencies are searched on the fly, so they are
created right after the invocation of the compiler. ``-MP`` adds the
new rules as phony targets to prevent errors when a header is missing.
Finally ``-MF"$(@:%.o=%.d)"`` is used to write this information into a
file named just like the object file but with .d extension. To decode
the obscure rules just RTFM[^make].

[^make]: [GNU make](https://www.gnu.org/software/make/manual/make.html),
    it is recommended to skim through the sections on pattern rules and
    automatic variables.

## The C source code
For this part it is recommended to open the files itself and explore
them a bit. The most important thing to bear in mind is that one needs
to use ``__attribute__``s to link ISRs into the ``text.handler*``
section (* is a wildcard here), and it must be signaled that these
functions must be kept regardless of link time optimization (LTO), so
the ``used`` attribute must be given. This is helped by a macro in
[``handler/util.h``](./inc/handler/util.h).

The variables with the type of a struct describing the layout of
peripherals should be linked into their corresponding sections (whose
name can be found in the linker script). There is a macro to help in
[``hal/util.h``](./inc/hal/util.h), but its placement is rather
unusual, it should be right after the name of the variable (see
[``hal/rcc.c``](./src/hal/rcc.c) for an example).

The registers are handled in a special way because they are unions with
an ``uint32_t`` and an anonymous struct member[^cstruct]. This permits
the access of the whole register (i.e ``rcc.ahbenr.reg``), and its bits
(i.e ``rcc.ahbenr.iopaen``). This can be used to shave off a few
instructions when all of the bits are to be written simultenously, but
in the case when only a few needs to be modified then there is no need
for masking, because this is done by the compiler. The registers are
collected into struct which follows the layout of the peripheral, which
is rarely a continous region of memory so there is a ``RESERVED()``
macro in [``hal/util.h``](./inc/hal/util.h) which creates a struct
member array with ``uint32_t`` type named ``_reserved<lineno>[n]``,
where ``n`` is the size and ``<lineno>`` is the literal number of the
line where the macro was used. This is needed to ensure the uniqueness
of the members if there are more than one in a single struct.

[^cstruct]: Anonymous structs were introduced in [C11](https://en.cppreference.com/w/c/language/struct).