/*************************************************************
*
* project name: Dice roll program for various die types
* file name:    roll.c
* initial date: 01/2/2014
* author:       Shawn Driscoll
* email:        shawndriscoll@hotmail.com
*
* Compile with TI-GCC version 0.96 Beta 8 for execution
* on a TI-89, a TI-92, or a Voyage 200.
*
**************************************************************/

#include <tigcclib.h>
#include "diceroll.h"

int _ti92plus;
int _ti89;

// ------------------------------------------------------------
//  START PROGRAM

void _main(void)
{
	int looping = TRUE;
	char roll_type[10];
	int i;
	
//	clear the screen
    clrscr();
    
    randomize();													// randomize seed
	
	printf ("Roll type [ex 2D6]: ");
	scanf ("%s", &roll_type);
	printf ("\n");
	
	for (i = 1; i <= 10; i++)
    	printf("%d\n", roll(roll_type));
            
	while (looping)
	{
		ST_showHelp("Programmed by shawndriscoll@hotmail.com");
		//	wait for a key press before the program exits
		if (ngetchx () == 13)
			looping = FALSE;
	}
}
