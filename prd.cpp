// Dynamic probability algorithm
#include<bits/stdc++.h>
#define pb(x) push_back(x)
#define nu 1100
using namespace std;

vector<int> ad[nu];
int n,m;
double ans[nu],temp[nu],d=0.85,o,sum;
void rankk()
{
    int i;
    for(i=1;i<=n;i++)
    {
        temp[i]=((1-d)/(double)n);
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
    for(i=1;i<=n;i++)
    {
        ans[i]=temp[i];
    }
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
	freopen ("input0.txt","r",stdin); freopen ("outputd0.txt","w",stdout);
    int i,j,x,y;
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
    for(i=0;i<2500;i++)
    {        
        rankk();
    }
    output();
	return 0;
}
