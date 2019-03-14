#include <iostream>
#include <cassert>
#include <cctype>
using namespace std;

bool isValidUppercaseStateCode(string stateCode);
string changeToUpper(string& lower);
bool hasCorrectSyntax(string pollData);
int countVotes(string pollData, char party, int& voteCount);

int main() 
{
	int votes;
	string a = "CA50d";
	string b = "FL4RCA30tDC29d";
	string c = "CA";
	string d = "CA 34";
	string e = "HI23";
	string f = "HId30";
	string g = "ZZ20p";
	string h = "";
	string i = "NV425CA34dnY98c";
	string j = "CA72dFl87rnY65dwv76rDC76DRI23iWy56R";
	string k = "a";
	string l = "TX34@";

	//assert(hasCorrectSyntax(a));
	assert(countVotes(a, 'd', votes) == 0 && votes == 50);
	assert(hasCorrectSyntax(b));
	assert(countVotes(b, 't', votes) == 0 && votes == 30);
	votes = -999;
	assert(!hasCorrectSyntax(c));
	assert(countVotes(c, 'd', votes) == 1 && votes == -999);
	assert(!hasCorrectSyntax(d));
	assert(countVotes(d, 'd', votes) == 1);
	assert(!hasCorrectSyntax(e));
	assert(countVotes(e, 'd', votes) == 1);
	assert(!hasCorrectSyntax(f));
	assert(countVotes(f, 'd', votes) == 1);
	assert(!hasCorrectSyntax(g));
	assert(countVotes(g, 'd', votes) == 1);
	assert(hasCorrectSyntax(h));
	assert(countVotes(h, 'd', votes) == 0 && votes == 0);
	assert(!hasCorrectSyntax(i));
	assert(countVotes(i, 'd', votes) == 1);
	assert(hasCorrectSyntax(j));
	assert(countVotes(j, 'd', votes) == 0 && votes == 213);
	assert(countVotes(j, 'r', votes) == 0 && votes == 219);
	assert(!hasCorrectSyntax(k));
	assert(countVotes(k, 'd', votes) == 1);
	assert(!hasCorrectSyntax(l));
	assert(countVotes(l, '@', votes) == 1);

	cout << "All tests succeeded" << endl;
}


// Return true if the argument is a two-uppercase-letter state code, or
// false otherwise.
bool isValidUppercaseStateCode(string stateCode)
{
	const string codes =
		"AL.AK.AZ.AR.CA.CO.CT.DE.DC.FL.GA.HI.ID.IL.IN.IA.KS."
		"KY.LA.ME.MD.MA.MI.MN.MS.MO.MT.NE.NV.NH.NJ.NM.NY.NC."
		"ND.OH.OK.OR.PA.RI.SC.SD.TN.TX.UT.VT.VA.WA.WV.WI.WY";
	return (stateCode.size() == 2 &&
		stateCode.find('.') == string::npos  &&  // no '.' in stateCode
		codes.find(stateCode) != string::npos);  // match found
}

//changes every character in a string to uppercase
string changeToUpper(string& lower) {
	for (int i = 0; i != lower.size(); i++) {
		lower[i] = toupper(lower[i]);
	}
	return lower;
}

bool hasCorrectSyntax(string pollData)
{
	changeToUpper(pollData);
	//return true if pollData has length 0
	if (pollData.size() == 0) 
		return true;
	
	else {
		for (int j = 0; j != pollData.size(); j++) {
			//return false if first two char in state forecast is not a state code
			if (!isValidUppercaseStateCode((pollData.substr(j, 2))))
				return false;

			//return false if there is no digit after the state code 
			else if (!isdigit(pollData[j += 2]))
				return false;

			//counts up to two digits and returns false if the character after is not a letter
			else {
				for (int k = 0; k < 2; k++) {
					if (isdigit(pollData[j]))
						j++;
				}
				if (!isalpha(pollData[j]))
					return false;
			}
		}
	}
	return true;
}

int countVotes(string pollData, char party, int& voteCount) {
	if (!hasCorrectSyntax(pollData))
		return 1;

	else if (!isalpha(party))
		return 3;

	else if (pollData.size() > 0)
		for (int i = 0; i != pollData.size() - 1; i++) {
			if (isalpha(pollData[i]) && pollData[i + 1] == 0)
				return 2;
		}

	voteCount = 0;
	int firstDigit;
	int secDigit;

	//state forecast with 2 digits versus 1 digit
	for (int j = 0; j != pollData.size(); j++) {
		if (isdigit(pollData[j]) && isdigit(pollData[j + 1]) && toupper(pollData[j + 2]) == toupper(party)) {
			firstDigit = pollData[j] - 48;
			secDigit = pollData[j + 1] - 48;
			voteCount += (firstDigit * 10 + secDigit);
			j += 2;

		}
		else if (isdigit(pollData[j]) && toupper(pollData[j + 1]) == toupper(party)) {
			firstDigit = pollData[j] - 48;
			voteCount += firstDigit;

		}
	}
	return 0;
}
