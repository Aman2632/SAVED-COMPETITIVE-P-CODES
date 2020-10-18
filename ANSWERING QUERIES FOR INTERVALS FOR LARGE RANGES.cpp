
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main()
{
    ll n;
    cin>>n;
    vector<pair<ll,ll> > v;     
    
    for(int i=0;i<n;i++)
    {
        ll x,y;
        cin>>x>>y;
        v.push_back(make_pair(x,y));
       // cin>>v[i].first>>v[i].second;
    }
    
    sort(v.begin(),v.end());
    ll maxend=0,ans=0;
    for(ll i=0;i<n;i++)
    {
        ans+=(max(v[i].second,maxend)-max(v[i].first-1,maxend));
        maxend=max(maxend,v[i].second);
    }
    
    cout<<ans<<"\n";
    
    
    
}
