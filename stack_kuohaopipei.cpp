#include<iostream>
#include<string.h>
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
		char GetTop();
		int Empty();
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
		return 0;
	}
	else
	{	
		int temp = top;
		top--;
		return data[temp];
		
	}
}

char SeqStack::GetTop()
{
	if(top==-1)
	{
		return 0;
	}
	else
	{
		return data[top];
	}
}

int SeqStack::Empty()
{
	if(top==-1)
	{
		return 1;//¿Õ
	}
	else
	{
		return 0;//²»¿Õ
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
	
	int t=0;
	int i = 0;
	for(;i<len;i++)
	{
		if(temp[i]=='['||temp[i]=='{'||temp[i]=='(')
		{
			stack.Push(temp[i]);
		}
		else if(temp[i]==']')
		{
			if(stack.Empty()==1)
			{
				t=1;
				break;
			}
			if(stack.GetTop()=='[')
			{
				stack.Pop();
			}
		}
		else if(temp[i]=='}')
		{
			if(stack.Empty()==1)
			{
				t=1;
				break;
			}
			if(stack.GetTop()=='{')
			{
				stack.Pop();
			}
		}
		else if(temp[i]==')')
		{
			if(stack.Empty()==1)
			{
				t=1;
				break;
			}
			if(stack.GetTop()=='(')
			{
				stack.Pop();
			}
		}
	}
	
	if(t==1)
	{
		cout<<"no"<<endl;
	}
	else
	{
	int choice = stack.Empty();

	if(choice==1)
	{
		cout<<"yes"<<endl;
	}
	else if(choice==0)
	{
		cout<<"no"<<endl;
	}
	}
	

	return 0;
}