#include<iostream>
using namespace std;

#define SIZE 100

class CirQueue
{
	public:
		CirQueue()
		{
			front=rear=SIZE-1;
		}
		~CirQueue()
		{
		}
		void EnQueue();//入队 
		void DeQueue();//出队 
		void GetQueue();//出队（不删除）
		void Delete();
	private:
		char data[SIZE];
		int front,rear;
 }; 
 
void CirQueue::EnQueue()
{
	if((rear+1)%SIZE==front)
	{
		return;
	}
	else
	{
		rear=(rear+1)%SIZE;
		cin>>data[rear];
	}
}

void CirQueue::DeQueue()
{
	if(rear==front)
	{
		cout<<"None"<<endl;
	}
	else
	{
		front=(front+1)%SIZE;
		cout<<data[front]<<endl;
	}
}

void CirQueue::GetQueue()//出队（不删除）
{
	if(rear==front)
	{
		cout<<"None"<<endl;
	}
	else
	{
		cout<<data[(front+1)%SIZE]<<endl;
	}
}

void CirQueue::Delete()
{
	rear=front=SIZE-1;
}

int main()
{
	CirQueue queue;
	
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
			case'D':
				queue.DeQueue();
				break;
			case'G':
				queue.GetQueue();
				break;
		}
	}
	return 0;
}
