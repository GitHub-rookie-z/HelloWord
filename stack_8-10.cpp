#include<iostream>
using namespace std;
#include<stack> 
int main()
{
	stack<int>sta;
	int a=0;
	int i=0;
	for(i=0;i<3;i++)
	{
		cin>>a;
		while(a!=0)
		{
			sta.push(a%8);
			a=a/8;
		}
		while(!sta.empty())
		{
			cout<<sta.top();
			sta.pop();
		}
		cout<<"\n";
	}
	return 0;
}