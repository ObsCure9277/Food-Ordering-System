#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <conio.h>
#include <cctype>
#include <vector>
#include <set>
#include <random>
#include <limits>

#define serviceChaarges 0.1
#define packagingCharges 2
#define MAX_LINES 1000
using namespace std;
double totalPayment, beforeTotal, balance;
int lines = 0, positionPointsGlobal, membershipPoints, position = 0, optionView, selectionDITA, positionBalanceGlobal, positionofMembershipStatusGlobal, backToPayment;
bool invalidId = false;
string information[MAX_LINES], customerId, tOrC, optionExit = "1", membershipStatus, optionYOrN, balanceString, nameSearch, memberId, stringMembershipPoints, name, memberName, directoryChoice, pass;
void userPayment();
string StoreId(string customerUsername, string pass);
void memberStatus(string customerUsername, string pass);
void calculationPoints(string optionYOrN);
void memberMsg();
void storeMembershipPoints(string customerUsername, string pass);
void storeBalance(string customerUsername, string pass);
void pointsAndBalance();
void memberStatus(string customerUsername, string pass);
void storring();
void writeToFile();
void OandSfile();

// Function to register a new user
void registerUser(string username, string password, string contactNum, string customerID, string topUp, int membershipPoints, string membershipStatus)
{
	ofstream file("user.txt", ios_base::app); // Open the file in append mode
	if (file.is_open())
	{
		file << username << endl;
		file << contactNum << endl;
		file << "ABC" << customerID << endl;
		file << topUp << endl;
		file << membershipPoints << endl;
		file << password << endl;
		file << membershipStatus << endl;
		file.close();
	}
	else
	{
		cerr << "Error opening the file for registration." << endl;
	}

}

// Function to check if a user exists and the password is correct
bool loginUser(string username, string password)

{
	OandSfile();
	int correct = 0;
	for (int i = 0; i < lines; i++) {
		if (information[i] == username && information[i + 5] == password)
		{
			correct = 1;
			break;
		}
	}

	if (correct == 1) {
		pass = password;
		name = username;
		return true;
	}
	else
		return false;

	// User does not exist or password is incorrect
}

// Function to get only alphabet input
bool notContainAlphabet(string& input) {
	for (char c : input) {
		if (isalpha(c)) {
			return false; // Non-alphabetic character found
		}
	}


	return true; // All characters are alphabetic
}

// Function to get only digit input
bool containsDigits(string& str)
{
	for (char ch : str)
	{
		if (isdigit(ch))
		{
			return true; // If any digit is found, return true 
		}
	}
	return false; // No digits found
}


// Function to generate a 6-digit number
string generate6DigitNumber(set<string>& generatedNumbers)
{
	static random_device rd;
	static mt19937 gen(rd());
	static uniform_int_distribution<> dist(000001, 999999);

	string membershipCardNum;
	do
	{
		membershipCardNum = to_string(dist(gen));
	} while (generatedNumbers.find(membershipCardNum) != generatedNumbers.end());

	generatedNumbers.insert(membershipCardNum);
	return membershipCardNum;
}

void selectionPage()
{
	system("cls");
	cout << "\n\n";
	cout << "****   ***** ****   *****   **** ***** ***** ****  *   *" << endl;
	cout << "*  **    *   *   *  *      *       *   *   * *   *  * * " << endl;
	cout << "*   **   *   ****   *****  *       *   *   * ****    *  " << endl;
	cout << "*  **    *   *   *  *      *       *   *   * *   *   *  " << endl;
	cout << "****   ***** *   *  *****   ****   *   ***** *   *   *  " << endl;
	cout << "------------------------------------------------------------------------\n";
	cout << "Choose Option:\n";
	cout << "------------------------------------------------------------------------\n\n";
	cout << "1)  Food Menu                         \n\n";
	cout << "2)  Top Up                            \n\n";
	cout << "3)  Upgrade Member Level              \n\n";
	cout << "4)  Exit                              \n\n";
	cout << "------------------------------------------------------------------------\n\n";
}

//-------------------------------------------------------------------------------------------- LOO JIE QI --------------------------------------------------------------------------------------------

struct convertSTR {
	string str;
};

struct convertCHR {
	char chr;
};


void menuLOGO() {
	system("cls");
	cout << "                                         _____          _____     ____________     ____     ____     _____       _____       " << endl;
	cout << "                                        |      \\\      /      |   |     _______|   |    \\\   |    |   |     |     |     |  " << endl;
	cout << "                                        |       \\\    /       |   |    |           |     \\\  |    |   |     |     |     |  " << endl;
	cout << "                                        |        \\\  /        |   |    |_______    |      \\\ |    |   |     |     |     |  " << endl;
	cout << "                                        |         \\\/         |   |     _______|   |    |\\\ \\\|    |   |     |     |     |" << endl;
	cout << "                                        |     |\\\      /|     |   |    |           |    | \\\      |   |     |     |     |  " << endl;
	cout << "                                        |     | \\\    / |     |   |    |_______    |    |  \\\     |   |      \\\___/      |" << endl;
	cout << "                                        |_____|  \\\__/  |_____|   |____________|   |____|   \\\____|    \\\_______________/ " << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
}

int ditaMSG(int temp) {
	convertSTR temp2;
	do {
		cout << "Do you want to dine in (enter 1) or take away (2) : ";
		cin >> temp2.str;
		if (temp2.str != "1" && temp2.str != "2") {
			cout << endl;
			cout << "--------------------------------------------" << endl;
			cout << "      Invalid input, please enter again     " << endl;
			cout << "--------------------------------------------" << endl;
			cout << endl;
		}
	} while (temp2.str != "1" && temp2.str != "2");

	temp = stoi(temp2.str);
	return temp;
}

void di_ta() {
	int temp = 0;
	menuLOGO();
	cout << "                                                  **********************************************************     " << endl;
	cout << "                                                  *                                                        *     " << endl;
	cout << "                                                  *        ****************************************        *     " << endl;
	cout << "                                                  *        *                                      *        *     " << endl;
	cout << "                                                  *        *                                      *        *     " << endl;
	cout << "                                                  *        *                                      *        *     " << endl;
	cout << "                                                  *        *            1)     Dine In            *        *     " << endl;
	cout << "                                                  *        *            2)     Take Away          *        *     " << endl;
	cout << "                                                  *        *                                      *        *     " << endl;
	cout << "                                                  *        *                                      *        *     " << endl;
	cout << "                                                  *        *                                      *        *     " << endl;
	cout << "                                                  *        ****************************************        *     " << endl;
	cout << "                                                  *                                                        *     " << endl;
	cout << "                                                  **********************************************************     " << endl;
	cout << endl;
	cout << endl;
	selectionDITA = ditaMSG(temp);
}

void menu(int* selectionMENU) {
	convertSTR temp2;
	menuLOGO();
	cout << "                                                  **********************************************************     " << endl;
	cout << "                                                  *                                                        *     " << endl;
	cout << "                                                  *        ****************************************        *     " << endl;
	cout << "                                                  *        *                                      *        *     " << endl;
	cout << "                                                  *        *                                      *        *     " << endl;
	cout << "                                                  *        *            1)     CHICKEN            *        *     " << endl;
	cout << "                                                  *        *            2)     BURGER             *        *     " << endl;
	cout << "                                                  *        *            3)     TWISTER            *        *     " << endl;
	cout << "                                                  *        *            4)     NUGGETS            *        *     " << endl;
	cout << "                                                  *        *                                      *        *     " << endl;
	cout << "                                                  *        *                                      *        *     " << endl;
	cout << "                                                  *        ****************************************        *     " << endl;
	cout << "                                                  *                                                        *     " << endl;
	cout << "                                                  **********************************************************     " << endl;
	cout << endl;
	cout << endl;
	do {    //this do-while is for checking validation
		cout << "Select a food that you want to buy (1-4) : ";
		cin >> temp2.str;
		if (temp2.str != "1" && temp2.str != "2" && temp2.str != "3" && temp2.str != "4") {
			cout << endl;
			cout << "--------------------------------------------" << endl;
			cout << "      Invalid input, please enter again     " << endl;
			cout << "--------------------------------------------" << endl;
			cout << endl;
		}
	} while (temp2.str != "1" && temp2.str != "2" && temp2.str != "3" && temp2.str != "4");

	*selectionMENU = stoi(temp2.str);
}

bool checkDigit(convertSTR tempQTY) {										//validation
	for (int l = 0; l < tempQTY.str.length(); l++) {
		if (!(tempQTY.str[l] >= 48 && tempQTY.str[l] <= 57)) {
			return false;
		}
	}
	return true;
}

//-------------------------------------------------------------- Chicken --------------------------------------------------------------

