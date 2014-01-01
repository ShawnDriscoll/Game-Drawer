#
#   Run this file to call roll()
#

"""Performs 10 dice rolls"""

import dice_stuff.diceroll

print 'Welcome to', dice_stuff.version.ver
dice = '3D6'
print 'Here are your ten', dice, 'rolls:'

for i in range(10):
    print dice_stuff.diceroll.roll(dice)
