class Solution {
public:
    unordered_map<int,int>m;
    long long int visited[51][2];
    int counter(vector<int>adj[],int src,int parent,int &flag,int des){
        if(src==des){
            m[src]++;
            flag=0;
        }
        if(flag)
        m[src]++;
        for(auto &it:adj[src]){
            if(it!=parent){
                int x=counter(adj,it,src,flag,des);
            }
        }
        if(flag){
            m[src]--;
        }
        return -1;
    }
    long long int solution(vector<int>adj[],int src,int parent,vector<int>&prices,int available){
        long long int score1=m[src]*prices[src];
        if(visited[src][available]!=-1){
            return visited[src][available];
        }
        for(auto &i:adj[src]){
            if(i!=parent){
               score1+=min(solution(adj,i,src,prices,1),solution(adj,i,src,prices,0));
            }
        }
        if(available==1){
        	long long int score2=m[src]*(prices[src]/2);
            for(auto &i:adj[src]){
                if(i!=parent){
                   score2+=solution(adj,i,src,prices,0);
                }
            }
			return visited[src][available]=min(score1,score2);
        }
        return score1;
    }
    int minimumTotalPrice(int n, vector<vector<int>>& ti, vector<int>& prices, vector<vector<int>>& v) {
        vector<int>adj[n];
        memset(visited,-1,sizeof(visited));
        for(auto &i:ti){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        int k=1;
        for(auto &i:v){
            k=1;
            counter(adj,i[0],-100,k,i[1]);
        } 
        return solution(adj,0,-1,prices,1);
    }
};