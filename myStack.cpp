#include <iostream>
#define size 4
using namespace std;
class Stack
{
	int top;
	int elements[size];
	public:
		Stack();	
		bool empty();
		bool full();
		void push(int);
		int pop();
		void display();

};
 Stack::Stack()
	{
		top=-1;
	}

 bool Stack::empty()
	{
		if( top == -1 )
			return true;
		else
			return false;
	}
 bool Stack::full()
	{
		if( top == size )
			return true;
		else
			return false;
	}
void Stack::push(int data)
{
	if( !full() )
	{
		elements[++top]=data;
	}
	else
	{
		cout << "Stack full " << endl;
	}
}

int Stack::pop()
{
	if( !empty() )
	{
		cout<<elements[top]<<" Element deleted \n";
		return elements[top--];
	}
	else
	{
		cout << "Stack empty " << endl;
		return -1;
	}
}
void Stack::display()
{
	for(int i=top;i>-1;i--)
		cout<<elements[i]<<"\t";
	cout<<"\n";

}
int main()
{
	Stack s;
	char ch;
	int data;
	do
	{
		cout<<"1.Push\n2:Pop\n3.Display\nq.Quit:";
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
		}
	}while( ch != 'q');				
	cout << endl;	
}
