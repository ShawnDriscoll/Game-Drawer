#
#   Written for Python 2.5.4
#
#   To use this module: from diceroll import roll
#
#   Make a dice roll for calling module
#
##########################################################

"""
Usage: from diceroll import roll
"""

from random import randint

def die_rolls(dtype, dcount):
    dtotal = 0
    for i in range(dcount):
        dtotal += randint(1, dtype)
    return dtotal

def roll(dice):
    """
    roll() is a dice rolling program.\n\n\
    The types of dice to roll are (in string values):\n\
    roll('D6') -- roll one 6-sided die\n\
    roll('1D6') -- roll one 6-sided die\n\
    roll('2D6') -- roll two 6-sided dice\n\
    roll('D10') -- roll a 10-sided die\n\
    roll('D100') -- roll a 100-sided die (1 - 100)\n\
    roll('D66') -- roll for a D66 chart\n\
    roll('2DD+3') -- roll (2D6+3) x 10\n\n\
    -/+ DMs can be added to rolls:\n\
    roll('3D6+6') -- add +6 DM to roll\n\
    roll('4D4-4') -- add -4 DM to roll\n
    """

    dice = str(dice).upper().strip()
    dice_mod = 0
    if dice == 'FLUX':
        return randint(1, 6) - randint(1, 6)
    else:
        if dice == 'GOOD FLUX':
            flux1 = randint(1, 6)
            flux2 = randint(1, 6)
            if flux1 < flux2:
                return flux2 - flux1
            else:
                return flux1 - flux2
        else:
            if dice == 'BAD FLUX':
                flux1 = randint(1, 6)
                flux2 = randint(1, 6)
                if flux1 > flux2:
                    return flux2 - flux1
                else:
                    return flux1 - flux2
    
    ichar1 = dice.find('DD')
    if ichar1 == -1:
        ichar1 = dice.find('D')
    if ichar1 == 0:
        num_dice = 1

    if ichar1 <> -1:
        if ichar1 <> 0:
            num_dice = int(dice[0:ichar1])
#            print 'Number of dice =', num_dice
        ichar2 = dice.find('+')
        if ichar2 <> -1:
            dice_mod = int(dice[ichar2:len(dice)])
#            print 'dice mod =', dice_mod
        else:
            ichar2 = dice.find('-')
            if ichar2 <> -1:
                dice_mod = int(dice[ichar2:len(dice)])
#                print 'dice mod =', dice_mod

        if ichar2 <> -1:
            dice_type = dice[ichar1: ichar2]
            dice_type = dice_type.rstrip()
        else:
            dice_type = dice[ichar1: len(dice)]
#            print 'dice type =', dice_type, 'Len = ', len(dice_type)

        if dice_type == 'D6':                                       
            return die_rolls(6, num_dice) + dice_mod
        else:
            if dice_type == 'D66' and num_dice == 1 and dice_mod == 0:
                return randint(1, 6) * 10 + randint(1, 6)
            else:
                if dice_type == 'D100' and num_dice == 1:                                      
                    return (randint(1, 10) - 1) * 10 + randint(1, 10) + dice_mod      
                else:
                    if dice_type == 'D10':                                       
                        return die_rolls(10, num_dice) + dice_mod
                    else:                               
                        if dice_type == 'D20':                                       
                            return die_rolls(20, num_dice) + dice_mod
                        else:
                            if dice_type == 'D30':                                       
                                return die_rolls(30, num_dice) + dice_mod
                            else:
                                if dice_type == 'D12':                                       
                                    return die_rolls(12, num_dice) + dice_mod
                                else:
                                    if dice_type == 'D8':                                       
                                        return die_rolls(8, num_dice) + dice_mod
                                    else:
                                        if dice_type == 'D4':                                       
                                            return die_rolls(4, num_dice) + dice_mod
                                        else:
                                            if dice_type == 'D9':                                       
                                                return die_rolls(9, num_dice) + dice_mod
                                            else:
                                                if dice_type == 'D3':                                       
                                                    return die_rolls(3, num_dice) + dice_mod
                                                else:
                                                    if dice_type == 'DD':
                                                        return (die_rolls(6, num_dice) + dice_mod) * 10
    
    print
    print "** DICE ERROR! '%s' is unknown **" % dice
    print 
    print "roll() is a dice rolling program."
    print
    print "The types of dice to roll are (in string values):"
    print "roll('D6') -- roll one 6-sided die"
    print "roll('1D6') -- roll one 6-sided die"
    print "roll('2D6') -- roll two 6-sided dice"
    print "roll('D10') -- roll a 10-sided die"
    print "roll('D100') -- roll a 100-sided die (1 - 100)"
    print "roll('D66') -- roll for a D66 chart"
    print "roll('2DD+3') -- roll (2D6+3) x 10"
    print
    print "-/+ DMs can be added to rolls:"
    print "roll('3D6+6') -- add +6 DM to roll"
    print "roll('4D4-4') -- add -4 DM to roll"
    print
    return 0
