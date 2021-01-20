class Solution {
public:
    long long int minDis(vector<int>&houses,int k,int ind,vector<vector<int>>&dp)
    {
        if(ind>=houses.size())
            return 0;
        if(k==0)
            return INT_MAX;
        if(dp[k][ind]!=-1)
            return dp[k][ind];
        long long int ans=INT_MAX;
        for(int i=ind;i<houses.size();i++)
        {
            
            long long int dist=0;
            int count=i-ind+1;
            if(count%2==0)
            {
                int box=(ind+i)/2;
                for(int j=ind;j<=i;j++)
                {
                    dist+=abs(houses[box]-houses[j]);
                    
                }
                
            }
            else
            {
                int box=(ind+i)/2;
                for(int j=ind;j<=i;j++)
                {
                    dist+=abs(houses[box]-houses[j]);
                    
                }
                
            }
            ans=min(ans,minDis(houses,k-1,i+1,dp)+dist);
        }
        dp[k][ind]=ans;
        return ans;
    }
    int minDistance(vector<int>& houses, int k) {
        if(houses.size()==0)
            return 0;
        sort(houses.begin(),houses.end());
        vector<vector<int>> dp(k+1,vector<int>(houses.size()+1,-1));
        vector<int> arr(houses.size(),0);
        arr[0]=houses[0];
        for(int i=1;i<houses.size();i++)
        {
            arr[i]=arr[i-1]+houses[i];
        }
        return minDis(houses,k,0,dp);
    }
};
