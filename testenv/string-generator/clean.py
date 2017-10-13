#!/usr/bin/python3

import string
import sys

if len(sys.argv) == 1:
   print('Not enough arguments')
   exit(1)
fname = sys.argv[1]

with open(fname) as f:
   lines = f.readlines()
   for line in lines:
      printable = set(string.printable)
      s = filter(lambda x: x in printable, line)
      print s,
