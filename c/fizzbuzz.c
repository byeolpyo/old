/* implementation of fizzbuzz, call from cmd */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void check_cmd_args(int argc, char* argv) {
    if(argc != 2 || !strspn(argv[1], "0123456789")) {
        printf("usage: %s <integer>\n", argv[0]);
    	exit(0);
    }
    return;
}

int main(int argc, char* argv[]) { 
    check_cmd_args(argc, argv);
    
    const char *FIZZ = "fizz";
    const char *BUZZ = "buzz";
    
    const int RANGE = strtol(argv[1], NULL, 10);
    
    int i;
    for(i = 1; i < RANGE+1; i++) {
	    char output[9] = "";
    	if(i % 3 == 0) strncat(output, FIZZ, sizeof(FIZZ));
    	if(i % 5 == 0) strncat(output, BUZZ, sizeof(BUZZ));
    	if(strcmp(output, "") == 0) printf("%d\n", i);
    	else printf("%s\n", output);
    }
    return 0;
}
