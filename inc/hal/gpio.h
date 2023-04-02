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
    uint32_t ot0  :  1;
    uint32_t ot1  :  1;
    uint32_t ot2  :  1;
    uint32_t ot3  :  1;
    uint32_t ot4  :  1;
    uint32_t ot5  :  1;
    uint32_t ot6  :  1;
    uint32_t ot7  :  1;
    uint32_t ot8  :  1;
    uint32_t ot9  :  1;
    uint32_t ot10 :  1;
    uint32_t ot11 :  1;
    uint32_t ot12 :  1;
    uint32_t ot13 :  1;
    uint32_t ot14 :  1;
    uint32_t ot15 :  1;
    uint32_t      : 16;
  };
} gpiox_otyper_t;

typedef union {
  uint32_t reg;
  struct {
    uint32_t ospeedr0  : 2;
    uint32_t ospeedr1  : 2;
    uint32_t ospeedr2  : 2;
    uint32_t ospeedr3  : 2;
    uint32_t ospeedr4  : 2;
    uint32_t ospeedr5  : 2;
    uint32_t ospeedr6  : 2;
    uint32_t ospeedr7  : 2;
    uint32_t ospeedr8  : 2;
    uint32_t ospeedr9  : 2;
    uint32_t ospeedr10 : 2;
    uint32_t ospeedr11 : 2;
    uint32_t ospeedr12 : 2;
    uint32_t ospeedr13 : 2;
    uint32_t ospeedr14 : 2;
    uint32_t ospeedr15 : 2;
  };
} gpiox_ospeedr_t;

typedef union {
  uint32_t reg;
  struct {
    uint32_t pupdr0  : 2;
    uint32_t pupdr1  : 2;
    uint32_t pupdr2  : 2;
    uint32_t pupdr3  : 2;
    uint32_t pupdr4  : 2;
    uint32_t pupdr5  : 2;
    uint32_t pupdr6  : 2;
    uint32_t pupdr7  : 2;
    uint32_t pupdr8  : 2;
    uint32_t pupdr9  : 2;
    uint32_t pupdr10 : 2;
    uint32_t pupdr11 : 2;
    uint32_t pupdr12 : 2;
    uint32_t pupdr13 : 2;
    uint32_t pupdr14 : 2;
    uint32_t pupdr15 : 2;
  };
} gpiox_pupdr_t;

typedef union {
  uint32_t reg;
  struct {
    uint32_t idr0  :  1;
    uint32_t idr1  :  1;
    uint32_t idr2  :  1;
    uint32_t idr3  :  1;
    uint32_t idr4  :  1;
    uint32_t idr5  :  1;
    uint32_t idr6  :  1;
    uint32_t idr7  :  1;
    uint32_t idr8  :  1;
    uint32_t idr9  :  1;
    uint32_t idr10 :  1;
    uint32_t idr11 :  1;
    uint32_t idr12 :  1;
    uint32_t idr13 :  1;
    uint32_t idr14 :  1;
    uint32_t idr15 :  1;
    uint32_t       : 16;
  };
} gpiox_idr_t;

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

typedef union {
  uint32_t reg;
  struct {
    uint32_t bs0  : 1;
    uint32_t bs1  : 1;
    uint32_t bs2  : 1;
    uint32_t bs3  : 1;
    uint32_t bs4  : 1;
    uint32_t bs5  : 1;
    uint32_t bs6  : 1;
    uint32_t bs7  : 1;
    uint32_t bs8  : 1;
    uint32_t bs9  : 1;
    uint32_t bs10 : 1;
    uint32_t bs11 : 1;
    uint32_t bs12 : 1;
    uint32_t bs13 : 1;
    uint32_t bs14 : 1;
    uint32_t bs15 : 1;
    uint32_t br0  : 1;
    uint32_t br1  : 1;
    uint32_t br2  : 1;
    uint32_t br3  : 1;
    uint32_t br4  : 1;
    uint32_t br5  : 1;
    uint32_t br6  : 1;
    uint32_t br7  : 1;
    uint32_t br8  : 1;
    uint32_t br9  : 1;
    uint32_t br10 : 1;
    uint32_t br11 : 1;
    uint32_t br12 : 1;
    uint32_t br13 : 1;
    uint32_t br14 : 1;
    uint32_t br15 : 1;
  };
} gpiox_bsrr_t;

typedef union {
  uint32_t reg;
  struct {
    uint32_t lck0 :   1;
    uint32_t lck1 :   1;
    uint32_t lck2 :   1;
    uint32_t lck3 :   1;
    uint32_t lck4 :   1;
    uint32_t lck5 :   1;
    uint32_t lck6 :   1;
    uint32_t lck7 :   1;
    uint32_t lck8 :   1;
    uint32_t lck9 :   1;
    uint32_t lck10 :  1;
    uint32_t lck11 :  1;
    uint32_t lck12 :  1;
    uint32_t lck13 :  1;
    uint32_t lck14 :  1;
    uint32_t lck15 :  1;
    uint32_t lckk  :  1;
    uint32_t       : 15;
  };
} gpiox_lckr_t;

typedef union {
  uint32_t reg;
  struct {
    uint32_t afsel0 : 4;
    uint32_t afsel1 : 4;
    uint32_t afsel2 : 4;
    uint32_t afsel3 : 4;
    uint32_t afsel4 : 4;
    uint32_t afsel5 : 4;
    uint32_t afsel6 : 4;
    uint32_t afsel7 : 4;
  };
} gpiox_afrl_t;

typedef union {
  uint32_t reg;
  struct {
    uint32_t afsel8  : 4;
    uint32_t afsel9  : 4;
    uint32_t afsel10 : 4;
    uint32_t afsel11 : 4;
    uint32_t afsel12 : 4;
    uint32_t afsel13 : 4;
    uint32_t afsel14 : 4;
    uint32_t afsel15 : 4;
  };
} gpiox_afrh_t;

typedef union {
  uint32_t reg;
  struct {
    uint32_t br0  :  1;
    uint32_t br1  :  1;
    uint32_t br2  :  1;
    uint32_t br3  :  1;
    uint32_t br4  :  1;
    uint32_t br5  :  1;
    uint32_t br6  :  1;
    uint32_t br7  :  1;
    uint32_t br8  :  1;
    uint32_t br9  :  1;
    uint32_t br10 :  1;
    uint32_t br11 :  1;
    uint32_t br12 :  1;
    uint32_t br13 :  1;
    uint32_t br14 :  1;
    uint32_t br15 :  1;
    uint32_t      : 16;
  };
} gpiox_brr_t;

typedef struct {
  gpiox_moder_t   moder;
  gpiox_otyper_t  otyper;
  gpiox_ospeedr_t ospeedr;
  gpiox_pupdr_t   pupdr;
  gpiox_idr_t     idr;
  gpiox_odr_t     odr;
  gpiox_bsrr_t    bsrr;
  gpiox_lckr_t    lckr;
  gpiox_afrl_t    afrl;
  gpiox_afrh_t    afrh;
  gpiox_brr_t     brr;
} gpiox_t;


extern volatile gpiox_t gpioa;
extern volatile gpiox_t gpiob;
extern volatile gpiox_t gpioc;
extern volatile gpiox_t gpiod;
extern volatile gpiox_t gpiof;
#endif
