class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& v) {
        vector<int>bit(32);
        vector<int>ans;
        int n=v.size();
        int j=n-1;
        int i = n-1;
        while(i>=0){
            int x = v[i];
            int counter=0;
            while(x){
                if(x&1){
                    bit[counter]++;
                }
                x = x/2;
                counter++;
            }
            
            // counter=0;
            while(j>i){
                int mid = v[j];
                int flag=0;
                counter=0;
                vector<int>sub(32);
                while(mid){
                    if(mid&1){
                        if(bit[counter]==1){
                            flag=1;
                            break;
                        }
                    }
                    counter++;
                    mid = mid/2;
                }
                if(flag==1){
                        break;
                }
                else{
                     mid = v[j];
                // int flag=0;
                counter=0;
                vector<int>sub(32);
                while(mid){
                    if(mid&1){
                       bit[counter]--;
                    }
                    counter++;
                    mid = mid/2;
                }
                }
                j--;
            }
            // for(auto i:bit){
            //     cout<<i<<" ";
            // }
            // cout<<i<<" "<<j<<endl;
            ans.push_back(abs(i-j)+1);
            i--;
            
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};