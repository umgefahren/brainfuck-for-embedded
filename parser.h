//
// Created by Hannes Furmans on 30.03.22.
//

#ifndef BRAINFUCK_FOR_EMBEDDED_PARSER_H
#define BRAINFUCK_FOR_EMBEDDED_PARSER_H

#define INC_PTR '>'
#define DEC_PTR '<'
#define INC_VAL '+'
#define DEC_VAL '-'
#define PUT_CHR '.'
#define GET_CHR ','
#define JMP_FOR '['
#define JMP_BCK ']'

#define INC_PTR_D 0
#define DEC_PTR_D 1
#define INC_VAL_D 2
#define DEC_VAL_D 3
#define PUT_CHR_D 4
#define GET_CHR_D 5
#define COMMENT_D 6

#define JUMP_ARRAY_SIZE 15000

unsigned short parse(unsigned short * instructions, unsigned short * jumps);

#endif //BRAINFUCK_FOR_EMBEDDED_PARSER_H
