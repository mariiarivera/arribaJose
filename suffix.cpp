#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void suffix(const string &input) {
    string text = input + "$"; 
    vector<int> arr(text.size());

    for (int i = 0; i < text.size(); i++) {
        arr[i] = i;
    }

    cout << "sin orden" << endl;
    for (int i : arr) {
        cout << i << " -> " << text.substr(i) << endl;
    }

    sort(arr.begin(), arr.end(), [&](int a, int b) {
        return text.substr(a) < text.substr(b);
    });

    cout << "orden" << endl;
    for (int i : arr) {
        cout << i << " -> " << text.substr(i) << endl;
    }
}

int main() {
    suffix("ababcabcabababd");
    return 0;
}
