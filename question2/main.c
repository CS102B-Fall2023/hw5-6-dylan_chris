#include <stdio.h>
#include <sos.h>

char board[50][50];
int Player1, Player2, Computer, players, n;

int main ()
{
        while(1)
        {
                how_big();
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
                        printf("Game done!\n");
                        winner();

                        if (!play_again())
                        {
                                break;
                        }

                }
        }
        return 0;
}
