

#include<random>
#include<iostream>
#include<iomanip>
#include<string>
#include<conio.h>
#include<ctime>
#include<cstdlib>
#include<fstream>
#include<windows.h>
#pragma warning(disable : 4996;disable : 4018)
using namespace std;
int main();
int g = 0, counter = 0;
class tictactoe {
private:
	int **p;			//double pointer to make dynamic 2D array 
	int size;			//holds the number of rows and columns or dynamically created array
public:
	tictactoe(int Size)		//parametrized constructor because no need to make default constructor
	{
		size = Size;
		int counter = 1;			//variable to assign values 
		p = new int*[size];		//declaring rows
		for (int i = 0; i<size; i++)
		{
			p[i] = new int[size];			//declaring columns
			for (int j = 0; j<size; j++)
			{
				p[i][j] = counter;		//initiallizing the elements of dynamic array
				counter++;
			}
		}
	}
	tictactoe()
	{
		size = 3;
		int counter = 1;			//variable to assign values 
		p = new int*[size];		//declaring rows
		for (int i = 0; i<size; i++)
		{
			p[i] = new int[size];			//declaring columns
			for (int j = 0; j<size; j++)
			{
				p[i][j] = counter;		//initiallizing the elements of dynamic array
				counter++;
			}
		}
	}
	~tictactoe()
	{
		for (int i = 0; i<size; i++)
		{
			delete[]p[i];			//deleting columns
		}
		delete[]p;					//deleting rows
	}
	void output()
	{
		system("cls");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		cout << "\n\t\t\tEnter S/s to save the game\n\t\t\tPress Q/q any time to terminate\n\n";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		cout << "\t\t\tPlayer 1 / Human : ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		cout << "O\n";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		cout << "\t\t\tPlayer 2 / Computer : ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
		cout << "X";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		cout<<"\n\n";
		if (size == 3)				//this check is for printing top border
			cout << "\n\t\t\t ------------------------------\n";
		else if (size == 4)
			cout << "\n\t\t\t ----------------------------------------\n";
		else if (size == 5)
			cout << "\n\t\t\t --------------------------------------------------\n";
		for (int i = 0; i<size; i++)
		{
			cout << "\t\t\t|";
			for (int j = 0; j<size; j++)
			{
				if (p[i][j] == 79 || p[i][j] == 88)				//checking for X and O and printing them from their ascii
				{
					if (p[i][j] == 79)
					{
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
						cout << setw(5) << setw(5) << char(p[i][j]) << setw(5);
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
						cout << '|';
					}
					else if (p[i][j] == 88)
					{
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
						cout << setw(5) << setw(5) << char(p[i][j]) << setw(5);
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
						cout << '|';
					}
				}
				else
					cout << setw(5) << p[i][j] << setw(5) << '|';		//printing simple box number
			}
			if (size == 3)		// again printing horizontal line
				cout << "\n\t\t\t ------------------------------\n";
			else if (size == 4)
				cout << "\n\t\t\t ----------------------------------------\n";
			else if (size == 5)
				cout << "\n\t\t\t --------------------------------------------------\n";
		}
	}

