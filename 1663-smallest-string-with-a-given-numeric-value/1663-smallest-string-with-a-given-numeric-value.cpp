class Solution {
public:
    string getSmallestString(int n, int k) {
        string ans="";
        for(int i=0;i<n;i++){
            int rem = n-i-1;
            int capacity = (26*rem);
            k--;
            char x='a';
            // cout<<capacity<<" "<<k-capacity<<" "<<endl;
            if(capacity<k){
                int rem = k-capacity;
                x+=rem;
                k-=rem;
            }
            ans+=x;
        }
        // ans+=('a'+k-1);
        return ans;
    }
};