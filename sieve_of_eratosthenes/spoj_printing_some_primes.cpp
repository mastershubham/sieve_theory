#include <iostream>
#include <vector>
#include <bitset>

using namespace std;
const int MAX = 100000000; // 10^8
vector<int> primes;
bitset<MAX> is_prime;

void sieve() {
    is_prime.set(); // Set all bits to true
    is_prime[0] = is_prime[1] = false; // 0 and 1 are not prime
    for (long long i = 2; i * i < MAX; i++) {
        if (is_prime[i]) {
            for (long long j = i * i; j < MAX; j += i) {
                is_prime[j] = false;
            }
        }
    }
    for (int i = 2; i < MAX; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
        }
    }
}

int main(){
    sieve();
    for (int i = 0; i < primes.size(); i+=100){
        cout << primes[i] << "\n";
    }
}
