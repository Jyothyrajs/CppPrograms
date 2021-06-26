#include<iostream>
using namespace std;
struct node 
{
	int data;
	node *next;
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
	void reverse();
	void display();
	int search(int);
};

//Insert at the beginning of the list
void LinkedList::insert_beg(int d)
{
	node *temp=new node;
	temp->data=d;
	temp->next=first;
	first=temp;	
	cout<<d<<" inserted in the beginning\n";
}
//Delete from beginning of the list
int LinkedList::delete_beg()
{
	int d=first->data;
	first=first->next;
	return d;
}

//Delete the specified element from the list
void LinkedList::delete_element(int d)
{
	int pos=0;	
	node *current=first,*prev;
	if(current->data==d)	// Element in the first node
	{
		first=current->next;
	
		cout<<"List after deleting element"<<d<<"\n";
		display();
		return;
	}
	while(current->data!=d && current->next!=NULL)
	{
		prev=current;
		current=current->next;
	}
	if(current->next!=NULL)    //Element in the middle 
	{	
		prev->next=current->next;
	}
	else if(current->data==d)    //Element  at the end 
		prev->next=NULL;
	else 
	{
		cout<<"Element Not found\n";
		return;	
	}
	cout<<"List after deleting element"<<d<<"\n";
	display();
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
void LinkedList:: reverse()
{
       node *current, *previous,*head = first;
       current = head->next;
       previous = head;
       head = current->next;
       previous->next = NULL;
        while(head)
        {
             current->next = previous;
             previous = current;
             current = head;
             head = head->next;
        }

             current->next = previous;
        first = current;

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
	cout<<"\nEnter choice\n1:Insert_beg\n2:Delete_beg\n3:Display\n4:Search\n5:Delete_element\n6:Reverse\n0:Exit";
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
	case 6: 
	    cout<<"Reverse of list:";
	    l.reverse();
          l.display();
	}
	
	}
	while(ch!=0);

	return 0;	
}
