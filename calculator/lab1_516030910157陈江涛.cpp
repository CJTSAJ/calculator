// calculator.cpp : �������̨Ӧ�ó������ڵ㡣
//������
#include "stdafx.h"
#include "std_lib_facilities.h"
#ifndef lab1_h
#define lab1_h

#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
using namespace std;

double R;//ȫ�ֱ���R
const char hold = 'M';
const char number = '8';//�������ֳ���
const char quit = 'q';//���庯��ֹͣ����
const char print = '=', prompt = '>', result = '=';//���峣�� ��ߴ���ɶ���

/*void error(string s)//������һ�������쳣����
{
	throw runtime_error(s);
}*/

int keep_window_open(string s)//�Զ��屣�ִ��ڴ򿪵ĺ���
{
	cout << "please enter " << s << " to exit" << endl;
	string ss;
	while (cin >> ss)
		if (ss == s)return 1;
	return 1;
}

class Token//Token��Ĺ���
{
public:
	char kind;
	double value;
	Token(char ch)//��ĳ�ʼ��
		:kind(ch), value(0) {}
	Token(char ch, double val)
		:kind(ch), value(val) {}
};

class Token_stream//Token��
{
public:
	Token_stream();
	Token get(stringstream& info);//�����ж�ȡ����
	void putback(Token);//���ʷŻ�����
	void ignore(char,stringstream&info);//�쳣���� ����ȡ��һ���ֺ�
private:
	bool full;
	Token buffer;
};

Token_stream::Token_stream()//Ĭ�Ϲ��캯��
	:full(false), buffer(0) {}

void Token_stream::putback(Token t)//�Żغ���
{
	if (full)error("putback() into a full buffer");
	buffer = t;
	full = true;
}

void Token_stream::ignore(char ch,stringstream& info)
{
	if (full&&buffer.kind == ch) {//�ȿ��������Ƿ���';'
		full = false;
		return;
	}
	char c;
	while (info >> c)
		if (c == ch)return;		
}

Token Token_stream::get(stringstream& info)//��Token���ж�һ������
{
	if (full)//�������Ƿ����е���
	{
		full = false;
		return buffer;
	}
	char ch;
	info >> ch;
	switch (ch)
	{
	case print:return Token(ch);//��ӡ
	case quit:return Token(ch);//ֹͣ
	case '+':case'-':case'*':case'/':case '(':case ')':case '!':case 'M':case 'R':
		return Token(ch);
	case '0':case'1':case '2':case'3':case '4':case'5':case'6':case '7':case '8':case'9':
	{
		info.putback(ch);
		double val;
		info >> val;
		return Token(number, val);
	}
	case 'e':
	{
		double val = exp(1);
		return Token(number, val);
	}
	case '��':
	{
		double val = 3.1415926;
		return Token(number, val);
	}
	default:
		error("bad token!\n");
	}
	return 0;
}

Token_stream ts;//����Token��

void clean_mess_up(stringstream& info) //�����쳣������������ignore������
{
	ts.ignore(print,info);
}

double jiech_calculate(double t)
{
	int test = int(t);
	if (test != t)error("the oprand of ! is wrong!\n");
	if (t < 0)error("the oprand of ! is wrong!\n");
	int t_ = 1;
	for (int i = 1; i <= test; i++)
		t_ *= i;
	return t_;
}
double expression(stringstream& info);//��������

double primary(stringstream& info)//�ķ���primary
{
	extern double R;
	Token t = ts.get(info);
	switch (t.kind)
	{
	case '(':
	{
		double d = expression(info);
		t = ts.get(info);
		if (t.kind != ')')error("')' expected!\n");//���û���ҵ���һ�����ţ�����
		Token tt = ts.get(info);
		if (tt.kind == '!')return jiech_calculate(d);
		else ts.putback(tt);
		return d;//����������ļ�����
	}
	case number: {
		Token tt = ts.get(info);
		if (tt.kind == '!') return jiech_calculate(t.value);
		else {
			ts.putback(tt);
			return t.value;
		}
		break;
	}
	case '-'://�����Ĵ���
		return -primary(info);
	case '+':
		return primary(info);
	case 'R':
		return R;
	default:error("primary expected!\n");
	}
}

double term(stringstream&info)
{
	double left = primary(info);
	Token t = ts.get(info);
	while (true)
	{
		switch (t.kind) {
		case '*': 
		{
			left *= primary(info);
			t = ts.get(info);
			break;
		}
		case '/':
		{
			double d = primary(info);
			if (d == 0)error("divide by 0\n");
			left /= d;
			t = ts.get(info);
			break;
		}
		case '%'://ģ����	
		{
			double x = primary(info);
			int x1 = int(left);
			if (x1 != left)error("the left oprand of '%' is not int type\n");
			int x2 = int(x);
			if (x2 != x)error("the right oprand of '%' is not int type\n");
			if (x2 == 0)error("%:divide by 0\n");
			left = x1%x2;
			t = ts.get(info);
			break;
		}
		default:
			ts.putback(t);
			return left;
		}
	}
}

double expression(stringstream &info)
{
	extern double R;
	double left = term(info);
	Token t = ts.get(info);
	while (true) {
		switch (t.kind) {
		case '+':
		{
			left += term(info);
			t = ts.get(info);
			break;
		}
		case '-':
		{
			left -= term(info);
			t = ts.get(info);
			break;
		}
		case 'M':
		{
			t = ts.get(info);
			if (t.kind != print)error("';' expected!\n");
			R = left;
			break;
		}
		default:
		{
			ts.putback(t);
			return left;
		}
		}
	}
}

string calculate(stringstream& info)
{
	Token t = ts.get(info);
	while (t.kind == print)t = ts.get(info);
	if (t.kind == quit)return "";
	ts.putback(t);
	stringstream ss;
	ss << expression(info);
	string s = ss.str();
	return s;
}
/*string calculate()//����һ�����㺯��
{
	while (cin)//��������
	{
		try {
			cout << prompt;
			Token t = ts.get();
			while (t.kind == print)t = ts.get();
			if (t.kind == quit)return;
			ts.putback(t);
			stringstream ss;
			ss << expression();
			return ss.str();
		}
		catch (runtime_error&e) {
			cerr << e.what() << endl;
			clean_mess_up();//�����쳣  ������ȡ
		}
	}
}*/
int main()
{
	try
	{
		calculate();
		keep_window_open("--");
		return 0;
	}
	catch (runtime_error& e)
	{
		cout << "error:" << e.what() << endl;
		keep_window_open("--");
		return 1;
	}
	catch (...)//�����쳣�Ĳ�׽
	{
		cerr << "there is something wrong!\n";
		keep_window_open("--");
		return 2;
	}
}
#endif