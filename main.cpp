#include <iostream>
#include "parser.h"
#include "execute.h"

int main() {
    // unsigned char instructions[30000] = {0};
    unsigned short * instructions = (unsigned short *) malloc(30000 * sizeof(unsigned short));
    if (instructions == nullptr) {
        printf("Couldn't allocate memory for instructions\r\n");
        exit(1);
    }
    for (int i = 0; i < 30000; i++) {
        instructions[i] = 0;
    }
    unsigned short * jumps = (unsigned short *) malloc(JUMP_ARRAY_SIZE * sizeof(unsigned short));
    if (jumps == nullptr) {
        printf("Couldn't allocate memory for jumps\r\n");
        exit(1);
    }
    for (int i = 0; i < 1000; i++) {
        jumps[i] = 0;
    }
    unsigned short limit = parse(instructions, jumps);

    unsigned int instruction_hash = 0;
    for (int i = 0; i < limit; i++) {
        instruction_hash += instructions[i];
    }

    printf("Instruction hash => %i\r\n", instruction_hash);

    unsigned int jump_hash = 0;
    for (int i = 0; i < 1000; i++) {
        jump_hash += jumps[i];
    }

    printf("Jump hash => %i\r\n", jump_hash);

    execute(instructions, limit, jumps);
    free(instructions);
    free(jumps);
    return 0;
}
