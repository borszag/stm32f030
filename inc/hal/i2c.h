#ifndef HAL_I2C_H
#define HAL_I2C_H

#include <stdint.h>
#include "hal/util.h"

typedef union {
    uint32_t reg;
    struct {
        uint32_t pe        : 1;
        uint32_t txie      : 1;
        uint32_t rxie      : 1;
        uint32_t addrie    : 1;
        uint32_t nackie    : 1;
        uint32_t stopie    : 1;
        uint32_t tcie      : 1;
        uint32_t errie     : 1;
        uint32_t dnf       : 4;
        uint32_t anfoff    : 1;
        uint32_t           : 1;
        uint32_t txdmaen   : 1;
        uint32_t rxdmaen   : 1;
        uint32_t sbc       : 1;
        uint32_t nostretch : 1;
        uint32_t           : 1;
        uint32_t gcen      : 1;
        uint32_t smbhen    : 1;
        uint32_t smbden    : 1;
        uint32_t alerten   : 1;
        uint32_t pecen     : 1;
        uint32_t           : 8;
    };
} i2c_cr1_t;

typedef union {
    uint32_t reg;
    struct {
        uint32_t sadd    : 10;
        uint32_t rd_wrn  :  1;
        uint32_t add10   :  1;
        uint32_t head10r :  1;
        uint32_t start   :  1;
        uint32_t stop    :  1;
        uint32_t nack    :  1;
        uint32_t nbytes  :  8;
        uint32_t reload  :  1;
        uint32_t autoend :  1;
        uint32_t pecbyte :  1;
        uint32_t         :  5;
    };
} i2c_cr2_t;

typedef union {
    uint32_t reg;
    struct {
        uint32_t oa1     : 10;
        uint32_t oa1mode :  1;
        uint32_t         :  4;
        uint32_t oa1en   :  1;
        uint32_t         : 16;
    };
} i2c_oar1_t;

typedef union {
    uint32_t reg;
    struct {
        uint32_t        :  1;
        uint32_t oa2    :  7;
        uint32_t oa2msk :  3;
        uint32_t        :  4;
        uint32_t oa2en  :  1;
        uint32_t        : 16;
    };
} i2c_oar2_t;

typedef union {
    uint32_t reg;
    struct {
        uint32_t scll   :  8;
        uint32_t sclh   :  8;
        uint32_t sdadel :  4;
        uint32_t scldel :  4;
        uint32_t        :  4;
        uint32_t presc  :  4;
    };
} i2c_timingr_t;

typedef union {
    uint32_t reg;
    struct {
        uint32_t timeouta  : 12;
        uint32_t tidle     :  1;
        uint32_t           :  2;
        uint32_t timeouten :  1;
        uint32_t timeoutb  : 12;
        uint32_t           :  3;
        uint32_t texten    :  1;
    };
} i2c_timeoutr_t;

typedef union {
    uint32_t reg;
    struct {
        uint32_t txe        : 1;
        uint32_t txis       : 1;
        uint32_t rxne       : 1;
        uint32_t addr       : 1;
        uint32_t nackf      : 1;
        uint32_t stopf      : 1;
        uint32_t tc         : 1;
        uint32_t tcr        : 1;
        uint32_t berr       : 1;
        uint32_t arlo       : 1;
        uint32_t ovr        : 1;
        uint32_t pecerr     : 1;
        uint32_t timeout    : 1;
        uint32_t alert      : 1;
        uint32_t            : 1;
        uint32_t busy       : 1;
        uint32_t dir        : 1;
        uint32_t addcode    : 7;
        uint32_t            : 8;
    };
} i2c_isr_t;

typedef union {
    uint32_t reg;
    struct {
        uint32_t          :  3;
        uint32_t addrcf   :  1;
        uint32_t nackcf   :  1;
        uint32_t stopcf   :  1;
        uint32_t          :  2;
        uint32_t berrcf   :  1;
        uint32_t arlocf   :  1;
        uint32_t ovrcf    :  1;
        uint32_t peccf    :  1;
        uint32_t timoutcf :  1;
        uint32_t alertcf  :  1;
        uint32_t          : 18;
    };
} i2c_icr_t;

typedef union {
    uint32_t reg;
    struct {
        uint32_t pec :  8;
        uint32_t     : 24;
    };
} i2c_pecr_t;

typedef union {
    uint32_t reg;
    struct {
        uint32_t rxdata :  8;
        uint32_t        : 24;
    };
} i2c_rxdr_t;

typedef union {
    uint32_t reg;
    struct {
        uint32_t txdata :  8;
        uint32_t        : 24;
    };
} i2c_txdr_t;

typedef struct {
    i2c_cr1_t      cr1;
    i2c_cr2_t      cr2;
    i2c_oar1_t     oar1;
    i2c_oar2_t     oar2;
    i2c_timingr_t  timingr;
    i2c_timeoutr_t timeoutr;
    i2c_isr_t      isr;
    i2c_icr_t      icr;
    i2c_pecr_t     pecr;
    i2c_rxdr_t     rxdr;
    i2c_txdr_t     txdr;
} i2c_t;

extern volatile i2c_t i2c1;
#endif//HAL_I2C_H