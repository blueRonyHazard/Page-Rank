// Weighted Page Rank
#include<bits/stdc++.h>
#define pb(x) push_back(x)
#define nu 1100
#define mp(x,y) make_pair((x),(y))
#define sz size()
#define ff first
#define ss second
using namespace std;

typedef pair<int,int> ii;
vector<ii> ad[nu];
int n,m;
double ans[nu],temp[nu],d=0.85,out[nu],sum;
void rankk()
{
    int i;
    for(i=1;i<=n;i++)
    {
        temp[i]=((1-d)/n);
    }
    for(i=1;i<=n;i++)
    {        
        for(ii x : ad[i])
        {
            temp[x.ff]+=((d*(ans[i])*x.ss)/out[i]);
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
	freopen ("input0.txt","r",stdin); freopen ("outputw.txt","w",stdout);
    int i,j,x,y,r;
    cin>>n>>m; 
    for(i=0;i<m;i++)
    {
        cin>>x>>y>>r;
        ad[x].pb(mp(y,r));
        out[x]+=r;
    }
    for(i=1;i<=n;i++)
    {
        ans[i]=(1/(double)n);
    }
    for(i=0;i<150;i++)
    { 
        rankk();
    }
    output();
	return 0;
}
