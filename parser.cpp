//
// Created by Hannes Furmans on 30.03.22.
//

#include "parser.h"
#include <stack>
#include <cstdio>


unsigned short parse(unsigned short * instructions, unsigned short * jumps) {
    std::stack<unsigned short> open_brackets;
    unsigned short instruction_pointer = 0;
    FILE * file = fopen("../hello.bf", "rb");
    unsigned short opening_index = 0;
    unsigned short closing_index = 0;
    while (instruction_pointer < 30000) {
        int read_char = fgetc(file);
        if (read_char == EOF) break;

        if (read_char == INC_PTR) {
            instructions[instruction_pointer] = INC_PTR_D;
        } else if (read_char == DEC_PTR) {
            instructions[instruction_pointer] = DEC_PTR_D;
        } else if (read_char == INC_VAL) {
            instructions[instruction_pointer] = INC_VAL_D;
        } else if (read_char == DEC_VAL) {
            instructions[instruction_pointer] = DEC_VAL_D;
        } else if (read_char == PUT_CHR) {
            instructions[instruction_pointer] = PUT_CHR_D;
        } else if (read_char == GET_CHR) {
            instructions[instruction_pointer] = GET_CHR_D;
        } else if (read_char == JMP_FOR) {
            open_brackets.push(instruction_pointer);
        } else if (read_char == JMP_BCK) {
            unsigned short opening_bracket = open_brackets.top();
            open_brackets.pop();
            unsigned short jump_for = instruction_pointer;
            unsigned short jump_back = opening_bracket;
            unsigned short jmp_for_d = (opening_index) * 2;
            opening_index += 1;
            unsigned short jmp_back_d = (closing_index) * 2 + 1;
            closing_index += 1;
            jumps[jmp_for_d] = jump_for;
            if (jump_for >= JUMP_ARRAY_SIZE) {
                printf("Out of bounds while writing jump\r\n");
                exit(1);
            }
            jumps[jmp_back_d] = jump_back;
            if (jmp_back_d >= JUMP_ARRAY_SIZE) {
                printf("Out of bounds while writing jump\r\n");
                exit(1);
            }
            instructions[instruction_pointer] = jmp_back_d + 8;
            instructions[opening_bracket] = jmp_for_d + 8;
        } else {
            instructions[instruction_pointer] = COMMENT_D;
        }

        instruction_pointer++;
    }
    fclose(file);
    printf("Opening index => %i closing index => %i\r\n", opening_index, closing_index);
    printf("Read %i instructions\r\n", instruction_pointer);
    return instruction_pointer;
};