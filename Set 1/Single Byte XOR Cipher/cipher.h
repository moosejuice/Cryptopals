#ifndef CIPHER_H
#define CIPHER_H
#include "conversions.h"


class cipher {
public:
	static std::deque<bool> oneByteXOR(std::deque<bool>, char);		//takes in a binary string(deque form) and applies a single byte cipher to it using XOR. Returns the result
	static float languageScore(std::deque<char>);					//takes a english language string(deque) and compares its contents to a letter frequency histogram. Values closer to one are more likely to contain readable english

};




#endif