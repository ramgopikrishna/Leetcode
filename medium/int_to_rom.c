// Roman to Int

#if 0
Seven different symbols represent Roman numerals with the following values:
Symbol	Value
I	1
V	5
X	10
L	50
C	100
D	500
M	1000

Roman numerals are formed by appending the conversions of decimal place values from highest to lowest. Converting a decimal place value into a Roman numeral has the following rules:

    If the value does not start with 4 or 9, select the symbol of the maximal value that can be subtracted from the input, append that symbol to the result, subtract its value, and convert the remainder to a Roman numeral.
    If the value starts with 4 or 9 use the subtractive form representing one symbol subtracted from the following symbol, for example, 4 is 1 (I) less than 5 (V): IV and 9 is 1 (I) less than 10 (X): IX. Only the following subtractive forms are used: 4 (IV), 9 (IX), 40 (XL), 90 (XC), 400 (CD) and 900 (CM).
    Only powers of 10 (I, X, C, M) can be appended consecutively at most 3 times to represent multiples of 10. You cannot append 5 (V), 50 (L), or 500 (D) multiple times. If you need to append a symbol 4 times use the subtractive form.

Given an integer, convert it to a Roman numeral.

 

Example 1:

Input: num = 3749

Output: "MMMDCCXLIX"

Explanation:

3000 = MMM as 1000 (M) + 1000 (M) + 1000 (M)
 700 = DCC as 500 (D) + 100 (C) + 100 (C)
  40 = XL as 10 (X) less of 50 (L)
   9 = IX as 1 (I) less of 10 (X)
Note: 49 is not 1 (I) less of 50 (L) because the conversion is based on decimal places

Example 2:

Input: num = 58

Output: "LVIII"

Explanation:

50 = L
 8 = VIII

Example 3:

Input: num = 1994

Output: "MCMXCIV"

Explanation:

1000 = M
 900 = CM
  90 = XC
   4 = IV

 

Constraints:

    1 <= num <= 3999

//Leetcode solution, better way copied 
typedef struct {
    const int value;
    const char* string;
    const int length;
} Roman;

const Roman romans[] = { 
    { 1, "I", 1 }, 
    { 4, "IV\0", 2 }, 
    { 5, "V\0", 1 }, 
    { 9, "IX\0", 2 }, 
    { 10, "X\0", 1 }, 
    { 40, "XL\0", 2 }, 
    { 50, "L\0", 1 }, 
    { 90, "XC\0", 2 }, 
    { 100, "C\0", 1 }, 
    { 400, "CD\0", 2 }, 
    { 500, "D\0", 1 }, 
    { 900, "CM\0", 2 }, 
    { 1000, "M\0", 1 } 
};
const int romansLength = sizeof(romans) / sizeof(romans[0]);

char* intToRoman(int num) {
    char* result = malloc(sizeof(char) * 30);
    int l = 0;
    for (int i = romansLength - 1; i >= 0; i--) {
        for (int j = num / romans[i].value; j > 0; j--) {
            strcpy(result + l, romans[i].string);
            l += romans[i].length;
        }

        num %= romans[i].value;
    }

    return result;
}
#endif


#include <stdio.h>
#include <string.h>

/* here thing is defined variable has to be checked from larger array to the given number */
/* two things to take care, one is smallest number to divide % give same divisor incase of small number, next thing is
	still the same number can be divised again after subtraction, then evrything is no issues */
char *InttoRoman(int val)
{
	struct arrays
	{
		int value;
		char rom[3];
	};
	struct arrays romint[] = {
		{1, "I"},
		{4, "IV"},
		{5, "V"},
		{9, "IX"},
		{10, "X"},
		{40, "XL"},
		{50, "L"},
		{90, "XC"},
		{100, "C"},
		{400, "CD"},
		{500, "D"},
		{900, "CM"},
		{1000, "M"}
	};
	static char let[16];
	memset(let,0,sizeof(let));
	int lseek_off=0;
	int x=val;
	int y=sizeof(romint)/ sizeof(romint[0]);
	for(x; x>0;)
	{
		for(y; y>=0;)
		{
			int temp = x%romint[y].value;
			if((temp == x))
			{
				y--;
				continue;
			}
			else
			{
				x=x-romint[y].value;
				memcpy(let+lseek_off,romint[y].rom, strlen(romint[y].rom));
				lseek_off+=strlen(romint[y].rom);
				if(x<romint[y].value)
				{
					y--;
				}
			}
		}
	} 

	return let;
}

int main(void)
{
	int val = 1999;
	char *rama = InttoRoman(val); 
	printf("RAMA final %s\n", rama);
}
