#ifndef CONVERSIONS_H
#define CONVERSIONS_H
/*
	Add XORBinaryString, BinaryToHex from latest challenge version. Update to more appropriate file name. 
	Update deque types. Binary Queues should be of bool type.
*/
#include <iostream>
#include <string>
#include <deque>
#include <bitset>
#include <map>
#include <vector>

class conversions {
public:
	static std::deque<bool> HexToBinary(std::vector<char>);			//converts a hex string (vector) to a binary string (deque)
	static std::deque<char> BinaryToBase64(std::deque<bool>);		//converts a binary string (held within a deque) to a base64 string (in another deque)
	static std::vector<char> StringToVector(std::string);			//converts a string to a vector. Vector is a more useful data structure for my purposes
	static void PrintDeque(std::deque<char>);						//prints a deque
	static void PrintDeque(std::deque<bool>);
	static std::deque<bool> XORBinaryStringEqSize(std::deque<bool>, std::deque<bool>);		//performs bit by bit XOR on two equal length binary strings (held in deque)
	static std::deque<char> BinaryToHex(std::deque<bool>);			//converts binary string (held in deque) to a hex string(held in a deque)
	static std::deque<char> BinaryToAscii(std::deque<bool>);
	static std::deque<bool> AsciiToBinary(std::vector<char>);
	static std::deque<bool> BinaryVectorToDeque(std::vector<char>);
	static std::string DequeToString(std::deque<bool>);
	static std::string DequeToString(std::deque<char>);
};



#endif
