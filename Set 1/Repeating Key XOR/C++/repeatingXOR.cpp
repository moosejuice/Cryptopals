#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <fstream>

using namespace std;

int main()
{	
	string input, cipher, inputfile;
	stringstream ss;
	int choice;

	cout << "All screen dumps are hex\n";
	cout << "Choose a mode:\n1 For string input (Ascii)\n"
						<<	"2 For string input (hex)\n"
						<<	"3 to encrypt entire file\n"
						<<	"4 to read file contents (Ascii)\n"
						<<	"5 to decrypt entire file: ";

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
		unsigned int offset = 0;
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
	else if( choice == 3 || choice == 5 )
	{
		cout << "Enter the file to read: ";
		getline(cin, inputfile);

		cout << "Enter the cipher: ";
		getline(cin, cipher);

		ifstream t(inputfile, ios::binary);
		input.assign((istreambuf_iterator<char>(t)),
			istreambuf_iterator<char>());
		t.close();
	}
	else if( choice == 4 )
	{
		cout << "Enter the file to read: ";
		getline(cin, inputfile);

		cout << "Enter the cipher: ";
		getline(cin, cipher);

		ifstream t(inputfile);
		input.assign((istreambuf_iterator<char>(t)),
			istreambuf_iterator<char>());
		t.close();
	}

	if( choice == 4 || choice == 2 || choice == 1)
	{
		ss.str(""); ss.clear();
		ss << std::hex << std::setfill('0') << std::noskipws;
		for(unsigned int i = 0; i < input.size(); i++)
			ss << std::setw(2) << (unsigned int)( input[i] ^ cipher[i%cipher.size()] );
		cout << ss.str() << endl;
	}
	else
	{
		string outputfile;
		if( choice == 3 )
		{
			outputfile = inputfile + ".enc";
			cout << "Writing to " << outputfile;
		}
		else
		{
			size_t end = inputfile.find(".enc");
			if( end == string::npos )
			{
				cout << "Invalid file\n";
				return 0;
			}
			outputfile = inputfile.substr(0, end);
			cout << "Writing to " << outputfile;
		}

		ofstream out(outputfile, ios::binary);
		for(unsigned int i = 0; i < input.size(); i++)
			out << (unsigned char)( input[i] ^ cipher[i%cipher.size()] );
		
		remove(inputfile.c_str());
	}

	cout << endl;
	return 0;
}