void chickenORDER(string* eachfoodName, double* eachfoodPrice, int* qty, double* eachfood_ttlAMT) {
	convertSTR temp2, tempQTY;
	bool chk2;
	double A[8] = { 25.99, 20.99, 20.99, 15.99, 16.99, 23.49, 34.99, 57.99 };
	system("cls");
	cout << "                                   ________   ___      ___   __________     ________   ___   _____   _________    ___     ___ " << endl;
	cout << "                                  /   _____| |   |    |   | |___    ___|   /   _____| |   | /    /  |   ______|  |   \\\   |   |" << endl;
	cout << "                                 /   /       |   |    |   |     |  |      /   /       |   |/    /   |   |        |    \\\  |   |" << endl;
	cout << "                                |   |        |   |____|   |     |  |     |   |        |        /    |   |_____   |     \\\ |   |" << endl;
	cout << "                                |   |        |    ____    |     |  |     |   |        |       \\\     |    _____|  |   |\\\ \\\|   |" << endl;
	cout << "                                |   |        |   |    |   |     |  |     |   |        |   |\\\   \\\    |   |        |   | \\\     |" << endl;
	cout << "                                 \\\   \\\_____  |   |    |   |  ___|  |___   \\\   \\\_____  |   | \\\   \\\   |   |_____   |   |  \\\    |" << endl;
	cout << "                                  \\\________| |___|    |___| |__________|   \\\________| |___|  \\\___\\\  |_________|  |___|   \\\___|" << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << setw(110) << "****************************** SET ******************************" << endl;
	cout << endl;
	cout << endl;
	cout << "                           ....................A01....................        " << "         ....................A02....................      " << endl;
	cout << "                           .                                         .        " << "         .                                         .      " << endl;
	cout << "                           .                                         .        " << "         .                                         .      " << endl;
	cout << "                           .            Dinner Plate Combo           .        " << "         .             Snack Plate Combo           .      " << endl;
	cout << "                           .                                         .        " << "         .                                         .      " << endl;
	cout << "                           .             Price : RM" << A[0] << "             .        " << "         .              Price : RM" << A[1] << "            .      " << endl;
	cout << "                           .                                         .        " << "         .                                         .      " << endl;
	cout << "                           .                                         .        " << "         .                                         .      " << endl;
	cout << "                           ...........................................        " << "         ...........................................      " << endl;
	cout << endl;
	cout << endl;
	cout << "                           ....................A03....................        " << "         ....................A04....................      " << endl;
	cout << "                           .                                         .        " << "         .                                         .      " << endl;
	cout << "                           .                                         .        " << "         .                                         .      " << endl;
	cout << "                           .              2-pc Rice Combo            .        " << "         .              1-pc Rice Combo            .      " << endl;
	cout << "                           .                                         .        " << "         .                                         .      " << endl;
	cout << "                           .             Price : RM" << A[2] << "             .        " << "         .              Price : RM" << A[3] << "            .      " << endl;
	cout << "                           .                                         .        " << "         .                                         .      " << endl;
	cout << "                           .                                         .        " << "         .                                         .      " << endl;
	cout << "                           ...........................................        " << "         ...........................................      " << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << setw(110) << "****************************** Ala Cart ******************************" << endl;
	cout << endl;
	cout << endl;
	cout << "                           ....................A05....................        " << "         ....................A06....................      " << endl;
	cout << "                           .                                         .        " << "         .                                         .      " << endl;
	cout << "                           .                                         .        " << "         .                                         .      " << endl;
	cout << "                           .                2-pc Chicken             .        " << "         .                3-pc Chicken             .      " << endl;
	cout << "                           .                                         .        " << "         .                                         .      " << endl;
	cout << "                           .             Price : RM" << A[4] << "             .        " << "         .              Price : RM" << A[5] << "            .      " << endl;
	cout << "                           .                                         .        " << "         .                                         .      " << endl;
	cout << "                           .                                         .        " << "         .                                         .      " << endl;
	cout << "                           ...........................................        " << "         ...........................................      " << endl;
	cout << endl;
	cout << endl;
	cout << "                           ....................A07....................        " << "         ....................A08....................      " << endl;
	cout << "                           .                                         .        " << "         .                                         .      " << endl;
	cout << "                           .                                         .        " << "         .                                         .      " << endl;
	cout << "                           .                5-pc Chicken             .        " << "         .                9-pc Chicken             .      " << endl;
	cout << "                           .                                         .        " << "         .                                         .      " << endl;
	cout << "                           .             Price : RM" << A[6] << "             .        " << "         .              Price : RM" << A[7] << "            .      " << endl;
	cout << "                           .                                         .        " << "         .                                         .      " << endl;
	cout << "                           .                                         .        " << "         .                                         .      " << endl;
	cout << "                           ...........................................        " << "         ...........................................      " << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << "============================================================================================================================================================" << endl;
	cout << endl;
	cout << endl;
	do {
		cout << "What do you like to order (1-8) : ";
		cin >> temp2.str;
		if (temp2.str != "1" && temp2.str != "2" && temp2.str != "3" && temp2.str != "4" && temp2.str != "5" && temp2.str != "6" && temp2.str != "7" && temp2.str != "8") {
			cout << endl;
			cout << "--------------------------------------------" << endl;
			cout << "      Invalid input, please enter again     " << endl;
			cout << "--------------------------------------------" << endl;
			cout << endl;
		}
	} while (temp2.str != "1" && temp2.str != "2" && temp2.str != "3" && temp2.str != "4" && temp2.str != "5" && temp2.str != "6" && temp2.str != "7" && temp2.str != "8");
	switch (stoi(temp2.str)) {
	case 1:
		*eachfoodPrice = A[0];
		*eachfoodName = "Dinner Plate Combo";
		break;

	case 2:
		*eachfoodPrice = A[1];
		*eachfoodName = "Snack Plate Combo";
		break;

	case 3:
		*eachfoodPrice = A[2];
		*eachfoodName = "2-pc Rice Combo ";
		break;

	case 4:
		*eachfoodPrice = A[3];
		*eachfoodName = "1-pc Rice Combo";
		break;

	case 5:
		*eachfoodPrice = A[4];
		*eachfoodName = "2-pc Chicken (Ala Cart)";
		break;

	case 6:
		*eachfoodPrice = A[5];
		*eachfoodName = "3-pc Chicken (Ala Cart)";
		break;

	case 7:
		*eachfoodPrice = A[6];
		*eachfoodName = "5-pc Chicken (Ala Cart)";
		break;

	case 8:
		*eachfoodPrice = A[7];
		*eachfoodName = "9-pc Chicken (Ala Cart)";
		break;
	}
	do {
		cout << "Quantity                        : ";
		cin >> tempQTY.str;
		chk2 = checkDigit(tempQTY);
		if (!chk2) {
			cout << endl;
			cout << "--------------------------------------------" << endl;
			cout << "      Invalid input, please enter again     " << endl;
			cout << "--------------------------------------------" << endl;
			cout << endl;
		}
	} while (!chk2);
	*qty = stoi(tempQTY.str);
	*eachfood_ttlAMT = A[stoi(temp2.str) - 1] * *qty;
	cout << "Total Amount                    : " << *eachfood_ttlAMT << endl;
}

void burgerORDER(string* eachfoodName, double* eachfoodPrice, int* qty, double* eachfood_ttlAMT) {
	convertSTR temp2, tempQTY;
	bool chk2;
	double B[8] = { 22.49, 19.99, 15.49, 21.49, 18.99, 16.49, 10.49, 17.99 };
	system("cls");
	cout << "                                        ________    ___      ___   __________     ________    _________   __________   " << endl;
	cout << "                                       |   ___  \\\  |   |    |   | |    ____  \\\   /   _____|  |   ______| |    ____  \\\  " << endl;
	cout << "                                       |  |   |  | |   |    |   | |   |____|  | /   /        |  |        |   |____|  | " << endl;
	cout << "                                       |  |___|  | |   |    |   | |        __/ |   |         |  |______  |        __/  " << endl;
	cout << "                                       |   _____/  |   |    |   | |   |\\\   \\\   |   |  ____   |   ______| |   |\\\   \\\    " << endl;
	cout << "                                       |   ___  \\\  |    \\\__/    | |   | \\\   \\\  |   | |__  |  |  |        |   | \\\   \\\   " << endl;
	cout << "                                       |  |___|  | |            | |   |  \\\   \\\  \\\   \\\___| |  |  |______  |   |  \\\   \\\  " << endl;
	cout << "                                       |________/   \\\__________/  |___|   \\\___\\\  \\\________|  |_________| |___|   \\\___\\\ " << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << setw(110) << "****************************** SET ******************************" << endl;
	cout << endl;
	cout << endl;
	cout << "                           ....................B01....................        " << "         ....................B02....................      " << endl;
	cout << "                           .                                         .        " << "         .                                         .      " << endl;
	cout << "                           .                                         .        " << "         .                                         .      " << endl;
	cout << "                           .         Cheezy O.R. Deluxe Combo        .        " << "         .           Zinger Classic Combo          .      " << endl;
	cout << "                           .                                         .        " << "         .                                         .      " << endl;
	cout << "                           .             Price : RM" << B[0] << "             .        " << "         .              Price : RM" << B[1] << "            .      " << endl;
	cout << "                           .                                         .        " << "         .                                         .      " << endl;
	cout << "                           .                                         .        " << "         .                                         .      " << endl;
	cout << "                           ...........................................        " << "         ...........................................      " << endl;
	cout << endl;
	cout << endl;
	cout << "                           ....................B03....................        " << "         ....................B04....................      " << endl;
	cout << "                           .                                         .        " << "         .                                         .      " << endl;
	cout << "                           .                                         .        " << "         .                                         .      " << endl;
	cout << "                           .          Colonel Classic Combo          .        " << "         .           Zinger Cheezy Combo           .      " << endl;
	cout << "                           .                                         .        " << "         .                                         .      " << endl;
	cout << "                           .             Price : RM" << B[2] << "             .        " << "         .              Price : RM" << B[3] << "            .      " << endl;
	cout << "                           .                                         .        " << "         .                                         .      " << endl;
	cout << "                           .                                         .        " << "         .                                         .      " << endl;
	cout << "                           ...........................................        " << "         ...........................................      " << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << setw(110) << "****************************** Ala Cart ******************************" << endl;
	cout << endl;
	cout << endl;
	cout << "                           ....................B05....................        " << "         ....................B06....................      " << endl;
	cout << "                           .                                         .        " << "         .                                         .      " << endl;
	cout << "                           .                                         .        " << "         .                                         .      " << endl;
	cout << "                           .            Cheezy O.R. Deluxe           .        " << "         .              Zinger Classic             .      " << endl;
	cout << "                           .                                         .        " << "         .                                         .      " << endl;
	cout << "                           .             Price : RM" << B[4] << "             .        " << "         .              Price : RM" << B[5] << "            .      " << endl;
	cout << "                           .                                         .        " << "         .                                         .      " << endl;
	cout << "                           .                                         .        " << "         .                                         .      " << endl;
	cout << "                           ...........................................        " << "         ...........................................      " << endl;
	cout << endl;
	cout << endl;
	cout << "                           ....................B07....................        " << "         ....................B08....................      " << endl;
	cout << "                           .                                         .        " << "         .                                         .      " << endl;
	cout << "                           .                                         .        " << "         .                                         .      " << endl;
	cout << "                           .             Colonel Classic             .        " << "         .              Zinger Cheezy              .      " << endl;
	cout << "                           .                                         .        " << "         .                                         .      " << endl;
	cout << "                           .             Price : RM" << B[6] << "             .        " << "         .              Price : RM" << B[7] << "            .      " << endl;
	cout << "                           .                                         .        " << "         .                                         .      " << endl;
	cout << "                           .                                         .        " << "         .                                         .      " << endl;
	cout << "                           ...........................................        " << "         ...........................................      " << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << "============================================================================================================================================================" << endl;
	cout << endl;
	cout << endl;
	do {
		cout << "What do you like to order (1-8) : ";
		cin >> temp2.str;
		if (temp2.str != "1" && temp2.str != "2" && temp2.str != "3" && temp2.str != "4" && temp2.str != "5" && temp2.str != "6" && temp2.str != "7" && temp2.str != "8") {
			cout << endl;
			cout << "--------------------------------------------" << endl;
			cout << "      Invalid input, please enter again     " << endl;
			cout << "--------------------------------------------" << endl;
			cout << endl;
		}
	} while (temp2.str != "1" && temp2.str != "2" && temp2.str != "3" && temp2.str != "4" && temp2.str != "5" && temp2.str != "6" && temp2.str != "7" && temp2.str != "8");
	switch (stoi(temp2.str)) {
	case 1:
		*eachfoodPrice = B[0];
		*eachfoodName = "Cheezy O.R. Deluxe Combo";
		break;

	case 2:
		*eachfoodPrice = B[1];
		*eachfoodName = "Zinger Classic Combo";
		break;

	case 3:
		*eachfoodPrice = B[2];
		*eachfoodName = "Colonel Classic Combo";
		break;

	case 4:
		*eachfoodPrice = B[3];
		*eachfoodName = "Zinger Cheezy Combo";
		break;

	case 5:
		*eachfoodPrice = B[4];
		*eachfoodName = "Cheezy O.R. Deluxe (Ala Cart)";
		break;

	case 6:
		*eachfoodPrice = B[5];
		*eachfoodName = "Zinger Classic (Ala Cart)";
		break;

	case 7:
		*eachfoodPrice = B[6];
		*eachfoodName = "Colonel Classic (Ala Cart)";
		break;

	case 8:
		*eachfoodPrice = B[7];
		*eachfoodName = "Zinger Cheezy (Ala Cart)";
		break;

	default:
		cout << endl;
		cout << "--------------------------------------------" << endl;
		cout << "      Invalid input, please enter again     " << endl;
		cout << "--------------------------------------------" << endl;
		cout << endl;
		break;
	}
	do {
		cout << "Quantity                        : ";
		cin >> tempQTY.str;
		chk2 = checkDigit(tempQTY);
		if (!chk2) {
			cout << endl;
			cout << "--------------------------------------------" << endl;
			cout << "      Invalid input, please enter again     " << endl;
			cout << "--------------------------------------------" << endl;
			cout << endl;
		}
	} while (!chk2);
	*qty = stoi(temp2.str);
	*eachfood_ttlAMT = B[stoi(temp2.str) - 1] * *qty;
	cout << "Total Amount                    : " << *eachfood_ttlAMT << endl;
}

