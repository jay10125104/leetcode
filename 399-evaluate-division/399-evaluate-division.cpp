class Solution {
public:
    void dfs(map<string,vector<pair<string,double>>>&m,string first,string second,map<string,int>&visited,int &flag,double &ans,double &mid){
        visited[first] = 1;
        // cout<<first<<" "<<second;
        if(first==second){
            mid = ans;
            flag=1;
            return ;
        }
        // cout<<ans<<" ";
        for(auto i:m[first]){
            if(visited.find(i.first)==visited.end()){
                ans*=i.second;
                dfs(m,i.first,second,visited,flag,ans,mid);
                ans/=i.second;
            }
        }
    }
    vector<double> calcEquation(vector<vector<string>>& e, vector<double>& v, vector<vector<string>>& q) {
        map<string,vector<pair<string,double>>>m;
        for(int i=0;i<e.size();i++){
            m[e[i][0]].push_back({e[i][1],v[i]});
            m[e[i][1]].push_back({e[i][0],1/v[i]});
        }
        
        vector<double>sol;
        for(auto i:q){
            // cout<<"fd";
            string first = i[0];
            string second = i[1];
            double ans=1;
            if(m.find(first)!=m.end()){
                map<string,int>visited;
                int flag=0;
                double mid;
                dfs(m,first,second,visited,flag,ans,mid);
                // cout<<mid<<" ";
                if(flag==1){
                sol.push_back(mid);
                }
                else{
                    sol.push_back(-1);
                }
            }
            else{
                sol.push_back(-1);
            }
            
        }
        return sol;
    }
};