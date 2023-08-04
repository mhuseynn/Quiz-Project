#pragma once
#include <cassert>




class Question
{
	string _question;
	string _correct_var;
	string _variant1;
	string _variant2;
	string _variant3;
	string _variant4;
public:
	
	Question(string question, string correct, string variant1, string variant2, string variant3, string variant4)
	{
		set_question(question);
		set_correct(correct);
		_variant1 = variant1;
		_variant2 = variant2;
		_variant3 = variant3;
		_variant4 = variant4;
	}

	string get_question() const { return _question; }
	string get_correct()  const { return _correct_var; }
	string get_variant1() const { return _variant1; }
	string get_variant2() const { return _variant2; }
	string get_variant3() const { return _variant3; }
	string get_variant4() const { return _variant4; }

	void set_question(string question)
	{
		if (question.size() >= 0)
		{
			_question = question;
		}
		else
			throw exception("Correct variant size is wrong");
	}
	void set_correct(string correct)
	{
		if (correct.size() >= 0)
		{
			_correct_var = correct;
		}
		else
			throw exception("Correct variant size is wrong");
	}

	void show()
	{
		cout << _question << endl << endl;
	}
};


class Data_base
{
	Question** _questions;
	int _count;
public:
	Data_base()
	{
		_questions = nullptr;
		_count = 0;
	}

	int get_count()const { return _count; }
	Question** get_questions() { return _questions; }

	void add(Question question)
	{
		Question** newarr = new Question * [_count + 1];
		for (size_t i = 0; i < _count; i++)
		{
			newarr[i] = _questions[i];
		}
		newarr[_count] = new Question(question.get_question(), question.get_correct(), question.get_variant1(), question.get_variant2(), question.get_variant3(), question.get_variant4());
		delete[] _questions;
		_count++;
		_questions = newarr;
	}


};

