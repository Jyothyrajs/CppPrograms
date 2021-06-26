

#include<iostream>

void doNothing(int&)
{

}
int main()
{
    int x;
    std::cout<<"X : "<<x<<std::endl;
    doNothing(x);

    std::cout<<"X after fun call "<<x;
}

