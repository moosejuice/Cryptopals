/*
To Compile with g++
	g++ main.cpp conversions.cpp cipher.cpp		//currently isn't running gcc 4.6.3 Ubuntu

*/
#include "conversions.h"
#include "cipher.h"
#include <fstream>
#include <ctime>

using namespace std;

int main()
{
	string in1, bestString;
	deque<bool> output, input;
	float best, current;
	int line, bestLine;
	char cip, bestChar;
	ifstream inFile;
	clock_t start;
	double duration;
	cip = bestChar = ' ';
	best = 0;
	line = bestLine = 0;

	cout << "Opening file" << endl;
	inFile.open("4.txt");
	if(!inFile.is_open())
	{
		cout << "Error opening file. Exiting." << endl;
		return 1;
	}

	
	cout << "Decoding input file";

	start = clock();
	while ( inFile >> in1 )
	{
		line++;
		if( (line%10) == 0)
			cout << " " << int((float)line/327*100) << "%";
		//cout << in1;
		for(int i = 0; i < 94; i++)		
		{
			//cip='X';
			input = conversions::HexToBinary(conversions::StringToVector(in1));
			output = cipher::oneByteXOR(input, cip+i);
			current = cipher::languageScore(conversions::BinaryToAscii(output));
			if(current > best)
			{
				best = current;
				bestChar = char(cip+i);
				bestString = in1;
				bestLine = line;
			}
		}
	}
	duration = (clock() - start)/(double)CLOCKS_PER_SEC;

	cout << "\nMost likely line to be encoded is " << bestLine << " with the cipher " << bestChar << " and a language score of " << best << endl;
	cout << "The string this cipher produces is:\n";
	conversions::PrintDeque(conversions::BinaryToAscii(cipher::oneByteXOR(conversions::HexToBinary(conversions::StringToVector(bestString)), bestChar)));

	cout << "Detection algorithm took " << duration << " seconds\n";
	inFile.close();
	return 0;
}
