class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> rights(heights.size(),0);
        vector<int> lefts(heights.size(),0);
        stack<pair<int,int>> st;
        for(int i=0;i<heights.size();i++)
        {
            while(!st.empty())
            {
                if(st.top().first<=heights[i])
                    break;
                rights[st.top().second]=(i-st.top().second-1);
                st.pop();
            }
            st.push({heights[i],i});
        }
        while(!st.empty())
        {
            rights[st.top().second]=(heights.size()-1-st.top().second);
            st.pop();
        }
        for(int i=heights.size()-1;i>=0;i--)
        {
            while(!st.empty())
            {
                if(st.top().first<=heights[i])
                    break;
                lefts[st.top().second]=(st.top().second-i-1);
                st.pop();
            }
            st.push({heights[i],i});
        }
        while(!st.empty())
        {
            lefts[st.top().second]=(st.top().second);
            st.pop();
        }
        int m1=0;
        for(int i=0;i<heights.size();i++)
        {
            m1=max(heights[i]*(lefts[i]+rights[i]+1),m1);
        }
        return m1;
    }
};
