// LONGEST SUBARRAY WITH EQUAL NUMBER OF 0'S AND 1'S 
// LONGEST SUBARRAY WITH SUM 0


#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
using ii= pair<ll,ll>;
#define fr(i,a,b) for(ll i=a;i<b;i++)
#define all(o) (o).begin(),(o).end()
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define ld long double
#define eps 0.00000000001
#define mod 1000000007

class prioritize{
    public: bool operator() (ii &p1,ii &p2){
        return p1.F<p2.F;
    }
};

int main()
{
    
    #ifndef ONLINE_JUDGE
        freopen("input1.txt","r", stdin);
        freopen("output1.txt","w", stdout);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    
    ll n;
    cin>>n;
    string s;
    cin>>s;
    vector<ll> v(n);
    fr(i,0,n)
    {
    	if(s[i]=='0') v[i]=-1;
    	else v[i]= 1;
    } 
    
    unordered_map<ll,ll> m;
    ll psum[n+1];
    psum[0]= v[0];
    m[v[0]]=0;
    ll max_len=0;
    fr(i,1,n)
    {
    	psum[i]=psum[i-1]+v[i];
    	if(psum[i]==0){                          // update max_len if psum[i]==0 with max(max_len,i);
    		max_len=max(max_len,i+1);
    		//continue;
    	} 
    	if(m.find(psum[i])!=m.end()){            // update again if the psum[now] is already encountered and update max_len as max(max_len,i-j);
    		//cout<<m[psum[i]]<<"#";
            max_len=max(max_len,i-m[psum[i]]);
    	}
    	else m[psum[i]]= i;
    }
    
    cout<<max_len<<"\n";
}