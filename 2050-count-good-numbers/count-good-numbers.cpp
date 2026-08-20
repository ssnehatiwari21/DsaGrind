class Solution {
public: 
    long long power(long long a,long long b){
        long long mod=1e9+7;
        if(b==0) return 1;

        long long half=power(a,b/2);
        long long ans=(half*half)%mod;

        if(b%2==1){
            ans=(ans*a)%mod;
        }
        return ans;
    }
    int countGoodNumbers(long long n) {
        long long mod=1e9+7;
        if(n==0) return 1;
        if(n==1) return 5;
        
        long long even=(n+1)/2;
        long long odd=n/2;
        return (power(5,even)*power(4,odd))%mod;
    }
};