#pragma once
#include <iostream>
#include <cmath>
#include <iomanip>


class Input_Interface
{
public:
	void Interface(int* Choice_Holder);
	void Print(float Integrer1, float Integrer2, char Sign);
	void Holder(float Result_Holder);
	void Check_Integrer(float* Integrer1, float* Integrer2);
	void Check_Integrer_Quadratic(float* a, float* b, float* c);
protected:
	float Result; 
};

class Operations :public Input_Interface
{
public:
	void Addition(float Addend1, float Addend2);
	void Subtraction(float Minuend, float Subtrahend);
	void Division(float Dividend, float Divisor);
	void Multiplication(float Factor1, float Factor2);
	void Square_Root(float Rooted_Number);
	void Quadratic_Equation(float a, float b, float c);
};