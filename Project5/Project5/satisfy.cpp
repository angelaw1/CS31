#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cctype>
#include <cstring>
#include <cassert>
using namespace std;

const int MAX_WORD_LENGTH = 20;
const int MAX_DOC_LENGTH = 200;

void changeToLower(char arr[]);
void shiftUp(char arr[][MAX_WORD_LENGTH + 1], int startPos, int endPos);
void shiftUp(int arr[], int startPos, int endPos); \
int normalizeRules(char word1[][MAX_WORD_LENGTH + 1],
	char word2[][MAX_WORD_LENGTH + 1],
	int distance[],
	int nRules);
bool isMatch(char arr1[], const char arr2[], int startPos);
bool isWithinRange(char arr1[], const char arr2[], int distance, int startPos);
void rearrangeDocument(char doc[]);
int calculateSatisfaction(const char word1[][MAX_WORD_LENGTH + 1],
	const char word2[][MAX_WORD_LENGTH + 1],
	const int distance[],
	int nRules,
	const char document[]);

int main() {
	//TEST FOR PURPORTED RULES
	/*char test[5][MAX_WORD_LENGTH + 1] = {
		"CaT", "FeRRet", "mOUse", "rAT", "HoRSE"
	};
	char test1[5][MAX_WORD_LENGTH + 1] = {
		"pIG", "FrOg", "cAT", "d0NK3y", "tIGER"
	};
	int distance[5] = { 2, -1, 3, 2, 1 };
	cout << normalizeRules(test, test1, distance, 5) << endl;
	for (int i = 0; i < 5; i++)
		cout << test[i] << test1[i] << distance[i] << endl;
	return 9; */


	//TEST FOR REPEATING RULES
	/*char test[7][MAX_WORD_LENGTH + 1] = {
		"CaT", "FeRRet", "mOUse", "rAT", "caT", "Dog", "moUse"
	};
	char test1[7][MAX_WORD_LENGTH + 1] = {
		"pIG", "FrOg", "cAT", "d0NK3y", "MousE", "RaBBit", "CAT"
	};
	int distance[7] = { 2, 1, 1, 2, 4, 1, 3 };
	cout << normalizeRules(test, test1, distance, 7) << endl;
	for (int i = 0; i < 7; i++)
		cout << test[i] << test1[i] << distance[i] << endl;
	return 9; */


	//TESTING REARRANGEDOC
	/* char doc1[] = { "   he   is  a butt    " };
	rearrangeDocument(doc1);
	cout << "~" << doc1 << "~" << endl;
	char doc2[] = { "What are    you doing     today?" };
	rearrangeDocument(doc2);
	cout << "~" << doc2 << "~" << endl;
	char doc3[] = { "???What ar3e    yo5u doing  6   today?" };
	rearrangeDocument(doc3);
	cout << "~" << doc3 << "~" << endl; */

	//TESTING ISMATCH
	/* char a1[] = { " I ate a lot of ice cream today " };
	char a2[] = { "ice" };
	if (isMatch(a1, a2, 16))
		cout << "Success" << endl;
	else {
		cout << "Fail" << endl;
	} */

	//TEST ISWITHINRANGE
	/* char a1[] = { " I ate a lot of ice cream today " };
	char a2[] = { "today" };
	if (isWithinRange(a1, a2, 3, 20))
		cout << "success" << endl;
	else {
		cout << "fail" << endl;
	}
	return 9; */

	const int TEST1_NRULES = 4;
	char test1w1[TEST1_NRULES][MAX_WORD_LENGTH + 1] = {
		"mad",       "deranged", "nefarious", "have"
	};
	char test1w2[TEST1_NRULES][MAX_WORD_LENGTH + 1] = {
		"scientist", "robot",    "plot",      "mad"
	};
	int test1dist[TEST1_NRULES] = {
		2,           4,          1,           13
	};
	assert(calculateSatisfaction(test1w1, test1w2, test1dist, TEST1_NRULES,
		"The mad UCLA scientist unleashed a deranged evil giant robot.") == 2);
	assert(calculateSatisfaction(test1w1, test1w2, test1dist, TEST1_NRULES,
		"The mad UCLA scientist unleashed    a deranged robot.") == 2);
	assert(calculateSatisfaction(test1w1, test1w2, test1dist, TEST1_NRULES,
		"**** 2016 ****") == 0);
	assert(calculateSatisfaction(test1w1, test1w2, test1dist, TEST1_NRULES,
		"  That plot: NEFARIOUS!") == 1);
	assert(calculateSatisfaction(test1w1, test1w2, test1dist, TEST1_NRULES,
		"deranged deranged robot deranged robot robot") == 1);
	assert(calculateSatisfaction(test1w1, test1w2, test1dist, TEST1_NRULES,
		"That scientist said two mad scientists suffer from deranged-robot fever.") == 0);


	const int TEST2_NRULES = 4;
	char test2w1[TEST2_NRULES][MAX_WORD_LENGTH + 1] = {
		"bananas",	"monkey",	"climb",	"eat"
	};
	char test2w2[TEST2_NRULES][MAX_WORD_LENGTH + 1] = {
		"ripe",		"hungry",	"tree",		"banana"
	};
	int test2dist[TEST2_NRULES] = {
		1,			2,			2,			3
	};
	assert(calculateSatisfaction(test2w1, test2w2, test2dist, TEST2_NRULES,
		"   The hungry     monkey      climbs  the tree for some ripe bananas") == 2);
	assert(calculateSatisfaction(test2w1, test2w2, test2dist, TEST2_NRULES,
		"Hungry crazy monkey will climb palm tree to eat some ripe bananas") == 3);
	assert(calculateSatisfaction(test2w1, test2w2, test2dist, TEST2_NRULES,
		"bananas ripe bananas ripe bananas ripe bananas ripe") == 1);
	assert(calculateSatisfaction(test2w1, test2w2, test2dist, TEST2_NRULES,
		"eat 1 banana") == 1);
	assert(calculateSatisfaction(test2w1, test2w2, test2dist, TEST2_NRULES,
		"hungr3y monk3ey loves to eat ripe bananas") == 2);
	assert(calculateSatisfaction(test2w1, test2w2, test2dist, TEST2_NRULES,
		"hungry Monke3333333333y climbs tree for a ripe banana") == 1);
	assert(calculateSatisfaction(test2w1, test2w2, test2dist, TEST2_NRULES,
		"hungry monkey") == 1);
	assert(calculateSatisfaction(test2w1, test2w2, test2dist, TEST2_NRULES,
		"the monkey will eat a delicious ripe banana") == 0);
	assert(calculateSatisfaction(test2w1, test2w2, test2dist, TEST2_NRULES,
		"the monkey is eating a ripebanana") == 0);
	assert(calculateSatisfaction(test2w1, test2w2, test2dist, TEST2_NRULES,
		"") == 0);
	
	cout << "All tests succeeded" << endl;
}

