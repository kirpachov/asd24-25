#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>

/*

  VERSIONE CON IL BEST-FIT

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

*/

int min(int n1, int n2){
  return n1 < n2 ? n1 : n2;
}

int max(int n1, int n2){
  return n1 > n2 ? n1 : n2;
}

int find(std::vector<int> const& v, const int n, const int start, const int end) {
  int size = end - start + 1;
  if (size <= 2){
    if (v.at(start) == n) return start;
    if (v.at(end) == n) return end;

    return -1;
  }

  const int m = start + (size / 2);
  if (v.at(m) > n) return find(v, n, start, m - 1);
  return find(v, n, m, end);
}

int find(std::vector<int> const& v, int n) {
  return find(v, n, 0, v.size() - 1);
}

void sort(std::vector<int>& v, int start, int end){
  int size = end - start + 1;
  if (size < 2) return;
  if (size == 2) {
    if (v[start] > v[end]) {
      int k = v[start];
      v[start] = v[end];
      v[end] = k;
    }

    return;
  } // if size 2

  int m = start + size / 2;
  sort(v, start, m);
  sort(v, m + 1, end);

  std::vector<int> copy = v;

  int i = start, sx = start, dx = m + 1;
  while(sx <= m && dx <= end) {
    if (copy[sx] < copy[dx])
      v[i++] = copy[sx++];
    else
      v[i++] = copy[dx++];
  }

  while(sx <= m)
    v[i++] = copy[sx++];

  while(dx <= end)
    v[i++] = copy[dx++];
}

void sort(std::vector<int> & v){
  return sort(v, 0, v.size() - 1);
}

int libriSelezionati(std::vector<int> prezzoLibri, double soldi, std::vector<std::pair<int, int>>& res) {

  sort(prezzoLibri);

  for(int i = 0; i < 1 + prezzoLibri.size() / 2; i++){
    int n = prezzoLibri[i];

    if (soldi - n > 0 && find(prezzoLibri, soldi - n) != -1) {
      res.push_back(
        std::pair<int, int>(
          min(soldi - n, n),
          max(soldi - n, n)
        )
      );
    }
  }

  return res.size();
}

int main() {
  int exitcode = 0;

  int soldi = 0, soldi_size = 0;
  std::vector<int> libri;
  std::vector<std::pair<int, int>> result;
  
  std::cin >> soldi;
  std::cin >> soldi_size;
  for(int i = 0; i < soldi_size; i++) {
    int tmp = 0;
    std::cin >> tmp;
    libri.push_back(tmp);
  }

  libriSelezionati(libri, soldi, result);

  {
    int expect_size = 0;
    std::cin >> expect_size;
    std::vector<std::pair<int, int>> expect;
    while(expect_size > 0) {
      expect_size--;

      int n1 = 0;
      int n2 = 0;
      std::cin >> n1;
      std::cin >> n2;

      expect.push_back(
        std::pair<int, int>(
          n1,
          n2
        )
      );
    }

    if (expect != result) {
      std::cout << "Error!\nExpected:" << std::endl;
      for(auto p: expect)
        std::cout << p.first << " " << p.second << std::endl;

      exitcode = 1;
    } else {
      std::cout << "correct" << std::endl;
    }
  }

  std::cout << "Output:" << std::endl;
  for(auto p: result)
    std::cout << p.first << ", " << p.second << std::endl;

  return exitcode;
}