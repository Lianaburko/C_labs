#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool are_stars(char* combination) {
	do {
		if (*combination != '*') {
			return false;
		}	
	} while (*(++combination));
	return true;
}

int underline_count(char** combination) {
	int underline_counter = 0;
	while (*(++(*combination)))
		switch (**combination)
		{
		case '_':
			underline_counter++;
			break;
		case '*':
			continue;
		default:
			return underline_counter;
		}
	return underline_counter;
}

bool str_check( char* word, char* combination) {
	int word_length = strlen(word);
	int combination_length = strlen(combination);
	int len = word_length < combination_length ? word_length : combination_length;
	for (int i = 0; i < len; i++) {
		char c = *combination;
		if (c == '*') {
			int underline_counter = underline_count(&combination);
			int remainder = word_length - i;
			if (remainder < underline_counter) {
				return false;
			}
			if (*combination == '\0') {
				return true;
			}
			if (remainder == underline_counter) {
				return false;
			}
			for (int j = i + underline_counter; j < word_length; j++) {
				if (str_check((word + j), combination)) {
					return true;
				}
			}
			return false;
		}
		combination++;
		if (c == '_') {
			continue;
		}
		if (c != *(word + i)) {
			return false;
		}

	}
	if (word_length == combination_length) {
		return true;
	}
	if (word_length > combination_length) {
		return false;
	}
	return are_stars(combination);
}

bool match_template(char* word,char* combination) {
	int word_length = strlen(word);
	int combination_length = strlen(combination);
	if (!combination_length)
		return word_length ? false : true;
	if (!word_length)
		return are_stars(combination);
	return str_check(word, combination);
}

char* gets_s(char* str, int num) {
	char* s = fgets(str, num, stdin);
	if (s)
	{
		int n = strlen(str) - 1;
		str += n;
		if (*str == '\n')
			*str = '\0';
	}
	return s;
}

int main() {
	char word[81], combination[81];
	while (1)
	{
		puts("Word is");
		gets_s(word, 80);
		puts("Template is");
		gets_s(combination, 80);

		if (match_template(word, combination)) {
			printf("the word suits");
		}
		else {
			printf("word don't suits");
		}
	}
	return 0;
}


