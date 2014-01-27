#
#   Written for Jython 2.5.4rc1
#
#   Run this file to call roll()
#

"""
Performs 10 dice rolls
"""

from dice_stuff.diceroll import roll
from dice_stuff import version

print
print 'Welcome to', version.ver
print
dice = raw_input("Enter roll type: ")
print 'Here are your ten', dice, 'rolls:'

for i in range(10):
    print roll(dice)