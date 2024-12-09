#include <iostream>
#include <vector>
using namespace std;

void deleteChars(char str[], int pos, int charCount) {
	int len = strlen(str);

	for (int i = 0;i != charCount;++i) {

		for (int j = pos;j != len;++j) {
			str[j] = str[j + 1];
		}

	}
}

bool isThere(vector<string> unique, string word) {
	for (auto item : unique) {
		if (item == word) {
			return true;
		}
	}
	return false;
}

int main() {
	setlocale(LC_ALL, "RU");
	char str[300] = "Пару пару пару слов будут повторяться повторяться повторяться";
	vector<string> unique;
	int len = strlen(str);

	string word = "";
	int letCounter = 0;
	for (int i = 0;i != len+1;++i) {
		len = strlen(str);

		if (str[i] == ' ' || str[i] == '\0') {
			if (letCounter != 0) {
				for (int j = i - letCounter;j != i;++j) {
					word += tolower(str[j]);
				}
				if (!(isThere(unique, word))) {
					unique.push_back(word);
				}
				else {
					deleteChars(str, i - letCounter, letCounter + 1);

					i -= ++letCounter;
				}
				word = "";

			}

			letCounter = 0;
		}
		else {
			++letCounter;
		}

	}
	cout << str;
}