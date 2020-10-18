// REVERSE STACK USING RECURSION//


#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
using ii= pair<ll,ll>;
#define all(o) (o).begin(),(o).end()
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define ld long double
#define eps 0.00000000001

class prioritize{
    public: bool operator() (ii &p1,ii &p2){
        return p1.F<p2.F;
    }
};

void insert(stack<ll> &s, ll top)
{
    if(s.size()==0)
    {
        s.push(top);
        return;
    }

    ll val= s.top();
    s.pop();
    insert(s,top);
    s.push(val);
    return;
}

void rec_reverse(stack<ll> &s)
{
    if(s.size()==1) return;
    ll temp= s.top();
    s.pop();
    rec_reverse(s);
    insert(s,temp);
}

int main()
{
    
    #ifndef ONLINE_JUDGE
        freopen("input1.txt","r", stdin);
        freopen("output1.txt","w",stdout);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    
    stack<ll> s;
    ll n;
    cin>>n;

    for(ll i=1;i<=n;i++)
    {
        ll x;
        cin>>x;
        s.push(x);
    }

     //while(!s.empty())
    
    //cout<<"\n";

    rec_reverse(s);
    while(!s.empty())
    {
        ll top= s.top();
        cout<<top<<"\n";
        s.pop();
    }


 
