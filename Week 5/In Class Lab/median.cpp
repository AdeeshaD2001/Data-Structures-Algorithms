#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> nums;
    int n;
    while (cin >> n) {
        nums.push_back(n);
        sort(nums.begin(), nums.end());
        int size = nums.size();
        double median;
        if (size % 2 == 0) {
            median = (nums[size/2 - 1] + nums[size/2]) / 2.0;
        } else {
            median = nums[size/2];
        }
        cout << "Sorted Median" << endl;
        for (int i = 0; i < size; i++) {
            cout << nums[i] << " ";
        }
        cout << endl << median << endl;
    }
    return 0;
}
