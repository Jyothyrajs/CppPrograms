//
//  Queue.hpp
//  Utilities
//
//  Created by Jyothyraj S on 11/12/2020.
//

#ifndef Queue_hpp
#define Queue_hpp

#include <iostream>
class Queue
{
    
    int front;
    int rear;
    int max;
    int *qa;

public:
    Queue(int n);
    int deletefront();
    void insertEnd( int element );
    bool isEmpty();
    bool isFull();
    int frontElement();
};

#endif /* Queue_hpp */
