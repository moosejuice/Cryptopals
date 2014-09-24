#include "cipher.h"
#include <bitset>

using namespace std;

deque<bool> cipher::oneByteXOR(deque<bool> binQue, char cipher)
{
	bool binCipher[8];
	string temp;
	deque<bool> output, first;
	int cipherPos = 0;

	temp = bitset<8>(cipher).to_string();

	for(int i = 0; i < 8; i++)
	{
		binCipher[7-i] = ( temp[i] == '1' );
	}


	//convert char to boolean
	for(unsigned int i = 0; i < binQue.size(); i++)
		first.push_front( (binQue.at(i)) ? false : true );

	for(unsigned int i = 0; i < first.size(); i++)
	{
		if( (first.at(i) + binCipher[cipherPos]) % 2 )
			output.push_front(true);
		else
			output.push_front(false);
		cipherPos++;
		if(cipherPos >= 8)
			cipherPos = 0;
	}


	return output;

}

float cipher::languageScore(std::deque<char> input)
{
	//only a very basic frequency analysis is done here. Is set up to become more accurate in the future. 

	map<char, int>::iterator it;
	map<char, int> FrequencyTally;
	FrequencyTally['e']=0;FrequencyTally['t']=0;FrequencyTally['a']=0;FrequencyTally['o']=0;
	FrequencyTally['i']=0;FrequencyTally['n']=0;FrequencyTally['s']=0;FrequencyTally['h']=0;
	FrequencyTally['r']=0;FrequencyTally['d']=0;FrequencyTally['l']=0;
	FrequencyTally['c']=0;FrequencyTally['u']=0;FrequencyTally['m']=0;
	FrequencyTally['w']=0;FrequencyTally['f']=0;FrequencyTally['g']=0;
	int other, nonAscii, inSize;
	other = nonAscii = 0;
	inSize = input.size();

	map<char,double> KnownFrequency;
	map<char,double>::iterator ik;
	KnownFrequency['e']=12.702;KnownFrequency['t']=9.056;KnownFrequency['a']=8.167;KnownFrequency['o']=7.507;
	KnownFrequency['i']=6.966; KnownFrequency['n']=6.749;KnownFrequency['s']=6.327;KnownFrequency['h']=6.094;
	KnownFrequency['r']=5.987; KnownFrequency['d']=4.253;KnownFrequency['l']=4.025;
	KnownFrequency['c']=2.782; KnownFrequency['u']=2.758;KnownFrequency['m']=2.406;
	KnownFrequency['w']=2.360; KnownFrequency['f']=2.228;KnownFrequency['g']=2.015;
	//92.379

	for(unsigned int i = 0; i < input.size(); i++)
	{
		it = FrequencyTally.find(tolower(input.at(i)));
		if(it == FrequencyTally.end())
		{
			int t = int(input.at(i));
			if( (t < 0) || (t >= 128))
				nonAscii++;
			else
				other++;
		}
		else
			it->second++;

	}

	int fCount = 0;
	float score, freq;
	for(it=FrequencyTally.begin(); it != FrequencyTally.end(); ++it)
		fCount += it->second;

	freq = float(fCount)/inSize;
	score = freq/float(92.379);		//score is abs of top 11 english characters. frequency in the string compared to that of the english language

	if( score > 1.0)
		score = score - 2*(score-1);

	if( nonAscii > (inSize/2)  )	//if more than half the characters are non-ascii, its probably not readable in any useful way
		return float(0);
	else
		score = score - (nonAscii / inSize);	//subtract % of non ascii characters from current score

	return score;
}

