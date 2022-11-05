class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>>v;
        int n=speed.size();
        for(int i=0;i<n;i++){
            v.push_back({position[i],speed[i]});
        }
        sort(v.begin(),v.end());
        vector<double>time(n);
        for(int i=0;i<n;i++){
            int distance = target - v[i].first;
            time[i] = (double)((double)(distance)/(double)(v[i].second));
            cout<<time[i]<<" ";
        }   
        stack<double>s;
        for(int i=0;i<n;i++){
            // int x  = time[i];
            while(s.size() && s.top()<=time[i]){
                s.pop();
            }
            s.push(time[i]);
        }
        return s.size();
    }
};