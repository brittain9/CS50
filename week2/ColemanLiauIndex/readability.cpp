#include <iostream>
#include <string>
#include <vector>
#include <sstream>


/*Harvard CS50 readability problem set
 *Compute Coleman-Liau index from string entered by the user
 *formula: index = 0.0588 * L - 0.296 * S - 15.8
 *where L is average number of letters per 100 words of text
 *S is average number of sentences per 100 words in the text
 */

using std::string;
using std::vector;
typedef vector<string> strVec;

//function declarations
int countLetters(string string1);
strVec arrayofWords(string string1);
int countPunct(string string1);

int main(int argc, string argv[]) //no command line argument required, but want to get used to seeing the format.
{
	//get user input
	printf("Please enter the text to determine Coleman-Liau index: ");
	string userEntry;
	std::getline(std::cin, userEntry);
	printf("%s", userEntry.c_str()); //temp tracing line

	//get amount of letters, split the string into tokens, and find punctuation to determine sentence count.
	int letters = countLetters(userEntry);
	strVec vec1 = arrayofWords(userEntry);
	int words = vec1.size();
	int punct = countPunct(userEntry);

	//compute Coleman-Liau Index
	double L{letters / (double)words * 100 };
	double S{ punct / (double)words * 100 };
	double index{ 0.0588 * L - 0.296 * S - 15.8 };
	printf("Letter count: %i\nWord Count: %i\nSentence Count: %i\nGrade Level: %.1f",letters, words, punct, index);
}

int countLetters(string string1)
{
	int n = string1.length();

	int spaceCount{ 0 };
	int endCount{ 0 };
	//loop through string and count all spaces and necessary punctuation to calculate # of letters.
	for(int i{0}; i < n; i++)
	{
		if (string1[i] == ' ') spaceCount++;
		if (string1[i] == '!' || string1[i] == '.' || string1[i] == '?') endCount++;

	}

	return  n - spaceCount - endCount ; //return letters
}

strVec arrayofWords(string string1)
{
	//create vector to store words in
	strVec words;

	std::stringstream ss(string1);
	string word;
	while (ss >> word)
	{
		words.push_back(word);
	}
	return words;
}

int countPunct(string string1)
{
	//simplistic function to count sentences. Doesn't work for reality, but works for this problem set.
	int n = string1.length();

	int endCount{ 0 };
	for (int i{ 0 }; i < n; i++)
	{
		if (string1[i] == '!' || string1[i] == '.' || string1[i] == '?') endCount++;
	}

	return endCount; //return letters
}