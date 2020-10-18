
// REFER ADITYA VERMA RECURSION PLAYLIST FOR MORE DETAIL...

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


void balanced_paranth(string out,ll op,ll cl)
{
    if((op==0)&&(cl==0)){
        cout<<out<<"\n";
        //return;
    }

    if(op>=cl){

        out.PB('(');
        op--;
        balanced_paranth(out,op,cl);
    }

    else{                 // IF number of closing brackets > than opening brackets then only push them...
        string out1= out;
        string out2= out;

        if(op>0){
            out1.PB('(');
            balanced_paranth(out1,op-1,cl);
        }

        if(cl>0){
            out2.PB(')');
            balanced_paranth(out2,op,cl-1);
        }
    }
}


int main()
{
    
    #ifndef ONLINE_JUDGE
        freopen("input1.txt","r", stdin);
        freopen("output1.txt","w",stdout);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    
    ll n;
    cin>>n;

    string res="";
    balanced_paranth(res,n,n);

}