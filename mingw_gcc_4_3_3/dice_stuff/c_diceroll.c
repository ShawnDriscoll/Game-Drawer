// 	c_diceroll.c
//
//	For use with numdice.c (compile with MinGW GCC 4.3.3)
//

#include <stdio.h>
#include <string.h>

int die_roll(int die)
{
	static int seed = 0;

	if (seed == 0)
	{
		srand((unsigned int)time(0));		// randomize seed
		seed = 1;
	}
    return rand() % die + 1;
}

int roll(char dice[10])
{
	int value;
	int i;		
	
	// String has to be 3 or 5 in length!
	if (strlen(dice) == 3 || ((strlen(dice) == 5) && (dice[3] == 43 || dice[3] == 45)))
	{
		if (dice[0] == 68)   							// "D" is at beginning of roll string?
		{
			if (dice[1] == 54 && dice[2] == 54 && strlen(dice) == 3)	// D66 rolled?
			{
				return die_roll(6) * 10 + die_roll(6);	// 11 - 66, no DMs allowed
			}
			if (dice[1] == 48 && dice[2] == 48)			// D00 rolled?
			{
				value = (die_roll(10) - 1) * 10 + die_roll(10);		// 1 - 100
				if (dice[3] == 43 || dice[3] == 45)		// Is there a +/- DM to apply?
				{
					if (dice[3] == 43)					// A +DM?
					{
					//	printf("+%d DM ", dice[4] - 48);
					//	printf("%d ", value);
						value += dice[4] - 48;
					//	printf("%d ", value);
					}
					else								// A -DM?
					{
					//	printf("-%d DM ", dice[4] - 48);
					//	printf("%d ", value);
						value += -(dice[4] - 48);
					//	printf("%d ", value);
					}
				}
				return value;
			}
			if (dice[1] == 49 && dice[2] == 48)			// D10 rolled?
			{
				value = die_roll(10);					// 1 - 10
				if (dice[3] == 43 || dice[3] == 45)		// Is there a +/- DM to apply?
				{
					if (dice[3] == 43)					// A +DM?
					{
					//	printf("+%d DM ", dice[4] - 48);
					//	printf("%d ", value);
						value += dice[4] - 48;
					//	printf("%d ", value);
					}
					else								// A -DM?
					{
					//	printf("-%d DM ", dice[4] - 48);
					//	printf("%d ", value);
						value += -(dice[4] - 48);
					//	printf("%d ", value);
					}
				}
				return value;
			}
		}
		else
		{
			if (dice[1] == 68)  						// "D" is in middle of roll string?
			{
				if (dice[0] >= 48 && dice[0] <= 57)		// How many dice?
				{
					value = 0;
					for (i = 1; i < dice[0] - 47; i++)  // Roll the number of dice
						value += die_roll(dice[2] - 48);  // Add this die roll type to the total
					if (dice[3] == 43 || dice[3] == 45)	// Is there a +/- DM to apply?
					{
						if (dice[3] == 43)				// A +DM?
						{
						//	printf("+%d DM ", dice[4] - 48);
						//	printf("%d ", value);
							value += dice[4] - 48;
						//	printf("%d ", value);
						}
						else							// A -DM?
						{
						//	printf("-%d DM ", dice[4] - 48);
						//	printf("%d ", value);
							value += -(dice[4] - 48);
						//	printf("%d ", value);
						}
					}
					return value;
				}
			}
		}
	}
	printf("\n** DICE ERROR! '%s' is unknown **\n\n", dice);
	printf("\nroll() is a dice rolling program.\n\n");
	printf("The types of dice to roll are (in string values):\n");
	printf("roll('1D6') -- roll one 6-sided die\n");
	printf("roll('2D6') -- roll two 6-sided dice\n");
	printf("roll('D10') -- roll a 10-sided die\n");
	printf("roll('D00') -- roll a 100-sided die (1 - 100)\n");
	printf("roll('D66') -- roll for a D66 chart\n\n");
	printf("-/+ DMs can be added to rolls:\n");
	printf("roll('3D6+6') -- add +6 DM to roll\n");
	printf("roll('4D4-4') -- add -4 DM to roll\n\n");
	return 0;
}
