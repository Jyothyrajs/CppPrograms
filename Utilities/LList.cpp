//
//  LList.cpp
//  Utilities
//
//  Created by Jyothyraj S on 27/11/2020.
//

#include<iostream>
#include "LList.hpp"


LList::LList(bool sort, bool circular)
    : isSorted(sort)
    , isCircular(circular)
{
    head = nullptr;
    
    if( isSorted && isCircular )
    {
        throw LListException("Error: Attempting to create circular sorted list");
    }
}

LList::~LList()
{
    Node *temp ;
    while ( head!=nullptr )
    {
        temp = head;
        head = head ->next;

        // delete temp;
    }
}

int LList::length()
{
    int len = 0;
    Node* temp = head;
    while( temp != nullptr )
    {
        len++;
        temp = temp->next;
    }
    return len;
}

void LList::push(int element)
{
    Node* temp = new Node(element);

    if( isSorted )
    {
        sortedPushBack(temp);
    }
    else
    {
        unsortedPushBack(temp);
    }
}

void LList::sortedPushBack(Node* temp)
{
    std::cout << "Inserting " <<temp->data << std::endl;
    Node* current = head;
    Node* previous = nullptr;
    for(; current !=nullptr && current->data < temp->data; current = current->next )
    {
        previous = current;
    }
    
    if ( previous == nullptr )
    {
        temp->next = head;
        head = temp;
    }
    else
    {
        previous->next = temp;
        temp->next = current;
    }
}

void LList::unsortedPushBack(Node* temp)
{
    Node* current = head;
    
    if ( nullptr == head )
    {
        head = temp;
        return;
    }
    
    while( current->next!=nullptr )
    {
        current = current->next;
    }
    
    current->next = temp;
}

void LList::deleteNode(int element)
{
    if ( head!= nullptr )
    {
        Node* temp = head;
        if ( head->data == element )
        {
            head = head->next;
            delete temp;
            std::cout << "deleted " << element << std::endl;
        }
        else
        {
            Node* current = temp;
            while ( temp->next != nullptr && temp->next->data != element )
            {
                current = current->next;
                temp = temp->next;
            }
            if( temp->next != nullptr)
            {
                temp = temp->next;
                current->next = current->next->next;
                delete temp;
                std::cout << "deleted " << element << std::endl;
            }
        }
    }
}

void LList::deleteDuplicateNodes ( )
{
    Node* temp;
    Node* current = head;
    if ( current != nullptr)
    {
    while ( current != nullptr && current->next != nullptr )
    {
        temp = current;
        while ( temp->next != nullptr && current->data != temp->next->data )
        {
            temp = temp->next;
        }
        if ( temp->next != nullptr )
        {
            Node* dup = temp->next;
            temp->next = temp->next->next;
            delete dup;
        }
        current = current->next;
    }
    }
}

bool LList::search(int element)
{
    bool found= false;
    Node* temp = head;
    while (temp != nullptr && temp->data != element )
    {
        temp = temp->next;
    }
    if(temp != nullptr)
    {
        found = true;
    }
    return  found;
}

int LList::middle ( )
{
    
    Node* slow_ptr = head;
    Node* fast_ptr = head;
    while ( fast_ptr->next && fast_ptr->next->next )
    {
        slow_ptr = slow_ptr->next;
        fast_ptr = fast_ptr->next->next;
    
    }
    std::cout << "Middle: "<< slow_ptr->data <<"\n";
    return  slow_ptr->data;
}


void LList::reverse()
{
    Node* current = head;
    Node* previous = nullptr;
    Node* temp;
    while ( current != nullptr)
    {
        temp = current->next;
        current->next = previous;
        previous = current;
        current = temp;
    }
    head = previous;
    std::cout << "List reversed " << std::endl;
}

void LList::merge(LList& l,int pos)
{
    Node* temp1 = head;
    while ( --pos )
    {
        temp1 = temp1->next;
    }
    Node* temp2 = l.head;
    while ( temp2 ->next)
    {
        temp2 = temp2->next;
    }
    temp2->next = temp1;
    
}

bool LList::isJoining(LList& l)
{
        int len1 = this->length();
        int len2 = l.length();

    
        Node* temp1 = this->head;
        Node* temp2 = l.head;
        
        if ( len1 > len2 )
        {
            int diff = len1 - len2;
            for ( int i = diff; i > 0; i--)
            {
                temp1 = temp1->next;
            }
            
        }
        if ( len2 > len1 )
        {
            int diff = len2 - len1;
            for ( int i = diff; i > 0; i--)
            {
                temp2 = temp2->next;
            }
            
        }
        while ( temp1 != temp2)
        {
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        return ( temp1!= nullptr && temp1 == temp2 );
    
}
    
void LList::makeLoop( int pos )
{
    Node* temp = head;
    while ( --pos )
    {
        temp = temp->next;
    }
    Node* joinPoint = temp;
    while ( temp->next)
    {
        temp = temp->next;
    }
    temp->next = joinPoint;
    
}
LList::Node* LList::whereLoop()
{
    Node* slow_ptr = head;
    Node* fast_ptr = head;
    while ( fast_ptr->next && fast_ptr->next->next )
    {
        slow_ptr = slow_ptr->next;
        fast_ptr = fast_ptr->next->next;
        
        if( slow_ptr == fast_ptr )
        {
            slow_ptr = head;
            while ( slow_ptr != fast_ptr )
            {
                slow_ptr = slow_ptr->next;
                fast_ptr = fast_ptr->next;
            }
            std::cout << "Loop exist ";
            return fast_ptr;
        }
        
    }
    return nullptr;
}


void LList::deleteLoop()
{
    Node* loop_entry = whereLoop();
    if(loop_entry)
    {
        Node* previous ;
        for ( Node* temp = loop_entry->next; temp!=loop_entry; temp = temp->next)
        {
            previous = temp;
        }
        std::cout << "Removing loop \n";
        previous->next = nullptr;
    }
    else
    {
        std::cout <<"No loop \n" << std::endl;
    }
}


	
void LList::show()
{
    for( Node* temp = head; temp!=nullptr; temp = temp->next )
    {
        std::cout << temp->data << "->";
    }
    
    std::cout << "nullptr" << std::endl << std::endl <<std::endl;
}

void LList::showLoop ( int count)
{
    Node* temp = head;
    for (; count;  count--,temp = temp->next )
    {
        std::cout << temp->data << "->" ;
    }
    std::cout << temp->data << std::endl << std::endl <<std::endl;
}
