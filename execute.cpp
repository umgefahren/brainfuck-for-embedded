//
// Created by Hannes Furmans on 30.03.22.
//

#include "execute.h"
#include "parser.h"
#include <cstdio>
#include <cstdlib>

void execute(const unsigned short * instructions, unsigned short instrution_limit, unsigned short * jumps) {
    unsigned char * memory = (unsigned char *) calloc(30000, sizeof(unsigned char));
    unsigned char * ptr = memory;
    unsigned int instruction_ptr = 0;
    while (instruction_ptr < instrution_limit) {
        unsigned short instruction = instructions[instruction_ptr];
        if (instruction == INC_PTR_D) {
            ptr++;
        } else if (instruction == DEC_PTR_D) {
            ptr--;
        } else if (instruction == INC_VAL_D) {
            ptr[0]++;
        } else if (instruction == DEC_VAL_D) {
            ptr[0]--;
        } else if (instruction == PUT_CHR_D) {
            printf("%c", ptr[0]);
        } else if (instruction == GET_CHR_D) {
            ptr[0] = getchar();
        } else if (instruction == COMMENT_D) {
        } else {
            unsigned short odd = instruction % 2;
            // Is odd => jumping back if condition holds
            if (odd && ptr[0] != 0) {
                unsigned short jmp_back_d = instruction - 8;
                unsigned short jmp_to = jumps[jmp_back_d];
                instruction_ptr = jmp_to;
            } else if (!odd && ptr[0] == 0) {
                unsigned short jmp_for_d = instruction - 8;
                unsigned short jmp_to = jumps[jmp_for_d];
                instruction_ptr = jmp_to;
            }
        }
        instruction_ptr++;
    }
    free(memory);
}