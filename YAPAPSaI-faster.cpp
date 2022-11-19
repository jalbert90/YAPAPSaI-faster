#include <iostream>
#include <algorithm>

using namespace std;

void solve() {
	int n, size = 0;
	long long int ans = 0;
	cin >> n;

	pair<int, int>* a = new pair<int, int>[n];

	for (int i = 1, j = 0; i <= n; i++) {
		int in;
		cin >> in;
		if (in < i) {
			a[j].first = in;
			a[j].second = i;
			size++;
			j++;
		}
	}

	sort(a, a + size);

	int ma = a[size - 1].first;

	for (int i = 0; i < size; i++) {
		int f = a[i].second + 1;
		int fi = size;
		if (a[i].second < ma) {
			fi = find_if(a + i, a + size, [f](pair<int, int> p) {return p.first >= f;}) - a;
		}
		ans += size - fi;
	}

	cout << ans << endl;

	delete[] a;
}

int main() {
	int t;
	cin >> t;

	while (t--) {
		solve();
	}
}