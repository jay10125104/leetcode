class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) 
    {
        priority_queue<pair<int,vector<int>>> pq;
        for(int i=0;i<points.size();i++)
        {
            int x = pow(points[i][0]-0,2)+pow(points[i][1]-0,2);
            if(pq.size()<k)
            pq.push({x,points[i]});
            else{
                int t = pq.top().first;
                if(t>x){
                    pq.pop();
                    pq.push({x,points[i]});
                }
            }
        }
        vector<vector<int>> answer;
        while(pq.size()){
            answer.push_back(pq.top().second);
            pq.pop();
        }
        return answer;
    }
};