//source code of our project Game "Tic tac toe"


//include header files

#include <stdio.h> 
#include <stdbool.h>

//Declare board size using two dimentional array with size 3

char board[3][3]; /*board is assumed to be declared glabaly*/

//Initialize the game board with empty spaces with the help of for loop

void initializeBoard() {
    for (int i = 0; i < 3; i++) { //loop over rows (0, 1 ,2)
        for (int j = 0; j < 3; j++) { //loop over colomns (0 , 1 , 2)
            board[i][j] = ' '; //set each sell to an empty space
        }
    }
}


//clear the screen after each run 

void clearScreen() {
    printf("\033[H\033[J");  /* /033 -> represents the escape character(ESC)*/
}

//Display the game board

void printBoard() {
    printf("\n");/*print a blank line to add some spacing before the board*/
    printf("  1   2   3\n");/*prints the column numbers at the top of the board*/
    printf("1 %c | %c | %c\n", board[0][0], board[0][1], board[0][2]);/*print row of the board*/
    printf("  ---------\n");/*print a horizontal divider line b/w rows*/
    printf("2 %c | %c | %c\n", board[1][0], board[1][1], board[1][2]);/*Prints row 2 with its row number (2).*/
    printf("  ---------\n");
    printf("3 %c | %c | %c\n", board[2][0], board[2][1], board[2][2]);/*Prints row 3 of the board.*/
}

//Check if the Game is over

bool isGameOver() {
    // Check rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][0] == board[i][2]) {//condition for winning in a row
            return true;
        }
    }

    // Check columns
    for (int j = 0; j < 3; j++) {
        if (board[0][j] != ' ' && board[0][j] == board[1][j] && board[0][j] == board[2][j]) { // condition for winning in a column
            return true;
        }
    }

    // Check diagonals
    if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[0][0] == board[2][2]) {//conditon for winning in diagonal
        return true;
    }
    if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[0][2] == board[2][0]) {
        return true;
    }

    // Check for a draw
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }

    return true;
}

//Determine the winner

char getWinner() {
    // Check rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][0] == board[i][2]) {
            return board[i][0];
        }
    }

    // Check columns
    for (int j = 0; j < 3; j++) {
        if (board[0][j] != ' ' && board[0][j] == board[1][j] && board[0][j] == board[2][j]) {
            return board[0][j];
        }
    }

    // Check diagonals
    if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[0][0] == board[2][2]) {
        return board[0][0];
    }
    if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[0][2] == board[2][0]) {
        return board[0][2];
    }

    return ' '; // No winner
}


//Implement the main game loop with main function

int main() {
    initializeBoard();
    int currentPlayer = 1;

    while (1) {
        clearScreen();
        printf("Current board state:\n");
        printBoard();

        int row, col;
        printf("Player %d, please enter a row and column (e.g., 1 2):", currentPlayer);

        while (scanf("%d %d", &row, &col) != 2) {
            printf("Invalid input, please try again: ");
            while (getchar() != '\n');
        }

        if (row < 1 || row > 3 || col < 1 || col > 3 || board[row - 1][col - 1] != ' ') {
            printf("Invalid move, please try again.\n");
        } else {
            if (currentPlayer == 1) {
                board[row - 1][col - 1] = 'X';
                currentPlayer = 2;
            } else {
                board[row - 1][col - 1] = 'O';
                currentPlayer = 1;
            }
        }

        if (isGameOver()) {
            clearScreen();
            printf("Game over!\n");
            printBoard();
            char winner = getWinner();
            if (winner != ' ') {
                printf("Player %c wins!\n", winner);
            } else {
                printf("It's a draw!\n");
            }
            break;
        }
    }

    return 0;
}