void twisterORDER(string* eachfoodName, double* eachfoodPrice, int* qty, double* eachfood_ttlAMT) {
	convertSTR temp2, tempQTY;
	bool chk2;
	double C[4] = { 19.99, 21.99, 16.49, 18.49 };
	system("cls");
	cout << "                                     ________   __      __      __   ________     _______   ________   _______    __________   " << endl;
	cout << "                                    |__    __| |  |    /  \\\    |  | |__    __|   /  _____| |__    __| |   ____|  |    ____  \\\  " << endl;
	cout << "                                       |  |    |  |   /    \\\   |  |    |  |     |  |          |  |    |  |       |   |____|  | " << endl;
	cout << "                                       |  |    |  |  /  /\\\  \\\  |  |    |  |     |  |____      |  |    |  |____   |        __/  " << endl;
	cout << "                                       |  |    |  | /  /  \\\  \\\ |  |    |  |      \\\____  \\\     |  |    |   ____|  |   |\\\   \\\    " << endl;
	cout << "                                       |  |    |  |/  /    \\\  \\\|  |    |  |           |  |    |  |    |  |       |   | \\\   \\\   " << endl;
	cout << "                                       |  |     \\\    /      \\\    /   __|  |__    _____|  |    |  |    |  |____   |   |  \\\   \\\  " << endl;
	cout << "                                       |__|      \\\__/        \\\__/   |________|  |_______/     |__|    |_______|  |___|   \\\___\\\ " << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << setw(110) << "****************************** SET ******************************" << endl;
	cout << endl;
	cout << endl;
	cout << "                           ....................C01....................        " << "         ....................C02....................      " << endl;
	cout << "                           .                                         .        " << "         .                                         .      " << endl;
	cout << "                           .                                         .        " << "         .                                         .      " << endl;
	cout << "                           .           Cheezy Twister Combo          .        " << "         .             BBQ Twister Combo           .      " << endl;
	cout << "                           .                                         .        " << "         .                                         .      " << endl;
	cout << "                           .             Price : RM" << C[0] << "             .        " << "         .              Price : RM" << C[1] << "            .      " << endl;
	cout << "                           .                                         .        " << "         .                                         .      " << endl;
	cout << "                           .                                         .        " << "         .                                         .      " << endl;
	cout << "                           ...........................................        " << "         ...........................................      " << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << setw(110) << "****************************** Ala Cart ******************************" << endl;
	cout << endl;
	cout << endl;
	cout << "                           ....................C03....................        " << "         ....................C04....................      " << endl;
	cout << "                           .                                         .        " << "         .                                         .      " << endl;
	cout << "                           .                                         .        " << "         .                                         .      " << endl;
	cout << "                           .              Cheezy Twister             .        " << "         .               BBQ Twister               .      " << endl;
	cout << "                           .                                         .        " << "         .                                         .      " << endl;
	cout << "                           .             Price : RM" << C[2] << "             .        " << "         .              Price : RM" << C[3] << "            .      " << endl;
	cout << "                           .                                         .        " << "         .                                         .      " << endl;
	cout << "                           .                                         .        " << "         .                                         .      " << endl;
	cout << "                           ...........................................        " << "         ...........................................      " << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << "============================================================================================================================================================" << endl;
	cout << endl;
	cout << endl;
	do {
		cout << "Select a food that you want to buy (1-4)   : ";
		cin >> temp2.str;
		if (temp2.str != "1" && temp2.str != "2" && temp2.str != "3" && temp2.str != "4") {
			cout << endl;
			cout << "--------------------------------------------" << endl;
			cout << "      Invalid input, please enter again     " << endl;
			cout << "--------------------------------------------" << endl;
			cout << endl;
		}
	} while (temp2.str != "1" && temp2.str != "2" && temp2.str != "3" && temp2.str != "4");
	switch (stoi(temp2.str)) {
	case 1:
		*eachfoodPrice = C[0];
		*eachfoodName = "Cheezy Twister Combo";
		break;

	case 2:
		*eachfoodPrice = C[1];
		*eachfoodName = "BBQ Twister Combo";
		break;

	case 3:
		*eachfoodPrice = C[2];
		*eachfoodName = "Cheezy Twister (Ala Cart)";
		break;

	case 4:
		*eachfoodPrice = C[3];
		*eachfoodName = "BBQ Twister (Ala Cart)";
		break;

	default:
		cout << endl;
		cout << "--------------------------------------------" << endl;
		cout << "      Invalid input, please enter again     " << endl;
		cout << "--------------------------------------------" << endl;
		cout << endl;
		break;
	}
	do {
		cout << "Quantity                                   : ";
		cin >> tempQTY.str;
		chk2 = checkDigit(tempQTY);
		if (!chk2) {
			cout << endl;
			cout << "--------------------------------------------" << endl;
			cout << "      Invalid input, please enter again     " << endl;
			cout << "--------------------------------------------" << endl;
			cout << endl;
		}
	} while (!chk2);
	*qty = stoi(tempQTY.str);
	*eachfood_ttlAMT = C[stoi(temp2.str) - 1] * *qty;
	cout << "Total Amount                               : " << *eachfood_ttlAMT << endl;
}


