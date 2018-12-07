#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
 
using namespace std;
 
 
void DFS(vector<vector<int>>& m, int r, vector<double>& probs) {
    int st[200001];
    int stIdx = 0;
    st[stIdx++] = r;
    while (stIdx >= 0) {
        int e = st[stIdx--];
        double prob = probs[e];
        if (!m[e].empty())
            probs[e] = 0;

        for (int idx : m[e]) {
            probs[idx] += prob / m[e].size();
            st[++stIdx] = idx;
        }
    }
}
 
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, m, r;
    cin >> n >> m >> r;
    vector<vector<int>> edges(n + 1, vector<int>());
    while (m--) {
        int a, b;
        cin >> a >> b;

        edges[a].push_back(b);
    }

    vector<double> probs(n + 1, 0);
    probs[r] = 1.;
    DFS(edges, r, probs);

    const double diff = 0.0000000001;
    double maxProb = 0;
    vector<int> res;
    for (int i = 1; i < probs.size(); ++i) {
        double p = probs[i];
        if (p > maxProb && abs(p - maxProb) > diff) {
            maxProb = p;
            res.clear();
            res.push_back(i);
        }
        else if (abs(p - maxProb) <= diff)
            res.push_back(i);
    }

    sort(res.begin(), res.end());
    for (auto x: res)
        cout << x << " ";
    cout << endl;

    return 0;
}