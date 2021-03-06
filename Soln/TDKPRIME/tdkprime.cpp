#include <stdio.h> 
#include <vector>     
using namespace std;                             
#define MAX 9472
#define LMT 98
#define RNG 86028160

unsigned base[MAX/64];
vector<int> primes;
vector<int> ans;
unsigned segment[RNG/64] = {0}; 


#define sq(x) ((x)*(x))
#define chkC(x,n) (x[n>>6]&(1<<((n>>1)&31)))
#define setC(x,n) (x[n>>6]|=(1<<((n>>1)&31)))

void print( int a)
{
	printf("%d\n",ans[a]);
}
void sieve()
{
	int i, j, k;
	for(i=3; i<LMT; i+=2)
		if(!chkC(base, i))
			for(j=i*i, k=i<<1; j<MAX; j+=k)
				setC(base, j);
	for(i=3; i<MAX; i+=2)
		if(!chkC(base, i))
		{	primes.push_back(i);
			ans.push_back(i);}
}

void segmented_sieve(int a, int b)
{
	unsigned i, j, k;
	for(i=0;sq(primes[i])<=b;i++)
	{
		j = primes[i]*((a+primes[i]-1)/primes[i]);
		if(j%2==0) j += primes[i];
		for(k=primes[i]<<1;j<=b;j+=k)
			if(j!=primes[i])
				setC(segment,(j-a));
	}
	for(i=0;i<=b-a;i+=2)
		if(!chkC(segment,i))
			ans.push_back(i+a);

}

int main()
{
	unsigned a, t, x;
	sieve();
	segmented_sieve(3,86028160);
printf("%d %d",ans[10000-2],ans.size());
	scanf("%d",&t);
	for(x=1;x<=t;x++)
	{
		scanf("%d",&a);
		if(a==1)
		{printf("2\n");  }
		else		
		print(a);
	}
	return 0;
}
