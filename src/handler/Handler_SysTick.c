#include <stdint.h>
#include "handler/util.h"
#include "hal/gpio.h"

HANDLER void Handler_SysTick(void) {
    gpioa.odr.odr4 = !gpioa.odr.odr4;
}