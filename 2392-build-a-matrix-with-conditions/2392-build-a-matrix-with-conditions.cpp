class Solution {
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& v, vector<vector<int>>& t) {
        vector<int>adj1[k+1];
        vector<int>adj2[k+1];
        vector<int>indegree1(k+1);
        vector<int>indegree2(k+1);
        for(int i=0;i<v.size();i++){
            adj1[v[i][0]].push_back(v[i][1]);
            indegree1[v[i][1]]++;
        }
        for(int i=0;i<t.size();i++){
            adj2[t[i][0]].push_back(t[i][1]);
            indegree2[t[i][1]]++;
        }
        queue<int>q1;
        queue<int>q2;
        for(int i=1;i<=k;i++){
            if(indegree1[i]==0){
                q1.push(i);
            }
        }
        for(int i=1;i<=k;i++){
            if(indegree2[i]==0){
                q2.push(i);
            }
        }
        int count1=0;
        vector<vector<int>>sol(k,vector<int>(k,0));
        int count2=0;
        map<int,int>m1;
        int idx=0;
        int idx2=0;
        while(q1.size()){
            int x = q1.front();
            q1.pop();
            m1[x]=idx++;
            count1++;
            for(auto i:adj1[x]){
                indegree1[i]--;
                if(indegree1[i]==0){
                    q1.push(i);
                }
            }
        }
        vector<vector<int>>dummy;
        
        if(count1!=k){
            cout<<-1<<endl;
            return dummy;
        }
        while(q2.size()){
            int x = q2.front();
            q2.pop();
            sol[m1[x]][idx2++]=x;
            count2++;
            for(auto i:adj2[x]){
                indegree2[i]--;
                if(indegree2[i]==0){
                    q2.push(i);
                }
            }
        }
        if(count2!=k){
            return dummy;
        }
        else{
            return sol;
        }
    }
};