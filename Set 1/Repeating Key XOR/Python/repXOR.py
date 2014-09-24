#/usr/bin/python
import binascii

print "Opening input.txt..."

with open('input.txt', 'r') as content:
	asciiIn = content.read()

cipher = raw_input("Enter the cipher string: ")
output=""
counter = 0

for x in asciiIn:
        output += chr( ord(x) ^ ord(cipher[counter%len(cipher)]))
        counter+=1

print binascii.hexlify(output)

