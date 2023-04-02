#ifndef HAL_STK_H
#define HAL_STK_H

#include <stdint.h>

typedef union {
    uint32_t reg;
    struct {
        uint32_t enable    :  1;
        uint32_t tickint   :  1;
        uint32_t clksource :  1;
        uint32_t           : 13;
        uint32_t countflag :  1;
        uint32_t           : 15;
    };
} stk_csr_t;

typedef union {
    uint32_t reg;
    struct {
        uint32_t reload : 24;
        uint32_t        :  8;
    };
} stk_rvr_t;

typedef union {
    uint32_t reg;
    struct {
        uint32_t current : 24;
        uint32_t         :  8;
    };
} stk_cvr_t;

typedef union {
    uint32_t reg;
    struct {
        uint32_t tenms : 24;
        uint32_t       :  6;
        uint32_t skew  :  1;
        uint32_t noref :  1;
    };
} stk_calib_t;

typedef struct {
    stk_csr_t   csr;
    stk_rvr_t   rvr;
    stk_cvr_t   cvr;
    stk_calib_t calib;
} stk_t;

extern volatile stk_t stk;
#endif//HAL_STK_H