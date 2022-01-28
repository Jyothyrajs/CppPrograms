//
//  LList.hpp
//  Utilities
//
//  Created by Jyothyraj S on 27/11/2020.
//

#ifndef LList_hpp
#define LList_hpp

#include <exception>

class LList
{
    class Node
    {
    public:
        int data;
        Node* next = nullptr;
        Node(int n) : data(n)
        {
        }
        
    };
    
    Node* head = nullptr;
    bool isSorted;
    bool isCircular;

public:
    LList(bool sort = false, bool circular = false);
    ~LList();

    int length();
    void push(int element);
    void sortedPushBack(Node* element);
    void unsortedPushBack(Node* element);
    void deleteNode(int element);
    void deleteDuplicateNodes();
    bool search(int element);
    int middle();
    void reverse();
    void merge(LList& l, int pos);
    bool isJoining(LList& l);
    void makeLoop(int point);
    Node* whereLoop();
    void deleteLoop();
    
    void pushSortedCircular(int element);
    void show();
    void showLoop(int count);
    
};

class LListException : public std::exception
{
    std::string error;
public:
    LListException(std::string _error)
        : error(_error)
    {}
    const char* what() const noexcept
    {
        return error.c_str();
    }
    
};

#endif /* LList_hpp */
