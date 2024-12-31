#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>


//user input function for win conditions
std::string userInput()
{
	std::cout << "Rock, Paper, or Scissors: ";
	std::string userInput;
	std::cin >> userInput;
	return userInput;
}

/* Generates a pseudo random number for compChoice()
It honestly kinda sucks, sometimes the computer will
get rock/paper/scissors 3 times in a row*/
int randNumGen()
{
	long long int elapsedSeconds = time(0);
	srand(elapsedSeconds);
	int randNum{ rand() % 11 };
	return randNum;
}
//Uses randomly generated number from randNumGen()
//to select rock, paper or scissors
std::string compChoice()
{
	int randNum{ randNumGen() };

	if (randNum <= 4)
	{
		return "Scissors";
	}
	if (4 < randNum && randNum <= 6)
	{
		return "Rock";
	}
	if (6 < randNum && randNum <= 10)
	{
		return "Paper";
	}
	return "";
}

/* These next three functions take the player choice, checks to see what it is
equal to, and returns the respective value depending on players choice.*/
std::string rockConditions(std::string computerChoice, std::string playerChoice)
{
	if (playerChoice == "rock")
	{
		std::cout << "I chose " << computerChoice << '\n';
		std::cout << "Tie!\n";
		return "tie";
	}
	if (playerChoice == "scissors")
	{
		std::cout << "I chose " << computerChoice << '\n';
		std::cout << "Haha! I got you\n";
		return "cWin";
	}
	if (playerChoice == "paper")
	{
		std::cout << "I chose " << computerChoice << '\n';
		std::cout << "Lucky.\n";
		return "pWin";
	}
	return "";
}

std::string paperConditions(std::string computerChoice, std::string playerChoice)
{
	if (playerChoice == "paper")
	{
		std::cout << "I chose " << computerChoice << '\n';
		std::cout << "Tie!\n";
		return "tie";
	}
	if (playerChoice == "rock")
	{
		std::cout << "I chose " << computerChoice << '\n';
		std::cout << "Haha! I got you\n";
		return "cWin";
	}
	if (playerChoice == "scissors")
	{
		std::cout << "I chose " << computerChoice << '\n';
		std::cout << "Lucky.\n";
		return "pWin";
	}
	return "";
}

std::string scissorConditions(std::string computerChoice, std::string playerChoice)
{
	if (playerChoice == "scissors")
	{
		std::cout << "I chose " << computerChoice << '\n';
		std::cout << "Tie!\n";
		return "tie";
	}
	if (playerChoice == "paper")
	{
		std::cout << "I chose " << computerChoice << '\n';
		std::cout << "Haha! I got you\n";
		return "cWin";
	}
	if (playerChoice == "rock")
	{
		std::cout << "I chose " << computerChoice << '\n';
		std::cout << "Lucky.\n";
		return "pWin";
	}
	return "";
}

/* Gets players and computers choice of rock, paper or scissors,
depending on the computers choice, it will call the respective function
and check the return value and increment the win count depending on who won.*/
int winConditions()
{
	//win counts to be used
	int compWinCount{0};
	int playerWinCount{0};
	
	while (compWinCount != 3 && playerWinCount != 3)
	{
		std::string playerChoice{ userInput() };
		std::string computerChoice{ compChoice() }; 
		//Rock win/lose conditions
		if (computerChoice == "Rock")
		{
			std::string rockReturn{ rockConditions(computerChoice, playerChoice) };
			if (rockReturn == "tie")
			{
				std::cout << "SEC's wins: " << compWinCount << '\n' 
						  << "Player wins: " << playerWinCount << '\n';
			}
			if (rockReturn == "cWin")
			{
				++compWinCount;
				std::cout << "SEC's wins: " << compWinCount << '\n'
						  << "Player wins: " << playerWinCount << '\n';
			}
			if (rockReturn == "pWin")
			{
				++playerWinCount;
				std::cout << "SEC's wins: " << compWinCount << '\n' 
						  << "Player wins: " << playerWinCount << '\n';
			}
		}
		//Paper win/lose conditions
		if (computerChoice == "Paper")
		{
			std::string paperReturn{ paperConditions(computerChoice, playerChoice) };
			if (paperReturn == "tie")
			{
				std::cout << "SEC's wins: " << compWinCount << '\n' 
						  << "Player wins: " << playerWinCount << '\n';
			}
			if (paperReturn == "cWin")
			{
				++compWinCount;
				std::cout << "SEC's wins: " << compWinCount << '\n' 
						  << "Player wins: " << playerWinCount << '\n';
			}
			if (paperReturn == "pWin")
			{
				++playerWinCount;
				std::cout << "SEC's wins: " << compWinCount << '\n' 
						  << "Player wins: " << playerWinCount << '\n';
			}
		}
		//scissors win/lose conditions
		if (computerChoice == "Scissors")
		{
			std::string scissorReturn{ scissorConditions(computerChoice, playerChoice) };
			if (scissorReturn == "tie")
			{
				std::cout << "SEC's wins: " << compWinCount << '\n' 
						  << "Player wins: " << playerWinCount << '\n';
			}
			if (scissorReturn == "cWin")
			{
				++compWinCount;
				std::cout << "SEC's wins: " << compWinCount << '\n' 
						  << "Player wins: " << playerWinCount << '\n';
			}
			if (scissorReturn == "pWin")
			{
				++playerWinCount;
				std::cout << "SEC's wins: " << compWinCount << '\n' 
						  << "Player wins: " << playerWinCount << '\n';
			}
		}
	}
	if (compWinCount == 3)
	{
		std::cout << "You lose!\n";
	}
	if (playerWinCount == 3)
	{
		std::cout << "You were just lucky...\n";
	}
	return 0;	
}

//Just a function to hold some text
int playerInput()
{
	std::cout << "Now we can get to business!\n"
				 "We'll play for three rounds, if I win two, you lose. If you win two you win.\n"
				 "Now I shouldn't have to explain the rest... you know how to play\n";

	winConditions();
	return 0;
}
//Only exists to help simplify the main function
char userYorN()
{
	char userInput{};
	std::cin >> userInput;
	//debug std::cout << userInput;
	return userInput;
}

//Asking if the player wants to play, you don't really have a choice actually.
int main()
{
	std::cout << "Hello! Welcome to SEC's super fun Rock, Paper, Scissors game!\n"
				 "Im pretty good at this game so if you're feeling lucky... Try me!\n"
				 "Wanna play me?(Y)(N): ";

		char yOrN{ userYorN() };

		int count{0};
		//I wasn't sure how to make all input lowercase so I wouldn't have to worry
		//about this
		while (yOrN != 'y' && yOrN != 'Y')
		{
			count++;
			std::cout << "C'mon, just think about it. It'll be fun\n";
			std::string yOrN{ userYorN() };
			if (count == 1)
			{
				std::cout << "You know you wanna play...\n";
				std::string yOrN{ userYorN() };
			}
			if (count == 1)
			{
				std::cout << "Okay, you think you're funny... You're playing anyways.\n";
				playerInput();
				break;
			}
		}
		if (yOrN == 'y' && 'Y')
			playerInput();

		return 0;
}