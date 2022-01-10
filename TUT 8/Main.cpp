#include <iostream>
#include <cmath>
#include <string>

using namespace std;

//declare variable arrays
string zeroToNine[] = { "Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
string tenToTwenty[] = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen" };
string tens[] = { "", "", "Twenty", "Thirty", "Fourty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety" };

//declare functions
string numToString(int numDisplay);
string decimalToString(int decimals);

int main()
{
	//declare variables
	string word;
	int letter;

	//display
	cout << "Question 1:" << endl << endl;

	//ask for input
	cout << "Please enter a word with upper or lower case letters: ";
	cin >> word;

	//run as many times as there are letters
	for (int i = 0; i < word.size(); i++)
	{
		//set the variable equal to the letter
		letter = word[i];

		//checks for lower or uppercase then flips it
		if (isupper(letter))
		{
			word[i] = tolower(letter);
		}
		else if(islower(letter))
		{
			word[i] = toupper(letter);
		}

		//prints the changed version
		cout << word[i];
	}

	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	//display
	cout << "\n\n\nQuestion 2:" << endl << endl;

	//declare variables
	double num;

	//runs until a number between 0 and 1 000 000 is inputted
	do
	{
		//asks for input
		cout << "Enter a number between 0 and 1,000,000: ";
		cin >> num;

	} while (num < 0 || num > 999999.99);

	//sets it as an integer
	int numDisplay = (int)num;
	//fins the amount of decimals 
	double decimals = num - numDisplay;
	//multiplies the decimals by 100
	decimals = decimals * 100;
	//sets it as an integer
	decimals = (int)decimals;

	//runs functions to find the number and then inputs them
	cout << numToString(numDisplay) << " Dollars and " << decimalToString(decimals) << " Cents" << endl;

	//stops extra files from appearing
	system("Pause");
}

//runs function declared above
string numToString(int numDisplay)
{
	//if its less than 10 then run
	if (numDisplay < 10)
	{
		//gets number from array
		return zeroToNine[numDisplay];
	}
	//if its less than 20 then run
	else if (numDisplay < 20)
	{
		//subtracts 10 from number than looks for it in the array
		return tenToTwenty[numDisplay - 10];
	}
	//if its less than 100 then run
	else if (numDisplay < 100)
	{
		//calculates to see what number it is
		//if the number is not divisible by 10 then it runs the function again after dividing it to fins the next number
		return tens[numDisplay / 10] + ((numDisplay % 10 != 0) ? " " + numToString(numDisplay % 10) : "");
	}
	//if its less than 1000 then run
	else if (numDisplay < 1000)
	{
		//calculates to see what number it is
		//if the number is not divisible by 100 then it runs the function again after dividing it to fins the next number
		return numToString(numDisplay / 100) + " Hundred" + ((numDisplay % 100 != 0) ? " " + numToString(numDisplay % 100) : "");
	}
	//if its less than 1 000 000 then run
	else if (numDisplay < 1000000)
	{
		//calculates to see what number it is
		//if the number is not divisible by 1000 then it runs the function again after dividing it to fins the next number
		return numToString(numDisplay / 1000) + " Thousand" + ((numDisplay % 1000 != 0) ? " " + numToString(numDisplay % 1000) : "");
	}

	return "";
}

//runs function declared above
string decimalToString(int decimals)
{
	//if its less than 10 then run
	if (decimals < 10)
	{
		//gets number from array
		return zeroToNine[decimals];
	}
	//if its less than 10 then run
	else if (decimals < 20)
	{
		//subtracts 10 from number than looks for it in the array
		return tenToTwenty[decimals - 10];
	}
	//if its less than 100 then run
	else if (decimals < 100)
	{
		//calculates to see what number it is
		//if the number is not divisible by 10 then it runs the function again after dividing it to fins the next number
		return tens[decimals / 10] + ((decimals % 10 != 0) ? " " + decimalToString(decimals % 10) : "");
	}

	return "";
}