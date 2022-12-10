class Solution {
public:
    bool ans(vector<int>&v,long long int k){
        int prev=0;
        int n=v.size();
        vector<int>visited(v.size());
        int i=1;
        while(i<n){
            
            if((v[i]-v[prev])>k){
                if((prev+1)==i){
                    return false;
                }
                else{
                    prev=i-1;
                    visited[i-1]=1;
                }
                
            }
            else
            i++;
            // cout<<v[i]-v[prev]<<" "<<prev<<" "<<i<<" "<<k<<endl;
            
        }
        if((v[n-1]-v[prev])>k){
            return false;
        }

        prev=n-1;
        i=n-2;
        while(i>=0){
            if(visited[i]){
                i--;
                continue;
            }
            if((v[prev]-v[i])>k){
                    int t=i+1;
                    while(visited[t]==1 && t<=(n-1)){
                        t++;
                    }
                if(t==prev){
                    return false;
                }
                else{
                    prev = t;
                }
                }
else{
            i--;
        }
            }
        
        if(v[prev]-v[0]>k){
                return false;
            }
        return true;
    }
    int maxJump(vector<int>& v) {
        int low=0;
        long long int high=INT_MAX;
        long long int sol=0;
        // cout<<ans(v,13);
        while(low<=high){
            long long int mid = (high+low)/2;
            if(ans(v,mid)){
                // cout<<mid<<" ";
                sol = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return sol;
    }
};