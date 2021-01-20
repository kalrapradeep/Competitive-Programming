class Solution {
public:
    int fact(int n)
    {
        if(n<=1)
            return 1;
        else return n*fact(n-1);
    }
    void removeIndex(vector<int>&v,int index)
    {
        for(int i=index;i<v.size()-1;i++)
        {
            v[i]=v[i+1];
        }
        v.pop_back();
    }
    string getPermutation(int n, int k) {
        int num=k/fact(n-1);
        int rem=k-num*fact(n-1);
        vector<int> v;
        string s="";
        for(int i=0;i<n;i++)
        {
            v.push_back(i+1);
        }
        while(rem!=0)
        {
            s=s+(char)(v[num]+'0');
            removeIndex(v,num);
            n--;
            num=rem/fact(n-1);
            rem-=num*fact(n-1);
        }
        cout<<num<<" ";
        s=s+(char)(v[num-1]+'0');
        removeIndex(v,num-1);
        for(int i=v.size()-1;i>=0;i--)
        {
            s=s+(char)(v[i]+'0');
        }
        return s;
    }
};
