#include "cipher.h"
#include <bitset>
#include "stdlib.h"		//for exit functions in g++

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
	//calculates chi-squared of Frequency tally and known frequency. It then deducts points for non-ascii characters and non-letter ascii characters
	//to assign a likelyhood score to the input string. The higher the output value, the more likely it is to contain a readable string.
	//NOTE: A word is on average 5 letters long, thus the Frequency of the space key is about 20% and is separated from other letters.

	double chiSquared, score, tallyPercent;
	int other, nonAscii, inSize, spaces;
	map<char, int>::iterator it;
	map<char, int> FrequencyTally;
	map<char,double> KnownFrequency;
	map<char,double>::iterator ik;

	FrequencyTally['e']=0;FrequencyTally['t']=0;FrequencyTally['a']=0;FrequencyTally['o']=0;
	FrequencyTally['i']=0;FrequencyTally['n']=0;FrequencyTally['s']=0;FrequencyTally['h']=0;
	FrequencyTally['r']=0;FrequencyTally['d']=0;FrequencyTally['l']=0;FrequencyTally['c']=0;
	FrequencyTally['u']=0;FrequencyTally['m']=0;FrequencyTally['w']=0;FrequencyTally['f']=0;
	FrequencyTally['g']=0;FrequencyTally['y']=0;FrequencyTally['b']=0;FrequencyTally['k']=0;
	FrequencyTally['p']=0;FrequencyTally['v']=0;FrequencyTally['j']=0;FrequencyTally['x']=0;
	FrequencyTally['q']=0;FrequencyTally['z']=0;FrequencyTally[' ']=0;
	
	KnownFrequency['e']=12.702;KnownFrequency['t']=9.056;KnownFrequency['a']=8.167;KnownFrequency['o']=7.507;
	KnownFrequency['i']=6.966; KnownFrequency['n']=6.749;KnownFrequency['s']=6.327;KnownFrequency['h']=6.094;
	KnownFrequency['r']=5.987; KnownFrequency['d']=4.253;KnownFrequency['l']=4.025;KnownFrequency['c']=2.782; 
	KnownFrequency['u']=2.758; KnownFrequency['m']=2.406;KnownFrequency['w']=2.360;KnownFrequency['f']=2.228;
	KnownFrequency['g']=2.015; KnownFrequency['y']=1.974;KnownFrequency['b']=1.492;KnownFrequency['k']=0.772;
	KnownFrequency['p']=1.929; KnownFrequency['v']=0.978;KnownFrequency['j']=0.153;KnownFrequency['x']=0.150;
	KnownFrequency['q']=0.095; KnownFrequency['z']=0.074;KnownFrequency[' ']=20.000;

	chiSquared = 0;
	other = nonAscii = spaces = 0;
	inSize = input.size();

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
		{
			it->second++;

			if(it->first == ' ')
				spaces++;
		}

	}
	
	

	for(it=FrequencyTally.begin(); it != FrequencyTally.end(); ++it)
	{
		if( it->first != ' ' )
		{
			ik = KnownFrequency.find(it->first);
			if(it == FrequencyTally.end())
			{
				cout << "Search error\n";
				exit(0);
			}
			if(inSize == spaces)
				inSize++;
			tallyPercent = double(it->second)/(inSize-spaces);
			chiSquared += (tallyPercent - ik->second) * (tallyPercent - ik->second) / ik->second;
		}
		else
		{
			ik = KnownFrequency.find(it->first);
			if(inSize == spaces)
				inSize++;
			tallyPercent = double(it->second)/(inSize);
			chiSquared += 2*(tallyPercent - ik->second) * (tallyPercent - ik->second) / ik->second;
		}
	}
	
	score = chiSquared;


	if( nonAscii > (inSize/2)  )	//if more than half the characters are non-ascii, its probably not readable in any useful way
		return float(0);
	
	score = score - (float(nonAscii) / inSize)*100;	//subtract % of non ascii characters from current score
	score = score - (float(other) / inSize)*100;	//subtract % of non-alphabet ascii characters from current score


	return float(score);
}

