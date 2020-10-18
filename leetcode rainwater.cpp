#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
    vector<int> height;
    
    int y=12;
    while(y--)
    {
        int u;
        cin>>u;
        height.push_back(u);
    }
	
	  int n=height.size();
        if(n<3){
            cout<< 0<<"\n";
        }
        
        else{
        int l=0,r=0;
        int sum=0;
        
        while(l<n)
        {
            int x=0;
            while(r<n&&height[r]<height[l])
            {
                r++;
                x+=(height[l]-height[r]);
            }
            
            if(r==n-1&&height[n-1]<height[l])
            {
               l+=n;
               
            }
            
            else
            {
                sum+=x;
                
            }
            
            l+=(r-l);
        }
      
       // cout<<l<<" "<<r<<"\n";
       cout<< sum<<"\n";
        }   
}
