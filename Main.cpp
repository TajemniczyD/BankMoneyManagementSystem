#include <iostream>
#include <string>
#include <Windows.h>

int choice;

void mainM();

class Banking
{
private:
	std::string firstName;
	std::string firstNameC;
	std::string lastName;
	std::string lastNameC;
	int id_num;
	int id_numC;
	int money;
	int moneyC;
public:
	Banking()
	{

	}

	void mainB()
	{
		system("cls");
		std::cout << "|=-=-=| Banking System |=-=-=|" << std::endl;
		std::cout << "1. Create account" << std::endl;
		std::cout << "2. Login to account" << std::endl;
		std::cout << "3. Exit" << std::endl;

		std::cin >> choice;

		switch (choice)
		{
		case 1:
			createAccount();
			break;
		case 2:
			login();
			break;
		case 3:
			mainM();
			break;
		default:
			std::cout << "ERROR::UNKNOWN::COMMAND::TRY::AGAIN" << std::endl;
			Sleep(1200);
			mainB();
			break;
		}
	}

	void createAccount()
	{
		system("cls");

		std::cout << "|-=-= Creating Account =-=-|" << std::endl;
		std::cout << "Enter Your First Name: " << std::endl;
		std::cin >> firstName;
		std::cout << "Enter Your Second Name: " << std::endl;
		std::cin >> lastName;
		std::cout << "Enter Identifier Number: " << std::endl;
		std::cin >> id_num;

		std::cout << "Processing..." << std::endl;
		Sleep(2300);

		std::cout << "Created account succesfully!" << std::endl;

		money = 1000;

		Sleep(1000);
		mainB();
	}

	void login()
	{
		system("cls");
		std::cout << "|-=-= Login to Account =-=-|" << std::endl;
		std::cout << "Enter Your First Name: " << std::endl;
		std::cin >> firstNameC;

		std::cout << "Enter Your Second Name: " << std::endl;
		std::cin >> lastNameC;

		std::cout << "Enter Identifier Number: " << std::endl;
		std::cin >> id_numC;

		std::cout << "Processing..." << std::endl;
		Sleep(700);

		if (firstNameC != firstName || lastNameC != lastName || id_numC != id_num)
		{
			std::cout << "ERROR::UNKOWN::ACCOUNT" << std::endl;
			Sleep(1200);
			mainB();
		}
		else
		{
			PDMC();
		}
	}

	void PDMC()
	{
		system("cls");
		std::cout << "Logged in succesfully!" << std::endl;
		std::cout << "You have " << money << "$" << std::endl;
		std::cout << "1. Payout money" << std::endl;
		std::cout << "2. Deposit money" << std::endl;
		std::cout << "3. Exit" << std::endl;

		std::cin >> choice;

		switch (choice)
		{
		case 1:
			payoutMoney();
			break;
		case 2:
			depositMoney();
			break;
		case 3:
			mainB();
			break;
		default:
			login();
			break;
		}
	}

	void payoutMoney()
	{
		int val;

		std::cout << "|-| Payout Money |-|" << std::endl;

		std::cout << "How much money you want to payout?" << std::endl;
		std::cin >> val;

		if (val <= money)
		{
			money -= val;
			std::cout << "You paid out " << val << " $" << std::endl;
			std::cout << "You have " << money << "$ left." << std::endl;
		}
		else
		{
			std::cout << "You don't have enough money" << std::endl;
		}

		Sleep(700);
		PDMC();
	}

	void depositMoney()
	{
		int val;

		std::cout << "|+| Deposit Money |+|" << std::endl;

		std::cout << "How much money you want to deposit into your bank account?" << std::endl;
		std::cin >> val;

		money += val;
		std::cout << "You have deposited " << val << "$" << std::endl;
		std::cout << "You have now " << money << "$ to spend." << std::endl;

		Sleep(1200);

		PDMC();
	}

	~Banking()
	{

	}
};

std::unique_ptr<Banking> BMS(new Banking());

void mainM()
{
	system("cls");
	std::cout << "-=-=-=-= Welcome to Main Menu =-=-=-=-" << std::endl;
	std::cout << "1. Banking System" << std::endl;
	std::cout << "2. Exit" << std::endl;
	
	std::cin >> choice;

	switch (choice)
	{
	case 1:
		BMS->mainB();
		break;
	case 2:
		exit(0);
		break;
	default:
		std::cout << "ERROR::UNKNOWN::COMMAND::TRY::AGAIN" << std::endl;
		Sleep(1200);
		mainM();
		break;
	}
}

int main()
{
	mainM();

	return 0;
}