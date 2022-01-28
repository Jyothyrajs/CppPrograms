#include<stdlib.h>
#include<stdio.h>
#include<string.h>
int main()
{
	char str[30]="Welcome",pat[10]="com",rep[10]="abc";
	int srclen,patlen,replen;
	char *strsrc,*cmp,*tmp,*start;
	int found=0;
	printf("\nEnter String:");
	gets(str);
	printf("\nEnter search String:");
	gets(pat);
	printf("\nEnter a replace String:");
	gets(rep);
	srclen=strlen(str);
	patlen=strlen(pat);
	start=str;
	for(;start<(str+(srclen-patlen));start++)
	{
		cmp=start;
		tmp=pat;
		while(*cmp==*tmp && (*tmp!='\0'))
		{
			tmp++;
			cmp++;
		}
		if(*tmp=='\0')
		{
			found=1;
			break;
		}
	}
	if(found)
	{
		tmp=rep;
		while(*tmp!='\0')
		{
			*start=*tmp;
			start++;
			tmp++;
		}
	}
	printf("String after replace %s",str);
}
