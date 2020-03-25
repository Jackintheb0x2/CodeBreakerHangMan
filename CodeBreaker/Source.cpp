#include <iostream>
#include <ctime>
#include <string>
#include <vector>

using namespace std;

int main()
{
	srand(static_cast<unsigned int>(time(nullptr)));
	string name;
	// Display Title of the program to the user
	cout << "\n\n\t\tWELCOME TO CODE BREAKER\n\n";
	// Ask the recruit to log in using their name
	cout << "Enter your code name :>";
	// Hold the recruit's name in a var, and address them by it throughout the simulation.
	getline(cin, name);
	// Display an overview of what Keywords II is to the recruit 
	cout << "\n\nCode Breaker is a simulation to maintain your skill and intellect by solving different codes\n";
	// Display directions to the recruit on how to use Keywords
	cout << "\nDIRECTIONS:";
	cout << "\nEnter different characters on your keyword to figure out the word given to you. The objective is to figure out the word in teh least number of guesses";
	cout << "\nAre you ready?\n";
	system("pause");
	// Create a collection of 10 words you had written down manually
	vector<string> wordBank;
	wordBank.push_back("Agent");
	wordBank.push_back("Burned");
	wordBank.push_back("Cipher");
	wordBank.push_back("Code");
	wordBank.push_back("Compromised");
	wordBank.push_back("Cryptology");
	wordBank.push_back("Double Agent");
	wordBank.push_back("Enigma");
	wordBank.push_back("Escort");
	wordBank.push_back("Infiltration");
	
	// Create an int var to count the number of simulations being run starting at 1
	int numberOfSimulation = 0;
	
	int currentWord = 0;
	int currentWordSize;

	do
	{
		// Display the simulation # is starting to the recruit. 
		++numberOfSimulation;
		
		// Pick new 3 random words from your collection as the secret code word the recruit has to guess. 
		vector<string> activeWord;
		for(int i = 0; i < 3; i++)
		{
			activeWord.push_back(wordBank[(rand() % 11) + 1]);
		}

		// While recruit hasn’t made too many incorrect guesses and hasn’t guessed the secret word
		do
		{
			
			//this gets the size of the first word which will increase after the recruit guesses it correctly
			currentWordSize = activeWord[currentWord].size();
			int guesses = currentWordSize * 2;
			do
			{
				for(int i = 0; i < currentWordSize; i++)
				{
					cout << "_ ";
				}
				system("pause");
			} while (guesses > 0);//will keep looping until the user gets the correct word or misses too many times
		} while (currentWord < 3);//this will keep looping until all three words have been gone through
		//     Tell recruit how many incorrect guesses he or she has left

		//     Show recruit the letters he or she has guessed

		//     Show player how much of the secret word he or she has guessed

		//     Get recruit's next guess

		//     While recruit has entered a letter that he or she has already guessed

		//          Get recruit ’s guess

		//     Add the new guess to the group of used letters

		//     If the guess is in the secret word

		//          Tell the recruit the guess is correct

		//          Update the word guessed so far with the new letter

		//     Otherwise

		//          Tell the recruit the guess is incorrect

		//          Increment the number of incorrect guesses the recruit has made

		// If the recruit has made too many incorrect guesses

		//     Tell the recruit that he or she has failed the Keywords II course.

		// Otherwise

		//     Congratulate the recruit on guessing the secret words

		// Ask the recruit if they would like to run the simulation again

		// If the recruit wants to run the simulation again

		//     Increment the number of simulations ran counter

		//     Move program execution back up to // Display the simulation # is starting to the recruit. 

		// Otherwise 

		//     Display End of Simulations to the recruit

		//     Pause the Simulation with press any key to continue
	} while (numberOfSimulation < 3);

	return 0;
}