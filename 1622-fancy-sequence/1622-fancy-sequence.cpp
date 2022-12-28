class Fancy {
public:
    int i=0;
    vector<long long int>v;
    long long int increment=0;
    long long int multiply = 1;
    int m=1000000007;
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
    Fancy() {
        v.resize(100001);
    }
    
    void append(int val) {
        v[i]=((val%m)-(increment%m)+m)%m;
        v[i] = ((v[i]%m)*(binaryexpo(multiply,m-2)%m))%m;
        i++;
    }
    
    void addAll(int inc) {
        increment = (increment%m + inc%m)%m;
    }
    
    void multAll(int mul) {
        multiply = ((multiply%m)*(mul%m))%m;
        increment = (((increment%m)*(mul%m)))%m;
        
    }
    
    int getIndex(int idx) {
        // cout<<i<<" ";
        if(idx>=i){
            return -1;
        }
        else{
            return (((v[idx]%m)*(multiply%m))%m + (increment)%m)%m;
        }
    }
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */