//
//  Animal.h
//  myInheritance
//
//  Created by Jyothyraj S on 18/01/2021.
//

#ifndef Animal_h
#define Animal_h
#include <string_view>
#include <iostream>

class Animal
{
protected:
    std::string m_name;
    std::string m_sound;

public:
    Animal():m_name{"Wild"},m_sound{"Roar"}
    {
        
    }
    Animal(std::string_view name):m_name{name},m_sound{"Roar"}
    {
        
    }
    Animal(std::string_view name, std::string_view sound):m_name{name},m_sound{sound}
    {
        
    }
    std::string_view getName()
    {
        return m_name;
    }
    std::string_view speak()
    {
        return m_sound;
    }
    
    void report( )
    {
        std::cout<< getName() << " Speaks " << speak() << std::endl;
    }
};

class Cat:public Animal
{
public:
    Cat( std::string_view name ): Animal{ name }
    {
        
    }
    Cat( std::string_view name,std::string_view sound ): Animal{ name, sound }
    {
        
    }
};


class Dog:public Animal
{
    public:
    Dog( std::string_view name, std::string_view sound):Animal{name,sound}
    {
        
    }
};

#endif /* Animal_h */
