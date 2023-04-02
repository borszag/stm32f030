#ifndef HAL_SCB_H
#define HAL_SCB_H

#include <stdint.h>
#include "hal/util.h"

typedef union {
    uint32_t reg;
    struct {
        uint32_t revision    :  4;
        uint32_t partno      : 12;
        uint32_t constant    :  4;
        uint32_t variant     :  4;
        uint32_t implementer :  8;
    };
} scb_cpuid_t;

typedef union {
    uint32_t reg;
    struct {
        uint32_t vectactive  : 6;
        uint32_t             : 6;
        uint32_t vectpending : 6;
        uint32_t             : 4;
        uint32_t isrpending  : 1;
        uint32_t             : 2;
        uint32_t pendstclr   : 1;
        uint32_t pendstset   : 1;
        uint32_t pendsvclr   : 1;
        uint32_t pendsvset   : 1;
        uint32_t             : 2;
        uint32_t nmipendset  : 1;
    };
} scb_icsr_t;

typedef union {
    uint32_t reg;
    struct {
        uint32_t               :  1;
        uint32_t vectclractive :  1;
        uint32_t sysresetreq   :  1;
        uint32_t               : 12;
        uint32_t endianess     :  1;
        uint32_t vectkey       : 16;
    };
} scb_aircr_t;

typedef union {
    uint32_t reg;
    struct {
        uint32_t             :  1;
        uint32_t sleeponexit :  1;
        uint32_t sleepdeep   :  1;
        uint32_t             :  1;
        uint32_t sevonpend   :  1;
        uint32_t             : 27;
    };
} scb_scr_t;

typedef union {
    uint32_t reg;
    struct {
        uint32_t             :  3;
        uint32_t unalign_trp :  1;
        uint32_t             :  5;
        uint32_t stkalign    :  1;
        uint32_t             : 22;
    };
} scb_ccr_t;

typedef union {
    uint32_t reg;
    struct {
        uint32_t            : 30;
        uint32_t pri_svcall :  2;
    };
} scb_shpr2_t;

typedef union {
    uint32_t reg;
    struct {
        uint32_t             : 22;
        uint32_t pri_pendsv  :  2;
        uint32_t             :  6;
        uint32_t pri_systick :  2;
    };
} scb_shpr3_t;

typedef struct {
    scb_cpuid_t cpuid;
    scb_icsr_t  icsr;
    RESERVED(1);
    scb_aircr_t aircr;
    scb_scr_t   scr;
    scb_ccr_t   ccr;
    RESERVED(1);
    scb_shpr2_t shpr2;
    scb_shpr3_t shpr3;
} scb_t;

extern volatile scb_t scb;
#endif//HAL_SCB_H