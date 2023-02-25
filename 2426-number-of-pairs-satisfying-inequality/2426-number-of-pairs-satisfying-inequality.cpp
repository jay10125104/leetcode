class Solution {
public:
    long long int solution=0;
    vector<int> ans(vector<int>&v,int start,int end,int diff){
        if(start==end){
            vector<int>t;
            t.push_back(v[start]);
            return t;
        }
        else{
            // cout<<start<<" "<<end<<endl;
            int mid=(start+end)/2;
            vector<int> left = ans(v,start,mid,diff);
            vector<int>right = ans(v,mid+1,end,diff);
            // solution+=(left+right);
            int count=0;
            for(int i=0;i<right.size();i++){
                int low = 0;
                int high = left.size()-1;
                int sol=0;
                int req = right[i]+diff;
                while(low<=high){
                    int middle = (low+high)/2;
                   
                    if(left[middle]<=req){
                        sol = middle+1;
                        low = middle+1;
                    }
                    else{
                        high = middle-1;
                    }
                }
                
                
                solution+=sol;
            // cout<<start<<" "<<end<<" "<<sol<<" "<<solution<<endl;
                // cout<<i<<" "<<
                // cout<<i<<" ";
            }
            for(int i=0;i<right.size();i++){
                left.push_back(right[i]);
            }
            sort(left.begin(),left.end());
            return left;
        }
    }
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        vector<int>v;
        int n=nums1.size();
        for(int i=0;i<nums1.size();i++){
            v.push_back(nums1[i]-nums2[i]);
        }
        ans(v,0,n-1,diff);
        return solution;
    }
};