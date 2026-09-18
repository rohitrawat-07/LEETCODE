class Solution {
public:
     bool isPrime(int n) {
    if (n < 2) {
        return false;
    }
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}
    int sumOfPrimesInRange(int n) {
        int x = n;
        int rev = 0;
        while(n != 0){
            int a = n % 10;
            rev = rev * 10 + a;
            n = n/10;
        }
         long long sum = 0;
        for(int i = min(x , rev); i <= max(x , rev); i++){
            if(isPrime(i)){
                sum += i;
            }
        }
        return sum;
    }
};

