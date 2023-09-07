#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <tuple>
#include <string>
#include <algorithm>
#include <limits>
#include <cmath>

using namespace std;

using ll = long long;
using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using pii = pair<int, int>;
using vii = vector<pii>;
using pll = pair<ll, ll>;
using vll = vector<pll>;

constexpr auto NINF = numeric_limits<ll>::min();

int n;
vl arr;

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	cin >> n;
	arr = vl(n + 2, 0);
	for (auto i = 1; i <= n; ++i) {
		cin >> arr[i];
	}

	auto st = stack<ll>{};
	st.push(0);
	auto ans = ll{ 0 };
	for (auto i = 1; i <= n + 1; ++i) {
		while (!st.empty() && arr[i] < arr[st.top()]) {
			auto chk = st.top();
			st.pop();

			ans = max(ans, arr[chk] * (i - st.top() - 1));
		}

		st.push(i);
	}

	cout << ans;

	return 0;
}