
class Solution {
public:
    vector<vector<int>> ans;
    void solve(vector<int> nums,vector<int> &x,int i)
    {
        if(i==nums.size())
        {
            ans.push_back(x);
            return ;
        }
        for(int j=i;j<nums.size();j++)
        {
            if(nums[i]==nums[j] and i!=j)
            {

                continue;
            }
            
                swap(nums[i],nums[j]);
                x.push_back(nums[i]);
                solve(nums,x,i+1);
                x.pop_back();
            
            
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> x;
        sort(nums.begin(),nums.end());
        solve(nums,x,0);
        return ans;
    }
};