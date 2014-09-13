/*
To Compile with g++
	g++ -std=c++0x main.cpp HexToBase64.cpp


*/

#include "HexToBase64.h"

using namespace std;

int main()
{
	string hexString;
	deque<char> BinaryQue, base64;
	cout << "Input a hex number: ";
	cin >> hexString;

	BinaryQue = conversions::HexToBinary(conversions::StringToVector(hexString));
	base64 = conversions::BinaryToBase64(BinaryQue);

	cout << "Base64 value: ";
	conversions::PrintDeque(base64);

	return 0;
	
}

