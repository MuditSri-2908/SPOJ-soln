#include <iostream>
#include <vector>
#include <cstdio>
#include <climits>
#include <string>
#include <sstream>

#define ninf INT_MIN;
using namespace std;
int size(long int z 	)
{
	int i=0;
	while(z>9)
	{
		z=(z-(z%10))/10;
		i++;
	}
	return i+1;

}
int ls(long int n, vector<int> &v ,int i)
{
	int a,c;
	a=n%100;
	c=n%10; 
	if(v[i]!=0) return v[i];
	if(a==0) {v[i]=ninf;}

	
	if(i==1)
	{   		if(a<10) 
			{return ninf;}
		else
		{	
			if(a>26)
			 { if(c==0){ return ninf;}
				 else v[1]=1;}
		else
		{if(c==0) 
			{v[1]=1;}
		 else v[1]=2;
		 }
		}
	}
	else
	{
		if(a>26) { if(c==0) 
				{return ninf;}
			 else 
				v[i]=ls((n-c)/10,v,i-1);}
		else 
		{	if(a==0) {return ninf;}
			else
			{
			if(c==0)
				{ v[i]=ls((n-a)/100,v,i-2);} 
			else
			{    if(a<10)  {v[i]=ls((n-c)/10,v,i-1);}
			else v[i]=ls((n-a)/100,v,i-2) + ls((n-c)/10,v,i-1);} 
	      		 }
		}
	}

return v[i]; 
}
int main()
{
long long int n=1;
int b=0;
string s;
vector<int> ans;
vector<long long int> ip;
while(n!=0)
{
	cin>>s;
	int x=1;
	if(s[0]=='0' && (s.size()>1))
	{ip.push_back(0);
	 }
	else
	 {  if(s[0]=='0')
		{n=0; } 
		else
	{	stringstream ss(s);
		ss>>n;
		 	
	 	if(n) {ip.push_back(n);}
	} }
}
int i=0;
int j=ip.size();
while(i<j)
{       
	
if(ip[i])
{
        n=ip[i];
	
	b=size(n);
	vector<int> v(b,0);

int i;
        v[0]=1;
	for(i=b-1;i>0;i--)
	{
		v[i]=ls(n,v,i);
	}
	if(v[b-1]>0)
	ans.push_back(v[b-1]);	
	else
	ans.push_back(0);	 


}
	else
	ans.push_back(0);
i++;
}
for(j=0;j<ans.size();j++) cout<<ans[j]<<"\n";
return 0;
}