#include <iostream>
#include "parser.h"
#include "execute.h"

int main() {
    // unsigned char instructions[30000] = {0};
    unsigned short * instructions = (unsigned short *) malloc(30000 * sizeof(unsigned short));
    unsigned short * jumps = (unsigned short *) malloc(1000 * sizeof(unsigned short));
    unsigned short limit = parse(instructions, jumps);
    execute(instructions, limit, jumps);
    return 0;
}
