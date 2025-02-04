// Character.h

#define SIZE_OF_BOARD 20

// Struct declaration
typedef struct {
	int		nRow;
	int		nCol;
	char	cSign;
}Character;

// Struct declaration
void AddCharacter(char	ioarrnBoard[][SIZE_OF_BOARD], Character* nttCharacter);

int MoveBully(char		ioarrnBoard[][SIZE_OF_BOARD],
			  Character* ionttBully,
			  int		inDirection);

int MoveBear(char		ioarrnBoard[][SIZE_OF_BOARD],
			 Character	ionttBully,
			 Character*	ionttBear,
			 int*		ionIsOnDot);