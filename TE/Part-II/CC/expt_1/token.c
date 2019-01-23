#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

#define SIZE 256

bool is_delimiter(char ch)
{
	if (ch == ' ' || ch == '+' || ch == '-' || ch == '*'
		|| ch == '/' || ch == ',' || ch == ';' || ch == '>'
		||ch == '<' || ch == '=' || ch == '(' || ch == ')'
		||ch == '[' || ch == ']' || ch == '{' || ch == '}')
		return true;
	return false;
}

bool is_operator(char ch)
{
	if (ch == '+' || ch == '-' || ch == '*'
		|| ch == '/' || ch == '>' || ch == '<'
		|| ch == '=')
		return true;
	return false;
}

bool is_keyword(char *str)
{
	if (!strcmp(str, "if") || !strcmp(str, "else")
		|| !strcmp(str, "while") || !strcmp(str, "do")
		|| !strcmp(str, "break") || !strcmp(str, "continue")
		|| !strcmp(str, "int") || !strcmp(str, "double")
		|| !strcmp(str, "float") || !strcmp(str, "return")
		|| !strcmp(str, "char") || !strcmp(str, "case")
		|| !strcmp(str, "char") || !strcmp(str, "sizeof")
		|| !strcmp(str, "long") || !strcmp(str, "short")
		|| !strcmp(str, "typedef") || !strcmp(str, "switch")
		|| !strcmp(str, "unsigned") || !strcmp(str, "void")
		|| !strcmp(str, "static") || !strcmp(str, "struct")
		|| !strcmp(str, "goto"))
		return true;
	return false;
}

bool is_valid_identifier(char *str)
{
	if (str[0] == '0' || str[0] == '1' || str[0] == '2'
		|| str[0] == '3' || str[0] == '4' || str[0] == '5'
		|| str[0] == '6' || str[0] == '7' || str[0] == '8'
		|| str[0] == '9' || is_delimiter(str[0]) == true)
		return false;
	return true;
}

char *sub_string(char* str, int left, int right)
{
	int i;
	char* substr = (char*)malloc(sizeof(char) * (right - left + 2));
	for (i = left; i <= right; i++)
		substr[i - left] = str[i];
	substr[right - left + 1] = '\0';
	return substr;
}

void identify(char *str)
{
	int left = 0, right = 0;
	int len = strlen(str);

	while (right <= len && left <= right) {
		if (is_delimiter(str[right]) == false)
			right++;

		if (is_delimiter(str[right]) == true && left == right) {
			if (is_operator(str[right]) == true)
				printf("'%c' is an operator\n", str[right]);

			right++;
			left = right;
		} else if (is_delimiter(str[right]) == true && left != right
				|| (right == len && left != right)) {
			char *sub_str = sub_string(str, left, right-1);

			if (is_keyword(sub_str) == true)
				printf("'%s' is a keyword\n", sub_str);
			else if (is_valid_identifier(sub_str) == true
					&& is_delimiter(str[right-1]) == false)
				printf("'%s' is an identifier\n", sub_str);
			else
				printf("'%s' is not a valid identifier", sub_str);
			left = right;
		}
	}
	return;
}

int main()
{
	char str[SIZE];

	printf("Enter a valid 'C' statement\n");
	fgets(str, SIZE, stdin);

	identify(str);

	return 0;
}
