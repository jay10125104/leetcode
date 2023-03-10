class Solution {
public:
    vector<int> pathInZigZagTree(int x) {
        int times=log2(x)+1;
        // cout<<times;
        // times++;
        int idx=-1;
        // cout<<times;
        vector<vector<int>>v;
        int it=0;
        int counter=1;
        while(it<times){
            vector<int>mid;
            for(int i=0;i<pow(2,it);i++){
                if(counter==x){
                    if(it%2==0)
                    idx=i;
                    else
                    idx=pow(2,it)-i-1;
                }
                mid.push_back(counter++);
            }
            if(it%2){
                reverse(mid.begin(),mid.end());
            }
            v.push_back(mid);
            // cout<<endl;
            it++;
        
        }
        // cout<<idx<<" ";
        vector<int>ans;
        while(times--){
            ans.push_back(v[times][idx]);
            idx=idx/2;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};