class Solution {
public:
    vector<vector<int>> ans;
    void solve(vector<int>& x,vector<int>& nums,int i)
    {
        if(i==nums.size())
        {
            ans.push_back(x);;
            return ;
        }
        for(int j=i;j<nums.size();j++)
        {
            swap(nums[i],nums[j]);
            x.push_back(nums[i]);
            solve(x,nums,i+1);
            swap(nums[i],nums[j]);
            x.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> x;
        solve(x,nums,0);
        return ans;
    }
};