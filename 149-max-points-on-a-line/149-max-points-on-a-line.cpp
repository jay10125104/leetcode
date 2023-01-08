class Solution {
public:
    int maxPoints(vector<vector<int>>& v) {
        double slope;
        int n=v.size();
        int ans=0;
        for(int i=0;i<n;i++){
            map<double,int>m;
            double x,y;
            int ma=0;
            int same=1;
            for(int j=i+1;j<n;j++){
                if(v[i][0]==v[j][0]&&v[i][1]==v[j][1]){
                    same++;
                    continue;
                }
                x=v[i][0]-v[j][0];
                y=v[i][1]-v[j][1];
                if(x==0){
                    slope=INT_MAX;
                }
                else{
                    slope=y/x;
                }
                m[slope]=m[slope]+1;
                if(m[slope]>ma) ma=m[slope];
            }
            ans=max(ma+same,ans);
        }
        return ans;
    }
};