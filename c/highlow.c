#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define INPUTLENGTH 30

int main(int argc, char *argv[])
{
	if(argc < 2)
	{
		printf("invalid number of arguments\n");
		return 0;
	}
	if(!strcmp(argv[1], "about"))
	{
		printf("this program play reverse higher-lower with the user\n");
		return 0;
	}
	if(strcmp(argv[1], "play"))
	{
		printf("invalid arguments\n");
		return 0;
	}

	srand(time(NULL));
	char playerinput[INPUTLENGTH];
	int counter = 1, lowbound = 0, highbound = 100, tmpnum;

	do
	{
		tmpnum = rand()%(highbound-lowbound)+lowbound;
		printf("My guess is...");
		for(int i = 0; i < 6; i++)
		{
			fflush(stdout);
			putchar('.');
			usleep(100000);
		}
		printf("highbound - %d, lowbound - %d\n\n", highbound, lowbound);
		printf(" %d, am I right?", tmpnum);
		printf("\n(type 'right' if I'm right, 'lower' if your number is lower, 'higher' if your number is higher):\n");
		scanf("%s", playerinput);
		if(!strcmp(playerinput, "lower"))
		{
			if(tmpnum == 0 || highbound-lowbound < 2)
			{
				printf("No it isn't\n");
				continue;
			}
			highbound = tmpnum;
		}

		if(!strcmp(playerinput, "higher"))
		{
			if(tmpnum == 100 || highbound-lowbound < 2)
			{
				printf("No it isn't\n");
				continue;
			}
			lowbound = tmpnum+1;
		}

		counter++;
	}while(strcmp(playerinput, "right"));

	printf("it took %d attempts\n", counter);
	return 0;
}
