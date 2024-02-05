class Solution {
public:
    vector<vector<int>> resultGrid(vector<vector<int>>& v, int t) {
        int m=v.size();
        int n=v[0].size();
        int mp[m][n];
        int cnt[m][n];
        memset(mp,0,sizeof(mp));
        memset(cnt,0,sizeof(cnt));
        // map<pair<int,int>,int>mp;
        // map<pair<int,int>,int>cnt;
        vector<vector<int>>dir={{0,-1},{-1,0},{1,0},{0,1}};
        for(int i=1;i<m-1;i++){
            for(int j=1;j<n-1;j++){
                int count=0;
                int sum=0;
                for(int p=i-1;p<=(i+1);p++){
                    for(int q=j-1;q<=(j+1);q++){
                        int ans=0;
                        for(auto &k:dir){
                            int x=p+k[0];
                            int y=q+k[1];
                            if(x<(i-1)||y<(j-1)||x>(i+1)||y>(j+1)){
                                ans++;
                            }
                            else{
                                ans+=(abs(v[x][y]-v[p][q])<=t);
                            }
                        }
                        count+=(ans==4);
                        sum+=v[p][q];
                    }
                }
                if(count==9){
                    for(int p=i-1;p<=(i+1);p++){
                        for(int q=j-1;q<=(j+1);q++){
                            mp[p][q]+=sum/9;
                            cnt[p][q]++;
                        }
                    }
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(cnt[i][j]!=0){
                    // cout<<mp[{i,j}]<<" "<<cnt[{i,j}]<<endl;
                    v[i][j]=mp[i][j]/cnt[i][j];
                }
                else{
                    
                }
            }
        }
        return v;
    }
};