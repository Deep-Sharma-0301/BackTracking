class Solution {
public:
    vector<vector<string>> ans;
    vector<string> temp; 
    bool isSafe(int board[][100],int i,int j,int n)
    {
        int x=i;
        int y=j;
        for(int k=0;k<i;k++)
        {
            if(board[k][j]==1)
            {
                return false;
            }
        }
        while(i>=0 and j<n)
        {
            if(board[i][j]==1)
            {
                return false;
            }
            i--;
            j++;
        }
        while(x>=0 and y>=0 )
        {
            if(board[x][y]==1)
            {
                return false;
            }
            x--;
            y--;
        }
        return true;
    }
    bool Nqueen(int board[][100],int i,int n)
    {
        if(i==n)
           {
             string s="";
               for(int i=0;i<n;i++)
               {
                   for(int j=0;j<n;j++)
                   {
                       if(board[i][j]==1)
                       {
                           s+='Q';
                       }
                       else
                       {
                           s+='.';
                       }

                   }
                   temp.push_back(s);
                   s.clear();
               }
            ans.push_back(temp);
            temp.clear();
            return false;
           }
        for(int j=0;j<n;j++)
        {
            if(isSafe(board,i,j,n))
            {
                board[i][j]=1;
                bool neecheKaKaam=Nqueen(board,i+1,n);
                if(neecheKaKaam)
                {
                    return true;
                }
                board[i][j]=0;
            }
        }
        return false;
    }
    vector<vector<string>> solveNQueens(int n) {
        int board[100][100]={0};
        Nqueen(board,0,n);
        return ans;
    }
};