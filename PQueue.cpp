#include<iostream>
using namespace std;
#define size 5
class Pqueue
{
	struct data
	{
		int val;
		int p;
	}q[size];
	int front,rear;
public:	Pqueue();
	void insert(data);
	data dequeue();
	void display();
};

Pqueue::Pqueue()
{
	front=rear=-1;
}
void Pqueue::insert(data d)
{
	if( rear == size-1)
		cout<<"Queue full";
	else
	{
		rear++;
		d[rear]=d;
		if(front==-1)
			front=0;
		data temp;	
		for(int i=0;i<rear;i++)
			for(int j=i+1;j<=rear;j++)
			{
				if(d[i].p>d[j].p)
				{
					temp=d[i];
					d[i]=d[j];
					d[j]=temp;
				}	
				/*else
				{
					
				}	*/	
			}		
	}
}
data Pqueue::dequeue()
{
	struct data d;
	if(rear==-1)
		cout<<"Queue Empty";	
	else
	{
		d=data[front];
		if(front==rear)
			front=rear=-1;
		else
			front++;
	}
}
void Pqueue::display()
{
	for(int i=front; i<rear;i++)
	{
		cout<<q[i].value<<"with Priority:"<<q[i].p;
	}
}
int main()
{

	struct data d;
	char ch;
	Pqueue q1;
	
	do
	{
	  switch(ch)
	  {
		case '1':cout<<"Enter data & priority to insert:";
			 cin>>d.val>>d.p;
			q1.insert(data);
			break;
		case '2':	
			d=q1.dequeue();
			break;
		case '3': q1.display();
			break;
	  }
	}while(ch!='0');
	return 0;
} 
