#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <stdbool.h>
#include <windows.h>
#include <MMsystem.h>

/* FUNCTION PROTOTYPE */
char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
void drawBoard();
char currentMark;
int currentPlayer;

/* FUNCTION DEFINITION */
void drawBoard()
{
    system("cls");
    printf("\n");
    printf("\n|\t|\t|\t|");
    printf("\n|   %c\t|   %c\t|   %c\t|", board[0][0], board[0][1], board[0][2]);
    printf("\n|\t|\t|\t|");
    printf("\n|-------|-------|-------|");
    printf("\n|\t|\t|\t|");
    printf("\n|   %c\t|   %c\t|   %c\t|", board[1][0], board[1][1], board[1][2]);
    printf("\n|\t|\t|\t|");
    printf("\n|-------|-------|-------|");
    printf("\n|\t|\t|\t|");
    printf("\n|   %c\t|   %c\t|   %c   |", board[2][0], board[2][1], board[2][2]);
    printf("\n|\t|\t|\t|");

} //end drawBoard function

/* FUNCTION DEFINITION */
bool placeMark(int slot)
{
    int row = slot / 3;
    int col;
    if(slot % 3 == 0){

        row = row - 1;
        col = 2;
    }else
        col = (slot % 3) - 1;

    if(board[row][col] != 'X' && board[row][col] != 'O'){
            board[row][col] = currentMark;
            return true;
    }else
        return false;

}//end placeMark function

/* FUNCTION DEFINITION */
int whoWin()
{
    int i = 0;
    for(i = 0; i < 3; i++){

        //rows
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2]){
            return currentPlayer;
        }

        //rows
        if(board[0][i] == board[1][i] && board[1][i] == board[2][i]){
            return currentPlayer;
        }
    }
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2]){
        return currentPlayer;
    }
    if(board[0][2] == board[1][1] && board[1][1] == board[2][0]){
        return currentPlayer;
    }
        return 0;
}// end whoWin function

/* FUNCTION DEFINITION */
void swap_player_and_marker()
{

    if(currentMark == 'X'){
        currentMark = 'O';
        }else
            currentMark = 'X';

    if(currentPlayer == 1){
        currentPlayer = 2;
        }else
            currentPlayer = 1;
}//end swap_play_and_marker function

/* FUNCTION DEFINITION */
void game()
{
    printf("\n\tWELCOME TO Tic-Tac-Toe Game\n\t     Made by: Keyan\n");
    printf("\nPlayer one, choose your marker (X or O): ");
    char marker_pl = '\0';
    scanf("%c", &marker_pl);

    currentPlayer = 1;
    currentMark = marker_pl;

    drawBoard();
    int i = 0;
    int playerWon;

    for(i = 0; i < 9; i++){
        printf("\nIt's player %d turn. Enter your slot: ", currentPlayer);
        int slot;
        scanf("%d", &slot);


        if(slot < 1 || slot > 9){
            printf("\nThat slot is invalid! Try another slot");
            i--;
            continue;
        }

        if(!placeMark(slot)){
            printf("\nThat slot is occupied! Try another slot");
            i--;
            continue;
        }
        drawBoard();

        playerWon = whoWin();

        if(playerWon == 1){
            printf("\nPlayer %d won!", currentPlayer);
            break;
        }else if(playerWon == 2){
            printf("\nPlayer %d won!", currentPlayer);
            break;
        }

        swap_player_and_marker();
    }

    if(playerWon == 0){
        printf("\nTie game!");
    }
}//end game function

int main()
{
    system("color 1f");
    game();
    return 0;
}
