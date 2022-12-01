class Solution {
public:
    int ans,diff = INT_MAX;
    void sol(vector<int>&t,int target,int idx,int c){
            if(abs(c-target)==diff){
                ans = min(ans,c);
            }
            else if(abs(c-target)<diff){
                diff=abs(c-target);
                ans = c;
            }
        
        if(idx==t.size()){
            return;
        }
        sol(t,target,idx+1,c);
        sol(t,target,idx+1,c+t[idx]);
        
    }
    int closestCost(vector<int>& v, vector<int>& t, int target) {
        int n=t.size();
        for(int i=0;i<n;i++){
            t.push_back(t[i]);
        }
        for(auto &i:v){
            sol(t,target,0,i);
        }
        return ans;
    }
};