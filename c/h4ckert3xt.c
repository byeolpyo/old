#include <stdio.h>
#include <unistd.h>

void printH4ck3r_char(const char ch);
void printH4ck3r_str(const char * str);

void printH4ck3r_char(const char ch)
{
	fflush(stdout);
	if(ch == '\n')
		usleep(200000);
	putchar(ch);
	usleep(50000);
}

void printH4ck3r_str(const char * str)
{
	int i = 0;
	while(*(str + i) != '\0')
	{
		fflush(stdout);
		if(str[i] == '\n')
			usleep(200000);
		putchar(str[i]);
		if(str[i] == ',')
			usleep(200000);
		usleep(50000);
		i++;
	}
}


int main(void)
{
	char ch;
	while((ch = getchar()) != EOF)
		printH4ck3r_char(ch);
	return 0;
}