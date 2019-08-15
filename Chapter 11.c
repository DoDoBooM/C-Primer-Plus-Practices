#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#define LIM 40
char* s_gets(char*,int);
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
void No_9();
char* reverse(char*);
void No_10();
void remove_space(char*);
void No_11();
char get_selection();
void print_string_array(char[10][LIM], int);
void print_string_ASCII(char[10][LIM], int);
void strsort_ASCII(char [][LIM], int);
void print_string_len(char [10][LIM], int);
void strsort_len(char [][LIM], int );
void print_string_firstwordlen(char [10][LIM], int);
void strsort_firstworlen(char [][LIM], int);
int firstwordlen(char *);
void No_12();
void No_13(int, char **);
double No_14(char **);
int No_15(char *);
void No_16(char*);
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
	// No_8();
	// No_9();
	// No_10();
	// No_11();
	// No_12();
	// No_13(argc, argv);
	// printf( "%.2lf\n" ,No_14(argv));
	// printf("%d\n", No_15(argv[1])); 
	No_16(argv[1]);
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

//No.9
void No_9()
{
	char testcases[] = "Hello World!";
	printf("%s\n", reverse(testcases));
}
char* reverse(char* str)
{
	int len = strlen(str);
	int low = 0, high = len - 1;
	while(low < high)
	{
		char temp = str[high];
		str[high] = str[low];
		str[low] = temp;
		high--;
		low++;
	}
	return str;
}

//No.10
void No_10()
{
	char str[10];
	while(1)
	{
		printf("Press enter at the head of a line to quit!\n");
		char* ptr = fgets(str, 10, stdin);
		if(ptr && *ptr != '\n')
		{
			remove_space(ptr);
		}
		else
		{
			break;
		}
		while(getchar() != '\n')
				continue;
	}
	printf("Bye\n");
}
void remove_space(char* str)
{
	int len = strlen(str);
	char temp[len];
	int c = 0;
	for (int i = 0; i < len; ++i)
	{
		if(str[i] != ' ')
			temp[c++] = str[i];
	}
	temp[c] = '\0';
	printf("%s\n", temp);
}

