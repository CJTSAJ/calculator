#include "stdafx.h"
#include "Simple_window.h"
#include "Window.h"
#include "Point.h"
#include <sstream>
#include "lab1_516030910157陈江涛.h"
#include <cmath>//cos()sin()sqrt()等数学函数的库

struct calcu_window:Window
{
	calcu_window(Point pt,int width,int height,const string&title);//构造函数
private:
	//输入框的字符串
	string info;
	//控件
	Button zero_button;
	Button one_button;
	Button two_button;
	Button three_button;
	Button four_button;
	Button five_button;
	Button six_button;
	Button seven_button;
	Button eight_button;
	Button nine_button;
	Button pi_button;//圆周率
	Button point_button;//小数点
	Button factorial_button;//阶乘
	Button left_bracket_button;//左括号
	Button right_bracket_button;//右括号
	Button Delete_button;//退位键
	Button plus_button;//加
	Button sub_button;//减
	Button multi_button;//乘
	Button divide_button;//除
	Button result_button;//等于
	Button clean_button;//清零
	Button natural_num_button;//自然对数
	Button M_button;//储存功能M
	Button R_button;//储存功能R
	Out_box input_button;
	Out_box output_button;
	//被调用的函数
	void num0();
	void num1();
	void num2();
	void num3();
	void num4();
	void num5();
	void num6();
	void num7();
	void num8();
	void num9();
	void pi();
	void point();
	void factorial();
	void left_bracket();
	void right_bracket();
	void Delete();
	void plus();
	void sub();
	void multi();
	void divide();
	void clean();
	void result();
	void natural_num();
	void M();
	void R();
	//callback函数
	static void cb_zero(Address, Address);
	static void cb_one(Address, Address);
	static void cb_two(Address, Address);
	static void cb_three(Address, Address);
	static void cb_four(Address, Address);
	static void cb_five(Address, Address);
	static void cb_six(Address, Address);
	static void cb_seven(Address, Address);
	static void cb_eight(Address, Address);
	static void cb_nine(Address, Address);
	static void cb_pi(Address, Address);
	static void cb_point(Address, Address);
	static void cb_factorial(Address, Address);
	static void cb_left_bracket(Address, Address);
	static void cb_right_bracket(Address, Address);
	static void cb_Delete(Address, Address);
	static void cb_plus(Address, Address);
	static void cb_sub(Address, Address);
	static void cb_multi(Address, Address);
	static void cb_divide(Address, Address);
	static void cb_result(Address, Address);
	static void cb_clean(Address, Address);
	static void cb_natural_num(Address, Address);
	static void cb_M(Address, Address);
	static void cb_R(Address, Address);
};

calcu_window::calcu_window(Point pt, int width, int height, const string &title) :
	Window(pt, width, height, title),
	left_bracket_button(Point(0, y_max() - 50), 70, 50, "(", cb_left_bracket),
	right_bracket_button(Point(70, y_max() - 50), 70, 50, ")", cb_right_bracket),
	zero_button(Point(140, y_max() - 50), 70, 50, "0", cb_zero),
	point_button(Point(210, y_max() - 50), 70, 50, ".", cb_point),
	result_button(Point(280, y_max() - 50), 70, 50, "=", cb_result),
	natural_num_button(Point(0, y_max() - 100), 70, 50, "e", cb_natural_num),
	one_button(Point(70, y_max() - 100), 70, 50, "1", cb_one),
	two_button(Point(140, y_max() - 100), 70, 50, "2", cb_two),
	three_button(Point(210, y_max() - 100), 70, 50, "3", cb_three),
	plus_button(Point(280, y_max() - 100), 70, 50, "+", cb_plus),
	factorial_button(Point(0, y_max() - 150), 70, 50, "!", cb_factorial),
	four_button(Point(70, y_max() - 150), 70, 50, "4", cb_four),
	five_button(Point(140, y_max() - 150), 70, 50, "5", cb_five),
	six_button(Point(210, y_max() - 150), 70, 50, "6", cb_six),
	sub_button(Point(280, y_max() - 150), 70, 50, "-", cb_sub),
	pi_button(Point(0, y_max() - 200), 70, 50, "Π", cb_pi),
	seven_button(Point(70, y_max() - 200), 70, 50, "7", cb_seven),
	eight_button(Point(140, y_max() - 200), 70, 50, "8", cb_eight),
	nine_button(Point(210, y_max() - 200), 70, 50, "9", cb_nine),
	multi_button(Point(280, y_max() - 200), 70, 50, "×", cb_multi),
	M_button(Point(0, y_max() - 250), 70, 50, "M", cb_M),
	R_button(Point(70, y_max() - 250), 70, 50, "R", cb_R),
	clean_button(Point(140, y_max() - 250), 70, 50, "C", cb_clean),
	Delete_button(Point(210, y_max() - 250), 70, 50, "←", cb_Delete),
	divide_button(Point(280, y_max() - 250), 70, 50, "÷", cb_divide),
	input_button(Point(x_max() - 200, 0), 200, 50, "input"),
	output_button(Point(x_max() - 200, 50), 200, 50, "output"),
	info("")
{
	attach(left_bracket_button);
	attach(right_bracket_button);
	attach(zero_button);
	attach(point_button);
	attach(result_button);
	attach(natural_num_button);
	attach(one_button);
	attach(two_button);
	attach(three_button);
	attach(plus_button);
	attach(factorial_button);
	attach(four_button);
	attach(five_button);
	attach(six_button);
	attach(sub_button);
	attach(pi_button);
	attach(seven_button);
	attach(eight_button);
	attach(nine_button);
	attach(multi_button);
	attach(M_button);
	attach(R_button);
	attach(clean_button);
	attach(Delete_button);
	attach(divide_button);
	attach(input_button);
	attach(output_button);
}

