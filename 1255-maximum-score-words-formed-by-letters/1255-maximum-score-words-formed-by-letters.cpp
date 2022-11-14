class Solution {
public:
    map<pair<int,vector<int>>,int>dp;
    int ans(int idx,vector<string>&words,vector<int>v,vector<int>&score){
        if(idx==words.size()){
            return 0;
        }
        else if(dp.find({idx,v})!=dp.end()){
            return dp[{idx,v}];
        }
        int pick = INT_MIN;
        int npick = ans(idx+1,words,v,score);
        vector<int>visited(26,0);
        int flag=0;
        for(auto &i:words[idx]){
            visited[i-'a']++;
            if(visited[i-'a']>v[i-'a']){
                flag=1;
                break;
            }
        }
        if(flag==0){
            int mid =0 ;
            vector<int>vi =v;
            for(int i=0;i<26;i++){
                mid+=(visited[i]*score[i]);
                vi[i]-=visited[i];
                
            }
            pick = mid + ans(idx+1,words,vi,score);
        }
        return max(pick,npick);
    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int>v(26,0);
        for(auto &i:letters){
            v[i-'a']++;
        }
        return ans(0,words,v,score);
    }
};