#include <iostream>
#include <cstring>
char *last_occured;

class Mystring
{
	char *data;
	void permute(char* str, int start,int end);
	void swap(char*,char*);
	public:
	Mystring()
	{
		data = NULL;
	}

	Mystring(const char* str)
	{
		// throw if str == NULL
		
		data = new char[strlen(str)+1];
		strcpy(data, str);
	}

	Mystring(const Mystring& s)
	{
		if( s.data == NULL)
		{
			data = NULL;
			return;
		}
		data = new char[strlen(s.data)+1];
		strcpy(data,s.data);
	}

	void show();
	int has(char);
	bool has(const char*);
	bool has(const Mystring& s);
	void common_char(const Mystring& s);
	void delete_char(char);
	void delete_allchar(char);
	bool palindrome();
	void permutation();	
	char* reverse();
};

void Mystring::show()
{
	if( data == NULL )
		throw "NuLL String";
	std::cout << data << std::endl;
}

int Mystring::has(char ch)
{
	int count=0;
	char *str=data;
	while(*str!='\0')
	{
		if(*str==ch)
			count++;
		str++;
	}
	return count;
}
bool Mystring::has(const Mystring& s)
{
	return has(s.data);
}

bool Mystring::has(const char *substr)
{
	if( substr == NULL || data == NULL)
		return false;

	const char *temp=substr;
	char *str=data;
	char *started_at = data;
	while((*str!= '\0') && (*temp!='\0'))
	{
		if(*str!=*temp)
		{
			temp=substr;	
			started_at++;
			str = started_at;
		}
		else
		{
			str++;
			temp++;
		}
	}

	return (*temp=='\0');
}

void Mystring::common_char(const Mystring& str)
{
	int i=0;
	char ch,*s2 = str.data,v[20];
	while((ch=*s2)!='\0')
	{
		if(has(ch)>0)
		{
			i++;
			v[i]=ch;
		}	
		s2++;
	}
	std::cout<<"Common characters:";
	while(i>0)
		std::cout<<v[i--]<<" ";
	return;
}

void Mystring::delete_char(const char ch)
{
	char *str=data,*nextchar;
	while(*str!=ch && *str!='\0')
	{
		str++;
	}
	if(*str==ch)
	{	last_occured=str;
		nextchar=(str+1);
		while(*str!='\0')
		{
			*str++=*nextchar++;
		}
	}
	else
		last_occured=str;
	
}

void Mystring::delete_allchar(const char ch)
{
	while(*last_occured!='\0')  
		delete_char(ch);
}
bool Mystring::palindrome()
{
	char *bptr,*fptr=data;
	if ( data == NULL)
		return false;
	bptr=((fptr+strlen(data))-1);
	while(fptr<bptr)
	{
		if(*fptr!=*bptr)
			return false;
		fptr++;
		bptr--;
		
	}
	return true;
}

char* Mystring::reverse()
{
	char *revstr,*str;
	int length=strlen(data);
	revstr= new char[length];
	while(length)
	{
		*revstr=*(data+length);
		length--;
		revstr++;
	}
	*revstr='\0';
	return revstr;
}

void Mystring::swap(char *x, char *y)
{
	char temp;
	temp= *x;
	*x=*y;
	*y=temp;
}

void Mystring::permutation()
{
	permute(data, 0, (strlen(data)-1));
}
void Mystring::permute(char *str, int start, int end)
{
	int i;
	if(start==end)
		std::cout<<str<<"\n";
	else
	{
		for(i=1; i<=end; i++)
		{
			std::cout<<"Permute "<<str<<" "<<start<<" "<<end<<"\n";
			swap((str+start), (str+i));
			permute(str, start+1, end);
			swap((str+start), (str+i));
		}
	}

}

int main()
{
try{
	char ch;
	char *rev;
	Mystring S1("SaSaSanish Kanjany"),S2("Sanish"),SP("ABC");
	std::cout<<"S1:";
	S1.show();
	std::cout<<"S2:";
	S2.show();
	S1.common_char(S2);
	Mystring S3(S1);
	std::cout<<"S3:";
	S3.show();
	std::cout<<"Reverse:";
	rev=S3.reverse();
	std::cout<<rev<<"\n";
	std::cout<<"S3:";
	S3.show();
	std::cout<<"Character to delete: ";
	std::cin>>ch;
	S3.delete_char(ch);
	std::cout<<"After first occurrence delete: ";
	S3.show();
	S1.delete_allchar(ch);
	std::cout<<"After all occurrence delete : ";
	S3.show();
	std::cout << std::boolalpha << S1.has("Kan") << std::endl;
	std::cout << std::boolalpha << S1.has(S2) << std::endl;
	Mystring S4(S2);
	S4.show();
	std::cout<<"Palindrome: ";
	std::cout << std::boolalpha << SP.palindrome() << std::endl;
	S4.show();
	SP.permutation();   
}
catch(const char *msg)
{	
	std::cout<<"Exception:";
	std::cerr<<msg<<std::endl;
}
}
