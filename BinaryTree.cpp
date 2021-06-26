#include "BinaryTree.h"
#include <iostream>
 
BinaryTree::Node::Node(int n)
{
	data=n;
	left=NULL;
	right=NULL;
}

BinaryTree::BinaryTree()
{
	root=NULL;
}

BinaryTree::BinaryTree(const BinaryTree &t1)
{
	root=copyTree(t1.root);
}

BinaryTree::~BinaryTree()
{
	std::cout<<std::endl<<"Deleting"<< "\n";
	if(root!=NULL)
		remove(root);
}

void BinaryTree::remove(Node *t)
{
	if(t->left!=NULL)
	{
		remove(t->left);
	}
	if(t->right!=NULL)
	{
		remove(t->right);
	}
	std::cout<<t->data<<" ";
	delete t;
}

BinaryTree::Node* BinaryTree::copyTree(Node* src )
{
	if(src)
	{
		Node* new_node = new Node(src->data);
		new_node->left = copyTree(src->left);
		new_node->right = copyTree(src->right);
		return new_node;
	}
	return NULL;
}

void BinaryTree::insert(int element)
{
	Node *new_node=new Node(element);
	if(root==NULL)
	{
		root=new_node;
		return;
	}
	Node* temp=root;
	while(1)
	{
		if(element<temp->data)
		{
			if(temp->left==NULL)
			{
				temp->left=new_node;
				return;
			}
			temp=temp->left;
		}
		else
		{
			if(temp->right==NULL)
			{
				temp->right=new_node;
				return;
			}
			temp=temp->right;
			
		}
	}
}
void BinaryTree::in_traverse(Node *temp)
{
	if(temp!=NULL)
	{
		in_traverse(temp->left);
		std::cout<<temp->data<<" ";
		in_traverse(temp->right);
	}
}
void BinaryTree::inorder_traverse()
{
	std::cout<<"In-order Traverse:";
	if(root!=NULL)
	{
		in_traverse(root->left);
		std::cout<<root->data<<" ";
		in_traverse(root->right);
	}
	std::cout<<"\n";
	return;
}
void BinaryTree::pre_traverse(Node *temp)
{
	if(temp!=NULL)
	{
		std::cout<<temp->data<<" ";
		pre_traverse(temp->left);
		pre_traverse(temp->right);
	}
	return;
}
void BinaryTree::preorder_traverse()
{
	std::cout<<"Pre-order Traverse:";
	if(root!=NULL)
	{
		std::cout<<root->data<<" ";
		pre_traverse(root->left);
		pre_traverse(root->right);
		
	}
	std::cout<<"\n";
	return;
}
void BinaryTree::post_traverse(Node *temp)
{
	if(temp!=NULL)
	{
		post_traverse(temp->left);
		post_traverse(temp->right);
		std::cout<<temp->data<<" ";
	}
	return;
}
void BinaryTree::postorder_traverse()
{
	std::cout<<"Post-order Traverse:";
	if(root!=NULL)
	{
		post_traverse(root->left);
		post_traverse(root->right);
		std::cout<<root->data<<" ";
		
	}
	std::cout<<"\n";
	return;
	
}

int BinaryTree:: max(int l, int r)
{
	return ((l>r)?l:r);
}
int BinaryTree::hight()
{
	if(root!=NULL)
	{
		return tree_hight(root);
	}
	else 
		return 0;
}
int BinaryTree::tree_hight(Node* temp)
{
	if(temp->left!=NULL && temp->right!=NULL )
	{
		return( 1 +( max(tree_hight(temp->left),tree_hight(temp->right) )) );
	}
	else if(temp->left!=NULL)
		return (1+tree_hight(temp->left));
	else if(temp->right!=NULL)
		return (1+tree_hight(temp->right));
	else
		return 0;
	
}
void BinaryTree::convert_to_mirror()
{
	std::cout<<"Mirror Image"<<"\n";
	if(root!=NULL)
		mirror_image(root);
}
void BinaryTree::mirror_image(Node* rnode)
{
	Node *temp=rnode;
	if(temp!=NULL)
	{
		swap_child(temp);
		mirror_image(temp->left);
		mirror_image(temp->right);
	}
}

void BinaryTree:: swap_child(Node *rnode)
{
	Node *temp;
	temp= rnode->left;
	rnode->left= rnode->right;
	rnode->right=temp;
}
void BinaryTree::merge(BinaryTree &t)
{
	mergeTree(t.root);
}
	
void BinaryTree::mergeTree(Node *temp)
{
	if(temp!=NULL)
	{
		insert(temp->data);
		mergeTree(temp->left);
		mergeTree(temp->right);
	}
	return;
}
int main()
{
	BinaryTree t;
/*
	t.insert(10);
	t.insert(100);
	t.insert(5);
	t.insert(45);
	t.insert(2);
	t.insert(41);
	t.insert(35);
	t.insert(15);
	t.insert(8);
	t.insert(63);
	t.insert(41);
	t2.insert(1);
	t2.insert(82);
	t2.insert(613);
	t2.insert(14);
	std::cout<<".......t1........."<<std::endl;
	t.inorder_traverse();
	t.preorder_traverse();
	t.postorder_traverse();
	BinaryTree t2(t);
	t3.inorder_traverse();
	t3.insert(68);	
	std::cout<<"t2(+68):";
	t3.inorder_traverse();
	std::cout<<"\n";
	std::cout<<"Hight of tree: "<<t.hight()<<"\n";
	t.convert_to_mirror();
	t.inorder_traverse();
	t2.inorder_traverse();
	std::cout<<"\n";
//	t3.merge(t2);
	t2.inorder_traverse();
	*/std::cout<<"\n";

	
}

