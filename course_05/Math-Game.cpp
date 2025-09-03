#include <iostream>
#include <cmath>
#include <string>
#include <cstdlib>
using namespace std;
#define SIZE 50

enum enResult {
	right = 1, wrong = 2
};

enum enPassFail {
	pass = 1, fial = 2
};

enum enQuestionsLevel {
	easy = 1, medium = 2, hard = 3, mix_level = 4
};

enum enOperations {
	add = 1, div_operation = 2, mul = 3, sub = 4, mix_operation = 5
};

struct stRoundInfo {
	// The number of this question
	int round_number = 0;
	// Is the user answer right or not?
	enResult final_result;
	int number_one = 0;
	int number_two = 0;
	// The correct result
	int result = 0;
	enOperations operation;
	int user_answer = 0;
};

struct stGameInfo {
	// the program saves in this array the game questions
	stRoundInfo rounds[SIZE];
	// this is the number of questions the user chose
	int number_of_rounds = 0;
	enQuestionsLevel questions_level;
	enOperations operation;
	// the program uses this as an array size, it increments this variable after each question
	// and it sets it to zero when the user restarts the game
	int rounds_played = 0;
};

int ReadPositiveNum(string str) {
	int N;
	do {
		cout << str;
		cin >> N;
	} while (N <= 0);
	return N;
}

bool IsNumberInArray(int arr[], int size, int target_number) {
	for (int i = 0; i < size; i++)
		if (arr[i] == target_number)
			return true;

	return false;
}

enQuestionsLevel ReadQuestionsLevel() {
	int nums[4] = { 1,2,3,4 };
	int user_number = 0;
	do {
		cout << "Enter questions level [1] Easy, [2] Med, [3] Hard, [4] Mix :";
		cin >> user_number;
		// I don't know why I did this :)
		// I could put while( user_number < 1 || user_number > 4 )
	} while (!IsNumberInArray(nums, 4, user_number));

	return (enQuestionsLevel)user_number;
}

enOperations ReadOperation() {
	int nums[5] = { 1,2,3,4,5 };
	int user_number = 0;
	do {
		cout << "Enter operation type [1] Add, [2] Div, [3] Mul, [4] Sub, [5] Mix :";
		cin >> user_number;
	} while (!IsNumberInArray(nums, 5, user_number));

	return (enOperations)user_number;
}

void ResetScreen() {
	// clears everything on the screen
	system("cls");
	// turns the screen to black and white
	system("color 0F");
}

void ChangeScreenStyle(enResult result) {
	if (result == enResult::right) {
		// turns the screen to black and green
		system("color 0a");
	}
	else {
		// turns the screen to black and red
		system("color 0C");
		// produces a bell sound
		cout << "\a";
	}
}

string PrintTabs(int number) {
	string st = "";
	for (int i = 0; i < number; i++) st += "\t";
	return st;
}
string PrintBreakLine(int number) {
	string st = "";
	for (int i = 0; i < number; i++) st += "\n";
	return st;
}
// "From" and "To" numbers will be included
int RandomNumber(int From, int To)
{
	int randNum = rand() % (To - From + 1) + From;
	return randNum;
}

enOperations GetRandomOperation() {
	return (enOperations)RandomNumber(1, 4);
}
enQuestionsLevel GetRandomQuestionsLevel() {
	return (enQuestionsLevel)RandomNumber(1, 3);
}

void GetRandomNumberBasedOnLevel(enQuestionsLevel questions_level, stRoundInfo& round) {
	switch (questions_level)
	{
	case easy:
	{
		round.number_one = RandomNumber(1, 10);
		round.number_two = RandomNumber(1, 10);
		break;
	}
	case medium:
	{
		round.number_one = RandomNumber(11, 30);
		round.number_two = RandomNumber(11, 30);
		break;
	}
	case hard:
	{
		round.number_one = RandomNumber(31, 60);
		round.number_two = RandomNumber(31, 60);
		break;
	}
	case mix_level:
	{
		GetRandomNumberBasedOnLevel(GetRandomQuestionsLevel(), round);
		break;
	}
	default:
		exit(-1);
	}
}

void CalculateRoundResult(stRoundInfo& round) {
	switch (round.operation)
	{
	case add:
	{
		round.result = round.number_one + round.number_two;
		break;
	}
	case enOperations::div_operation:
	{
		round.result = round.number_one / round.number_two;
		break;
	}
	case mul:
	{
		round.result = round.number_one * round.number_two;
		break;
	};
	case sub:
	{
		round.result = round.number_one - round.number_two;
		break;
	}
	default:
		exit(-1);
	}
}

void SetOperationInRound(enOperations operation, stRoundInfo& round) {
	if (operation != enOperations::mix_operation) round.operation = operation;
	else round.operation = GetRandomOperation();
}

