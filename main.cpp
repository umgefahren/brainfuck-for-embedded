#include <iostream>
#include "parser.h"
#include "execute.h"

int main() {
    auto * instructions = (unsigned char *) malloc(30000 * sizeof(unsigned char));
    if (instructions == nullptr) {
        printf("Couldn't allocate memory for instructions\r\n");
        exit(1);
    }
    for (int i = 0; i < 30000; i++) {
        instructions[i] = 0;
    }

    unsigned short limit = parse(instructions);

    execute(instructions, limit);
    free(instructions);

    return 0;
}
