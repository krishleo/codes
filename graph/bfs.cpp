/****************BFS and level of a node*****************/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n, a, b, i, lev;
    cin >> n;
    vector <int> v[n+1];
    
    for (i = 0; i < n-1; i++) {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
        
    }
    cin >> lev;
    
    queue <int> q;
    q.push(1);
    vector <bool> vis(n+1, false);
    int level[n+1];
    
    vis[1] = true;
    level[1] = 1;
    
    int ans = 0;
    
    while (!q.empty()) {
        int p = q.front();
        q.pop();
        
        for (i = 0; i < v[p].size(); ++i) {
            if (vis[v[p][i]] == false) {
                q.push(v[p][i]);
                vis[v[p][i]] = true;
                level[v[p][i]] = level[p] + 1;
                
                if (level[v[p][i]] == lev) {
                    ++ans;
                }
            }
        }
    }
    cout << ans << endl;
}
