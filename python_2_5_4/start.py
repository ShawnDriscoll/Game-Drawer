#
#   Written for Python 2.5.4
#
#   Run this file to call roll()
#

"""
Performs 10 dice rolls
"""

from program.diceroll import roll
from program import version

print
print 'Welcome to', version.ver
print
dice = raw_input("Enter roll type, such as 3D6: ")
print 'Here are your ten', dice, 'rolls:'

for i in range(10):
    print roll(dice)