#include <iostream>
#include <cstdlib>
#include <string>
/*
*	c++ without classes.
*	add W/L table
*	make .cfg file, for save W/L and extras and rand seed
*	make .log file, for save difficulty W/L-tryes, use cheat(show magic)
*	make generator menu extras
*/
using namespace std;

void play(unsigned* magic, unsigned* attempts);
void extra(unsigned* range, unsigned* magic, unsigned* attempts);

int main() {
	unsigned option = 0;
	unsigned range = 10;
	unsigned attempts = range / 3;
	unsigned magic = 0;
	srand(time(NULL));
	magic = rand() % range + 1;//диапазон от 1 до range
	//cout << magic;
	cout << "Hello! Do you wanna play this game? Cool!\n\n";
	do
	{
		cout << "-----\n1.Play!\n2.Extra\n3.Exit!\n-----";
		do
		{
			cout << "\nMake a choice:", cin >> option;
		} while (option < 1 || option > 3);
		switch (option)
		{
		case 1: play(&magic, &attempts);
			break;
		case 2: extra(&range, &magic, &attempts);
			break;
		case 3: cout << "\nBye bye!";
			break;
		default:
			break;
		}
	} while (option != 3);

	return 0;
}

void extra(unsigned* range, unsigned* magic, unsigned* attempts) {
	int option = 0;
	do
	{
		system("cls");
		cout << "-----\nCurrent range: 1-" << *range << "\nNumber of attempts: " << *attempts << "\nCurrent magic number:[SECRET]\n\n1.Set range\n2.Set number of attempts\n3.Generate new magic number\n4.Show magic number\n5.Back\n-----\n\n";
		do
		{
			cout << "\nYour choice: ", cin >> option;
		} while (option < 1 || option > 5);
		switch (option)
		{
		case 1:
			system("cls");
			cout << "\nCurrent range 1-" << *range;
			do
			{
				cout << "\nInput range 1-", cin >> *range;
			} while (*range < 1);
			*magic = rand() % *range + 1;
			cout << "\nThe number was generated in range 1-" << *range << "\n";
			system("pause");
			break;
		case 2:
			system("cls");
			cout << "\nCurrent number of attemps: " << *attempts;
			cout << "\nInput number of attemps: ", cin >> *attempts;
			break;
		case 3:
			system("cls");
			*magic = rand() % *range + 1;
			cout << "!!!!!The number was generated!!!!!\n";
			system("pause");
			break;
		case 4:
			system("cls");
			cout << "Magic number is: " << *magic << "\n";
			system("pause");
			break;
		case 5:
			system("cls");
			cout << "\nBack to main menu!\n\n";
			break;
		default:
			cout << "Error!";
			break;
		}
	} while (option != 5);

}

void play(unsigned* magic, unsigned* attempts) {
	unsigned numb = 0;
	unsigned tryes = 0;
	system("cls");
	cout << "\nLet's go!\nYou have " << *attempts << " attempts\n";
	do
	{
		cout << "\n\nMagic number is: ", cin >> numb;
		if (numb == *magic)
		{
			system("cls");
			cout << "\nWIN!!!!!!!!!\n\n";
			return;
		}
		else {
			if (numb < *magic) cout << "few...\n\n";
			else cout << "Too much\n\n";
		}
		cout << "You have attempts: " << *attempts - ++tryes;
	} while (tryes < *attempts);
	system("cls");
	cout << "\n\nLoser....\n\n";
}