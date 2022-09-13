class Solution {
public:
    struct seg{
        // vector<int>v;
        vector<int>tree;
      seg(vector<int>&arr){
          vector<int>t(80001);
          tree=t;
        }    
        int query(int node,int start,int end,int l,int r){
            if(start>r || end<l){
                return 0;
            }
            if(start==end){
                return tree[node];
            }
            else if(start>=l && end<=r){
                return tree[node];
            }
            else{
                int mid = (start+end)/2;
                int x = query(node*2,start,mid,l,r);
                int y = query(node*2+1,mid+1,end,l,r);
                return x+y;
            }
        }
        void update(int node,int start,int end,int x){
            if(start==end){
                tree[node]++;
            }
            else{
                int mid = (start+end)/2;
                if(x<=mid){
                    update(node*2,start,mid,x);
                }
                else{
                    update(node*2+1,mid+1,end,x);
                }
                tree[node] = tree[node*2] + tree[node*2+1];
            }
        }
    };
    vector<int> countSmaller(vector<int>& nums) {
        seg se = seg(nums);
        int n=nums.size();
        vector<int>sol;
        for(int i=n-1;i>=0;i--){
            int x = nums[i];
            int lower = 0;
            int upper = 10000+nums[i];
                int ans = se.query(1,0,20000,0,upper-1);
            // cout<<upper<<" ";
                se.update(1,0,20000,upper);
            sol.push_back(ans);
            // cout<<ans<<" ";;
        }
        reverse(sol.begin(),sol.end());
        return sol;

    }
};