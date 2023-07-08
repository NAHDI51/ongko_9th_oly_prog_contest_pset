#include <bits/stdc++.h>
using namespace std;

int main() {

    int high = 200000; // Lower bound of the range
    int low = 1; // Upper bound of the range

    random_device rd; // Obtain a random seed from the hardware
    mt19937_64 eng(rd()); // Seed the random number engine
    uniform_int_distribution<long long> dist(low, high);

    int n = dist(eng);
    int q = dist(eng);  

    cout << n << ' ' << q << '\n';
    // Tree
    for(long i = 2; i <= n; ++i) cout << (dist(eng) % (i - 1) + 1) << " " << i << "\n";
    // Queries
    for(int i = 0; i < q; i++) cout << dist(eng) % 2 << ' ' << (dist(eng)%n)+1 << ' ' << (dist(eng)%n)+1 << '\n';
}