#include <iostream>
#include <string>
using namespace std;

int main()
{
	const double FIRST_TWENTY = 20 * 0.181;	// a variable holding the fee for the first 20 million of the expected revenue
	
	string identification;		//creates a variable for the identificaton of the property
	cout << "Identification: ";
	getline(cin, identification);

	double expRevenue;				//creates a variable for the expected revenue 
	cout << "Expected revenue (in millions): ";
	cin >> expRevenue;
	cin.ignore(10000, '\n');

	string country;				//creates a variable for the country the property is lcoated in
	cout << "Country: ";
	getline(cin, country);

	cout << "---" << endl;

	double amount;				//creates the license fee amount
	cout.setf(ios::fixed);
	cout.precision(3);

	if (expRevenue <= 20) 									// for cases where the expected revenue is less than or equal to 20 million
	{
		amount = expRevenue * 0.181;
	}
	else if (expRevenue <= 50)									//for cases where the expected revenue is greater than 20 million and less than or equal to 50 million
	{
		if (country == "UAE" || country == "Turkey")			//for cases where the location of the property is UAE or Turkey
			amount = FIRST_TWENTY + (expRevenue - 20) * 0.217;
		else													//for cases where the location of the property is not located in UAE or Turkey
			amount = FIRST_TWENTY + (expRevenue - 20) * 0.203;
	}
	else														//for cases where the expected revenue is greater than 50 million
	{
		if (country == "UAE" || country == "Turkey")
			amount = FIRST_TWENTY + 30 * 0.217 + (expRevenue - 50) *0.230;
		else
			amount = FIRST_TWENTY + 30 * 0.203 + (expRevenue - 50) *0.230;
	}

	cout << "The license fee for " << identification << " is $" << amount << " million." << endl;
}