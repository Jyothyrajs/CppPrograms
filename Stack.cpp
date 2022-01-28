#include <iostream>
#define size 4
using namespace std;
class Stack
{
	int top;
	int elements[size];
	public:
		Stack();
		Stack(const Stack &);	
		void push(int);
		int pop();
		void display();
		bool isEmpty();
		bool isFull();

};
 Stack::Stack()
	{
		top=-1;
	}

 Stack::Stack(const Stack& S)
	{
		top=-1;
		for(int i=0;i<=S.top;i++)
		{
			elements[++top]=S.elements[i];	
		}
	}
void Stack::push(int data)
{
	if(!isFull())
		elements[++top]=data;
	else
		cout<<"Stack Full\n";
}

int Stack::pop()
{
	if(!isEmpty())
	{
		cout<<elements[top]<<" Element deleted \n";
		int data=elements[top];
		top--;
		return data;
	}
		cout<<"Stack Empty\n";
}
void Stack::display()
{
	for(int i=top;i>=0;i--)
		cout<<elements[i]<<"\t";
	cout<<"\n";

}
bool Stack::isEmpty()
{
	if(top==-1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Stack::isFull()
{
	if(top==size-1)
	{
		return true;
	}
	else
	{
		return false;
		
	}
}
int main()
{
	Stack s;
	char ch;
	int data;
	bool v;
	do
	{
		cout<<"1.Push\n2:Pop\n3.Display\n4.isEmpty\n5.isFull\n6.Copy Constructor\nq.Quit:";
		cin>>ch;
		switch(ch)
		{
			case '1':				
				cout<<"Element:";
				cin>>data;
				s.push(data);
				break;
			case '2':
				cout<<s.pop();
				break;
			case '3':
				s.display();
				break;		
			case '4':
				v=s.isEmpty();
				if(v)
					cout<<"Stack empty";
				else
					cout<<"Stack Not empty";
				break;
			case '5': 
				v=s.isFull();
				if(v)
					cout<<"Stack full";
				else
					cout<<"Stack Not full";
				break;
			case '6': Stack S2(s);
				s.display();
				cout<<"Copied Stack:";
				S2.display();		
}
		cout<<"\n";
	
	}while(ch!='q');
}
