class Solution {
public:
    unordered_map<int,int> mp;
    void findPerms(int r,int n,vector<vector<string>>&v,vector<string> v1)
    {
        if(r==n)
        {
            v.push_back(v1);
            return;
        }
        for(int i=0;i<n;i++)
        {
            if(mp.find(i)==mp.end())
            {
                bool b=true;
                int j=r-1,k=i-1;
                while(j>=0&&k>=0)
                {
                    if(v1[j][k]!='.')
                    {
                        b=false;
                        break;
                    }
                    j--;
                    k--;
                }
                j=r-1,k=i+1;
                while(j>=0&&k<n)
                {
                    if(v1[j][k]!='.')
                    {
                        b=false;
                        break;
                    }
                    j--;
                    k++;
                }
                if(!b)
                    continue;
                v1[r][i]='Q';
                mp[i]=1;
                findPerms(r+1,n,v,v1);
                v1[r][i]='.';
                mp.erase(i);
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        mp.clear();
        vector<string> v;
        vector<vector<string>> v1;
        string s1="";
        for(int i=0;i<n;i++)
        {
            s1.push_back('.');
        }
        for(int i=0;i<n;i++)
        {
            v.push_back(s1);
        }
        findPerms(0,n,v1,v);
        return v1;
    }
};
