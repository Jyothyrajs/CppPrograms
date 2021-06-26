//
//  Wireless.hpp
//  myInheritance
//
//  Created by Jyothyraj S on 21/01/2021.
//

#ifndef Wireless_hpp
#define Wireless_hpp

#include <iostream>
#include <string_view>
#include <array>

class Wireless
{
protected:
    std::string name;
    int speed;
public:
    Wireless(std::string conName , int conSpeed ) : name{conName},speed{conSpeed}
    {
        
    }
    std::string getName()
    {
        return name;
    }
    int getSpeed()
    {
        return speed;
    }
    
};

class Bluetooth:public Wireless
{
protected:
    
    
    int devices[5]{};
    
public:
    Bluetooth( std::string bName, int bSpeed, int dev[5] ): Wireless{bName,bSpeed},devices{dev}
    {
        
    }
    
};

class WiFi: public Wireless
{
protected:
    int deviceCount;
public:
    WiFi( std::string wName, int wSpeed, int wDev) : Wireless( wName, wSpeed ), deviceCount{wDev}
    {
        
    }
    
    
};

#endif /* Wireless_hpp */
