#ifndef HAL_UTIL_H
#define HAL_UTIL_H

#define HAL_CONCAT(x,y) x ## y
#define HAL_EXPAND(x,y) HAL_CONCAT(x,y)
#define RESERVED(num) uint32_t HAL_EXPAND(_reserved, __LINE__)[(num)]

#define PERIPHERAL(per) __attribute__((section("."#per)))


#endif//HAL_UTIL_H