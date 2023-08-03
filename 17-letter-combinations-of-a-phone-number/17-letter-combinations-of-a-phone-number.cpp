class Solution {
public:
    vector<string>ans(string s,vector<string>&ref){
        if(s.size()==0){
            return {};
        }
        if(s.size()==1){
            vector<string>temp;
            int x = s[0]-'0';
            for(auto i:ref[x]){
                char x=i;
                // cout<<x<<" ";
                string t = "";
                t = t + x;
                temp.push_back(t);
            }
            return temp;
        }
        int x = s[0]-'0';
        string mid = s.substr(1);
        vector<string>dup = ans(mid,ref);
        vector<string>sol;
        for(auto i:dup){
            for(auto j:ref[x]){
             sol.push_back(j+i);
            }
        }
        return sol;
    }
    vector<string> letterCombinations(string s) {
        vector<string>ref;
        ref.push_back(" ");
        ref.push_back(" ");
        ref.push_back("abc");
        ref.push_back("def");
        ref.push_back("ghi");
        ref.push_back("jkl");
        ref.push_back("mno");
        ref.push_back("pqrs");
        ref.push_back("tuv");
        ref.push_back("wxyz");
        
        return ans(s,ref);
    }
};