class Solution {
public:
    vector<vector<int>> ans;
    void solve(vector<int>& candidates, int target,int i,int sum,vector<int> &out,int n)
    {
        if(sum==target)
        {
            ans.push_back(out);
            return ;
        }
        if(sum>target)
        {
            return ;
        }
        int prev=-1;//initializing with -1 so that ki pehle first element ka inclusion ho
        for(int j=i;j<n;j++)
        {
            if(prev==candidates[j])//this is for exclusion case, hum agar exclude karre hai toh us value ke equal jitne bhi elements hai sabko kardenge taaki duplication na ho
            {
                continue;
            }
            if(sum+candidates[j]<=target)
            {
                out.push_back(candidates[j]);
                solve(candidates,target,j+1,sum+candidates[j],out,n);
                out.pop_back();//backtracking
                prev=candidates[j];//no once the inclusion part is done for ith element then we will do exclusion part 
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int i=0;
        int j=0;
        int sum=0;
        vector<int> out;
        int n=candidates.size();
        sort(candidates.begin(),candidates.end());
        solve(candidates,target,i,sum,out,n);
        return ans;
    }
};