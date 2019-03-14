#include <iostream>
#include <string>
#include <cassert>
using namespace std;

const int BAD_ARGUMENT = -1;

int appendToAll(string a[], int n, string value);
int lookup(const string a[], int n, string target);
int positionOfMax(const string a[], int n);
int rotateLeft(string a[], int n, int pos);
int countRuns(const string a[], int n);
void swap(string& a, string& b);
int flip(string a[], int n);
int min(int a, int b);
int differ(const string a1[], int n1, const string a2[], int n2);
int subsequence(const string a1[], int n1, const string a2[], int n2);
int lookupAny(const string a1[], int n1, const string a2[], int n2);
int separate(string a[], int n, string separator);

int main() {

	string a[8] = { "Bob", "Bill", "", "Angela", "Jill", "Steve", "Stacy", "Jill" };
	assert(lookup(a, 3, "Angela") == -1);
	assert(lookup(a, 8, "angela") == -1);
	assert(lookup(a, 8, "Jill") == 4);
	assert(lookup(a, -5, "Steve") == -1);
	assert(lookup(a, 8, "Paul") == -1);
	assert(lookup(a, 0, "Angela") == -1);
	assert(positionOfMax(a, 1) == 0);
	assert(positionOfMax(a, 2) == 0);
	assert(positionOfMax(a, 3) == 0);
	assert(positionOfMax(a, 8) == 5);
	assert(positionOfMax(a, 0) == -1);

	string b[7] = { "Bob", "Bill", "Bill", "Bob", "Angela", "Steve" };
	assert(positionOfMax(b, 4) == 0);
	assert(countRuns(b, 6) == 5);
	assert(countRuns(b, 4) == 3);
	assert(countRuns(b, 0) == 0);

	string c[7] = { "Bob", "Bill", "Bob", "Angela", "Stacy", "Bobby", "Steve" };
	string d[4] = { "Bob", "Angela", "Stacy", "Bobby" };
	string e[7] = { "Bob", "Bill", "Bob", "Steve", "", "Bobby", "Angela" };
	string f[4] = { "Bob", "Bill", "Bob", "Steve" };
	assert(differ(c, 7, d, 4) == 1);
	assert(differ(c, 7, e, 7) == 3);
	assert(differ(c, 3, e, 3) == 3);
	assert(differ(e, 7, f, 4) == 4);
	assert(subsequence(c, 7, d, 4) == 2);
	assert(subsequence(c, 7, d, 0) == 0); 
	assert(subsequence(c, 5, d, 4) == -1);
	assert(subsequence(e, 3, f, 4) == -1);
	assert(subsequence(e, 5, f, 0) == 0);
	assert(subsequence(e, 0, f, 0) == 0);

	string g[5] = { "Bill", "Bobby", "Hillary", "Jill", "Eva" };
	string h[7] = { "Evan", "Hillary" ,"Hillary", "Billy", "Bobby", "Bob", "Steve" };
	assert(lookupAny(g, 5, h, 7) == 1);
	assert(lookupAny(g, 0, h, 7) == -1);
	assert(lookupAny(h, 1, g, 5) == -1);

	string i[6] = { "Steve", "Jill", "Eva", "Bob", "Bill", "Evan" };
	assert(appendToAll(i, 4, "!!!") == 4);
	assert(i[0] == "Steve!!!" && i[1] == "Jill!!!" && i[2] == "Eva!!!" 
		&& i[3] == "Bob!!!" && i[4] == "Bill");

	string j[6] = { "Steve", "Jill", "Eva", "Bob", "Bill", "Evan" };
	string k[6] = { "Steve", "Jill", "Eva", "Bob", "Bill", "Evan" };
	assert(rotateLeft(j, 0, 0) == 0);
	assert(j[0] == "Steve" && j[1] == "Jill");
	assert(rotateLeft(j, 2, 5) == -1);
	assert(rotateLeft(j, 6, 2) == 2);
	assert(j[0] == "Steve" && j[1] == "Jill" && j[2] == "Bob" 
		&& j[3] == "Bill" && j[4] == "Evan" && j[5] == "Eva");
	assert(rotateLeft(k, 0, 0) == 0);
	assert(rotateLeft(k, 6, 1) == 1);
	assert(k[0] == "Steve" && k[1] == "Eva" && k[2] == "Bob"
		&& k[3] == "Bill" && k[4] == "Evan" && k[5] == "Jill");

	string l[6] = { "Steve", "Jill", "Eva", "Bob", "Bill", "Evan" };
	string m[6] = { "Steve", "Jill", "Eva", "Bob", "Bill", "Evan" };
	assert(flip(l, 0) == 0);
	assert(l[0] == "Steve" && l[1] == "Jill");
	assert(flip(l, 1) == 1);
	assert(l[0] == "Steve" && l[1] == "Jill");
	assert(flip(l, 6) == 6);
	assert(l[0] == "Evan" && l[1] == "Bill" && l[2] == "Bob"
		&& l[3] == "Eva" && l[4] == "Jill" && l[5] == "Steve");
	assert(flip(m, 3) == 3);
	assert(m[0] == "Eva" && m[1] == "Jill"
		&& m[2] == "Steve" && m[3] == "Bob");

	string n[6] = { "Steve", "Jill", "Eva", "Bob", "Bill", "Evan" };
	string o[7] = { "Steve", "Jill", "Eva", "Bob", "Bill", "Evan", "Jen" };
	string p[5] = { "Steve", "Steve", "Steve", "Steve", "Steve" };
	string q[6] = { "Evan", "Jen", "Jennie", "Lisa", "Jennie", "Jill" };
	string r[6] = { "Evan", "Jen", "Jennie", "Jennie", "Jill", "Lisa" };
	string s[6] = { "Steve", "Jennie", "Lisa", "Jill", "Jen", "Evan" };
	assert(separate(n, 6, "Aaron") == 0);
	assert(separate(n, 6, "ZZZZZZ") == 6);
	assert(separate(n, 6, "Evan") == 3);
	assert(n[0] == "Eva" && n[1] == "Bob" && n[2] == "Bill"
		&& n[3] == "Evan" && n[4] == "Steve" && n[5] == "Jill");
	assert(separate(o, 7, "Jennie") == 5);
	assert(o[0] == "Eva" && o[1] == "Bob" && o[2] == "Bill"
		&& o[3] == "Evan" && o[4] == "Jen" && o[5] == "Jill" 
		&& o[6] == "Steve");
	assert(separate(p, 5, "Steve") == 0);
	assert(separate(q, 6, "Jennie") == 2);
	assert(q[0] == "Evan" && q[1] == "Jen" && q[2] == "Jennie"
		&& q[3] == "Jennie" && q[4] == "Lisa" && q[5] == "Jill");
	assert(separate(r, 6, "Jennie") == 2);
	assert(r[0] == "Evan" && r[1] == "Jen" && r[2] == "Jennie"
		&& r[3] == "Jennie" && r[4] == "Jill"&& r[5] == "Lisa"); 
	assert(separate(s, 6, "Jen") == 1);
	assert(s[0] == "Evan" && s[1] == "Jen" && s[2] == "Lisa"
		&& s[3] == "Jill" && s[4] == "Steve" && s[5] == "Jennie"); 

	cout << "All tests succeeded!" << endl;
}

