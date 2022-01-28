#include<iostream>
#include<fstream.h>
using namespace std;
/** Display program details( No of Characters, lines, functions etc) */
int main()
{
	int linecount, wordcount,functioncount;
	char filename[25];
	FILE *inputfile;
	std::cout<<"Enter the name of file to get the details\n";
	std::cin>>filename;
	inputfile=fopen(filename,"r");

	
	while((character=fgetc(inputfile))!=EOF)
	{
		if(character=='\n' || character=='\r')
			linecount++;
		elseif(character=='\t' || character==" ")
			wordcount++;
	}
	cout<<"No of Lines: "<<linecount<<"\n";
	
	cout<<"No of words: "<<wordcount<<"\n";
}
