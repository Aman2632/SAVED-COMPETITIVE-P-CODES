// FINDING MAXIMUM AMONG MINIMUM OF WINDOWS OF ALL POSSIBLE SIZE IN AN ARRAY IN O(n) ..BRUTE FORCE->O(n3)...THIS-> O(n)...

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


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	
	ll n;
	cin>>n;
	
	ll arr[n];
	for(ll i=0;i<n;i++)
	{
	    cin>>arr[i];
	}
	
	ll left[n];         // array to store the idex of previous minimum element of arr[i] i.e. element smaller than arr[i] to the left of it..
	ll right[n];        // array to store the idex of next minimum element of arr[i] i.e. element smaller than arr[i] to the right of it..
	
	for(ll i=0;i<n;i++) // initializing
	{
	    left[i] = -1;   // if there is no element smaller than arr[i] to its left.....leave left[i] as -1;
	    right[i] = n;   // if there is no element smaller than arr[i] to its right.....leave right[i] as n;
	}
	
	ll ans[n+1]={0};    // ans[i] stores the maximum among the minimum element of all possible windows of size i....i->(1...n);
	
	stack<ll> s;        // stack to find left[i] and right[i] in O(n)...
	
// refer  https://www.geeksforgeeks.org/find-the-maximum-of-minimums-for-every-window-size-in-a-given-array/ to understand this part..

// FILLING THE left array...
	
	for(ll i=0;i<n;i++)    
	{
	    while(!s.empty()&&arr[s.top()]>=arr[i])   
	    {                                         
	        s.pop();
	    }
	    
	    if(!s.empty())
	    {
	        left[i]=s.top();
	    }
	    
	    s.push(i);
	}

//  clearing the stack to reuse it again....

	while(!s.empty())
	{
	    s.pop();
	}

//  FILLING THE right array...

	for(ll i=n-1;i>=0;i--)
	{
	    while(!s.empty()&&arr[s.top()]>=arr[i])
	    {
	        s.pop();
	    }
	    
	    if(!s.empty())
	    {
	        right[i]=s.top();
	    }
	    
	    s.push(i);
	}
	
//  Filling the ans array....

	for(ll i=0;i<n;i++)
	{
	    ll len = right[i]-left[i]-1;       // len-> size of the window whose minimum element is arr[i]...
	    ans[len] = max(arr[i],ans[len]);   // ans[len] will be max among arr[i] and ans[len] (from some previous window of same size len)..
	}
	
	for(ll i=n-1;i>=1;i--)    // There might be some i's in ans which are 0 as len do not necessarily covers all 1 ---> n....
	{
	    ans[i] = max(ans[i],ans[i+1]); // for those use the fact that  ans[len] will be >= ans for (len+1)  
	}                                  
	
	for(ll i=1;i<=n;i++)
	{
	    cout<<ans[i]<<" ";
	}
  
    cout<<"\n";
}





