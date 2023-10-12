void print_board() {
        for(int i=0; i<5; i++){
                printf("%c|%c|%c|%c|%c\n", board[i][0], board[i][1], board[i][2], board[i][3], board[i][4]);
        if (i< 4){
                printf("-----\n");
        }

        }
}

void init_board() {
        for(int i=0; i<5; i++){
        	for(int j=0; j<5; j++){
                	board[i][j] = ' ';
                }
        }
}

void player_move1() {
        printf("Player 1, Enter a space (1-25) and a letter(S or O): ");
        int space;
	char player;
        scanf("%d, %c", &space, &player);

        int row = (space -1)/5;
	int col = (space -1)%5;
        board[row][col] = player;
}

void player_move2() {
        printf("Player 2, Enter a space (1-25) and a letter(S or O): ");
        int space;
        char player;
        scanf("%d, %c", &space, &player);

        int row = (space -1)/5;
        int col = (space -1)%5;
        board[row][col] = player;
}
