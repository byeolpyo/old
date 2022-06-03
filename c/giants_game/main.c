#include "game_functions.h"
#include <string.h>

struct result {
	float winratio;
	int bankruptcy;
};


/* simulate a game starting with <balance> of money, betting <bet> each round,
 * greed how conservative the player is with the bets;
 * essentially, if the difference between the player's and the casino's score is more than greed, the player rerolls 
 * repeats is the cap on how many bets the player will make regardless of current balance */

struct result simulate_session(int balance, int bet, int greed, int repeats) {
	struct result res;

	const int first_balance = balance;
	int casinowins = 0, bet_size;
	float winratio;

	int i;
	for(i = 0; i < repeats; i++) {
		bet_size = bet;
		if(balance < bet_size)
			bet_size = balance;
		int game_result = game(MODE_SIMULATE, bet_size, greed); 
		balance += game_result;
		if(game_result < 0)
			casinowins++;
		winratio = 100*casinowins/(i+1);
		float return_percent = 100*balance/first_balance;
		if(balance <= 0)
			break;	
	}
	res.winratio = winratio;
	res.bankruptcy = i;
	return res;
}

void check_cmd_args(int argc, char* argv[]) {
    for(int i = 2; i < argc; i++) {
        strcat(argv[1], argv[i]);
    }

    if(argc != 5 || !strspn(argv[1], "012345678)")) {
        printf("usage: %s <balance> <bet> <greed> <repeats>\n", argv[0]);
        exit(0);
    }
    return;
}

int main(int argc, char* argv[]) {
	srand(time(NULL));
	struct result tmp;

    check_cmd_args(argc, argv);

    int balance = atoi(argv[1]);
    int bet = atoi(argv[2]);
    int greed = atoi(argv[3]);
    int repeats = atoi(argv[4]);

	float average_winratio = 0, average_bankrupt = 0;
	unsigned int games = 50000;
	for(int i = 0; i < games; i++) {
		tmp = simulate_session(10000, 100, 3, 10000);
		average_winratio += tmp.winratio;
		average_bankrupt += tmp.bankruptcy;
	}

	printf("average winratio = %f, average bankruptcy = %f\n", average_winratio/games, average_bankrupt/games);

	return 0;
}
