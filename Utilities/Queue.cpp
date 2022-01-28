//
//  Queue.cpp
//  Utilities
//
//  Created by Jyothyraj S on 11/12/2020.
//

#include "Queue.hpp"

Queue::Queue(int n):max(n)
{
    qa = new int[max];
    front  = -1;
    rear = -1;
}

bool Queue::isEmpty()
{
    if( front == -1  && rear == -1 )
    {
        return true;
    }
    else
        return false;
}

bool Queue::isFull()
{
    if( front == 0 && rear == max )
    {
        return true;
    }
    else
        return false;
}

void Queue::insertEnd ( int element )
{
    
    if (isFull())
        return;
    if ( front == -1)
    {
        front++;
    }
    qa[++rear] = element;
}

int Queue::deletefront ( )
{
    
    int element = qa[front];
    front++;
    if ( front > rear)
    {
        front = -1;
        rear = -1;
    }
    return element;
}

int Queue::frontElement()
{
    if( !isEmpty() )
        return qa[front];
    return -1;
}
