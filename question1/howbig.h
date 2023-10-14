#include <stdio.h>

void how_big()
{

        printf("The board is nxn, how big do you want n to be (1-50)\n");
        do
        {
                scanf("%d", &n);
        } while((n==0) && (n>50));
	
	return;
}

