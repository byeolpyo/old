/* cellular automata generator */

/* theres a linear array of cells, all of which can be either "on" or "off" (0 or 1, " " or "o") */
/* the array "evolves" according to a set rule - each cell looks at its neighbours and determines whether its going to become "on" or "off" in the next generation */
/* in this implementation, the neighbourhood size is one which means that the cell looks at itself, the cell one unit left and one unit right. */
/* since we have a combination of 3 bits, there are 8 possible neighbourhoods. for each neighbourhood, it is determined whether the result is a 1 or a 0 by the given rule */
/* each rule is a 8-bit integer. each bit represents a neighbourhood - if the neighbourhood is 111, the 8th bit is the result in the next generation */
/* the INITGEN and AGE constants may be altered to change the behaviour of the program. */
/* INITGEN determines the starting generation */
/* AGE is the number of generations the program will compute */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INITGEN "0000000000000000000000000000000100000000000000000000000000000000"
#define AGE 32

void printGeneration(const char * gen);
void calcNextGen(const char * gen, char * nextGen, int rule);
char nextBitState(int neighb, int rule);

void printGeneration(const char * gen) {
	for(int i = 0; i < strlen(gen); i++) {
		if(gen[i] == '0')
			putchar(' ');
		else if(gen[i] == '1')
			putchar('o');
		else {
			printf("Generation formatted incorrectly\n");
			break;
		}
		putchar(' ');
	}
}


/* Why subtract 336 from each sum?
 * short answer: 4*48 + 2*48 + 48 = 336
 * long answer: gen[i] is a character, so if we want to get the integer 1 from gen[i] we need to subtract 48 since 49 (48+1) is the ASCII code for '1'
 */ 
void calcNextGen(const char * gen, char * nextGen, int rule) {
	nextGen[0] = nextBitState((gen[strlen(gen)-1]*4 + gen[0]*2 + gen[1])-336, rule);
	for(int i = 1; i < strlen(gen)-1; i++)
		nextGen[i] = nextBitState((gen[i-1]*4 + gen[i]*2 + gen[i+1])-336, rule);
	nextGen[strlen(gen)-1] = nextBitState((gen[strlen(gen)-2]*4 + gen[strlen(gen)-1]*2 + gen[0])-336, rule);

}

/* get the bit that corresponds to neighb in rule */
char nextBitState(int neighb, int rule) {
	return ((rule >> neighb) & 1) + '0';
}

int main(int argc, char* argv[])
{
	if(argc < 2) {
		puts("insufficient arguments, use -h for help screen\n");
		return 0;
	}
	if(!strcmp(argv[1], "-h")) {
		puts("usage\n./onedim [rule]/[-h]\n	-h prints this help screen\n	rule number must be between 0-255\n");
		return 0;
	}

	if(!atoi(argv[1]) && strcmp(argv[1], "0")) {
		puts("incorrect rule number, use -h for help screen");
		return 0;
	}
	int rule = atoi(argv[1]);
	char currentGen[] = INITGEN;
	char backup[] = INITGEN;

	for(int i = 0; i < AGE; i++) {
		printGeneration(currentGen);
		calcNextGen(backup, currentGen, rule);
		strcpy(backup, currentGen);
		putchar('\n');
	}
	return 0;
}

