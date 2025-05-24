#include <stdio.h>

char board[3][3];
char currentPlayer;

void initializeBoard() {
    for(int i=0; i<3; i++)
        for(int j=0; j<3; j++)
            board[i][j] = ' ';
}

void printBoard() {
    printf("\n");
    printf("  0   1   2\n");
    for(int i=0; i<3; i++) {
        printf("%d ", i);
        for(int j=0; j<3; j++) {
            printf(" %c ", board[i][j]);
            if(j < 2) printf("|");
        }
        printf("\n");
        if(i < 2) printf("  ---|---|---\n");
    }
    printf("\n");
}

int checkWin() {
    // Rows and Columns
    for(int i=0; i<3; i++) {
        if(board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer)
            return 1;
        if(board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer)
            return 1;
    }
    // Diagonals
    if(board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer)
        return 1;
    if(board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)
        return 1;

    return 0;
}

int checkDraw() {
    for(int i=0; i<3; i++)
        for(int j=0; j<3; j++)
            if(board[i][j] == ' ')
                return 0; // still empty spaces
    return 1; // draw
}

void switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

void playGame() {
    int row, col;
    currentPlayer = 'X';
    while(1) {
        printBoard();
        printf("Player %c, enter row and column (0-2): ", currentPlayer);
        scanf("%d %d", &row, &col);
        if(row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ') {
            printf("Invalid move! Try again.\n");
            continue;
        }
        board[row][col] = currentPlayer;

        if(checkWin()) {
            printBoard();
            printf("Player %c wins!\n", currentPlayer);
            break;
        }
        if(checkDraw()) {
            printBoard();
            printf("It's a draw!\n");
            break;
        }
        switchPlayer();
    }
}

int main() {
    initializeBoard();
    playGame();
    return 0;
}
