class Solution {
public:
    class DisjointSet
    {
        public:
        int* arr;
        int* rank;
        int n;
        DisjointSet(int n)
        {
            this->n=n;
            arr=new int[n+1];
            rank=new int[n+1];
            for(int i=0;i<=n;i++)
            {
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
        void unions(int x,int y)
        {
            int p1=find(x);
            int p2=find(y);
            if(rank[p1]>rank[p2])
            {
                arr[p2]=p1;
            }
            else
            {
                arr[p1]=p2;
                if(rank[p1]==rank[p2])
                    rank[p2]+=1;
            }
        }
        bool checkSet()
        {
            int ct=0;
            for(int i=1;i<=n;i++)
            {
                if(arr[i]==i)
                    ct++;
            }
            return ct==1;
        }
    };
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        DisjointSet *s1=new DisjointSet(n);
        DisjointSet *s2=new DisjointSet(n);
        int count=0;
        for(int i=0;i<edges.size();i++)
        {
            cout<<edges[i][0]<<" ";
            if(edges[i][0]==3)
            {
                bool b1=true,b2=true;
                if(s2->find(edges[i][1])!=s2->find(edges[i][2]))
                    s2->unions(edges[i][1],edges[i][2]);
                else
                    b1=false;
                if(s1->find(edges[i][1])!=s1->find(edges[i][2]))
                    s1->unions(edges[i][1],edges[i][2]);
                else
                    b2=false;
                if(!b1&&!b2)
                    count++;
                
            }
            
        }
        for(int i=0;i<edges.size();i++)
        {
            if(edges[i][0]==1)
            {
                if(s1->find(edges[i][1])!=s1->find(edges[i][2]))
                    s1->unions(edges[i][1],edges[i][2]);
                
                else
                    count++;
            }
            else if(edges[i][0]==2)
            {
                if(s2->find(edges[i][1])!=s2->find(edges[i][2]))
                    s2->unions(edges[i][1],edges[i][2]);
                
                else
                    count++;
            }
            
            
        }
        
        if(s1->checkSet()&&s2->checkSet())
        return count;
        else
            return -1;
        
    }
};
