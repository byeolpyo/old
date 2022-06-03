#include <stdio.h>

int min(int x, int y);
int max(int x, int y);
int gcd(int x, int y);
void relprime(int bot, int top, int p);

int min(int x, int y) {
	return x < y ? x : y;
}

int max(int x, int y) {
	return x > y ? x : y;
}

int gcd(int x, int y) {
	while(x != y)
	{
		if(x > y)
			x = x-y;
		else
			y = y-x;
	}
	return x;
}

void relprime(int bot, int top, int p) {
	for(int i = bot; i <= top; i++)
		if(!(gcd(p, i)-1))
			printf("%d ", i);
}

int main() {
	int a, b, p;
	printf("Podaj liczbe naturalna p i jakis przedzial liczbowy (q konczy program): ");
	while(scanf("%d %d %d", &p, &a, &b) == 3) {
		printf("Liczby wzglednie pierwsze do %i w przedziale [%i, %i]: ", p, min(a, b), max(a, b));
		relprime(min(a, b), max(a,b), p);
		printf("\nPodaj kolejna liczbe naturalna p i jakis przedzial liczbowy (q konczy program): ");
	}
	putchar('\n');
	return 0;
}


