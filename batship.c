//Auothor: Olivia Hall
//Final Project Due 7/26/24

#include <stdio.h>
#include <stdbool.h>
#define DIM 10
#define FILE_NAME "easy.txt"

void loadShips(FILE* fp, char board[][DIM]);
void displayCells(char board [][DIM]);
int getMove(int* rowPtr, int* colPtr);
void uncover(FILE* fp, char ships[][DIM], char board[][DIM]);

int main () {
	int rowInd, colInd;
	char batship[DIM][DIM];
	char ships[DIM][DIM];
	FILE* fp = fopen(FILE_NAME,"r");
		if(fp == NULL){
			printf("Cannot open file.\n");
		return 0;
		}
		
	printf("*****LET'S PLAY BATSHIP*****\n\n");
	
	//while (playGame == false){ 
	loadShips(fp, ships);
	displayCells(batship);
	uncover(fp, ships, batship);
	displayCells(batship);
	fclose(fp);
	
return 0;
}


void loadShips(FILE* fp, char ships[][DIM]){
	char temp;
	for(int row = 0; row < DIM; row++){
		for(int col = 0; col < DIM; col++){
			fscanf(fp, "%c", &ships[row][col]);
		}
		fscanf(fp, "%c", &temp);
	}
}


void displayCells(char board [][DIM]){
	int rowNum = 1; 
	char colLet = 'A';
	printf("  ");
	while(colLet <= 'J'){
		printf(" %c", colLet++);
	}
		printf("\n");
	for(int rowInd = 0; rowInd < DIM; rowInd++){
		printf(" %d", rowNum++);	
		for(int colInd = 0; colInd < DIM; colInd++){
			printf(" %c", board[rowInd][colInd]);
		}
		printf("\n");
	}
}	


//bool playGame(int num){
	//if all the ship spots in the file have been uncovered rerturn true
	
int getMove(int* rowPtr, int* colPtr){
	char colLet;
	int rowNum;
	printf("       FIRE AWAY!\n(enter a spot in the grid like A1)\n");
	
	scanf(" %c%d", &colLet, &rowNum);
		if (rowNum >= 1 && rowNum <= 10){
		*rowPtr = rowNum - 1;
		}
		else {
		printf("Invalid row number. Try again\n");
		} 
		if (colLet >= 'A' && colLet <= 'J'){
		*colPtr = colLet-'A';
		}
		else{
		printf("Invalid column number. Try again\n");
		}
return 0;	
}

void uncover(FILE* fp, char ships[][DIM], char board[][DIM]){
	int rowMove, colMove;
	int row, col;
	char temp;
	getMove(&rowMove, &colMove);
	
	for(row = 0; row < DIM; row++){
		for(col = 0; col < DIM; col++){
			if(board[rowMove][colMove] = ships[row][col] && ships[row][col] == ' '){
			board[rowMove][colMove] == 'O';
			printf("%c", board[rowMove][colMove]);
			}
			else if(board[rowMove][colMove] = ships[row][col] && ships[row][col] == 'S'){
			board[rowMove][colMove] == 'X';
			printf("%c", board[rowMove][colMove]);
			}
			
			}
		printf("\n");		
		}
		
	
}
	
		 

//void showScores()
