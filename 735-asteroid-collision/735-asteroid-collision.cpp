class Solution {
public:
    vector<int> asteroidCollision(vector<int>& v) {
        stack<int>s;
        for(int i=0;i<v.size();i++){
            if(s.size() && s.top()>0 && v[i]<0){
                    int x = s.top();
                    int m = abs(v[i]);
                    while(s.size() && m){
                        int t = s.top();
                        if(t<0){
                            s.push(-m);
                            break;
                        }
                        if(m>abs(t)){
                            s.pop();
                        }
                        else if(m==t){
                            s.pop();
                            m=0;
                            break;
                        }
                        else{
                            break;
                        }
                    }
                    if(s.size()==0 && m){
                        s.push(-m);
                    }
                
            }
                else{
                    s.push(v[i]);
                }
            if(s.size())
            cout<<s.top()<<" "<<s.size()<<" ";
        }
        vector<int>ans;
        while(s.size()){
            ans.push_back(s.top());
            s.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};