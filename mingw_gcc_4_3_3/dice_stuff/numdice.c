//
//	numdice.c -- makes 20 dice rolls
//	compile with c_diceroll.c using MinGW GCC 4.3.3 at DOS prompt:
//      gcc numdice.c c_diceroll.c -o numdice.exe

#include <stdio.h>

int main(void)
{
	int x;
	char roll_type[10];

	printf("\nType of roll (example: 2D6+3):? ");

	scanf("%s", &roll_type);
	printf("\n");

	for (x = 1; x <= 20; x++)
	{
		printf("You rolled a %d\n", roll(roll_type));
	}

	return 0;
}
