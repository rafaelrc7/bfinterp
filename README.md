# bfinterp

bfinterp is a interpreter for the simplist esoteric language "brainfuck". This interpreter is pretty simple, with no error detection, so beware. I may add features
to it in the future, but currently it's just a personal challenge.
## Compilation

You may simply compile it with gcc:
```
gcc ${CFLAGS} -o bfinterp bf_interp.c bf_logic.c
```
## Usage
./bfinterp file.bf


Example:
```
./bfinterp helloworld.bf
```
Hello World!

## Contributing
You may make pull requests for modifications you find relevant.

## License
[MIT](https://choosealicense.com/licenses/mit/)
