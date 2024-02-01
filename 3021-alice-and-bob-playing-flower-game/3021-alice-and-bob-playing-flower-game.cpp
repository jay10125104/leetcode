class Solution {
public:
    long long flowerGame(int n, int m) {
        long long int even1 = n/2;
        long long int even2=m/2;
        long long int odd1=(n/2)+(n%2);
        long long int odd2=(m/2)+(m%2);
        return even1*odd2+even2*odd1;
    }
};