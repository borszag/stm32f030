/* Setting undefined handlers to the default */
PROVIDE(Handler_NMI	                    = Handler_Default);
PROVIDE(Handler_HardFault               = Handler_Default);
PROVIDE(Handler_SVC                     = Handler_Default);
PROVIDE(Handler_PendSV                  = Handler_Default);
PROVIDE(Handler_SysTick                 = Handler_Default);
PROVIDE(Handler_IRQ_WWDG                = Handler_Default);
PROVIDE(Handler_IRQ_RTC                 = Handler_Default);
PROVIDE(Handler_IRQ_FLASH               = Handler_Default);
PROVIDE(Handler_IRQ_RCC                 = Handler_Default);
PROVIDE(Handler_IRQ_EXTI0_1             = Handler_Default);
PROVIDE(Handler_IRQ_EXTI2_3             = Handler_Default);
PROVIDE(Handler_IRQ_EXTI4_15            = Handler_Default);
PROVIDE(Handler_IRQ_DMA1_Channel1       = Handler_Default);
PROVIDE(Handler_IRQ_DMA1_Channel2_3     = Handler_Default);
PROVIDE(Handler_IRQ_DMA1_Channel4_5     = Handler_Default);
PROVIDE(Handler_IRQ_ADC1                = Handler_Default);
PROVIDE(Handler_IRQ_TIM1_BRK_UP_TRG_COM = Handler_Default);
PROVIDE(Handler_IRQ_TIM1_CC             = Handler_Default);
PROVIDE(Handler_IRQ_TIM3                = Handler_Default);
PROVIDE(Handler_IRQ_TIM14               = Handler_Default);
PROVIDE(Handler_IRQ_TIM16               = Handler_Default);
PROVIDE(Handler_IRQ_TIM17               = Handler_Default);
PROVIDE(Handler_IRQ_I2C1                = Handler_Default);
PROVIDE(Handler_IRQ_SPI1                = Handler_Default);
PROVIDE(Handler_IRQ_USART1              = Handler_Default);

/* Entry Point */
ENTRY(Handler_Reset)

/* Highest address of the user mode stack */
_estack = ORIGIN(RAM) + LENGTH(RAM);    /* end of RAM */
/* Generate a link error if stack with given size doesn't fit into RAM */
_Min_Stack_Size = 0x0400; /* required amount of stack */

/* Specify the memory areas */
MEMORY
{
FLASH (rx)     : ORIGIN = 0x08000000, LENGTH = 16K
RAM (xrw)      : ORIGIN = 0x20000000, LENGTH = 4K

/* Cortex-M0 core peripherals */
STK(rw)        : ORIGIN = 0xE000E010, LENGTH = 16
NVIC(rw)       : ORIGIN = 0xE000E100, LENGTH = 1K
SCB(rw)        : ORIGIN = 0xE000ED00, LENGTH = 36

/* Peripherals */
I2C1(rw)       : ORIGIN = 0x40005400, LENGTH = 1K
SPI1(rw)       : ORIGIN = 0x40013000, LENGTH = 1K
RCC(rw)        : ORIGIN = 0x40021000, LENGTH = 1K
GPIOA(rw)      : ORIGIN = 0x48000000, LENGTH = 1K
GPIOB(rw)      : ORIGIN = 0x48000400, LENGTH = 1K
GPIOC(rw)      : ORIGIN = 0x48000800, LENGTH = 1K
GPIOD(rw)      : ORIGIN = 0x48000C00, LENGTH = 1K
GPIOF(rw)      : ORIGIN = 0x48001400, LENGTH = 1K
}

