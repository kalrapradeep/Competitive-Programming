class Solution {
public:
    unordered_map<int,int> mp;
    void findPerms(int r,int n,vector<string> v1,int&count)
    {
        if(r==n)
        {
            count++;
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
                findPerms(r+1,n,v1,count);
                v1[r][i]='.';
                mp.erase(i);
            }
        }
    }
    
    int totalNQueens(int n) {
        mp.clear();
        vector<string> v;
        string s1="";
        for(int i=0;i<n;i++)
            s1.push_back('.');
        for(int i=0;i<n;i++)
        {
            v.push_back(s1);
        }
        int count=0;
        findPerms(0,n,v,count);
        return count;
        
    }
};
