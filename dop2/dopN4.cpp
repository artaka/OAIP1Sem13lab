#include <iostream>
using namespace std;

void deleteChars(char str[], int pos, int charCount) {
	int len = strlen(str);

	for (int i = 0;i != charCount;++i) {
		len = strlen(str);
		for (int j = pos;j != len;++j) {
			str[j] = str[j + 1];
		}

	}
}

void reverseWord(string word, char str[], int pos) {
	string res = "";
	for (int i = word.length()-1;i != -1;--i) {
		res += word[i];
	}

	for (int i = pos, j = 0;i != pos + res.length();++i, ++j) {
		str[i] = res[j];
	}
}

int main() {
	setlocale(LC_ALL, "RU");
	char arr[300] = "HOW DO YOU DO";

	int len = strlen(arr);
	int letCounter = 0;
	int wordCounter = 0;

	for (int i = 0;i != len + 1;++i) {

		len = strlen(arr);

		if (arr[i] == ' ' || arr[i] == '\0') {
			if (letCounter != 0) {

				++wordCounter;

				if (wordCounter % 2 != 0) {
					deleteChars(arr, i - letCounter, letCounter + 1);

					i -= ++letCounter;
				}
				else {
					string word = "";
					for (int j = i - letCounter;j != i;++j) {
						word += arr[j];
					}
					reverseWord(word, arr, i - letCounter);
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