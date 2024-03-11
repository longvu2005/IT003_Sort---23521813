/**
 *    author:  longvu
 *    created: 03/06/24 21:11:47
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

mt19937_64 rng ((int64_t)(new char));

int randomnumber(int start, int end) {
	uniform_int_distribution<> dis(start, end);
	return dis(rng);
}

int a[nax], b[nax];
void quick_sort(int l, int r) {
	if (l >= r) {
		return;
	}
	int rd = randomnumber(l, r), v = a[rd];
	int m = l - 1;
	for (int i = l; i <= r; ++i) {
		if (a[i] < v) {
			b[++m] = a[i];
		}
	}
	for (int i = l; i <= r; ++i) {
		if (a[i] == v) {
			b[++m] = a[i];
		}
	}
	for (int i = l; i <= r; ++i) {
		if (a[i] > v) {
			b[++m] = a[i];
		}
	}
	for (int i = l; i <= r; ++i) {
		a[i] = b[i];
	}
	quick_sort(l, rd - 1);
	quick_sort(rd + 1, r);
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("test_case/quick_sort.out", "w", stdout);
	for (int tests = 1; tests <= 10; tests++) {
		string fname = "test_case/Test_" + to_string(tests) + ".txt";
		ifstream inp(fname);
		int n;
		inp >> n;
		for (int i = 1; i <= n; ++i) {
			inp >> a[i];
		}
		auto start = high_resolution_clock::now();
		quick_sort(1, n);
		auto end = high_resolution_clock::now();
		auto duration = duration_cast<microseconds>(end - start);
		cout << (long double)duration.count() / 1000 << endl;
	}
	return 0;
}