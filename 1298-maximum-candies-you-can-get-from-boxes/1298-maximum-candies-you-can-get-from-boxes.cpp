class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& init) {
        set<int>s;
        int n=status.size();
        for(int i=0;i<status.size();i++){
            if(status[i]){
                s.insert(i);
            }
        }
        queue<int>q;
        for(int i=0;i<init.size();i++){
            q.push(init[i]);
        }
        vector<int>visited(n);
        int ans=0;
        map<int,int>prev;
        while(q.size()){
            int x = q.front();
            q.pop();
            // cout<<x<<" ";
            if(visited[x]==1){
                continue;
            }
            if(s.count(x)){
                ans+=candies[x];
                candies[x]=0;
                visited[x]=1;
            }
            else{
                prev[x]=1;
                continue;
            }
            for(auto i:keys[x]){
                s.insert(i);
                if(prev[i]!=0){
                    q.push(i);
                    prev[i]=0;
                }
            }
            for(auto i:containedBoxes[x]){
                q.push(i);
            }
        }
        return ans;
    }
};