#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cstdio>
using namespace std;
struct time1
{
	int st;
	int et;
} ;


bool myfunc(time1 t1,time1 t2)
{
	return (t1.et<t2.et);

}
int nt(vector<time1> v,int s)
{
	for(int i=s-2;i>-1;i--)
	{
		if(v[i].et<=v[s-1].st)
		return i;
	}	
	return -1;
}

int ss(vector<time1> v,int s,vector<int> &d)
{

	if(v[s-1].et==0)
	return 0;
	if(s==1)
	return 1;
	if(d[s-1]!=0)
	return d[s-1];
	int ans1=1,ans2=0;
	int t=nt(v,s);
	 if(t!=-1)
	{
		ans1=1+ss(v,t+1,d);
	}
	ans2=ss(v,s-1,d);
	d[s-1]=ans1+ans2;
	return ans1+ans2;
}
	


int main()
{
 	vector<time1> v;
	vector<int> ans;
	int x=1;time1 t;
	while(x>-1)
{
	scanf("%d",&x);
	if(x>0)
{	for(int i=0;i<x;i++)
{
	scanf("%d",&t.st);
	scanf("%d",&t.et);
	v.push_back(t);
}
}
	if(x==0) {t.st=0;t.et=0;v.push_back(t);}
	
}
stable_sort(v.begin(),v.end(),myfunc);    
vector<int> d(v.size(),0);
ans.push_back(ss(v,v.size(),d));
for(int j=0;j<ans.size();j++)
cout<<setfill('0')<<setw(8)<<ans[j]<<"\n";
	
	
return 0;
}