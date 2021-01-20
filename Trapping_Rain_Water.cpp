class Solution {
public:
    int trap(vector<int>& height) {
        int sum=0;
        vector<int> arr(height.size(),0);
        int curr_max=0;
        for(int i=0;i<height.size();i++)
        {
            curr_max=max(curr_max,height[i]);
            arr[i]=curr_max;
        }
        curr_max=0;
        for(int i=height.size()-1;i>=0;i--)
        {
            curr_max=max(curr_max,height[i]);
            sum+=(min(curr_max,arr[i])-height[i]);
        }
        return sum;
    }
};
