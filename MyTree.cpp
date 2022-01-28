

#include<iostream>
#include<cstdlib>
using namespace std;
	struct node
	{
		int data;
		node *left,*right;
	};
void insert_left(node*,node*);
void insert_right(node*,node*);
int max(int,int);
void traverse(node*);
void swap_child(node *);
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
	void mirror(node*);
	int level(node*);
	void inOrderTraversal();
	int level()
	{
		level(root);
	}
	void merge(node*);		
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
		node *prev;
		while(current->right!=NULL)
			{
			prev=current;
			current=current->right;
			}
		if(current->left!=NULL)
		{
			prev->right=current->left;
		}
		else
		{
			prev->right=NULL;
		}
		rnode->data=current->data;
/*		node *current=rnode;
		while (current->right!=NULL)
		    if(current->left!=NULL)
			current=current->left;
		    else
			break;
		rnode->data=current->data;
		rnode->left=current->left;
		rnode->right=delete_node(rnode->right,rnode->data);
*/	}
	return rnode;
		
}
void MyTree::mirror(node* rnode)
{
	node *temp=rnode;
	if(temp!=NULL)
	{
		swap_child(temp);
		mirror(temp->left);
		mirror(temp->right);
	}
}

void swap_child(node *rnode)
{
	node *temp=new node;
	temp= rnode->left;
	rnode->left= rnode->right;
	rnode->right=temp;
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
int max(int l, int r)
{
	return ((l>r)?l:r);
}

int MyTree::level(node *rnode)
{
	int l;
	node *temp=rnode;
	if(temp==root)
		l=0;
	if(temp->left!=NULL && temp->right!=NULL )
	{
		return( 1 +( max(level(temp->left),level(temp->right) )) );
	}
	else if(temp->left!=NULL)
		return (1+level(temp->left));
	else if(temp->right!=NULL)
		return (1+level(temp->right));
	else
		return 0;
		
}
void MyTree::merge(node *rnode)
{
	node *temp=rnode;
	if(temp!=NULL)
	{
		insert(temp->data);
		merge(temp->left);
		merge(temp->right);
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
				if(temp!=NULL)
					cout<<"Element deleted\n";
				else
					cout<<"element Not found\n";
				break;
			}
		}while(ch!='0');

/*		
		t1.insert(55);
		node *r=t1.getRoot();
		std::cout<<"t1(Single element): ";		
		t1.inOrderTraversal();
		std::cout<<std::endl;		
		std::cout<<"...........Create t1.......... "<<std::endl;		
		t1.create(elements,14);
		t1.inOrderTraversal();
		std::cout<<std::endl;		
		
		t2.insert(44);
		t2.insert(100);
		node *r3=t2.getRoot();
		std::cout<<"-----------Merge(t1,t2)............ "<<std::endl;		
		t1.merge(r3);
		t1.inOrderTraversal();
		std::cout<<std::endl;		
		std::cout<<std::endl;		
		std::cout<<"..........Search........... "<<std::endl;		
		std::cout<<"Element:";
		std::cin>>element;
		std::cout<<std::boolalpha<<t1.search(r3,element)<<std::endl;
		std::cout<<"..........Insertion........... "<<std::endl;		
		std::cout<<"Element:";
		std::cin>>element;
		t1.insert(element);	
		std::cout<<"\nAfterInsertion: ";
		t1.inOrderTraversal();
		std::cout<<"\n";
		std::cout<<"..........Level........... "<<std::endl;		
		std::cout<<"level: "<<t1.level(r3)<<"\n";
		std::cout<<"..........Mirror Image........... "<<std::endl;		
		t1.inOrderTraversal();
		std::cout<<"\n";
*/	}
	catch(const char *msg)
	{
		std::cout<<"Exception: ";
		std::cerr<<msg<<std::endl;
	}
}

