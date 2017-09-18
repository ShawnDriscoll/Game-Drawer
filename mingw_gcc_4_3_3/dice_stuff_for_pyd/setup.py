#
#   This script will use MinGW GCC 4.3.3 to compile dicerollModule.c
#   into diceroll.pyd for importing into Python 2.5.4.
#
#   Usage:
#     At DOS prompt enter: setup.py build -c mingw32
#
#     Do not try to install.  Just copy
#     the .pyd to the site-packages folder
#     so it can be imported by Python.
#
################################################################

from distutils.core import setup
from distutils.core import Extension

module1 = Extension('diceroll', sources = ['dicerollModule.c'])

setup(name = 'diceroll', version = '2.0.7', ext_modules=[module1])
