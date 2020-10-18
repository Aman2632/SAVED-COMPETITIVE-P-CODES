


#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
using ii= pair<ll,ll>;
#define F first
#define S second
#define MP make_pair
#define PB push_back


ll maze[1000][1000];
ll gr[1000][1000];
vector<ii> v[1000001];
ll dist[1000001];

class prioritize {
    public: bool operator() (ii p1,ii p2){
        return p1.S>p2.S;
    }
};

void dijkstra(ll s,ll n,ll m)
{
    for(ll i=1;i<=n*m;i++)
    {
            dist[i]=1e18;
    }
    
    dist[s]=maze[1][1];
    
    priority_queue<ii,vector<ii>,prioritize> pq;    // second-> weight
    pq.push({s,dist[s]});
    
    while(!pq.empty())
    {
        ii h= pq.top();
        pq.pop();
        
        ll node= h.F;
        
        for(ll i=0;i<v[node].size();i++)
        {
            ll neigh= v[node][i].F;
            ll wt= v[node][i].S;
            
            if(dist[neigh]>dist[node]+wt)
            {
                dist[neigh]= dist[node]+wt;
                pq.push(MP(neigh,dist[neigh]));
            }
        }
    }
    
    
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	ll t;
	cin>>t;
	while(t--)
	{
	    ll n;
	    cin>>n;
	    ll m;
	    cin>>m;
	    
	    for(ll i=1;i<=n;i++)
	    {
	        for(ll j=1;j<=m;j++)
	        {
	            gr[i][j]=0;
	            maze[i][j]=0;
	        }
	    }
	    
	    for(ll i=1;i<=n;i++)
	    {
	        for(ll j=1;j<=m;j++)
	        {
	            ll x;
	            cin>>x;
	            maze[i][j]=x;
	        }
	    }
	    
	    ll id=1;
	    for(ll i=1;i<=n;i++)
	    {
	        for(ll j=1;j<=m;j++)
	        {
	            gr[i][j]=id;
	            id++;
	        }
	    }
	    
	    for(ll i=1;i<=1000001;i++)
	    {
	        dist[i]=0;
	        v[i].clear();
	    }
	    
	    for(ll i=1;i<=n;i++)
	    {
	        for(ll j=1;j<=m;j++)
	        {
	           if(j+1<=m){
	                v[gr[i][j]].PB({gr[i][j+1],maze[i][j+1]}); 
	                v[gr[i][j+1]].PB({gr[i][j],maze[i][j]});
	              }
	            
	           
	           
	            ll c=0;
	            
	            if(i+1<=n){
	                 v[gr[i][j]].PB({gr[i+1][j],maze[i+1][j]});
	                 v[gr[i+1][j]].PB({gr[i][j],maze[i][j]});
	            }
	           
	        }
	    }
	    
	    dijkstra(1,n,m);
	    
/*	    for(ll i=1;i<=n;i++)
	    {
	        for(ll j=1;j<=m;j++)
	        {
	            cout<<gr[i][j]<<" "<<dist[gr[i][j]]<<"\n";
	        }
	    }         */
	    
	    cout<<dist[n*m]<<"\n";
	    
	}
}
