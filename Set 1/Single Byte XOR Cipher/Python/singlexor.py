#!/usr/bin/python
import binascii
from frequencyAnalysis import FrequencyAnalysis
	
hexin = raw_input("Enter a hex string: ")
ascii = binascii.unhexlify(hexin)

best=9999999.99
bestc=' '
for cipher in (chr(i) for i in xrange(32, 127)):
	output=""
	#cipher='A'
	for c in range(0, len(ascii)):
		output += chr( ord(ascii[c]) ^ (ord(cipher)) )
	score=FrequencyAnalysis(output)
	if( score < best ):
		best = score
		bestc = ((cipher))

print "Best score", score, "From cipher", bestc
out=""
for c in range(0, len(ascii)):
	out += chr( ord(ascii[c]) ^ (ord(bestc)) )
print out
