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
	wordBank.push_back("agent");
	wordBank.push_back("burned");
	wordBank.push_back("cipher");
	wordBank.push_back("code");
	wordBank.push_back("compromised");
	wordBank.push_back("cryptology");
	wordBank.push_back("espionage");
	wordBank.push_back("enigma");
	wordBank.push_back("escort");
	wordBank.push_back("infiltration");
	
	// Create an int var to count the number of simulations being run starting at 1
	int numberOfSimulation = 0;
	

	do
	{
		char answer;
		int currentWord = 0;
		// Display the simulation # is starting to the recruit.
		//Increment the number of simulations ran counter
		++numberOfSimulation;
		// Pick new 3 random words from your collection as the secret code word the recruit has to guess. 
		vector<string> activeWords;
		for(int i = 0; i < 3; i++)
		{
			int pos = rand() % 9 + 1;
			activeWords.push_back(wordBank.at(pos));
		}

		// While recruit hasn’t made too many incorrect guesses and hasn’t guessed the secret word
		while (currentWord < 3)
		{
			
			//this gets the size of the first word which will increase after the recruit guesses it correctly
			int currentWordSize = activeWords.at(currentWord).size();
			int guesses = currentWordSize * 2;

			//this is the user array where we will check this array with the active word array
			vector<char> userGuess;
			vector<char> activeLetters(activeWords.at(currentWord).begin(), activeWords.at(currentWord).end());
			vector<char> guessesMade;
			//this sets up the vector to start if only blank spaces.
			for(int i = 0; i < currentWordSize; i++)
			{
				userGuess.push_back('_');
			}
			do
			{
				//this displays the known and unknown characters in the current word
				// Show player how much of the secret word he or she has guessed
				// Update the word guessed so far with the new letter
				for(unsigned int i = 0; i < userGuess.size(); i++)
				{
					cout << userGuess.at(i);
					cout << " ";
				}
				cout << "\n\n";

				//gets the users guess
				char letter;
				//     Get recruit's next guess
				cout << "Enter your guess :>";
				cin >> letter;

				
				//     While recruit has entered a letter that he or she has already guessed
				if(find(guessesMade.begin(), guessesMade.end(), letter) != guessesMade.end())
				{
					
					cout << "\nUh oh! looks like you've already guessed this word! why don't you pick a new one.\n";
				}else
				{
					//checks to see if the guess is inside the current word
					if (find(activeLetters.begin(), activeLetters.end(), letter) != activeLetters.end())
					{
						//goes through every element and replaces the character to the correct place
						for (unsigned int i = 0; i < activeLetters.size(); i++)
						{
							//checks the letter to see if it is inside the current word
							// If the guess is in the secret word
							if (activeLetters.at(i) == letter)
							{
								//found a correct letter
								userGuess.at(i) = letter;
							}
						}
						
						//          Tell the recruit the guess is correct
						cout << "\nYou got the correct letter!\n";
					}
					else
					{
						//wrong guess
						//Increment the number of incorrect guesses the recruit has made
						guesses--;
						// Tell the recruit the guess is incorrect
						//  Tell recruit how many incorrect guesses he or she has left
						cout << "\nOops! that is not the correct letter!\nYou have " << guesses << " guesses left.\n";
					}

					//checks to see if the word is finished
					if (activeLetters == userGuess)
					{
						//start the next word
						//Congratulate the recruit on guessing the secret words
						cout << "\nGuess completed\n";
						for (unsigned int i = 0; i < userGuess.size(); i++)
						{
							cout << userGuess.at(i);
							cout << " ";
						}
						cout << "\n\n";
						break;
					}
				}
				//     Add the new guess to the group of used letters
				guessesMade.push_back(letter);
				
			// If the recruit has made too many incorrect guesses
			} while (guesses > 0);//will keep looping until the user gets the correct word or misses too many times

			if(guesses > 0)
			{
				currentWord++;
				
			}else
			{
				//Tell the recruit that he or she has failed the Keywords II course.
				cout << "\nYou ran out of guess and you have failed this course!\n";
				exit(0);
			}
			
			
		} //this will keep looping until all three words have been gone through
		

		do
		{
			// Ask the recruit if they would like to run the simulation again
			cout << "\nWould you like to run the simulation again? Y/N :>";
			cin >> answer;

			// If the recruit does not want to run the simulation again
			if (answer == 'N')
			{
				exit(0);
			}
		} while (answer != 'N' && answer != 'Y');

		//     Display End of Simulations to the recruit
		cout << "\nEnd of Simulation!\n";
		//     Pause the Simulation with press any key to continue
		system("pause");
		//Move program execution back up to // Display the simulation # is starting to the recruit.
	} while (numberOfSimulation < 4);

	return 0;
}