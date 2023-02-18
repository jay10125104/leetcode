class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        set<int>st;
        int n=arr.size();
        for(int i=0;i<n;i++)
        {
            int pre_or=0, curr_or=arr[i],j=i-1;
            st.insert(arr[i]);
            while(j>=0 && curr_or!=pre_or) 
            {
                curr_or|=arr[j];
                pre_or|=arr[j];
                // cout<<i<<" "<<j<<" "<<curr_or<<" "<<pre_or<<endl;
                st.insert(curr_or);
                j--;
            }
            
        }
        return st.size();
    }
};