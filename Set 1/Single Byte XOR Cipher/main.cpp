/*
To Compile with g++
	g++ -std=c++0x main.cpp conversions.cpp cipher.cpp

*/
#include "conversions.h"
#include "cipher.h"

using namespace std;

int main()
{
	string in1, in2, in3;
	deque<bool> output, input;
	float best, current;
	char cip, bestChar;
	cip = ' ';
	best = 0;
	cout << "Enter a string encoded with a single character cipher: ";
	cin >> in1;
	cout << "Decoding..." << endl;

	input = conversions::HexToBinary(conversions::StringToVector(in1));

	for(int i = 0; i < 94; i++)
	{
		output = cipher::oneByteXOR(input, cip+i);
		current = cipher::languageScore(conversions::BinaryToAscii(output));
		if(current > best)
		{
			best = current;
			bestChar = char(cip+i);
		}

	}

	cout << "Most likely cipher is: " << bestChar << " with a score of " << best << endl;
	cout << "The string this cipher produces is:\n";
	conversions::PrintDeque(conversions::BinaryToAscii(cipher::oneByteXOR(input, bestChar)));

	return 0;
}
