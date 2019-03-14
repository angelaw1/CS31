#include <iostream>
using namespace std;

/* int main()
{
	int arr[3] = { 5, 10, 15 };
	int* ptr = arr;

	*ptr = 30;          // set arr[0] to 30
	*(ptr + 1) = 20;      // set arr[1] to 20

	ptr += 2;
	ptr[0] = 10;        // set arr[2] to 10

	while (ptr <= arr + 4)
	{
		cout << *(ptr - 2) << endl;    // print values
		ptr++;
	}
} */


/* void findMax(int arr[], int n, int*& pToMax)
{
	if (n <= 0)
		return;      // no items, no maximum!

	pToMax = arr;

	for (int i = 1; i < n; i++)
	{
		if (arr[i] > *pToMax)
			pToMax += i;
	}
}

int main()
{
	int nums[4] = { 5, 3, 15, 6 };
	int* ptr;

	findMax(nums, 4, ptr);
	cout << "The maximum is at address " << ptr << endl;
	cout << "It's at position " << ptr - nums << endl;
	cout << "Its value is " << *ptr << endl;
 */

/* void computeCube(int n, int* ncubed)
{
	*ncubed = n * n * n;
}

int main()
{
	int a;
	int* ptr = &a;
	computeCube(6, ptr);
	cout << "Five cubed is " << *ptr << endl;
} */


// return true if two C strings are equal
/* bool strequal(char str1[], char str2[])
{
	char* a = str1;
	char* b = str2;
	while (a <= str1 + strlen(str1) && b <= str2 + strlen(str2))
	{
		if (*a != *b)  // compare corresponding characters
			return false;
		a++;            // advance to the next character
		b++;
	}
	return *a == *b;   // both ended at same time?
}

int main()
{
	char a[15] = "Zhao";
	char b[15] = "Zhao";

	if (strequal(a, b))
		cout << "They're the same person!\n";
} */


/* int* getPtrToArray(int& m)
{
	int anArray[100];
	for (int j = 0; j < 100; j++) {
		anArray[j] = 100 - j;
	}
	m = 100;
	return anArray;
}

void f()
{
	int junk[100];
	for (int k = 0; k < 100; k++)
		junk[k] = 123400000 + k;
}

int main()
{
	int n;
	int* ptr = getPtrToArray(n);
	for (int i = 0; i < n; i++)
		cout << ptr[i] << " ";
	f();
	for (int i = 0; i < 3; i++)
		cout << ptr[i] << ' ';
	for (int i = n - 3; i < n; i++)
		cout << ptr[i] << ' ';
	cout << endl; 
} */


/* double mean(const double* scores, int numScores)
{
	const double* ptr = scores;
	double tot = 0;
	while (ptr != scores + numScores)
	{
		tot += *ptr;
		ptr++;
	}
	return tot / numScores;
} */

/* int main()
{
	double* cat;
	double mouse[5];
	cat = &mouse[4];
	*cat = 25;
	*(mouse + 3) = 42;
	cat -= 3;
	cat[1] = 54;
	cat[0] = 17;
	if (mouse[4] == 25 && mouse[3] == 42 && mouse[2] == 54 && mouse[1] == 17) 
		cout << "true" << endl;;
	cat[1] = 17;
	bool b = (*cat == *(cat + 1));
	if (b)
		cout << "true" << endl;
	cat = &mouse[0];
	bool d = (cat == mouse);
	if (d)
		cout << "true" << endl;
} */

/* double mean(const double* scores, int numScores)
{
	const double* ptr = scores;
	double tot = 0;
	for (int i = 0; i < numScores; i++) {
		tot += *(ptr + i);
	}
	return tot / numScores;
}

int main()
{
	double scores[6] = { 1.0, 2.0, 3.0, 4.0, 5.0, 6.0 };
	cout << mean(scores, 6) << endl;
} */

/* const char* findTheChar(const char* str, char chr)
{
	const char* ptr = str;
	for (int k = 0; *(str + k) != '\0'; k++)
		if (*(str + k) == chr)
			return str + k;
	return nullptr;
}

int main() {
	char a[] = { "hello" };
	const char* pointer = findTheChar(a, 'e');
	if (pointer == &a[1])
		cout << "true" << endl;
} */

/* const char* findTheChar(const char* str, char chr)
{
	while (str != '\0') {
		if (*str == chr) {
			return str;
		}
		str++;
	}
	return nullptr;
}

int main() {
	char a[] = { "hello" };
	const char* pointer = findTheChar(a, 'l');
	if (pointer == &a[2])
		cout << "true" << endl;
} */


/* int* maxwell(int* a, int* b)
{
	if (*a > *b)
		return a;
	else
		return b;
}

void swap1(int* a, int* b)
{
	int* temp = a;
	a = b;
	b = temp;
}

void swap2(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int main()
{
	int array[6] = { 5, 3, 4, 17, 22, 19 };

	int* ptr = maxwell(array, &array[2]);
	*ptr = -1;
	ptr += 2;
	ptr[1] = 9;
	*(array + 1) = 79;

	cout << &array[5] - ptr << endl;

	swap1(&array[0], &array[1]);
	swap2(array, &array[2]);

	for (int i = 0; i < 6; i++)
		cout << array[i] << endl;
} */


/* void removeS(char* str) {
	char* ptr;
	for (ptr = str; *ptr != 0; ptr++) {
		if (*ptr == 's' || *ptr == 'S') {
			for (str = ptr; *str != '\0'; str++)
				*str = *(str + 1);
			ptr--;
		}
	}
}

int main()
{
	char msg[50] = "She'll be a massless princess.";
	removeS(msg);
	cout << msg;  // prints   he'll be a male prince.
} */