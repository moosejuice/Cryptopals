#!/usr/bin/python

#Function to implement PKCS#7 Padding
#input -> unpadded text, and required block size
#output -> padded text
def PKCS7Padding(text, blocksize):
	padd=blocksize-(len(text)%blocksize)
	if padd == blocksize: padd = 0
	return text + (chr(padd)*padd)

if __name__ == '__main__':
	unpad = raw_input("Enter a string: ")
	block = int(raw_input("Enter block size in bytes: "))
	pad = PKCS7Padding(unpad,block)
	print "Length of padded string:", len(pad)
	print "Padded result:", pad.encode('string_escape')		#print non printable characters as hex representation
