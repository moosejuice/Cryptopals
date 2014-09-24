#!/usr/bin/python
import collections

#takes ascii string as input, returns a score, the lower/closer to zero, the more likey it is to contain english
def FrequencyAnalysis(strIn):
	englishLetterFreq = {'E': 12.702, 'T': 9.056, 'A': 8.167, 'O': 7.507, 'I': 6.966, 'N': 6.749, 'S': 6.327, 'H': 6.094, 'R': 5.987, 'D': 4.253, 'L': 4.025, 'C': 2.782, 'U': 2.758, 'M': 2.402, 'W': 2.360, 'F': 2.228, 'G': 2.015, 'Y': 1.974, 'P': 1.929, 'B': 1.492, 'V': 0.978, 'K': 0.772, 'J': 0.153, 'X': 0.150, 'Q': 0.095, 'Z': 0.074}
	nonChar=len(strIn)
	inLen = len(strIn)
	nonAscii=0
	space=0
	other=0
	count = collections.Counter(strIn.upper())
	total = sum(count.values())
	for x in range(0,len(strIn)):
		if (ord(strIn[x]) < 0) or (ord(strIn[x]) > 127):
			nonAscii += 1
		elif ( ord(strIn[x].upper()) < 65 ) or ( ord(strIn[x].upper()) > 90 ):
			if ord(strIn[x]) == 32:
				space += 1
			else:
				other += 1
	chi=0
	
	for k,e in englishLetterFreq.items():
		if inLen == space: inLen += 1
		c=count[k]/float(inLen-space)*100
		chi += (c-e)*(c-e)/float(e)
	c=space/float(inLen)*100
	chi += ( (c-16.667)*(c-16.667)/float(16.667) )
	chi += ( nonAscii/float(inLen) )*100
	#facor amount that are actual letters or space
	#a = total + space
	#chi += 2*(a-inLen)*(a-inLen)/float(inLen)
	#Other is puncuation. Should expect ~ 2%
	o=other/float(inLen)*100
	chi += (o-2.0)*(o-2.0)/float(2.0)
	#print count
	#print nonAscii, space, other, o, c,( (c-16.667)*(c-16.667)/float(16.667) ),  chi
	if(nonAscii > (inLen/2)):	#mostly unreadable characters
		return 99999
	
	return chi