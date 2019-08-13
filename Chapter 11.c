#include <stdio.h>
#include <string.h>
#include <ctype.h>
void No_1(int,char[*]);
void No_2(int,char[*]);
void No_3_4();
void No_5();
char* mstrchr(char*, char);
void No_6();
int is_within(char, char*);
void No_7();
char* mystrncpy(char*, char*, int);
void No_8();
char* string_in(char*, char*);
int main(int argc, char**argv)
{
	// int n = 10;
	// char str[n];
	// No_1(n, str);
	// No_2(n, str);
	// char str[10];
	// No_3_4(str, 10);
	// No_5();
	// No_6();
	// No_7();
	No_8();
	return 0;
}
//No.1
void No_1(int n, char str[n])
{
	for (int i = 0; i < n - 1; ++i)
	{
		str[i] = getchar();
	}
	str[n - 1] = '\0';
	while(getchar() != '\n')
		;
}
//No.2
void No_2(int n, char str[n])
{
	int i;
	for (i = 0; i < n - 1; ++i)
	{
		str[i] = getchar();
		if(str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
			break;
	}
	str[i] = '\0';
	while(getchar() != '\n')
		;
}

//No.3 No.4
void No_3_4(char* str, int len)
{
	char str1[len];
	fgets(str1, len, stdin);
	int i = 0;
	while(isspace(str1[i]))
		i++;
	int j = 0;
	while(j + i < len && !isspace(str1[j+i]) && str1[j+i] != '\0')
	{
		str[j] = str1[j+i];
		j++;
	}
	str[j] = '\0';
}
//No.5
void No_5()
{
	int len = 50;
	char str[50];
	char ch;
	while(1)
	{
		printf("Enter the string, press enter in the head of line to quit!\n");
		fgets(str, len, stdin);
		if(*str == '\n')
			break;
		printf("Input the character.\n");
		ch = getchar();
		char* ptr = mstrchr(str, ch);
		if(ptr)
			printf("Found character %c in string %s", *ptr, str);
		else
			printf("Didn't find character %c in string %s", ch, str);
		while(getchar() != '\n')
			;
	}
	printf("Bye\n");
}
char* mstrchr(char* str, char ch)
{
	while(*str)
	{
		if(*str == ch)
			return str;
		str++;
	}
	return NULL;
}
//No.6
void No_6()
{
	int len = 50;
	char str[50];
	char ch;
	while(1)
	{
		printf("Enter the string, press enter in the head of line to quit!\n");
		fgets(str, len, stdin);
		if(*str == '\n')
			break;
		printf("Input the character.\n");
		ch = getchar();
		int isWithin = is_within(ch, str);
		if(isWithin)
			printf("Found character %c in string %s", ch, str);
		else
			printf("Didn't find character %c in string %s", ch, str);
		while(getchar() != '\n')
			;
	}
	printf("Bye\n");
}
int is_within(char ch, char* str)
{
	if(strchr(str, ch))
		return 1;
	else
		return 0;
}
//No.7
void No_7()
{
	char t[10];
	char *s[3] = {"ABCDEFGHIJKLMN", "My name is", "La la la"};
	for (int i = 0; i < 3; ++i)
		printf("%s\n", mystrncpy(t, s[i], 10));
}
char* mystrncpy(char* t, char* s, int len)
{
	for (int i = 0; i < len; ++i)
	{
		*(t + i) = *(s + i);
		if(*(t + i) == '\0')
			break;
	}
	return t;
}
//No.8
void No_8()
{
	char *strs[3][2] = {
		{"ABCDE", "BCD"},
		{"Hello World!", "World!"},
		{"Hello", "World!"}
	};
	for (int i = 0; i < 3; ++i)
	{
		if(string_in( strs[i][0], strs[i][1]))
			printf("Found.\n");
		else
			printf("Didn't find.\n");
	}
}
char* string_in(char* str, char* pattern)
{
	return strstr(str, pattern);
}