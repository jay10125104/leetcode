class Solution {
public:
    int xorAllNums(vector<int>& v, vector<int>& t) {
        int x =v.size();
        int y = t.size();
        // cout<<x<<" "<<y<<endl;
        if(x%2 ==0 && y%2==0){
            return 0;
        }
        else if(x%2==1 && y%2==1){
            int ans=0;
            for(auto i:v){
                ans = ans^i;
            }
            for(auto i:t){
                ans = ans^i;
            }
            return ans;
        }
        else if(x%2){
             int ans=0;
            for(auto i:t){
                ans = ans^i;
            }
            return ans;
        }
        else {
            int ans=0;
            for(auto i:v){
                ans = ans^i;
            }
            return ans;
        }
        return -1;
    }
};