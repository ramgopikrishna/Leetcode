#include <stdio.h>
#include <string.h>


int romanToInt(char* s)
{
    int len=strlen(s);
    int final_value = 0;
    int last_value = 0;
    int tmp = 0;

    int i;
    for(i=0; i<len; i++)
    {
    	if(s[i] == 'M')
	{
	    tmp=1000;
	}
    	if(s[i] == 'D')
	{
	    tmp=500;
	}
    	if(s[i] == 'C')
	{
	    tmp=100;
	}
    	if(s[i] == 'L')
	{
	    tmp=50;
	}
    	if(s[i] == 'X')
	{
	    tmp=10;
	}
    	if(s[i] == 'V')
	{
	    tmp=5;
	}
    	if(s[i] == 'I')
	{
	    tmp=1;
	}
	final_value +=tmp;

	if(i>0 && last_value<tmp)
	{
	    final_value=final_value-(last_value*2);
	}
	last_value=tmp;
    }
    return final_value;
}

int main(void)
{
    int s = romanToInt("MCMXCIV");
    printf("RAMA %d\n", s);
    s = romanToInt("LVIII");
    printf("RAMA %d\n", s);
    s = romanToInt("III");
    printf("RAMA %d\n", s);
}
