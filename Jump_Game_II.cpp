class Solution {
public:
    int jump(vector<int>& nums) {
        int arr[nums.size()];
        arr[nums.size()-1]=0;
        stack<pair<int,int>> st;
        st.push(make_pair(0,nums.size()-1));
        for(int i=nums.size()-2;i>=0;i--)
        {
            arr[i]=INT_MAX;
        pair<int,int> p;
            while(!st.empty())
            {
                if(i+nums[i]>=st.top().second)
                {
                    if(st.top().first!=INT_MAX)
                    arr[i]=st.top().first+1;
                }
                else
                    break;
                p=st.top();
                st.pop();
            }
            st.push(p);
            while(!st.empty())
            {
                if(st.top().first>arr[i])
                    st.pop();
                else
                    break;
            }
            st.push(make_pair(arr[i],i));
            
        }
        return arr[0];
    }
};