	void input1()			//taking input from player 1
	{
		int ind; string ind1; bool checker = false;
		system("cls");
		output();
		cout << "\n\n\n\t\t\t\tPlayer 1's turn\n\n\t\t\t\t";
		cin >> ind1;
		exit(ind1);
		if (ind1 == "s" || ind1 == "S")
		{
			saveGame(1, 2);
			cout << "game saved\n";
			system("pause");
			main();
		}
		bool val = check_string(ind1);
		if (val == true)
		{
			ind = atoi(ind1.c_str());
			if (ind < 1 || ind>size*size)				//checking for values whether they are beyons the limits
			{
				cout << "invalid entry.. press any key to enter again\n";
				system("pause>>null");
				input1();
			}
			else
			{
				checker = checkPrevious(ind - 1);		//cheking for already exiting values
				if (checker == true)
					setVal(ind - 1, 'O');		//inserting value to array
				else
				{
					cout << "invalid input..Press any key to continue\n";
					system("pause>>null");
					input1();
				}
				output();
				validation('O');	//checking for validation
				input2();
			}
		}
		else
		{
			cout << "you have entered an incorrect value\nPlease enter again\n";
			system("pause");
			input1();
		}
	}
	void input2()		//taking innput from player 2
	{
		int ind; string ind1; bool checker = false;
		system("cls");
		output();
		cout << "\n\n\n\t\t\t\tPlayer 2's turn\n\n\t\t\t\t";
		cin >> ind1;;
		exit(ind1);
		if (ind1 == "s" || ind1 == "S")
		{
			saveGame(2, 2);
			cout << "game saved\n";
			system("pause");
			main();
		}
		bool val = check_string(ind1);
		if (val == true)
		{
			ind = atoi(ind1.c_str());
			if (ind < 1 || ind>size*size)		//checking whether entered values are within limits
			{
				cout << "invalid entry.. press any key to enter again\n";
				system("pause>>null");
				input2();
			}
			else
			{
				checker = checkPrevious(ind - 1);		//chekcing for already existing values
				if (checker == true)
					setVal(ind - 1, 'X');			//innserting values to array
				else
				{
					cout << "invalid input..Press any key to continue\n";
					system("pause>>null");
					input2();
				}
				output();
				validation('X');		//cheking for game win or draw
				input1();
			}
		}
		else
		{
			cout << "you have entered an incorrect value\nPlease enter again\n";
			system("pause");
			input2();
		}
	}
	bool checkPrevious(int index)		//cheking for already existing values
	{
		int check = 0;
		for (int i = 0; i<size; i++)
		{
			for (int j = 0; j<size; j++)
			{
				if (index == check)		//comparing index with the entered value
				{
					if (p[i][j] == 79 || p[i][j] == 88)
						return false;
					else return true;
				}
				else
					check++;
			}
		}
		return false;
	}
	int setVal(int index, char P)		//inserting values to array
	{
		int check = 0;
		for (int i = 0; i<size; i++)
		{
			for (int j = 0; j<size; j++)
			{
				if (index == check)
				{
					p[i][j] = P;
					return 0;
				}
				else
					check++;
			}
		}
		return 0;
	}
	int validation(int y)		//this function check for all kinds of validations
	{
		h_win(y);				//checking for horizontal winning
		v_win(y);				//checking for ertical winning
		d_win(y);				//checking for first diagonal winner
		s_d_win(y);				//checking for other diagonal winning
		bool check = draw();		//cheking wether game drawn or not
		if (check == true)
		{
			cout << "\n\t\t\tgame draw\n";
			again();
		}
		return 0;
	}
	int h_win(int x)		//cheking for horizontal validation
	{
		bool flag = false;
		for (int i = 0; i<size; i++)
		{
			for (int j = 0; j<size - 1; j++)
			{
				if (p[i][j] == x && p[i][j + 1] == x)
				{
					flag = true;
					continue;
				}
				else
				{
					flag = false;
					break;
				}
			}
			if (flag == true)
				win(x);
		}
		return 0;
	}
	int v_win(int x)		//checking for vertical winner
	{
		bool flag = false;
		for (int j = 0; j<size; j++)
		{
			for (int i = 0; i<size - 1; i++)
			{
				if (p[i][j] == x && p[i + 1][j] == x)		//cheking if vertically next and previous indexs are equal to  X or O
				{
					flag = true;
					continue;
				}
				else
				{
					flag = false;
					break;
				}
			}
			if (flag == true)
				win(x);
		}
		return 0;
	}
	int d_win(int x)		//cheking for first diagonal winning
	{
		int j = 0, i = 0;
		bool flag = false;
		while (j<size - 1)
		{
			if (p[i][j] == x && p[i + 1][j + 1] == x)		//checking for i,j and i+1 and j+1 values
			{
				flag = true;
			}
			else
			{
				flag = false;
				return 0;
			}
			i++;
			j++;
		}
		if (flag = true)
			win(x);
		return 0;
	}
	int s_d_win(int x)			//checking for second diagonal winning
	{
		int j = size - 1, i = 0;
		bool flag = false;
		while (i<size - 1)
		{
			if (p[i][j] == x && p[i + 1][j - 1] == x)  //cheking if i,j and i-1,j-1 winning
			{
				flag = true;
			}
			else
			{
				flag = false;
				return 0;
			}
			i++;
			j--;
		}
		if (flag = true)
			win(x);
		return 0;
	}
	bool draw()			//cheking wether game drawn or not
	{
		for (int i = 0; i<size; i++)
		{
			for (int j = 0; j<size; j++)
			{
				if (p[i][j] != 79 && p[i][j] != 88)
				{
					return false;
				}
			}
		}
		return true;
	}
	void win(int n)		//printing winner message
	{
		if (n == 79)
		{
			cout << "Player 1 wins\n";
		}
		else
		{
			if (g == 1)
				cout << "computer wins\n";
			else
				cout << "Player 2 wins\n";
		}
		again();
	}

