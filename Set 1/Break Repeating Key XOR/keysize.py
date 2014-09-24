#!/usr/bin/python
from hamming import HammingDistance

#Input string must be a hex string of length at least 160 characters
#Returns dictionary of normalized edit distance over 2 keysizes, and the keysize
def guessKeySize(hexstr):
	d={}
	for x in range(4,82,2):	#figure out the most likely key size
		norm = HammingDistance(hexstr[0:x], hexstr[x:x*2], 'h')/float(x/2)
		norm += HammingDistance(hexstr[x*2:x*3], hexstr[x*3:x*4], 'h')/float(x/2)
		d[x/2]=norm/2
	return d