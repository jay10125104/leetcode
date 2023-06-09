class Solution {
public:
    void rotate(vector<vector<int>>& v) {
        int n=v.size();
        for(int i=n-1;i>=0;i--){
            for(int j=i;j<n;j++){
                swap(v[i][j],v[j][i]);
            }
        }
        for(auto &i:v){
            reverse(i.begin(),i.end());
        }
    }
};