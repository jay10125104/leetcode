class Solution {
public:
    int countDaysTogether(string a1, string a2, string b1, string b2) {
        vector<int>v = {0,31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int sam = 10*(a1[0]-'0') + (a1[1]-'0'); 
        int sad =10*(a1[3]-'0') + (a1[4]-'0');
         int eam = 10*(a2[0]-'0') + (a2[1]-'0'); 
        int ead =10*(a2[3]-'0') + (a2[4]-'0');
         int sbm = 10*(b1[0]-'0') + (b1[1]-'0'); 
        int sbd =10*(b1[3]-'0') + (b1[4]-'0'); 
        int ebm = 10*(b2[0]-'0') + (b2[1]-'0'); 
        int ans=0;
        int ebd =10*(b2[3]-'0') + (b2[4]-'0');
        map<string,int>m;
        // cout<<sam<<" "<<sad<<" "<<eam<<" "<<ead<<endl;
        for(int i=sam;i<=eam;i++){
            int sd = 1;
            if(i==sam){
                sd = sad;
            }
            int ed = v[i];
            if(i==eam){
                // cout<<ead<<" ";
                ed = ead;
            }
            for(int day = sd;day<=ed;day++){
                string mid = to_string(i);
                mid+='-';
                string mid2 = to_string(day);
                mid+=mid2;
                m[mid]++;
            }
            
        }
        for(int i=sbm;i<=ebm;i++){
            int sd = 1;
            if(i==sbm){
                sd = sbd;
            }
            int ed = v[i];
            if(i==ebm){
                // cout<<ead<<" ";
                ed = ebd;
            }
            for(int day = sd;day<=ed;day++){
                string mid = to_string(i);
                mid+='-';
                string mid2 = to_string(day);
                mid+=mid2;
                if(m[mid]>=1){
                    ans++;
                }
            }
            
        }
        return ans;
    }
};