void nuggetsORDER(string* eachfoodName, double* eachfoodPrice, int* qty, double* eachfood_ttlAMT) {
	convertSTR temp2, tempQTY;
	bool chk2;
	double D[8] = { 20.49, 17.49, 20.49, 17.49, 15.49, 12.49, 15.49, 12.49 };
	system("cls");
	cout << "                                   ___    ___   __      __     ________     ________    _________   __________    _______ " << endl;
	cout << "                                  |   \\\  |   | |  |    |  |   /   _____|   /   _____|  |   ______| |___    ___|  /  _____|" << endl;
	cout << "                                  |    \\\ |   | |  |    |  |  /   /        /   /        |  |            |  |     |  |      " << endl;
	cout << "                                  |     \\\|   | |  |    |  | |   |        |   |         |  |______      |  |     |  |____  " << endl;
	cout << "                                  |          | |  |    |  | |   |  ____  |   |  ____   |   ______|     |  |      \\\____  \\\ " << endl;
	cout << "                                  |   |\\\     | |   \\\__/   | |   | |__  | |   | |__  |  |  |            |  |           |  |" << endl;
	cout << "                                  |   | \\\    | |          |  \\\   \\\___| |  \\\   \\\___| |  |  |______      |  |      _____|  |" << endl;
	cout << "                                  |___|  \\\___|  \\\________/    \\\________|   \\\________|  |_________|     |__|     |_______/ " << endl;
	cout << endl;
	cout << endl;
	cout << setw(110) << "****************************** SET ******************************" << endl;
	cout << endl;
	cout << endl;
	cout << "                           ....................D01....................        " << "         ....................D02....................      " << endl;
	cout << "                           .                                         .        " << "         .                                         .      " << endl;
	cout << "                           .                                         .        " << "         .                                         .      " << endl;
	cout << "                           .         9-pc Spicy Nuggets Combo        .        " << "         .         6-pc Spicy Nuggets Combo        .      " << endl;
	cout << "                           .                                         .        " << "         .                                         .      " << endl;
	cout << "                           .             Price : RM" << D[0] << "             .        " << "         .              Price : RM" << D[1] << "            .      " << endl;
	cout << "                           .                                         .        " << "         .                                         .      " << endl;
	cout << "                           .                                         .        " << "         .                                         .      " << endl;
	cout << "                           ...........................................        " << "         ...........................................      " << endl;
	cout << endl;
	cout << endl;
	cout << "                           ....................D03....................        " << "         ....................D04....................      " << endl;
	cout << "                           .                                         .        " << "         .                                         .      " << endl;
	cout << "                           .                                         .        " << "         .                                         .      " << endl;
	cout << "                           .            9-pc Nuggets Combo           .        " << "         .             6-pc Nuggets Combo          .      " << endl;
	cout << "                           .                                         .        " << "         .                                         .      " << endl;
	cout << "                           .             Price : RM" << D[2] << "             .        " << "         .              Price : RM" << D[3] << "            .      " << endl;
	cout << "                           .                                         .        " << "         .                                         .      " << endl;
	cout << "                           .                                         .        " << "         .                                         .      " << endl;
	cout << "                           ...........................................        " << "         ...........................................      " << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << setw(110) << "****************************** Ala Cart ******************************" << endl;
	cout << endl;
	cout << endl;
	cout << "                           ....................D05....................        " << "         ....................D06....................      " << endl;
	cout << "                           .                                         .        " << "         .                                         .      " << endl;
	cout << "                           .                                         .        " << "         .                                         .      " << endl;
	cout << "                           .            9-pc Spicy Nuggets           .        " << "         .            6-pc Spicy Nuggets           .      " << endl;
	cout << "                           .                                         .        " << "         .                                         .      " << endl;
	cout << "                           .             Price : RM" << D[4] << "             .        " << "         .              Price : RM" << D[5] << "            .      " << endl;
	cout << "                           .                                         .        " << "         .                                         .      " << endl;
	cout << "                           .                                         .        " << "         .                                         .      " << endl;
	cout << "                           ...........................................        " << "         ...........................................      " << endl;
	cout << endl;
	cout << endl;
	cout << "                           ....................D07....................        " << "         ....................D08....................      " << endl;
	cout << "                           .                                         .        " << "         .                                         .      " << endl;
	cout << "                           .                                         .        " << "         .                                         .      " << endl;
	cout << "                           .               9-pc Nuggets              .        " << "         .               6-pc Nuggets              .      " << endl;
	cout << "                           .                                         .        " << "         .                                         .      " << endl;
	cout << "                           .             Price : RM" << D[6] << "             .        " << "         .              Price : RM" << D[7] << "            .      " << endl;
	cout << "                           .                                         .        " << "         .                                         .      " << endl;
	cout << "                           .                                         .        " << "         .                                         .      " << endl;
	cout << "                           ...........................................        " << "         ...........................................      " << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << "============================================================================================================================================================" << endl;
	cout << endl;
	cout << endl;
	do {
		cout << "What do you like to order (1-8)     : ";
		cin >> temp2.str;
		if (temp2.str != "1" && temp2.str != "2" && temp2.str != "3" && temp2.str != "4" && temp2.str != "5" && temp2.str != "6" && temp2.str != "7" && temp2.str != "8") {
			cout << endl;
			cout << "--------------------------------------------" << endl;
			cout << "      Invalid input, please enter again     " << endl;
			cout << "--------------------------------------------" << endl;
			cout << endl;
		}
	} while (temp2.str != "1" && temp2.str != "2" && temp2.str != "3" && temp2.str != "4" && temp2.str != "5" && temp2.str != "6" && temp2.str != "7" && temp2.str != "8");
	switch (stoi(temp2.str)) {
	case 1:
		*eachfoodPrice = D[0];
		*eachfoodName = "9-pc Spicy Nuggets Combo";
		break;

	case 2:
		*eachfoodPrice = D[1];
		*eachfoodName = "6-pc Spicy Nuggets Combo";
		break;

	case 3:
		*eachfoodPrice = D[2];
		*eachfoodName = "9-pc Nuggets Combo";
		break;

	case 4:
		*eachfoodPrice = D[3];
		*eachfoodName = "6-pc Nuggets Combo";
		break;

	case 5:
		*eachfoodPrice = D[4];
		*eachfoodName = "9-pc Spicy Nuggets (Ala Cart)";
		break;

	case 6:
		*eachfoodPrice = D[5];
		*eachfoodName = "6-pc Spicy Nuggets (Ala Cart)";
		break;

	case 7:
		*eachfoodPrice = D[6];
		*eachfoodName = "9-pc Nuggets (Ala Cart)";
		break;

	case 8:
		*eachfoodPrice = D[7];
		*eachfoodName = "6-pc Nuggets (Ala Cart)";
		break;

	default:
		cout << endl;
		cout << "--------------------------------------------" << endl;
		cout << "      Invalid input, please enter again     " << endl;
		cout << "--------------------------------------------" << endl;
		cout << endl;
		break;
	}
	do {
		cout << "Quantity                            : ";
		cin >> tempQTY.str;
		chk2 = checkDigit(tempQTY);
		if (!chk2) {
			cout << endl;
			cout << "--------------------------------------------" << endl;
			cout << "      Invalid input, please enter again     " << endl;
			cout << "--------------------------------------------" << endl;
			cout << endl;
		}
	} while (!chk2);
	*qty = stoi(tempQTY.str);
	*eachfood_ttlAMT = D[stoi(temp2.str) - 1] * *qty;
	cout << "Total Amount                        : " << *eachfood_ttlAMT << endl;
}


void chooseANDstoreOrder(int selectionMENU, vector<string>& foodName_array, vector<double>& price_array, vector<int>& qty_array, vector<double>& ttlAMT_array) {
	int qty, i = 0;
	double eachfoodPrice, eachfood_ttlAMT;
	string eachfoodName;
	switch (selectionMENU) {
	case 1:
		chickenORDER(&eachfoodName, &eachfoodPrice, &qty, &eachfood_ttlAMT);
		break;

	case 2:
		burgerORDER(&eachfoodName, &eachfoodPrice, &qty, &eachfood_ttlAMT);
		break;

	case 3:
		twisterORDER(&eachfoodName, &eachfoodPrice, &qty, &eachfood_ttlAMT);
		break;

	case 4:
		nuggetsORDER(&eachfoodName, &eachfoodPrice, &qty, &eachfood_ttlAMT);
		break;
	}

	foodName_array.push_back(eachfoodName);
	price_array.push_back(eachfoodPrice);				  //store each price of food item in efPrice
	qty_array.push_back(qty);                           //store each quantity of food item into qty_array
	ttlAMT_array.push_back(eachfood_ttlAMT);            //store each total amount of food item into ttlAMT_array
	i++;
}


void display_orderDetails(int* ttlnumOrder, int times, vector<string> foodName_array, vector<double>& price_array, vector<int>& qty_array, vector<double>& ttlAMT_array, double ttl) {
	system("cls");
	cout << "   ********************************************************************************************************************************************************" << endl;
	cout << "   *         *                                                            *                          *                     *                              *" << endl;
	cout << "   *         *                                                            *                          *                     *                              *" << endl;
	cout << "   *         *                            FOOD                            *        PRICE (RM)        *       QUANTITY      *          TOTAL (RM)          *" << endl;
	cout << "   *         *                                                            *                          *                     *                              *" << endl;
	cout << "   *         *                                                            *                          *                     *                              *" << endl;
	cout << "   ********************************************************************************************************************************************************" << endl;
	*ttlnumOrder = 0;
	for (int j = 0; j < times; j++) {
		cout << "   *         *                                                            *                          *                     *                              *" << endl;
		cout << "   *" << setw(5) << j + 1 << setw(5) << "*" << setw(40) << foodName_array[j] << setw(21) << "*" << setw(15) << price_array[j] << setw(12) << "*" << setw(11) << qty_array[j] << setw(11) << "*" << setw(17) << ttlAMT_array[j] << setw(14) << "*" << endl;
		cout << "   *         *                                                            *                          *                     *                              *" << endl;
		*ttlnumOrder += 1;
	}
	cout << "   ********************************************************************************************************************************************************" << endl;
	cout << "   *                                                                                                                                                      *" << endl;
	cout << "   *" << setw(137) << ttl << setw(14) << "*" << endl;
	cout << "   *                                                                                                                                                      *" << endl;
	cout << "   ********************************************************************************************************************************************************" << endl;
	system("pause");
}

void cal_reduceOrder(int reduceORremove_foodNum, int qtyreduce, vector<int>& qty_array, vector<double>& ttlAMT_array, vector<double>& price_array) {
	qty_array[reduceORremove_foodNum] -= qtyreduce;
	ttlAMT_array[reduceORremove_foodNum] = price_array[reduceORremove_foodNum] * qty_array[reduceORremove_foodNum];
}

