//
//  main.cpp
//  LinkedList
//
//  Created by Jyothyraj S on 07/12/2020.
//

#include <iostream>
#include <Utilities/LList.hpp>
#include <Utilities/Tree.hpp>


const char* bool_cast(bool b)
{
    return b? "True":"False";
}
int main()
{
    LList l ;
    l.push(10);
    l.push(20);
    l.push(15);
    l.push(15);
    l.push(50);
    l.push(5);
    l.show();
    std::cout << "Element to search: " ;
    int element;
    std::cin >> element;
    std::cout << "Element found: "<< bool_cast(l.search(element)) << std::endl;
   
    std::cout << "Middle: "<< l.middle() << std::endl;
    LList d ;
    d.push(10);
    d.push(10);
    d.show();
    d.deleteDuplicateNodes();
    std::cout << "Dupplicates removed :";
    d.show();
    std::cout<< std::endl;
    LList s(true);
    s.push(1);
    s.reverse();
    s.show();
    s.deleteNode(1);
    s.reverse();
    s.show();
    s.push(23);
    s.push(5);
    s.push(18);
    s.show();
    s.deleteNode(5);
    s.show();
    s.reverse();
    s.show();
    s.deleteNode(23);
    s.show();
    std::cout << "Length of list : " << s.length() << std::endl;
    
    LList p(true);
    p.deleteNode(5);
    p.show();
    std::cout << "Length of list : " << p.length() << std::endl;
   
    LList l1;
    l1.push(1);
    l1.push(2);
    l1.push(3);
    l1.push(5);
    l1.push(6);
    l1.push(7);
   
    
    LList l2;
    l2.push(10);
    l2.push(20);
    l2.push(30);
    l2.push(40);
    l2.push(50);
    l2.push(60);
    l1.show();
    l2.show();
    
    std::cout << "L1 joining L2 : " << bool_cast(l1.isJoining(l2)) <<std::endl << std::endl;
   
    l1.merge(l2,5 );
    l1.show();
    l2.show();
    //bool join = l1.isJoining(l2);
    
    
    std::cout << "L1 joining L2 : " << bool_cast(l1.isJoining(l2)) <<std::endl << std::endl;
    
    LList loop;
    loop.push(2);
    loop.push(20);
    loop.push(200);
    loop.push(220);
    loop.makeLoop(2);
    loop.showLoop(4);
    std::cout << "Loop point :" << loop.whereLoop() << std::endl;
    std::cout << "Loop point :" << l1.whereLoop() << std::endl;
    
    l1.deleteLoop();
    
    loop.deleteLoop();

    try
    {
        LList ss(true, true);
    }
    catch(std::exception& ex)
    {
        std::cout <<"1. " << ex.what();
    }
        catch (LListException& e)
        {
            std::cout << e.what();

        }

     
    return 0;
}
