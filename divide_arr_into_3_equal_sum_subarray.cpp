#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

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

auto start_time= high_resolution_clock::now();
void time()
{
    #ifndef ONLINE_JUDGE
        auto stop_time= high_resolution_clock::now();
        auto duration= duration_cast<milliseconds>(stop_time-start_time);
        cout<<"run time: "<<duration.count()<<" ms"<<"\n";
    #endif
    return;
}

void ojudge()
{
    #ifndef ONLINE_JUDGE
        freopen("input1.txt","r", stdin);
        freopen("output1.txt","w",stdout);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    return;
}



int main()
{
    ojudge();
    

    ll n;
    cin>>n;

    ll arr[n];
   // fr(i,0,n) cin>>arr[i];
    ll psum[n+1];
    psum[0]= 0;
    fr(i,0,n){
        cin>>arr[i];
        psum[i+1]= psum[i]+ arr[i];
    }

    ll s= psum[n];

    if(s%3!=0) {
        cout<<0<<"\n";
        return 0;
    }

    ll isbt[n+1]={0};   // if sum[j----n]==s/3 put 1;

    fr(i,3,n+1){

        if(3*(psum[n]-psum[i-1])==s) isbt[i]= 1;
    }

    ll psumd[n+2]={0};   // sum of all instances where sum[j---n]== s/3
    psumd[n+1]=0;
    for(ll j=n;j>2;j--){

        psumd[j]= psumd[j+1]+isbt[j];
    }

    
    ll cc=0;
    fr(i,1,n-1){

        if(3*psum[i]==s)
        {
            cc+= psumd[i+2];
        }
    }

    

    cout<<cc<<"\n";

    time();
    return 0;
}
