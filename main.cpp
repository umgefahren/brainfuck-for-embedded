#include <iostream>
#include "parser.h"
#include "execute.h"

int main() {
    // unsigned char instructions[30000] = {0};
    unsigned short * instructions = (unsigned short *) calloc(30000, sizeof(unsigned short));
    if (instructions == nullptr) {
        printf("Couldn't allocate memory for instructions\r\n");
        exit(1);
    }
    for (int i = 0; i < 30000; i++) {
        instructions[i] = 0;
    }
    unsigned short * jumps = (unsigned short *) calloc(1000, sizeof(unsigned short));
    if (jumps == nullptr) {
        printf("Couldn't allocate memory for jumps\r\n");
        exit(1);
    }
    for (int i = 0; i < 1000; i++) {
        jumps[i] = 0;
    }
    unsigned short limit = parse(instructions, jumps);
    execute(instructions, limit, jumps);
    free(instructions);
    free(jumps);
    return 0;
}
