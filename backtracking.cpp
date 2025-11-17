#include <iostream>
#include <vector>
using namespace std;

void findSubsets(vector<int>& S, int target, int index, vector<int>& current) {
    if (target == 0) {  
        cout << "{ ";
        for (int num : current) cout << num << " ";
        cout << "}\n";
        return;
    }
    if (index == S.size() || target < 0) return;

    current.push_back(S[index]);
    findSubsets(S, target - S[index], index + 1, current);
    current.pop_back();

    findSubsets(S, target, index + 1, current);
}

int main() {
    vector<int> S = {2, 3, 7, 9};
    int target = 5;
    vector<int> current;

    cout << "Subsets that sum to " << target << ":\n";
    findSubsets(S, target, 0, current);

    return 0;
}

