#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <random>
#include <string>
#include <algorithm>

#define ll long long 

int main(int argc, char** argv) {
    ll high = 1e18; // Lower bound of the range
    ll low = -high; // Upper bound of the range

    std::random_device rd; // Obtain a random seed from the hardware
    std::mt19937_64 eng(rd()); // Seed the random number engine
    std::uniform_int_distribution<long long> dist(low, high);


    int n = abs(dist(eng) % 200000) + 1;
    // int n = 10000;
    std::vector<ll> arr(n);

    if(argc == 2) {
        
    // Generally randomly generated numbers have an infinestimally 
    // small chance of being in a series, so we need to generate 
    // some amount of matching solutions per testcase.

    //Typically, we would do this if we have argv[1] % 6 == 0,
    //in which, generator maker will call this program with two
    //arguments. Otherwise, there is no need to do this.
    
        arr[0] = (dist(eng) % (ll) 1e9);
        ll distance = (dist(eng) % (ll) 1e9);

        for(int i = 1; i < n; i++) {
            arr[i] = arr[i-1] + distance;
        }

        if(dist(eng) % 2) std::reverse(arr.begin(), arr.end());
    } else {

        // To avoid polarized values, we need to make within_billion
        // = not_within_billion.
        int within_billion = 0;
        int not_within_billion = 0;

        // Get the numbers
        for (int i = 0; i < n; i++) {
            arr[i] = dist(eng);

            if(abs(arr[i]) <= 1e9) within_billion++;
            else not_within_billion++;
        }
        // Typically, we'd want at least half of the numbers 
        // to be within a billion. OTherwise, it'd be far
        // too polarized, and that would be pretty bad.

        for(int i = 0; i < n; i++) {
            if(abs(within_billion - not_within_billion) <= 1) break;

            if(abs(arr[i]) > 1e9) {
                arr[i] %= (ll) 1e9;
                within_billion++, not_within_billion--;
            }
        }
        std::reverse(arr.begin(), arr.end());
    }

    // Output
    std::cout << n << '\n';
    for(int i = 0; i < n; i++) {
        std::cout << arr[i] << ' ';
    }
    std::cout << '\n';

    return 0;
}

/*
Sample Input 0

4
5 10 15 20
Sample Output 0

5
Explanation 0

In the first sample, we see that

which means that they create an addition series with difference of 5 in-between. Thus, we return .

Sample Input 1

4
3 6 7 9
Sample Output 1

-1
Explanation 1

In the second example, we see that

Which means, it does not form an addition series. Thus, we return .
*/
 