#!/usr/bin/python
from Crypto.Cipher import AES
from Crypto import Random
import base64

def decryptAESbase64(inputFile):
	print "Opening", inputFile
	with open(inputFile, 'r') as content:
		data=content.read().replace('\n','').decode("base64")	#decode the base64 input

	key = "YELLOW SUBMARINE"
	#create the cipher
	iv = Random.new().read(AES.block_size)
	cipher = AES.new(key, AES.MODE_ECB, iv)
	#decrypt
	msg = cipher.decrypt(data)

	print msg

if __name__ == '__main__':
	decryptAESbase64("7.txt")
	