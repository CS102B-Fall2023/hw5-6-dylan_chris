#include <stdio.h>

int Player1, Player2, Computer, players, n;
void how_big()
{

        printf("The board is nxm, how big do you want n to be (1-50)\n");
        do
        {
                scanf("%d", &n);
        } while((n==0) && (n>50));
	
	return;
}

