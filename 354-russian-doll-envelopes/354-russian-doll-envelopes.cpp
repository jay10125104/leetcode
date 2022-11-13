bool cmp(pair<int,int>&a,pair<int,int>&b){
    if(a.first==b.first){
        return a.second>b.second;
    }
    return a.first<b.first;
}
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& v) {
        int n=v.size();
        vector<pair<int,int>>p;
        for(auto i:v){
            p.push_back({i[0],i[1]});
        }
        sort(p.begin(),p.end(),cmp);
        vector<int>ans;
        ans.push_back(p[0].second);
        for(int i=1;i<v.size();i++){
            int low = 0;
            int high = ans.size()-1;
            int sol = -1;
            while(low<=high){
                int mid = (high+low)/2;
                if(ans[mid]>=p[i].second){
                    sol = mid;
                    high = mid-1;
                }
                else{
                    low = mid+1;
                }
            }
            if(sol==-1){
                ans.push_back(p[i].second);
            }
            else{
                ans[sol] = p[i].second;
            }
        }
        return ans.size();
        
    }
};