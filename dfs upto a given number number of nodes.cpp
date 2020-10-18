#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll arr[501][501];
vector <ll> v[250002];
bool vst[250002]={false};


void dfs(ll h, ll s,ll k, ll &count)
{
  if(count<s-k){ 
    queue<ll> q;
    q.push(h);
    vst[h]=true;
    count++;
   
   while(!q.empty())
   {
       ll p=q.front();
       q.pop();
        
    for(ll i=0;i<v[p].size();i++)
    {
        if(!vst[v[p][i]])
        {
            dfs(v[p][i],s,k,count);
        }
        
    }
    
   }
   }
   
   else
   {
       return;
   }
    
}



int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);

	
	ll n,m,k;
	cin>>n>>m>>k;
	ll s=0;
	
	for(ll i=1;i<=n;i++)
	{
	    for(ll j=1;j<=m;j++)
	    {
	        char c;
	        cin>>c;
	        if(c=='.')
	        {
	            arr[i][j]=s;
	            s++;
	        }
	        else
	        {
	            arr[i][j]=-1;
	        }
	    }
	}

	ll h=s-1;     // since s is greater than actual no. of dots by 1...

	for(ll i=1;i<=n;i++)
	{
	    for(ll j=1;j<=m;j++)
	    {
	        if(arr[i][j]!=-1)
	        {
	            if((i-1>0)&&arr[i-1][j]!=-1)
	            {
	                v[arr[i][j]].push_back(arr[i-1][j]);
	            }
	            
	            if((j-1>0)&&arr[i][j-1]!=-1)
	            {
	                v[arr[i][j]].push_back(arr[i][j-1]);
	            }
	            
	            if(i+1<=n&&arr[i+1][j]!=-1)
	            {
	                v[arr[i][j]].push_back(arr[i+1][j]);
	            }
	            
	            if(j+1<=m&&arr[i][j+1]!=-1)
	            {
	                v[arr[i][j]].push_back(arr[i][j+1]);
	            }
	        }
	    }
	}
	ll count=0;
	dfs(h,s,k,count);
	
	for(ll i=1;i<=n;i++)
	{
	    for(ll j=1;j<=m;j++)
	    {
	        if(arr[i][j]==-1)
	        {
	            cout<<'#';
	        }
	        else if(vst[arr[i][j]]==true)
	        {
	            cout<<'.';
	        }
	        else 
	        {
	            cout<<'X';
	        }
	    }
	    
	    cout<<"\n";
	}
	

}
