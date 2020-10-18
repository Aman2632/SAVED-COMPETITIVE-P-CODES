#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
using ii= pair<ll,ll>;
#define F first
#define S second
#define MP make_pair
#define PB push_back
//using min_of_3=min({ll a,ll b,ll c});

vector<ll> v[26];
ll indegree[26]={0};
vector<ll> topo;
map<ll,ll> ma;   // map to count number of distinct elements in the graph......
map<char,ll> sig;

void Cahn()
{
    queue<ll> q;
    for(ll i=0;i<26;i++)
    {
        if(indegree[i]==0&&(ma[i]>0))
        {
            q.push(i);
        }
    }
    
    while(!q.empty())
    {
        ll node = q.front();
        q.pop();
        
        for(auto neigh:v[node])
        {
            indegree[neigh]--;
            if(indegree[neigh]==0)
            {
                q.push(neigh);
            }
        }
        
        topo.PB(node);
    }
    
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	
	ll t;
	cin>>t;
	for(ll k=1;k<=t;k++)
	{
	    ll r,c;
	    cin>>r>>c;
	    
	    for(ll i=0;i<26;i++)
	    {
	        v[i].clear();
	        indegree[i]=0;
	    }
	    
	    topo.clear();
	    ma.clear();
	    sig.clear();
	    
	    string g[r];
	    for(ll i=0;i<r;i++)
	    {
	        cin>>g[i];
	    }
	    
	    if(r==1)
	    {
	        for(ll i=0;i<c;i++)
	        {
	            sig[g[0][i]]++;
	        }
	        cout<<"Case #"<<k<<":"<<" ";
	        for(auto it:sig)
	           cout<<it.F;
	        cout<<"\n";
	        continue;
	    }
	    
	    
	    for(ll j=0;j<c;j++)
	    {
	        for(ll i=r-1;i>0;i--)
	        {
	            ll x = g[i][j]-'A';
	            ll y = g[i-1][j]-'A';
	            
	            ma[x]++;
	            ma[y]++;
	            
	            if(x!=y)
	            {
	                v[x].PB(y);
	                indegree[y]++;
	            }
	        }
	    }
	    
	    
	    ll len = ma.size();
	    Cahn();
	    
	    if(topo.size()!=len)
	    {
	        //cout<<len<<" "<<topo.size()<<"\n";
	        cout<<"Case #"<<k<<":"<<" "<<-1<<"\n";
	    }
	    else
	    {
	        //cout<<len<<" "<<topo.size()<<"\n";
	        cout<<"Case #"<<k<<":"<<" ";
	        for(auto it:topo)
	        {
	            cout<<char(it+65);
	        }
	        cout<<"\n";
	    }
	    
	}
	
}