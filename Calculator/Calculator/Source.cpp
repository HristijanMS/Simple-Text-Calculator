#include "Calculator_Logic.h"
#include <iostream>
#include <cstdlib>
#include <cmath>

int main()
{
	//Variables
	float Number1 = 0;
	float Number2 = 0;
	float Number3 = 0;

	int Choice;
	
	//Objects
	Input_Interface Inter_Obj;
	Operations Oper_Obj;

	do
	{
		system("color A");
		system("cls");

		//Interface and input
		Inter_Obj.Interface(&Choice);

		//Checks input
		while (std::cin.fail() || Choice > 6 && Choice != 0)
		{
			system("cls");

			std::cin.clear();
			std::cin.ignore(1000, '\n');

			Inter_Obj.Interface(&Choice);
		}

		//Calling operations functions
		if (Choice == 1)
		{
			std::cout << "Addition!" << std::endl<<std::endl;
			std::cout << "------------" << std::endl << std::endl;

			Oper_Obj.Addition(Number1, Number2);

			std::cout << std::endl;
			std::cout << "------------" << std::endl << std::endl;

			system("PAUSE");
		}
		else if (Choice == 2)
		{
			std::cout << "Subtraction!" << std::endl << std::endl;
			std::cout << "------------" << std::endl << std::endl;

			Oper_Obj.Subtraction(Number1, Number2);

			system("PAUSE");
		}
		else if (Choice == 3)
		{
			std::cout << "Division!" << std::endl << std::endl;
			std::cout << "------------" << std::endl << std::endl;

			Oper_Obj.Division(Number1, Number2);

			std::cout << std::endl;
			std::cout << "------------" << std::endl << std::endl;

			system("PAUSE");
		}
		else if (Choice == 4)
		{
			std::cout << "Multiplication!" << std::endl << std::endl;
			std::cout << "------------" << std::endl << std::endl;

			Oper_Obj.Multiplication(Number1, Number2);

			std::cout << std::endl;
			std::cout << "------------" << std::endl << std::endl;

			system("PAUSE");
		}
		else if (Choice == 5)
		{
			std::cout << "Square root!" << std::endl << std::endl;
			std::cout << "------------" << std::endl << std::endl;

			Oper_Obj.Square_Root(Number1);

			std::cout << std::endl;
			std::cout << "------------" << std::endl << std::endl;

			system("PAUSE");
		}
		else if (Choice == 6)
		{
			std::cout << "Quadratic equation!" << std::endl << std::endl;
			std::cout << "------------" << std::endl << std::endl;

			Oper_Obj.Quadratic_Equation(Number1, Number2, Number3);

			std::cout << std::endl;
			std::cout << "------------" << std::endl << std::endl;

			system("PAUSE");
		}
	}
	while (Choice != 0);
	{
		std::cout << "Goodbye!" << std::endl;

		system("PAUSE");
	}
}
//351 line 