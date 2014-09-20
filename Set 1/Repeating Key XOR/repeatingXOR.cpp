#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <fstream>

using namespace std;

int main()
{	
	string input, cipher;
	stringstream ss;
	int choice;

	cout << "Choose a mode, 1 For string input (Ascii), "
						<<	"2 For string input (hex), "
						<<	"3 to encrypt entire file, "
						<<	"4 to read file contents (Ascii) ";

	getline(cin, input);
	ss << input;
	ss >> choice;
	ss.str("");
	ss.clear();
	input="";

	if( choice == 1 )
	{
		cout << "Enter input string in ASCII: ";
		getline(cin, input);

		cout << "Enter the cipher: ";
		getline(cin, cipher);
	}
	else if( choice == 2 )
	{		
		string inputHex;
		cout << "Enter input string in HEX: ";
		getline(cin, inputHex);
		int offset = 0;
		unsigned int buffer;
		while (offset < inputHex.length() )
		{
			ss.clear();
			ss << std::hex << inputHex.substr(offset, 2);
			ss >> buffer;
			input += (unsigned char)buffer;
			offset += 2;
		}

		cout << "Enter the cipher: ";
		getline(cin, cipher);
	}
	else if( choice == 3 )
	{
		cout << "NOT COMPLETE" << endl;
		return 0;
	}
	else if( choice == 4 )
	{
		string inputfile;
		cout << "Enter the file to read: ";
		getline(cin, inputfile);

		cout << "Enter the cipher: ";
		getline(cin, cipher);

		ifstream t(inputfile);
		input.assign((istreambuf_iterator<char>(t)),
			istreambuf_iterator<char>());
	}
	
	ss.str(""); ss.clear();

	ss << std::hex << std::setfill('0') << std::noskipws;
	for(int i = 0; i < input.size(); i++)
	{	
		cout << input[i];
		ss << std::setw(2) << (unsigned int)( input[i] ^ cipher[i%cipher.size()] );
	}

	cout << ss.str() << endl;

return 0;
}