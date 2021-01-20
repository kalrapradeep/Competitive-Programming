class Solution {
public:
    vector<vector<int>> memo;
    const int MODULO=pow(10,9)+7;
    int dfs(vector<int>&locations,int start,int finish,int fuel)
    {
        if(memo[start][fuel]!=-1)
            return memo[start][fuel];
        memo[start][fuel]=0;
        if(start==finish)
            memo[start][fuel]=1;
        for(int i=0;i<locations.size();i++)
        {
            if(i!=start&&abs(locations[i]-locations[start])<=fuel)
            {
                if(start==finish&&i==finish)
                    continue;
                memo[start][fuel]=(memo[start][fuel]+(memo[i][fuel-abs(locations[i]-locations[start])]==-1?dfs(locations,i,finish,fuel-abs(locations[i]-locations[start])):memo[i][fuel-abs(locations[i]-locations[start])]))%MODULO;
            }
        }
        return memo[start][fuel];
    }
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        while(!memo.empty())
            memo.pop_back();
        vector<int> v;
        for(int i=0;i<=fuel;i++)
        {
            v.push_back(-1);
        }
        for(int i=0;i<locations.size();i++)
        {
            memo.push_back(v);
        }
        dfs(locations,start,finish,fuel);
        return memo[start][fuel];
    }
};
