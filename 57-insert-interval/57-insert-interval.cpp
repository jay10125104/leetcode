class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& v, vector<int>& t) {
        int idx=v.size();
        int mn=t[0];
        int mx = t[1];
        int n=v.size();
        vector<int>visited(n);
        for(int i=0;i<v.size();i++){
            if(v[i][0]>mx){
                idx=i;
                break;
            }
            else if((mn>=v[i][0] && mn<=v[i][1]) || (mx>=v[i][0] && mx<=v[i][1]) || (v[i][0]>=mn && v[i][1]<=mx)){
                mn = min(mn,v[i][0]);
                mx = max(mx,v[i][1]);
                visited[i]=1;
            }
        // cout<<idx<<" "<<mx<<" "<<mn<<endl;
            
        }
        vector<vector<int>>ans;
        int c=1;
        if(n==0){
                ans.push_back({mn,mx});
            return ans;
        }
        if(mx<v[0][0]){
                ans.push_back({mn,mx});
            c=0;
            }
        for(int i=0;i<v.size();i++){
            if(c && mx<v[i][0]){
                c=0;
                ans.push_back({mn,mx});
            }
            if(visited[i]==1){

            }
            else{
                ans.push_back({v[i][0],v[i][1]});
            }
        }
        if(c){
            ans.push_back({mn,mx});
            
        }
        return ans;
    }
};