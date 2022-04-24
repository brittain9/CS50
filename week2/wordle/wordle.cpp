#include <iostream>
#include <windows.h>
#include <iostream>
#include <string>
#include <numeric>
#include <algorithm>
//created in C++20 and C17
//my attempt at wordle for problem set 2 of CS50. Had a lot of fun doing this one.
//lots of improvement could be made, but im following the course which has not introduced lots of material yet.

void toUpper(std::string& makeUpper);
std::string setWord();

//copy and pasted the enum, color function
enum Color {
	DBLUE = 1, GREEN, GREY, DRED, DPURP, BROWN, LGREY, DGREY, BLUE, LIMEG, TEAL,
	RED, PURPLE, YELLOW, WHITE, B_B
};
/* These are the first 16 colors anyways. You test the other hundreds yourself.
   After 15 they are all combos of different color text/backgrounds. */

bool quit;

//function to assign color to text using windows.h
void col(unsigned short color)
{
	HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hcon, color);
}

int main(void)
{
	col(TEAL); //set color to fun color
	printf("Welcome to two player WORDLE!\n");
	col(LGREY); //back to grey

	//change word here
	std::string wordle = setWord();
	//change word here


	toUpper(wordle);


	std::string userGuess;

	//main game loop
	const int GUESSES{ 5 };
	int attempts{ 0 };
	while (attempts <= GUESSES)
	{
		col(LGREY);
		printf("\nPlease enter attempt %i: ", attempts + 1);
		//Wordle words are 5 characters; therefore, we read only 5 characters; the 6 includes null terminator for c string.
		std::cin >> userGuess;
		std::cin.ignore(30000, '\n'); //30000 because windows.h messed up the max() function from numeric_limits
		if (userGuess.length() != 5)
		{
			col(LGREY);
			printf("Please enter a 5 letter word.\n\n");
			continue;
		}

		toUpper(userGuess);
		//check if user entered the correct word
		if (strcmp(wordle.c_str(), userGuess.c_str()) == 0)
		{
			col(LIMEG); //set color to green to indicate correct word;
			printf("%s\n", userGuess.c_str());
			col(LGREY);
			printf("You win in %i attempts!", attempts + 1);
			break;
		}

		//check if any of the letters are found in the string and check if indexes are equal
		for (int i{ 0 }; i < userGuess.length(); i++)
		{
			//for entire length of guess
			char ch1{ userGuess[i] }; //store element in ch1
			toupper(ch1); // make sure everything is uppercase


			for (int j{ 0 }; j < wordle.length(); j++)
			{
				auto it = std::find(wordle.begin(), wordle.end(), ch1);
				auto index{ std::distance(wordle.begin(), it) };
				if (it == wordle.end()) //if char not found continue
				{
					col(RED);
					printf("%c", ch1);
					break;
				}
				else if (userGuess[index] == wordle[index])
				{
					//we now have iterator to char in the answer so we can find index
					col(LIMEG);
					printf("%c", ch1);
					break;

				}
				else
				{
					col(YELLOW);
					printf("%c", ch1);
					break;
				}
			}
			
		}
		attempts++;
	}
	

	if (attempts >= 6)
	{
		printf("\nThe word is %s; Thanks for playing.", wordle.c_str());
	}
}


void toUpper(std::string& makeUpper)
{
	//algorithm to make entire string upper
	//probably could find one, but why not write it myself


	for (int i{ 0 }; i < makeUpper.length(); i++)
	{
		if(makeUpper[i] >= 'a' && makeUpper[i] <= 'z') //if the character is lowercase
		{
			makeUpper[i] -= 32; //add 32 to get uppercase character as per the ASCII code
		}
	}
}

std::string setWord()
{
	std::string word;
	do
	{
		printf("\nPlease enter the 5 letter word: ");
		std::cin >> word;
		if(word.length() != 5)
		{
			printf("\nYou entered a %i character word! The word must have 5 letters.", word.length());
		}
	} while (word.length() != 5);

	return word;
}
