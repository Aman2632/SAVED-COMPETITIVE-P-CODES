#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll m=1e9+7;

ll power(ll x,ll y, ll p)   // finding x to the power y modulo p where x and y are very large....
{  
    ll res = 1;     
  
    x = x % p; 
   
    if (x == 0) return 0;  
  
    while (y > 0)  
    {  
       
        if (y & 1)  
            res = (res*x) % p;  
            
        y = y>>1; 
        x = (x*x) % p;  
    }  
    return res;  
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
	    
	    ll a=power(26,n,m);
	    ll b=power(21,n,m);
	    ll c=power(5,n,m);
	    
	    ll ans= (a-b-c+3*m)%m;
	    cout<<ans<<"\n";
	    
	}
	
}
