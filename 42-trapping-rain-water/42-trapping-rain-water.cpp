class Solution {
public:
    int trap(vector<int>& v) {
        int n=v.size();
        int ans=0;
        stack<int>s;
        for(int i=0;i<n;i++){
            while(s.size() && v[s.top()]<=v[i]){
                int t = s.top();
                s.pop();
                if(s.size()){
                    int x = v[s.top()];
                    int height = min(x,v[i]);
                    int dis = i - s.top()-1;
                    ans+=(height*dis - (dis*v[t]));
                }
            }
            // cout<<ans<<endl;
            s.push(i);
        }
    
    return ans;
    }
};