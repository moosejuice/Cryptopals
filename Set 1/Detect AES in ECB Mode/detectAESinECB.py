#!/usr/bin/python
from collections import Counter
import itertools
import math

'''
Detect if AES is in ECB mode
The lower the score, the better
Set best score as worst score possible
Split input into chunks of 16 bytes, since input is hex, this is len 32
Place this output into a set, so we can count distinct values (lower is worse, more likely to be ECB)
Return the line with the lowest score as it is most likely the ECB encoded string
'''
def detectAESinECB(inFile):
	f=open(inFile, 'r')
	content=f.readlines()
	best=""
	bestscore=math.ceil(len(content[0])/32.0)	#set best score(actually worst) as number of chunks
	for x in content:
		c = [x[i:i+32] for i in range(0,len(x),32)]
		distinct=set(c)
		if bestscore > len(distinct):
			bestscore = len(distinct)
			best=x

	print "Best score", bestscore, "from input string:"
	print best

if __name__ == '__main__':
	detectAESinECB('8.txt')
