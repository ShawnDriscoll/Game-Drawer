#
#   Written for Python 2.5.4
#
#   Run this file to call roll()
#

"""Performs 10 dice rolls"""

import dice_stuff.diceroll

print
print 'Welcome to', dice_stuff.version.ver
print
dice = raw_input("Enter roll type: ")
print 'Here are your ten', dice, 'rolls:'

for i in range(10):
    print dice_stuff.diceroll.roll(dice)