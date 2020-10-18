#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
using ii= pair<ll,ll>;
#define all(o) (o).begin(),(o).end()
#define F first
#define S second
#define MP make_pair
#define PB push_back
//using min_of_3=min({ll a,ll b,ll c});

class prioritize{
    public: bool operator() (ii &p1,ii &p2){
        return p1.F<p2.F;
    }
};

ll power(ll n,ll y)
{
    if(y==0) return 1;
    else if (y%2==0) return power(n,y/2)*power(n,y/2);
    else return n*power(n,y/2)*power(n,y/2);
}

long long maxPrimeFactors(long long n) 
{ 
    long long maxPrime = -1; 
    while (n % 2 == 0) { 
        maxPrime = 2; 
        n >>= 1; 
    } 
    for (int i = 3; i <= sqrt(n); i += 2) { 
        while (n % i == 0) { 
            maxPrime = i; 
            n = n / i; 
        } 
    } 
    if (n > 2) 
        maxPrime = n; 
        
    return maxPrime; 
} 


ll spf(ll n)
{
    if(n%2==0) return 2;
    else{
        for(ll i=3;i<=sqrt(n);i+=2)
        {
            if(n%i==0) return i;
        }
    }
    return n;
}

bool checker(ll n,ll s)
{
    ll sum=0;
    ll x = n;
    
    while(x)
    {
        sum+=(x%10);
        x = x/10;
    }
    if(n-sum>=s) return true;
    else return false;
}




int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	
    ll n,s;
    cin>>n>>s;
    
    
    if(!checker(n,s))
    {
        cout<<0<<"\n";
    }
    
    else{
    ll start = 0;
    ll mid = 0;
    ll end = n;
    ll ans=0;
    while(start<=end)
    {
        mid = start + ((end-start)/2);
        if(checker(mid,s))
        {
            if(!checker(mid-1,s))
            {
                ans = mid-1;
                break;
            }
            else{
                end = mid-1;
            }
        }
        else{
            if(checker(mid+1,s))
            {
                ans = mid;
                break;
            }
            else{
                start = mid+1;
            }
        }
    }
    
    cout<<(n-ans);
    
    }
}









