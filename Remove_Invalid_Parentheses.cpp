class Solution {
public:
    unordered_map<string,int> mp;
    void getPerms(string s,vector<int>&openIndex,vector<int>&closeIndex,int i1,int i2,int ind,vector<string>& res,string s1)
    {
        if(ind==s.length())
        {
            if(i1==openIndex.size()&&i2==closeIndex.size()&&mp.find(s1)==mp.end())
            {
                mp[s1]=1;
                res.push_back(s1);
            }
            return;
        }
        getPerms(s,openIndex,closeIndex,i1,i2,ind+1,res,s1+s[ind]);
        if(s[ind]=='('&&i1!=openIndex.size())
        {
            if(openIndex[i1]<=ind)
            {
                getPerms(s,openIndex,closeIndex,i1+1,i2,ind+1,res,s1);
            }
            
        }
        if(s[ind]==')'&&i2!=closeIndex.size())
        {
            if(closeIndex[i2]>=ind)
            {
                getPerms(s,openIndex,closeIndex,i1,i2+1,ind+1,res,s1);
            }
            
        }
        
    }
    vector<string> removeInvalidParentheses(string s) {
        vector<string> res;
        mp.clear();
        vector<int> closeIndex;
        vector<int> openIndex;
        int open=0,close=0;
        stack<int> st;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='(')
            {
                st.push(i);
            }
            if(s[i]==')')
            {
                if(st.size()==0)
                    closeIndex.push_back(i);
                else
                    st.pop();
            }
        }
        while(!st.empty())
        {
            openIndex.push_back(st.top());
            st.pop();
        }
        reverse(openIndex.begin(),openIndex.end());
        getPerms(s,openIndex,closeIndex,0,0,0,res,"");
        return res;
    }
};
