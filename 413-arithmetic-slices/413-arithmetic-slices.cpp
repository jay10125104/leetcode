class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& v){
       int ans=0;
        int count=0;
        int n=v.size();
        for(int i=2;i<n;i++){
            if((v[i]-v[i-1]) ==( v[i-1]-v[i-2])){
                count++;
            }
            else{
                count=0;
            }
            cout<<count<<endl;
            ans+=count;
        }
    return ans;
    }
    
    
};