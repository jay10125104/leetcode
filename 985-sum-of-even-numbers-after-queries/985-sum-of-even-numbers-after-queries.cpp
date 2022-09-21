class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& v, vector<vector<int>>& q) {
        vector<int>ans;
        int sum=0;
        for(auto i:v){
            if(i%2==0)
            sum+=i;
        }
        for(auto i:q){
            // sum=v[i[1]];
            v[i[1]]+=i[0];
            if(v[i[1]]%2==0){
                sum+=v[i[1]];
            }
            if((v[i[1]]-i[0])%2==0){
                sum-=(v[i[1]]-i[0]);
            }
            ans.push_back(sum);
        }
        return ans;
    }
};