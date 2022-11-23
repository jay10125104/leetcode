class Solution {
public:
    int openLock(vector<string>& v, string target) {
        map<string,int>m;
        for(auto &i:v){
            m[i]++;
        }
        queue<string>q;
        q.push("0000");
        int level=0;
        map<string,int>m1;
        while(q.size()){
            int x = q.size();
            // cout<<x<<" ";
            while(x--){
                string s = q.front();
                q.pop();
                if(m[s]){
                    continue;
                }
                if(s==target){
                    return level;
                }
                m1[s]=1;
                // cout<<s<<" ";
                for(int i=0;i<s.size();i++){
                    if(s[i]=='9'){
                         string t=s;
                        t[i]='0';
                        if(m1[t]==0){
                        q.push(t);
                        m1[t]=1;
                        }
                        t=s;
                        t[i]='8';
                        if(m1[t]==0){
                        q.push(t);
                        m1[t]=1;
                        }
                    }
                    else if(s[i]=='0'){
                        string t=s;
                        t[i]='9';
                        if(m1[t]==0){
                        q.push(t);
                        m1[t]=1;
                        }
                        t=s;
                        t[i]='1';
                        if(m1[t]==0){
                        q.push(t);
                        m1[t]=1;
                        }
                    }
                    else{
                        string t=s;
                        t[i]-=1;
                        if(m1[t]==0){
                        q.push(t);
                        m1[t]=1;
                        }
                        t=s;
                        t[i]+=1;
                        // cout<<t<<" ";
                        if(m1[t]==0){
                        q.push(t);
                        m1[t]=1;
                        }
                    }
                }
                
            }
            level++;
        }
        return -1;
    }
};