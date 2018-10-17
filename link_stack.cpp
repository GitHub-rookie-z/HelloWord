#include<iostream>
using namespace std;

class Link
{
	public:
		char data;
		Link *next;
};

class LinkStack
{
	public:
		LinkStack()
		{
			top=new Link;
			top->next=NULL;
		}
		~LinkStack()
		{
			
		}
		void Push();
		void Pop();
		void GetTop();
		void Empty();
		void Delete();
	private:
		Link *top;
};

void LinkStack::Push()
{
	char a;
	cin>>a;
	
	Link *temp=new Link;
	temp->data=a;
	
	temp->next=top->next;
	top->next=temp;
}

void LinkStack::Pop()
{
	if(top->next==NULL)
	{
		cout<<"None"<<endl;
	}
	else
	{
		cout<<top->next->data<<endl;
		Link *temp=top->next;
		top->next=top->next->next;
		delete temp;
	}
}	

void LinkStack::GetTop()		
{
	if(top->next==NULL)
	{
		cout<<"None"<<endl;
	}
	else
	{
		cout<<top->next->data<<endl;
	}
}
void LinkStack::Empty()
{
	if(top->next==NULL)
	{
		cout<<"Yes"<<endl;
	}
	else
	{
		cout<<"No"<<endl;
	}
}

void LinkStack::Delete()
{
	Link *temp;
	while(top->next)
	{
		temp=top->next;
		top->next=top->next->next;
		delete temp;
	}
}
int main()
{	
	LinkStack stack;
	
	char choice='0';
	
	while(choice!='E')
	{
		cin>>choice;
		switch(choice)
		{
			case'P':
				stack.Push();
				break;
			case'D':
				stack.Pop();
				break;
			case'G':
				stack.GetTop();
				break;
			case'T':
				stack.Delete();
				break;
			case'Y':
				stack.Empty();
				break;
		}
	}
	return 0;
}
