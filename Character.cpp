// Character.cpp

#define _CRT_SECURE_NO_WARNINGS // this define needs to be as the first comnend outherwise it will not work

#include <stdio.h>
#include "Character.h"

//---------------------------------------------------------------------------------------
//										Add Character
//										----------
//
// General		: Add an character to the board.
//
// Parameters	:
//		ioarrnBoard			- The playing board we wish to add our character to.	(In\Out)
//		ionttCharacter		- The character we wish to add.							(In\Out)
//
// Return Value : None
//
//---------------------------------------------------------------------------------------
void AddCharacter(char	ioarrnBoard[][SIZE_OF_BOARD], Character* ionttCharacter)
{
	// Code section
	if (ionttCharacter->cSign == 'B')
	{
		printf("Please enter bully position: \n");
	}
	else
	{
		printf("Please enter the bear position: \n");
	}

	printf("Please enter the row: ");
	scanf("%d", &(ionttCharacter->nRow));
	printf("Please enter the column: ");
	scanf("%d", &(ionttCharacter->nCol));

	// Match to start from 0 
	ionttCharacter->nRow--;
	ionttCharacter->nCol--;

	// Inser the character into the board
	ioarrnBoard[ionttCharacter->nRow][ionttCharacter->nCol] = ionttCharacter->cSign;
}

//---------------------------------------------------------------------------------------
//										Move Bully
//										----------
//
// General		: Move the player character.
//
// Parameters	:
//		ioarrnBoard		- The playing board we wish to move bully at.	(In\Out)
//		ionttBully		- Bully the character we wish to move.			(In\Out)
//		inDirection		- The direction the player wish to move bully. 	(In)
//
// Return Value : Whether or not we peaked up a dot.
//
//---------------------------------------------------------------------------------------
int MoveBully(char		ioarrnBoard[][SIZE_OF_BOARD],
			  Character* ionttBully,
			  int		inDirection)
{
	// Variable definition
	int nBullyNewRow = ionttBully->nRow;
	int nBullyNewCol = ionttBully->nCol;
	int nIsOnDot = 0;

	// Code section
	switch (inDirection)
	{
	case (1):
		nBullyNewCol++;

		break;
	case (2):
		nBullyNewCol--;

		break;
	case (3):
		nBullyNewRow--;

		break;
	case (4):
		nBullyNewRow++;

		break;

	default:

		break;
	}

	// Check if we are not walking into a wall
	if ((ioarrnBoard[nBullyNewRow][nBullyNewCol] != '*') &&
		(nBullyNewCol < SIZE_OF_BOARD) && (nBullyNewCol >= 0) &&
		(nBullyNewRow < SIZE_OF_BOARD) && (nBullyNewRow >= 0))
	{
		// Check if we peaked up a dot
		nIsOnDot = ioarrnBoard[nBullyNewRow][nBullyNewCol] == '.';

		// Move bully on the board
		ioarrnBoard[ionttBully->nRow][ionttBully->nCol] = ' ';
		ioarrnBoard[nBullyNewRow][nBullyNewCol] = ionttBully->cSign;

		// Chang the main postion into the new one
		ionttBully->nRow = nBullyNewRow;
		ionttBully->nCol = nBullyNewCol;
	}

	return (nIsOnDot);
}

//---------------------------------------------------------------------------------------
//										Compare
//										-------
//
// General		: Compare numbers.
//
// Parameters	:
//		inFirst		- The place we wish to get to.				(In)
//		inSecond	- The place we are from.					(In)
//
// Return Value : Returns 1 if inTo is greater than inFrom,
//				  -1 if inTo is less than inFrom,
//				  and 0 if they are equal.
//
//---------------------------------------------------------------------------------------
int Compare(int inFirst, int inSecond)
{
	// Code section
	// This expression uses boolean logic to compare inFirst and inSecond:
	// If inFirst > inSecond, the left side is 1, the right side is 0, resulting in 1.
	// If inFirst < inSecond, the left side is 0, the right side is 1, resulting in -1.
	// If inFirst == inSecond, both sides are 0, resulting in 0.
	return (inFirst > inSecond) - (inFirst < inSecond);
}

//---------------------------------------------------------------------------------------
//										Move Bear
//										---------
//
// General		: Move the enemy towards the player.
//
// Parameters	:
//		ioarrnBoard		- The playing board we wish to move bully at.	(In\Out)
//		ionttBully		- Bully the character the enemy try to catch.	(In\Out)
//		ionttBear		- The enemy we move towards our character.		(In\Out)
//		ionIsOnDot		- Whether or not the bear is standing on a dot. (In\Out)
//
// Return Value : Whether or not the bear caught us.
//
//---------------------------------------------------------------------------------------
int MoveBear(char		ioarrnBoard[][SIZE_OF_BOARD],
			 Character	ionttBully,
			 Character*	ionttBear,
			 int*		ionIsOnDot)
{
	// Variable definition
	int nBearNewRow = ionttBear->nRow;
	int nBearNewCol = ionttBear->nCol;
	int nDidWeCatchBully = 0;

	// Code section
	nBearNewRow += Compare(ionttBully.nRow, nBearNewRow);
	nBearNewCol += Compare(ionttBully.nCol, nBearNewCol);

	// Check if we are not walking into a wall.
	if ((ioarrnBoard[nBearNewRow][nBearNewCol] != '*') &&
		(nBearNewCol < SIZE_OF_BOARD) && (nBearNewCol >= 0) &&
		(nBearNewRow < SIZE_OF_BOARD) && (nBearNewRow >= 0))
	{
		// Check if we cout bully.
		nDidWeCatchBully = ioarrnBoard[nBearNewRow][nBearNewCol] == 'B';

		// Move bear on the board.
		if (*ionIsOnDot)
		{
			ioarrnBoard[ionttBear->nRow][ionttBear->nCol] = '.';
		}
		else
		{
			ioarrnBoard[ionttBear->nRow][ionttBear->nCol] = ' ';
		}

		// Check if the bear is standing on a dot.
		*ionIsOnDot = ioarrnBoard[nBearNewRow][nBearNewCol] == '.';

		// Place the bear icon.
		ioarrnBoard[nBearNewRow][nBearNewCol] = 'D';

		// Chang the main postion into the new one.
		ionttBear->nRow = nBearNewRow;
		ionttBear->nCol = nBearNewCol;
	}

	return (nDidWeCatchBully);
}
