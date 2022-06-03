/* love calculator */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void verify_cmd_args(int argc, char* argv[]);
unsigned int love_index_generator(int n);

void verify_cmd_args(int argc, char* argv[]) {
    if(argc != 3 || strlen(argv[1]) < 2 || strlen(argv[2]) < 2) {
    	printf("usage: %s <name 1> <name 2>\n", argv[0]);
	    exit(0);
    }
}


/* !!! this returns a value in range [0, UINT_MAX] */
unsigned int love_index_generator(int n) {
    if(n == 0) return 394587;
    return love_index_generator(n-1)*3487+293;
}

int main(int argc, char* argv[]) {
    verify_cmd_args(argc, argv);

    /* using argv to compute seed ensures that the result is consistent for the same names */
    int seed = argv[2][0] * argv[2][1]  +  argv[1][0] * argv[1][1];

    unsigned int love_index = love_index_generator(seed);
    printf("%u\%\n", love_index%100);
    return 0;
}
