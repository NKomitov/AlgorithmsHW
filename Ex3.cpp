#include <iostream>
#include <vector>
#include <cmath>

int main() {
  std::vector<int> numberA;
  std::vector<int> numberB;
  std::vector<int> result;
  int inputA, inputB;
  std::cin >> inputA >> inputB;
  int biggerValue = (inputA > inputB) ? log10(inputA) : log10(inputB);
  for (int i = biggerValue, del = pow(10, biggerValue); i >= 0; i--, del /= 10) {
    numberA.push_back(inputA / del % 10);
    numberB.push_back(inputB / del % 10);
  }
  // деклариране на векторите и записване на числата

  int res = 0;
  bool carry1 = 0;
  for (int i = biggerValue; i >= 0; i--) {
    res = (numberA[i] + numberB[i]);
    result.insert(result.begin(), res % 10 + carry1);
    carry1 = res / 10;
  }
  if (carry1)
    result.insert(result.begin(), carry1);
  for (int i = 0; i <= biggerValue + carry1; i++) {
    std::cout << result[i];
  }

  return 0;
}