	void again()		//asking user if he/she wants to play again
	{
		char c;
		cin.ignore();
		cout << "\n\t\t\tdo you want to play again(Y/N)\n\n\t\t\t\t";
		c = getch();;
		if (c == 'Y' || c == 'y')		//if yes ,call main to start again
			main();
		else if (c == 'N' || c == 'n')		//if no exit the program
		{
			cout << "\n\t\t\tthanks for playing this game\n";
			exit(0);
		}
		else		//else print error message and ask user if he want to play again
		{
			cout << "\n\t\t\tplease select a correct option\n";
			again();
		}
	}
	void human()			//taking input from player 1
	{
		int ind; string ind1; bool checker = false;
		system("cls");
		output();
		cout << "\n\n\n\t\t\t\tEnter a value\n\n\t\t\t\t";
		cin >> ind1;			//checking for values whether they are beyons the limits
		exit(ind1);
		if (ind1 == "S" || ind1 == "s")
		{
			saveGame(1, 1);
			cout << "game saved\n";
			system("pause");
			main();
		}
		bool val = check_string(ind1);
		if (val == true)
		{
			ind = atoi(ind1.c_str());
			if (ind < 1 || ind>size*size)				//checking for values whether they are beyons the limits
			{
				cout << "invalid entry.. press any key to enter again\n";
				system("pause>>null");
				human();
			}
			else
			{
				checker = checkPrevious(ind - 1);		//cheking for already exiting values
				if (checker == true)
					setVal(ind - 1, 'O');		//inserting value to array
				else
				{
					cout << "invalid input..Press any key to continue\n";
					system("pause>>null");
					human();
				}
				output();
				validation('O');	//checking for validation
				computer();
			}
		}
		else
		{
			cout << "you have entered an incorrect value\nPlease enter again\n";
			system("pause");
			human();
		}

	}
	void computer()		//taking innput from player 2
	{
		bool checker = false;
		setIND();		//DECIDING THE INPUT values for computer
		output();
		validation('X');
		human();
	}
	friend bool check_string(string str);
	int setIND()
	{
		int count = 0, check = 0, k = 0, l = 0;
		bool flag = false;
		for (int i = 0; i<size; i++)		//this loop is checking the values to be assigned for computer winner horizontally
		{
			count = 0; check = 0; flag = false;
			for (int j = 0; j<size; j++)
			{
				if (p[i][j] == 'X')
				{
					count++;
				}
				else if (p[i][j] == 'O')
				{
					flag = false;
				}
				else if (p[i][j] != 'X' && p[i][j] != 'O')
				{
					flag = true;
					k = i; l = j;
				}
			}
			if (count == size - 1 && flag == true)
			{
				p[k][l] = 'X';
				return 0;
			}
		}

		for (int i = 0; i<size; i++)		//this loop is checking the values to be assigned for computer winner vertically
		{
			count = 0; check = 0; flag = false;
			for (int j = 0; j<size; j++)
			{
				if (p[j][i] == 'X')
				{
					count++;
				}
				else if (p[j][i] == 'O')
				{
					flag = false;
				}
				else if (p[j][i] != 'X' && p[j][i] != 'O')
				{
					flag = true;
					k = j; l = i;
				}
			}
			if (count == size - 1 && flag == true)
			{
				p[k][l] = 'X';
				return 0;
			}
		}
		int i = 0, j = 0;
		count = 0;
		while (i<size)			//checking for first diagonal values to make computer a winner
		{
			if (p[j][i] == 'X')
			{
				count++;
			}
			else if (p[j][i] == 'O')
			{
				flag = false;
			}
			else if (p[j][i] != 'X' && p[j][i] != 'O')
			{
				flag = true;
				k = j; l = i;
			}
			i++; j++;
		}
		if (count == size - 1 && flag == true)
		{
			p[k][l] = 'X';
			return 0;
		}
		j = size - 1; i = 0; flag = false;
		count = 0;
		while (i<size)				//checking for second diagonal values to make computer a winner
		{
			if (p[i][j] == 'X')
			{
				count++;
			}
			else if (p[i][j] == 'O')
			{
				flag = false;
			}
			else if (p[i][j] != 'X' && p[i][j] != 'O')
			{

				flag = true;
				k = i; l = j;
			}
			i++; j--;
		}
		if (count == size - 1 && flag == true)
		{
			p[k][l] = 'X';
			return 0;
		}
		for (int i = 0; i<size; i++)			//decideing the values for the computer to stop the player from winning horizontaly
		{
			count = 0; check = 0; flag = false;
			for (int j = 0; j<size; j++)
			{
				if (p[i][j] == 'O')
				{
					count++;
				}
				else if (p[i][j] == 'X')
				{
					flag = false;
				}
				else if (p[i][j] != 'X' && p[i][j] != 'O')
				{
					flag = true;
					k = i; l = j;
				}
			}
			if (count == size - 1 && flag == true)
			{
				p[k][l] = 'X';
				return 0;
			}
		}

		for (int i = 0; i<size; i++)		//decideing the values for the computer to stop the player from winning vertically
		{
			count = 0; check = 0; flag = false;
			for (int j = 0; j<size; j++)
			{
				if (p[j][i] == 'O')
				{
					count++;
				}
				else if (p[j][i] == 'X')
				{
					flag = false;
				}
				else if (p[j][i] != 'X' && p[j][i] != 'O')
				{
					flag = true;
					k = j; l = i;
				}
			}
			if (count == size - 1 && flag == true)
			{
				p[k][l] = 'X';
				return 0;
			}
		}
		i = 0, j = 0;
		count = 0;
		while (i<size)			//checking the first diagonal and if the player is winning decide the value for the cmoputer to stop him from winning
		{
			if (p[j][i] == 'O')
			{
				count++;
			}
			else if (p[j][i] == 'X')
			{
				flag = false;
			}
			else if (p[j][i] != 'X' && p[j][i] != 'O')
			{
				flag = true;
				k = j; l = i;
			}
			i++; j++;
		}
		if (count == size - 1 && flag == true)
		{
			p[k][l] = 'X';
			return 0;
		}
		j = size - 1; i = 0; flag = false;
		count = 0;
		while (i<size)		//checking the second diagonal and if the player is winning decide the value for the cmoputer to stop him from winning
		{
			if (p[i][j] == 'O')
			{
				count++;
			}
			else if (p[i][j] == 'X')
			{
				flag = false;
			}
			else if (p[i][j] != 'X' && p[i][j] != 'O')
			{

				flag = true;
				k = i; l = j;
			}
			i++; j--;
		}
		if (count == size - 1 && flag == true)
		{
			p[k][l] = 'X';
			return 0;
		}
		while (true)		//if all of the above conditions are false decide any random value for the computer
		{
			random_device rd; // obtain a random number from hardware
			mt19937 eng(rd()); // seed the generator
			uniform_int_distribution<> distr(0, size*size);
			check = distr(eng);
			if (check<0 || check>size*size - 1)
			{
				continue;
			}
			bool checker = checkPrevious(check);		//chekcing for already existing values
			if (checker == true)
			{
				setVal(check, 'X');			//innserting values to array
				break;
			}
		}
		return 0;
	}
	void saveGame(int player, int mode)			//this function is being used to save the current state of the game if it is called
	{
		const time_t t = time(0);
		ofstream out1("time.txt", ios::app);		//saving time and game mode and turn of current player in this file
		out1 << asctime(localtime(&t)) << player << ' ' << mode << '\n';
		out1.close();
		ofstream out2("array.txt", ios::app);		//saving the contents of array and array size in this file
		out2 << size << ' ';
		for (int i = 0; i<this->size; i++)
		{
			for (int j = 0; j<size; j++)
			{
				out2 << p[i][j] << ' ';
			}
		}
		out2 << '\n';
		out2.close();
	}
	void setSize(int size)			//setting the size if the size of the object is different from the array which is read from the file
	{
		this->size = size;
	}
	void setValues(int i, int j, int value)		//functin being used to set the values read from the file
	{
		p[i][j] = value;
	}
	tictactoe loadGame(int val)		//this function is reading array contents from the file
	{
		ifstream in("array.txt");
		string jawad;

		for (int j = 0; j < val - 1; j++)
		{
			getline(in, jawad);
		}
		int size1;
		in >> size1;
		this->setSize(size1);
		delete[]p;				//deleting old pointer,,,,,i have not deleted columns as they will be over written automatically
		p = new int*[size];
		int value;
		for (int i = 0; i<size; i++)
		{
			p[i] = new int[size];
			for (int j = 0; j<size; j++)
			{
				in >> value;
				setValues(i, j, value);
			}
		}
		in.close();
		return 0;
	}
	friend void exit(string);
};

