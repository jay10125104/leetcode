class Solution {
public:
    double dp[26][26][101];
    double ans(int n,int k,int row,int col){
        if(row<0 || col<0 || row>=n || col>=n){
            return 0;
        } 
        else if(k==0){
            return 1.0;
        }
        else if(dp[row][col][k]!=0){
            return dp[row][col][k];
        }
        else{
            double mid = ans(n,k-1,row-2,col-1)+ans(n,k-1,row-2,col+1)+ans(n,k-1,row-1,col+2)+ans(n,k-1,row+1,col+2)+ans(n,k-1,row+2,col-1)+ans(n,k-1,row+2,col+1)+ans(n,k-1,row+1,col-2)+ans(n,k-1,row-1,col-2);
            return dp[row][col][k] = (double)(mid)/8.0;
        }
    }
    double knightProbability(int n, int k, int row, int column) {
        memset(dp,0,sizeof(dp));
        return ans(n,k,row,column);
    }
};