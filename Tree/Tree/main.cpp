//
//  main.cpp
//  Tree
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
  
    Tree t;
   t.insert(10);
    t.insert(20);
    t.insert(30);
    t.insert(12);
    t.insert(5);
    t.insert(22);
    t.insert(15);
    
  //  t.insert(23);
   // t.insert(9);
    
    t.inorder(t.root);
    std::cout << std::endl ;
    std::cout << ":Leaves: " ;
    t.leaves(t.root);
    std::cout << std::endl;
   
    t.preorder(t.root);
    std::cout << std::endl;
   
    t.postorder(t.root);
    std::cout << std::endl;
  
    t.levelorder(t.root);
    std::cout << std::endl;
    
    t.dfs(t.root);
    
 /*   std::cout << "MaxValue " << t.maxValue()<< std::endl;
    std::cout << "MinValue " << t.minValue()<< std::endl;
    std::cout << "Depth of tree: " << t.depth(t.root)<< std::endl;
   std::cout << std::endl;
    std::cout << "Deletion\n";
    std::cout << "Tree size : "<< t.size(t.root) <<  std::endl;
    t.deleteNode(t.root, 20);
    std::cout << "Tree size after deletion : "<< t.size(t.root) <<  std::endl;;
    t.inorder(t.root);
    std::cout << "\nDeleting " << std::endl;
    t.deleteNode(t.root, 5);
    t.inorder(t.root);
    std::cout << std::endl;
    std::cout << "MaxValue " << t.maxValue()<< std::endl;
    std::cout << "MinValue " << t.minValue()<< std::endl;
    std::cout << "Depth of tree: " << t.depth(t.root)<< std::endl;
    Tree t1;
    t1.insert(10);
     t1.insert(20);
     t1.insert(30);
     t1.insert(12);
     t1.insert(5);
     t1.insert(23);
     t1.insert(9);
    Tree t2;
    t2.insert(10);
     t2.insert(20);
   t2.insert(25);
     t2.insert(30);
     t2.insert(12);
     t2.insert(5);
     t2.insert(23);
     t2.insert(9);
    std::cout << "Is t1 == t2 : " << bool_cast(t.identical(t1.root, t2.root))<< std::endl;
    t1.deleteTree(t1.root);
    std::cout << std::endl;
    t2.inorder(t2.root);
    std::cout << std::endl;
    t2.mirror(t2.root);
    t2.inorder(t2.root);
    std::cout << std::endl;
    t2.mirror(t2.root);
    t2.inorder(t2.root);
    std::cout << std::endl;

  */
  
  }
