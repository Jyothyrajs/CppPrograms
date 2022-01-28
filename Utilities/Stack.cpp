//
//  Stack.cpp
//  Utilities
//
//  Created by Jyothyraj S on 08/12/2020.
//
#include <iostream>
#include "Stack.hpp"


void Stack::push ( int element )
{
    Node* newNode = new Node(element);
    newNode->next = nullptr;
    if ( top == nullptr )
    {
        top = newNode;
    }
    else
    {
        newNode->next = top;
        top = newNode;
    }
}

void Stack::pop (  )
{
    if ( top == nullptr )
    {
        return ;
    }
    else
    {
        Node* temp = top;
        top = top->next;
        std::cout << "popped " << temp->data <<"\n";
        delete temp;
    }
}

bool Stack::search ( int element )
{
    if ( top == nullptr )
    {
        return false;
    }
    else
    {
        Node* temp = top;
        while ( temp )
        {
            if ( temp->data == element )
                return true;
            else
                temp = temp->next;
        }
        return false;
    }
}


bool Stack::isEmpty ()
{
    return (top == nullptr );
}


void Stack::empty()
{
    while ( top )
    {
        pop();
    }
}

int Stack::stackTop ()
{
    if (top )
    {
        return top->data;
    }
    return 0;
}

void Stack::display ()
{
    Node* temp = top;
    std::cout << "Stack elements: ";
    while ( temp )
    {
        std::cout << temp->data <<"\t";
        temp = temp->next;
    }
    std::cout << std::endl;
}