void cal_removeOrder(int ttlnumOrder, int reduceORremove_foodNum, vector<int>& qty_array, vector<double>& ttlAMT_array, vector<double>& price_array, vector<string>& foodName_array) {
	for (int i = reduceORremove_foodNum; i < ttlnumOrder - 1; i++) {
		qty_array[i] = qty_array[i + 1];
		ttlAMT_array[i] = ttlAMT_array[i + 1];
		price_array[i] = price_array[i + 1];
		foodName_array[i] = foodName_array[i + 1];
	}
}

void cal_ttl(double* ttl, int times, vector<double>& price_array, vector<int>& qty_array) {
	for (int i = 0; i < times; i++) {
		*ttl += price_array[i] * qty_array[i];
	}
}

double cal_ttlpayment(double ttl) {
	beforeTotal = ttl;
	if (selectionDITA == 1) {
		ttl -= ttl * serviceChaarges;
	}
	else {
		ttl += packagingCharges;
	}
	return ttl;
}


bool checkCharacter(convertSTR temp3) {
	for (int l = 0; l < temp3.str.length(); l++) {
		if (!isdigit(temp3.str[l])) {
			return false;
		}
	}
	return true;
}

bool checkReduceQTY(convertSTR tempQTYreduce) {
	for (int l = 0; l < tempQTYreduce.str.length(); l++) {
		if (!(tempQTYreduce.str[l] >= 48 && tempQTYreduce.str[l] <= 57)) {
			return false;
		}
	}
	return true;
}

void MainMenu() {
	convertSTR temp2, temp4, temp3, tempQTYreduce;
	int selectionMENU, times = 0, ttlnumOrder = 0, reduceORremove_foodNum = 0, qtyreduce = 0;
	double ttl = 0, ttlPayment;
	bool chk;
	vector<string> foodName_array = { };
	vector<double> price_array = {  }, ttlAMT_array = {  };
	vector<int>qty_array = {  };
	di_ta();
	do {   // this do while is for add on
		do {   //this do while is for customer keep odering
			menu(&selectionMENU);
			chooseANDstoreOrder(selectionMENU, foodName_array, price_array, qty_array, ttlAMT_array);
			times++;
			do {
				cout << endl;
				cout << "Do you want to keep odering ? " << endl;
				cout << "( If yes enter 1 )" << endl;
				cout << "( If no enter 2 )" << endl;
				cout << "Option                        : ";
				cin >> temp2.str;
				if (temp2.str != "1" && temp2.str != "2") {
					cout << endl;
					cout << "--------------------------------------------" << endl;
					cout << "      Invalid input, please enter again     " << endl;
					cout << "--------------------------------------------" << endl;
					cout << endl;
				}
			} while (temp2.str != "1" && temp2.str != "2");

		} while (temp2.str == "1");
		cal_ttl(&ttl, times, price_array, qty_array);   // calculation for total amount

	label1:
		display_orderDetails(&ttlnumOrder, times, foodName_array, price_array, qty_array, ttlAMT_array, ttl);
		cout << endl;
		cout << endl;
		do {    		 	//this do-while is for validation
			cout << "Do you want to add/reduce/remove your food order?" << endl;
			cout << "Press 1 to add on" << endl;
			cout << "Press 2 to reduce" << endl;
			cout << "Press 3 to remove" << endl;
			cout << "Press 4 proceed to payment" << endl;
			cout << "Option : ";
			cin >> temp2.str;
			if (temp2.str != "1" && temp2.str != "2" && temp2.str != "3" && temp2.str != "4") {
				cout << endl;
				cout << "--------------------------------------------" << endl;
				cout << "      Invalid input, please enter again     " << endl;
				cout << "--------------------------------------------" << endl;
				cout << endl;
			}
		} while (temp2.str != "1" && temp2.str != "2" && temp2.str != "3" && temp2.str != "4");
		switch (stoi(temp2.str)) {
		case 1:						//add on
			ttl = 0;
			break;

		case 2:                     //reduce
			do {
				do {
					cout << endl;
					cout << "Choose the number of your order that you want to reduce : ";
					cin >> temp3.str;
					chk = checkCharacter(temp3);		//check whether it is character or not
					if (chk == false) {
						cout << endl;
						cout << "--------------------------------------------" << endl;
						cout << "      Invalid input, please enter again     " << endl;
						cout << "--------------------------------------------" << endl;
						cout << endl;
					}
				} while (chk == false);
				while (stoi(temp3.str) < 1 || stoi(temp3.str) > ttlnumOrder) {
					cout << endl;
					cout << "--------------------------------------------" << endl;
					cout << "      Invalid input, please enter again     " << endl;
					cout << "--------------------------------------------" << endl;
					cout << endl;
					break;
				}
			} while (stoi(temp3.str) < 1 || stoi(temp3.str) > ttlnumOrder);

			reduceORremove_foodNum = stoi(temp3.str) - 1;			// if user select 3 means the number of food order is in index 2

			do {
				cout << "How many quantity you want to reduce                    : ";
				cin >> tempQTYreduce.str;
				chk = checkReduceQTY(tempQTYreduce);
				while (stoi(tempQTYreduce.str) < 0 || stoi(tempQTYreduce.str) > qty_array[times - 1] || !chk) {
					cout << endl;
					cout << "--------------------------------------------" << endl;
					cout << "      Invalid input, please enter again     " << endl;
					cout << "--------------------------------------------" << endl;
					cout << endl;
					break;
				}
			} while (stoi(tempQTYreduce.str) < 0 || stoi(tempQTYreduce.str) > qty_array[times - 1] || !chk);
			qtyreduce = stoi(tempQTYreduce.str);
			cal_reduceOrder(reduceORremove_foodNum, qtyreduce, qty_array, ttlAMT_array, price_array);  //calculation for reduce amount
			ttl = 0;
			cal_ttl(&ttl, times, price_array, qty_array);									   // calculation for total amount
			display_orderDetails(&ttlnumOrder, times, foodName_array, price_array, qty_array, ttlAMT_array, ttl);
			break;

		case 3:					// remove
			do {
				do {
					cout << endl;
					cout << "Choose the number of your order that you want to remove : ";
					cin >> temp3.str;
					chk = checkCharacter(temp3);	         //check whether it is character or not
					if (chk == false) {
						cout << endl;
						cout << "--------------------------------------------" << endl;
						cout << "      Invalid input, please enter again     " << endl;
						cout << "--------------------------------------------" << endl;
						cout << endl;
					}
				} while (chk == false);
				while (stoi(temp3.str) < 1 || stoi(temp3.str) > ttlnumOrder) {
					cout << endl;
					cout << "--------------------------------------------" << endl;
					cout << "      Invalid input, please enter again     " << endl;
					cout << "--------------------------------------------" << endl;
					cout << endl;
					break;
				}
			} while (stoi(temp3.str) < 1 || stoi(temp3.str) > ttlnumOrder);

			reduceORremove_foodNum = stoi(temp3.str) - 1;			// if user select 3 means the number of food order is in index 2
			cal_removeOrder(ttlnumOrder, reduceORremove_foodNum, qty_array, ttlAMT_array, price_array, foodName_array);  // remove and replace item
			times -= 1;
			ttl = 0;
			cal_ttl(&ttl, times, price_array, qty_array);									   // calculation for total amount
			display_orderDetails(&ttlnumOrder, times, foodName_array, price_array, qty_array, ttlAMT_array, ttl);
			break;

		case 4:
			break;
		}
	} while (temp2.str == "1");        // this while is for add on

	if (temp2.str == "1" || temp2.str == "2" || temp2.str == "3") {
		do {
			cout << "Do you want to keep add/reduce/remove your food order?" << endl;
			cout << "Press 1 : Yes" << endl;
			cout << "Press 2 : No" << endl;
			cout << "Option  : ";
			cin >> temp4.str;
			while (temp4.str != "1" && temp4.str != "2") {
				cout << endl;
				cout << "--------------------------------------------" << endl;
				cout << "      Invalid input, please enter again     " << endl;
				cout << "--------------------------------------------" << endl;
				cout << endl;
				break;
			}
		} while (temp4.str != "1" && temp4.str != "2");
	}

	if (temp4.str == "1") {
		goto label1;
	}

	ttlPayment = cal_ttlpayment(ttl);
}


//-------------------------------------------------------------------------------------------- LOO JIE QI --------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------- LOO JIE QI --------------------------------------------------------------------------------------------

bool checkLevelOption(convertSTR option) {
	for (int l = 0; l < option.str.length(); l++) {
		if (!(option.str[l] >= 48 && option.str[l] <= 57)) {
			return false;
		}
	}
	return true;
}

void membersLevelPaymentLogo() {
	cout << "                             _______        ___       ___     ___   ___          ___     __________    ___     ___    _________  " << endl;
	cout << "                            |   __  \\\      /   \\\      \\\  \\\   /  /  |    \\\      /    |   |     _____|  |   \\\   |   |  |__     __| " << endl;
	cout << "                            |  |__|  |    /  _  \\\      \\\  \\\ /  /   |     \\\    /     |   |    |        |    \\\  |   |     |   |    " << endl;
	cout << "                            |   ____/    /  /_\\\  \\\      \\\     /    |      \\\  /      |   |    |_____   |     \\\ |   |     |   |    " << endl;
	cout << "                            |  |        /  _____  \\\      |   |     |       \\\/       |   |     _____|  |   |\\\ \\\|   |     |   |    " << endl;
	cout << "                            |  |       /  /     \\\  \\\     |   |     |   |\\\      /|   |   |    |        |   | \\\     |     |   |    " << endl;
	cout << "                            |  |      /  /       \\\  \\\    |   |     |   | \\\    / |   |   |    |_____   |   |  \\\    |     |   |    " << endl;
	cout << "                            |__|     /__/         \\\__\\\   |___|     |___|  \\\__/  |___|   |__________|  |___|   \\\___|     |___|    " << endl;
}

