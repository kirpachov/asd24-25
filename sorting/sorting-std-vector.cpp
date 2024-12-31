#include <iostream>
#include <vector>
#include <algorithm>

// *** HERE insert your function call ***
void do_sort(std::vector<int>& v){
}

void print(std::vector<int> const &v) {
  for(auto n: v)
    std::cout << n << "\t";

  std::cout << std::endl;
}

int main(){
  std::vector<int> input;
  while(std::cin) {
    int n = 0;
    std::cin >> n;
    input.push_back(n);
    std::cin >> std::ws;
  }
  auto output = input;
  auto expected = input;
  std::sort(expected.begin(), expected.end());

  do_sort(output);

  std::cout << "input: " << std::endl;
  print(input);

  std::cout << "output: " << std::endl;
  print(output);

  std::cout << "expected: " << std::endl;
  print(expected);

  if (expected != output) {
    std::cerr << "DIFFERENT!" << std::endl;
    return 1;
  } else {
    std::cout << "ok" << std::endl;
  }

  return 0;
}