#include <bitset>
#include <iostream>

using namespace std;

class Solution {
public:
    int countPrimes(int n) {
       bitset<5000000> is_prime; // We can change 5*10^6.
       is_prime.set();
       is_prime[0] = 0;
       for(int i = 2; i * i < n; i++){
        if(is_prime[i-1]){
            for(int j = 2 * i; j < n; j+=i){
                is_prime[j-1] = 0;
            }
        }
       }
       int count = 0;
       for(int i = 1; i < n; i++){
        if(is_prime[i-1]){
            count++;
        }
       }
       return count;
    }
};

int main(){
    int n = 5000000;
    Solution prime_counter; 
    int result = prime_counter.countPrimes(n);
    cout << result << "\n";
}
