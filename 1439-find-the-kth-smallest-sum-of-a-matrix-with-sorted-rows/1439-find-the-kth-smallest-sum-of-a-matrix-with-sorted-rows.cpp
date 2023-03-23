class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        vector<int>temp = mat[0];
        for(int i=1;i<mat.size();i++){
            vector<int>mid;
            for(int j=0;j<mat[0].size();j++){
                for(auto &k:temp){
                    mid.push_back(k+mat[i][j]);
                }
            }
            sort(mid.begin(),mid.end());
            temp.clear();
            for(int j=0;j<min(k,(int)mid.size());j++){
                temp.push_back(mid[j]);
            }
            // temp=mid;/
        }
        return temp[k-1];
    }
};