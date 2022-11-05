bool cmp(pair<int,int>&a,pair<int,int>&b){
    if(a.first==b.first){
        return a.second>b.second;
    }
    else{
        return a.first<b.first;
    }
}
class Solution {

public:
    int numberOfWeakCharacters(vector<vector<int>>& p) {
        vector<pair<int,int>>v;
        for(auto &i:p){
            v.push_back({i[0],i[1]});
        }
        int n=p.size();
        sort(v.begin(),v.end(),cmp);
        stack<pair<int,int>>s;
        int ans=0;
        for(int i=0;i<n;i++){
            // cout<<v[i].first<<" "<<v[i].second<<endl; 
            while(s.size() && s.top().first<v[i].first && v[i].second>s.top().second){
                s.pop();
                ans++;
            }
            
            s.push(v[i]);
        }
        return ans;
    }
};