void membersLevelPayment(double levelAMT) {
	convertSTR creditcardNum;
	double enterAMT;
	bool chk2;
	system("cls");
	membersLevelPaymentLogo();
	cout << "============================================================================================================================================================" << endl;
	cout << endl;
	cout << "                                                             Upgrade Level :  " << information[positionofMembershipStatusGlobal] << endl;
	cout << "                                                             Total Amount  :  RM" << levelAMT << endl;
	cout << endl;
	cout << "============================================================================================================================================================" << endl;
	do {
		cout << endl;
		cout << "                                                          Enter Amount  :  RM";
		cin >> enterAMT;
		if (enterAMT < levelAMT) {
			cout << endl;
			cout << "----------------------------------------------------" << endl;
			cout << "      The amount must greater than total amount     " << endl;
			cout << "----------------------------------------------------" << endl;
			cout << endl;
		}
	} while (enterAMT < levelAMT);
	cout << "                                                          Changes      :  RM" << enterAMT - levelAMT << endl;
	cout << endl;
	cout << "                                                          PAYMENT SUCCESSFUL !" << endl;
	writeToFile();
	system("pause");
}

void membersLevel() {
	convertSTR option;
	bool chk;
	int levelAMT = 0;
	system("cls");
	cout << endl;
	cout << "============================================================================================================================================================" << endl;
	cout << endl;
	cout << setw(89) << "Upgrade Member Level" << endl;
	cout << endl;
	cout << "============================================================================================================================================================" << endl;
	cout << endl;
	cout << endl;
	cout << "                                                  **********************************************************     " << endl;
	cout << "                                                  *                                                        *     " << endl;
	cout << "                                                  *        ****************************************        *     " << endl;
	cout << "                                                  *        *                                      *        *     " << endl;
	cout << "                                                  *        *                                      *        *     " << endl;
	cout << "                                                  *        *                                      *        *     " << endl;
	cout << "                                                  *        *       1)     Bronze -- RM 50         *        *     " << endl;
	cout << "                                                  *        *       2)     Silver -- RM 150        *        *     " << endl;
	cout << "                                                  *        *       3)     Gold   -- RM 300        *        *     " << endl;
	cout << "                                                  *        *                                      *        *     " << endl;
	cout << "                                                  *        *                                      *        *     " << endl;
	cout << "                                                  *        *                                      *        *     " << endl;
	cout << "                                                  *        ****************************************        *     " << endl;
	cout << "                                                  *                                                        *     " << endl;
	cout << "                                                  **********************************************************     " << endl;
	cout << endl;
	cout << "Bronze : you can get 10% discount for food purchase" << endl;
	cout << "Silver : you can get 20% discount for food purchase" << endl;
	cout << "Gold   : you can get 30% discount for food purchase" << endl;
	cout << "\n\n";
	cout << "Which level you want to upgrade ?" << endl;
	do {
		cout << "Option : ";
		cin >> option.str;
		chk = checkLevelOption(option);
		if (!chk || option.str != "1" && option.str != "2" && option.str != "3") {
			cout << endl;
			cout << "--------------------------------------------" << endl;
			cout << "      Invalid input, please enter again     " << endl;
			cout << "--------------------------------------------" << endl;
			cout << endl;
		}
	} while (!chk || option.str != "1" && option.str != "2" && option.str != "3");
	switch (stoi(option.str)) {
	case 1:
		information[positionofMembershipStatusGlobal] = "Bronze";
		levelAMT = 50;
		break;

	case 2:
		information[positionofMembershipStatusGlobal] = "Silver";
		levelAMT = 150;
		break;

	case 3:
		information[positionofMembershipStatusGlobal] = "Gold";
		levelAMT = 300;
		break;
	}

	membersLevelPayment(levelAMT);
}

void paymentDetails() {
	cout << "*****************************************************************************************" << endl;
	cout << left << "| Username: " << setw(20) << name << "  " << "Member ID: " << setw(20) << memberId << "Member status: " << setw(8) << membershipStatus << "|" << endl;
	cout << "*****************************************************************************************" << endl;
	cout << "| Description" << setw(48) << right << "Amount" << setw(28) << "|" << endl;
	cout << "|" << setw(88) << setfill('-') << "|" << endl;
	cout << setfill(' ');
	cout << "| Food Ordering" << setw(43) << right << fixed << setprecision(2) << "RM " << left << setw(30) << beforeTotal << "|" << endl;
	cout.unsetf(ios::left);
	cout << "|" << setw(88) << "|" << endl;
	if (selectionDITA == 1) {
		cout << "|" << setw(54) << "service tax: " << fixed << setprecision(2) << "RM " << left << setw(30) << beforeTotal / 10 << "|" << endl;
		cout.unsetf(ios::left);
		totalPayment += beforeTotal * serviceChaarges;
	}
	else {
		cout << "|" << setw(58) << "Take away charges: RM 2" << setw(30) << "|" << endl;
		cout.unsetf(ios::left);
		totalPayment += packagingCharges;
	}

	if (information[positionofMembershipStatusGlobal] == "Bronze") {
		cout << "|" << setw(57) << "Discount (10%) : RM " << fixed << setprecision(2) << totalPayment * 0.1 << setw(26) << "|" << endl;
		totalPayment *= 0.9;
	}
	else if (information[positionofMembershipStatusGlobal] == "Silver") {
		cout << "|" << setw(57) << "Discount (20%) : RM " << fixed << setprecision(2) << totalPayment * 0.2 << setw(26) << "|" << endl;
		totalPayment *= 0.8;
	}
	else if (information[positionofMembershipStatusGlobal] == "Gold") {
		cout << "|" << setw(57) << "Discount (30%) : RM " << fixed << setprecision(2) << totalPayment * 0.3 << setw(26) << "|" << endl;
		totalPayment *= 0.7;
	}
	cout << "|" << setw(54) << "Total: " << fixed << setprecision(2) << "RM " << left << setw(30) << totalPayment << "|" << endl;
	cout << right << "|" << setw(88) << "|" << endl;
	cout << "*****************************************************************************************" << endl;
}

void thankyouPage() {
	system("cls");
	cout << "\n\n\n\n\n\n";
	cout << "                               * * * * * * * *   * * *   * * *             * *           * * *    * * *   * * *   * * *" << endl;
	cout << "                               *             *   *   *   *   *            *   *          *    *   *   *   *   *  *   * " << endl;
	cout << "                               * * *     * * *   *   *   *   *           *  *  *         *     *  *   *   *   * *   *  " << endl;
	cout << "                                   *     *       *   * * *   *          *  * *  *        *      * *   *   *   *    *   " << endl;
	cout << "                                   *     *       *           *         *  * * *  *       *       *    *   *       *    " << endl;
	cout << "                                   *     *       *           *        *           *      *   *        *   *      *     " << endl;
	cout << "                                   *     *       *   * * *   *       *   * * * *   *     *   * *      *   *   *   *    " << endl;
	cout << "                                   *     *       *   *   *   *      *   *       *   *    *   *  *     *   *   * *  *   " << endl;
	cout << "                                   *     *       *   *   *   *     *   *         *   *   *   *   *    *   *   *  *   * " << endl;
	cout << "                                   * * * *       * * *   * * *    * * *           * * *  * * *    * * *   * * *   * * *" << endl;
	cout << endl;
	cout << "                                          * * *           * * *       * * * *          * * *       * * *" << endl;
	cout << "                                           *    *       *    *      *         *        *   *       *   *" << endl;
	cout << "                                             *    *   *   *       *     * *     *      *   *       *   *" << endl;
	cout << "                                               *    *   *       *     *     *     *    *   *       *   *" << endl;
	cout << "                                                 *    *         *   *         *   *    *   *       *   *" << endl;
	cout << "                                                  *   *         *   *         *   *    *   *       *   *" << endl;
	cout << "                                                  *   *         *     *     *     *    *   *       *   *" << endl;
	cout << "                                                  *   *           *     * *     *      *     * * *     *" << endl;
	cout << "                                                  *   *             *         *          *           *  " << endl;
	cout << "                                                  * * *               * * * *              * * * * *    " << endl;
	system("pause");
}
//-------------------------------------------------------------------------------------------- LOO JIE QI --------------------------------------------------------------------------------------------

