#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;

/* This functions checks for decimal numbers, if it is entered, will be asked to enter again*/
int decimal_val() {
	double val;
	cin >> val;
	while (val - floor(val))
	{
		cout << "ERROR! Enter a non - decimal (whole) number" << endl;
		cin.clear();
		cin >> val;
	}
	int val_1 = (int)val;
	return val_1;
}

void ReadFraction(int& Num, int& Denom, int& Num2, int& Denom2, int& Num3, int& Denom3, int& Num4, int& Denom4)
/* This function will allow the user to enter four fractions. Also checks for negative numbers */
{
	cout << "Enter the numerator for the first fraction: ";
	Num = decimal_val();
	cout << endl;
	while (Num < 0) {
		cout << "ERROR! Enter a postive and non - decimal number" << endl;
		Num = decimal_val();
		cout << endl;
	}
	cout << "Enter the denominator for the first fraction: ";
	Denom = decimal_val();
	cout << endl;
	while (Denom <= 0) {
		cout << "ERROR! Enter a postive and non - decimal number" << endl;
		Denom = decimal_val();
		cout << endl;
	}


	cout << "Enter the numerator for the second fraction: ";
	Num2 = decimal_val();
	cout << endl;
	while (Num2 < 0) {
		cout << "ERROR! Enter a postive and non - decimal number" << endl;
		Num2 = decimal_val();
		cout << endl;
	}
	cout << "Enter the denominator for the second fraction: ";
	Denom2 = decimal_val();
	cout << endl;
	while (Denom2 <= 0) {
		cout << "ERROR! Enter a postive and non - decimal number" << endl;
		Denom2 = decimal_val();
		cout << endl;
	}


	cout << "Enter the numerator for the third fraction: ";
	Num3 = decimal_val();
	cout << endl;
	while (Num3 < 0) {
		cout << "ERROR! Enter a postive and non - decimal number" << endl;
		Num3 = decimal_val();
		cout << endl;
	}
	cout << "Enter the denominator for the third fraction: ";
	Denom3 = decimal_val();
	cout << endl;
	while (Denom3 <= 0) {
		cout << "ERROR! Enter a postive and non - decimal number" << endl;
		Denom3 = decimal_val();
		cout << endl;
	}


	cout << "Enter the numerator for the fourth fraction: ";
	Num4 = decimal_val();
	cout << endl;
	while (Num4 < 0) {
		cout << "ERROR! Enter a postive and non - decimal number" << endl;
		Num4 = decimal_val();
		cout << endl;
	}
	cout << "Enter the denominator for the fourth fraction: ";
	Denom4 = decimal_val();
	cout << endl;
	while (Denom4 <= 0) {
		cout << "ERROR! Enter a postive and non - decimal number" << endl;
		Denom4 = decimal_val();
		cout << endl;
	}


}

void reduce(int& Num, int& Denom)
/* This function is called after ReadFraction(). This function will
   reduce the two fractions.
   Pre: Two Fractions
   Post: Two reduced fractions */
{
	int i, j;
	j = Num;
	i = Denom;

	for (int x = i * j; x > 1; x--)
	{
		if ((i % x == 0) && (j % x == 0))
		{
			i /= x;
			j /= x;
		}
	}
	cout << Num << "/" << Denom << " is reduced to " << j << "/" << i << endl;

	Denom = i;
	Num = j;
}

void reduce2(int& Num, int& Denom)
// This function reduces it into a full integer and a fraction with smallest magnitudes for the 
// numerator and the denominator.
{
	int mag_num = 0;
	mag_num = Num / Denom;
	int div = 0;
	div = Num % Denom;
	cout << Num << "/" << Denom << " is reduced  to " << mag_num << " and " << div << "/" << Denom << endl;
	cout << endl;

}

int addfractions(int Num, int Denom, int Num2, int Denom2, int& i, int& j, int& sum, int& x, int& y)
/* This function is called after Reduce. This function adds the two
   fractions Reduce() reduced
   Pre: Two Fractions
   Post: One reduced fraction  */
{

	cout << "The sum of " << Num << "/" << Denom << " and " << Num2 << "/" << Denom2 << " is ";
	if (Denom != Denom2)
	{

		y = Denom * Denom2;
		i = Denom2 * Num;
		j = Denom * Num2;
		sum = i + j;
	}
	else
	{
		sum = Num + Num2;
		y = Denom;
	}
	cout << sum << "/" << y << endl;

	reduce(sum, y);
	reduce2(sum, y);

	return sum, y;
}


