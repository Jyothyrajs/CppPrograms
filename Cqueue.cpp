#include<iostream>
using namespace std;
#define size 5
class Cqueue
{
	int front,rear;
public:	Cqueue();
	void insert(int);
	int dequeue();
	void display();
};

Cqueue::Cqueue()
{
	front=rear=-1;
}
void Cqueue::insert(int data)
{
	if((front==rear-1) || (front==0 && rear == size-1))
		cout<<"Queue full";
	else
	{
		
	}
}
int Cqueue::dequeue()
{

}
void Cqueue::display()
{
}
int main()
{
	int data;
	char ch;
	Cqueue q1;
	
	do
	{
	  switch(ch)
	  {
		case '1':cout<<"Enter data to insert:";
			 cin>>data;
			q1.insert(data);
			break;
		case '2':	
			data=q1.dequeue();
			break;
		case '3': q1.display();
	  }
	}while(ch!='0');
	return 0;
} 
