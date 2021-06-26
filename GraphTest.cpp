
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
enum Relation
{
	PaternalUncle,
	
}
struct node 
{
	char *name;
	char *mom;
	char* gender;
	int kid_count;
	node *kids[10];
	node *spouse;
	node(const char *m,const char *n,const char *g)
	{
			mom =new char[strlen(m)+1];
			name =new char[strlen(n)+1];
			gender =new char[strlen(g)+1];
			strcpy(mom,m);
			strcpy(name,n);
			strcpy(gender,g);
			kid_count = 0;
	}

	void Show()
	{
			cout<<name<<"\t"<<mom<<"\t"<<gender<<"\t"<<kid_count << endl;		
	}

};
	static void Show(vector<node*>& vNodes)
	{
		std::for_each(vNodes.begin(), vNodes.end(), std::mem_fun(&node::Show));
	}
class Family

{
	node* root;
	
public:
	Family()
	{
		root = NULL;
	}
	void addChild(const char *m,const char *n,const char *g)
	{
			node *temp= new node(m, n, g);
			if(!root)
			{
				root = temp;
			}
			else
			{
				node* parent = search(m,root);
				parent->kids[parent->kid_count++]= temp;
			}
	}


	node* search(const char *m, node *root)
	{				
		if(!strcmp(root->name,m))
		{
			return root;
		}
		else
		{
			int kids= root->kid_count;
			node* ret = NULL;
			for(int j=0;j<kids;j++)
			{	
				ret = search(m, root->kids[j]);
				if(ret)
					break;
				
			}
			return ret;
		}
	}
	void traverse( node *root)
	{				
		int j=0;
		int kids= root->kid_count;
		root->Show();
		
		for(j=0;j<kids;j++)
		{	
			traverse(root->kids[j]);
		}
	}

	void siblings(const char *name, vector<node*>& vSiblings)
	{
		vSiblings.clear();
		int sib=0;
		node *sibling;
		node *person= search(name,root);
		node *parent= search(person->mom,root);
		
		for(int j=0;j<parent->kid_count;j++)
		{
			if(parent->kids[j] && parent->kids[j]!=person)
			{
				vSiblings.push_back(parent->kids[j]);
	
			}
		}
		cout<<endl;
	}
	void spouseUpdate(const char *member,const char *m,const char *n,const char *g)
	{
			node *temp= new node(m, n, g);
			if(!root)
			{
				cout<<"Empty tree";
			}
			else
			{
				node* old_member = search(member,root);
				temp->spouse = old_member;
				old_member->spouse= temp;
				cout<<"Spouse of "<<old_member->name<<" Updated"<<endl;	
			}
	}
	void getRelationship(const char *name, char *relation,vector<node*>& vRelatives)
	{
		switch(relation)
		{
			case 'son': 
					node *parent = search(name,root);
					for(int j=0;j<parent->kid_count;j++)
					{
							vRelatives.push_back(parent->kids[j]);
	
					}
			default: cout<<"No members"<<endl;
		}
		

	}


	void showFamily()
	{
		traverse(root);
		cout << "Done...." << endl;
	}	
};


int main()
{
	Family f;
	int k=0;
	f.addChild("Karthu","Sobhana","Female");
	f.addChild("Sobhana","Jhancy","Female");
	f.addChild("Jhancy","Adi","male");
	f.addChild("Jhancy","Anu","male");
	f.addChild("Sobhana","Jyothy","Female");
	f.addChild("Jyothy","Dhrona","male");
	 f.addChild("Sobhana","Jeeja","Female");
	std::vector<node*> vSiblings;
	std::vector<node*> vRelatives;
	f.showFamily();
	f.siblings("Jeeja", vSiblings);
	cout << "Siblings of Jeeja: " << endl;
	Show(vSiblings);
	f.siblings("Dhrona", vSiblings);
	cout << "Siblings of Dhrona: " << endl;
	Show(vSiblings);
	f.getRelationship("Jyothy","son",vRelatives);
	Show(vRelatives);
	f.spouseUpdate("Jyothy","Omana","Sanish","Male");
	f.spouseUpdate("Jeeja","Ramani","Baiju","Male");
	f.spouseUpdate("Jhancy","Rajamma","Rajaneesh","Male");
	return 0;
}

