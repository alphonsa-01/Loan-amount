//Name: Alphonsa George
//Assignment:PROG 1203-Homework1 Review
#include<cmath>			//<iomanip> and <locale> need to be added whenever we are formatting floating point data.
#include<iomanip>
#include<iostream>
#include<locale>
#include<string>
//given below are all the function prototypes.
double get_double(std::string prompt);
double get_double_within_range(std::string prompt, double min, double max);
double get_interest_rate(std::string prompt);
double get_interest_rate_within_range(std::string prompt, double min_rate, double max_rate);
int get_integer(std::string prompt);
int get_integer_within_range(std::string prompt, int min_year, int max_year);
double get_payment_amount(double loan_amount, double interest_rate, int no_of_years);



void main()
{
	char again = 'y';
	while (again == 'y' || again == 'Y') {
	
		std::cout.imbue(std::locale("ENGLISH_US")); //cout.imbue is used for the formatting of the outputs
		double loan_amount = get_double_within_range("Enter the loan amount:", 0.0, 1000000.0);
		double  interest_rate = get_interest_rate_within_range("Enter the interest rate:", 0.0, 20.0);
		int no_of_years = get_integer_within_range("Enter the number of years:", 0, 30);
		double payment = get_payment_amount(loan_amount, interest_rate, no_of_years);

		std::cout << std::fixed << std::showpoint << std::setprecision(2); //to keep the output values fixed and with proper precision values
		std::cout << "loan amount is $" << loan_amount << std::endl; //loan amount is with precision value 2,which is 2 decimal places after the decimal point
		std::cout << "interest rate is:" << std::setprecision(1) << interest_rate; std::cout << "%" << std::endl;//interest_rate is with
						//one decimal point and % sign at the end.
		std::cout << "number of years is:" << no_of_years << std::endl; //since this is integer, setprecision() does not effect
		std::cout << "Monthly payment is $" << std::setprecision(2) << payment << std::endl;
		std::cout << "continue?(y/n)" << std::endl;//to check whether we would like to continue or not
		std::cin >> again; //the value we enter goes to again and if is is 'y' or 'Y' it continues else it stops.
	} 
	
}

double get_double(std::string prompt) //function to get the loan amount
{

	std::cout << prompt;
	auto loan_amount = 0.0;
	std::cin >> loan_amount;
	while (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(1024, '\n');
			std::cout << "Invalid decimal value,Try again:" << std::endl;
			std::cout << prompt;
			std::cin >> loan_amount;
		
	}
	
	return loan_amount;
}
double get_double_within_range(std::string prompt, double min, double max) //function to check whether loan amount is in the correct range
{
	auto loan_amount = get_double(prompt);
	while (loan_amount<min || loan_amount>max)
	{
		std::cout << "Loan amount should be between 0 and 1000,000,try again" << std::endl;
		loan_amount = get_double(prompt);
	}
	return loan_amount;
 }


	

double get_interest_rate(std::string prompt) //function to get the interest rate
{
	std::cout << prompt;
	auto interest_rate = 0.0;
	std::cin >> interest_rate;
	while (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(1024, '\n');
		std::cout << "Invalid decimal value,Try again:" << std::endl;
		std::cout << prompt;
		std::cin >> interest_rate;
	}
	return interest_rate;
}

	double get_interest_rate_within_range(std::string prompt, double min_rate, double max_rate)//funtion to check 
		//whether the interest rate is within the applicable range
	{
		auto interest_rate = get_interest_rate(prompt);
		while (interest_rate<min_rate || interest_rate>max_rate)
		{
			std::cout<<"interest rate should be between 0 and 20,try again" << std::endl;
			interest_rate = get_interest_rate(prompt);
		}
		return interest_rate;
	}

	int get_integer(std::string prompt) //function to get the number of years
	{

		std::cout << prompt;
		auto no_of_years = 0;
		std::cin >> no_of_years;
		while (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(1024, '\n');
			std::cout << "Invalid integer value,Try again:"<<std::endl;
			std::cout << prompt;
			std::cin >> no_of_years;

		}

		return no_of_years;
	}
	int get_integer_within_range(std::string prompt, int min_year, int max_year)//function to check whether 
		//the no_of_years is within the applicable range
	{
		auto no_of_years = get_integer(prompt);
		while (no_of_years<min_year || no_of_years>max_year)
		{
			std::cout << "number of years must be between greater than 0 and less than 30" << std::endl;
			no_of_years= get_integer(prompt);
		}
		return no_of_years;
	}

	double get_payment_amount(double loan_amount, double interest_rate, int no_of_years) //funtion to find the monthly payment amount
	{
		double no_of_months = (double)no_of_years * 12.0; //as no_of_months is a double we typecast no_of_years
		double rate = interest_rate / 1200; //interest rate is in annual percentage rate, so we need to divide by 1200
		double payment = loan_amount * rate / (1.0 - (1.0 / powf((1.0 + rate),no_of_months)));
		return payment;
	}
	