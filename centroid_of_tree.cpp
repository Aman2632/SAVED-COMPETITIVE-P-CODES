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

vector<ll> v[100010];
ll vst[100010]={0};
ll sz[100010]={0};
//vector<bool> ctr(100010);
set<ll> croid;


// croid-> set to store the centroids of the tree
// if n-> odd ->only one centroid possible. if n-> even-> two may be possible


ll dfs(ll node,ll n)
{
    vst[node]= 1;
    sz[node]= 1;
    bool is_ctr= true;
    for(auto it:v[node])
    {
        if(!vst[it])
        {
            
            sz[node]+= dfs(it,n);
            if(sz[it]>(n)/2) is_ctr= false;
        }
    }

    if(sz[node]<((n+1)/2)) is_ctr= false;  // (n+1) important in case of odd number of nodes....
    if(is_ctr) croid.insert(node);
    return sz[node];
}


int main()
{
    
    #ifndef ONLINE_JUDGE
        freopen("input1.txt","r", stdin);
        freopen("output1.txt","w",stdout);
        auto start= high_resolution_clock::now();
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;

        croid.clear();
        fr(i,0,n+8) v[i].clear();
        fr(i,0,n+8){
            vst[i]= 0;
            sz[i] = 0;
          //  ctr[i]= true;
        }


        fr(i,1,n)
        {
            ll x,y;
            cin>>x>>y;
            v[x].PB(y);
            v[y].PB(x);
        }

        ll si=dfs(1,n);

        for(auto it:croid) cout<<it<<"*";
        cout<<"\n";

        cout<<sz[1]<<"->"<<sz[2]<<"->"<<sz[3]<<"\n";
        

        if(croid.size()==1){

            auto it= croid.begin();
            ll centroid= *it;
            ll neigh= v[centroid][0];
            cout<<centroid<<" "<<neigh<<"\n";
            cout<<centroid<<" "<<neigh<<"\n";
        }
        else{

            auto it= croid.begin();
            ll centroid1= *it;
            it++;
            ll centroid2= *it;
            ll other;
            set<ll> cr;
            for(auto it:v[centroid1]) cr.insert(it);
            cr.insert(centroid1);
            for(auto it:v[centroid2]){
                if(cr.find(it)==cr.end()) other= it;
            }

            cout<<centroid2<<" "<<other<<"\n";
            cout<<centroid1<<" "<<other<<"\n";
        }


    }


    
    #ifndef ONLINE_JUDGE
        auto stop= high_resolution_clock::now();
        auto duration= duration_cast<milliseconds>(stop-start);
        cout<<"run time: "<<duration.count()<<" ms"<<"\n";
    #endif
}
