#include <iostream>
#include <vector>
using namespace std;
int size(int z )
{
	int i=0;
	while(z>9)
	{
		z=(z-(z%10))/10;
		i++;
	}
	return i+1;

}
int ls(int n, vector<int> &v ,int i)
{
	int a,c;
	a=n%100;
	c=n%10;
	if(v[i]!=0) return v[i];

	if(i==1)
	{
		if(a>26) v[1]=1;
		else
		 v[1]=2;
	}
	else
	{
		if(a>26) v[i]=ls((n-c)/10,v,i-1);
		else v[i]=ls((n-a)/100,v,i-2) + ls((n-c)/10,v,i-1);
	}
return v[i];
}
int main()
{
int n=1;
int b=0;
vector<int> ans;
vector<int> ip;
while(n!=0)
{
	cin>>n;
	if(n) ip.push_back(n);
}
int i=0;
while( ip[i]!=0)
{
        n=ip[i];i++;
	
	b=size(n);
	vector<int> v(b,0);
	v[0]=1;
int i;
	for(i=b-1;i>0;i--)
	{
		v[i]=ls(n,v,i);
	}
	cout<<v[i];
	ans.push_back(v[b-1]);		 


}
for(int j=0;j<ans.size();j++) cout<<ans[j]<<"\n";
return 0;
}