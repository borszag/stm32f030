#ifndef HAL_GPIO
#define HAL_GPIO

#include <stdint.h>
#include "hal/util.h"

typedef union {
  uint32_t reg;
  struct {
    uint32_t moder0  : 2;
    uint32_t moder1  : 2;
    uint32_t moder2  : 2;
    uint32_t moder3  : 2;
    uint32_t moder4  : 2;
    uint32_t moder5  : 2;
    uint32_t moder6  : 2;
    uint32_t moder7  : 2;
    uint32_t moder8  : 2;
    uint32_t moder9  : 2;
    uint32_t moder10 : 2;
    uint32_t moder11 : 2;
    uint32_t moder12 : 2;
    uint32_t moder13 : 2;
    uint32_t moder14 : 2;
    uint32_t moder15 : 2;
  };
} gpiox_moder_t;


typedef union {
  uint32_t reg;
  struct {
    uint32_t odr0  :  1;
    uint32_t odr1  :  1;
    uint32_t odr2  :  1;
    uint32_t odr3  :  1;
    uint32_t odr4  :  1;
    uint32_t odr5  :  1;
    uint32_t odr6  :  1;
    uint32_t odr7  :  1;
    uint32_t odr8  :  1;
    uint32_t odr9  :  1;
    uint32_t odr10 :  1;
    uint32_t odr11 :  1;
    uint32_t odr12 :  1;
    uint32_t odr13 :  1;
    uint32_t odr14 :  1;
    uint32_t odr15 :  1;
    uint32_t       : 16;
  };
} gpiox_odr_t;

typedef struct {
  gpiox_moder_t moder;
  RESERVED(4);
  gpiox_odr_t   odr;
} gpiox_t;


extern volatile gpiox_t gpioa;
#endif
