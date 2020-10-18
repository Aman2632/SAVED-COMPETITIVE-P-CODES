#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
char mapp[55][55];
ll vst[55][55];

ll n,m,k,size,top=0;
ll dx[]={0,1,0,-1};     //BEST WAY TO TRAVERSE ON THE NEIGHBOURS...
ll dy[]={1,0,-1,0};

/*vector<pair<ll,pair<ll,ll>> > v(52*52);  //v[i].first.first=x,v[i].first.second=y,v[i].second=size of lake

bool comp(pair<ll,pair<ll,ll>> &v1,pair<ll,pair<ll,ll>> &v2)
{
    return v1.first<v2.first ;
} */

struct node{     // MORE BETTER THAN USING PAIRS.....
    ll x;
    ll y;
    ll num;
}v[55*55];

bool comp(node a,node b)    // BETTER WAY TO COMPARE
{
    return a.num<b.num;
}


void dfs(ll x,ll y)
{
    size++;
    vst[x][y]=1;
    
    for(ll i=0;i<4;i++)
    {
        ll g=x+dx[i];
        ll h=y+dy[i];
        if(vst[g][h]==0&&(mapp[g][h]=='.')&&(g<n&&h<m)&&(g>=0&&h>=0))
        {
            dfs(g,h);
        }
        
    }
}

void dfs_ocean(ll x,ll y)
{
     vst[x][y]=1;
    
    for(ll i=0;i<4;i++)
    {
        ll g=x+dx[i];
        ll h=y+dy[i];
        if(vst[g][h]==0&&(mapp[g][h]=='.')&&(g<n&&h<m)&&(g>=0&&h>=0))
        {
            dfs_ocean(g,h);
        }
        
    }
}


void dfs_change(ll x,ll y)
{
    vst[x][y]=1;
    mapp[x][y]='*';
    
     for(ll i=0;i<4;i++)
    {
        ll g=x+dx[i];
        ll h=y+dy[i];
        if((mapp[g][h]=='.')&&(g<n&&h<m)&&(g>=0&&h>=0))
        {
            dfs_change(g,h);
        }
        
    }

}

void print()
{
    for(ll i=0;i<n;i++)
    {
        for(ll j=0;j<m;j++)
        {
          cout<<mapp[i][j];
        }
        
        cout<<"\n";
    }
}



int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	memset(vst,0,sizeof(vst));
	

	cin>>n>>m>>k;
	
//	top=0;
	
	for(ll i=0;i<n;i++)
	{
	    for(ll j=0;j<m;j++)
	    {
	        cin>>mapp[i][j];
	    }
	}
	

	
	for(ll i=0;i<n;i++)
	{
	    for(ll j=0;j<m;j++)
	    {
	        if((i==0||j==0||i==n-1||j==m-1)&&mapp[i][j]=='.'&&!vst[i][j])
	        {
	            dfs_ocean(i,j);
	        }
	    }
	}
	
	ll cc=0;
	
		for(ll i=0;i<n;i++)
	{
	    for(ll j=0;j<m;j++)
	    {
	        if(mapp[i][j]=='.'&&vst[i][j]==0)
	        {
	            dfs(i,j);
	          //  pair <ll,ll> a=make_pair(i,j);
	          //  v.push_back(make_pair(size,a));
	           // size=0;
	          //  cc++;
	          
	          v[top].x=i;
	          v[top].y=j;
	          v[top++].num=size;
	          size=0;
	        }
	    }
	}
	
	sort(v,v+top,comp);
	
	ll high=top;ll z=0;
	
	for(ll i=0;i<top;i++)
	{
	       if(high==k)
	        {
	            break;
	        }
	        
	        dfs_change(v[i].x,v[i].y);
	        z+=v[i].num;
	        high--;
	}
	
	cout<<z<<"\n";
	print();
	
	return 0;
	
	
}?/
