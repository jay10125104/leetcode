class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& v) {
        set<int>s;
        set<int>t;
        int n=v.size();
        for(int i=0;i<n;i++){
            s.insert(v[i][0]);
            t.insert(v[i][1]);
        }
        // int n=v.size();
        if(s.size()==1 || t.size()==1){
            return true;
        }
        else if(s.size()!=n && t.size()!=n){
            return false;
        }
        
        int down = v[0][1]-v[1][1];
        int up = v[0][0]-v[1][0];
        double x = (double)((double)down/(double)up);
        for(int i=1;i<v.size()-1;i++){
            int u = v[i][0]-v[i+1][0];
            int d = v[i][1]-v[i+1][1];
        double xi = (double)((double)d/(double)u);   
            cout<<x<<" "<<xi<<endl;
            
            if(xi!=x){
                return false;
            }
        }
    return true;
    }
    
};