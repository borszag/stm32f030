#ifndef HAL_SPI_H
#define HAL_SPI_H

#include <stdint.h>
#include "hal/util.h"

typedef union {
    uint32_t reg;
    struct {
        uint32_t cpha     :  1;
        uint32_t cpol     :  1;
        uint32_t mstr     :  1;
        uint32_t br       :  3;
        uint32_t spe      :  1;
        uint32_t lsbfirst :  1;
        uint32_t ssi      :  1;
        uint32_t ssm      :  1;
        uint32_t rxonly   :  1;
        uint32_t crcl     :  1;
        uint32_t crcnext  :  1;
        uint32_t crcen    :  1;
        uint32_t bidioe   :  1;
        uint32_t bidimode :  1;
        uint32_t          : 16;
    };
} spix_cr1_t;

typedef union {
    uint32_t reg;
    struct {
        uint32_t rxdmaen :  1;
        uint32_t txdmaen :  1;
        uint32_t ssoe    :  1;
        uint32_t nssp    :  1;
        uint32_t frf     :  1;
        uint32_t errie   :  1;
        uint32_t rxneie  :  1;
        uint32_t txeie   :  1;
        uint32_t ds      :  4;
        uint32_t frxth   :  1;
        uint32_t ldma_rx :  1;
        uint32_t ldma_tx :  1;
        uint32_t         : 17;
    };
} spix_cr2_t;

typedef union {
    uint32_t reg;
    struct {
        uint32_t rxne   :  1;
        uint32_t txe    :  1;
        uint32_t        :  2;
        uint32_t crcerr :  1;
        uint32_t modf   :  1;
        uint32_t ovr    :  1;
        uint32_t bsy    :  1;
        uint32_t fre    :  1;
        uint32_t frlvl  :  2;
        uint32_t ftlvl  :  2;
        uint32_t        : 19;
    };
} spix_sr_t;

typedef union {
    uint32_t reg;
    struct {
        uint32_t dr : 16;
        uint32_t    : 16;
    };
} spix_dr_t;

typedef union {
    uint32_t reg;
    struct {
        uint32_t crcpoly : 16;
        uint32_t         : 16;
    };
} spix_crcpr_t;

typedef union {
    uint32_t reg;
    struct {
        uint32_t rxcrc : 16;
        uint32_t       : 16;
    };
} spix_rxcrcr_t;


typedef union {
    uint32_t reg;
    struct {
        uint32_t txcrc : 16;
        uint32_t       : 16;
    };
} spix_txcrcr_t;

typedef struct {
    spix_cr1_t    cr1;
    spix_cr2_t    cr2;
    spix_sr_t     sr;
    spix_dr_t     dr;
    spix_crcpr_t  crcpr;
    spix_rxcrcr_t rxcrcr;
    spix_txcrcr_t txcrcr;
} spix_t;

extern volatile spix_t spi1;
#endif//HAL_SPI_H
