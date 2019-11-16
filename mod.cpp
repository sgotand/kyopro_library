#include <bits/stdc++.h>

using namespace std;

namespace Mod {

using namespace std;
using i64 = long long;

const i64 kMod = 1e9 + 7;
vector<i64> fac = {1LL};
i64 pow(i64 k, i64 n) { // k の n乗を計算
  k %= kMod;
  if (n == 0 || k == 1) {
    return 1;
  } else if (n < 0) {
    n %= kMod - 1;
    n += kMod - 1;
    return pow(k, n);
  } else if (n >= kMod - 1) {
    n %= kMod - 1;
    return pow(k, n);
  } else if (n % 2) {
    return (pow(k, n - 1) * k) % kMod;
  } else {
    i64 tmp = pow(k, n / 2);
    return (tmp * tmp) % kMod;
  }
}

i64 fact(i64 n) {
  if (n <= 0) {
    return 1;
  } else if ((i64)fac.size() > n && fac[n] != 0) {
    return fac[n];
  }

  if ((i64)fac.size() <= n) {
    fac.resize(2 * n);
  }

  i64 i = 1;

  while (fac[i] != 0 && i <= n) // i<= n is for avoiding infinite loop
    i++;
  while (i <= n) {
    fac[i] = (fac[i - 1] * (i % kMod)) % kMod;
    i++;
  }
  return fac[n];
}
i64 ifact(i64 n) { return pow(fact(n), -1); }
i64 comb(i64 n, i64 m) {
  i64 tmp = fact(n);
  i64 tmp2 = ifact(m);
  i64 tmp3 = ifact(n - m);
  tmp = (tmp * tmp2) % kMod;
  tmp = (tmp * tmp3) % kMod;
  return tmp;
}

i64 perm(i64 n, i64 m) { return (fact(n) * ifact(n - m)) % kMod; }

} // namespace Mod

int main(int argc, char const *argv[]) {
  long long x, y;
  cin >> x >> y;
  cout << Mod::pow(5 , 3) << endl;
  cout << Mod::fact(5) << endl;
  cout << Mod::ifact(5) << endl;
  cout << (Mod::ifact(5) * Mod::fact(5))%Mod::kMod << endl;
  cout << Mod::comb(6, 3) << endl;
  cout << Mod::perm(6, 3) << endl;
  return 0;
}
