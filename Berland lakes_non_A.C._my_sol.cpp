#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
char arr[52][52];
ll gra[52][52];
vector<ll> v[55];
bool vst[55]={false};
vector<ll> com[55];

vector<pair<ll,ll> > haha ;


void dfs(ll h)
{
    queue<ll> q;
    q.push(h);
    vst[h]=true;
    
    while(!q.empty())
    {
        ll p=q.front();
        q.pop();
        // com[h].push_back(p);
        for(ll i=0;i<v[p].size();i++)
        {
            
            
            if(vst[v[p][i]]==false)
            {
                com[h].push_back(v[p][i]);
                dfs(v[p][i]);
               
            }
        }
    }
}


int main()
{
	 ios_base::sync_with_stdio(false);
	 cin.tie(NULL);cout.tie(NULL);
	 ll n,m,k;
	 cin>>n>>m>>k;
	 
	 for(ll i=1;i<=n;i++)
	 {
	     for(ll j=1;j<=m;j++)
	     {
	         cin>>arr[i][j];
	     }
	 }
	 
	 for(ll j=1;j<=m;j++)
	 {
	     if(arr[1][j]=='.')
	     {
	         gra[1][j]=-1;
	     }
	     else
	     {
	         gra[1][j]=0;
	     }
	     
	     if(arr[n][j]=='.')
	     {
	         gra[n][j]=-1;
	     }
	     else
	     {
	         gra[n][j]=0;
	     }
	 }
	 
	  for(ll j=1;j<=n;j++)
	 {
	     if(arr[j][1]=='.')
	     {
	         gra[j][1]=-1;
	     }
	     else
	     {
	         gra[j][1]=0;
	     }
	     
	     if(arr[j][m]=='.')
	     {
	         gra[j][m]=-1;
	     }
	     else
	     {
	         gra[j][m]=0;
	     }
	 }
	 
	 ll s=0;
	 
	 for(ll i=2;i<=n-1;i++)
	 {
	     for(ll j=2;j<=m-1;j++)
	     {
	         if(arr[i][j]=='*')
	         {
	             gra[i][j]=0;
	         }
	         
	         else
	         {
	             if(gra[i-1][j]==-1||gra[i][j-1]==-1||gra[i+1][j]==-1||gra[i][j+1]==-1)
	             {
	                 gra[i][j]=-1;
	             }
	             else
	             {
	                 gra[i][j]=s;
	                 s++;
	             }
	             
	         }
	     }
	 }
	 
 /* 	 for(ll i=1;i<=n;i++)
	 {
	     for(ll j=1;j<=m;j++)
	     {
	         cout<<gra[i][j]<<" ";
	     }
	     
	     cout<<"\n";
	 }   
*/

//  ll s=1;
    
    for(ll i=1;i<=n;i++)
	 {
	     for(ll j=1;j<=m;j++)
	     {
	         if(gra[i][j]!=0||gra[i][j]!=-1)
	         {
	             if((i-1>0)&&(gra[i-1][j]!=-1||gra[i-1][j]!=0))
	            {
	                v[gra[i][j]].push_back(gra[i-1][j]);
	            }
	            
	            if((j-1>0)&&(gra[i][j-1]!=-1||gra[i][j-1]!=0))
	            {
	                v[gra[i][j]].push_back(gra[i][j-1]);
	            }
	            
	            if(i+1<=n&&(gra[i+1][j]!=-1||gra[i+1][j]!=0))
	            {
	                v[gra[i+1][j]].push_back(gra[i+1][j]);
	            }
	            
	            if(j+1<=m&&(gra[i][j+1]!=-1||gra[i][j+1]!=0))
	            {
	                v[gra[i][j]].push_back(gra[i][j+1]);
	            }
	         }
	     }
	 } 

ll cc=0;
ll xxx[55];
ll e=0;
    for(ll i=0;i<s;i++)
    {
        if(vst[i]==false)
        {
            dfs(i);
            xxx[e++]=i;
            cc++;
        }
    }


   for(ll i=0;i<cc;i++)
   {
       haha.push_back(make_pair(com[xxx[i]].size(),i));
   }

   


    if(cc==k)
    {
        cout<<0<<"\n";
        for(ll i=1;i<=n;i++)
	   {
	     for(ll j=1;j<=m;j++)
	     {
	         cout<<arr[i][j];
	     }
	     
	     cout<<"\n";
	   }
    }
	
   else{
       
     
	sort(haha.begin(),haha.end());
	ll lol[55]={0};
	ll si=0;
	for(ll i=0;i<(cc-k);i++)
	{
	    si+=com[haha[i].second].size();
	    for(ll j=0;j<com[haha[i].second].size();j++)
	    {
	        lol[com[xxx[i]][j]]=1;
	    }
	}
	
	cout<<si+cc-k<<"\n";
	
	
	for(ll i=1;i<=n;i++)
	{
	    for(ll j=1;j<=m;j++)
	    {
	        if(gra[i][j]==0)
	        {
	            cout<<'*'<<" ";
	        }
	        else if(gra[i][j]==-1)
	        {
	            cout<<'.'<<" ";
	        }
	        else 
	        {
	            if(lol[gra[i][j]]==1)
	            {
	                cout<<'*'<<" ";
	            }
	            else
	            {
	                cout<<'.'<<" ";
	            }
	        }
	    }
	    
	    cout<<"\n";
	    
	}
	}
	
}
