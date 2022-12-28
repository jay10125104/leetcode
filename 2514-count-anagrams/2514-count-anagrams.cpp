vector<long long int>fact(100001);
long long int m = 1000000007;
long long int binaryexpo(long long int a,long long int b){
    long long int ans=1;
    while(b){
        if(b&1){
            ans = (ans*a)%m;
        }
        a = (a*a)%m;
        b=b/2;
    }
    return ans;
}
void factorial(){
    long long int ans=1;
    fact[0]=1;
    for(int i=1;i<=100000;i++){
        ans = ans*i;
        ans=ans%m;
        fact[i]=ans;
    }
}
class Solution {
public:
    int countAnagrams(string s) {
        vector<string>v;
        string mid="";
        for(int i=0;i<s.size();i++){
            if(s[i]!=' '){
                mid+=s[i];
                
            }
            else{
                v.push_back(mid);
                mid="";
            }
        }
        factorial();
        v.push_back(mid);
        long long int sol=1;
        for(int i=0;i<v.size();i++){
            map<char,int>m1;
            for(int j=0;j<v[i].size();j++){
                m1[v[i][j]]++;
            }
            long long int mid1 = fact[(int)v[i].size()];
            for(auto &it:m1){
                int r = it.second;
                int r_inverse = binaryexpo(fact[r],m-2);
                mid1 = ((mid1%m)*(r_inverse%m))%m;
            }
            sol =(sol%m * mid1%m)%m;
            
        }
        return sol;
        
    }
};