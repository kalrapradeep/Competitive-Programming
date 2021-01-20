class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        bool isMax=false;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==nums.size())
                isMax=true;
            if(nums[i]>=nums.size()||nums[i]<0)
                nums[i]=0;
            
        }
        for(int i=0;i<nums.size();i++)
        {
            nums[nums[i]%nums.size()]=nums[nums[i]%nums.size()]%nums.size()+nums.size();
        }
        for(int i=0;i<nums.size();i++)
            nums[i]=nums[i]/nums.size();
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]==0)
                return i;
        }
        if(isMax)
        return nums.size()+1;
        if(nums.size()==0)
            return 1;
        return nums.size();
    }
};
