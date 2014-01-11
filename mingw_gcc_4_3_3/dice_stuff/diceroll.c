//
//  diceroll.c
//
//  For use with Python programs:
//      from diceroll import roll
//
//--------------------------------------
//
//  Use setup.py to compile this code into a .pyd file
//  for importing into Python 2.5.4.  The MinGW GCC 4.3.3
//  compiler for Python is required.
//
//  Usage:
//    setup.py build -c mingw32
//
//    Do not try to install.  Just copy
//    the .pyd to the folder where your
//    Python code is located.
//

#include <Python.h>

#define DICE_HELP "\nroll() is a dice rolling program.\n\n\
The types of dice to roll are (in string values):\n\
roll('1D6') -- roll one 6-sided die\n\
roll('2D6') -- roll two 6-sided dice\n\
roll('D10') -- roll a 10-sided die\n\
roll('D00') -- roll a 100-sided die (1 - 100)\n\
roll('D66') -- roll for a D66 chart\n\n\
-/+ DMs can be added to rolls:\n\
roll('3D6+6') -- add +6 DM to roll\n\
roll('4D4-4') -- add -4 DM to roll\n\n"

int die_roll(int die)
{
    static int seed = 0;

    if (seed == 0)
    {
        srand((unsigned int)time(0));       // randomize seed
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
        if (dice[0] == 68)                              // "D" is at beginning of roll string?
        {
            if (dice[1] == 54 && dice[2] == 54 && strlen(dice) == 3)    // D66 rolled?
            {
                return die_roll(6) * 10 + die_roll(6);  // 11 - 66, no DMs allowed
            }
            if (dice[1] == 48 && dice[2] == 48)         // D00 rolled?
            {
                value = (die_roll(10) - 1) * 10 + die_roll(10);     // 1 - 100
                if (dice[3] == 43 || dice[3] == 45)     // Is there a +/- DM to apply?
                {
                    if (dice[3] == 43)                  // A +DM?
                    {
                        value += dice[4] - 48;
                    }
                    else                                // A -DM?
                    {
                        value += -(dice[4] - 48);
                    }
                }
                return value;
            }
            if (dice[1] == 49 && dice[2] == 48)         // D10 rolled?
            {
                value = die_roll(10);                   // 1 - 10
                if (dice[3] == 43 || dice[3] == 45)     // Is there a +/- DM to apply?
                {
                    if (dice[3] == 43)                  // A +DM?
                    {
                        value += dice[4] - 48;
                    }
                    else                                // A -DM?
                    {
                        value += -(dice[4] - 48);
                    }
                }
                return value;
            }
            if (dice[1] == 50 && dice[2] == 48)         // D20 rolled?
            {
                value = die_roll(20);                   // 1 - 20
                if (dice[3] == 43 || dice[3] == 45)     // Is there a +/- DM to apply?
                {
                    if (dice[3] == 43)                  // A +DM?
                    {
                        value += dice[4] - 48;
                    }
                    else                                // A -DM?
                    {
                        value += -(dice[4] - 48);
                    }
                }
                return value;
            }
            if (dice[1] == 51 && dice[2] == 48)         // D30 rolled?
            {
                value = die_roll(30);                   // 1 - 30
                if (dice[3] == 43 || dice[3] == 45)     // Is there a +/- DM to apply?
                {
                    if (dice[3] == 43)                  // A +DM?
                    {
                        value += dice[4] - 48;
                    }
                    else                                // A -DM?
                    {
                        value += -(dice[4] - 48);
                    }
                }
                return value;
            }
            if (dice[1] == 49 && dice[2] == 50)         // D12 rolled?
            {
                value = die_roll(12);                   // 1 - 12
                if (dice[3] == 43 || dice[3] == 45)     // Is there a +/- DM to apply?
                {
                    if (dice[3] == 43)                  // A +DM?
                    {
                        value += dice[4] - 48;
                    }
                    else                                // A -DM?
                    {
                        value += -(dice[4] - 48);
                    }
                }
                return value;
            }
        }
        else
        {
            if (dice[1] == 68)                          // "D" is in middle of roll string?
            {
                if (dice[0] >= 49 && dice[0] <= 57 && (dice[2] == 52 || dice[2] == 54 || dice[2] == 56))
                {                                       // How many dice, and how many sides?
                    value = 0;
                    for (i = 1; i < dice[0] - 47; i++)  // Roll the number of dice
                        value += die_roll(dice[2] - 48);  // Add this die roll type to the total
                    if (dice[3] == 43 || dice[3] == 45) // Is there a +/- DM to apply?
                    {
                        if (dice[3] == 43)              // A +DM?
                        {
                            value += dice[4] - 48;
                        }
                        else                            // A -DM?
                        {
                            value += -(dice[4] - 48);
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

static PyObject *diceroll_roll(PyObject *self, PyObject *args)
{
    char *num;
    if (!PyArg_ParseTuple(args, "s", &num))
        return NULL;
    return (PyObject*)Py_BuildValue("i", roll(num));
}

static PyMethodDef diceroll_methods[] =
{
    { "roll", (PyCFunction)diceroll_roll, METH_VARARGS, DICE_HELP, },
    { NULL, NULL, 0, NULL }
};

PyMODINIT_FUNC initdiceroll()
{
    Py_InitModule3("diceroll", diceroll_methods, "Usage: from diceroll import roll");
}
