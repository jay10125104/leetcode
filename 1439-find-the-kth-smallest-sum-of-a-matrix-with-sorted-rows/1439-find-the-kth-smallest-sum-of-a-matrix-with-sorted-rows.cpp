class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        vector<int>temp = mat[0];
        for(int i=1;i<mat.size();i++){
            priority_queue<int>q;
            for(int j=0;j<mat[0].size();j++){
                for(auto &k:temp){
                    q.push((k+mat[i][j])*(-1));
                }
            }
            temp.clear();
            int mx = min((int)q.size(),k);
            while(mx--){
                temp.push_back(-1*(q.top()));
                q.pop();
            }
            // temp=mid;/
        }
        return temp[k-1];
    }
};