#include <iostream>
using namespace std;

bool isThis(char str[], char okon[], int pos) {
	int okonlen = strlen(okon)-1;

	for (int i = pos, j = okonlen;i != pos - okonlen;--i, --j) {
		if (str[i] != okon[j]) {
			return false;
		}
	}
	return true;
}

int main() {
	setlocale(LC_ALL, "RU");
	char arr[300] = "Серый Белый Трава Красив Фиолетовый";
	int len = strlen(arr);
	char okonch[3] = "ый";
	int okonLen = strlen(okonch);

	int letCounter = 0;


	for (int i = 0;i != len+1;++i) {

		len = strlen(arr);

		if (arr[i] == ' ' || arr[i] == '\0') {
			if (letCounter != 0) {

				if (isThis(arr, okonch, i - 1)) {
					for (int j = i-letCounter;j != i;++j) {
						cout << arr[j];
					}
					cout << endl;
				}
				
			}

			letCounter = 0;
		}
		else {
			++letCounter;
		}

	}
}