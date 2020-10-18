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

ll n;
ll x[60001];
ll v[60001];

bool checker(float t)
{
    vector<pair<float,float>> interval;

    fr(i,0,n)
    {
        interval.PB(MP(x[i]-v[i]*t,x[i]+v[i]*t));
    }

    float lo= interval[0].F;     // FINDING INTERSECTION OF SEVERAL INTERVALS....
    float hi= interval[0].S;
    for(ll i=1;i<n;i++)
    {
        float ri= interval[i].S;
        float le= interval[i].F;

        if(ri<lo||hi<le) return false;
        else{
            lo= max(lo,le);
            hi= min(hi,ri);
        }
    }

    return true;
}




int main()
{
    
    #ifndef ONLINE_JUDGE
        freopen("input1.txt","r", stdin);
        freopen("output1.txt","w",stdout);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    
    
    cin>>n;
    
    fr(i,0,n) cin>>x[i];
    fr(i,0,n) cin>>v[i];
   
    ll cc=0;
    fr(i,1,n)
    {
        if(x[i]==x[i-1]) cc++;
    }

    if(cc==n-1){
        cout<<fixed<<setprecision(6)<<0.000000<<"\n";
        return 0;
    }

    ll itr=300;
    float left= 0;
    float right= 1.0*1e9;
    float mid;
    float ans=1e9;
    while(itr--)
    {
        mid= left+ (right-left)/2.0;
        if(checker(mid))
        {
            ans=min(ans,mid);
            right= mid-1;
        }
        else{
            left= mid+1;
        }
    }

    cout<<fixed<<setprecision(6)<<ans<<"\n";

}