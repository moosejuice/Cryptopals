#!/usr/bin/python
from frequencyAnalysis import FrequencyAnalysis

#Input, ascii encoded string
#Output, tuple of the best cipher character and its language score
def bestCipher(ascii):
	best=9999999.99
	bestc=' '
	for cipher in (chr(i) for i in xrange(32, 127)):
		output=""
		for c in range(0, len(ascii)):
			output += chr( ord(ascii[c]) ^ (ord(cipher)) )
		score=FrequencyAnalysis(output)
		if( score < best ):
			best = score
			bestc = ((cipher))
	return (bestc, best)
