class Solution {
public:
   
    vector<string> ans;
   string key[10] = { "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    void solve(string in,int i,char *out,int j)
    {
        if(in.length()==0)
        {
            return ;
        }
        if (in[i] == '\0') {
		out[j] = '\0';
		ans.push_back(out);
		return;
	}

	// recursive case
	int dig = in[i] - '0';
    cout<<dig<<endl;
	for (int k = 0 ; key[dig][k] != '\0' ; k++) 
    {
		out[j] = key[dig][k];
		solve(in, i + 1, out, j + 1);
	}
    }
    vector<string> letterCombinations(string digits) {
        char out[100];
        solve(digits,0,out,0);
        return ans;
    }
};