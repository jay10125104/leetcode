class Solution {
public:
    long long totalCost(vector<int>& v, int c, int k) {
        priority_queue<int, vector<int>, greater<int> >p1;
        priority_queue<int, vector<int>, greater<int> >p2;
        int i=0;
        int j=v.size()-1;
        long long int ans=0;
              while(c--){
            while(p1.size()!=k && i<=j ){
                p1.push(v[i]);
                i++;
            }
            while(p2.size()!=k && j>=i){
                p2.push(v[j]);
                j--;
            }
            int x = INT_MAX;
            int y = INT_MAX;
            if(p1.size())
             x = p1.top();
            if(p2.size())
            y = p2.top();
           
            if(x<=y){
                p1.pop();
                ans+=x;
                // c--;
            }
            else{
                p2.pop();
                ans+=y;
                // c--;
            }
            // if(c==0){
            //     break;
            // }
        }
        
        return ans;
    }
};