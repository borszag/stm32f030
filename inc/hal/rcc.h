#ifndef HAL_RCC_H
#define HAL_RCC_H

#include <stdint.h>
#include "hal/util.h"

typedef union {
  uint32_t reg;
  struct {
    uint32_t hsion   : 1;
    uint32_t hsirdy  : 1;
    uint32_t         : 1;
    uint32_t hsitrim : 5;
    uint32_t hsical  : 8;
    uint32_t hseon   : 1;
    uint32_t hserdy  : 1;
    uint32_t hsebyp  : 1;
    uint32_t csson   : 1;
    uint32_t         : 4;
    uint32_t pllon   : 1;
    uint32_t pllrdy  : 1;
    uint32_t         : 6;
  };
} rcc_cr_t;

typedef union {
  uint32_t reg;
  struct {
    uint32_t dmaen   :  1;
    uint32_t         :  1;
    uint32_t sramen  :  1;
    uint32_t         :  1;
    uint32_t flitfen :  1;
    uint32_t         :  1;
    uint32_t crcen   :  1;
    uint32_t         : 10;
    uint32_t iopaen  :  1;
    uint32_t iopben  :  1;
    uint32_t iopcen  :  1;
    uint32_t iopden  :  1;
    uint32_t         :  1;
    uint32_t iopfen  :  1;
    uint32_t         :  9;
  };
} rcc_ahbenr_t;

typedef union {
  uint32_t reg;
  struct {
    uint32_t  syscfgen : 1;
    uint32_t           : 4;
    uint32_t  usart6en : 1;
    uint32_t           : 3;
    uint32_t  adcen    : 1;
    uint32_t           : 1;
    uint32_t  tim1en   : 1;
    uint32_t  spi1en   : 1;
    uint32_t           : 1;
    uint32_t  usart1en : 1;
    uint32_t           : 1;
    uint32_t  tim15en  : 1;
    uint32_t  tim16en  : 1;
    uint32_t  tim17en  : 1;
    uint32_t           : 3;
    uint32_t  dbgmcuen : 1;
    uint32_t           : 9;
  };
} rcc_apb2enr_t;

typedef struct {
  rcc_cr_t     cr;
  RESERVED(4);
  rcc_ahbenr_t  ahbenr;
  rcc_apb2enr_t apb2enr;
} rcc_t;

extern volatile rcc_t rcc PERIPHERAL(rcc);
#endif
