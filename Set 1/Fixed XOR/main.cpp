/*
To Compile with g++
	g++ -std=c++0x main.cpp conversions.cpp

*/
#include "conversions.h"

using namespace std;

int main()
{
	string in1, in2;
	deque<char> output;

	cout << "Enter the first hex string: ";
	cin >> in1;
	cout << "Enter the second hex string: ";
	cin >> in2;

	output = conversions::XORBinaryStringEqSize( conversions::HexToBinary(conversions::StringToVector(in1)), conversions::HexToBinary(conversions::StringToVector(in2)) );

	cout << "After XOR: " << endl;
	conversions::PrintDeque(conversions::BinaryToHex(output));

	return 0;
}
