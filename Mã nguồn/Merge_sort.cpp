/**
 *    author:  longvu
 *    created: 03/06/24 21:31:03
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

int a[nax], b[nax];
void merge_sort(int l, int r) {
	if (l >= r) {
		return;
	}
	int mid = (l + r) >> 1;
	merge_sort(l, mid);
	merge_sort(mid + 1, r);
	int j = mid + 1, e = l - 1;
	for (int i = l; i <= mid; ++i) {
		while (j <= r && a[j] <= a[i]) {
			b[++e] = a[j++];
		}
		b[++e] = a[i];
	}
	while (j <= r) {
		b[++e] = a[j++];
	}
	for (int i = l; i <= r; ++i) {
		a[i] = b[i];
	}
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("test_case/merge_sort.out", "w", stdout);
	for (int tests = 1; tests <= 10; tests++) {
		string fname = "test_case/Test_" + to_string(tests) + ".txt";
		ifstream inp(fname);
		int n;
		inp >> n;
		for (int i = 1; i <= n; ++i) {
			inp >> a[i];
		}
		auto start = high_resolution_clock::now();
		merge_sort(1, n);
		auto end = high_resolution_clock::now();
		auto duration = duration_cast<microseconds>(end - start);
		cout << (long double)duration.count() / 1000 << endl;
	}
	return 0;
}