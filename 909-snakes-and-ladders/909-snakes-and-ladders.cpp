class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        vector<int>v;
        int n=board.size();
        int count=0;
        v.push_back(0);
        for(int i=board.size()-1;i>=0;i--){
            // for(int j=0;j<n;j++){
            //     // v.push_back(board[i][j]);
            //     cout<<board[n-i-1][j]<<" ";
            // }
            if(count%2==1){
                reverse(board[i].begin(),board[i].end());
            }for(int j=0;j<n;j++){
                v.push_back(board[i][j]);
                // cout<<board[i][j]<<" ";
            }
            
            
            // cout<<endl;
            count++;
        
        }
        int visited[n*n+1];
        memset(visited,0,sizeof(visited));
        queue<int>q;
        q.push(1);
         count=0;
        // visited[1]=1;
        while(q.size()){
            
            int x = q.size();
            // cout<<endl;
            // cout<<endl;
            while(x--){
                // cout<<q.front()<<" ";
                auto it = q.front();
                q.pop();
                if(visited[it]==1){
                    continue;
                }
                visited[it]=1;
                // if(v[it]!=-1){
                //     it = v[it];
                //     visited[it]=1;
                // }
                if(it==((n*n))){
                    return count;
                }
                

                   for(int i=1;i<=6;i++){
                       if(((it+i)<=(n*n))){
                           if(v[it+i]!=-1){
                               q.push(v[it+i]);
                               
                           }
                           else{
                               q.push(it+i);
                           }
                       }
                   }

                
                
            }
            count++;
        }
        return -1;
    }
};