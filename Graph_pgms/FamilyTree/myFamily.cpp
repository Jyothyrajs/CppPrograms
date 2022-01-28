#include<iostream>
#include<string>
using namespace std;

class Family
{
	Family *member;
	int kids;
	string name;
	string mother;
	string spouse;
	int root;
	Family* child[5];
public:
	Family()
	{}
	Family( string n)
	{
		kids = 0;
		root =1;
		name = n;
	}
	Family( string n, string m )
	{
		kids = 0;
		root = 0;
		name = n;
		mother = m;
	}
	string getMother()
	{
		return mother;
	}
	string getName()
	{
		return name;
	}
	void addChild(string m, string n)
	{
		if( m.compare(name) == 0)
		{
			child[kids++] = new Family(n,m);
		}
		else
		{
			int i = 0;
			while( i < kids )
			{
				child[i]->addChild(m,n);
				i++;
			}
		}
	}
	void myKids(string m)
	{
		int found = 0;
		if( m.compare(name) == 0 )
		{
			int i = 0;
			cout << "My Kids are (" <<name <<" ) "<<" : " ;
			while ( i < kids )
			{
				cout << child[i]->name << " ";
				i++;
			}
			cout << endl;
			found = 1;
		}
		else
		{
			int i = 0;
			while ( i < kids )
			{
				child[i]->myKids(m);
				if( found )
					return;
				i++;
			}

		}
	}
	Family getNode(string n) // need to check & update
	{
		Family *prev;
		while( name.compare(n) != 0 )
		{

			for ( int i =0; i< kids; i++ )
			{
				cout << "Compared " << name << endl;
				prev = child[i];
				return child[i]->getNode( n );
			}
			return *prev;
		}
		return *this;
	}
	void mySiblings(string n )
	{
		
	}
};


int main()
{
	Family f("A");
	cout << f.getName();
	f.addChild("A","B");
	f.addChild("A","C");
	f.addChild("A","D");
	f.addChild("A","E");
	f.addChild("B","F");
	f.addChild("D","G");
	f.addChild("D","H");
	f.myKids("A");
	f.myKids("C");
	f.myKids("B");
	f.myKids("D");
	f.myKids("G");
	string s = "D";
	Family curr = f.getNode(s);
	//cout << curr.getName();

}
