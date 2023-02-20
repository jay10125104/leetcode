class Solution {
public:
    vector<int>ans;
    int mx=INT_MAX;
    int dp[61][1<<16];
    void sol(int n,vector<int>&req,vector<int>&people,int idx,int mask,vector<int>&v){
        if(idx==n){
            if(v.size()<mx){
                mx = v.size();
                ans =v;
            }
            return;
        }
        if(mask&(1<<idx)){
            sol(n,req,people,idx+1,mask,v);
        }
        else{
        for(int i=0;i<people.size();i++){
            if(people[i]&(1<<idx)){
                v.push_back(i);
                sol(n,req,people,idx+1,mask|people[i],v);
                v.pop_back();
                }
            }
        }
        // dp[idx][mask]=1;
    }
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        map<string,int>m;
        int count=0;
        vector<int>req;
        for(auto &i:req_skills){
            m[i]=count;
            req.push_back(count);
            count++;
        }
        vector<int>workers;
        for(auto &i:people){
            int mask = 0;
            for(auto &j:i){
                mask|=(1<<m[j]);
            }
            workers.push_back(mask);
        }
        vector<int>v;
        memset(dp,-1,sizeof(dp));
        sol(count,req,workers,0,0,v);
        return ans;
        
    }
};