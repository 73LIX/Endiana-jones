//Todo
//[.] First i will implement the 16-bit htons
//[.] Input -> 16-bit number containing 2 bytes (hex representation)
//[.] Extract the first byte: 'B3' from 'B34F'
//[.] Extract the second byte: '4F' 
//[.] Reverse the bytes: by moving the first one to lower position and second one to higher position
//[.] Combine the result -- and print

#include <stdio.h>
#include <stdint.h>

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

int main(){

    //input
    uint16_t hexCode = 0;
    printf("Enter your hexCode: ");
    scanf("%hx", &hexCode);

    //Big-Endian
    uint16_t networkByte = htons_16(hexCode);

    printf("%hx", networkByte);
    return 0;
}