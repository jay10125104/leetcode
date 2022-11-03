class Solution {
public:
    bool validateStackSequences(vector<int>& v, vector<int>& p) {
        stack<int>s;
        int i=0;
        int j=0;
        while(i<v.size()){
            while(s.size() && s.top()==p[j]){
                j++;
                s.pop();
            }
            s.push(v[i]);
            while(s.size() && s.top()==p[j]){
                j++;
                s.pop();
            }
            i++;
        }
        if(s.size()==0){
            return true; 
        }
        else{
            return false;
        }
    }
};