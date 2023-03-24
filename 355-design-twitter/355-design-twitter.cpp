class Twitter {
public:
    map<int,set<int>>m;
    vector<vector<int>>v;
    int count=0;
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        v.push_back({userId,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int>ans;
        for(int i=v.size()-1;i>=0 && ans.size()<10;i--){
            if(v[i][0]==userId || m[userId].count(v[i][0])){
                ans.push_back(v[i][1]);
            }
        }
        return ans;
    }
    
    void follow(int x, int y) {
        m[x].insert(y);
    }
    
    void unfollow(int x, int y) {
        m[x].erase(y);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */