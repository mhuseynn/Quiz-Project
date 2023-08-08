#pragma once

#include <random>
HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);


void menu_print(string* arr, int a, int size)
{
	for (size_t i = 0; i < size; i++)
	{
		if (i == a)
			SetConsoleTextAttribute(console, 10);
		else
			SetConsoleTextAttribute(console, 7);

		cout << "\t\t\t\t\t " << arr[i] << endl;
	}
}

void menu_print2(string* arr, int a, string b)
{
	cout << "\t\t\t";
	for (size_t i = 0; i < 4; i++)
	{
		if (i == a)
		{
			SetConsoleTextAttribute(console, 2);
		}
		else if (arr[i] == b)
		{
			SetConsoleTextAttribute(console, 12);
		}
		else
		{
			SetConsoleTextAttribute(console, 7);
		}

		cout << arr[i] << "  ";

	}
	cout << endl << endl;
	for (size_t i = 4; i < 7; i++)
	{
		if (i == a)
		{
			SetConsoleTextAttribute(console, 5);
		}
		else
		{
			SetConsoleTextAttribute(console, 7);
		}

		cout << "\t\t\t" << arr[i] << endl;
	}
}


void delete_quiz_file(const string& quiz_name)
{
	char* name = new char[quiz_name.size() + 5] {};
	strcpy_s(name, quiz_name.size() + 1, quiz_name.c_str());
	name[quiz_name.size()] = '.';
	name[quiz_name.size() + 1] = 't';
	name[quiz_name.size() + 2] = 'x';
	name[quiz_name.size() + 3] = 't';
	if (remove(name) == 0)
		cout << "Quiz file deleted successfully." << endl;
	else
		cout << "Error deleting quiz file." << endl;
}

