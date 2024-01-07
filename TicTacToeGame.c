#include<Stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<time.h>

char board[3][3];	//globle vriables
const char PLAYER = 'X';
const char COMPUTER = 'O';

void resetBord();
void printBoard();
int checkFreeSpace();
void playerMove();
void computerMove();
char checkWinner();
void printWinner(char);

int main(){
	
	char win = ' ';		//empty, no winner
	
	resetBord();
	printBoard();
	
	return 0;
}

void resetBord(){
	
	int i, j;
	
	for(i = 0; i < 3; i++){		//nested for loop
		
		for(j = 0; j < 3; j++){
			board[i][j] = ' ';		//empty cahr
		}
	}
}

void printBoard(){
	
	printf(" %c  |  %c | %c ", board[0][0], board[0][1], board[0][2]);
	printf("\n----|----|----\n");
	
	printf(" %c  | %c  | %c ", board[1][0], board[1][1], board[1][2]);
	printf("\n----|----|----\n");
	
	printf(" %c  | %c  | %c ", board[2][0], board[2][1], board[2][2]);
	printf("\n");
}

int checkFreeSpace(){
}

void playerMove(){
}

void computerMove(){
}

char checkWinner(){
}

void printWinner(char win){
}
