class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        long long int x=num1;
        long long int y = num2;
        for(int i=1;i<=60;i++){
            long long int mid = x;
            mid-=(y*1ll*i);
            int count=0;
            long long int t=mid;
            while(t){
                count+=(t&1);
                t/=2;
            }
            long long int mn=count;
            long long int mx = mid;
            // cout<<i<<" "<<mn<<" "<<mx<<" "<<mid<<endl;
            if(mid<0){
                continue;
            }
            if(i>=mn && i<=mx){
                return i;
            }
        }
        return -1;
    }
};