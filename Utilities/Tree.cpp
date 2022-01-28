//
//  Tree.cpp
//  Utilities
//
//  Created by Jyothyraj S on 03/12/2020.
//

#include "Tree.hpp"
#include <iostream>

Tree::Tree()
{
    
}

Tree::~Tree()
{
    deleteTree(root);
}

void Tree::insert(int element)
{
   
    Node* newNode = new Node(element);
    if ( root == nullptr)
    {
        root = newNode;
    }
    else
    {
        Node* temp = root;
        while ( temp != nullptr )
        {
            if ( element < temp->data )
            {
                if ( temp->left == nullptr)
                {
                    temp->left = newNode;
                    temp= newNode->left;
                }
                else
                    temp = temp->left;
            }
            else
            {
                if ( temp->right == nullptr)
                {
                    temp->right = newNode;
                    temp = newNode->right;
                }
               else
                   temp =temp->right;
                
            }
        }
    }
}


void Tree:: inorder ( Node* root )
{
    Node* temp = root;
    if( temp!=nullptr )
    {
        inorder(temp->left);
        std::cout << temp->data <<"\t";
        inorder(temp->right);
    }
   
}
void Tree::preorder ( Node* root )
{
    Node* temp = root;
    if ( temp )
    {
        std::cout << temp->data << "\t";
        preorder(temp->left);
        preorder(temp->right);
    }
}


void Tree::postorder ( Node* root )
{
    Node* temp = root;
    if ( temp )
    {
        postorder(temp->left);
        postorder(temp->right);
        std::cout << temp->data <<"\t";
    }
}

void Tree::leaves( Node* root )
{
    Node* temp = root;
    if ( temp )
    {
        leaves(temp->left);
        leaves(temp->right);
        if ( temp->left == nullptr && temp->right == nullptr)
        {
            std::cout << temp->data <<"\t";
        }
    }
}

void Tree::dfs ( Node* root )
{
    if ( root == nullptr )
        return;
    else
    {
        std::cout << root->data << "\t";
        dfs(root->left);
        dfs(root->right);
    }
}



void Tree:: printgivenlevel( Node* root, int level )
{
    if ( root == nullptr )
        return;
   if ( level == 1)
    {
        std::cout << root->data << "\t";
    }
    if ( level > 1)
    {
        printgivenlevel ( root->left, level-1 );
        printgivenlevel ( root->right, level-1 );
 
    }
    
}


void Tree::levelorder( Node* root )
{
    std::cout << "LEVEL ORDER " << std::endl;
    if ( root == nullptr)
        return ;
    else
    {
        int height = depth(root);
        for ( int i = 1; i <= height; i++ )
        {
            printgivenlevel(root,i);
        }
        
    }
}

Tree::Node* Tree::deleteNode ( Node* root, int key )
{
    if ( root == nullptr )
    {
        return root;
    }
    
    else
    {
        if ( key < root->data )
        {
            root->left = deleteNode( root->left , key );
        }
        else if ( key > root->data )
        {
            root->right = deleteNode( root->right, key );
        }
        else
        {
                 if( root->left == nullptr )
                 {
                   Node* temp = root->right ;
                    free(root);
                    return temp;
                }
                if( root->right == nullptr )
                {
                  Node* temp = root->left ;
                   free(root);
                   return temp;
               }
            else
            {
                Node* temp = minValueNode(root->right);
                root->data = temp->data;
                root->right = deleteNode(root->right,temp->data);
            }
        }
    }
    return root;
}

Tree::Node* Tree::minValueNode( Node* root )
{
    Node* current = root;
    while (  current->left )
    {
        current = current->left;
    }
    return current;
}

int Tree::minValue ( )
{
    Node* temp = root;
   
    while ( temp->left )
    {
        temp = temp->left;
    }
    return temp->data;
}


int Tree::maxValue ( )
{
    Node* temp = root;
   
    while ( temp->right )
    {
        temp = temp->right;
    }
    return temp->data;
}


int Tree::size( Node* root )
{
    
    if ( root == nullptr )
        return 0;
    else
        return ( size(root->left) + 1 + size(root->right) );
}

int Tree::depth( Node* root )
{
    if  ( root == nullptr )
    {
        return 0;
    }
    else
    {
        int leftdepth = depth( root->left );
        int rightdepth = depth( root->right );
        if ( leftdepth > rightdepth )
        {
            return ( 1 + depth(root->left) );
        }
        else
            return ( 1 + depth(root->right) );
        
    }
}

bool Tree::identical ( Node* root1, Node* root2)
{
    if ( root1 == nullptr && root2 == nullptr )
        return true;
    else
    {
        if ( ( root1->data == root2->data ) && ( identical ( root1->left, root2->left) ) && ( identical ( root1->right, root2->right) ))
            return  true;;
    }
    return false;
}

void Tree::deleteTree(Node* root)
{
    if ( root == nullptr )
        return ;
    deleteTree( root->left );
    deleteTree( root->right );
    std::cout << "Deleting :" << root->data << std::endl;
    delete root;
    
}

void Tree::mirror ( Node* root)
{
    if ( root == nullptr )
    {
        return;
    }
    mirror ( root->left);
    mirror(root->right);
    Node* temp = root->left;
    root->left = root->right;
    root->right = temp;
    
}
