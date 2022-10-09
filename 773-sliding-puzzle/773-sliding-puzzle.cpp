class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& v) {
        string req = "12345*";
        string s="";
        for(auto i:v){
            for(auto j:i){
                if(j)
                s+=(j+'0');
                else{
                    s+='*';
                }
            }   
        }
        vector<string>move = {"13","024","15","04","315","24"};
        map<string,int>m;
        int count=0;
        queue<string>q;
        q.push(s);
        while(q.size()){
            int x=q.size();
            
            while(x--){
                string mid = q.front();
                q.pop();
                m[mid]++;
            
                // cout<<mid<<" ";
                if(mid==req){
                    return count;
                }
                int idx=0;
                for(int i=0;i<6;i++){
                    if(mid[i]=='*'){
                        idx=i;
                        break;
                    }
                }
                string tomove = move[idx];
                for(auto i:tomove){
                    int x = i-'0';
                    string mid2=mid;
                    swap(mid2[idx],mid2[x]);
                    if(m[mid2]==0){
                        
                        q.push(mid2);
                    }
                }
                
            }
            count++;
        }
      
        return -1;
    }
};