void registerModule()
{
	int exist;
	set<string> generatedNumbers;
	string customerID = generate6DigitNumber(generatedNumbers);
	string loginRegChoice;
	OandSfile();
RegisterMenu:
	do
	{
		cout << "\n\n";
		cout << "*             * ***** *      ****  ***** **   ** *****   ***** *****   *   * *****  ****" << endl;
		cout << " *     *     *  *     *     *      *   * * * * * *         *   *   *   *  *  *     *    " << endl;
		cout << "  *   * *   *   ***** *     *      *   * *  *  * *****     *   *   *   ***   ***   *    " << endl;
		cout << "   * *   * *    *     *     *      *   * *     * *         *   *   *   *  *  *     *    " << endl;
		cout << "    *     *     ***** *****  ****  ***** *     * *****     *   *****   *   * *      ****" << endl << endl;
		cout << "----------------------------------------------------------------------------------------" << endl;
		cout << "Choose an option: " << endl;
		cout << "----------------------------------------------------------------------------------------" << endl << endl;
		cout << "Press 1 : To Register As New User " << endl << endl;
		cout << "Press 2 : To Login For Order" << endl << endl;
		cout << "Please enter your choice (1/2): ";
		cin >> loginRegChoice;
		cin.ignore();

		if (loginRegChoice == "1")
		{
			string username, password, customerID, membershipStatus = "normal", contactNum, topUp = "0";
			int membershipPoint = 0;
			system("cls");
			cout << "\n\n";
			cout << "****  *****   *****  *****  **** ***** ***** **** " << endl;
			cout << "*   * *      *         *   *       *   *     *   *" << endl;
			cout << "****  ***** *  *****   *    ****   *   ***** **** " << endl;
			cout << "*  *  *      *  *  *   *        *  *   *     *  * " << endl;
			cout << "*   * *****    *   * *****  ****   *   ***** *   *" << endl << endl;

			do
			{
				system("cls");
				cout << "\n\n";
				cout << "****  *****   *****  *****  **** ***** ***** **** " << endl;
				cout << "*   * *      *         *   *       *   *     *   *" << endl;
				cout << "****  ***** *  *****   *    ****   *   ***** **** " << endl;
				cout << "*  *  *      *  *  *   *        *  *   *     *  * " << endl;
				cout << "*   * *****    *   * *****  ****   *   ***** *   *" << endl << endl;
				cout << "------------------------------------------------------" << endl << endl;
				do {
					cout << "Enter username\t\t\t: ";
					getline(cin, username);

					for (int i = 0; i < lines; i++) {
						if (information[i] == username)
						{
							cout << "Username already exist or invalid input, please enter to try again" << endl;
							cout << "\n\n";
							cin.ignore();
							exist = 1;
							break;
						}
						else
							exist = 0;
					}
				} while (exist == 1);

				if (!containsDigits(username))
				{
					cout << "\n\n";
					cout << "Enter password\t\t\t: ";
					getline(cin, password);

					do
					{
						system("cls");
						cout << "\n\n";
						cout << "****  *****   *****  *****  **** ***** ***** **** " << endl;
						cout << "*   * *      *         *   *       *   *     *   *" << endl;
						cout << "****  ***** *  *****   *    ****   *   ***** **** " << endl;
						cout << "*  *  *      *  *  *   *        *  *   *     *  * " << endl;
						cout << "*   * *****    *   * *****  ****   *   ***** *   *" << endl << endl;
						cout << "------------------------------------------------------" << endl << endl;
						cout << "Enter username\t\t\t: " << username;
						cout << "\n\n";
						cout << "Enter password\t\t\t: " << password;
						cout << "\n\n";
						cout << "Enter your contact number (10 digit)\t: ";
						getline(cin, contactNum);


						if (notContainAlphabet(contactNum))
						{
							cout << "\n\n";
							cout << "-------------------------------------------------\n\n";
							customerID = generate6DigitNumber(generatedNumbers);

							if (customerID.empty())
							{
								cout << "Error: All possible membership card numbers have been generated." << endl;
							}
							else
							{
								cout << "Your membership card number\t: ABC" << customerID << endl << endl;
								cout << "-------------------------------------------------\n\n";
								cout << "User registered successfully!\n\n";
								cout << "Your current balance: RM" << topUp << endl;
								cout << "Your current membership points： " << membershipPoint << endl;
								cout << "Press anykey to continue....." << endl;
								_getch();
								registerUser(username, password, contactNum, customerID, topUp, membershipPoint, membershipStatus);
								system("cls");
								goto RegisterMenu;
							}
						}
						else
						{
							cout << "\n";
							cout << "------------------------------------------------------" << endl;
							cout << "       Invalid input. Please enter only numbers.      " << endl;
							cout << "------------------------------------------------------" << endl;
							cout << "Press enter to try again.....";
							cin.ignore();
							system("cls");
						}
					} while (!notContainAlphabet(contactNum));
				}
				else
				{
					cout << "\n";
					cout << "------------------------------------------------------" << endl;
					cout << "      Invalid name. Please do not enter numbers.      " << endl;
					cout << "------------------------------------------------------" << endl;
					cout << "Press anykey to try again.....";
					cin.ignore();
					system("cls");
				}
			} while (containsDigits(username));
		}
		else if (loginRegChoice == "2")
		{
			string username, password;
			int skipIgnore = 0;

		LoginPage:

			system("cls");
			cout << "\n\n";
			cout << "*     *****   ****  ***** *   *" << endl;
			cout << "*     *   *  *        *   **  *" << endl;
			cout << "*     *   * * *****   *   * * *" << endl;
			cout << "*     *   *  * *  *   *   *  **" << endl;
			cout << "***** *****   *   * ***** *   *" << endl << endl;

			do
			{
				do
				{
					system("cls");
					cout << "\n\n";
					cout << "*     *****   ****  ***** *   *" << endl;
					cout << "*     *   *  *        *   **  *" << endl;
					cout << "*     *   * * *****   *   * * *" << endl;
					cout << "*     *   *  * *  *   *   *  **" << endl;
					cout << "***** *****   *   * ***** *   *" << endl << endl;
					cout << "------------------------------------------------------\n\n";
					cout << "Enter username\t\t\t: ";
					if (skipIgnore == 1)
					{
						cin.ignore();
					}
					getline(cin, username);

					if (!containsDigits(username))
					{
						cout << "\n\n";
						cout << "Enter password\t\t\t: ";
						getline(cin, password);
						cout << "\n\n";
						if (loginUser(username, password))
						{
							cout << "---------------------------------------------" << endl;
							cout << "            Login successfull !!!            " << endl;
							cout << "---------------------------------------------" << endl;
							_getch();
						}
						else
						{
							string retryChoice;

							cout << "---------------------------------------------" << endl;
							cout << "Login failed. Incorrect username or password." << endl;
							cout << "---------------------------------------------" << endl;
							skipIgnore = 1;

							do
							{
								cout << "Press 0 : To Register Page" << endl;
								cout << "Press 1 : To Try Again" << endl;
								cout << "Option : ";
								cin >> retryChoice;

								if (retryChoice == "0")
								{
									system("cls");
									goto RegisterMenu;
								}
								else if (retryChoice == "1")
								{
									system("cls");
									goto LoginPage;
								}
								else
								{
									cout << "---------------------------------------------" << endl;
									cout << "      Invalid choice. Please try again.      " << endl;
									cout << "---------------------------------------------" << endl;
								}
							} while (retryChoice != "0" and retryChoice != "1");
						}
					}
					else
					{
						cout << "------------------------------------------------------" << endl;
						cout << "      Invalid name. Please do not enter numbers.      " << endl;
						cout << "------------------------------------------------------" << endl;
						cout << "Press anykey to try again.....";
						_getch();
						system("cls");
						cin.ignore();
					}
				} while (!loginUser(username, password));
			} while (containsDigits(username));
		}
		else
		{
			cin.ignore();
			cout << "\n";
			cout << "--------------------------------------------" << endl;
			cout << "  Invalid input, please enter 1 or 2 only.  " << endl;
			cout << "--------------------------------------------" << endl;
			cout << "Press enter to try again.....";
			cin.ignore();
			system("cls");
		}
	} while ((loginRegChoice != "1" && loginRegChoice != "2") || (!containsDigits(loginRegChoice)));
}



void userPayment() {
	string creditCardNum, expirationDate, cvv;
	float serviceCharge = 0.1;
	totalPayment = beforeTotal;
afterTopUp:
	system("cls");
	cout << "\n\n";
	cout << "******  ****  *****  ****  *****  ******  *******" << endl;
	cout << "*    *  *     *      *       *    *    *     *   " << endl;
	cout << "* * *   ****  *      ****    *    ******     *   " << endl;
	cout << "*   *   *     *      *       *    *          *   " << endl;
	cout << "*    *  ****  *****  ****  *****  *          *	  " << endl;
	paymentDetails();

	int optionPayment;
	cout << "Payment Amount: RM " << fixed << setprecision(2) << totalPayment << endl << endl;
	cout << "Your Current Balance in your account : RM " << balance << endl << endl;
	cout << "Your Membership Points: " << membershipPoints << endl << endl;
	do {
		cout << "please select option (1) to pay with top up balance press (2) to pay with membership points" << endl;
		cin >> optionPayment;
		if (optionPayment == 1) {
			while (balance < totalPayment)
			{
				cout << "You have not enough balance to proceed the payment.\n";
				cout << "Options: \n";
				cout << "Press 1: To top-up balance\n";
				cout << "Press 2: To pay with membership points\n";
				cout << "Enter your choice: ";

				char balancePointsChoice;
				cin >> balancePointsChoice;

				if (balancePointsChoice == '1')
				{

					char optionAmount;
					system("CLS");
					cout << "Enter top up amount" << endl << "1. RM 5.00\n" << "2. RM 10.00\n" << "3. RM 30.00\n" << "4. RM 50.00\n";
					cout << "Note that RM 0.50 will be deducted from the top up Amount for processing charges " << endl;
					cout << "Select either option (1), (2), (3) or (4): ";
					cin >> optionAmount;
					switch (optionAmount) {
					case '1':
						balance += 4.50;
						break;
					case '2':
						balance += 9.50;
						break;
					case '3':
						balance += 29.50;
						break;
					case '4':
						balance += 49.50;
						break;
					default:
						cout << "You entered an invalid option please enter again" << endl;
						continue;
					}

					cout << "Payment for topup" << endl;
					cout << "-----------------" << endl << endl;
					do {
						cout << "credit card number (16 numbers): ";
						cin >> creditCardNum;
						if (creditCardNum.length() != 16) {
							cout << "You have entered an invalid card number please try again" << endl;
						}
					} while (creditCardNum.length() != 16);
					cout << "example output (12/28)" << endl << "Expiration Date : ";
					cin >> expirationDate;
					do {
						cout << "CVV\t: ";
						cin >> cvv;
						if (cvv.length() != 3)
							cout << "invalid CVV , please try again." << endl;
					} while (cvv.length() != 3);

					cout << "TOPUP SUCCESSFUL!!" << endl;
					cout << "Press any key to continue back to payment" << endl;
					_getch();
					goto afterTopUp;

				}
				else if (balancePointsChoice == '2')
				{
					memberMsg();
					calculationPoints(optionYOrN);
					if (backToPayment == 1)
						goto afterTopUp;
				}
				else
				{
					cout << "Invalid choice. Please try again.\n";
				}
			}
			if (balance >= totalPayment) {
				balance -= totalPayment;
				membershipPoints += totalPayment;
				cout << "Payment successful!" << endl;
				cout << "Top Up Balance has been deducted" << endl;
				cout << "New Balance\t\t:" << balance << endl;
				cout << "New membershipPoints\t:" << membershipPoints << endl;
				cout << "press any key to end " << endl;
				_getch();
			}
		}
		else if (optionPayment == 2) {
			memberMsg();
			calculationPoints(optionYOrN);
			if (backToPayment == 1)
				goto afterTopUp;
		}
		else
			cout << "you have entered invalid input please try again" << endl;
	} while (optionPayment != 1 && optionPayment != 2);
}

