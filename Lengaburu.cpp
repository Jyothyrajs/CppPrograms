#include <iostream>
using namespace std;
#include "string.h"
class Family
{
	int kids;
	char name[20];
	char mother[10];
	char gender[6];
	char spouse[10];
	static Family child[10];
public:
	Family(){}
	 Family(const char *m,const char *n,const char *g)
	{
		strcpy(name,n);
		strcpy(mother,m);
		strcpy(gender,g);
	}
/*	char* getGender(char *name)
	{
		return *gender;
	}
*/
	char * getName(char *n)
	{

		return name;
	}
	void member()
	{
		cout<<name;
	}
	void addChild(const char *m,const char *n,const char *g)
	{	
		if(strcmp(m,mother))
			child[kids++]=Family(m,n,g);
		else
		{
			int i =0;
			for(i=0;i <kids; i++)
			{
				if(strcmp(child[i].name,m))
				{
					child[i].addChild(m,n,g);
					break;
				}
			}
		}
		child[kids++];
	}
};


class Lengaburu
{
	char king[20];
	char queen[20];
	char *mother;
	int kids;
	Family child[10];
public:
	Lengaburu()
	{
		kids =0;
	}
	Lengaburu(const char* k,const char* q)
	{
		kids =0;
		strcpy(king,k);
		strcpy(queen,q);
		mother =NULL;
	}
	void getMembers()
	{
		std::cout<<"King:"<<king<<endl;
		std::cout<<"Queen:"<<queen<<endl;
	}
	void addChild(const char *m,const char *n,const char *g)
	{
		if(strcmp(m,queen))
			child[kids++]=Family(m,n,g);
		else
			Family.addChild(m,n,g);
	}
	void getChildren()
	{
		int i;
		for (i=0;i<kids;i++)
		{
			child[i].member();
		}
	}	
};

int main()
{
	Lengaburu l("Rajendran", "Shobhana");
	l.getMembers();
	
	l.addChild("Shobhana","Jyothy","Male"); 
	l.addChild("Sobhana","Jhancy","Male"); 
	l.addChild("Shobhana","Jeeja","Male"); 
	l.addChild("Jyothy","Dhrona","Male"); 
	cout<<"Dhrona Added";
	l.getChildren();
}
