#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
using ii= pair<ll,ll>;
#define F first
#define S second
#define MP make_pair
#define PB push_back
//using min_of_3=min({ll a,ll b,ll c});

ll cc;
ll parent[100001];
ll size[100001];

void make_set(ll v)
{
    parent[v]=v;
    size[v]=1;
}

ll find_set(ll v)
{
    if(v==parent[v])
    {
        return v;
    }
    
    else
    {
        return parent[v]=find_set(parent[v]);
    }
}

void union_set(ll u,ll v)
{
    u= find_set(u);
    v= find_set(v);
    
    if (u==v) return;
    
    
    if(u!=v)
    {
        if(size[u]<size[v]) swap(u,v);
        parent[v]=u;
        size[u]+=size[v];
        --cc;
    }
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	
	ll n,m;
	cin>>n>>m;
	
	
	vector<ll> v[100001];
	
	set<ll> needed;
	set<ll> non;
	set<ll> cut;
	
    for(ll i=1;i<=n;i++)
	{
	    make_set(i);
	}
	
	for(ll i=1;i<=m;i++)
	{
	    ll a,b;
	    cin>>a>>b;   // b,a->node_number
	    
	    v[i].PB(a);
	    v[i].PB(b);
	}
	
	
	
	
	//cout<<cc<<"\n";
	ll q;
	cin>>q;
	
	while(q--)
	{
	    ll e;
	    cin>>e;
	    cut.insert(e);
	}
	
	ll edge[m+1];
	ll w=0;
	
	 cc=n;
	
	for(ll i=1;i<=m;i++)
	{
	    if(cut.find(i)==cut.end())
	    {
	        union_set(v[i][0],v[i][1]);
	        edge[w++]=i;
	    }
	}
	
	
	
/*	if(w==0)
	{
	    cc=n;
	}
	
	else
	{
	    cc+=0;
	    
	    for(ll j=1;j<w;j++)
	    {
	        if(find_set(edge[j])!=find_set(edge[0]))
	        {
	            cc++;
	        }
	    }
	}
	
	*/
	
	vector<ll> ans;
	set<ll>::reverse_iterator rit;
	
	cout<<cc<<"\n";
	
	for(rit=cut.rbegin();rit!=cut.rend();rit++)
	{
	    ans.PB(cc);
	    union_set(v[*rit][0],v[*rit][1]);
	}
	
	reverse(ans.begin(),ans.end());
	
	for(auto i: ans)
	{
	    cout<<i<<" ";
	}
	
}
