#include <iostream>
using namespace std;
#include "string.h"
class Family
{
	int kids;
	int root;
	char name[20];
	char mother[10];
	char gender[6];
	char spouse[10];
	Family* child[10];
public:
	Family(){}
	Family(const char *n)
	{
		root = 1;
		kids = 0;
		strcpy(name,n);
		strcpy(gender,"Female");
		strcpy(mother, "root");
	}
	 Family(const char *m,const char *n,const char *g)
	{
		cout << n <<  " added " << endl;
		kids = 0;
		root = 0;
		strcpy(name,n);
		strcpy(mother,m);
		strcpy(gender,g);
	}
	char * getName(char *n)
	{

		return name;
	}
	char * getMother()
	{

		return mother;
	}
	void member()
	{
		for(int i =0; i< kids; i++ )
		{
			cout << child[i]->name << " ";
		}

	}

	void getChildren()
	{
		int i;
		cout << "kids of " << name << " : "; 
		for (i=0; i<kids; i++)
		{
			cout << child[i]->name << endl;
		}
	}	
	void addChild(const char *m,const char *n,const char *g)
	{
		if ( kids == 0)
		{
			child[0] = new Family(m,n,g);
			kids++;
		}
		else{
		       for(	int i =0; i< kids; i++)
		{
				if( strcmp(m, name) == 0)
				{
					child[kids++] = new Family(m,n,g);
					break;
				}
				else
				{
				for( int i = 0; i < kids; i++)
				{
					if( strcmp(child[i]->name,m) == 0 )
					{
						child[i]->addChild(m,n,g);
						break;
					}	
				}
		
				}	
		}}
	}
	void getSiblings(char *person)
	{
		if( strcmp(name,person) != 0)
		{
			for(int i = 0 ; i<kids; i++)
			{
				cout << " Not in " << name << endl;
				child[i]->getSiblings(person);
			}		
		}
		else
		{
			cout << "Siblings of  " << person <<": " ;
				for(int i= 0; i< kids; i++)
				{
					if( !strcmp(child[i]->name,person))
						cout << child[i]->name << " ";
				}
			cout << endl;
				return;
		}

	}
};


int main()
{
	Family r( "Sobhana");
	
	r.addChild("Sobhana","Jyothy","female"); 
	r.addChild("Sobhana","Jhancy","female"); 
	r.addChild("Sobhana","Jeeja","female"); 
	r.addChild("Jyothy","Dhrona","male"); 
	r.addChild("Jhancy","Adithyan","Male"); 
	r.addChild("Jhancy","Anudeepthi","Female"); 
	r.getChildren();
	char test[20] = "Jyothy";
	r.getSiblings(test);
}
