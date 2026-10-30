#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

//change byte order
uint16_t byteOrder_Conv(uint16_t value){
    //isolate the first byte using logical right shift
    //each hexa digit represents 4bits(nibble) so to shift by 2 nibbles we need to shift 2*4 = 8bits
    uint16_t highByte = value & 0xFF00;

    //isolate the second byte
    uint16_t lowByte = value & 0x00FF;

    //convert host byte order to network byte order
    return (highByte >> 8) | (lowByte << 8);
}

//check host's endianness
bool is_little_endian(void){
    uint16_t num = 1;
    uint8_t *byte_ptr = (uint8_t *)&num; //checking the first byte (8bits)

    if(*byte_ptr == 1){ //1 or 0x01 is the same, ultimately checking the byte order(which is 8bits)
        return true; //returns true if the byte order is 0x0100 that is little-endian, cause 1 in 16-bit hex representation is - 0x0001
    }
    return false;
}

//host to network
uint16_t hstontk(uint16_t hostByte) {
    //check if host is little-endian, if it is then convert it to big-endian for the network byte order
    if(is_little_endian()){
        uint16_t networkByte = byteOrder_Conv(hostByte);
        return networkByte;
    } else {
        return hostByte;
    }
}

//network to host
uint16_t ntkohst(uint16_t networkByte){
    //check if the host(reciever side) is little-endian
    if(is_little_endian()){
        uint16_t hostByte = byteOrder_Conv(networkByte);
        return hostByte;
    } else {
        return networkByte;
    }
}

int main(){
    //simulating the host to network and network to host
    //input
    uint16_t host = 0;
    printf("Enter your 16-bit hexCode: ");
    if(scanf("%hx", &host) != 1){
        printf("Invalid input.\n");
        return 1;
    }

    //hstontk()
    uint16_t networkByte = hstontk(host);
    printf("%04hx \n", networkByte);
    
    //ntkohst()
    host = ntkohst(networkByte);
    printf("%04hx \n", host);
    return 0;
}