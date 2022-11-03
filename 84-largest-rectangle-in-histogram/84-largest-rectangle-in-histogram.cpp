class Solution {
public:
    int largestRectangleArea(vector<int>& v) {
        int n=v.size();
        vector<int>left(n);
        vector<int>right(n);
        stack<int>s;
        for(int i=0;i<n;i++){
            while(s.size() && v[s.top()]>=v[i]){
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
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            while(st.size() && v[st.top()]>=v[i]){
                st.pop();
            }
            if(st.size()==0){
                right[i] = n-1;
            }
            else{
                right[i] = st.top()-1;
            }
            st.push(i);
        }
        int ans =0;
        for(int i=0;i<n;i++){
            ans = max(ans,(right[i]-left[i]+1)*v[i]);
        }
        return ans;
    }
};