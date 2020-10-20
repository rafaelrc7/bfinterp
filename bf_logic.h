#ifndef _BF_LOGIC
#define _BF_LOGIC

#define DAT_SIZE 30000

void inc_ptr(char**, char**);
void dec_ptr(char**, char**);
void inc_byt(char**, char**);
void dec_byt(char**, char**);
void prt_byt(char**, char**);
void get_byt(char**, char**);
void jmp_eqz(char**, char**);
void jmp_noz(char**, char**);

void bf_run(char*, char*);

#endif
