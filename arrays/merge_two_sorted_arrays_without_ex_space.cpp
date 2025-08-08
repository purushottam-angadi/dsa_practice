#include <iostream>
#include <vector>
#include <algorithm>

#include <bits/stdc++.h>
using namespace std;

pair<vector<int>, vector<int>> merge(vector<int> &arr1, vector<int> &arr2)
{
    int n = arr1.size();
    int m = arr2.size();
    int left = n - 1;
    int right = 0;

    while (left > 0 && right < m)
    {
        if (arr1[left] > arr2[right])
        {
            swap(arr1[left], arr2[right]);
            left--;
            right++;
        }
        else
        {
            break;
        }
    }

    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());

   return {arr1,arr2};
}

int main()

{

    vector<int> arr1 = {1, 3, 5, 7};
    vector<int> arr2 = {0, 2, 6, 8, 9};
    pair<vector<int>, vector<int>> result = merge(arr1, arr2);

     cout << "Merged arr1: ";
    for (int val : result.first) cout << val << " ";
    cout << "\nMerged arr2: ";
    for (int val : result.second) cout << val << " ";
    cout << endl;

}



// Optimal method 2:-
#include <bits/stdc++.h>
using namespace std;

void swapIfGreater(long long a[], long long b[], int i, int j) {
    if (a[i] > b[j]) swap(a[i], b[j]);
}

void merge(long long a[], long long b[], int n, int m) {
    int len = n + m, gap = (len / 2) + (len % 2);
    while (gap > 0) {
        int i = 0, j = gap;
        while (j < len) {
            if (i < n && j >= n) swapIfGreater(a, b, i, j - n);
            else if (i >= n) swapIfGreater(b, b, i - n, j - n);
            else swapIfGreater(a, a, i, j);
            i++, j++;
        }
        if (gap == 1) break;
        gap = (gap / 2) + (gap % 2);
    }
}

int main() {
    long long a[] = {1, 4, 8, 10}, b[] = {2, 3, 9};
    int n = 4, m = 3;
    merge(a, b, n, m);
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << "\n";
    for (int i = 0; i < m; i++) cout << b[i] << " ";
    cout << "\n";
    return 0;
}