void create_quiz()
{
	string question, variant1, variant2, variant3, variant4, correct;
	string quiz_name;
	cout << "Quiz name: ";
	getline(cin, quiz_name);
	bool ischeck = true;
	
	ofstream file("allQuiz/" + quiz_name + ".txt");

	if (!file)
	{
		cout << "Error creating the file. Exiting the program." << endl;
		return;
	}
	string* menu = new string[3];
	menu[0] = (" NEW  ");
	menu[1] = (" BACK ");
	menu[2] = (" SAVE ");
	int a = 0;
	int input = 0;
	while (true)
	{
		system("cls");
		menu_print(menu, a, 3);
		input = _getch();
		if (input == 224)
		{
			input = _getch();
			if (input == 72)
			{
				if (a == 0)
				{
					a = 2;
				}
				else
				{
					a--;
				}
			}
			else if (input == 80)
			{
				if (a == 2)
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
			while (true)
			{
				cout << "Enter the question: ";
				getline(cin, question);

				cout << "Enter variant(a): ";
				getline(cin, variant1);

				cout << "Enter variant(b): ";
				getline(cin, variant2);

				cout << "Enter variant(c): ";
				getline(cin, variant3);

				cout << "Enter variant(d): ";
				getline(cin, variant4);


				while (true)
				{
					cout << "Enter correct variant.(a,b,c,d): ";
					getline(cin, correct);
					if (correct == "a")
					{
						break;
					}
					else if (correct == "b")
					{
						break;
					}
					else if (correct == "c")
					{
						break;
					}
					else if (correct == "d")
					{
						break;
					}
					else
					{
						SetConsoleTextAttribute(console, 4);
						cout << "Wrong " << endl;
						SetConsoleTextAttribute(console, 7);
						continue;
					}
				}
				file << question << "|";
				if (correct == "a")
				{
					file << "a)" << variant1 << "|";
				}
				else if (correct == "b")
				{
					file << "b)" << variant2 << "|";
				}
				else if (correct == "c")
				{
					file << "c)" << variant3 << "|";
				}
				else if (correct == "d")
				{
					file << "d)" << variant4 << "|";
				}
				file << "a)" << variant1 << "|";
				file << "b)" << variant2 << "|";
				file << "c)" << variant3 << "|";
				file << "d)" << variant4 << " \n";

				break;
			}
			continue;
		}
		else if (input == 13 && a == 1)
		{
			char choice;
			cout << "Are you sure you want to go back and delete the quiz file? (Y/N): ";
			cin >> choice;
			if (choice == 'Y' || choice == 'y')
			{
				file.close();
				delete_quiz_file(quiz_name);
				cin.ignore();
				break;
			}
			if (choice == 'N' || choice == 'n')
			{
				continue;
			}
		}
		else if (input == 13 && a == 2)
		{
			file.flush();
			ofstream fquiz("Quiz names.txt", ios::app);
			if (!fquiz)
			{
				cout << "Error creating the file. Exiting the program." << endl;
				return;
			}
			fquiz << quiz_name << endl;
			fquiz.close();
			break;
		}
	}
	file.close();
}


void result(vector<string> arr, Data_base base, int& correct, int& falsee, int& pass)
{
	int correct_count = 0;
	int false_count = 0;
	int pass_count = 0;

	for (size_t i = 0; i < base.get_count() - 1; i++)
	{
		if (arr[i] == "")
		{
			pass_count++;
		}
		else if (arr[i] == base.get_questions()[i]->get_correct())
		{
			correct_count++;
		}
		else if (arr[i] != base.get_questions()[i]->get_correct() && arr[i] != "")
		{
			false_count++;
		}

	}
	correct = correct_count;
	falsee = false_count;
	pass = pass_count;
	SetConsoleTextAttribute(console, 3);
	cout << "\n\t\t\t\t" << "Result:";
	cout << "\n\t\t\t\t" << "Correct count-->" << correct_count << endl;
	cout << "\t\t\t\t" << "False count-->" << false_count << endl;
	cout << "\t\t\t\t" << "Pass count-->" << pass_count << endl;
	SetConsoleTextAttribute(console, 7);
}


void updateLeaderboard(string& quiz_name, string& username, int correct_, int false_, int pass_)
{

	ifstream file2("Leader board.txt");
	string quizname, username1;
	int correct_count, false_count, pass_count;
	bool inserted = false;
	ofstream tempFile("Leader board temp.txt");


	while (file2 >> quizname >> username1 >> correct_count >> false_count >> pass_count)
	{
		if (!inserted && correct_ > correct_count)
		{
			tempFile << quiz_name << " " << username << " " << correct_ << " " << false_ << " " << pass_ << endl;
			inserted = true;
		}
		tempFile << quizname << " " << username1 << " " << correct_count << " " << false_count << " " << pass_count << endl;
	}

	if (!inserted)
	{
		tempFile << quiz_name << " " << username << " " << correct_ << " " << false_ << " " << pass_ << endl;
	}

	file2.close();
	tempFile.close();


	remove("Leader board.txt");
	rename("Leader board temp.txt", "Leader board.txt");

	cout << "Leaderboard updated." << endl;
}



void shuffle_questions(Data_base& base)
{
	srand((time(0)));
	int n = base.get_count() - 1;
	for (int i = n - 1; i > 0; i--)
	{
		int j = rand() % (i + 1);
		if (i != j)
		{
			swap(base.get_questions()[i], base.get_questions()[j]);
		}
	}
}

bool is_emptyf(ifstream& pFile)
{
	return pFile.peek() == ifstream::traits_type::eof();
}

void start_quiz(string username)
{
	ifstream fname("Quiz names.txt");

	string name1;
	SetConsoleTextAttribute(console, 6);
	cout << "Quiz names:" << endl;
	if (!is_emptyf(fname))
	{
		while (!fname.eof())
		{
			getline(fname, name1);
			cout << name1 << endl;
		}
		
		fname.close();
	}
	else
	{
		SetConsoleTextAttribute(console, 4);
		cout << "There is no Quiz" << endl;
		SetConsoleTextAttribute(console, 7);
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
		return;
	}

	string quiz_name;
	string question, variant1, variant2, variant3, variant4, correct;
	cout << "Enter quiz name: ";
	getline(cin, quiz_name);
	ifstream file("allQuiz/" + quiz_name + ".txt");
	if (!file)
	{
		cout << "File is not found" << endl;
		system("pause");
		return;
	}

	Data_base base;

	while (!file.eof())
	{
		getline(file, question, '|');
		getline(file, correct, '|');
		getline(file, variant1, '|');
		getline(file, variant2, '|');
		getline(file, variant3, '|');
		getline(file, variant4, '\n');

		Question q(question, correct, variant1, variant2, variant3, variant4);
		base.add(q);
	}

	string* menu2 = new string[7];
	vector<string> selected_variants(base.get_count() - 1);
	int a = 0;
	string b = "";
	int input;
	bool ischeck = false;
	int correct_ = 0, false_ = 0, pass_ = 0;

	shuffle_questions(base);

	for (size_t i = 0; i < base.get_count() - 1; i++)
	{

		while (true)
		{
			menu2[0] = (base.get_questions()[i]->get_variant1());
			menu2[1] = (base.get_questions()[i]->get_variant2());
			menu2[2] = (base.get_questions()[i]->get_variant3());
			menu2[3] = (base.get_questions()[i]->get_variant4());

			menu2[4] = ("Previus");
			menu2[5] = ("Next");
			menu2[6] = ("Submit");

			system("cls");
			SetConsoleTextAttribute(console, 7);
			cout << "\n\n\n\t\t\t";
			SetConsoleTextAttribute(console, 6);
			cout << i + 1 << ")";
			base.get_questions()[i]->show();
			SetConsoleTextAttribute(console, 7);
			menu_print2(menu2, a, b);

			input = _getch();
			if (input == 224)
			{
				input = _getch();
				if (input == 75)
				{
					if (a == 0)
					{
						a = 3;
					}
					else  if (a == 4 || a == 5 || a == 6)
					{
						system("alert");
					}
					else
					{
						a--;
					}
				}
				else if (input == 77)
				{
					if (a == 3)
					{
						a = 0;
					}
					else  if (a == 4 || a == 5 || a == 6)
					{
						system("alert");
					}
					else
					{
						a++;
					}
				}
				else if (input == 72)
				{
					if (a == 0)
					{
						a = 6;
					}
					else if (a == 4)
					{
						a = 0;
					}
					else if (a == 0 || a == 2 || a == 3 || a == 1)
					{
						system("alert");
					}
					else
					{
						a--;
					}
				}
				else if (input == 80)
				{
					if (a == 6)
					{
						a = 0;
					}
					else if (a == 0 || a == 2 || a == 3 || a == 1)
					{
						a = 4;
					}
					else
					{
						a++;
					}
				}
			}
			if (input == 13 && a == 0)
			{
				b = base.get_questions()[i]->get_variant1();
				selected_variants[i] = base.get_questions()[i]->get_variant1();
				continue;
			}
			if (input == 13 && a == 1)
			{
				b = base.get_questions()[i]->get_variant2();
				selected_variants[i] = base.get_questions()[i]->get_variant2();
				continue;
			}
			if (input == 13 && a == 2)
			{
				b = base.get_questions()[i]->get_variant3();
				selected_variants[i] = base.get_questions()[i]->get_variant3();
				continue;
			}
			if (input == 13 && a == 3)
			{
				b = base.get_questions()[i]->get_variant4();
				selected_variants[i] = base.get_questions()[i]->get_variant4();
				continue;
			}
			if (input == 13 && a == 4)
			{
				i = i - 1;
				if (i == -1)
				{
					system("alert");
					i++;
				}
				b = selected_variants[i];
				continue;
			}
			if (input == 13 && a == 5)
			{
				i++;
				if (i == base.get_count() - 1)
				{
					system("alert");
					i--;
				}
				b = selected_variants[i];
				continue;
			}
			if (input == 13 && a == 6)
			{
				system("cls");
				result(selected_variants, base, correct_, false_, pass_);
				break;
			}
		}
		break;
	}

	updateLeaderboard(quiz_name, username, correct_, false_, pass_);

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
