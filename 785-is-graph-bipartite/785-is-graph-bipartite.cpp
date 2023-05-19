class Solution {
public:
    int ans(vector<vector<int>>graph,vector<int>&color,int src){
        int x = color[src];
        for(auto i:graph[src]){
            if(color[i]==-1){
                color[i]=!x;
                if(ans(graph,color,i)==1){
                    return 1;
                }
            }
            else{
                if(color[i]==color[src]){
                    return 1;
                }
            }
        }
        return 0;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>color(n,-1);
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                if(ans(graph,color,i)==1){
                    return false;
                }
            }
        }
        return true;
        }
};