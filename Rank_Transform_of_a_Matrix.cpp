class DisjointSet
{
  private:
    int* arr,*rank;
    int* score;
    public:
    DisjointSet(int n)
    {
        score=new int[n];
        arr=new int[n];
        rank=new int[n];
        for(int i=0;i<n;i++)
        {
            score[i]=1;
            arr[i]=i;
            rank[i]=1;
        }
    }
    int find(int x)
    {
        if(x==arr[x])
            return x;
        return find(arr[x]);
    }
    int getScore(int x)
    {
        if(x==arr[x])
            return score[x];
        else return getScore(arr[x]);
    }
    void unions(int a,int b,int s1)
    {
        int pa=find(a);
        int pb=find(b);
        if(pa==pb)
        {
            score[pa]=max(score[pa],s1);
            return;
        }
        if(rank[pa]>rank[pb])
        {
            arr[pb]=pa;
            score[pa]=max(max(score[pa],score[pb]),s1);
        }
        else
        {
            arr[pa]=pb;
            if(rank[pa]==rank[pb])
                rank[pb]+=1;
            score[pb]=max(max(score[pa],score[pb]),s1);
        }
    }
};
class Solution {
public:
    vector<vector<int>> matrixRankTransform(vector<vector<int>>& matrix) {
        vector<int> rows(matrix.size(),0);
        vector<int> cols(matrix[0].size(),0);
        vector<vector<int>> v;
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                v.push_back(vector<int>{matrix[i][j],i,j});
            }
        }
        sort(v.begin(),v.end());
        vector<vector<int>> temp;
        for(int i=0;i<v.size();i++)
        {
            if(temp.size()==0||temp[0][0]==v[i][0])
            {
                temp.push_back(v[i]);
            }
            else
            {
            DisjointSet* d=new DisjointSet(1000);
                for(int j=0;j<temp.size();j++)
                {
                    d->unions(temp[j][1],temp[j][2]+500,max(rows[temp[j][1]]+1,cols[temp[j][2]]+1));
                }
                for(int j=0;j<temp.size();j++)
                {
                    matrix[temp[j][1]][temp[j][2]]=d->getScore(temp[j][1]);
                    rows[temp[j][1]]=matrix[temp[j][1]][temp[j][2]];
                    cols[temp[j][2]]=matrix[temp[j][1]][temp[j][2]];
                }
                
            temp.clear();
                temp.push_back(v[i]);
            }
            
        }
            DisjointSet* d=new DisjointSet(1000);
                for(int j=0;j<temp.size();j++)
                {
                    d->unions(temp[j][1],temp[j][2]+500,max(rows[temp[j][1]]+1,cols[temp[j][2]]+1));
                }
                for(int j=0;j<temp.size();j++)
                {
                    matrix[temp[j][1]][temp[j][2]]=d->getScore(temp[j][1]);
                    rows[temp[j][1]]=matrix[temp[j][1]][temp[j][2]];
                    cols[temp[j][2]]=matrix[temp[j][1]][temp[j][2]];
                }
                
        return matrix;
    }
};
