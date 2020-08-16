#include<iostream>
#include<map>
#include<vector>

using namespace std;
int arr[1000001];
int main() {
	int n;
	cin >> n;
	map < int, int > m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < n; i++) {
		if (m.find(arr[i]) != m.end()) {
			m[arr[i]]++;
		} else {
			m[arr[i]]++;
		}
	}
	vector < int > ans;
	for (auto it: m) {
		if (it.second == 2) {
			ans.push_back(it.first);
		}
	}

	for (int i = 0; i < ans.size(); i++) {
		if (i == ans.size() - 1) {
			cout << ans[i];
		} else {
			cout << ans[i] << " ";
		}
	}

	return 0;
}