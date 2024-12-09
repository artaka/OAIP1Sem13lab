#include <iostream>
using namespace std;

void deleteChars(char str[], int pos, int charCount) {
	int len = strlen(str);

	for (int i = 0;i != charCount;++i) {

		for (int j = pos;j != len;++j) {
			str[j] = str[j + 1];
		}

	}
}

void task1() {
	char arr[300] = "Это какой-то текст для задания";
	int len = strlen(arr);
	
	int letCounter = 0;
	int wordCounter = 0;

	for (int i = 0;i != len;++i) {

		len = strlen(arr);

		if (arr[i] == ' ' || arr[i] == '\0') {
			if (letCounter != 0) {

				++wordCounter;

				if (wordCounter % 2 == 0) {
					deleteChars(arr, i - letCounter, letCounter + 1);

					++i;
					i -= letCounter;
				}
			}

			letCounter = 0;
		}
		else {
			++letCounter;
		}

	}
	cout << arr << endl;
}

void task2() {
	char arr[300] = "Это какой-то текст для задания";
	int k = 13;
	//cin >> k;

	int letCounter = 0;
	int wordCounter = 0;
	int len = strlen(arr);

	for (int i = 0;i != len;++i) {
		if (i == k) {
			(*(arr + i) != ' ' && *(arr + i) != '\0') ? cout << wordCounter + 1 : cout << wordCounter;
		}
		else
		{
			if (*(arr +i) == ' ' || *(arr + i) == '\0') {
				if (letCounter != 0) {
					++wordCounter;
				}

				letCounter = 0;
			}
			else {
				++letCounter;
			}
		}


	}
}

int main() {
	setlocale(LC_ALL, "RU");
	task1();
	task2();
}