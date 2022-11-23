class Solution {
public:
    int stoneGameVI(vector<int>& a, vector<int>& b) {
        int ans1=0;
        int ans2=0;
        priority_queue<pair<int,pair<int,int>>>q;
        for(int i=0;i<a.size();i++){
            q.push(make_pair(a[i]+b[i],make_pair(a[i],b[i])));
        }
        int k=0;
        while(q.size()){
            if(k%2==0){
                ans1+=q.top().second.first;
            }
            else{
                ans2+=q.top().second.second;
            }
            k++;
            q.pop();
        }
        // cout<<ans1<<" "<<ans2<<endl;
        if(ans1==ans2){
            return 0;
        }
        else if(ans1<ans2){
            return -1;
        }
        else{
            return 1;
        }
    }
};