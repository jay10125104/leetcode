class Solution {
public:
    int closestCost(vector<int>& v, vector<int>& t, int target) {
        int n=v.size();
        int ans=INT_MAX;
        int diff = INT_MAX;
        for(auto it:v){
            int x = it;
            int a =pow(2,t.size());
            for(int i=0;i<a;i++){
                int mid1=0;
                int tt = i;
                int count=0;
                while(tt){
                    if(tt&1){
                        mid1+=t[count];
                    }
                    count++;
                    tt =tt/2;
                }
                for(int j=0;j<a;j++){
                 int mid2=0;
                    count=0;
                    tt = j;
                    while(tt){
                    if(tt&1){
                        mid2+=t[count];
                    }
                    count++;
                    tt =tt/2;
                }
                    int sol = x + mid2 + mid1;
                    int mid3 = abs(sol-target);
                    if(diff>mid3){
                        diff = mid3;
                        ans = sol;
                    }
                    else if(diff==mid3){
                        ans = min(ans,sol);
                    }
                    if(diff==0){
                        return target;
                    }
                    
                    
                }
            }
        }
        return ans;
        
    }
};