void calcu_window::cb_zero(Address,Address pw)
{
	reference_to<calcu_window>(pw).num0();
}

void calcu_window::cb_one(Address, Address pw)
{
	reference_to<calcu_window>(pw).num1();
}

void calcu_window::cb_two(Address, Address pw)
{
	reference_to<calcu_window>(pw).num2();
}

void calcu_window::cb_three(Address, Address pw)
{
	reference_to<calcu_window>(pw).num3();
}

void calcu_window::cb_four(Address, Address pw)
{
	reference_to<calcu_window>(pw).num4();
}

void calcu_window::cb_five(Address, Address pw)
{
	reference_to<calcu_window>(pw).num5();
}

void calcu_window::cb_six(Address, Address pw)
{
	reference_to<calcu_window>(pw).num6();
}

void calcu_window::cb_seven(Address, Address pw)
{
	reference_to<calcu_window>(pw).num7();
}

void calcu_window::cb_eight(Address, Address pw)
{
	reference_to<calcu_window>(pw).num8();
}

void calcu_window::cb_nine(Address, Address pw)
{
	reference_to<calcu_window>(pw).num9();
}

void calcu_window::cb_pi(Address, Address pw)
{
	reference_to<calcu_window>(pw).pi();
}

void calcu_window::cb_point(Address, Address pw)
{
	reference_to<calcu_window>(pw).point();
}

void calcu_window::cb_factorial(Address, Address pw)
{
	reference_to<calcu_window>(pw).factorial();
}

void calcu_window::cb_left_bracket(Address, Address pw)
{
	reference_to<calcu_window>(pw).left_bracket();
}

void calcu_window::cb_right_bracket(Address, Address pw)
{
	reference_to<calcu_window>(pw).right_bracket();
}

void calcu_window::cb_Delete(Address, Address pw)
{
	reference_to<calcu_window>(pw).Delete();
}

void calcu_window::cb_plus(Address, Address pw)
{
	reference_to<calcu_window>(pw).plus();
}

void calcu_window::cb_sub(Address, Address pw)
{
	reference_to<calcu_window>(pw).sub();
}

void calcu_window::cb_multi(Address, Address pw)
{
	reference_to<calcu_window>(pw).multi();
}

void calcu_window::cb_divide(Address, Address pw)
{
	reference_to<calcu_window>(pw).divide();
}

void calcu_window::cb_result(Address, Address pw)
{
	reference_to<calcu_window>(pw).result();
}

void calcu_window::cb_clean(Address, Address pw)
{
	reference_to<calcu_window>(pw).clean();
}

void calcu_window::cb_natural_num(Address, Address pw)
{
	reference_to<calcu_window>(pw).natural_num();
}

void calcu_window::cb_M(Address, Address pw)
{
	reference_to<calcu_window>(pw).M();
}

void calcu_window::cb_R(Address, Address pw)
{
	reference_to<calcu_window>(pw).R();
}

void calcu_window::num0()
{
	info += '0';
	input_button.put(info);
	redraw();
}

void calcu_window::num1()
{
	info += '1';
	input_button.put(info);
	redraw();
}

void calcu_window::num2()
{
	info += '2';
	input_button.put(info);
	redraw();
}

void calcu_window::num3()
{
	info += '3';
	input_button.put(info);
	redraw();
}

void calcu_window::num4()
{
	info += '4';
	input_button.put(info);
	redraw();
}

void calcu_window::num5()
{
	info += '5';
	input_button.put(info);
	redraw();
}

void calcu_window::num6()
{
	info += '6';
	input_button.put(info);
	redraw();
}

void calcu_window::num7()
{
	info += '7';
	input_button.put(info);
	redraw();
}

void calcu_window::num8()
{
	info += '8';
	input_button.put(info);
	redraw();
}

void calcu_window::num9()
{
	info += '9';
	input_button.put(info);
	redraw();
}

void calcu_window::pi()
{
	info += 'Π';
	input_button.put(info);
	redraw();
}

void calcu_window::point()
{
	info += '.';
	input_button.put(info);
	redraw();
}

void calcu_window::factorial()
{
	info += '!';
	input_button.put(info);
	redraw();
}

void calcu_window::left_bracket()
{
	info += '(';
	input_button.put(info);
	redraw();
}

void calcu_window::right_bracket()
{
	info += ')';
	input_button.put(info);
	redraw();
}

void calcu_window::Delete()
{
	info=info.substr(0,info.length()-2);
	input_button.put(info);
	redraw();
}

void calcu_window::plus()
{
	info += '+';
	input_button.put(info);
	redraw();
}

void calcu_window::sub()
{
	info += '-';
	input_button.put(info);
	redraw();
}

void calcu_window::multi()
{
	info += '*';
	input_button.put(info);
	redraw();
}

void calcu_window::divide()
{
	info += '/';
	input_button.put(info);
	redraw();
}

void calcu_window::clean()
{
	info = "";
	input_button.put(info);
	output_button.put(info);
	redraw();
}

void calcu_window::result()
{
	info += "=";
	stringstream ss(info);
	string result=calculate(ss);
	output_button.put(result);
	redraw();
}

void calcu_window::natural_num()
{
	info += 'e';
	input_button.put(info);
	redraw();
}

void calcu_window::M()
{
	info += 'M';
	input_button.put(info);
	redraw();
}

void calcu_window::R()
{
	info += 'R';
	input_button.put(info);
	redraw();
}

/*int main()
{
	calcu_window win(Point(100, 100),350, 400, "calculator");
	return gui_main();
}*/