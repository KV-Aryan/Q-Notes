An array B of size M is called good if for all 1 ≤ i ≤ M, either one of the following conditions hold: Bi = 1. There exists j such that 1 ≤ j < i and Bj = Bi − 1.

Given an array A of size N, find the size of the largest good subsequence B of A. B is said to be a subsequence of A if it can be formed by deleting several elements from the array A without changing the order of the remaining elements.

Input Format

The first line of input will contain a single integer T, denoting the number of test cases. Each test case consists of multiple lines of input. The first line contains a single integer N. The second line contains N integers A1, A2, …, AN.

Output Format

For each test case, output on a new line the size of the largest good subsequence of A.

Constraints

1 ≤ T ≤ 100. 1 ≤ N ≤ 100. 1 ≤ Ai ≤ N.

Sample 1

Input
3
4
1 2 3 4
5
1 3 1 2 3
3
2 2 2

Output
4
4
0
  
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        int N;
        cin >> N;
        
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        
        vector<int> taken(N + 2, 0); // 1-based indexing for values
        
        for (int val : arr) {
            if (val == 1) {
                taken[1]++;
            } else {
                if (taken[val - 1] > 0) {
                    taken[val]++;
                }
            }
        }
        
        int total = 0;
        for (int count : taken) {
            total += count;
        }
        
        cout << total << endl;
    }
    
    return 0;
}
