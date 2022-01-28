#include<iostream>
#include<string>
using namespace std;

struct node
{
	int v =0;
	int kids;
	string name;
	string mother;
	string spouse;
	node* child[5];
};

class Family
{
	node *root;
public:
	int found;
	Family()
	{
		found = 0;
		root = NULL;
	}
	Family( string n)
	{
		found = 0;
		root = new node;
		root->kids = 0;
		root->name = n;
	}
	Family( string n, string m )
	{
		found = 0;
		root = new node;
		root->kids = 0;
		root->name = n;
		root->mother = m;
	}
	node* getroot()
	{
		return root;
	}
	string getName(node* r)
	{
		return r->name;
	}	
	int isChild( node* r, string str)

	{
		int i =0;
		node* curr = r->child[i];
		while( curr->name.compare(str)  && i < curr->kids )
		{
			i++;
			curr = r->child[i];
		}
		if( i == root->kids )
			return 1;
		else
			return 0;	
	}
	
	node* moveTo(node* root, string str)
	{
		node *temp = root;
		node* parent;
		int i =0;
		if( root->name.compare(str) == 0)
		{
			cout << "In " << temp->name;
			return temp;
		}
		else
		{
			while(  i < root->kids )
			{
				parent = root;
				temp = moveTo(root->child[i],str);
				i++;
			
			}
		}
		
	}
	node* moveToParent(node* root,node* parent, string str)
	{
		node* temp = root;
		int i =0;
		if( root->name.compare(str) == 0)
		{
			cout << "Parent : " << parent->name << endl;
			found = 1;
			return parent;
		}
		else
		{
			while(  i < root->kids )
			{
				parent = root;
				temp = moveToParent(root->child[i],parent,str);
				i++;
			}
		}
		
	}
/*	node* getParent( node *r, string str)
	{
		node *temp = r;
		node *parent;
		while ( temp->name.compare(str) )
		{
			parent = temp;
			for( int i = 0; i < temp->kids ; i++ )
			{
				temp = parent->child[i];
				if ( temp->name.compare(str) )
					moveTo(temp,str);
				else
				{
					cout <<"Parent : " <<  parent->name << endl;
					return parent;
				}
			}
		}
		cout << "Parent : " << parent->name << endl;
		return parent;
	}*/
	void addChild(node *r,string m, string n)
	{
		int added = 0;
		if( m.compare(r->name) != 0)
		{
			int i = 0;
			while( i < r->kids  )
			{
				addChild(r->child[i],m,n);
				i++;
				
			}
		}
		else
		{
			node *temp = new node;
			temp->name = n;
			temp->mother = m;
			r->child[r->kids++] = temp;
			added = 1;
			cout << "Added " <<n << endl;
		}
	}
	void mySiblings(node *r,node *p, string n )
	{
		cout << "Parent of " << n  <<" : " <<p->name;
		int i = 0;
		cout << "Siblings of " << n << ": " ;
/*		while( i < p->kids )
		{
			if( p->child[i]->name.compare(n) )
			{
				cout << p->child[i]->name << " ";
			}
			i++;
		}*/	
	}
};


int main()
{
	Family f("A");
	node* root = f.getroot();
	f.addChild(root,"A","B");
	f.addChild(root,"A","C");
	f.addChild(root,"A","D");
	f.addChild(root,"B","E");
	f.addChild(root,"B","F");
	f.addChild(root,"F","H");
	f.addChild(root,"C","I");
	
	string s = "D";
	node* n = f.moveTo(f.getroot(),s);
	node* p1 = f.moveToParent(f.getroot(),root,"H");
	node* p2= f.moveToParent(f.getroot(),root,"I");
	node* p3 = f.moveToParent(f.getroot(),root,"D");
	f.mySiblings(root,p3,"D");	
	//	f.mySiblings(root,"F");
}
