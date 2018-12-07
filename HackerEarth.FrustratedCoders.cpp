#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
int main() {
    int n;
    cin >> n;
 
    vector<int> skills;
    long long int sum = 0;
    while (n--) {
        int x;
        cin >> x;
        skills.push_back(x);
        sum += x;
    }
 
    sort(skills.begin(), skills.end());
    
    auto it0 = skills.rbegin();
    auto it1 = next(it0);
    
    while (it1 != skills.rend()) {
        if (*it0 > *it1) {
            sum -= *it1;
            it0++;
            it1++;
        }
        else if (*it0 == *it1 || it0 == it1)
            it1++;
    }
    
    cout << sum << endl;
    
    return 0;
}