//NO.11
void No_11()
{
	char str[10][LIM];
	printf("Enter at most 10 lines! Empty line to end entering.\n");
	int count = 0;
	for (count = 0; count < 10; ++count)
	{
		char * ptr = fgets(str[count], LIM, stdin);
		if(*ptr == '\n')
			break;
	}

	while(1)
	{
		char ch = get_selection();
		switch(ch)
		{
			case '1':
			{
				print_string_array(str, count);
				break;
			}
			case '2':
			{
				print_string_ASCII(str, count);
				break;
			}
			case '3':
			{
				print_string_len(str, count);
				break;
			}
			case '4':
			{
				print_string_firstwordlen(str, count);
				break;
			}
			case '5':
			{
				goto end;
			}
		}
	}
	end:printf("Bye\n");
}
char get_selection()
{
	printf("Please select a operation.\n");
	printf("1.print your inputs.\t\t\t\t\t2.print your inputs in the order of ASCII\n");
	printf("2.print your inputs in the order of length.\t\t4.print your inputs in the order of the length of the first word in string.\n");
	printf("5.quit\n");

	while(1)
	{
		printf("Your selection is:");
		char ch = getchar();
			while(getchar() != '\n')
				continue;
		if(ch != '1' && ch != '2' && ch != '3' && ch != '4'&& ch != '5')
			printf("Invalid select, try again! %c", ch);
		else
			return ch;
	}
}
void print_string_array(char str[10][LIM], int count)
{
	for (int i = 0; i < count; ++i)
	{
		printf("No.%d\t%s\n", i + 1, str[i]);
	}
}
void print_string_ASCII(char str[10][LIM], int count)
{
	strsort_ASCII(str, count);
	for (int i = 0; i < count; ++i)
	{
		printf("No.%d\t%s\n", i + 1, str[i]);
	}
}
void strsort_ASCII(char strings[][LIM], int num)
{
	char * temp;
	int top, seek;
	for (top = 0; top < num - 1; ++top)
	{
		for (seek = top + 1; seek < num; ++seek)
		{
			if(strcmp(strings[top], strings[seek]) > 0)
			{
				temp = strings[top];
				*strings[top] = *strings[seek];
				*strings[seek] = *temp;
			}
		}
	}
}
void print_string_len(char str[10][LIM], int count)
{
	strsort_len(str, count);
	for (int i = 0; i < count; ++i)
	{
		printf("No.%d\t%s\n", i + 1, str[i]);
	}
}
void strsort_len(char strings[][LIM], int num)
{
	char * temp;
	int top, seek;
	for (top = 0; top < num - 1; ++top)
	{
		for (seek = top + 1; seek < num; ++seek)
		{
			if(strlen(strings[top]) > strlen(strings[seek]))
			{
				temp = strings[top];
				*strings[top] = *strings[seek];
				*strings[seek] = *temp;
			}
		}
	}
}
void print_string_firstwordlen(char str[10][LIM], int count)
{
	strsort_firstworlen(str, count);
	for (int i = 0; i < count; ++i)
	{
		printf("No.%d\t%s\n", i + 1, str[i]);
	}
}
void strsort_firstworlen(char strings[][LIM], int num)
{
	char * temp;
	int top, seek;
	for (top = 0; top < num - 1; ++top)
	{
		for (seek = top + 1; seek < num; ++seek)
		{
			if(firstwordlen(strings[top]) > firstwordlen(strings[seek]))
			{
				temp = strings[top];
				*strings[top] = *strings[seek];
				*strings[seek] = *temp;
			}
		}
	}
}
int firstwordlen(char * str)
{
	int len = 0;
	while(isspace(*str))
		str++;
	while(!isspace(*str))
	{
		len++;
		str++;
	}
	return len;
}
void No_12()
{
	char ch;
	int wordCnt = 0, upperCnt = 0, lowerCnt = 0, puncCnt = 0, numCnt = 0;
	bool inword = false;
	while((ch = getchar()) != EOF)
	{
		if (isalpha(ch))
		{
			if (!inword)
			{
				inword = true;
				wordCnt++;
			}

			if (isupper(ch))
				upperCnt++;
			if (islower(ch))
				lowerCnt++;
		}
		else if (ispunct(ch))
		{
			puncCnt++;
			inword = false;
		}
		else if (isdigit(ch))
		{
			numCnt++;
			inword = false;
		}
		else if (isspace(ch))
			inword = false;
	}
	printf("Word Count: %d\n", wordCnt);
	printf("Upper Character Count: %d\n", upperCnt);
	printf("Lower Character Count: %d\n", lowerCnt);
	printf("Punctuation Character Count: %d\n", puncCnt);
	printf("Numeric Character Count: %d\n", numCnt);
}
//NO.13
void No_13(int len, char ** words)
{
	for (int i = len - 1; i > 0; i--)
	{
		printf("%s ", words[i]);
	}
	printf("\n");
}
double No_14(char ** args)
{
	double num = atof(args[1]);
	int n = atof(args[2]);
	double res = 1;
	for (int i = 0; i < n; ++i)
	{
		res *= num;
	}
	return res;
}
int No_15(char * str)
{
	while(*str == '0')
		str++;
	bool negative = false;
	if(*str == '-')
	{
		str++;
		negative = true;
	}
	int result = 0;
	int num = 0;
	while(*str != '\0')
	{
		switch(*str)
		{
			case '0':
			{
				num = 0;
				break;
			}
			case '1':
			{
				num = 1;
				break;
			}
			case '2':
			{
				num = 2;
				break;
			}
			case '3':
			{
				num = 3;
				break;
			}
			case '4':
			{
				num = 4;
				break;
			}
			case '5':
			{
				num = 5;
				break;
			}
			case '6':
			{
				num = 6;
				break;
			}
			case '7':
			{
				num = 7;
				break;
			}
			case '8':
			{
				num = 8;
				break;
			}
			case '9':
			{
				num = 9;
				break;
			}
			default:
			{
				return 0;
			}
		}
		str++;
		result *= 10;
		result += num;
	}
	return result * (negative ? -1 : 1);
}

void No_16(char* arg)
{
	char str[LIM];
	s_gets(str, LIM);
	switch(arg)
	{
		case NULL:
		case "-p":
		{
			puts(str);
			break;
		}
		case "-u":
		{
			puts(strupr(str));
			break;
		}
		case "-l":
		{
			puts(strlwr(str));
			break;
		}
		default:
		{
			printf("Invalid argument\n");
			break;
		}
	}
}

char* s_gets(char* str, int len)
{
	char *ret_val = fgets(str, len, stdin);
	while (*str != '\0')
	{
		if (*str == '\n')
		{
			*str = '\0';
			break;
		}
		str++;
	}
	return ret_val;
}