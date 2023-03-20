class Solution {
public:
    int minPartitions(string n) {
        int mx=0;
        for(auto &i:n){
            mx=max(mx,i-'0');
        }
        return mx;
    }
};