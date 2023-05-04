class Solution {
public:
    string predictPartyVictory(string s) {
        int r=0;
        int d=0;
        queue<int>q1;
        queue<int>q2;
        for(int i=0;i<s.size();i++){
            if(s[i]=='D')
            q1.push(i);
            if(s[i]=='R')
            q2.push(i);
        }
        int n=s.size();
        while(q1.size()&&q2.size()){
            int x = q1.front();
            int y = q2.front();
            if(x<y){
                q2.pop();
                q1.pop();
                q1.push(n+x);
            }
            else{
                q1.pop();
                q2.pop();
                q2.push(n+y);
            }
        }
        if(q1.size()){
            return "Dire";
        }
        else{
            return "Radiant";
        }
        
    }
};