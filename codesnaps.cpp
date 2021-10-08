#include <iostream>
using namespace std;
/*
线性筛：

*/
const int N = 100005;
int primes[N];
bool st[N];
int cnt;
void get_primes(int n) {
    for (int i = 2; i <= n; i++) {
        if (!st[i]) {
            primes[cnt++] = i;
        }
        for (int j = 0; primes[j] <= n / i; j++) {
            st[primes[j] * i] = true;
            if (i % primes[j] == 0) break;
        }
    }
}

// void get_primes(int n) {
//     for (int i = 2; i <= n; i++) {
//         if (!st[i]) {
//             primes[cnt++] = i;
//             for (int j = i + i; j <= n; j += i) st[j] = true;
//         }
//     }
// }


int main() {
    int n; 
    cin >> n;
    get_primes(n);
    for (int i = 0; i < cnt; i++) {
        cout << primes[i] << " ";
    }
    cout << endl;
}