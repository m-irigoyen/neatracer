#!/usr/bin/env python3

"""MMG project init. This will download the catch2 unit tests framework

Usage:
  init.py
  init.py (-h | --help)

Options:
  -h --help     Show this screen
"""



from contextlib import contextmanager
from docopt import docopt
import os
import sys


# -------------------------
# CONTEXT MANAGER
# -------------------------
@contextmanager
def cwd(path):
    oldpwd=os.getcwd()
    os.chdir(path)
    try:
        yield
    finally:
        os.chdir(oldpwd)

# -------------------------
# Setup script
# -------------------------
	
def main(argv) :
		with cwd(os.path.dirname(os.path.realpath(__file__))) :
			os.system("python thirdparties/catch/update.py")

if __name__ == "__main__":
	main(sys.argv[1:])
