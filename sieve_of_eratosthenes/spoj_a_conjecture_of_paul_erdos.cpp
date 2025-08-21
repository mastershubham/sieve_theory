#include <iostream>
#include <vector>
#include <bitset>
#include <set>

using namespace std;
const int MAX = 10000000; // 10^7
vector<int> primes;
bitset<MAX> is_prime;
set<int> friedlander_iwaniec_primes;

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

int square(int x) {
    return x * x;
}

int fourth_power(int x) {
    return square(square(x));
}

void friedlander_iwaniec_sieve(){
    for (int x = 1; square(x) < MAX; x++) {
        for (int y = 1; fourth_power(y) + square(x) < MAX; y++) {
            int n = fourth_power(y) + square(x);
            if (is_prime[n]) {
                friedlander_iwaniec_primes.insert(n);
            }
        }
    }
}

int main(){
    sieve();
    friedlander_iwaniec_sieve();
    
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        // Output the number of friedlander-iwaniec primes less than or equal to n
        int count = 0;
        for (int prime : friedlander_iwaniec_primes) {
            if (prime <= n) {
                count++;
            }
        }
        cout << count << "\n";
    }
    return 0;
}
