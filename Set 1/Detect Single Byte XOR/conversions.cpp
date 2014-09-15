#include "conversions.h"
#include <bitset>
#include "stdlib.h"		//for exit functions in g++

using namespace std;

std::deque<bool> conversions::HexToBinary(std::vector<char> HexVector)
{
	deque<bool> BinQue;
	char HexChar;
	string BinStr;
	map<char, string>::iterator i;
	map<char, string> hexToBin;
	hexToBin['0']="0000"; hexToBin['1']="0001"; hexToBin['2']="0010"; hexToBin['3']="0011"; hexToBin['4']="0100";
	hexToBin['5']="0101"; hexToBin['6']="0110"; hexToBin['7']="0111"; hexToBin['8']="1000"; hexToBin['9']="1001";
	hexToBin['A']="1010"; hexToBin['B']="1011"; hexToBin['C']="1100"; hexToBin['D']="1101"; hexToBin['E']="1110"; hexToBin['F']="1111";
	hexToBin['a']="1010"; hexToBin['b']="1011"; hexToBin['c']="1100"; hexToBin['d']="1101"; hexToBin['e']="1110"; hexToBin['f']="1111";

	
	for(vector<char>::reverse_iterator rit = HexVector.rbegin(); rit != HexVector.rend(); rit++)
	{
		HexChar = (*rit);
		i=hexToBin.find(HexChar);
		if(i == hexToBin.end())
		{
			cout << "\nInvalid Hex input: " << HexChar << endl;
			exit(1);
		}
		BinStr = i->second;
		BinQue.push_front( (BinStr[3] == '1') );
		BinQue.push_front( (BinStr[2] == '1') );
		BinQue.push_front( (BinStr[1] == '1') );
		BinQue.push_front( (BinStr[0] == '1') );
	}

	return BinQue;
}

std::deque<char> conversions::BinaryToBase64(std::deque<bool> BinaryQue)
{
	map<string, char> BinToBase64;
	map<string, char>::iterator it;
	BinToBase64["000000"]='A';BinToBase64["000001"]='B';BinToBase64["000010"]='C';BinToBase64["000011"]='D';BinToBase64["000100"]='E';BinToBase64["000101"]='F';BinToBase64["000110"]='G';BinToBase64["000111"]='H';
	BinToBase64["001000"]='I';BinToBase64["001001"]='J';BinToBase64["001010"]='K';BinToBase64["001011"]='L';BinToBase64["001100"]='M';BinToBase64["001101"]='N';BinToBase64["001110"]='O';BinToBase64["001111"]='P';
	BinToBase64["010000"]='Q';BinToBase64["010001"]='R';BinToBase64["010010"]='S';BinToBase64["010011"]='T';BinToBase64["010100"]='U';BinToBase64["010101"]='V';BinToBase64["010110"]='W';BinToBase64["010111"]='X';
	BinToBase64["011000"]='Y';BinToBase64["011001"]='Z';BinToBase64["011010"]='a';BinToBase64["011011"]='b';BinToBase64["011100"]='c';BinToBase64["011101"]='d';BinToBase64["011110"]='e';BinToBase64["011111"]='f';
	BinToBase64["100000"]='g';BinToBase64["100001"]='h';BinToBase64["100010"]='i';BinToBase64["100011"]='j';BinToBase64["100100"]='k';BinToBase64["100101"]='l';BinToBase64["100110"]='m';BinToBase64["100111"]='n';
	BinToBase64["101000"]='o';BinToBase64["101001"]='p';BinToBase64["101010"]='q';BinToBase64["101011"]='r';BinToBase64["101100"]='s';BinToBase64["101101"]='t';BinToBase64["101110"]='u';BinToBase64["101111"]='v';
	BinToBase64["110000"]='w';BinToBase64["110001"]='x';BinToBase64["110010"]='y';BinToBase64["110011"]='z';BinToBase64["110100"]='0';BinToBase64["110101"]='1';BinToBase64["110110"]='2';BinToBase64["110111"]='3';
	BinToBase64["111000"]='4';BinToBase64["111001"]='5';BinToBase64["111010"]='6';BinToBase64["111011"]='7';BinToBase64["111100"]='8';BinToBase64["111101"]='9';BinToBase64["111110"]='+';BinToBase64["111111"]='/';

	string BinChar, temp, tc;
	deque<char> Base64;

	while((BinaryQue.size() % 6) != 0)
		BinaryQue.push_front(false);

	while(BinaryQue.size() >= 6)
	{
		tc.clear();
		BinChar.clear();
		for(int i = 0; i < 6; i++)
		{
			tc += BinaryQue.back() ? '1' : '0' ;
			BinaryQue.pop_back();
		}
		BinChar+=tc[5];
		BinChar+=tc[4];
		BinChar+=tc[3];
		BinChar+=tc[2];
		BinChar+=tc[1];
		BinChar+=tc[0];
		it=BinToBase64.find(BinChar);
		if(it == BinToBase64.end())
		{
			cout << "\nInvalid Binary input\n";
			exit(1);
		}
		Base64.push_front(it->second);
	}

	return Base64;
}