void changeToLower(char arr[]) {
	for (int i = 0; arr[i] != '\0'; i++)	// i < strlen(arr)
		arr[i] = tolower(arr[i]);
}

void shiftUp(char arr[][MAX_WORD_LENGTH + 1], int startPos, int endPos) {
	int i;
	int j;
	for (i = startPos; i < endPos - 1; i++) {
		for (j = 0; arr[i + 1][j] != '\0'; j++) {	// j < strlen(arr[i + 1])
			arr[i][j] = arr[i + 1][j];
		}
		arr[i][j] = '\0';
	}
}

void shiftUp(int arr[], int startPos, int endPos) {
	for (int i = startPos; i < endPos - 1; i++)
		arr[i] = arr[i + 1];
}

int normalizeRules(char word1[][MAX_WORD_LENGTH + 1],
	char word2[][MAX_WORD_LENGTH + 1],
	int distance[],
	int nRules) {

	if (nRules < 0)
		nRules = 0;

	for (int i = 0; i < nRules; i++) {
		changeToLower(word1[i]);
		changeToLower(word2[i]);
	}

	for (int i = nRules - 1; i >= 0; i--) {
		//have we finished checking all the characters in w1 and w2
		bool isW1Checked = false;
		bool isW2Checked = false;

		int j = 0;
		//if not finished checking through both w1 and w2, continue with loop
		while (!isW1Checked || !isW2Checked) {
			if (j == strlen(word1[i]))
				isW1Checked = true;

			if (j == strlen(word2[i]))
				isW2Checked = true;

			if (!isW1Checked && !isalpha(word1[i][j]) ||
				!isW2Checked && !isalpha(word2[i][j]) ||
				strlen(word1[i]) == 0 || strlen(word2[i]) == 0 ||
				distance[i] <= 0) {
				shiftUp(word1, i, nRules);
				shiftUp(word2, i, nRules);
				shiftUp(distance, i, nRules);
				nRules--;
				break;
			}
			j++;
		}
	}

	for (int i = nRules - 1; i > 0; i--) {
		for (int j = i - 1; j >= 0; j--) {
			if (strcmp(word1[i], word1[j]) == 0 && strcmp(word2[i], word2[j]) == 0 ||
				strcmp(word1[i], word2[j]) == 0 && strcmp(word1[j], word2[i]) == 0) {
				if (distance[i] < distance[j])
					distance[i] = distance[j];
				else
					distance[j] = distance[i];
				shiftUp(word1, i, nRules);
				shiftUp(word2, i, nRules);
				shiftUp(distance, i, nRules);
				nRules--;
				break;
			}
		}
	}
	return nRules;
}

