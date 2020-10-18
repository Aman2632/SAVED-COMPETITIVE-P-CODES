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


void rec_subset(string out,string in,map<string,ll> &m)
{
     if(in.length()==0)
     {
        //cout<<out<<"\n";
        m[out]++;
        return;
     }

     string op1= out;
     string op2= out;
     op2.push_back(in[0]);
     in.erase(in.begin()+0);
     rec_subset(op1,in,m);
     rec_subset(op2,in,m);
     return;
}


int main()
{
    
    #ifndef ONLINE_JUDGE
        freopen("input1.txt","r", stdin);
        freopen("output1.txt","w",stdout);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    
    string s,t;
    cin>>s>>t;
    
    map<string,ll> m;
    rec_subset("",s,m);

    cout<<m[t];
}