#include "bits/stdc++.h"
using namespace std;
vector<int> rotateImage(vector<int> inputImage) {
  vector<int> ans;
  for (int i = 0; i < inputImage[2]; i++) {
    for (int j = inputImage[1] - 1; j >= 0; j--) {
      ans.push_back(inputImage[j * inputImage[2] + i + 3]);
    }
  }
  return ans;
}
int main() {
  auto v = rotateImage({8, 2, 3, 1, 2, 3, 4, 5, 6});
  for (auto z : v)
    cout << z << " ";
  return 0;
}