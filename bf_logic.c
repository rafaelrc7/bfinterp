#include "bf_logic.h"

#include <stdio.h>
#include <stdlib.h>

void inc_ptr(char** dat, char** ins)
{
	(*dat)++;
	(*ins)++;
}

void dec_ptr(char** dat, char** ins)
{
	(*dat)--;
	(*ins)++;
}

void inc_byt(char** dat, char** ins)
{
	(**dat)++;
	(*ins)++;
}

void dec_byt(char** dat, char** ins)
{
	(**dat)--;
	(*ins)++;
}

void prt_byt(char** dat, char** ins)
{
	putchar((**dat));
	(*ins)++;
}

void get_byt(char** dat, char** ins)
{
	(**dat) = getchar();
	(*ins)++;
}

void jmp_eqz(char** dat, char** ins)
{
	int match = 0;

	if ((**dat)) {
		(*ins)++;
		return;
	}

	while ( (*(++(*ins))) != ']' || match) {
		if ( (**ins) == '[' )
			match++;
		else if ( (**ins) == ']' )
			match--;
	}

	(*ins)++;
}

void jmp_noz(char** dat, char** ins)
{
	int match = 0;

	if (!(**dat)) {
		(*ins)++;
		return;
	}

	while ( (*(--(*ins))) != '[' || match) {
		if ( (**ins) == ']' )
			match++;
		else if ( (**ins) == '[' )
			match--;
	}

	(*ins)++;
}

void bf_run(char* dat, char* ins)
{
	while (*ins) {
		switch ((*ins)) {
			case '>':
				inc_ptr(&dat, &ins);
				break;

			case '<':
				dec_ptr(&dat, &ins);
				break;

			case '+':
				inc_byt(&dat, &ins);
				break;

			case '-':
				dec_byt(&dat, &ins);
				break;

			case '.':
				prt_byt(&dat, &ins);
				break;

			case ',':
				get_byt(&dat, &ins);
				break;

			case '[':
				jmp_eqz(&dat, &ins);
				break;

			case ']':
				jmp_noz(&dat, &ins);
				break;

		}
	}
}
