#include<iostream>
using namespace std;

class Link
{
	public:
		char data;
		Link *next;
};
class LinkQueue
{
	public:
		LinkQueue();
		~LinkQueue()
		{
		}
		void EnQueue();
		void DeQueue();
		void GetQueue();
		void Delete();
	private:
		Link *front;
		Link *rear;
};

LinkQueue::LinkQueue()
{
	Link *temp = new Link;
	temp->next = NULL;
	front=rear=temp;
}

void LinkQueue::EnQueue()
{
	Link *temp = new Link;
	cin>>temp->data;

	rear->next = temp;
	temp->next = NULL;
	rear = temp;
}

void LinkQueue::DeQueue()
{
	if(rear==front)
	{
		cout<<"None"<<endl;
	}
	else
	{
		front = front->next;
		cout<<front->data<<endl;
	}
}

void LinkQueue::GetQueue()
{
	cout<<front->next->data<<endl;
}

void LinkQueue::Delete()
{
	Link *temp;
	while(front!=rear)
	{
		temp = front;
		front = front->next;
		delete temp;
	}
}
int main()
{
	LinkQueue queue;

	char choice='0';
	while(choice!='Q')
	{
		cin>>choice;
		switch(choice)
		{
			case'E':
				queue.EnQueue();
				break;
			case'C':
				queue.Delete();
				break;
			case'G':
				queue.GetQueue();
				break;
			case'D':
				queue.DeQueue();
				break;
		}
	}
	return 0;
}