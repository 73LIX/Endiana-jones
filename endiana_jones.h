#ifndef ENDIANA_JONES_H
#define ENDIANA_JONES_H
#include <stdint.h>
#include <stdbool.h>

//change byte order (logic)
static inline uint16_t byteOrder_Conv(uint16_t value){
    uint16_t highByte = value & 0xFF00;
    uint16_t lowByte = value & 0x00FF;

    return (highByte >> 8) | (lowByte << 8);
}

//host endianness check 
static inline bool is_little_endian(void){
    uint16_t num = 1;
    uint8_t *byte_ptr = (uint8_t *)&num;

    if(*byte_ptr == 1){
        return true;
    }
    return false;
}

//host to network
static inline uint16_t hstontk(uint16_t hostByte) {
    if(is_little_endian()){
        uint16_t networkByte = byteOrder_Conv(hostByte);
        return networkByte;
    } else {
        return hostByte;
    }
}

//network to host
static inline uint16_t ntkohst(uint16_t networkByte){
    if(is_little_endian()){
        uint16_t hostByte = byteOrder_Conv(networkByte);
        return hostByte;
    } else {
        return networkByte;
    }
}

#endif