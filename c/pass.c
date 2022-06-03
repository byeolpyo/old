/* generate a random, safe password (which includes uppercase and lowercase letters, as well as numbers) */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

void verify_cmd_args(int argc, char* argv[]) {
    /* check if argv[1] is a number */
    if(argc != 2 || strspn(argv[1], "0123456789") != strlen(argv[1])) {
	    printf("usage: %s <number of character in the password>\n", argv[0]);
    	exit(0);
    }
    
    if(strlen(argv[1]) == 1 && argv[1][0] < '8') {
    	printf("password length must be at least 8\n");
    	exit(0);
    }
}

int main(int argc, char* argv[]) {
    verify_cmd_args(argc, argv);
    
    /* using just time(NULL) is considered unsafe */
    srand(time(NULL)*time(NULL)*getpid());

    int i;
    const int len = atoi(argv[1]);

    /* there are 10 numbers, and 2*26 letters.
     * those characters are not grouped together in the ascii code, so the type of character is determined first;
     * then a character of that type is generated from the corresponding range. */

    for(i = 0; i < len; i++) {
	    if(rand()%62>35) { printf("%c", rand()%26+65); continue; }
    	if(rand()%62>9) { printf("%c", rand()%26+97); continue; }
    	printf("%c", rand()%10+48);

    }
    putchar('\n');
    return 0;
}
