class Solution {
public:
    const int MODULO=pow(10,9)+7;
           vector<vector<int>> v;
    vector<vector<int>> dp;
    string targ;
    long long int dfs(int index,int start)
    {
        if(start==targ.length())
            return 1;
        if(index>=v.size())
            return 0;
        if(dp[index][start]!=-1)
            return dp[index][start];
        long long int total=0;
        
            if(v[index][targ[start]-'a']>0)
            total=(total+(long long int)v[index][targ[start]-'a']*(long long int)(dp[index+1][start+1]==-1?dfs(index+1,start+1):dp[index+1][start+1]))%MODULO;
            total=(total+dfs(index+1,start))%MODULO;
        dp[index][start]=total;
        return total;
    }
    int numWays(vector<string>& words, string target) {
        int sz=0;
        for(int i=0;i<words.size();i++)
        {
            for(int j=0;j<words[i].length();j++)
            {
                if(j==v.size())
                    v.push_back(vector<int>(26,0));
                v[j][words[i][j]-'a']++;
            }
            int len=words[i].length();
            sz=max(sz,len);
        }
        targ=target;
            vector<vector<int>> dp1(sz+1,vector<int>(target.length()+1,-1));
        dp=dp1;
        return dfs(0,0);
        
    }
};
