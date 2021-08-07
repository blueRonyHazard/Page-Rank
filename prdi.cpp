#include<bits/stdc++.h>
#define pb(x) push_back(x)
#define nu 1100
#define delta 0.00000001
#define Abs(a,b) ((a) < (b) ? (b)-(a) : (a)-(b))
using namespace std;

vector<int> ad[nu];
int n,m;
double ans[nu],temp[nu],d=0.85,o,sum;
bool rankk()
{
    int i;
    for(i=1;i<=n;i++)
    {
        temp[i]=(0.15/(double)n);
    }
    for(i=1;i<=n;i++)
    {
        o=0;
        for(int x : ad[i])
        {
            o+=ans[x];
        }
        for(int x : ad[i])
        {
            temp[x]+=((d*(ans[i])*ans[x])/o);
        }
    }
	bool fl=1; 
    for(i=1;i<=n;i++)
    {
        if((Abs(ans[i],temp[i]))>delta)
        {
        	fl=0;
        	break;
		}        	
    }
    for(i=1;i<=n;i++)
    {
        ans[i]=temp[i];
    }
    return fl;
}
void output()
{
    int i;
    sum=0;
    for(i=1;i<=n;i++)
    {
        cout<<i<<" - "<<ans[i]<<"\n";
        sum+=ans[i];
    }
    cout<<"Total Probability - "<<sum<<"\n";
}
int main()
{
	freopen ("input0.txt","r",stdin); freopen ("outputdi0.txt","w",stdout);
    int i,j,x,y,cnt=1;
    cin>>n>>m; 
    for(i=0;i<m;i++)
    {
        cin>>x>>y;
        ad[x].pb(y);
    }
    for(i=1;i<=n;i++)
    {
        ans[i]=(1/(double)n);
    }
    while(rankk()==0)
    {
    	cnt++;        
    }
    output();
    cout<<"Total Iterations - "<<cnt<<"\n";
	return 0;
}
