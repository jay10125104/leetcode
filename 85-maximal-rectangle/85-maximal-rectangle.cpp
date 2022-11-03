class Solution {
public:
    int answer(vector<int>&mid){
        int n=mid.size();
        vector<int>left(n);
        vector<int>right(n);
        stack<int>s;
        for(int i=0;i<n;i++){
            while(s.size() && mid[s.top()]>=mid[i]){
                s.pop();
            }
            if(s.size()==0){
                left[i] = 0;
            }
            else{
                left[i] = s.top()+1;
            }
            s.push(i);
        }
        while(s.size()){
            s.pop();
        }
        for(int i=n-1;i>=0;i--){
            while(s.size() && mid[s.top()]>=mid[i]){
                s.pop();
            }
            if(s.size()==0){
                right[i] = n-1;
            }
            else{
                right[i] = s.top()-1;
            }
            s.push(i);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans = max(ans,(right[i] - left[i]+1)*mid[i]);
        }
        return ans;
        
    }
    int maximalRectangle(vector<vector<char>>& v) {
        int n = v[0].size();
        vector<int>v1(n,0);
        int sol=0;
        for(int i=0;i<v.size();i++){
            for(int j=0;j<v[0].size();j++){
                if(v[i][j]=='1'){
                    v1[j]++;
                }
                else{
                    v1[j]=0;
                }
            }
            // cout<<answer(v1)<<endl;
            sol  = max(sol,answer(v1));
        }
        return sol;
    }
};