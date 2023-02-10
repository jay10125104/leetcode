class Solution {    
public:
    int eraseOverlapIntervals(vector<vector<int>>& p) {
        vector<pair<int,int>>v;
        for(auto i:p){
            v.push_back({i[1],i[0]});
        }
        // cout<<"df";
        
        sort(v.begin(),v.end());
        int mx=INT_MIN;
        long long int count=0;
        for(int i=0;i<v.size();i++){
            if(mx<=v[i].second){
                mx = v[i].first;
            }
            else{
                count++;
            }
        }
        return count;
    }
};