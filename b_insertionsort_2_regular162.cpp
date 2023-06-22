#include <bits/stdc++.h>


int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int N;
    std::cin >> N;
    
    std::vector<int> P(N);
    for (int i = 0; i < N; i++) {
        std::cin >> P[i];
        P[i]--;
    }
    
    std::vector<std::array<int, 2>> ans;
    for (int i = N - 1; i >= 2; i--) {
        int j = std::find(P.begin(), P.end(), i) - P.begin();
        if (j == 0) {
            ans.push_back({1, 1});
            std::rotate(P.begin(), P.begin() + 2, P.begin() + 3);
            j = 1;
        }
        ans.push_back({j, i - 1});
        std::rotate(P.begin() + j - 1, P.begin() + j + 1, P.begin() + i + 1);
    }
    if (P[0] != 0) {
        std::cout << "No\n";
        return 0;
    }
    std::cout << "Yes\n";
    std::cout << ans.size() << "\n";
    for (auto [i, j] : ans) {
        std::cout << i << " " << j << "\n";
    }
    
    return 0;
}
