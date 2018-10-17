#include<iostream>
using namespace std;
const int MAXSIZE=20;

class List
{
	public:
		List(); 				//初始化空表 
		void FindKth(int k); 	//找k位元素 
		int Find(int x); 		//找x返回第几位
		void Insert(int x,int i);//在第i位插入x
		int Delete(int i);		//删除i位元素
		int Longth();			//返回线性表长度 
		void print();
			
	protected:
		int Data[MAXSIZE];
		int Last;
};
List::List() 					//初始化空表 
{
	Last=0;
}
void List::FindKth(int k)				//找k位元素 
{
	if(k>Last||k<1)
	{
		cout<<"位置不正确"<<endl;
		return ;
	}
	else 
	{
		cout<<Data[k-1];
	}
}
int List::Find(int x)					//找x返回下标 
{
	int i=0;
	while(i<Last&&Data[i]!=x)
	{
		i++;
	}
	if(i==Last)
	{
		i=-1;
	}
	return i;
}

void List::Insert(int x,int i)		//第i位放入x 
{
	int j=0;
	if(Last>=MAXSIZE)
	{
		cout<<"上溢"<<endl;
		return ;
	}
	if(i<1||i>Last+1)
	{
		cout<<"位置不正确"<<endl;
		return ;
	}
	
	for(j=Last;j>i-1;j--)
	{
		Data[j]=Data[j-1];
	}
		
	Data[i-1]=x;
		
	Last++;

	return ;
}
int List:: Longth()
{
	return Last;
}
int List::Delete(int i)		//删除第i位元素 
{
	int j=0;
	if(Last<=0)
	{
		cout<<"下溢";
		return -1;
	}
	if(i<1||i>Last)
	{
		cout<<"位置不正确"<<endl;
		return -1;
	}

	
		int k;
		k=Data[i-1];
		for(j=i;j<Last;j++)
		{
			Data[j-1]=Data[j];
		}
		
		Last--;
	
	return k;
}
void List::print()
{
	int i;

	for(i=0;i<Last;i++)
	{
		cout<<Data[i]<<endl;
	}
}
int main()
{	
	List list;
	char choice='0';
	while(choice!='E')
	{
		cin>>choice;

		switch(choice)
		{
		case'I':
			int n;
			int i;
			int x;
			
			int j;
			j = 0;

			cin>>n;
			for(j=0;j<n;j++)
			{
				cin>>i;
				cin>>x;
				list.Insert(x,i);
			}
			break;
		case'S':
			int s;
			cin>>s;

			int ss;
			ss=list.Find(s);
			if(ss==-1)
			{
				cout<<"None"<<endl;
			}
			else
			{
				cout<<ss+1<<endl;
			}
			break;
		case'G':
			int k;
			cin>>k;
			list.FindKth(k);
			break;
		case'D':
			int g;
			cin>>g;
			int	D;
			D=list.Delete(g);
			if(D!=-1)
			{
				cout<<D<<endl;
			}
			break;
		case'V':
			list.print();
			break;	
		}
	}

	return 0;
}