#include <stdio.h>
#include <stdlib.h>

void init_board (void);
void draw_board (void);
int numb_players (void);
int play_again (void);
int square_valid (int);
int game_done (void);
int find_sos (int, int, char);
void two_player (void);
int find_square (void);
void player_move(int);
void comp_play(void);
void comp_move(void);
void winner (void);
int comp_find_os (void);
int comp_find_ss (void);
void how_big(void);


char board[5][5];
int Player1, Player2, Computer, players;

int main ()
{
	while(1)
	{
		how_big();
		init_board();
		if(numb_players()==1)
		{
			players=1;
			comp_play();
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
