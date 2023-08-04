#include<iostream>
#include<conio.h>
#include<Windows.h>
#include<string>
#include<fstream>
#include <vector>
#include<time.h>
#include<algorithm>
using namespace std;
#include"Classes.h"
#include"Functions.h"




int main()
{

	string admin_name = "admin";
	string admin_passw = "admin";
	string* menu = new string[2];
	menu[0] = "Admin";
	menu[1] = "Guest";



	string* mymenu_admin = new string[5];

	mymenu_admin[0] = string{ "     Create Quiz" };
	mymenu_admin[1] = string{ "     Start Quiz" };
	mymenu_admin[2] = string{ " Leader Board(Top 10)" };
	mymenu_admin[3] = string{ "        EXIT" };
	mymenu_admin[4] = string{ "        Back" };



	string* mymenu_guest = new string[4];
	mymenu_guest[0] = string{ "     Start Quiz" };
	mymenu_guest[1] = string{ " Leader Board(Top 10)" };
	mymenu_guest[2] = string{ "        EXIT" };
	mymenu_guest[3] = string{ "        Back" };

	int input;
	int a = 0;
	bool ischeck = false;
	while (true)
	{
		system("cls");
		SetConsoleTextAttribute(console, 1);
		cout << R"(

                                   ____ ____ ____ ____ 
                                  ||Q |||u |||i |||z ||
                                  ||__|||__|||__|||__||
                                  |/__\|/__\|/__\|/__\|
                                  								       
)";


		menu_print(menu, a, 2);
		input = _getch();
		if (input == 224)
		{
			input = _getch();

			if (input == 72)
			{
				if (a == 0)
				{
					a = 3;
				}
				else
				{
					a--;
				}
			}
			else if (input == 80)
			{
				if (a == 3)
				{
					a = 0;
				}
				else
				{
					a++;
				}
			}

		}
		if (input == 13 && a == 0)
		{
			system("cls");
			string name, password;
			cout << "\n\n\n\t\t\t\t\t" << "Admin name: ";
			cin >> name;
			cout << "\t\t\t\t\t" << "Admin password: ";
			cin >> password;
			while (true)
			{
				if (name == admin_name && password == admin_passw)
				{
					break;
				}
				else
				{
					system("cls");
					SetConsoleTextAttribute(console, 4);
					cout << "\n\t\t\t\t\tWrong password or name.Try again";
					SetConsoleTextAttribute(console, 7);
					cout << "\n\t\t\t\t\t" << "Admin name: ";
					cin >> name;
					cout << "\t\t\t\t\t" << "Admin password: ";
					cin >> password;

				}
			}
			cin.ignore();
			while (true)
			{
				system("cls");
				SetConsoleTextAttribute(console, 1);
				cout << R"(
                
                
                 .----------------. .----------------. .----------------. .----------------. 
                | .--------------. | .--------------. | .--------------. | .--------------. |
                | |    ___       | | | _____  _____ | | |     _____    | | |   ________   | |
                | |  .'   '.     | | ||_   _||_   _|| | |    |_   _|   | | |  |  __   _|  | |
                | | /  .-.  \    | | |  | |    | |  | | |      | |     | | |  |_/  / /    | |
                | | | |   | |    | | |  | '    ' |  | | |      | |     | | |     .'.' _   | |
                | | \  `-'  \_   | | |   \ `--' /   | | |     _| |_    | | |   _/ /__/ |  | |
                | |  `.___.\__|  | | |    `.__.'    | | |    |_____|   | | |  |________|  | |
                | |              | | |              | | |              | | |              | |
                | '--------------' | '--------------' | '--------------' | '--------------' |
                 '----------------' '----------------' '----------------' '----------------' 
                
                         )";
				SetConsoleTextAttribute(console, 7);
				int input2;
				cout << endl;
				menu_print(mymenu_admin, a, 5);
				input2 = _getch();
				if (input2 == 224)
				{
					input2 = _getch();
					if (input2 == 72)
					{
						if (a == 0)
						{
							a = 4;
						}
						else
						{
							a--;
						}
					}
					else if (input2 == 80)
					{
						if (a == 4)
						{
							a = 0;
						}
						else
						{
							a++;
						}
					}

				}
				if (input2 == 13 && a == 0)
				{
					system("cls");
					create_quiz();
				}
				if (input2 == 13 && a == 1)
				{
					system("cls");
					string username;
					cout << "Username: ";
					cin >> username;
					cin.ignore();
					start_quiz(username);
				}
				if (input2 == 13 && a == 2)
				{
					system("cls");
					ifstream file("Leader board.txt", ios::in);

					if (!file)
						throw exception("File is not found");

					if (!file.is_open())
						throw exception("file could not be opened");
					string data;
					cout << "Quiz name|Username|correct|false|pass" << endl;
					while (!file.eof())
					{
						getline(file, data);
						cout << data << endl;
					}
					char g;
					cout << "Back[b]";
					g = _getch();
					while (true)
					{
						if (g == 'b')
							break;
						else
						{
							system("alert");
							cout << "Back[b]";
							g = _getch();
						}
					}
				}
				if (input2 == 13 && a == 3)
				{
					delete[] mymenu_guest;
					delete[] mymenu_admin;
					delete[] menu;
					break;
				}
				if (input2 == 13 && a == 4)
				{
					ischeck = true;
					break;
				}
			}
			if (ischeck)
			{
				a = 0;
				ischeck = false;
				continue;
			}
			break;
		}
		if (input == 13 && a == 1)
		{
			a = 0;
			while (true)
			{
				system("cls");
				SetConsoleTextAttribute(console, 1);
				cout << R"(
					                
                                        ____   __    _______ ______   
                                       / __ \  ) )  ( (_   _(____  )  
                                      / /  \ \( (    ) )| |     / /   
                                     ( (    ) )) )  ( ( | | ___/ /_   
                                     ( (  /\) ( (    ) )| |/__  ___)  
                                      \ \_\ \/ ) \__/ (_| |__/ /____  
                                       \___\ \_\______/_____(_______) 
                                            \__)                      
)";
				SetConsoleTextAttribute(console, 7);
				int input2;
				cout << endl;
				menu_print(mymenu_guest, a, 4);
				input2 = _getch();
				if (input2 == 224)
				{
					input2 = _getch();
					if (input2 == 72)
					{
						if (a == 0)
						{
							a = 3;
						}
						else
						{
							a--;
						}
					}
					else if (input2 == 80)
					{
						if (a == 3)
						{
							a = 0;
						}
						else
						{
							a++;
						}
					}

				}
				if (input2 == 13 && a == 0)
				{
					system("cls");
					string username;
					cout << "Username: ";
					cin >> username;
					cin.ignore();
					start_quiz(username);
				}
				if (input2 == 13 && a == 1)
				{
					system("cls");
					ifstream file("Leader board.txt", ios::in);

					if (!file)
						throw exception("File is not found");

					if (!file.is_open())
						throw exception("file could not be opened");
					string data;
					cout << "Quiz name|Username|correct|false|pass" << endl;
					while (!file.eof())
					{
						getline(file, data);
						cout << data << endl;
					}
					char g;
					cout << "Back[b]";
					g = _getch();
					while (true)
					{
						if (g == 'b')
							break;
						else
						{
							system("alert");
							cout << "Back[b]";
							g = _getch();
						}
					}
				}
				if (input2 == 13 && a == 2)
				{
					delete[] mymenu_guest;
					delete[] mymenu_admin;
					delete[] menu;
					break;
				}
				if (input2 == 13 && a == 3)
				{
					ischeck = true;
					break;
				}


			}
			if (ischeck)
			{
				a = 0;
				ischeck = false;
				continue;
			}
			break;
		}
	}

}