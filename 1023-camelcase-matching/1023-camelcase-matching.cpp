class Solution {
public:
    vector<bool> camelMatch(vector<string>& q, string s) {
        vector<bool>ans;
        for(int i=0;i<q.size();i++){
            int idx1=0;
            int idx2=0;
            int flag=1;
            while(idx1<q[i].size() && idx2<s.size()){
                if(q[i][idx1]==s[idx2]){
                    idx1++;
                    idx2++;
                }
                else if(q[i][idx1]>='A' && q[i][idx1]<='Z'){
                    flag=0;
                    break;
                }
                else{
                    idx1++;
                }
            }
            while(idx1<q[i].size()){
                 if(q[i][idx1]>='A' && q[i][idx1]<='Z'){
                    flag=0;
                    break;
                }
                idx1++;
            }
            // cout<<idx1<<" "<<idx2<<" "<<flag<<" "<<endl;
            if(flag==1 && idx2==s.size()){
                ans.push_back(true);
            }
            else{
                ans.push_back(false);
            }
        }
        return ans;
    }
};