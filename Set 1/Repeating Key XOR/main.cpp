/*
To Compile with g++
	g++ main.cpp conversions.cpp cipher.cpp		


Everything works, Just setup this file to accept either:
	1) A string from keyboard
	2) Open a file and encrypt it appending .enc to file name
	3) Open a file and decrypt it removing .enc from file name
*/
#include "conversions.h"
#include "cipher.h"
#include <fstream>
#include <streambuf>
#include <ctime>
#include <sstream>
#include <limits>

const size_t bits_per_byte = std::numeric_limits<unsigned char>::digits;
using namespace std;

int main()
{
	string cipher, newname, inputfile, outputstring, input;
	clock_t start;
	double duration;
	deque<bool> output, out1, encode;
	int choice;
	//cipher = "ICE";
	ofstream out;
	//char choice;
	start = clock();
	cout << bits_per_byte << endl;
	cout << "Choose a mode, 1 For string input, 2 to encrypt entire file, 3 to read file contents: ";
	getline(cin, input);
	stringstream stream(input);
	stream >> choice;
		

	if( choice == 1 )
	{
		cout << "Enter the string to encrypt: ";
		getline(cin, input);

		cout << "Enter the password to encrypt the file with: ";
		getline(cin, cipher);

		conversions::PrintDeque(conversions::BinaryToHex(cipher::repeatingKeyXOR(conversions::AsciiToBinary(conversions::StringToVector(input)), cipher)));
	}
	else if( choice == 2)
	{
		cout << "Enter the file name: ";
		getline(cin, inputfile);

		cout << "Enter the password to encrypt the file with: ";
		getline(cin, cipher);

		ifstream t(inputfile);
		string in1((istreambuf_iterator<char>(t)),
			istreambuf_iterator<char>());

		conversions::PrintDeque(conversions::BinaryToHex(cipher::repeatingKeyXOR(conversions::AsciiToBinary(conversions::StringToVector(in1)), cipher)));

	}
/*	else if( choice == 3)
	{

		cout << "Enter the file to encrypt: ";
		getline(cin, inputfile);
		cout << "Enter the new file name: ";
		getline(cin, newname);

		cout << "Enter the password to encrypt the file with: ";
		getline(cin, cipher);

		ifstream in1(inputfile, ios::binary);
		char c;
		while( in1.get(c) )
			input += bitset<8>( unsigned char(c) ).to_string();

		output = cipher::repeatingKeyXOR(conversions::BinaryVectorToDeque(conversions::StringToVector(input)), cipher);
		outputstring = conversions::DequeToString(conversions::BinaryToAscii(output));

		while( outputstring.size()%bits_per_byte) outputstring += '0';

		ofstream outfile(newname, ios::binary);

		for(int i = 0; i < outputstring.size(); i++)
		{
			unsigned char b = outputstring[i];
			outfile << b;
		}

		//for(size_t i = 0; i < outputstring.size(); i += bits_per_byte)
		//{
		//	string tmp= outputstring.substr( i, bits_per_byte );
		//	for(int k = 0; k < tmp.size(); k++)
		//		tmp[k] = ( tmp[k]=='\0' || tmp[k]=='0' ) ? '0' : '1';

		//	unsigned char b = bitset<bits_per_byte>( tmp ).to_ulong();
		//	//cout << b;
		//	outfile << b;
		//}

		in1.close();
		outfile.close();
	} */
	else
		cout << "Invalid input\n";

	duration = (clock() - start)/(double)CLOCKS_PER_SEC;

	cout << "Algorithm took " << duration << " seconds\n";

	return 0;
}
