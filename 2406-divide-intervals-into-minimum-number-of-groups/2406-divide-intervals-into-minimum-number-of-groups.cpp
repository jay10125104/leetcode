class Solution {
public:
    int minGroups(vector<vector<int>>& pt) {
        vector<pair<int,int>>v;
        for(auto i:pt){
            v.push_back({i[0],i[1]});
        }
        // int count=0;
        sort(v.begin(),v.end());
           priority_queue<int, vector<int>, greater<int> >p;
        p.push(v[0].second);
        int count=1;
        for(int i=1;i<v.size();i++){
            int x = p.top();
            if(x<v[i].first){
                p.pop();
                p.push(v[i].second);
            }
            else{
                p.push(v[i].second);
            }
        }
        return p.size();
    }
};