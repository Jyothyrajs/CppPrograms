#include<iostream>

using namespace std;
struct Person
{
	char name[20];
	char relation[20];
	bool gender;
	Person *child;
};

class Family
{
	Person *head;
public:
	Family()
	{
		head = NULL;
	}
	void addChild(char* mom, char* name,char* gender);
	Person* getMother(char *);
	char* getRelationship(char*, char*);
	void show();
};

void Family::addChild(char m[],char n[],char g[])
{
	Person *p1= new Person;
	strcpy(p1->mother,m);
	strcpy(p1->name,n);
	strcpy(p1->gender,g);
	if(strcmp(g,"Female"))
	{
		p1->daughter =true;
	}
	else
		p1->daughter = false;
/* 	Person *parent = getMother(n);	
	if(parent!=NULL)
		parent->child=p1;
*/	p1->child = NULL;
	Person *parent =p1;
	if(head==NULL)
		head=p1;
}
Person* Family::getMother(char *n)
:0
{
	Person *prev =head;
	Person *temp=head;
		while(temp!=NULL && strcmp(temp->name,n)!=0)
		{
			prev= temp;
			temp= temp->child;
		}
	return (prev);
}
char* Family::getRelationship(char *n, char *r)
{
	return NULL;
}
void Family::show()
{
	cout<<head->mother<<" "<<head->name<<" "<<head->gender<<endl;
	
}

int main()
{
	Family *f=new Family();
	f->addChild("Jyothy","Dhrona","Male");
	Person *m1=f->getMother("Dhrona");
	cout<<m1->name<<endl;
	f->show();
	return 0;
}

