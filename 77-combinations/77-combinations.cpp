class Solution {
public:
    vector<vector<int>>ans;
    void ans1(vector<int>&mid,int idx,int n,int k){
        if(k==0){
            ans.push_back(mid);
            return;
        }
        else if(idx>(n)){
            return;
        }
        ans1(mid,idx+1,n,k);
        mid.push_back(idx);
        ans1(mid,idx+1,n,k-1);
        mid.pop_back();
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int>mid;
        ans1(mid,1,n,k);
        return ans;
    }
};