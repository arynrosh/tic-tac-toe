/*TIC-TAC-TOE BY ARYAN ROSHAN*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define SIZE 3

// Function to change between players 'X' and 'O' each round
char changePlayer(char player) {
    if (player == 'X') {
        player = 'O';
    } 
    else {
        player = 'X';
    }
    return player;
}

// Function to print the tic-tac-toe board
void printBoard(char board[SIZE][SIZE]) {
    printf("\n");
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            printf(" %c ", board[i][j]);
            if (j < SIZE - 1)
                printf("|");
        }
        printf("\n");
        if (i < SIZE - 1)
            printf("-----------\n");
    }
    printf("\n");
}

// Function to check if a player has won
bool checkWin(char board[SIZE][SIZE], char player) {
    for (int i = 0; i < SIZE; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return true; // Check rows
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
            return true; // Check columns
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return true; // Check forward diagonal
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
        return true; // Check backward diagonal

    return false; // No win condition was met
}

// Function to check if the board is full
bool isBoardFull(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j < SIZE; j++){
            if (board[i][j] == ' '){
                return false; // There is an empty space on the board
            }
        }
    }
    return true; // The board is filled up
}

int main() {
    int row;
    int col;
    char player1[200];
    char player2[200];
    char player = 'X';
    char board[SIZE][SIZE] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };
    
    // Introduces the game to the player
    printf("Welcome to Tic-Tac-Toe by Aryan Roshan\n"); 
    
    printf("Player 1, Please enter your name:\n"); //Asks for the first player's name
    scanf("%199s", player1);
    while(getchar() != '\n');
    
    printf("Player 2, Please enter your name:\n"); //Asks for the second player's name
    scanf("%199s", player2);
    while(getchar() != '\n');
    
    printf("%s will be X and %s will be O.\n", player1, player2); //Assigns players to their respective characters
    printf("%s starts first.\n", player1); //Prompts the player assigned to X to start first


    while(1) {
    printBoard(board); // Prints the current state of the tic-tac-toe board

    // Determines which player's turn it is and prompt for their move
    if (player == 'X')
        printf("%s, enter your move.\n", player1);
    else
        printf("%s, enter your move.\n", player2);

    printf("Row (0-2): ");
    scanf("%d", &row); // Reads the row input from the player
    printf("Column (0-2): ");
    scanf("%d", &col); // Reads the column input from the player

    // Checks if the player's move is valid
    if (row < 0 || row >= SIZE || col < 0 || col >= SIZE || board[row][col] != ' ') {
        printf("Invalid move, please try again.\n");
        continue;
    }

    board[row][col] = player; // Updates the board with the player's move

    // Checks if the current player has won the game
    if (checkWin(board, player)) {
        printBoard(board); // Print the final board state
        if (player == 'X')
            printf("Congratulations %s! You win!\n", player1); // Prints a winning message for Player X
        else
            printf("Congratulations %s! You win!\n", player2); // Prints a winning message for Player O
        break; // Exit the game loop
    }

    // Checks if the board is full (a tie)
    if (isBoardFull(board)) {
        printBoard(board); // Prints the final board state
        printf("It is a tie!!\n"); // Prints a tie message
        break; // Exits the game loop
    }

    player = changePlayer(player); // Switches to the other player's turn
    }

    return 0; // Exits the program
}