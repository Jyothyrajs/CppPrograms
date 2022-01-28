#include<iostream>
#include<cstdlib>
using namespace std;
struct node 
{
	int data;
	node *next;
	node *prev;
};
class LinkedList
{
	node *first;
	public:LinkedList()
	{
		first=NULL;	
	}	
	bool empty()
	{
		if(first!=NULL)
			return false;
		else 
			return true;
	}
	void insert_beg(int);
	int delete_beg();
	void delete_element(int);
	void display();
	int search(int);
};

//Insert at the beginning of the list
void LinkedList::insert_beg(int d)
{
	node *temp=new node;
	temp->data=d;
	temp->next=first;
	temp->prev=NULL;
	first=temp;	
	cout<<d<<" inserted in the beginning\n";
}
//Delete from beginning of the list
int LinkedList::delete_beg()
{
	node *temp;
	int d= first->data;
	temp=first;
	if(first->next!=NULL)
	{
		first=first->next;	
		first->prev=NULL;
	}
	first=NULL;
	return d;
}

//Delete the specified element from the list
void LinkedList::delete_element(int d)
{
	int pos=0;	
	node *current=first,*temp;
	if(current->data==d)	// Element in the first node
	{
		first=first->next;
		first->prev=NULL;
		free(current);
		cout<<"List after deleting element"<<d<<"\n";
		display();
	 	return; 
	}
	while(current->next->next!=NULL)  //Element in between
	{
		if(current->next->data==d)
		{
			temp=current->next;
			current->next=temp->next;
			temp->next->prev=current;
			free(temp);
			cout<<"List after deleting element"<<d<<"\n";
			display();
			return;
		}
		current=current->next;
	}
	if(current->next->data==d)
	{
		temp=current->next;
		free(temp);
		current->next=NULL;
		cout<<"List after deleting element"<<d<<"\n";
		display();
		return;
	}
	else 
	{
		cout<<"Element Not found\n";
		return;	
	}
}
int LinkedList::search(int d)
{
	int pos=0;
	node *current=first;
	while(current->data!=d && current->next!=NULL)
	{
		pos++;
		current=current->next;
	}
	if(!(current->next!=NULL && current->data!=d )) //Element at the last position
		return ++pos;
	else if(current->next!=NULL)//Element found in bw 
		return ++pos;
	else return 0;	//Element not in the list
	
}
	
void LinkedList::display()
{
	node *current=first;
	while(current!=NULL)
	{
		cout<<current->data<<"->";
		current=current->next;
	}	
	cout<<"NULL\n";
}
int main()
{
	LinkedList l;
	int ch,value,pos=0;
	do
	{
	cout<<"\nEnter choice\n1:Insert_beg\n2:Delete_beg\n3:Display\n4:Search\n5:Delete_element\n0:Exit";
	cin>>ch;
	switch(ch)
	{
	case 1: cout<<"Enter data to insert";
		cin>>value;
		l.insert_beg(value);
		break;
	case 2:if(!l.empty())
		{
		 value=l.delete_beg();
		cout<<"Deleted" <<value;
		}
		break;
	case 3: l.display();
		break;
	case 4: cout<<"Enter element to search:";
		cin>>value;
		if(!l.empty())
			pos=l.search(value);
		if(pos>0)
			cout<<"Data "<<value<<" found in position "<<pos;
		else
			cout<<"Not found \n";
		break;
	case 5:	 cout<<"Enter element to delete: ";
		cin>>value;
		if(!l.empty())
			l.delete_element(value);
		else
			cout<<"List is empty\n\n";
		break;
	}
	
	}
	while(ch!=0);

	return 0;	
}