/* Define output sections */
SECTIONS
{    
  /* The interrupt service routine vector goes first into FLASH */
  .isr_vector :
  {
    /* Stack start */
    . = 0x00;
    LONG(_estack)
    /* Placing the addresses into the ISR vector with LSB set 1 for THUMB */
    . = 0x04;
    LONG(Handler_Reset | 1)
    . = 0x08;
    LONG(Handler_NMI | 1)
    . = 0x0C;
    LONG(Handler_HardFault | 1)
    . = 0x2C;
    LONG(Handler_SVC | 1)
    . = 0x38;
    LONG(Handler_PendSV | 1)
    . = 0x3C;
    LONG(Handler_SysTick | 1)
    . = 0x40;
    LONG(Handler_IRQ_WWDG | 1)
    . = 0x48;
    LONG(Handler_IRQ_RTC | 1)
    . = 0x4C;
    LONG(Handler_IRQ_FLASH | 1)
    . = 0x50;
    LONG(Handler_IRQ_RCC | 1)
    . = 0x54;
    LONG(Handler_IRQ_EXTI0_1 | 1)
    . = 0x58;
    LONG(Handler_IRQ_EXTI2_3 | 1)
    . = 0x5C;
    LONG(Handler_IRQ_EXTI4_15 | 1)
    . = 0x64;
    LONG(Handler_IRQ_DMA1_Channel1 | 1)
    . = 0x68;
    LONG(Handler_IRQ_DMA1_Channel2_3 | 1)
    . = 0x6C;
    LONG(Handler_IRQ_DMA1_Channel4_5 | 1)
    . = 0x70;
    LONG(Handler_IRQ_ADC1 | 1)
    . = 0x74;
    LONG(Handler_IRQ_TIM1_BRK_UP_TRG_COM | 1)
    . = 0x78;
    LONG(Handler_IRQ_TIM1_CC | 1)
    . = 0x80;
    LONG(Handler_IRQ_TIM3 | 1)
    . = 0x8C;
    LONG(Handler_IRQ_TIM14 | 1)
    . = 0x94;
    LONG(Handler_IRQ_TIM16 | 1)
    . = 0x98;
    LONG(Handler_IRQ_TIM17 | 1)
    . = 0x9C;
    LONG(Handler_IRQ_I2C1 | 1)
    . = 0xA4;
    LONG(Handler_IRQ_SPI1 | 1)
    . = 0xAC;
    LONG(Handler_IRQ_USART1 | 1)
  } > FLASH

  /* The program code and other data goes into FLASH */
  .text :
  {
    . = ALIGN(4);
    KEEP(*(.text.handler*))
    *(.text*)
    *(.text)
    . = ALIGN(4);
  } > FLASH
  
  /* Constants and otherwise read only data */
  .rodata :
  {
    . = ALIGN(4);
    *(.rodata*)
    *(.rodata)
    . = ALIGN(4);
  } > FLASH

  /* Non zero initialized data */
  .data :
  {
    . = ALIGN(4);
    _sdata = .;
    *(.data*)
    *(.data)
    . = ALIGN(4);
    _edata = .;
  } > RAM AT> FLASH
  _idata = LOADADDR(.data);

  /* Zero initialized data */
  .bss (NOLOAD) :
  {
    . = ALIGN(4);
    _sbss = .;
    *(.bss*)
    *(.bss)
    . = ALIGN(4);
    _ebss = .;
  } > RAM
  _lbss = _ebss - _sbss;
  
  /* Ensure a minimal stack size by allocation */
  ._user_stack :
  {
   . = ALIGN(4);
   . += _Min_Stack_Size;
   . = ALIGN(4);
  } > RAM

/*************** CORTEX-M0 CORE PERIPHERALS **********************************/

  .stk (NOLOAD) :
  {
    *(.stk)
  } > STK

  .nvic (NOLOAD) :
  {
    *(.nvic)
  } > NVIC

  .scb (NOLOAD) :
  {
    *(.scb)
  } > SCB

/*************** PERIPHERALS *************************************************/

  .i2c1 (NOLOAD) :
  {
    *(.i2c1)
  } > I2C1

  .spi1 (NOLOAD) :
  {
    *(.spi1)
  } > SPI1

  .rcc (NOLOAD) :
  {
    *(.rcc)
  } > RCC

  .gpioa (NOLOAD) :
  {
    *(.gpioa)
  } > GPIOA

  .gpiob (NOLOAD) :
  {
    *(.gpiob)
  } > GPIOB

  .gpioc (NOLOAD) :
  {
    *(.gpioc)
  } > GPIOC

  .gpiod (NOLOAD) :
  {
    *(.gpiod)
  } > GPIOD

  .gpiof (NOLOAD) :
  {
    *(.gpiof)
  } > GPIOF
}
