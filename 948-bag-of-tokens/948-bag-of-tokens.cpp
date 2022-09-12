class Solution {
public:
    int bagOfTokensScore(vector<int>& v, int power) {
        sort(v.begin(),v.end());
        if(v.size()==0){
            return 0;
        }
        if(v[0]>power){
            return 0;
        }
        int n=v.size();
        int score=0;
        int i=0;
        int j=n-1;
        while(i<=j){
            if(v[i]<=power){
                power-=v[i];
                score++;
                i++;
            }
            else{
               if(v[j]+power>=v[i] && i!=j){
                   power+=v[j];
                   j--;
                   score--;
               }
                else{
                    break;
                }
            }
        }
        return score;
    }
};