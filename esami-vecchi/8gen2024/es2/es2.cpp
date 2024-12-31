#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>

// Vogliamo il best-fit. Avvicinarci più possibile a tot, anche se non possiamo arrivarci esattamente.
int libriSelezionati(std::vector<int>& pl, int tot, std::vector<int>& r){
  assert(pl.size() >= 2);
  std::sort(pl.begin(), pl.end());
  int i = 0;
  int j = pl.size() - 1;

  r.push_back(pl.at(0));
  r.push_back(pl.at(1));
  int best_fit = r.at(0) + r.at(1);

  while(i < j) {
    const int x1 = pl.at(i);
    const int x2 = pl.at(j);
    const int sum = x1 + x2;
    if (sum == tot){
      r.at(0) = x1;
      r.at(1) = x2;
      return 2;
    }

    if (sum > tot) j--;
    if (sum < tot){
      // Found a new best fit: current sum is
      //   - less than total
      //  - more than last fit.
      if (r.at(0) + r.at(1) < sum) {
        r.at(0) = x1;
        r.at(1) = x2;
      }
      i++;
    }
  }

  return 2;
}

int main() {
  int soldi = 0, soldi_size = 0, tmp = 0;
  std::vector<int> libri, expected_result, result;
  
  std::cin >> soldi;
  std::cin >> soldi_size;
  for(int i = 0; i < soldi_size; i++) {
    int tmp = 0;
    std::cin >> tmp;
    libri.push_back(tmp);
  }

  {
    int exp1 = 0;
    std::cin >> exp1;
    expected_result.push_back(exp1);
    std::cin >> exp1;
    expected_result.push_back(exp1);
  }

  libriSelezionati(libri, soldi, result);

  std::cout << "---DEBUG---" << std::endl;
  std::cout << "money: " << soldi << std::endl;
  std::cout << "libri:" << std::endl;
  for(auto j: libri) std::cout << j << " ";
  std::cout << "\nexpected: " << std::endl;
  for(auto j: expected_result) std::cout << j << " ";
  std::cout << "\ngot: " << std::endl;
  for(auto j: result) std::cout << j << " ";
  std::cout << "\n///DEBUG///\n" << std::endl;

  if (expected_result != result) {
    std::cout << "ERROR. expected" << std::endl;
    for(auto j: expected_result) std::cout << j << " ";
    std::cout << "\nbut got\n";
    for(auto j: result) std::cout << j << " ";
    std::cout << std::endl;
    return 1;
  }

  return 0;
}
