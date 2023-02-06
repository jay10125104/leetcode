class Solution {
public:
    int longestBeautifulSubstring(string s) {
        vector<int>req(5);
        for(int i=0;i<s.size();i++){
            if(s[i]=='e'){
                s[i]='b';
            }
            else if(s[i]=='i'){
                s[i]='c';
            }
            else if(s[i]=='o'){
                s[i]='d';
            }
            else if(s[i]=='u'){
                s[i]='e';
            }
        }
        int ans=0;
        int j=0;
        int count=0;
        for(int i=0;i<s.size();i++){
            int x = s[i]-'a';
            if(j==x){
                count++;
            }
            else if(count && (j+1)==x){
                j++;
                count++;
            }
            else{
                j=0;
                count=0;
                if(x==0){
                    count=1;
                }
            }
            // cout<<count<<" "<<j<<endl;
            if(j==4){
                ans=max(ans,count);
            }
        }
        return ans;
    }
};