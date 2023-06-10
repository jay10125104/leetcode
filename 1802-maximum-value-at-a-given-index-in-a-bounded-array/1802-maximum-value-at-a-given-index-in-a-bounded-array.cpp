class Solution {
public:
    bool sol(int mid,int x,int n,int idx){
        long long int ans=mid;
        long long int i=idx-1;
        long long int m=mid-1;
        while(i>=0){
            ans+=m;
            m--;
            m=max(m,1ll);
            i--;
        }
        i=idx+1;
        m=mid-1;
        while(i<n){
            ans+=m;
            m--;
            m=max(m,1ll);
            i++;
        }
        return ans<=x;
    }
    int maxValue(int n, int index, int maxSum) {
        long long int low=1;
        long long int high=maxSum;
        long long int ans=-1;
        long long int leftrem = index+1;
        long long int rightrem = n-index;
        while(low<=high){
            long long int mid=(low+high)/2;
            long long int leftsum = (mid*(mid+1))/2;
            if(leftrem>=mid){
                leftsum+=(leftrem-mid);
            }
            else{
                long long int rem = mid-leftrem;
                leftsum-=((rem*(rem+1))/2);
            }
            long long int rightsum = (mid*(mid+1))/2;
            if(rightrem>=mid){
                rightsum+=(rightrem-mid);
            }
            else{
                long long int rem = mid-rightrem;
                rightsum-=((rem*(rem+1))/2);
            }
            long long int total = leftsum+rightsum-mid;
            if(total<=maxSum){
                low=mid+1;
                ans=mid;
            }
            else{
                high=mid-1;
            }
        }
        return ans;
    }
};