string GetOperationAsString(enOperations operation) {
	switch (operation)
	{
	case enOperations::add: return "+";
	case enOperations::div_operation: return "/";
	case enOperations::mul: return "*";
	case enOperations::sub: return "-";
	default: exit(-1);
	}
}
string GetQuestionLevelAsString(enQuestionsLevel question_level) {
	switch (question_level)
	{
	case enQuestionsLevel::easy: return "Easy";
	case enQuestionsLevel::medium: return "Meduim";
	case enQuestionsLevel::hard: return "Hard";
	case enQuestionsLevel::mix_level: return "Mix";
	default: exit(-1);
	}
}

void GetFinalResult(stRoundInfo& round) {
	if (round.result == round.user_answer) round.final_result = enResult::right;
	else round.final_result = enResult::wrong;
}

void AddElementToArray(stRoundInfo element, stRoundInfo arr[], int& size) {
	arr[size++] = element;
}

void ResetGameInfo(stGameInfo& game_info) {
	game_info.rounds_played = 0;
}

void ReadGameInfo(stGameInfo& game_info) {
	game_info.number_of_rounds = ReadPositiveNum("How many questions do you want to answer? ");
	game_info.operation = ReadOperation();
	game_info.questions_level = ReadQuestionsLevel();
}

void PrintRoundBody(stRoundInfo round, int current_round_number, int number_of_rounds) {
	cout << PrintBreakLine(2);
	cout << "Question [" << current_round_number << "/" << number_of_rounds << "]" << PrintBreakLine(2);
	cout << round.number_one << endl;
	cout << round.number_two << " " << GetOperationAsString(round.operation) << PrintBreakLine(2);
	cout << "-----------" << endl;
}

void PrintResultBody(enResult result, int right_answer) {
	if (result == enResult::right) {
		cout << "Right answer :)" << endl;
	}
	else {
		cout << "Wrong answer :(" << endl;
		cout << "The right answer is " << right_answer << endl;
	}
	ChangeScreenStyle(result);
}

void play_a_round(stRoundInfo& round, int current_round_number, stGameInfo game_info) {
	GetRandomNumberBasedOnLevel(game_info.questions_level, round);
	SetOperationInRound(game_info.operation, round);
	CalculateRoundResult(round);
	PrintRoundBody(round, current_round_number, game_info.number_of_rounds);
	cin >> round.user_answer;
	GetFinalResult(round);
	PrintResultBody(round.final_result, round.result);
}

void StartRounds(stGameInfo& game_info) {
	stRoundInfo aux_round;

	for (int i = 1; i <= game_info.number_of_rounds; i++) {
		play_a_round(aux_round, i, game_info);
		AddElementToArray(aux_round, game_info.rounds, game_info.rounds_played);
	}

}

int CountNumberOfWinningTimes(stRoundInfo arr[], int size) {
	int counter = 0;
	for (int i = 0; i < size; i++) {
		if (arr[i].final_result == enResult::right) counter++;
	}
	return counter;
}

enPassFail GetGameFinalResult(stGameInfo game_info, int number_of_winning_times) {
	if (number_of_winning_times >= (game_info.number_of_rounds - number_of_winning_times)) return enPassFail::pass;
	else return enPassFail::fial;
}

void ChangeScreenToFinalStyle(enPassFail pass_fial) {
	if (pass_fial == enPassFail::pass) ChangeScreenStyle(enResult::right);
	else ChangeScreenStyle(enResult::wrong);
}

void PrintGameResultsHeader(enPassFail pass_fial) {
	cout << "-------------------------------------" << PrintBreakLine(2);
	if (pass_fial == enPassFail::pass) {
		cout << "           Y o u   P a s s           " << PrintBreakLine(2);
	}
	else
		cout << "           Y o u   F a i l           " << PrintBreakLine(2);
	cout << "-------------------------------------" << PrintBreakLine(2);
}

void PrintGameResults(stGameInfo game_info) {
	int number_of_winning_times = CountNumberOfWinningTimes(game_info.rounds, game_info.rounds_played);

	enPassFail game_final_result = GetGameFinalResult(game_info, number_of_winning_times);

	ChangeScreenToFinalStyle(game_final_result);

	PrintGameResultsHeader(game_final_result);


	cout << "Number of questions : " << game_info.number_of_rounds << endl;
	cout << "Questions level     : " << GetQuestionLevelAsString(game_info.questions_level) << endl;
	cout << "Number of right answers : " << number_of_winning_times << endl;
	cout << "Number of wrong answers : " << game_info.number_of_rounds - number_of_winning_times << endl;
	cout << "-------------------------------------" << PrintBreakLine(2);
}

void StartGame() {
	char repeat_game = 'n';
	stGameInfo game_info;

	int number_of_interation = 0;
	do {
		ResetScreen();

		ResetGameInfo(game_info);

		ReadGameInfo(game_info);

		StartRounds(game_info);

		PrintGameResults(game_info);

		cout << "Do you want to play again [Y/N]: ";
		cin >> repeat_game;
	} while (repeat_game == 'y' || repeat_game == 'Y');
}


int main()
{
	// this function allow rand() to return a new number each time
	srand((unsigned)time(NULL));

	StartGame();

	return 0;
}