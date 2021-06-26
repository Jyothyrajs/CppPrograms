//
//  Stack.hpp
//  Utilities
//
//  Created by Jyothyraj S on 08/12/2020.
//

#ifndef Stack_hpp
#define Stack_hpp

#include <stdio.h>


class Stack
{
    class Node
    {
    public:
        int data;
        Node* next;
        Node(int n):data(n)
        {
            
        }
    };
    Node* top = nullptr;
public:
    Stack()
    {
    }
    ~Stack()
    {
        
    }
    
    void push(int element);
    void pop();
    bool isEmpty();
    void empty();
    int stackTop();
    bool search(int element);
    void display();
};


#endif /* Stack_hpp */
