class Solution {
public:
    int ans(vector<long long int>v,long long int r,long long int k,long long int mid){
        long long int n=v.size();
        long long int sum1=0;
        long long int one=0;
        int two=0;
        int id=min(n-1,r);
        for(int i=0;i<n;i++){
            while((one-i)<=r && one<n){
                sum1+=v[one];
                one++;
            }
            while((i-two)>r && two<n){
                sum1-=v[two];
                two++;
            }
            // cout<<one<<" "<<two<<" ";
            
            // cout<<sum1<<endl;
            if(sum1>mid){
                continue;
            }
            long long int req = mid-sum1;
            if(req>k){
                return false;
            }
            k-=req;
            v[min(i+r,n-1)]+=req;
            sum1+=req;
        }
        return true;
    }
    long long maxPower(vector<int>& v, int r, int k) {
        long long int low =0;
        long long int high = 1e15;
        int n=v.size();
        long long int sol=0;
        vector<long long int>vi;
        for(auto &i:v){
            vi.push_back(i);
        }
        while(low<=high){
            long long int mid = (low+high)/2;
            if(ans(vi,(long long int)r,(long long int)k,mid)){
                low = mid+1;
                sol = mid;
            }
            else{
                high = mid-1;
            }
            // cout<<endl;
        }
        return sol;
    }
};