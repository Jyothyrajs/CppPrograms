//
//  main.cpp
//  myInheritance
//
//  Created by Jyothyraj S on 18/01/2021.
//

#include <iostream>
#include <array>
#include "Animal.h"
#include "Wireless.hpp"
int main(int argc, const char * argv[])
{
   
    Animal dog("Dog","Bow");
    Animal *pAnimal { &dog };
    pAnimal->report();
    
    Cat cat("Cat","Mew");
    pAnimal = &cat;
    pAnimal->report();
    
    //Array of Cats
    auto arAnimals{std::array<Animal,2> {Animal{"Cat","Mew"}, Animal{"Dog","bow"} }};
    for( auto animal:arAnimals)
    {
        animal.report();
    }
    
    auto arrAnimals { std::array <Animal,2>({cat,dog}) };
    for( auto animal:arrAnimals)
    {
        animal.report();
    }
    
    
    auto paAnimals { std::array <Animal*, 2>({&cat,&dog}) };
    for(  auto panimal : paAnimals )
    {
         panimal->report();
    }
    std::array<int,3> p_devices = { 1,2,3};
    
    Wireless w1("Bluetooth",20,5);
    Wireless w2("WiFi",5);
    std::cout << w1.getName() << std::endl;
    std::cout << w2.getName() << std::endl;

    return 0;
}