int appendToAll(string a[], int n, string value) {
	if (n < 0)
		return BAD_ARGUMENT;
	else {
		for (int i = 0; i < n; i++)
			a[i] += value;
		return n;
	}
}

int lookup(const string a[], int n, string target) {
	if (n < 0)
		return BAD_ARGUMENT;
	else {
		for (int i = 0; i < n; i++) {
			if (a[i] == target)
				return i;
		}
		return -1;
	}
}

int positionOfMax(const string a[], int n) {
	int indexOfMax = 0;
	string max = a[0];
	if (n <= 0)
		return BAD_ARGUMENT;
	else {
		for (int i = 1; i < n; i++) {
			if (max < a[i]) {
				indexOfMax = i;
				max = a[i];
			}
		}
	}
	return indexOfMax;
}

int rotateLeft(string a[], int n, int pos) {
	if (n < 0 || pos < 0 || pos > n)
		return BAD_ARGUMENT;
	else if (n > 0) {
		string temp = a[pos];
		for (int i = pos; i < n - 1; i++) {
			a[i] = a[i + 1];
		}
		a[n - 1] = temp;
	}
	return pos;
}

int countRuns(const string a[], int n) {
	int count = 1;
	if (n < 0)
		return BAD_ARGUMENT;
	else if (n == 0)
		return 0;
	for (int i = 0; i < n - 1; i++) {
		if (a[i] != a[i + 1])
			count++;
	}
	return count;
}

//swaps the values of two strings
void swap(string& a, string& b) {
	string temp;
	temp = a;
	a = b;
	b = temp;
}

int flip(string a[], int n) {
	string temp;
	if (n < 0)
		return BAD_ARGUMENT;
	for (int i = 0; i < n/2; i++) {
		swap(a[i], a[n - 1 - i]);
	}
	return n;
}

//returns the minimum of two integers or the first integer if they are both the same
int min(int a, int b) {
	if (a < b)
		return a;
	return b;
}

int differ(const string a1[], int n1, const string a2[], int n2) {
	int smaller = min(n1, n2);
	if (n1 < 0 || n2 < 0)
		return BAD_ARGUMENT;
	for (int i = 0; i < smaller; i++) {
		if (a1[i] != a2[i]) {
			return i;
		}
	}
	return smaller;
}

int subsequence(const string a1[], int n1, const string a2[], int n2) {
	if (n1 < 0 || n2 < 0)
		return BAD_ARGUMENT;
	else if (n1 == 0 && n2 == 0)
		return 0;
	for (int i = 0; i < n1; i++) {
		//counts number of consecutive indices that match in both arrays
		int count = 0;
		//finds where in a1 does the first value of a2 appear
		if (a1[i] == a2[0]) {
			for (int j = 0; j < n2; j++) {
				//increment count if elements are same in in both arrays
				//and we are not looking past the interested values in a1
				if (a1[i + j] == a2[j] && i + j < n1)
					count++;
				else
					break;
			}
			if (count == n2)
				return i;
		}
	}
	return -1;
}

int lookupAny(const string a1[], int n1, const string a2[], int n2) {
	if (n1 < 0 || n2 < 0)
		return BAD_ARGUMENT;
	for (int i = 0; i < n1; i++) {
		for (int j = 0; j < n2; j++) {
			if (a1[i] == a2[j])
				return i;
		}
	}
	return -1;
}

int separate(string a[], int n, string separator) {
	int index = 0;
	bool hasValueNotSmallerThanSeparator = false;
	if (n < 0)
		return BAD_ARGUMENT;
	for (int i = 0; i < n; i++) {
		if (a[i] >= separator) {
			hasValueNotSmallerThanSeparator = true;
			for (int j = i + 1; j < n; j++) {
				if (a[j] <= separator) {
					swap(a[i], a[j]);
					//do not increment index or break out of loop
					//unless element is less than separator
					//we want all elements less than separator 
					//before elements equal to separator
					if (a[i] < separator) {
						index = i + 1;
						break;
					}
				}
			}
		}
		else
			index = i + 1;
	}
	if (hasValueNotSmallerThanSeparator)
		return index;
	return n;
}