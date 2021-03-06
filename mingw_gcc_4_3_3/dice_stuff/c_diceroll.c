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
	int flux1;
	int flux2;

	if (strcmp("FLUX", dice) == 0)
	{
		return die_roll(6) - die_roll(6);
	}
	else if (strcmp("GOODFLUX", dice) == 0)
	{
	    flux1 = die_roll(6);
	    flux2 = die_roll(6);
	    if (flux1 < flux2)
	    {
	    	return flux2 - flux1;
	    }
	    else
	    {
	    	return flux1 - flux2;
	    }
	}
	else if (strcmp("BADFLUX", dice) == 0)
	{
		flux1 = die_roll(6);
		flux2 = die_roll(6);
		if (flux1 > flux2)
		{
			return flux2 - flux1;
		}
		else
		{
			return flux1 - flux2;
		}
	}

	if (dice[0] == 68 || dice[0] == 100)   							// "D" or "d" is at beginning of roll string?
	{
		if (dice[1] == 54 && dice[2] == 54 && strlen(dice) == 3)	// D66 rolled?
		{
			return die_roll(6) * 10 + die_roll(6);	// 11 - 66, no DMs allowed
		}
		if (dice[2] == 48 && dice[3] == 48)			// D100 rolled?
		{
			if (dice[1] == 49)
			{
				value = (die_roll(10) - 1) * 10 + die_roll(10);		// 1 - 100
				if (dice[4] == 43 || dice[4] == 45)		// Is there a +/- DM to apply?
				{
					if (dice[4] == 43)					// A +DM?
					{
						value += dice[5] - 48;
					}
					else								// A -DM?
					{
						value += -(dice[5] - 48);
					}
				}
				return value;
			}
			else
			{
				printf("Bad die: %s\n\n", dice);
				return 0;
			}
		}
		if (dice[1] == 49 && dice[2] == 48)			// D10 rolled?
		{
			value = die_roll(10);					// 1 - 10
			if (dice[3] == 43 || dice[3] == 45)		// Is there a +/- DM to apply?
			{
				if (dice[3] == 43)					// A +DM?
				{
					value += dice[4] - 48;
				}
				else								// A -DM?
				{
					value += -(dice[4] - 48);
				}
			}
			return value;
		}
		if (dice[1] == 50 && dice[2] == 48)			// D20 rolled?
		{
			value = die_roll(20);					// 1 - 20
			if (dice[3] == 43 || dice[3] == 45)		// Is there a +/- DM to apply?
			{
				if (dice[3] == 43)					// A +DM?
				{
					value += dice[4] - 48;
				}
				else								// A -DM?
				{
					value += -(dice[4] - 48);
				}
			}
			return value;
		}
		if (dice[1] == 51 && dice[2] == 48)			// D30 rolled?
		{
			value = die_roll(30);					// 1 - 30
			if (dice[3] == 43 || dice[3] == 45)		// Is there a +/- DM to apply?
			{
				if (dice[3] == 43)					// A +DM?
				{
					value += dice[4] - 48;
				}
				else								// A -DM?
				{
					value += -(dice[4] - 48);
				}
			}
			return value;
		}
		if (dice[1] == 49 && dice[2] == 50)			// D12 rolled?
		{
			value = die_roll(12);					// 1 - 12
			if (dice[3] == 43 || dice[3] == 45)		// Is there a +/- DM to apply?
			{
				if (dice[3] == 43)					// A +DM?
				{
					value += dice[4] - 48;
				}
				else								// A -DM?
				{
					value += -(dice[4] - 48);
				}
			}
			return value;
		}
	}
	else
	{
		if (dice[1] == 68 || dice[1] == 100)        // "D" is in middle of roll string?
		{
			//if (dice[0] >= 49 && dice[0] <= 57 && (dice[2] == 52 || dice[2] == 54 || dice[2] == 56))
            if (dice[0] >= 49 && dice[0] <= 57 && (dice[2] >= 50 && dice[2] <= 57))
			{										// How many dice, and how many sides?
				value = 0;
				for (i = 1; i < dice[0] - 47; i++)  // Roll the number of dice
					value += die_roll(dice[2] - 48);  // Add this die roll type to the total
				if (dice[3] == 43 || dice[3] == 45)	// Is there a +/- DM to apply?
				{
					if (dice[3] == 43)				// A +DM?
					{
						value += dice[4] - 48;
					}
					else							// A -DM?
					{
						value += -(dice[4] - 48);
					}
				}
				return value;
			}
		}
	}
    
	printf("\n** DICE ERROR! '%s' is unknown **\n\n", dice);
	printf("The types of dice to roll are (in string values):\n");
	printf("roll('1D6') -- roll one 6-sided die\n");
	printf("roll('2D6') -- roll two 6-sided dice\n");
	printf("roll('D10') -- roll a 10-sided die\n");
	printf("roll('D100') -- roll a 100-sided die (1 - 100)\n");
	printf("roll('D66') -- roll for a D66 chart\n");
    printf("roll('FLUX') -- a FLUX roll (-5 to 5)\n\n");
	printf("-/+ DMs can be added to rolls:\n");
	printf("roll('3D6+6') -- add +6 DM to roll\n");
	printf("roll('4D4-4') -- add -4 DM to roll\n\n");
	return 0;
}
