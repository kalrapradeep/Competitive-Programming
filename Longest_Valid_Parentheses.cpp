class Solution {
public:
    int longestValidParentheses(string s) {
        stack<pair<char,int>> st1;
        int max=0;
        stack<pair<int,int>> st2;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='(')
            {
                st1.push(make_pair('(',i));
                
            }
            else
            {
                if(st1.size()!=0)
                {
                    pair<int,int> p=make_pair(st1.top().second,i);
                    while(!st2.empty())
                    {
                        if(st2.top().second==p.first-1)
                        {
                            p.first=st2.top().first;
                            st2.pop();
                            break;
                        }
                        else if(st2.top().first>p.first)
                        {
                            st2.pop();
                        }
                        else
                            break;
                    }
                    st2.push(p);
                    st1.pop();
                }
                
                
            }
        }
        while(!st2.empty())
        {
            if(max<st2.top().second-st2.top().first+1)
                max=st2.top().second-st2.top().first+1;
            st2.pop();
        }
        return max;
    }
};
