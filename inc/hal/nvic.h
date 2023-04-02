#ifndef HAL_NVIC_H
#define HAL_NVIC_H

#include <stdint.h>
#include "hal/util.h"

typedef union {
    uint32_t reg;
    struct {
        uint32_t seten31 : 1;
        uint32_t seten30 : 1;
        uint32_t seten29 : 1;
        uint32_t seten28 : 1;
        uint32_t seten27 : 1;
        uint32_t seten26 : 1;
        uint32_t seten25 : 1;
        uint32_t seten24 : 1;
        uint32_t seten23 : 1;
        uint32_t seten22 : 1;
        uint32_t seten21 : 1;
        uint32_t seten20 : 1;
        uint32_t seten19 : 1;
        uint32_t seten18 : 1;
        uint32_t seten17 : 1;
        uint32_t seten16 : 1;
        uint32_t seten15 : 1;
        uint32_t seten14 : 1;
        uint32_t seten13 : 1;
        uint32_t seten12 : 1;
        uint32_t seten11 : 1;
        uint32_t seten10 : 1;
        uint32_t seten09 : 1;
        uint32_t seten08 : 1;
        uint32_t seten07 : 1;
        uint32_t seten06 : 1;
        uint32_t seten05 : 1;
        uint32_t seten04 : 1;
        uint32_t seten03 : 1;
        uint32_t seten02 : 1;
        uint32_t seten01 : 1;
        uint32_t seten00 : 1;
    };
} nvic_iser_t;

typedef union {
    uint32_t reg;
    struct {
        uint32_t clren31 : 1;
        uint32_t clren30 : 1;
        uint32_t clren29 : 1;
        uint32_t clren28 : 1;
        uint32_t clren27 : 1;
        uint32_t clren26 : 1;
        uint32_t clren25 : 1;
        uint32_t clren24 : 1;
        uint32_t clren23 : 1;
        uint32_t clren22 : 1;
        uint32_t clren21 : 1;
        uint32_t clren20 : 1;
        uint32_t clren19 : 1;
        uint32_t clren18 : 1;
        uint32_t clren17 : 1;
        uint32_t clren16 : 1;
        uint32_t clren15 : 1;
        uint32_t clren14 : 1;
        uint32_t clren13 : 1;
        uint32_t clren12 : 1;
        uint32_t clren11 : 1;
        uint32_t clren10 : 1;
        uint32_t clren09 : 1;
        uint32_t clren08 : 1;
        uint32_t clren07 : 1;
        uint32_t clren06 : 1;
        uint32_t clren05 : 1;
        uint32_t clren04 : 1;
        uint32_t clren03 : 1;
        uint32_t clren02 : 1;
        uint32_t clren01 : 1;
        uint32_t clren00 : 1;
    };
} nvic_icer_t;

typedef union {
    uint32_t reg;
    struct {
        uint32_t setpend31 : 1;
        uint32_t setpend30 : 1;
        uint32_t setpend29 : 1;
        uint32_t setpend28 : 1;
        uint32_t setpend27 : 1;
        uint32_t setpend26 : 1;
        uint32_t setpend25 : 1;
        uint32_t setpend24 : 1;
        uint32_t setpend23 : 1;
        uint32_t setpend22 : 1;
        uint32_t setpend21 : 1;
        uint32_t setpend20 : 1;
        uint32_t setpend19 : 1;
        uint32_t setpend18 : 1;
        uint32_t setpend17 : 1;
        uint32_t setpend16 : 1;
        uint32_t setpend15 : 1;
        uint32_t setpend14 : 1;
        uint32_t setpend13 : 1;
        uint32_t setpend12 : 1;
        uint32_t setpend11 : 1;
        uint32_t setpend10 : 1;
        uint32_t setpend09 : 1;
        uint32_t setpend08 : 1;
        uint32_t setpend07 : 1;
        uint32_t setpend06 : 1;
        uint32_t setpend05 : 1;
        uint32_t setpend04 : 1;
        uint32_t setpend03 : 1;
        uint32_t setpend02 : 1;
        uint32_t setpend01 : 1;
        uint32_t setpend00 : 1;
    };
} nvic_ispr_t;

typedef union {
    uint32_t reg;
    struct {
        uint32_t clrpend31 : 1;
        uint32_t clrpend30 : 1;
        uint32_t clrpend29 : 1;
        uint32_t clrpend28 : 1;
        uint32_t clrpend27 : 1;
        uint32_t clrpend26 : 1;
        uint32_t clrpend25 : 1;
        uint32_t clrpend24 : 1;
        uint32_t clrpend23 : 1;
        uint32_t clrpend22 : 1;
        uint32_t clrpend21 : 1;
        uint32_t clrpend20 : 1;
        uint32_t clrpend19 : 1;
        uint32_t clrpend18 : 1;
        uint32_t clrpend17 : 1;
        uint32_t clrpend16 : 1;
        uint32_t clrpend15 : 1;
        uint32_t clrpend14 : 1;
        uint32_t clrpend13 : 1;
        uint32_t clrpend12 : 1;
        uint32_t clrpend11 : 1;
        uint32_t clrpend10 : 1;
        uint32_t clrpend09 : 1;
        uint32_t clrpend08 : 1;
        uint32_t clrpend07 : 1;
        uint32_t clrpend06 : 1;
        uint32_t clrpend05 : 1;
        uint32_t clrpend04 : 1;
        uint32_t clrpend03 : 1;
        uint32_t clrpend02 : 1;
        uint32_t clrpend01 : 1;
        uint32_t clrpend00 : 1;
    };
} nvic_icpr_t;

typedef union {
    uint32_t reg;
    struct {
        uint32_t      : 6;
        uint32_t pri0 : 2;
        uint32_t      : 6;
        uint32_t pri1 : 2;
        uint32_t      : 6;
        uint32_t pri2 : 2;
        uint32_t      : 6;
        uint32_t pri3 : 2;
    };
} nvic_iprx_t;

typedef struct {
    nvic_iser_t iser;
    RESERVED(31);
    nvic_icer_t icer;
    RESERVED(31);
    nvic_ispr_t ispr;
    RESERVED(31);
    nvic_icpr_t icpr;
    RESERVED(95);
    nvic_iprx_t ipr[8];
} nvic_t;

extern volatile nvic_t nvic;
#endif//HAL_NVIC_H