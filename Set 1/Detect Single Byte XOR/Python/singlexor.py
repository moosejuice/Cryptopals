#!/usr/bin/python
import binascii
from frequencyAnalysis import FrequencyAnalysis
	
#hexin = raw_input("Enter a hex string: ")
#ascii = binascii.unhexlify(hexin)

def bestCipher(ascii):
	best=9999999.99
	bestc=' '
	second=0
	for cipher in (chr(i) for i in xrange(32, 127)):
		output=""
		#cipher='5'
		for c in range(0, len(ascii)):
			output += chr( ord(ascii[c]) ^ (ord(cipher)) )
		score=FrequencyAnalysis(output)
		#print score, cipher
		#print output
		if( score < best ):
			second=best
			best = score
			bestc = ((cipher))
	#print bestc, best, second
	l=[bestc, best]
	return l

content = open('4.txt', 'r')

bestscore=9999
bestchar=' '
bestline=0
count=1
beststr=""
for l in content:
	l=l.strip()
	line = binascii.unhexlify(l)
	current = bestCipher(line)
	if( current[1] < bestscore ):
		bestchar = current[0]
		bestscore = current[1]
		bestline=count
		beststr=line
	count += 1
		
print "Best score was", bestscore, "for cipher", bestchar, "on line", bestline
#print "Best score", score, "From cipher", bestc
out=""
for c in range(0, len(beststr)):
	out += chr( ord(beststr[c]) ^ (ord(bestchar)) )
print out
