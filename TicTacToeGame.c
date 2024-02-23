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
	char response;
	
	do{
		
		win = ' ';
		response = ' ';
		
		resetBord();
	
		while(win == ' ' && checkFreeSpace() != 0){
		
			printBoard();
		
			playerMove();		
		
			win = checkWinner();
		
			if(win != ' ' || checkFreeSpace() == 0){
				break;
			}
		
			computerMove();		
		
			win = checkWinner();
		
			if(win != ' ' || checkFreeSpace() == 0){
				break;
			}
		}
	
		printBoard();
		printWinner(win);
		
		printf("Would you like to play again? (Y/N) : ");
		scanf(" %c");
		scanf(" %c", &response);
		response = toupper(response); 
		
	}while(response == 'Y');
	
	printf("Thank you for playing..!");
	
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
	int freeSpace = 9;
	int i,j;
	
	for(i = 0; i < 3; i++){
		
		for(j = 0; j < 3; j++){
			
			if(board[i][j] != ' '){
				freeSpace--;
			}
		}
	}
	
	return freeSpace;
}

void playerMove(){
	
	int x,y;
	
	do{
		
		printf("Enter Row number Please (1 to 3) : ");
		scanf("%d", &x);
		x--;
	
		printf("Enter Column number Please (1 to 3) : ");
		scanf("%d", &y);
		y--;
	
		if(board[x][y] != ' '){
		printf("Invalid Move..!\n");
		}
		else{
			board[x][y] = PLAYER;
			break;
		}
		
	}while(board[x][y] != ' ');
}

void computerMove(){
	
	//creates a seed base on ciurrent time 
	
	srand(time(0));
	
	int x,y;
	
	if(checkFreeSpace() > 0){
		
		do{
	
			x = rand() % 3;
			y = rand() % 3;
		
		}while(board[x][y] != ' ');
		
		board[x][y] = COMPUTER;
	}
	else{
		printWinner(' ');
	}
}

char checkWinner(){
	
	int i;
	
	//check rows
	for(i = 0; i < 3; i++){
		
		if(board[i][0] == board[i][1] && board[i][0] == board[i][2]){
			return board[i][0];
		}
	}
	
	//check columns
	for(i = 0; i < 3; i++){
		
		if(board[0][i] == board[1][i] && board[0][i] == board[2][i]){
			return board[0][1];
		}
	}
	
	//check Diagonals
	for(i = 0; i < 3; i++){
		
		if(board[0][0] == board[1][1] && board[0][0] == board[2][2]){
			return board[0][0];
		}
	}
	
	for(i = 0; i < 3; i++){
		
		if(board[0][2] == board[1][1] && board[0][2] == board[2][0]){
			return board[0][2];
		}
	}
	
	return ' ';
}

void printWinner(char win){
	
	if(win == PLAYER){
		printf("Congratulation..! You Win");
	}
	else if(win == COMPUTER){
		printf("You Lose..!");
	}
	else{
		printf("It is a Draw");
	}
}
