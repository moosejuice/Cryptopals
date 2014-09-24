#!/usr/bin/python
import binascii
import base64
from keysize import guessKeySize
from singlexor import bestCipher
from frequencyAnalysis import FrequencyAnalysis

#Main Function: Input - Input file path (base64), how many of the most likely key sizes to try before choosing the best
#Output: String decoded using the best choice key
def breakRepeatingKeyXOR(inputFile, maxcount):
	if maxcount > 40: maxcount=40
	print "Opening", inputFile
	with open(inputFile, 'r') as content:
		data=content.read().replace('\n','').decode("base64")	#decode the base64 input

	hexstr=binascii.hexlify(data)	#turn input into hex
	d = guessKeySize(hexstr)		#guess key size, returns dictionary of keysize, edit dist.
	count=0
	bestcipher=""
	bestscore=9999
	for best in sorted(d, key=d.get, reverse=False):	#cycle through best to worst edit dist.
		l=[]
		avg=0
		mycipher=""
		out=""
		for x in range(0,best):		#init list length
			l.append("")

		for x in range(0,len(data)):		#break up block into individual bytes to solve as series of single char xor
			l[x%best] = l[x%best]+data[x]

		for x in l:				#solve each indiviual single char xor, building cipher string & score
			cip = bestCipher(x)
			mycipher += cip[0]
			avg += cip[1]
			
		avg /= len(l)
		if avg < bestscore:		#only keep best score
			bestscore = avg
			bestcipher = mycipher
		if count >= maxcount:	#only try max count key lengths
			break
		count += 1

	best=len(bestcipher)	
	for x in range(0, len(data)):
		out += chr( ord(data[x]) ^ ord(bestcipher[x%best]))

	print "The most likely cipher found to be:", bestcipher
	return out

if __name__ == "__main__":
	tries = int(raw_input("Enter max number of tries:"))
	out = breakRepeatingKeyXOR('input.txt', tries)
	if 'Y' == raw_input("Does this look legit? (Y) To decode: ").upper():
		print out
