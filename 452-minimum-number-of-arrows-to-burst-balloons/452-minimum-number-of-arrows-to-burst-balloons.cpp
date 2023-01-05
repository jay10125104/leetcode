class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        vector<pair<int,int>>v;
        for(auto &i:points){
            v.push_back({i[0],i[1]});
        }
        sort(v.begin(),v.end());
        int mx = v[0].second;
        int mn = v[0].first;
        int count=1;
        for(int i=1;i<v.size();i++){
            // cout<<v[i].first<<" "<<v[i].second<<" "<<mx<<" "<<mn<<endl; 
            if(v[i].first>mx){
                mn = v[i].first;
                mx = v[i].second;
                count++;
            }
            else{
                mn = max(v[i].first,mn);
                mx = min(mx,v[i].second);
            }
            
        }
        return count;
    }
};