void OandSfile() {

	ifstream inFile;
	inFile.open("user.txt", ios::out);

	if (inFile.fail()) {
		cerr << "Error Opening File" << endl;
		exit(1);
	}
	while (!inFile.eof()) {
		getline(inFile, information[lines]);
		lines++;
		if (lines == MAX_LINES) {
			cout << "no more storage" << endl;
			break;
		}
	}
	inFile.close();
}
void storring() {
	storeMembershipPoints(name, pass);
	storeBalance(name, pass);
	memberStatus(name, pass);
	pointsAndBalance();
	memberId = StoreId(name, pass);
}


void writeToFile() {
	information[positionBalanceGlobal] = to_string(balance);
	information[positionPointsGlobal] = to_string(membershipPoints);
	ofstream outFile;
	outFile.open("user.txt", ios::in);
	if (outFile.fail()) {
		cerr << "Error Opening File" << endl;
		exit(1);
	}
	for (int i = 0; i < lines; i++) {
		outFile << information[i] << endl;
	}
	outFile.close();
}

string optionContinue(string optionExit1) {
	cout << "\n\n" << "Do you wish to go back to the main menu " << endl << "Enter (1) to continue" << endl << "Enter any other key to go back to main menu" << endl << "option : ";
	cin >> optionExit;
	return optionExit1;
	system("CLS");
}

void optionTopUp() {
	cout << "MEMBERSHIP CARD TOP UP" << endl;
	cout << "-----------------------------------------------------" << endl;
	cout << "1.Top up " << endl << "2.Check balance" << endl << "press (1) for Top up || press(2) for check balance: ";
	cin >> tOrC;
}

void TopUpBalance() {
	string creditCardNum, expirationDate, cvv, password;
	int correct;
	do {
		string membershipId;
		system("cls");
		cout << "MEMBERSHIP CARD TOP UP" << endl;
		cout << "=======================" << endl;
		cout << "Please Enter Your Membership ID: ";
		cin >> membershipId;
		cout << "Please Enter Your Password: ";
		cin.ignore();
		getline(cin, password);

		if (memberId == membershipId && pass == password)
		{
			correct = 1;
			cout << "Membership Id valid, press any key to continue" << endl;
			_getch();
		}
		else {
			correct = 2;
			cout << "Membership ID or password invalid, please try again" << endl;
			cout << membershipId << endl;
			cout << password << endl;
			cout << memberId << endl;
			cout << pass << endl;
			_getch();
		}
	} while (correct != 1);
	while (true) {
		system("cls");
		optionTopUp();

		if (tOrC == "1") {
			char optionAmount;
			system("CLS");
			cout << "Enter top up amount" << endl << "1. RM 5.00\n" << "2. RM 10.00\n" << "3. RM 30.00\n" << "4. RM 50.00\n";
			cout << "Note that RM 0.50 will be deducted from the top up Amount for processing charges " << endl;
			cout << "Select either option (1), (2), (3) or (4): ";
			cin >> optionAmount;
			switch (optionAmount) {
			case '1':
				balance += 4.50;
				break;
			case '2':
				balance += 9.50;
				break;
			case '3':
				balance += 29.50;
				break;
			case '4':
				balance += 49.50;
				break;
			default:
				cout << "You entered an invalid option please enter again" << endl;
				continue;
			}
			system("cls");
			cout << "Payment for topup" << endl;
			cout << "-----------------" << endl;
			do {
				cout << "credit card number (16 numbers): ";
				cin >> creditCardNum;
				if (creditCardNum.length() != 16) {
					cout << "You have entered an invalid card number please try again" << endl;
				}
			} while (creditCardNum.length() != 16);
			cout << "example output (12/28)" << endl << "Expiration Date : ";
			cin >> expirationDate;
			do {
				cout << "CVV\t: ";
				cin >> cvv;
				if (cvv.length() != 3)
					cout << "invalid CVV , please try again." << endl;
			} while (cvv.length() != 3);

			cout << "TOPUP SUCCESSFUL!!" << endl;


			while (true) {
				cout << "Do you wish to wish to view balance? press (1) to view balance. press (2) to continue to directory: ";
				cin >> optionView;
				if (optionView == 1) {
					cout << "Your balance is\t: RM " << balance << endl;
					cout << "Press anykey to return back to directory" << endl;
					_getch();
					break;
				}

				else if (optionView == 2) {
					cout << "go to directory" << endl;
					break;
				}
				else
					cout << "You entered an invalid option please enter again" << endl;
				continue;
			}
			break;
		}
		else if (tOrC == "2") {
			system("CLS");
			cout << "Your balance is\t: RM " << fixed << setprecision(2) << showpoint << balance << endl;
			cout << "Press anykey to return back to directory" << endl;
			_getch();
			break;
		}
		else {
			system("CLS");
			cout << "You have entered an invalid option please enter valid input" << endl;
			continue;
		}
	}
}

void storeMembershipPoints(string customerUsername, string pass) {
	int positionPoints = 0;
	for (int i = 0; i < lines; i++) {
		if (information[i] == customerUsername && information[i + 5] == pass) {
			system("CLS");
			positionPoints = i;
			break;

		}
	}

	positionPoints += 4;
	positionPointsGlobal = positionPoints;
	stringMembershipPoints = information[positionPoints];
}

void memberStatus(string customerUsername, string pass) {
	int positionofMembershipStatus = 0;
	for (int i = 0; i < lines; i++) {
		if (information[i] == customerUsername && information[i + 5] == pass) {
			system("CLS");
			positionofMembershipStatus = i;
			break;

		}
	}

	positionofMembershipStatus += 6;
	positionofMembershipStatusGlobal = positionofMembershipStatus;
	membershipStatus = information[positionofMembershipStatus];
}

string StoreId(string customerUsername, string pass) {
	int	positionId = 0;
	for (int i = 0; i < lines; i++) {
		if (information[i] == customerUsername && information[i + 5] == pass) {
			system("CLS");
			positionId = i;
			break;

		}
	}

	positionId += 2;
	memberId = information[positionId];
	return memberId;
}
void storeBalance(string customerUsername, string pass) {
	int positionBalance;
	for (int i = 0; i < lines; i++) {
		if (information[i] == customerUsername && information[i + 5] == pass) {
			system("CLS");
			positionBalance = i;
			break;
		}
	}

	positionBalance += 3;
	positionBalanceGlobal = positionBalance;
	balanceString = information[positionBalance];

}

void pointsAndBalance() {
	balance = stod(balanceString);
	membershipPoints = stoi(stringMembershipPoints);


}

void memberMsg() {
	do {
		cout << "Your purchase amount is RM " << fixed << setprecision(2) << totalPayment << endl;
		cout << "one point is RM 0.01 , for example 100 points is equal to RM 1.00 " << endl;
		cout << "Do you wish to pay with membership points? press (1) for yes, press (2) for no" << endl;
		cin >> optionYOrN;
		if (optionYOrN != "1" && optionYOrN != "2")
			cout << "invalid input please try again." << endl;
	} while (optionYOrN != "1" && optionYOrN != "2");

}

void calculationPoints(string optionYOrN) {   // remember to put in membershipPoints

	if (optionYOrN == "1")
		if ((membershipPoints / 100) - totalPayment > 0) {
			membershipPoints -= (totalPayment * 100);
			system("CLS");
			cout << "You have sufficient amount of points . proceeding to deduct points from account" << endl;
			cout << "Payment Successful" << endl;
			cout << "Press any key to end" << endl;
			_getch();
			backToPayment = 0;

		}
		else {
			string optionCOrC;
			do {
				system("CLS");
				cout << "You have insufficient amount of points. Do you wish to cancel the order or purchase using top up amount." << endl;
				cout << "If you wish to proceed with payment press (1) , press (2) to cancel order  : " << endl;
				cin >> optionCOrC;
				if (optionCOrC == "1") {
					cout << "returning to payment page, press any key to continue" << endl;
					_getch();
					backToPayment = 1;
				} //goto here; 

				else if (optionCOrC == "2")
				{
					cout << "press any key to end" << endl;
					_getch();
				}
				else
					cout << "invalid input please try again." << endl;

			} while (optionCOrC != "1" && optionCOrC != "2");
		}
	else if (optionYOrN == "2") {
		cout << "returning to payment page, press any key to continue" << endl;
		_getch();
		backToPayment = 1;
		//goto payment
	}
}


int main() {
	string directoryChoice;

	OandSfile();
	registerModule();
	storring();

directory:
	do
	{
		selectionPage();
		cout << "Option: ";
		cin >> directoryChoice;
		if (directoryChoice == "1")
		{
			MainMenu();
			userPayment();
			break;
		}
		else if (directoryChoice == "2")
		{
			TopUpBalance();
			writeToFile();
			goto directory;

		}
		else if (directoryChoice == "3")
		{
			membersLevel();
			goto directory;
		}
		else if (directoryChoice == "4")
		{
			goto end;
		}
		else
		{
			cout << "\n";
			cout << "------------------------------------------------------" << endl;
			cout << "       Invalid input. Please enter only numbers.      " << endl;
			cout << "------------------------------------------------------" << endl;
			cout << "Press enter to try again.....";
			cin.ignore();
			system("cls");
		}
	} while ((directoryChoice != "1" and directoryChoice != "2" and directoryChoice != "3" and directoryChoice != "4") or !containsDigits(directoryChoice));

	writeToFile();
end:
	thankyouPage();

	return 0;
}