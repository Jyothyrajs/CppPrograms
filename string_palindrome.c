

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void palindrome(char *);
main()
{
	char string[25];
	printf("String:\n");
	scanf("%s",string);
	palindrome(string);

}

void palindrome(char *string)
{
	
	int length,i;
	char *ptr;
	length= strlen(string);
	ptr=(char *)malloc(length*sizeof(char));
	ptr=(string+length-1);
	for(i=1;i<=(length/2);i++)
	{
		if(*string != (*ptr))
		{
			printf("%c%c\n",*string,*ptr);
			printf("Not a palindrome\n");
			break;
		}
		string++;
		ptr--;
	}
	if( i  > length/2 )	
	printf("palindrome\n");

}
