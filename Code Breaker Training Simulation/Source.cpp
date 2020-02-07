#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

bool playAgain = true;
bool wordCleared;
string answer;
string lastChoice[4] = { "","","" };

int main()
{
	while (playAgain == true) {
		enum fields { WORD, HINT, NUM_FIELDS };
		const int NUM_WORDS = 5;
		const string WORDS[NUM_WORDS][NUM_FIELDS] =
		{
			{"table","I'll put the food on the what?"},
			{"phone","Call me."},
			{"strength","Body builders have a great amount of what?"},
			{"persistent","Keep at it"},
			{"jumble","It's what the game is all about"}
		};
		for (int i = 0; i < 3; i++)
		{
			wordCleared = false;
			srand(static_cast<unsigned int>(time(0)));
			int choice = (rand() % NUM_WORDS);
			string theWord = WORDS[choice][WORD]; // word to guess
			string theHint = WORDS[choice][HINT]; // hint for word

			//prevents it from using the same world as last time
			//checks if the word as used last time
			while (wordCleared==false)
			{
				if (theWord == lastChoice[0] || theWord == lastChoice[1] || theWord == lastChoice[2])
				{
					wordCleared = false;
				}
				else
				{
					wordCleared = true;
				}
			}
			
			string jumble = theWord; //jumbled version of word
			int length = jumble.size();
			for (int i = 0; i < length; i++)
			{
				int index1 = (rand() % length);
				int index2 = (rand() % length);
				char temp = jumble[index1];
				jumble[index1] = jumble[index2];
				jumble[index2] = temp;
			}
			cout << "\t\t\tWelcome to Word Jumble!\n\n";
			cout << "Unscramble the letters to make a word.\n";
			cout << "Enter 'hint' for a hint.\n";
			cout << "Enter 'quit' to quit the game.\n\n";


			cout << "The Jumble is: " << jumble;

			string guess;
			cout << "\n\nYour guess: ";
			cin >> guess;

			while ((guess != theWord) && guess != "quit")
			{
				if (guess == "hint")
				{
					cout << theHint;
				}
				else
				{
					cout << "Sorry, that's not it.";
				}

				cout << "\n\nYour guess: ";
				cin >> guess;
			}

			if (guess == theWord)
			{
				cout << "\nThat's it! You guessed it!\n";
			}
			if (guess == "quit") 
			{
				return 0;
			}
			lastChoice[i] = theWord;
		}
		
		cout << "\nWanna play again? 'Yes' or 'No'?\n";
		cin >> answer;
		
		if (answer == "Yes" || answer == "yes") 
		{
			playAgain = true;
		}
		else
		{
			playAgain = false;
		}
	}
	cout << "\nThanks for playing.\n";

	return 0;
}