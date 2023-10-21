#include <stdio.h>
#include <stdlib.h>

void init_board (void);
void draw_board (void);
int number_players (void);
int play_again (void);
int square_valid (int);
int game_done (void);
int find_sos (int, int, char);
void two_player (void);
int find_square (void);
void player_move(int);
void computer_play(void);
void computer_move(void);
void winner (void);
int computer_find_ss (void);

char board[5][5];
int Player1, Player2, Computer, players;


void init_board()
{
	for (int row = 0; row < 5; row++)
	{
		for (int col=0; col<5; col++)
		{
			board[row][col]=' ';
		}
	}
	Player1 = 0;
	Player2 = 0;
	Computer = 0;
	
	return;
}

void draw_board()
{
        printf("----------\n");
	for(int i = 0; i < 5; i++)
        {
		printf("|%c|%c|%c|%c|%c|\n", board[i][0], board[i][1], board[i][2], board[i][3], board[i][4]);
	if(i < 5){
		printf("----------\n");
                }
	}
	printf("\n");		
	if (players == 1)
	{
		printf("Player: %d  Computer: %d \n", Player1, Computer);
	}
	else if (players == 2)
	{
		printf("Player 1: %d Player 2: %d\n", Player1, Player2);
	}
	return;
}

int number_players()
{
	char answer;
	
	printf("How many players are playing? (1 or 2)\n");
	do 
	{
		answer = getchar();
	} while((answer !='1') && (answer !='2'));
	
	if(answer == '1')
	{
		return 1;
	}
	else
	{
		return 2;
	}
}


int play_again()
{
  char response;

  printf("Would you like to play again? (y/n) \n");
  do
  { 
    response = getchar();

  }while ((response != 'y') && (response != 'Y') &&
       (response != 'n') && (response != 'N'));

  if ((response == 'y') || (response == 'Y'))
  {
     return 1;
  }
  else if (response == 'n'|| response == 'N')
  {
    return 0;
  }
}

int game_done()
{
	int row, col;
	
	for (row=0; row<5; row++)
	{
		for(col=0; col<5; col++)
		{
			if (board[row][col] == ' ')
			{
				return 0;
			}
		}
	}
        return 1;
}

int square_valid (int square)
{
   int row, col;
   
   if(square>0 && square<26)
   {	
	row = (square-1)/5;
	col = (square-1)%5;

	if (board[row][col]==' ')
	{
		return 1;
	}
	else 
	{
		return 0;
	} 
  }
  else
  {
	return 0;	
  }
}

void two_player()
{
	do
	{
		player_move(1);
		if(game_done())
		{ 
			return;
		}
		player_move(2);
	}while (!game_done());

	return;	
}

void player_move(int player)
{
  int square;
  int row, col;
  char symbol;

  do
  {
	draw_board();
        printf("\nPlayer %d enter a square: \n",player);

	do
	{
		scanf("%d", &square);
	}while (!square_valid(square));

	row = (square-1)/5;
	col = (square-1)%5;
	
	printf("Pick a letter (S or O)\n");
	do
	{
		symbol = getchar();
	}while (symbol != 'S' && symbol != 's' && symbol != 'O' && symbol != 'o');

	if((symbol == 'S') || (symbol == 's'))
	{
		symbol = 'S';
	}
	else 
	{
		symbol = 'O';	
	}

	board[row][col] = symbol;
   }while(find_sos (square, player, symbol)); 
   
   return;
}

int find_sos (int square, int player, char symbol)
{
	int row,col,sos;
	
	row = (square-1)/5;
	col = (square-1)%5;
	sos = 0;
	
  if(symbol == 'S')
  {
	if (board[row][col-2] == 'S' && board[row][col-1] == 'O')
	{
		sos++;
	}
	if ((board[row][col+1]== 'O') && (board[row][col+2] == 'S'))
	{
		sos++;
	}	
	if((board[row+1][col] == 'O') && (board[row+2][col] == 'S'))
	{
		sos++;
	}
	if((board[row-1][col] == 'O') && (board[row-2][col] == 'S'))
	{
		sos++;
	}
	if((board[row+1][col+1] == 'O') && (board[row+2][col+2] == 'S'))
	{
		sos++;
	}
	if((board[row-1][col-1] == 'O') && (board[row-2][col-2] == 'S'))
	{
		sos++;
	}
	if((board[row+1][col-1] == 'O') && (board[row+2][col-2] == 'S'))
	{
		sos++;
	}
	if((board[row-1][col+1] == 'O') && (board[row-2][col+2] == 'S'))
	{
		sos++;
	}
  }
  else if(symbol == 'O')
  {
	if((board[row+1][col] == 'S') && (board[row-1][col] == 'S'))
	{
		sos++;
	}
	if((board[row][col+1] == 'S') && (board[row][col-1] == 'S'))
	{
		sos++;
	}
	if((board[row+1][col+1] == 'S') && (board[row-1][col-1] == 'S'))
	{
		sos++;
	}
	if((board[row+1][col-1] == 'S') && (board[row-1][col+1] == 'S'))
	{
		sos++;
	}
  }



        if (player == 1)
        {
                Player1= Player1+sos;
        }
        else if (player == 2)
        {
                 Player2= Player2+sos;
        }
        else if (player == 3)
        {
                 Computer= Computer+sos;
        }
	


	if (sos>0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void winner()
{
	if ((Player1 > Player2) && (Player1 > Computer))
	{
		printf("Player 1 won!\n");
	}
	else if (Player2> Player1)
	{
		printf("Player 2 won!\n");
	}
	else if (Computer > Player1)
	{ 
		printf("Computer won!\n");
	}
	else
	{
		printf("Game is a draw\n");
	}
}

void computer_play()
{
	do
	{
		player_move(1);
		if (!game_done())
		{
			computer_move();
		}
	}while(!game_done());

	return;
}

int find_square()
{
	int row, col, square;
	
	for (square = 1; square < 26; square++)
	{
		row = (square-1)/5;
		col = (square-1)%5;
		if (board[row][col] == ' ')
		{
			return square;
		}
	}
	return 0;
}

void computer_move()
{
	
  int square;
  int row, col;
  char symbol;

  do
  {
        draw_board();
	
	if(computer_find_ss())
	{
		square = computer_find_ss();
		symbol = 'O';
	}
	else
	{
		square = find_square();
		symbol = 'S';
	}
	row = (square-1)/5;
	col = (square-1)%5;
        
   	board[row][col] = symbol;
	printf("I am putting a %c in %d square\n", symbol, square);
   }while(find_sos (square, 3, symbol));

   return;
}


int computer_find_ss()
{
	int square;

        for (int ii=0; ii<5; ii++)
        {
                for(int jj=0; jj<5; jj++)
                {  
                   square = ((ii*5) +jj)+1;

                   if(square_valid(square))
                   {

		        if((board[ii][jj+1]=='S') && (board[ii][jj-1] == 'S'))
                        {
                                return square;
                        }
                        if ((board[ii+1][jj] == 'S') && (board[ii-1][jj] =='S'))
                        {
                                return square;
                        }
                        if((board[ii+1][jj+1] == 'S') && (board[ii-1][jj-1] == 'S'))
                        {
                                return square;
                        }
                        if((board[ii+1][jj-1] == 'S') && (board[ii-1][jj+1] == 'S'))
                        {
                                return square;
                        }
                  }
		}
        }
	return 0;
}