std::vector<char> conversions::StringToVector(std::string inString)
{
	vector<char> returnVector;

	for(unsigned int i = 0; i < inString.length(); i++)
		returnVector.push_back(inString[i]);

	return returnVector;
}

void conversions::PrintDeque(std::deque<char> theQue)
{
	for(unsigned i = 0; i < theQue.size(); i++)
		cout << theQue.at(i);

	cout << endl;
};

void conversions::PrintDeque(std::deque<bool> theQue)
{
	for(unsigned i = 0; i < theQue.size(); i++)
		cout << theQue.at(i);

	cout << endl;
};

deque<bool> conversions::XORBinaryStringEqSize(deque<bool> firstQue, deque<bool> secondQue)
{
	if(firstQue.size() != secondQue.size())
	{
		cout << "Inputs not the same length" << endl;
		exit(1);
	}

	deque<bool> first, second;
	deque<bool> ret;
	//convert char to boolean
	for(unsigned int i = 0; i < firstQue.size(); i++)
		first.push_front( (firstQue.at(i)) ? false : true );

	for(unsigned int i = 0; i < secondQue.size(); i++)
		second.push_front( (secondQue.at(i)) ? false : true );

	for(unsigned int i = 0; i < first.size(); i++)
	{
		if( (first.at(i) + second.at(i)) % 2 )
			ret.push_front(true);
		else
			ret.push_front(false);
	}

	return ret;

}

std::deque<char> conversions::BinaryToHex(std::deque<bool> inQue)
{
	deque<char> BinQue;
	//char HexChar;
	string BinStr, t;
	map<string, char>::iterator i;
	map<string, char> BinToHex;
	BinToHex["0000"]='0';BinToHex["0001"]='1';BinToHex["0010"]='2';BinToHex["0011"]='3';
	BinToHex["0100"]='4';BinToHex["0101"]='5';BinToHex["0110"]='6';BinToHex["0111"]='7';
	BinToHex["1000"]='8';BinToHex["1001"]='9';BinToHex["1010"]='A';BinToHex["1011"]='B';
	BinToHex["1100"]='C';BinToHex["1101"]='D';BinToHex["1110"]='E';BinToHex["1111"]='F';

	while((inQue.size() % 4) != 0)
		inQue.push_front(false);


	for(deque<bool>::reverse_iterator rit = inQue.rbegin(); rit != inQue.rend(); rit++)
	{
		BinStr += (*rit) ? '1' : '0';
		if(BinStr.length() == 4)
		{
			t += BinStr[3];
			t += BinStr[2];
			t += BinStr[1];
			t += BinStr[0];
			i=BinToHex.find(t);
			if(i == BinToHex.end())
			{
				cout << "\nInvalid binary input\n";
				exit(1);
			}
			BinQue.push_front(i->second);
			BinStr.clear();
			t.clear();
		}
	}

	return BinQue;
}

deque<char> conversions::BinaryToAscii(deque<bool> input)
{
	bitset<8> character;
	int bitPos = 0;
	int charascii;
	deque<char> output;

	while((input.size() % 8) != 0)
		input.push_front(false);

	for(deque<bool>::reverse_iterator rit = input.rbegin(); rit != input.rend(); rit++)
	{
		character[bitPos] = input.at((*rit));
		bitPos++;
		
		if(bitPos >=8)
		{
			bitPos = 0;
			charascii = character.to_ulong();
			//cout << charascii << " ";
			output.push_front(char(charascii));
		}

	}
	//cout << endl;
	return output;
}




