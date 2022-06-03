#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define PASS 0
#define REROLL 1

#define MODE_SIMULATE 0
#define MODE_INTERACTIVE 1

void welcome_prompt();
unsigned int roll_dice(unsigned int);
int process_reroll(unsigned int, unsigned int, unsigned int, unsigned int);
int game(unsigned int, unsigned int, unsigned int);

void welcome_prompt() {
	printf("+++++++++++++++++++++++++\n");
	printf("+ WELCOME TO THE CASINO +\n");
	printf("+++++++++++++++++++++++++\n\n\n");

}

unsigned int roll_dice(unsigned int sides) {
	return rand()%sides+1;
}

int process_reroll(unsigned int mode, unsigned int score_player, unsigned int score_casino, unsigned int reroll_threshold) {
	if(mode == MODE_SIMULATE) {
		if(score_casino - score_player > reroll_threshold)
			return roll_dice(6);
		else
			return 0;
	}
	else if(mode == MODE_INTERACTIVE) {
		unsigned int decision;
		printf("Type 0 to pass, type 1 to reroll\n");
		scanf("%u", &decision);
		if(decision == PASS)
			return 0;
		if(decision == REROLL)
			return roll_dice(6);
	}
	return -1;

}


int game(unsigned int mode, unsigned int bet, unsigned int greed) {
	if(mode != MODE_INTERACTIVE && mode != MODE_SIMULATE)
		return 0;

	unsigned int score_player, score_casino;
	unsigned int reroll_counter = 0;
	int result = -1 * bet;

	score_player = roll_dice(12);
	score_casino = 2 * roll_dice(6);
	
	if(mode == MODE_INTERACTIVE)
		printf("Player score = %d, casino score = %d\n", score_player, score_casino);
	
	while(score_casino > score_player && reroll_counter < 2) {
		int reroll = process_reroll(mode, score_player, score_casino, greed);
		if(reroll == 0)
			break;
		if(reroll > 0) {
			reroll_counter++;
			score_player += reroll;
			if(mode == MODE_INTERACTIVE)
				printf("Player score = %d, casino score = %d\n", score_player, score_casino);
		}

	}


	if(score_casino > score_player) {
		result += bet * (pow(reroll_counter, 2) + 1);
		if(mode == MODE_INTERACTIVE)
			printf("You won!\n");
	}
	else
		if(mode == MODE_INTERACTIVE)
			printf("You lost!\n");
	

	return result;
}
