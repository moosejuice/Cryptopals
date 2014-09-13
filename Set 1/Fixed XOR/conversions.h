#ifndef CONVERSIONS_H
#define CONVERSIONS_H
/*
	Add XORBinaryString, BinaryToHex from latest challenge version. Update to more appropriate file name. 
*/
#include <iostream>
#include <string>
#include <deque>
#include <bitset>
#include <map>
#include <vector>

class conversions {
public:
	static std::deque<char> HexToBinary(std::vector<char>);
	static std::deque<char> BinaryToBase64(std::deque<char>);
	static std::vector<char> StringToVector(std::string);
	static void PrintDeque(std::deque<char>);
	static std::deque<char> XORBinaryStringEqSize(std::deque<char>, std::deque<char>);
	static std::deque<char> BinaryToHex(std::deque<char>);
};



#endif
