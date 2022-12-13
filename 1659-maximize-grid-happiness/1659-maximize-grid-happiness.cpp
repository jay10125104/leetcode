class Solution
{
public:
    int dp[6][1<<6][1<<6][7][7];
    int ans(int m, int n, int idx, int mask1, int mask2, int intro, int extro)
    {
        // if((intro+extro)==0)
        if (intro < 0 || extro < 0)
        {
            return INT_MIN;
        }
        else if (idx == m)
        {
            return 0;
        }
        else if(dp[idx][mask1][mask2][intro][extro]!=-1){
            return dp[idx][mask1][mask2][intro][extro];
        }
        else
        {
            int mn = 0;
            //i->intro
            //j->extro
            //mask1->intro
            //mask2->extro
            for (int i = 0; i < (1 << n); i++)
            {
                for (int j = 0; j < (1 << n); j++)
                {
                    
                    if ((j & i) == 0)
                    {
                        int t1 = __builtin_popcount(i);
                        int t2 = __builtin_popcount(j);
                        int mid=0;
                        mid+=(t1*120);
                        mid+=(t2*40);
                        for(int k=0;k<n;k++){
                            if((i&(1<<k))&&(mask1&(1<<k))){
                                mid-=(2*30);
                            }
                            if((i&(1<<k))&&(mask2&(1<<k))){
                                mid-=(10);
                            }
                          if(k>=1){
                            if((i&(1<<k))&&(i&(1<<(k-1)))){
                                mid-=(2*30);
                            }
                            if((i&(1<<k))&&(j&(1<<(k-1)))){
                                mid-=10;
                            }
                          }
                        }
                        for(int k=0;k<n;k++){
                            if((j&(1<<k))&&(mask1&(1<<k))){
                                mid-=(10);
                            }
                            if((j&(1<<k))&&(mask2&(1<<k))){
                                mid+=(2*20);
                            }
                          if(k>=1){
                            if((j&(1<<k))&&(i&(1<<(k-1)))){
                                mid-=(10);
                            }
                            if((j&(1<<k))&&(j&(1<<(k-1)))){
                                mid+=40;
                            }
                          }
                        }
            // cout<<idx<<" "<<i<<" "<<j<<" "<<intro-t1<<" "<<extro-t2<<" "<<mid<<endl;
                        
                        mn = max(mn,mid+ans(m,n,idx+1,i,j,intro-t1,extro-t2));
                    }
                }
            }
            
            return dp[idx][mask1][mask2][intro][extro] = mn;
        }
    }
    int getMaxGridHappiness(int m, int n, int i, int j)
    {
        memset(dp, -1, sizeof(dp));
        return ans(m, n, 0, 0, 0, i, j);
    }
};