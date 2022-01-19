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
        for(int j=i;j<n;j++)
//we are not making any recursive calls for the exclusion    case of ith   element because once all the recurive calls that includes the ith elements are over we backtrack and this loop helps us to move to next element   of the input array    that does not include previous ith elememt
        {
            if(sum+candidates[j]<=target)
            {
                out.push_back(candidates[j]);
                solve(candidates,target,j,sum+candidates[j],out,n);
                out.pop_back();//backtracking
                //we backtrack because after the inclusion is over then we come to this line if we don't want the current element in our vector so we remove it
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int i=0;
        int j=0;
        int sum=0;
        vector<int> out;
        int n=candidates.size();
        solve(candidates,target,i,sum,out,n);
        return ans;
    }
};