bool isMatch(char arr1[], const char arr2[], int startPos) {
	int i;
	for (i = 0; i < strlen(arr2); i++) {
		if (arr1[i + startPos] != arr2[i]) 
			return false;
	}
	if (arr1[startPos + i] == ' ')
		return true;
	return false;
}

bool isWithinRange(char arr1[], const char arr2[], int distance, int startPos) {
	int space = 0;
	int i;
	for (i = startPos;(space <= distance && i != strlen(arr1)); i++) { // traces document
		if (arr1[i] == ' ')
			space++;
	}
	for (int k = startPos + 1; k < i; k++) {
		if (arr1[k - 1] == ' ') {
			if (isMatch(arr1, arr2, k))
				return true;
		}
	}
	space = 0;
	for (i = startPos - 1; (space <= distance && i != 0); i--) {  // traces doc
		if (arr1[i] == ' ')
			space++;
	}
	for (int k = startPos - 1; k > i; k--) {
		if (arr1[k - 1] == ' ') {
			if (isMatch(arr1, arr2, k))
				return true;
		}
	}
	return false;
} 

// changes document so that it is formatted with 
// spaces at the beginning and end of the array,
// only one space between each word and
// without non letter characters
void rearrangeDocument(char doc[]) {
	char originalDoc[MAX_DOC_LENGTH + 1];
	strcpy(originalDoc, doc);
	doc[0] = ' ';
	int j = 1;
	for (int i = 0; originalDoc[i] != '\0'; i++) {	// i < strlen(originalDoc)
		if (originalDoc[i] == ' ' && doc[j - 1] != ' ' || 
			isalpha(originalDoc[i])) {

			doc[j] = originalDoc[i];
			j++;
		}
	}
	if (doc[j - 1] != ' ')
		doc[j] = ' ';
	doc[j + 1] = '\0';
}

int calculateSatisfaction(const char word1[][MAX_WORD_LENGTH + 1],
	const char word2[][MAX_WORD_LENGTH + 1],
	const int distance[],
	int nRules,
	const char document[]) {

	char docCopy[MAX_DOC_LENGTH + 1];
	strcpy(docCopy, document);
	changeToLower(docCopy);
	rearrangeDocument(docCopy);

	int score = 0;
	if (nRules < 0)
		nRules = 0;

	for (int i = 0; i < nRules; i++) {	// go through all rules
		int k = (strlen(docCopy) - strlen(word1[i]));
		for (int j = 1; j < k; j++) {	// go though docCopy
			if (docCopy[j - 1] == ' ') {	// look for space in docCopy
				if (isMatch(docCopy, word1[i], j)) {	// if word1[i] matches docCopy starting at character after space
					if (isWithinRange(docCopy, word2[i], distance[i], j)) { // see if corresponding word2 is within distance from word1
						score++;
						break;
					}
				}
			}
		}
	}
	return score;
}