AB or C

You are given 3 arrays of positive integers A, B and C, all of length N. Now, you need to construct another array D of length N such that Di is either Ai, Bi or Ci for each 1 ≤ i ≤ N. You can independently choose which value to take for each index. Find the minimum possible value of max(D) − min(D) when we optimally choose the array D. Here, max(D) represents the maximum element of D, and symmetrically min(D) represents the minimum element.

Input Format

The first line of input will contain a single integer T, denoting the number of test cases. Each test case consists of multiple lines of input. The first line contains a single integer N - the size of the arrays. The i-th of the next N lines contain 3 integers each - Ai, Bi and Ci.

Output Format

For each test case, output a single integer - the minimum possible value of max(D) − min(D).

Input
2
4
2 4 8
10 12 7
1 6 3
8 2 3
4
10 7 7
2 5 5
3 9 9
11 12 12

Output
2
6


#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<pair<int,int>> v; // {value, index}

        for (int i = 0; i < N; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            v.push_back({a, i});
            v.push_back({b, i});
            v.push_back({c, i});
        }

        sort(v.begin(), v.end());

        vector<int> count(N, 0);
        int covered = 0;
        int left = 0;
        int ans = INT_MAX;

        for (int right = 0; right < 3*N; right++) {
            int idx = v[right].second;

            if (count[idx] == 0) covered++;
            count[idx]++;

            // try to shrink window
            while (covered == N) {
                ans = min(ans, v[right].first - v[left].first);

                int left_idx = v[left].second;
                count[left_idx]--;
                if (count[left_idx] == 0) covered--;

                left++;
            }
        }

        cout << ans << "\n";
    }

    return 0;
}
