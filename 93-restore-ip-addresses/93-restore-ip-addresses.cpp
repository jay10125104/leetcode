class Solution {
public:
    int mid(string &s){
        long long int x = stoll(s);
        if(s[0]=='0' && x!=0){
            return 1;
        }
        else if(x>=256){
            return 1;
        }
        return 0;
    }
    vector<string> restoreIpAddresses(string s) {
        int n=s.size();
        string one = "";
        vector<string>ans;
        for(int i=0;i<n;i++){
            one+=s[i];
            string two="";
            for(int j=i+1;j<n;j++){
                two+=s[j];
                string three="";
                for(int k=j+1;k<n;k++){
                    three+=s[k];
                    string four="";
                    for(int t=k+1;t<n;t++){
                        four+=s[t];
                    }
                    int flag=1;
                    if(!one.size() || !two.size() || !three.size() || !four.size()){
                        continue;
                    }
                    
                    long long int x = stoll(one);
                    long long int y = stoll(two);
                    long long int z = stoll(three);
                    long long int o = stoll(four);
                    if(mid(one)||mid(two)||mid(three)||mid(four)){
                        continue;
                    }
                    else{
                        if(x==0){
                            one="0";
                        }
                        if(y==0){
                            two="0";
                        }
                        if(z==0){
                            three="0";
                        }
                        if(o==0){
                            four="0";
                        }
                        string hi = one;
                        hi+='.';
                        hi+=two;
                        hi+='.';
                        hi+=three;
                        hi+='.';
                        hi+=four;
                        if(hi.size()==(n+3))
                        ans.push_back(hi);
                    }
                }
            }
        }
        return ans;
    }
};