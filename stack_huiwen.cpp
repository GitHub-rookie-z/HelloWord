#include<iostream>
#include<stdio.h>
#include <string.h>
using namespace std;

#define SIZE 100 

class SeqStack
{
	public:
		SeqStack()
		{
			top=-1;
		}
		~SeqStack()
		{}
		void Push(char a);
		char Pop();
		void GetTop();
		void Empty();
		void Delete();
	private:
		char data[SIZE];
		int top;
};

void  SeqStack::Push(char a)
{
	if(top==SIZE-1)
	{
		return;
	}
	top++;
	data[top] = a;
}

char SeqStack::Pop()
{
	if(top==-1)
	{
		cout<<"None"<<endl;
		return 0;
	}
	else
	{	
		int temp = top;
		top--;
		return data[temp];
		
	}
}

void SeqStack::GetTop()
{
	if(top==-1)
	{
		cout<<"None"<<endl;
		return ;
	}
	else
	{
		cout<<data[top]<<endl;
	}
}

void SeqStack::Empty()
{
	if(top==-1)
	{
		cout<<"Yes"<<endl;//¿Õ
	}
	else
	{
		cout<<"No"<<endl;;//²»¿Õ
	}
}

void SeqStack::Delete()
{
	top=-1;
}

int main()
{
	SeqStack stack;

	char temp[SIZE];
	cin>>temp;
	
	int len = strlen(temp);

	int i = 0;

	for(i=0;i<len;i++)
	{
		stack.Push(temp[i]);
	}

	char temp2[SIZE];

	for(i=0;i<len;i++)
	{
		temp2[i] = stack.Pop();
	}

	temp2[i]='\0';

	int choice = strcmp(temp,temp2);
	
	if(choice==0)
	{
		cout<<"yes"<<endl;
	}
	else
	{
		cout<<"no"<<endl;
	}

	return 0;
}