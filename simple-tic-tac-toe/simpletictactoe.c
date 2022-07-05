#include <stdio.h>

int checkForWin();
int drawBoard();
int checkBoard(int userInput);
int inputBoardP1(int userInput);
int inputBoardP2(int userInput);

int userInput=0;
char arrBoard[10]={'0','1','2','3','4','5','6','7','8','9'};

int main()
{
	
	int i=0;
	int count=0;	
	int temp=0;
	int userInput=0;
	drawBoard();
	for(i=0;i<9;i++)
	{
		for(i=0;i<=5;i++)
		{
			printf("\n   Player 1~ ");
			scanf("%d",&userInput);
			temp=checkBoard(userInput);

			if(temp==1)
			{			
				i--;
				continue;
			}
			else
			{
				inputBoardP1(userInput);
				drawBoard();
				break;	
			}
		}
	count++;	
	temp=0;
	temp=checkForWin();

	if(temp==1)
	break;		
		
	temp=0;
	temp=checkForWin();

	if(count>8 && temp== 0)
	{
		printf("That's a DRAW!\n");
		break;
	}

		for(i=0;i<=5;i++)
		{
			printf("\nPlayer 2~ ");
			scanf("%d",&userInput);
			temp=checkBoard(userInput);

			if(temp==1)
			{	
				i--;
				continue;
			}
			else
			{
			inputBoardP2(userInput);
			drawBoard();
			break;	
			}
		}
		count++;	
		temp=0;
		temp=checkForWin();

		if(temp==1)
		break;		
		temp=0;
		temp=checkForWin();

		if(count>8 && temp== 0)
		{
			printf("That's a DRAW!");
			break;
		}	
	}	
	return 0;
}

int checkForWin()
{
	int i=0;
	int shiftRow=3;
	int shiftColumn=1;

	for(i=1;i<shiftRow;i+=3)
	{
		if(arrBoard[i]=='X' && arrBoard[i+1]=='X' && arrBoard[i+2]=='X')
		{
			printf(" Player 1 Wins!\n");
			return 1;
			break;	
		}
		shiftRow+=3;
		if(shiftRow>9)
		break;		
	}
	for(i=1;i<=shiftColumn;i++)
	{
		if(arrBoard[i]=='X' && arrBoard[i+3]=='X' && arrBoard[i+6]=='X')
		{
			printf(" Player 1 Wins!\n");
			return 1;			
			break;
		}
		shiftColumn++;
		if(shiftColumn>3)
		break;
	}
	if(arrBoard[5]=='X' && arrBoard[3]=='X' && arrBoard[7]=='X' || 					        arrBoard[5]=='X' && arrBoard[1]=='X' && arrBoard[9]=='X')
		{
			printf(" Player 1 Wins!\n");
			return 1;
		}	
	shiftRow=3;
	shiftColumn=1;

	for(i=1;i<shiftRow;i+=3)
	{
		if(arrBoard[i]=='O' && arrBoard[i+1]=='O' && arrBoard[i+2]=='O')
		{
			printf(" Player 2 Wins!\n");
			return 1;			
			break;	
		}
		shiftRow+=3;
		if(shiftRow>9)
		break;
	}
	for(i=1;i<=shiftColumn;i++)
	{
		if(arrBoard[i]=='O' && arrBoard[i+3]=='O' && arrBoard[i+6]=='O')
		{
			printf(" Player 2 Wins!\n");
			return 1;			
			break;
		}
		shiftColumn++;
		if(shiftColumn>3)
		break;
	}
	if(arrBoard[5]=='O' && arrBoard[3]=='O' && arrBoard[7]=='O' || 					        arrBoard[5]=='O' && arrBoard[1]=='O' && arrBoard[9]=='O')
		{
			printf(" Player 2 Wins!\n");
			return 1;
		}

	return 0;
}

int drawBoard()
{
	printf("\n\n	TIC.TAC.TOE	\n\n");

	printf("Player 1 ~ (X) | Player 2 ~ (O)\n\n");

	printf("            |     |     \n");
	printf("         %c  |  %c  |  %c  \n",arrBoard[1],arrBoard[2],arrBoard[3]);
	printf("       _____|_____|_____\n");
	printf("            |     |     \n");
	printf("         %c  |  %c  |  %c \n",arrBoard[4],arrBoard[5],arrBoard[6]);
	printf("       _____|_____|_____\n");
	printf("            |     |     \n");
	printf("         %c  |  %c  |  %c  \n",arrBoard[7],arrBoard[8],arrBoard[9]);	
	printf("            |     |     \n\n");

	return 0;
}	

int checkBoard(int userInput)
{
	if(arrBoard[userInput]=='X' || arrBoard[userInput]=='O')
	{
		printf("Invalid Move");		
		return 1;
	}
	else if(userInput>9 || userInput<= 0)
	{
		printf("Invalid Move");		
		return 1;
	}
	return 0;
}

int inputBoardP1(int userInput)
{
	arrBoard[userInput] = 'X';
	return 0;
}

int inputBoardP2(int userInput)
{
	arrBoard[userInput] = 'O';
	return 0;
}









