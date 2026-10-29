//Todo
//[.] First i will implement the 16-bit htons
//[.] Input -> 16-bit number containing 2 bytes (hex representation)
//[.] Extract the first byte: 'B3' from 'B34F'
//[.] Extract the second byte: '4F' 
//[.] Reverse the bytes: by moving the first one to lower position and second one to higher position
//[.] Combine the result -- and print
//[.] Check for host byte order

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

uint16_t htons_16(uint16_t hostByte){
    //isolate the first byte using logical right shift
    //each hexa digit represents 4bits(nibble) so to shift by 2 nibbles we need to shift 2*4 = 8bits
    uint16_t firstByte = hostByte & 0xFF00;

    //isolate the second byte
    uint16_t secondByte = hostByte & 0x00FF;

    //convert host byte order to network byte order
    uint16_t networkByte = (firstByte >> 8) | (secondByte << 8);

    return networkByte;
}

bool is_little_endian(){
    uint16_t num = 1;
    uint8_t *byte_ptr = (uint8_t *)&num; //checking the first byte (8bits)

    if(*byte_ptr == 1){ //1 or 0x01 is the same, ultimately checking the byte order(which is 8bits)
        return true; //returns true if the byte order is 0x0100 that is little-endian, cause 1 in 16-bit hex representation is - 0x0001
    }
    return false;
}

int main(){

    //input
    uint16_t hexCode = 0;
    printf("Enter your hexCode: ");
    scanf("%hx", &hexCode);

    //check for little-endian
    if (is_little_endian()){
        printf("Is a little-endian system\n");
        //convert to network byte order(big-endian)
        uint16_t networkByte = htons_16(hexCode);
        printf("%hx", networkByte);
    } else {
        uint16_t networkByte = hexCode;
        printf("%hx", networkByte);
    }
    return 0;
}