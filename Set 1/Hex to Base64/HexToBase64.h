#ifndef HEXTOBASE64_H
#define HEXTOBASE64_H
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

};



#endif