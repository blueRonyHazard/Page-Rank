// Weighted Iterations
#include<bits/stdc++.h>
#define pb(x) push_back(x)
#define nu 1100
#define mp(x,y) make_pair((x),(y))
#define sz size()
#define ff first
#define ss second
#define delta 0.00000001
#define Abs(a,b) ((a) < (b) ? (b)-(a) : (a)-(b))
using namespace std;

typedef pair<int,int> ii;
vector<ii> ad[nu];
int n,m;
double ans[nu],temp[nu],d=0.85,out[nu],sum;
bool rankk()
{
    int i;
    for(i=1;i<=n;i++)
    {
        temp[i]=((1-d)/(double)n);
    }
    for(i=1;i<=n;i++)
    {        
        for(ii x : ad[i])
        {
            temp[x.ff]+=((d*(ans[i])*x.ss)/out[i]);
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
	freopen ("inputw.txt","r",stdin); freopen ("outputw.txt","w",stdout);
    int i,j,x,y,r,ts,cnt;
    cin>>ts;
    while(ts--)
    {
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
    cnt=1;
    while(rankk()==0)
    {
    	cnt++;
    }
    output();
    cout<<"Total Iterations - "<<cnt<<"\n";
    for(i=1;i<=n;i++)
    {
    	ad[i].clear();
    	out[i]=0;
	}
	}	
	return 0;
}
