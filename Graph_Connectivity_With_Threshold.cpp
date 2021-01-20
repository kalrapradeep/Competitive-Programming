class DisjointSet
{
    public:
    int* arr;
    DisjointSet(int n)
    {
        arr=new int[n+1];
        for(int i=0;i<=n;i++)
        {
            arr[i]=i;
        }
    }
    int find(int x)
    {
        if(arr[x]==x)
            return x;
        int y=find(arr[x]);
        arr[x]=y;
        return y;
    }
    void unions(int x,int y)
    {
        int px=find(x);
        int py=find(y);
        if(px==py)
            return;
            arr[py]=px;
        
    }
};
class Solution {
public:
    vector<bool> areConnected(int n, int threshold, vector<vector<int>>& queries) {
        vector<bool> v;
        DisjointSet* d=new DisjointSet(n);
        unordered_map<int,vector<int>> mp;
        for(int i=threshold+1;i<=n;i++)
        {
            for(int j=i;j<=n;j+=i)
            {
                mp[i].push_back(j);
            }
        }
        for(auto x:mp)
        {
            for(int j=0;j<x.second.size()-1;j++)
            {
                d->unions(x.second[j],x.second[j+1]);
            }
        }
        for(int i=0;i<queries.size();i++)
        {
                if(d->find(queries[i][0])==d->find(queries[i][1]))
                {
                    v.push_back(true);
                }
                else
                v.push_back(false);
            
        }
        return v;
    }
};
