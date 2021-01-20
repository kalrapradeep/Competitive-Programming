class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int T[prices.size()+1][3];
        for(int i=0;i<prices.size();i++)
        {
            T[i][0]=0;
        }
        for(int i=0;i<3;i++)
        {
            T[0][i]=0;
        }
        for(int j=1;j<3;j++)
        {
            int maxDiff=INT_MIN;
            for(int i=1;i<=prices.size();i++)
            {
                T[i][j]=max(maxDiff+prices[i-1],T[i-1][j]);
                maxDiff=max(T[i-1][j-1]-prices[i-1],maxDiff);
            }
        }
        return T[prices.size()][2];
    }
};
