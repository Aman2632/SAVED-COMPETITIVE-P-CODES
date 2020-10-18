#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
using ii = pair<ll,ll>;
using iii = pair<ll,ii>;
#define F first
#define S second
#define MP make_pair
#define PB push_back

vector<pair<ll,ll> > v[10002];       // v[i].F->node connnected to i & v[i].S-> distance b/w them...
ll dist[1002][1002];         // dist[i][j]->cost to reach node i with fuel j still left...
ll price[1002];
ll vst[1002][102];          // whether the state (i,j) is visited or not...


class prioritize {
   public:  bool operator()(iii &p1,iii &p2){
        return p1.F>p2.F;
    }
};

ll dijkstra(ll s,ll e,ll c,ll n)
{
    for(ll i=0;i<n;i++)
    {
        
        for(ll j=0;j<=c;j++)
        {
            vst[i][j]=0;
            dist[i][j]=1e9;
        }
    }
    
    dist[s][0]=0;          // cost to reach source with 0 fuel left is 0....
    
    priority_queue<iii,vector<iii>,prioritize > pq;    // iii->(min_cost,(node i,fuel j));
    
    pq.push(MP(0,MP(s,0)));     // iii.F->cost,iii.S.F-> node,iii.S.S-> fuel level.....
    
    while(!pq.empty())
    {
        iii h= pq.top();
        pq.pop();
        
        ll node= h.S.F;
        ll fuel= h.S.S;
        
        if(vst[node][fuel]) continue;
        vst[node][fuel]=1;
        
        for(ll u=0;u<v[node].size();u++)            // transition TO NEW neighbours.....
        {
            ll neigh= v[node][u].F;
            ll len= v[node][u].S;
            
            if(fuel>=len)
            {
                if(dist[neigh][fuel-len]>dist[node][fuel])
                {
                    dist[neigh][fuel-len]=dist[node][fuel];
                    pq.push(MP(dist[neigh][fuel-len],MP(neigh,fuel-len)));
                }
            }
        }
        
        if(fuel+1<=c)                     // TRANSITION TO A NEW FUEL STATE OF SAME NODE......
        {
            if(dist[node][fuel+1]>dist[node][fuel]+price[node])
            {
                dist[node][fuel+1]=dist[node][fuel]+price[node];  
                pq.push(MP(dist[node][fuel+1],MP(node,fuel+1)));
            }
        }
        
        
        
    }
    
    return dist[e][0];
    
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	
	ll n,m;
	cin>>n>>m;
	for(ll i=0;i<n;i++){
	    cin>>price[i];
	}
	
	while(m--){
	    ll u,ne,d;
	    cin>>u>>ne>>d;     // d-> length of road b/w u and v....
	    v[u].push_back(make_pair(ne,d));
	    v[ne].push_back(make_pair(u,d));
	}
	
 
	  
	ll q;
	cin>>q;
	while(q--){
	    ll c,s,e;        // s-> start,e-> end, c-> fuel capacity of the tank....
	    cin>>c>>s>>e;
	    
	    
	    ll d=dijkstra(s,e,c,n);
	    //dist[e][0];
	    
	    if(d==1e9){
	        cout<<"impossible\n";
	    }
	    else{
	         cout<<d<<"\n";
	    }
	   
	}
	
	
	
}
