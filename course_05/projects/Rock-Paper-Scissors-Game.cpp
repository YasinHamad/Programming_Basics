#include <iostream>
#include <cmath>
#include <string>
#include <cstdlib>
using namespace std;
#define SIZE 50

enum enGameTools {
	Stone = 1, Paper = 2, Scissors = 3
};

enum enWinner {
	User = 1, Bot = 2, NoWinner = 3
};

struct stRoundInfo {
	enGameTools user_choice;
	enGameTools bot_choice;
	enWinner winner;
};

enGameTools GetGameChoice(int aux_num) {
	switch (aux_num)
	{
	case 1: {
		return enGameTools::Stone;
	}
	case 2: {
		return enGameTools::Paper;
	}
	case 3: {
		return enGameTools::Scissors;
	}
	default:
		exit(-1);
	}
}

string GetChoiceAsString(enGameTools choice) {
	switch (choice)
	{
	case enGameTools::Stone:
		return "Stone";
	case enGameTools::Paper:
		return "Paper";
	case enGameTools::Scissors:
		return "Scissors";
	default:
		exit(-1);
	}
}
string GetWinnerAsString(enWinner winner) {
	string arr[3] = { "User", "Bot", "NoWinner" };
	return arr[winner - 1];
}

void ReadUserChoice(enGameTools& user_choice) {
	int aux_num = 0;
	do {
		cout << "Your choice: [1]:Stone, [2]:Paper, [3]:Scissors ? ";
		cin >> aux_num;
	} while (aux_num != 1 && aux_num != 2 && aux_num != 3);

	user_choice = GetGameChoice(aux_num);
}

enWinner GetWinner(int user_won_times, int bot_won_times) {
	if (user_won_times == bot_won_times) return enWinner::NoWinner;
	return user_won_times > bot_won_times ? enWinner::User : enWinner::Bot;
}

int RandomNumber(int From, int To)
{
	int randNum = rand() % (To - From + 1) + From;
	return randNum;
}

enGameTools GenerateBotChoice() {
	int aux_num = RandomNumber(1, 3);
	return GetGameChoice(aux_num);
}

enWinner GetRoundResult(enGameTools user_choice, enGameTools bot_choice) {
	if (user_choice == bot_choice) return enWinner::NoWinner;
	else if (
		(user_choice == enGameTools::Paper && bot_choice == enGameTools::Stone) ||
		(user_choice == enGameTools::Stone && bot_choice == enGameTools::Scissors) ||
		(user_choice == enGameTools::Scissors && bot_choice == enGameTools::Paper)
		) return enWinner::User;
	else return enWinner::Bot;
}

void CreateARound(enGameTools user_choice, stRoundInfo& aux_round) {
	aux_round.user_choice = user_choice;
	aux_round.bot_choice = GenerateBotChoice();
	aux_round.winner = GetRoundResult(aux_round.user_choice, aux_round.bot_choice);
}

void AddElementToArray(stRoundInfo element, stRoundInfo arr[], int& size) {
	arr[size++] = element;
}

void ChangeScreenColor(enWinner winner) {
	switch (winner)
	{
	case enWinner::User: {
		system("color 0a");
		return;
	}
	case enWinner::Bot: {
		system("color 0C");
		cout << "\a";
		return;
	}
	case enWinner::NoWinner: {
		system("color 06");
		return;
	}
	default:
		exit(-1);
	}
}

int CountPlayerTries(enWinner player, stRoundInfo arr[], int draw_times) {
	int counter = 0;
	for (int i = 0; i < draw_times; i++)
		if (arr[i].winner == player)
			counter++;
	return counter;
}

void PrintRoundResults(int round_number, stRoundInfo round) {
	ChangeScreenColor(round.winner);
	cout << "\n--------------------Round [" << round_number << "]--------------------\n" << endl;
	cout << "User choice :\t" << GetChoiceAsString(round.user_choice) << endl;
	cout << "Bot choice :\t" << GetChoiceAsString(round.bot_choice) << endl;
	cout << "Round Winner :\t" << GetWinnerAsString(round.winner) << endl;
	cout << "\n-------------------------------------------------\n" << endl;
}

void SartRounds(int rounds_number, stRoundInfo game_history[], int& draw_times) {
	enGameTools user_choice = enGameTools::Paper;
	stRoundInfo aux_round;

	for (int i = 0; i < rounds_number; i++) {
		cout << "\nRound [" << i + 1 << "] begins:\n" << endl;

		ReadUserChoice(user_choice);

		CreateARound(user_choice, aux_round);

		PrintRoundResults(i + 1, aux_round);

		AddElementToArray(aux_round, game_history, draw_times);
	}
}

float ReadNumInRange(string str, float from, float to) {
	float N;
	do {
		cout << str;
		cin >> N;
	} while (N < from || N > to);

	return N;
}

void PrintGameResults(stRoundInfo arr[], int draw_times, int rounds_number) {
	cout << "\t\t------------------------------------------------\n\n";
	cout << "\t\t          + + + G a m e  O v e r + + +";
	cout << "\n\n\t\t------------------------------------------------";
	cout << "\n\n\t\t----------------[ Game Results ]----------------\n\n";


	cout << "\t\tGame rounds :\t" << rounds_number << endl;
	int user_won_times = CountPlayerTries(enWinner::User, arr, draw_times);
	int bot_won_times = CountPlayerTries(enWinner::Bot, arr, draw_times);
	cout << "\t\tUser won times:\t" << user_won_times << endl;
	cout << "\t\tBot won times:\t" << bot_won_times << endl;
	enWinner winner = GetWinner(user_won_times, bot_won_times);
	cout << "\t\tFinal winner:\t" << GetWinnerAsString(winner) << endl;

	cout << "\n\n\t\t------------------------------------------------\n\n";
	ChangeScreenColor(winner);
}

void StartGame() {
	char start_again = 'n';
	int rounds_number = 0;
	stRoundInfo game_history[SIZE];
	int draw_times = 0;

	do {
		if (start_again == 'y' || start_again == 'Y') {
			system("cls");
			system("color 0F");
		}
		rounds_number = ReadNumInRange("How many rounds do you want to play? [1-10] : ", 1, 10);

		SartRounds(rounds_number, game_history, draw_times);

		PrintGameResults(game_history, draw_times, rounds_number);

		cout << "\t\tDo you want to play agian? [Y/N] : ";
		cin >> start_again;
	} while (start_again == 'y' || start_again == 'Y');
}




int main()
{
	// this function allow rand() to return a new number each time
	srand((unsigned)time(NULL));

	StartGame();

	return 0;
}