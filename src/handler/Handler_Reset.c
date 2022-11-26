#include <stdint.h>
#include "handler/util.h"
#include "hal/rcc.h"
#include "hal/gpio.h"

HANDLER void Handler_Reset(void) {

  // Initializing .data section
  {
    extern uint32_t _idata;
    extern uint32_t _sdata;
    extern uint32_t _edata;
    uint32_t *dst = &_sdata;
    uint32_t *src = &_idata;
    while (dst < &_edata) {
      *dst++ = *src++;
    }
  }
  
  // Clearing .bss section
  {
    extern uint32_t _sbss;
    extern uint32_t _ebss;
    uint32_t *dst = &_sbss;
    while (dst < &_ebss) {
      *dst++ = 0;
    }
  }

  rcc.ahbenr.iopaen  = 1;
  gpioa.moder.moder4 = 1;

  volatile int32_t i = 0;
  while(1) {
    for (i = 0; i < 70000; ++i);
    gpioa.odr.odr4 = !gpioa.odr.odr4;
  }

  // It is recommended to put an infinite loop at the end of this
  // function to avoid a return from it because there is nowhere to
  // return to.
  while(1) {
    //asm("nop");
  }
}
