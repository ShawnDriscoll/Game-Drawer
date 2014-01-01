#
#   To use this module: from diceroll import roll
#
#   Make a dice roll for calling module
#
##########################################################

"""Usage: from diceroll import roll"""

from random import randint

def roll(dice):
    """\nroll() is a dice rolling program.\n\n\
The types of dice to roll are (in string values):\n\
roll('1D6') -- roll one 6-sided die\n\
roll('2D6') -- roll two 6-sided dice\n\
roll('D10') -- roll a 10-sided die\n\
roll('D00') -- roll a 100-sided die (1 - 100)\n\
roll('D66') -- roll for a D66 chart\n\n\
-/+ DMs can be added to rolls:\n\
roll('3D6+6') -- add +6 DM to roll\n\
roll('4D4-4') -- add -4 DM to roll\n\n"""

    dice = str(dice)                                                # Make sure dice is a string and not an integer
    dm = 0
    # is there any modifier added?
    if len(dice) == 3 or (len(dice) == 5) and (dice[3] == '+' or dice[3] == '-'):
        if dice[0] == 'D':                                          # "D" is at beginning of roll string?
            if dice[1:3] == '66' and len(dice) == 3:                # D66 rolled?
                return randint(1,6) * 10 + randint(1,6)             # 11 - 66, no DMs allowed
            if dice[1:3] == '00':                                   # D00 rolled?
                value = (randint(1,10) - 1) * 10 + randint(1,10)    # 1 - 100
                if len(dice) > 3 and (dice[3] == '+' or dice[3] == '-'):        # Is there a +/- DM to apply?
                    if dice[3] == '+':                              # A +DM?
                        value += int(dice[4])
                    else:                                           # A -DM?
                        value += -(int(dice[4]))
                return value
            if dice[1:3] == '10':                                   # D10 rolled?
                value = randint(1,10)                               # 1 - 10
                if len(dice) > 3 and (dice[3] == '+' or dice[3] == '-'):        # Is there a +/- DM to apply?
                    if dice[3] == '+':                              # A +DM?
                        value += int(dice[4])
                    else:                                           # A -DM?
                        value += -(int(dice[4]))
                return value
        else:
            if dice[1] == 'D':                                      # "D" is in middle of roll string?
                if int(dice[0]) >= 1 and int(dice[0]) <= 9:         # How many dice?
                    value = 0
                    for i in range(int(dice[0])):                   # Roll the number of dice
                        value += randint(1,int(dice[2]))            # Add this die roll type to the total
                    if len(dice) > 3 and (dice[3] == '+' or dice[3] == '-'):        # Is there a +/- DM to apply?
                        if dice[3] == '+':                          # A +DM?
                            value += int(dice[4])
                        else:                                       # A -DM?
                            value += -(int(dice[4]))
                    return value
    print
    print "** DICE ERROR! '%s' is unknown **" % dice
    print
    print "roll() is a dice rolling program."
    print
    print "The types of dice to roll are (in string values):"
    print "roll('1D6') -- roll one 6-sided die"
    print "roll('2D6') -- roll two 6-sided dice"
    print "roll('D10') -- roll a 10-sided die"
    print "roll('D00') -- roll a 100-sided die (1 - 100)"
    print "roll('D66') -- roll for a D66 chart"
    print
    print "-/+ DMs can be added to rolls:"
    print "roll('3D6+6') -- add +6 DM to roll"
    print "roll('4D4-4') -- add -4 DM to roll"
    print
    return 0