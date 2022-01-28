//
//  Tree.hpp
//  Utilities
//
//  Created by Jyothyraj S on 03/12/2020.
//

#ifndef Tree_hpp
#define Tree_hpp

class Tree
{
    class Node
    {
    public:
        int data;
        Node* left = nullptr;
        Node* right = nullptr;
        Node(int n): data(n)
        {
            
        }
    };
   
public:
    Node* root = nullptr;
    Tree();
    ~Tree();
    void insert( int element );
    void inorder( Node* root );
    void preorder( Node* root );
    void postorder( Node* root );
    void levelorder( Node* root );
    void leaves( Node* root);
    void dfs(Node* root);
    void printgivenlevel( Node* root, int level );
    Node* deleteNode( Node* root, int key );
    Node* minValueNode( Node* root );
    int minValue();
    int maxValue();
    int size( Node* root );
    int depth( Node* root );
    bool identical( Node* root1, Node* root2 );
    void deleteTree(Node* root);
    void mirror(Node* root);
};

#endif /* Tree_hpp */
