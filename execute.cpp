//
// Created by Hannes Furmans on 30.03.22.
//

#include "execute.h"
#include "parser.h"
#include <cstdio>
#include <cstdlib>

void execute(const unsigned short * instructions, unsigned short instrution_limit, unsigned short * jumps) {
    auto * memory = (unsigned char *) calloc(30000, sizeof(unsigned char));
    if (memory == nullptr) {
        printf("Couldn't allocate memory for memory\r\n");
        exit(1);
    }
    for (int i = 0; i < 30000; i++) {
        memory[i] = 0;
    }
    unsigned int ptr = 0;
    unsigned int instruction_ptr = 0;
    while (instruction_ptr <= instrution_limit) {
        unsigned short instruction = instructions[instruction_ptr];
        if (instruction == INC_PTR_D) {
            ptr++;
        } else if (instruction == DEC_PTR_D) {
            ptr--;
        } else if (instruction == INC_VAL_D) {
            memory[ptr]++;
        } else if (instruction == DEC_VAL_D) {
            memory[ptr]--;
        } else if (instruction == PUT_CHR_D) {
            printf("%c", memory[ptr]);
        } else if (instruction == GET_CHR_D) {
            memory[ptr] = getchar();
        } else if (instruction == COMMENT_D) {
            char lowerbits = instructions[instruction_ptr++] << 8;

        } else {
            unsigned short odd = instruction % 2;
            // Is odd => jumping back if condition holds
            if (odd == 1 && memory[ptr] != 0) {
                unsigned short jmp_back_d = instruction - 8;
                unsigned short jmp_to = jumps[jmp_back_d];
                if (jmp_to >= instrution_limit) {
                    printf("\nTried to jump to %i from %i. Instruction: %i Jump Index: %i\r\n", jmp_to, instruction_ptr, instruction, jmp_back_d);
                    exit(1);
                }
                instruction_ptr = jmp_to;
            } else if (odd == 0 && memory[ptr] == 0) {
                unsigned short jmp_for_d = instruction - 8;
                unsigned short jmp_to = jumps[jmp_for_d];
                if (jmp_to >= instrution_limit) {
                    printf("\nTried to jump to %i from %i. Instruction: %i Jump Index: %i\r\n", jmp_to, instruction_ptr, instruction, jmp_for_d);
                    exit(1);
                }
                instruction_ptr = jmp_to;
            }
        }
        instruction_ptr++;
    }
    printf("\nstopping after %i instructions moved by\r\n", instruction_ptr);
    free(memory);
}