

#include<iostream>
#include<cstdlib>
using namespace std;
	struct node
	{
		int data;
		node *left,*right;
	};
void traverse(node*);
class MyTree
{

	node *root;

public:
	MyTree()
	{
		root=NULL;
	}
	MyTree(const int a)
	{
		root=new node;
		root->data=a;
		root->left=NULL;
		root->right=NULL;
	}
	node* getRoot();
	void create(int[],int);
	void insert(int);
	bool search(node*,int);
	node* delete_node(node*,int);
	void inOrderTraversal();
};

void MyTree::create(int elements[],int count)
{
	int i;
	for(i=0;i<count;i++)
	{
		node *new_node=new node;
		new_node->data=elements[i];
		new_node->left=NULL;
		new_node->right=NULL;
		if(i==0)
		{
			root=new_node;
		}
		else
		{
			insert(elements[i]);
		}
	}
}

void MyTree::insert(int value)
{
	
	node *new_node=new node;
	new_node->data=value;
	new_node->left=NULL;
	new_node->right=NULL;
	if( root == NULL )
	{
		root = new_node;
		return;
	}

	node *temp = root;
	while(1)
	{
		if( value < temp->data )
		{
			if( temp->left == NULL )
			{
				temp->left = new_node;
				return;
			}
			else
			{
				temp = temp->left;
			}
		}
		else
		{
			if( temp->right == NULL )
			{
				temp->right = new_node;
				return;
			}
			else
			{
				temp = temp->right;
			}
		}
	
	}
	
}
bool MyTree::search(node *rnode,int element)
{
	
		node *temp=rnode;
		if(element == temp->data)
				return true;
		else if(element < temp->data && temp->left!=NULL)
		{
			search(temp->left,element);
		}
		else if(temp->right!=NULL)
		{
			search(temp->right,element);
		}
		else
			return false;
}
node* MyTree::delete_node(node *rnode, int element)
{
	node *temp;
	if(rnode==NULL)
		return rnode;
	if(element< rnode->data)
		rnode->left=delete_node(rnode->left,element);
	else if(element > rnode->data)
		rnode->right=delete_node(rnode->right,element);
	else
	{
		if(rnode->left==NULL)
		{
			temp=rnode;
			free(temp);
			return rnode->right;
		}
		if(rnode->right==NULL)
		{
			temp=rnode;
			free(temp);
			return rnode->left;
		}
		//Deleted node is somewhere in middle

		node *current=rnode->left;
		node *prev=current;
		node *temp=rnode;
		while(current->right!=NULL)
		{
			prev=current;
			current=current->right;
		}
		temp->data=current->data;
			if(current->left!=NULL)
			{
				prev->right=current->left;
			}
			else
			{
				prev->right=NULL;
			}
	//	temp->data=current->data;
		return temp;
	}
//	return rnode;
		
}

node* MyTree::getRoot()
{	
	if(root!=NULL)
		return root;
	return NULL;
}

void MyTree::inOrderTraversal()
{
	if(root!=NULL)
	{
	
		traverse(root->left);
		std::cout<<root->data<<" ";
		traverse(root->right);
	}
	return;
}

void traverse(node *rnode)
{
	if(rnode!=NULL)
	{
		traverse(rnode->left);
		std::cout<<rnode->data<<" ";
		traverse(rnode->right);
	}
	return;
}
int main()
{

	try{

		MyTree t1,t2;
		char ch;
		int elements[]={10,3,45,23,24,9,67,4,11},element;
		do
		{
			cout<<"\nInput your choice\n1.Create\n2.Insert\n3.Search\n4.Display(Traverse)\n5. Delete\n0.Exit\n";
			cin>>ch;
			switch(ch)
			{
			case '1':t1.create(elements,9);
				cout<<"Select display to see the tree\n";
				break;
			case '2':cout<<"Element to insert:";
				cin>>element;
				t1.insert(element);
				cout<<"Select display to see the tree\n";
				break;
			case '3':cout<<"Element to Search:";
				cin>>element;
				if(t1.search(t1.getRoot(),element))
					cout<<"Element found\n";
				else
					cout<<"element Not found\n";
				break;
			case '4':t1.inOrderTraversal();
				break;
			case '5':cout<<"Element to delete:";
				cin>>element;
				node *temp=t1.delete_node(t1.getRoot(),element);
				if(temp==NULL)
					cout<<"Element deleted\n";
				else
					cout<<"element Not found\n";
				break;
			}
		}while(ch!='0');

	}
	catch(const char *msg)
	{
		std::cout<<"Exception: ";
		std::cerr<<msg<<std::endl;
	}
}

