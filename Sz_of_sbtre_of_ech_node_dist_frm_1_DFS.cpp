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


vector<ll> v[200010];

ll size_n[200010]={0};
ll dpth_n[200010]={0};
ll cont_n[200010]={0};


ll dfs(ll n,ll bap)
{
    
    size_n[n]=1;                   //Counting size of subtree of each node, including itself, using DFS
    dpth_n[n] =dpth_n[bap]+1;      //Counting depth of each node( rather number of  nodes in shortest path from root to itself)
 
    for(auto it:v[n])
    {
        if(it!=bap)
        {
            size_n[n]+= dfs(it,n);;
        }
    }

    cont_n[n]= size_n[n]-dpth_n[n];
    return size_n[n];
}

int main()
{
    ojudge();
    
    ll n,k;
    cin>>n>>k;

    fr(i,1,n){
        ll u,w;
        cin>>u>>w;
        v[u].PB(w);
        v[w].PB(u);
    }

    dpth_n[0]= 0;

    dfs(1,0);

    vector<ll> ans;

    fr(i,1,n+1){

        ans.PB(cont_n[i]);
    }

    sort(all(ans));
    reverse(all(ans));

    ll cc=0;

    for(ll i=0;i<n-k;i++)
    {
        //cout<<ans[i]<<" ";
        cc+= ans[i];
    }

    cout<<cc<<"\n";

    time();
    return 0;
}
