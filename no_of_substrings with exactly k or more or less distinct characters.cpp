// NUMBER OF SUBSTRINGS OF A STRING HAVING EXACTLY K, MORE THAN K OR ATLEAST K DISTINCT ELEMENTS..
// EXACTLY K-> no_subarray(ll k,ll arr[],ll n)-no_subarray(ll k-1,ll arr[],ll n)
// ATLEAST K-> n*(n+1)/2  - no_subarray(ll k-1,ll arr[],ll n)
// ATMOST K -> no_subarray(ll k,ll arr[],ll n)



#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;


ll no_subarray(ll k,ll arr[],ll n)
{
    ll count=0;

    ll left=0;
    ll right=0;
    
    map<ll,ll> m;
    
    while(right<n)
    {
        if(m.find(arr[right])==m.end())
        {
            m[arr[right]]=0;
        }
        
        m[arr[right]]++;
        
        
        while(m.size()>k)
        {
            m[arr[left]]=m[arr[left]]-1;
            
            if(m[arr[left]]==0)
            {
                m.erase(arr[left]);
            }
            left++;
        }
        
        count+=(right-left+1);
        right++;
    
    }
    
    return count;
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
	    string s;
	    cin>>s;
	    
	    ll arr[n+1];
	    for(ll i=0;i<n;i++)
	    {
	        arr[i]=s[i]-'a';
	    }
	    
	    for(ll k=1;k<=26;k++)
	    {
	        ll x= no_subarray(k-1,arr,n);  // x-> no of subarrays having at max (k-1) distinct characters
	        ll y= n*(n+1)/2;           // y-> total number of subarrays
	                               // y-x -> total number of  subarrays such that it has exactly k or more than
	        cout<<(y-x)<<" ";    // k distinct elements.... which is the required answer...
	    }
	    
	    cout<<"\n";
	    
	}
	
}
