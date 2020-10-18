class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target)
    {
	    
        sort(nums.begin(),nums.end());
        
        int ans=1e5;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            int t=(target-nums[i]);  // from O(n3) to O(n2) cn be reuced by fixing 
            int left=i+1;  // one of nums[i] and two pointer on the rest
            int right=n-1;
            
            while(left<right)
            {
                int s=nums[left]+nums[right]+nums[i];
                
                if(abs(s-target)<=abs(ans-target))
                {
                    ans=s;
                   
                }
                
                if(s==target)
                {
                    break;
                }
                
                else if(s>target)
                {
                    right--;
                }
                
                else
                {
                    left++;
                }
            }
            
        }
        
        return ans;
    
}

    
};