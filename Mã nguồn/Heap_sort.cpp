/**
 *    author:  longvu
 *    created: 03/06/24 21:26:11
**/
#include<bits/stdc++.h>

using namespace std;
using namespace std::chrono;

#define int long long
#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
const int INF = numeric_limits<int>::max();
const int nax = (int)(2010001);
const int mod = 1e9 + 7;

template<class X, class Y>
bool maximize(X& x, const Y y) {
    if (y > x) {x = y; return true;}
    return false;
}
template<class X, class Y>
bool minimize(X& x, const Y y) {
    if (y < x) {x = y; return true;}
    return false;
}

int a[nax];
void help(int N, int i) {
    int largest = i, l = 2 * i + 1, r = 2 * i + 2;
    if (l < N && a[l] > a[largest]) {
        largest = l;
    }
    if (r < N && a[r] > a[largest]) {
        largest = r;
    }
    if (largest != i) {
        swap(a[i], a[largest]);
        help(N, largest);
    }
}

void heap_sort(int N) {
    for (int i = N / 2 - 1; i >= 0; i--) {
        help(N, i);
    }
    for (int i = N - 1; i > 0; i--) {
        swap(a[0], a[i]);
        help(i, 0);
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen("test_case/heap_sort.out", "w", stdout);
    for (int tests = 1; tests <= 10; tests++) {
        string fname = "test_case/Test_" + to_string(tests) + ".txt";
        ifstream inp(fname);
        int n;
        inp >> n;
        for (int i = 0; i < n; ++i) {
            inp >> a[i];
        }
        auto start = high_resolution_clock::now();
        heap_sort(n);
        auto end = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(end - start);
        cout << (long double)duration.count() / 1000 << endl;
        cout.flush();
    }
    return 0;
}