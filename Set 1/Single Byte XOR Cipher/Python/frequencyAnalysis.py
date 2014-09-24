#!/usr/bin/python
import collections

#takes ascii string as input, returns a score, the lower/closer to zero, the more likey it is to contain english
def FrequencyAnalysis(strIn):
	englishLetterFreq = {'E': 12.70, 'T': 9.06, 'A': 8.17, 'O': 7.51, 'I': 6.97, 'N': 6.75, 'S': 6.33, 'H': 6.09, 'R': 5.99, 'D': 4.25, 'L': 4.03, 'C': 2.78, 'U': 2.76, 'M': 2.41, 'W': 2.36, 'F': 2.23, 'G': 2.02, 'Y': 1.97, 'P': 1.93, 'B': 1.29, 'V': 0.98, 'K': 0.77, 'J': 0.15, 'X': 0.15, 'Q': 0.10, 'Z': 0.07}
	nonChar=len(strIn)
	inLen = len(strIn)
	nonAscii=0
	space=0
		
	count = collections.Counter(strIn.upper())
	total = sum(count.values())
	for x in range(0,len(strIn)):
		if ord(strIn[x]) < 0 or ord(strIn[x]) > 127:
			nonAscii += 1
		if strIn[x] == ' ':
			space += 1
	chi=0
	for k,e in englishLetterFreq.items():
		c=count[k]/float(inLen-space)
		chi += (c-e)*(c-e)/float(e)
	c=space/float(inLen-nonAscii)
	chi += ( (c-16.67)*(c-16.67)/float(16.67) )
	chi += ( nonAscii/inLen )
	if(nonAscii > (inLen/2)):	#mostly unreadable characters
		return 99999
	return chi