bool cmp(vector<int>&a,vector<int>&b){
    return a[1]<b[1];
}

class Solution {
public:
    int findMinimumTime(vector<vector<int>>& v) {
        // int time=0;
        vector<int>visited(2001);
        sort(v.begin(),v.end(),cmp);
        for(int i=0;i<v.size();i++){
            int x = v[i][2];
            for(int j=v[i][0];j<=v[i][1] && x;j++){
                // if(j>=v[i][0]){
                    x-=visited[j];
                    // x--;
                // }
            }
            for(int j=v[i][1];j>=v[i][0] && x;j--){
                if(visited[j]==0){
                    visited[j]=1;
                    x--;
                }
            }
            // time=max(time,v[i][1]);
        }
        int ans=0;
        for(int i=1;i<2001;i++){
            ans+=visited[i];
        }
        return ans;
    }
};