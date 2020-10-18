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


void permut_with_cases(string in,string out)
{
    if(in.length()==0){
        cout<<out<<"\n";
        return;
    }

    string out1= out;
    string out2= out;

    out2.PB(toupper(in[0]));
    out1.PB(in[0]);
    in.erase(in.begin()+0);

    permut_with_cases(in,out1);
    permut_with_cases(in,out2);

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
    
    string s;
    cin>>s;

    string outp="";
    permut_with_cases(s,outp);

}