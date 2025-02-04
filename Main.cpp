//Main.cpp

// This define needs to be as the first comnend outherwise it will not work
#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include<stdlib.h>
#include <conio.h>
#include <math.h>
#include "Character.h"

// Function prototypes
void PrintBoard(char	iarrnBoard[][SIZE_OF_BOARD], 
				int		inCurrentPoints,
				int		inMaxPoints);

void BuildWalls(char	ioarrnBoard[][SIZE_OF_BOARD]);

int FillDots(char		ioarrnBoard[][SIZE_OF_BOARD]);

//---------------------------------------------------------------------------------------
//											Bully
//											-----
//
// General	: A game that resembles Pacman.
//
// Input	: None.
//
// Process	: Move the player cherecter and the enemy.
//
// Output	: Game screen drawn using ASCII art.
//
//---------------------------------------------------------------------------------------
// Programmer : Ben Kadaner
// Student No : 24
// Date : 23.10.2024
//---------------------------------------------------------------------------------------
void main() 
{
	// Array definition
	char arrnBoard[SIZE_OF_BOARD][SIZE_OF_BOARD];

	// Variable definition
	Character nttBully = { 0,0,'B'};
	Character nttBear = { 0,0,'D' };
	int nDotCapturedCounter = 1;
	int nMaxPoints;
	int nIsBearOnDot = 1;
	int nIsGameFinished = 0;
	int nPrevDirection = 0;
	int nDirection;

	// Code section
	BuildWalls(arrnBoard);
	nMaxPoints = FillDots(arrnBoard);

	// Add Bully
	AddCharacter(arrnBoard, &nttBully);

	// Add the bear
	AddCharacter(arrnBoard, &nttBear);

	// Ptint the board with all its' ditails
	PrintBoard(arrnBoard, nDotCapturedCounter, nMaxPoints);
	
	// Check if the game started in a stat were the bear olready cour bully.
	if (nttBear.nCol == nttBully.nCol && nttBear.nRow == nttBully.nRow)
	{
		nIsGameFinished = 1;
	}

	// Game loop
	while (!nIsGameFinished) 
	{
		// Get the user diraction
		printf("Please enter Direction: ");
		getDiraction:
		nDirection = _getch() - '0';
		if (nDirection)
		{
			nPrevDirection = nDirection;
		}
		else 
		{
			// Check if there is a direction in '0' outherwise get one
			while (!nPrevDirection)
			{
				nPrevDirection = _getch() - '0';
			}
			
			nDirection = nPrevDirection;
		}

		// Move bully
		nDotCapturedCounter += MoveBully(arrnBoard, &nttBully, nDirection);
		if (nDotCapturedCounter == nMaxPoints)
		{
			nIsGameFinished = 2;
			break;
		}

		// If the bear is seposed to catch us when we got the last dot we win
		nIsGameFinished = MoveBear(arrnBoard, nttBully, &nttBear, &nIsBearOnDot);

		// Print the board egain after the chaninges
		PrintBoard(arrnBoard, nDotCapturedCounter, nMaxPoints);
	}

	// Check end game result
	if (nIsGameFinished == 2)
	{
		PrintBoard(arrnBoard, nDotCapturedCounter, nMaxPoints);
		printf("You won!!!!");
	}
	else 
	{
		printf("You lost");
	}
}

//---------------------------------------------------------------------------------------
//										Print Board
//										-----------
//
// General		: Print the map using ASCII art.
//
// Parameters	:
//		iarrnBoard		- The playing board we wish to print.			(In)
//		inCurrentPoints	- The curent amount of points we have.			(In)
//		inMaxPoints		- The max amount of points the player can get.	(In)
//
// Return Value : None
//
//---------------------------------------------------------------------------------------
void PrintBoard(char iarrnBoard[][SIZE_OF_BOARD], int inCurrentPoints, int inMaxPoints) 
{
	// Code section
	system("cls");
	printf("Points: %d/%d\n", inCurrentPoints, inMaxPoints);

	// Print upper border.
	for (int i = 0; i < (SIZE_OF_BOARD * 2); i++)
	{
		putchar('-');
	}

	putchar('\n');

	// Print the content of the board with side borders.
	for (int i = 0; i < SIZE_OF_BOARD; i++)
	{
		putchar('|');
		for (int j = 0; j < SIZE_OF_BOARD; j++)
		{
			putchar(iarrnBoard[i][j]);
			if (j < (SIZE_OF_BOARD - 1))
			{
				putchar(' ');
			}
			else 
			{
				printf("|\n");
			}
		}
	}

	// Print lower border.
	for (int i = 0; i < (SIZE_OF_BOARD * 2); i++)
	{
		putchar('-');
	}
	putchar('\n');
}

//---------------------------------------------------------------------------------------
//										Build Walls
//										-----------
//
// General		: Get from the user the cords to build the walls at
//
// Parameters	:
//		ioarrnBoard		- The playing board we wish to add walls to.	(In)
//
// Return Value : None
//
//---------------------------------------------------------------------------------------
void BuildWalls(char ioarrnBoard[][SIZE_OF_BOARD]) 
{
	// Variable definition
	int nWallRow;
	int nWallCol;

	// Code section
	printf("Please enter the postion of the walls you wish to add:\n");

	// Get from the use postion to biuld the walls and build them.
	while (1)
	{
		printf("Please enter the row: ");
		scanf("%d", &nWallRow);
		if (!nWallRow)
		{
			break;
		}

		printf("Please enter the column: ");
		scanf("%d", &nWallCol);
		if (!nWallCol)
		{
			break;
		}

		ioarrnBoard[nWallRow - 1][nWallCol - 1] = '*';
	}
}

//---------------------------------------------------------------------------------------
//										Fill Dots
//										---------
//
// General		: FIlls the playing board with dots the user will try to get.
//
// Parameters	:
//		ioarrnBoard		- The playing board we wish add dots to.			(In)
//
// Return Value : Amount of dots we added.
//
//---------------------------------------------------------------------------------------
int FillDots(char ioarrnBoard[][SIZE_OF_BOARD]) 
{
	// Variable definition
	int nDotCounter = 0;

	// Code section

	//Enter the dots to the empty places
	for (int i = 0; i < SIZE_OF_BOARD; i++)
	{
		for (int j = 0; j < SIZE_OF_BOARD; j++)
		{
			// Check if the place is empty
			if (ioarrnBoard[i][j] != '*')
			{
				ioarrnBoard[i][j] = '.';
				nDotCounter++;
			}
		}
	}

	return (nDotCounter);
}
