#include <algorithm> // next_permutation
#include <iostream>
#include <numeric> // iota
#include <vector>
using namespace std;

int main(int argc, char const *argv[]) {

  vector<int> v(3);
  // サイズを設定しておく必要がある
  iota(v.begin(), v.end(), 0);

  do {
    for (auto e : v)
      cout << e << ',';

    cout << endl;
  } while (next_permutation(v.begin(), v.end()));
  // 末尾から変わる
  /*
  0,1,2,
  0,2,1,
  1,0,2,
  1,2,0,
  2,0,1,
  2,1,0,
  */
  return 0;
}
