#include "Calculator_Logic.h"

//Holds the result
void Input_Interface::Holder(float Result_Holder)
{
	Result = Result_Holder;
}


//Main interface 
void Input_Interface::Interface(int *Choice_Holder)
{
	std::cout << "==========" << std::endl;
	std::cout << "CALCULATOR" << std::endl;
	std::cout << "==========" << std::endl;
	std::cout << "Choose your operation: " << std::endl;
	std::cout << "(1) Addition" << std::endl;
	std::cout << "(2) Subtraction" << std::endl;
	std::cout << "(3) Division" << std::endl;
	std::cout << "(4) Multiplication" << std::endl;
	std::cout << "(5) Square root" << std::endl;
	std::cout << "(6) Quadratic Equation" << std::endl;
	std::cout << "(0) Exit" << std::endl;
	std::cout << std::endl;
	
	std::cout << "Enter your choice: ";
	std::cin >> *Choice_Holder;
	std::cout << std::endl;
}

//Prints Result
void Input_Interface::Print(float Integrer1, float Integrer2, char Sign)
{
	std::cout << "The result is: ";
	std::cout << std::noshowpos << Integrer1 << Sign << Integrer2 << "=" << Result << std::endl;
}

//Checks integrer
void Input_Interface::Check_Integrer(float *Integrer1, float *Integrer2)
{
	std::cout << "Enter first number: ";
	std::cin >> *Integrer1;

	while (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(1000, '\n');
		std::cout << "Invalid input, try again" << std::endl<<std::endl;

		std::cout << "Enter first number: ";
		std::cin >> *Integrer1;	
	}

	std::cout << "Enter second number: ";
	std::cin >> *Integrer2;

	while (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(1000, '\n');
		std::cout << "Invalid input, try again" << std::endl << std::endl;

		std::cout << "Enter second number: ";
		std::cin >> *Integrer2;
	}
}

//Check input for quadratic
void Input_Interface::Check_Integrer_Quadratic(float *a, float *b, float *c)
{
	std::cout << "a=";
	std::cin >> *a;

	while (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(1000, '\n');

		std::cout << "Invalid input, try again!" << std::endl;
		std::cout << "a=" << std::endl;

		std::cin >> *a;
	}

	std::cout << "b=";
	std::cin >> *b;

	while (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(1000, '\n');

		std::cout << "Invalid input, try again!" << std::endl;
		std::cout << "b=" << std::endl;

		std::cin >> *b;
	}

	std::cout << "c=";
	std::cin >> *c;

	while (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(1000, '\n');

		std::cout << "Invalid input, try again!" << std::endl;
		std::cout << "c=" << std::endl;

		std::cin >> *c;
	}
}

//Operations
void Operations::Addition(float Addend1, float Addend2)
{
	char Plus = '+';
	
	Check_Integrer(&Addend1, &Addend2);
	
	Result = Addend1 + Addend2;
	 
	Print(Addend1, Addend2, Plus);
}

void Operations::Subtraction(float Minuend, float Subtrahend)
{
	char Minus = '-';

	Check_Integrer(&Minuend, &Subtrahend);

	Result = Minuend - Subtrahend;

	Print(Minuend, Subtrahend, Minus );
}

void Operations::Division(float Dividend, float Divisor)
{
	char Division_Sign = '/' ;

	Check_Integrer(&Dividend, &Divisor);

	Result = Dividend / Divisor;

	Print(Dividend, Divisor, Division_Sign);
}

void Operations::Multiplication(float Factor1, float Factor2)
{
	char Multiplication_Sign = '*';

	Check_Integrer(&Factor1, &Factor2);

	Result = Factor1 * Factor2;
	
	Print(Factor1, Factor2, Multiplication_Sign);
}

void Operations::Square_Root(float Rooted_Number)
{
	unsigned char Square_Symbol = 251;
	std::cout << "Enter number:" << std::endl;
	std::cin >> Rooted_Number;

	while (Rooted_Number <= 0 || std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(1000, '\n');

		std::cout << std::endl;
		std::cout << "Invalid input!" << std::endl;
		std::cout << "Number must'n be less or eqaual to 0!" << std::endl;
		std::cout << "Number mustn't contain characters!" << std::endl;
		std::cout << "Enter number: ";
		
		std::cin >> Rooted_Number;
	}

	Result = sqrt(Rooted_Number);

	std::cout << Square_Symbol << std::setprecision(4) << Rooted_Number << " = " << Result << std::endl;
}

void Operations::Quadratic_Equation(float a, float b, float c)
{
	float x1, x2;
	float Diskriminanta;
	float Realen_Del;
	float Imaginaren_Del;

	unsigned char Square_Symbol = 253;
	
	//Inteface
	std::cout << "ax" << Square_Symbol << "+bx" << "+c" << "=0" << std::endl;
	std::cout << "Enter the the values:" << std::endl << std::endl;
	
	//Input
	Check_Integrer_Quadratic(&a, &b, &c);

	std::cout << "The solution of " << a << "x" << Square_Symbol << std::showpos << b << "x" <<std::showpos << c << "=0 ";

	Diskriminanta = (b * b) - 4 * a * c;

	if (Diskriminanta > 0)
	{
		std::cout << "are two real roots." << std::endl;
		
		x1 = (-b + sqrt(Diskriminanta)) / ( 2 * a );
		x2 = (-b - sqrt(Diskriminanta)) / (2 * a);
		
		std::cout << "x1 = " << std::noshowpos << x1 << std::endl;
		std::cout << "x2 = " << std::noshowpos << x2 << std::endl;
	}
	if (Diskriminanta == 0)
	{
		std::cout << "is one real solutions." << std::endl;

		x1 = -b / (2 * a);

		std::cout << "x1 = x2 = " << std::noshowpos << x1 << std::endl;
	}
	if (Diskriminanta < 0)
	{
		Diskriminanta = -((b * b) - 4 * a * c);

		std::cout << "are two complex solutions." << std::endl;

		Realen_Del = b / (2*a);
		Imaginaren_Del = sqrt (Diskriminanta) / (2 * a);
		
		std::cout << "x1 = " << Realen_Del << " + " << Imaginaren_Del << "i" << std::endl;
		std::cout << "x2 = " << Realen_Del << " - " << Imaginaren_Del << "i" << std::endl;
	}
}