void menu()		//printing menu to get user choice
{
	system("cls");
	cout << "Press q at any point to terminate\n\n1 : 3x3 box\n2 : 4x4 box\n3 : 5x5 box\nSelect an option to continue : ";
}

void showGames()
{
	ifstream in1("time.txt");
	ifstream in2("array.txt");
	int i = 1;
	string val;
	if (!in1 || !in2)		//cheking id the file does not exists
	{
		cout << "File does not exists\n";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		remove("array.txt");
		remove("time.txt");
		main();
	}
	in2.close();
	while (getline(in1, val))		//printing saved times
	{
		cout << i << " : " << val << '\n';
		i++;
		getline(in1, val);
		counter++;
	}
	in1.close();
	if (counter == 0)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		cout << "sorry the file is empty\n";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		system("pause");
		main();
	}
}
int readTurn(int val1)				//cheking for player's turn wither player 1 was playing or player 2 was playing
{
	ifstream in1("time.txt");
	int i = 0;
	string val;
	for (int j = 0; j < val1 * 2 - 1; j++)
		getline(in1, val);
	in1 >> i;
	return i;
	in1.close();
}
int readMode(int val1)				//cheacking whether game was computer vs computer or human vs human
{
	ifstream in1("time.txt");
	int i = 0;
	string val;
	for (int j = 0; j < val1 * 2 - 1; j++)
		getline(in1, val);
	in1 >> i;
	in1 >> i;
	return i;
	in1.close();
}
void delete_record(int opt)		//function being used to delete the record on a specific time if user want to delete that record
{
	string value;
	int ch = 1;
	ifstream in1("array.txt");		//reading array content from the first file
	ifstream in2("time.txt");		//reading time and turn data from the 2nd file
	ofstream out1("temp1.txt");		//this file is being used to store the temporary data of contents of array
	ofstream out2("temp2.txt");		//this file is being used to store time and players turn and game mode temporarily
	while (!in1.eof())
	{
		if (opt == ch)
		{
			getline(in1, value);		
			ch++;
			continue;
		}
		getline(in1, value);	//reading the content of array line by line from file 1
		out1 << value;			//saving that previously read data into temporarily created file
		if (!in1.eof())
		{
			out1 << '\n';
		}
		ch++;
	}
	in1.close();
	out1.close();
	ch = 1;
	while (!in2.eof())
	{
		if (opt == ch)
		{
			getline(in2, value);		//reading time from one line
			getline(in2, value);		//reading players turn and game mode from 2nd line
			ch++;
			continue;
		}
		getline(in2, value);
		out2 << value;
		if (!in2.eof())
		{
			out2 << '\n';
		}
		getline(in2, value);
		out2 << value;
		if (!in2.eof())
		{
			out2 << '\n';
		}
		ch++;
	}
	in2.close();
	out2.close();
	remove("array.txt");		//removing old array file
	remove("time.txt");			//removing old time file
	rename("temp1.txt", "array.txt");	//renaming newly created file to old name of array file
	rename("temp2.txt", "time.txt");	//renaming newly created file to old name of time file
}
void exit(string s)
{
	if (s == "q" || s == "Q")
		exit(0);
}
bool check_string(string str)
{
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] < '0' || str[i]>'9')
			return false;
	}
	return true;
}
int main()
{
	system("cls");
	string choice, option;
	int choice1=0, option1=0;
	tictactoe obj(3);
	cout << "wlecome to tic tac toe game\n\nPress q at any point to terminate\n\n";
	cout << "Select an option\n1 : Load Previous game\n2 : Delete record\n3 : Start new game\n";
	cin >> choice;
	exit(choice);
	bool val = check_string(choice);
	if (val == true && choice == "1" || choice == "2" || choice == "3")
	{
		choice1 = atoi(choice.c_str());
		if (choice1 == 1)		//cheking if the choice is 1(49 is the ascii of 1)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
			showGames();
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			again:
			cout << "Enter your choice : \n";
			cin >> choice;
			exit(choice);
			bool val = check_string(choice);
			if (val == true)
			{
				choice1 = atoi(choice.c_str());
				if (choice1<0 || choice1 > counter)		//cheking for the invalid input
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
					cout << "invalid selection select again\n";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
					goto again;
				}
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				obj.loadGame(choice1);		//loading the game from the file
				int turn = readTurn(choice1);	//reading the players turn from the file
				int mode = readMode(choice1);	//reading game mode (computer vs human or human vs human)
				if (mode == 1)				//calling respective function
				{
					g = 1;
					obj.human();
				}
				else if (mode == 2)
				{
					g = 0;
					if (turn == 1)
					{
						obj.input1();
					}
					else
						obj.input2();
				}
			}
			else
				goto again;
		}
		else if (choice1 == 2)			//cheking if the choice was 2(50 is the ascii of 2)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
			showGames();				//printing the saved games time
		again1:
			cout << "Enter a value to delete the record\n";
			cin >> choice;
			exit(choice);
			bool val = check_string(choice);
			if (val == true)
			{
				choice1 = atoi(choice.c_str());
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
				if (choice1 <= 0 || choice1 > counter)
				{
					cout << "invalid selection select again\n";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
					counter = 0;
					goto again1;
				}
				delete_record(choice1);
				cout << "Record deleted\n";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				counter = 0;
				system("pause");
				main();
			}
			else
				goto again1;
		}
		else if (choice1 == 3)			//cheking if the choice is 3(ascii of 3 is 51)
		{
			again2:
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
			cout << "Select an option\n1 : human vs computer\n2 : human vs human\n";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			cin >> option;
			exit(option);
			bool val = check_string(option);
			if (val == true)
			{
				option1 = atoi(option.c_str());
				while (option1 <= 0 || option1 > 2)
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
					cout << "please select a valid option\n";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
					cin >> option;
					option1 = atoi(option.c_str());
				}
				again4:
				menu();
				cin >> choice;	//taking input from user
				exit(choice);
				val = check_string(choice);
				if (val == true)
				{
					choice1 = atoi(choice.c_str());
					while (choice1 <= 0 || choice1 > 3)
					{
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
						cout << "please select a valid option\n";
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
						cin >> choice;
						exit(choice);
					}
					tictactoe obj1(choice1 + 2);		//making the object according to choice
					obj1.output();
					if (option1 == 1)
					{
						g = 1;
						obj1.human();
					}
					else
					{
						g = 0;
						obj1.input1();
					}
				}
				else
					goto again4;
			}
			else
				goto again2;
		}
		
	}
	else
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		cout << "sorry you have entered an invalid option.";
		system("pause");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		main();
	}
}
