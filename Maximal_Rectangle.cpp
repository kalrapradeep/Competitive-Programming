class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size()==0)
            return 0;
        vector<vector<int>> dp(matrix.size(),vector<int>(matrix[0].size(),0));
        int ans=0;
        for(int i=0;i<matrix[0].size();i++)
        {
            for(int j=0;j<matrix.size();j++)
            {
                if(j==0)
                {
                    dp[j][i]=matrix[j][i]-'0';
                }
                else
                {
                    if(matrix[j][i]=='0')
                    dp[j][i]=0;
                    else
                        dp[j][i]=dp[j-1][i]+1;
                }
            }
        }
        for(int i=0;i<matrix[0].size();i++)
        {
            for(int j=0;j<matrix.size();j++)
            {
                int ht=INT_MAX;
                        for(int k=i;k>=0;k--)
                        {
                            ht=min(ht,dp[j][k]);
                            ans=max(ans,ht*(i-k+1));
                        }
            }
            
        }
        
        return ans;
    }
};
