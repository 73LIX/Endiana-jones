#include <stdio.h>
#include "endiana_jones.h"

int main(void) {
    uint16_t host = 0x1234;

    uint16_t network = hstontk(host);
    uint16_t converted_back = ntkohst(network);

    printf("Host Byte Order:    0x%04hx\n", host);
    printf("Network Byte Order: 0x%04hx\n", network);
    printf("Converted Back:     0x%04hx\n", converted_back);

    return 0;
}