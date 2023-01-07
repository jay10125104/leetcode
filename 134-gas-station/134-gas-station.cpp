class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        vector<int>v;
        int t1 =0;
        int t2=0;
        for(int i=0;i<cost.size();i++){
            v.push_back(gas[i]-cost[i]);
            t1+=cost[i];
            t2+=gas[i];
        }
        if(t1>t2){
            return -1;
        }
        else{
            int idx=0;
            int sum=0;
            for(int i=0;i<v.size();i++){
                sum+=v[i];
                if(sum<0){
                    idx=i+1;
                    sum=0;
                }
            }
            if(idx==v.size()){
                return -1;
            }
            else{
                return idx;
            }
        }
    }
};