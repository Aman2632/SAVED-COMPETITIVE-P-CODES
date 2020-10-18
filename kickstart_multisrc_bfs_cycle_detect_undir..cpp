#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

vector<ll> v[200200];
ll color[200200]={0};
ll parent[200200];
vector<ll> cycle;

// Running dfs to detect the cycle using color method...

// COLOR-CODE: 0->unvisited; 1->in_queue; 2->already processed...

void dfs(ll h,ll p)   // h->CURRENT,p->PARENT.....
{
  
   parent[h]=p;      // mark p as parent of h...
   if(color[h]==2)   //already completely visited...
   {
       return;
   }
   
   else if(color[h]==1)             //-> a backedge detected.....
   {
        
       ll curr=p;                   // backtrack using the parent array untill you reach the node h...
       while(curr!=h)
       {
           cycle.push_back(curr);   // keep pushing all parents into the cycle vector....
           curr=parent[curr];       // update curr to its parent....
       }
       
       cycle.push_back(h);          // push_back the initial node h to complete the cycle...
       
       color[h]=2;                  // change the colour of the node to 2 and return from  the function since
       return;                      // given that only one CYCLE....
       
   }
   
   
   
  if(color[h]==0)                    // unvisited.....go for normal dfs....
   {
       color[h]=1;                   // mark visited-1 at start...
       for(auto u: v[h])             // iterate on adjacency list of h.....
       {
           if(u!=parent[h])          // if a list item u of h is not the parent of h, run dfs on u...
           {
              dfs(u,h);
           }
       }
       color[h]=2;                    // mark visited-2 at end...
       return;                        // return from the function call....
   }
}


ll vst[200200]={0};
//ll dist[200200]={0};

// running multi_source bfs to calculate shortest distance....

void multi_sorce_bfs(vector<ll> &dist)    // BETTER PASS AND RETURN  VECTOR THAN ARRAYS...
{
    queue<ll> q;
    for(ll i=0;i<cycle.size();i++)
    {
        q.push(cycle[i]);
        //dist[cycle[i]]=0;   // THIS STEP NOT NEEDED as we already initialized all dist elements to 0...
        vst[cycle[i]]=1;      // THIS STEP IS MUST AS IT'S Absence may cause the distance of source to be reassigned 
    }                         // as it appears in the adjacency list of the neighbour elements of the cycle..
    
    while(!q.empty())
    {
        ll j=q.front();
        q.pop();
        vst[j]=1;
        
        for(auto i:v[j]){
            if(!vst[i])
            {
                q.push(i);
                dist[i]=dist[j]+1;
                vst[i]=1;
            }
        }
    }
   // return dist;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	
	ll t;
	cin>>t;
	for(ll z=1;z<=t;z++)
	{
	    
	    ll n;
	    cin>>n;
	    
	    for(ll i=1;i<=n;i++)
	    {
	        v[i].clear();
	    }
	    vector<ll> dist(n+1);
	    memset(color,0,sizeof(color));       // must clear all global variables since multiple test cases involved...
	    memset(parent,0,sizeof(parent));
	    cycle.clear();                       
	    memset(vst,0,sizeof(vst));
	    //memset(dist,0,sizeof(dist));
	    dist.assign(n+1,0);  
	   
	    
	    while(n--)                     // ONLY N edges since it was given that graph has only 1 cycle...
	    {
	        ll x,y;
	        cin>>x>>y;
	        v[x].push_back(y);         // generating the undirected graph's adjacency list....        
	        v[y].push_back(x); 
	    }
	    
	    memset(color,0,sizeof(color));            // initalize the color array as unvisited...
	    memset(parent,-1,sizeof(parent));         // initalize the parent array as -1...
	    
	  dfs(1,0);                       // run dfs on 1 and mark its parent as 0... 
	    

	  multi_sorce_bfs(dist);
	  
	  cout<<"Case #"<<z<<": ";
	  
	  for(auto it=dist.begin()+1;it!=dist.end();it++)
	  {
	      cout<<*it<<" ";
	  }
	  
	  //cout<<cycle[0]<<" "<<cycle[1]<<" "<<cycle[2]<<" "<<dist[1]<<" "<<dist[4]<<" "<<dist[3]<<"\n";
	  cout<<"\n";
	 
	}
	
}
