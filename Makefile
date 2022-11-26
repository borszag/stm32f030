# Project structure
INCDIR = inc
SRCDIR = src
OBJDIR = build

# Input and output linker files
LDSCRIPT = layout.ld
LDMAP    = $(OBJDIR)/linker.map

# Flags for compilation and linking
CFLAGS  = -mthumb -mcpu=cortex-m0 -flto -ffunction-sections -fno-builtin -I$(INCDIR) -Os -Wall -Wextra
LDFLAGS = -nostdlib -Wl,--gc-sections,-Map=$(LDMAP) -flto -fwhole-program

# Output files
EXE = $(OBJDIR)/fw.elf
APP = $(OBJDIR)/fw.hex

## Rules and rarely modified things ###########################################
# Compiler prefix
PREFIX = arm-none-eabi-

# Tools
CC  = $(PREFIX)gcc
AS  = $(PREFIX)as
LD  = $(PREFIX)gcc
CP  = $(PREFIX)objcopy
SZ  = $(PREFIX)size -A
HEX = $(CP) -O ihex


# List of subdirectories
TMPDIRS = $(wildcard $(SRCDIR)/*/.)
OBJDIRS = $(OBJDIR) $(TMPDIRS:$(SRCDIR)/%/.=$(OBJDIR)/%)

# List of assembly and C source files
ASRCS = $(wildcard $(SRCDIR)/*.s) $(wildcard $(SRCDIR)/*/*.s)
CSRCS = $(wildcard $(SRCDIR)/*.c) $(wildcard $(SRCDIR)/*/*.c)

# List of object files
AOBJS   = $(ASRCS:$(SRCDIR)/%.s=$(OBJDIR)/%.o)
COBJS   = $(CSRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
OBJECTS = $(AOBJS) $(COBJS)

# Generate dependency information
CFLAGS += -MMD -MP -MF"$(@:%.o=%.d)"

## Building the firmware
$(APP) : $(EXE)
	$(HEX) $(EXE) $@

$(EXE) : $(OBJECTS) $(LDSCRIPT) | $(OBJDIRS)
	$(LD) $(LDFLAGS) -T$(LDSCRIPT) $(OBJECTS) -o $@
	$(SZ) -x $@

$(OBJDIR)/%.o : $(SRCDIR)/%.s Makefile | $(OBJDIRS)
	$(AS) -c $< -o $@

$(OBJDIR)/%.o : $(SRCDIR)/%.c Makefile | $(OBJDIRS)
	$(CC) -c $(CFLAGS) $< -o $@

$(OBJDIRS) :
	mkdir $@

## Cleaning up
.PHONY : all clean
all    : $(APP)

clean  :
	rm -fr $(OBJDIR)

## Dependencies
-include $(wildcard $(OBJDIR)/*.d)
-include $(wildcard $(OBJDIR)/*/*.d)
