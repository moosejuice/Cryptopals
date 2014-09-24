#!/usr/bin/python
import binascii

#str1 and str2 are the two strings to be compared.
#type is: 'a' for ascii strings, 'h' for hex strings
#output: The hamming distance or edit distance of the input strings
def HammingDistance( str1, str2, type ):
	popcount = {'0':0, '1':1, '2':1, '3':2, '4':1, '5':2, '6':2, '7':3, '8':1, '9':2, 'a':2, 'b':3, 'c':1, 'd':3, 'e':3, 'f':4}
	if len(str1) != len(str2):
		print "Cannot calculate Hamming distance when inputs are not the same length"
		return
	xor=""
	if type == 'a':
		for x in range(0,len(str1)):
			xor += chr( ord(str1[x]) ^ ord(str2[x]))

	elif type == 'h':
		for x in range(0,len(str1)):
			xor += chr( int(str1[x], 16) ^ int(str2[x],16))
	else:
		print "Invalid input type"
		return -1
		
	hexstr = binascii.hexlify(xor)	
	distance=0
	for x in hexstr:
		distance += popcount[x]
	return distance




