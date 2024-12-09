#include <stdio.h>
void main()
{
	char s[256];
	int i, count;
	puts("Enter string: ");
	gets_s(s);
	for (count = i = 0; s[i] != 0; i++)
	{
		if (i == 0 && s[i] != '(') {
			printf("Wrong str!\n");
			break;
		}
		else if (s[i] == '(') {
			count++;
		}
		else if (s[i] == ')') {
			count--;
		}
	}
	if (!count)
		puts("Ok\n");
	else
		puts("Not Ok\n");
}
