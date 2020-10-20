#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bf_logic.h"


char *read_bffile(char *file_name);

int main(int argc, char *argv[])
{

	char *ins_ptr;
	char *dat_ptr;

	if (argc < 2) {
		fprintf(stderr, "No file name provided\n");
		exit(1);
	}

	dat_ptr = (char*)malloc(DAT_SIZE);
	if (!dat_ptr) {
		fprintf(stderr, "Failed to allocate data segment\n");
		exit(1);
	}

	ins_ptr = read_bffile(argv[1]);
	if (!ins_ptr) {
		fprintf(stderr, "Failed to open file %s\n", argv[1]);
		exit(1);
	}


	bf_run(dat_ptr, ins_ptr);

	free(ins_ptr);
	free(dat_ptr);
	return 0;
}

char *read_bffile(char *file_name)
{
	FILE *file = fopen(file_name, "r");
	char *source;
	int code_size = 0, pos = 0;
	int in;
	char valid_chars[256] = {0};

	valid_chars['>'] = 1;
	valid_chars['<'] = 1;
	valid_chars['+'] = 1;
	valid_chars['-'] = 1;
	valid_chars['.'] = 1;
	valid_chars[','] = 1;
	valid_chars['['] = 1;
	valid_chars[']'] = 1;

	if (!file) return NULL;

	while ((in = fgetc(file)) != EOF)
		if (valid_chars[in])
			code_size++;

	rewind(file);

	source = (char*)malloc(sizeof(char)*code_size + 1);
	if (!source) {
		fprintf(stderr, "Failed to allocate memory\n");
		exit(1);
	}

	while ((in = fgetc(file)) != EOF)
		if (valid_chars[in])
			source[pos++] = in;
	source[pos] = '\0';

	fclose(file);

	return source;
}
