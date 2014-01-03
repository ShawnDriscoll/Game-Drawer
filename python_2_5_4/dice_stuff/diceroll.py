#
#   To use this module: from diceroll import roll
#
#   Make a dice roll for calling module
#
##########################################################

"""\nUsage: from diceroll import roll\n"""

from random import randint
import re

def roll(dice):
    """\nroll() is a dice rolling program.\n\n\
The types of dice to roll are (in string values):\n\
roll('<N>D<S>+<M>')
where N = number of dice (optional)
      S = number of sides on the dice
      M = a DM modifier (optional)

roll('1D6') -- roll one 6-sided die\n\
roll('2D6') -- roll two 6-sided dice\n\
roll('D10') -- roll a 10-sided die\n\
roll('D00') -- roll a 100-sided die (1 - 100)\n\
roll('D66') -- roll for a D66 chart\n\n\
-/+ DMs can be added to rolls:\n\
roll('3D6+6') -- add +6 DM to roll\n\
roll('4D4-4') -- add -4 DM to roll\n\n"""

    # Apply our regular expression to the dice string
    # To extract the number of dice, sides and modifier
    dice_info = re.search('([\d+])?D([\d]+)([-\+]\d+)?', str(dice))

    # The supplied dice string was invalid
    if dice_info == None:
        print
        print "** DICE ERROR! '%s' is unknown **" % dice
        print
        print "roll() is a dice rolling program."
        print
        print "The types of dice to roll are (in string values):"
        print "roll('<N>D<S>+<M>')"
        print "where N = number of dice (optional)"
        print "      S = number of sides on the dice"
        print "      M = a DM modifier (optional)"
        print
        print "Examples:"
        print
        print "roll('D20')"
        print "roll('2D12')"
        print "roll('3D6+6')"
        print "roll('4D4-4')"
        print
        return 0

    # Sets number of dice to 1 if it was not specified
    ndice = 1
    if dice_info.group(1) != None:
        # Sets number of dice to speficied number
        ndice = int(dice_info.group(1))

    # Sets dice type (number of sides)
    dice_type = int(dice_info.group(2))

    # Sets DM to 0 if not specified
    dice_modifier = 0
    if dice_info.group(3) != None:
        # Sets DM to specified value
        dice_modifier = int(dice_info.group(3))

    # Calculates ndice * randint(1,dicetype) + dice_modifier
    value = 0
    # For each dice, roll it
    for d in range(ndice):
        # add value of this roll to the total
        value += randint(1, dice_type) 
    # Apply the modifier
    value += dice_modifier

    # Return the dice value to user.
    return value