bool IsGreater(int& Num, int& Denom, int& Num2, int& Denom2)
// This function gives us the returned value is  ‘True” is the 
// first fraction is strictly larger than the second fractionand returns the
// value “false” otherwise.
{
	int a, b = 0;
	a = Num * Denom2;
	b = Num2 * Denom;
	if (a > b) {
		return true;
	}
	else {
		return false;
	}
}

int pwr(int frac, int n)
// This returns the fraction with the power
{
	if (n == 0) {
		return 1;
	}
	else {
		return pow(frac, n);
	}
}

void Fraction_Power(int Num, int Denom, int x)
// Implements power to the fraction
{

	int temp_num = 0;
	int temp_denom = 0;
	temp_denom = pwr(Denom, x);
	temp_num = pwr(Num, x);
	cout << Num << '/' << Denom << " raised to power of " << x << " gives " << temp_num << "/" << temp_denom << endl;
	reduce(temp_num, temp_denom);
	reduce2(temp_num, temp_denom);

}

int main()
{
	char YorN;
	do
	{
		int a, b, Sum, x, y = 0;
		int Num, Denom, Num2, Denom2, Num3, Denom3, Num4, Denom4, Num5, Denom5, Num6, Denom6, Num7, Denom7, Num8, Denom8;

		ReadFraction(Num, Denom, Num2, Denom2, Num3, Denom3, Num4, Denom4);

		reduce(Num, Denom);
		reduce(Num2, Denom2);
		reduce(Num3, Denom3);
		reduce(Num4, Denom4);
		cout << endl;
		cout << endl;

		reduce2(Num, Denom);
		reduce2(Num2, Denom2);
		reduce2(Num3, Denom3);
		reduce2(Num4, Denom4);
		cout << endl;
		cout << endl;

		Num5, Denom5 = addfractions(Num, Denom, Num2, Denom2, a, b, Sum, x, y);
		Num5, Denom6 = addfractions(Num, Denom, Num3, Denom3, a, b, Sum, x, y);
		Num5, Denom7 = addfractions(Num2, Denom2, Num3, Denom3, a, b, Sum, x, y);
		Num5, Denom8 = addfractions(Num2, Denom2, Num4, Denom4, a, b, Sum, x, y);
		cout << endl;
		cout << endl;


		if (IsGreater(Num, Denom, Num2, Denom2) == true)
		{
			cout << Num << "/" << Denom << " is greater than " << Num2 << "/" << Denom2 << endl;
		}
		else 
		{
			cout << Num << "/" << Denom << " is not greater than " << Num2 << "/" << Denom2 << endl;
		}

		if (IsGreater(Num2, Denom2, Num3, Denom3) == true)
		{
			cout << Num2 << "/" << Denom2 << " is greater than " << Num3 << "/" << Denom3 << endl;
		}
		else 
		{
			cout << Num2 << "/" << Denom2 << " is not greater than " << Num3 << "/" << Denom3 << endl;
		}

		if (IsGreater(Num2, Denom2, Num4, Denom4) == true)
		{
			cout << Num2 << "/" << Denom2 << " is greater than " << Num4 << "/" << Denom4 << endl;
		}
		else 
		{
			cout << Num2 << "/" << Denom2 << " is not greater than " << Num4 << "/" << Denom4 << endl;
		}
		if (IsGreater(Num3, Denom3, Num4, Denom4) == true)
		{
			cout << Num3 << "/" << Denom3 << " is greater than " << Num4 << "/" << Denom4 << endl;
		}
		else 
		{
			cout << Num3 << "/" << Denom3 << " is not greater than " << Num4 << "/" << Denom4 << endl;
		}



		int pwr1, pwr2, pwr3, pwr4;
		cout << "Enter power for fraction 1: ";
		cin >> pwr1;
		cout << "Enter power for fraction 2: ";
		cin >> pwr2;
		cout << "Enter power for fraction 3: ";
		cin >> pwr3;
		cout << "Enter power for fraction 4: ";
		cin >> pwr4;

		Fraction_Power(Num, Denom, pwr1);
		Fraction_Power(Num2, Denom2, pwr2);
		Fraction_Power(Num3, Denom3, pwr3);
		Fraction_Power(Num4, Denom4, pwr4);

		cout << "Would you like to restart the program? (y\n) ";
		cin >> YorN;
	} while ((YorN == 'Y') || (YorN == 'y'));

	return(0);
}