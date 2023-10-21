#include <stdio.h>
#include <stdlib.h>

void init_board (void);
void draw_board (void);
int number_players (void);
int play_again (void);
int open_square (int);
int game_done (void);
int find_sos (int, int, char);
void two_player (void);
int find_square (void);
void player_move(int);
void computer_play(void);
void computer_move(void);
void winner (void);
int comp_find_ss (void);



char board[5][5];
int Player1, Player2, Computer, players;

int main ()
{
	while(1)
	{
		
		init_board();
		if(numb_players()==1)
		{
			players=1;
			computer_play();
		}
		else
		{
			players=2;
			two_player();
		}
                if(game_done())
                {
                        printf("Game over\n");
			winner();
			
			if (!play_again())
                	{
                        	break;
                	}

                }
	} 	
	return 0;
}
