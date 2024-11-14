#include <bits/stdc++.h>
using namespace std;
 
const int md = (int) 1e9 + 7; 
 
int nums, msk;
int numToMask[100];
int digitToMask[] = {10, 2, 9, 7, 18, 21, 12, 3, 29, 23};
 
void init() {
  for (int i = 0; i < 10; ++i) {
    for (int j = 0; j < 10; ++j) {
      numToMask[i * 10 + j] = digitToMask[i] * 32 + digitToMask[j];
    }
  }
}
 
void add(int& a, int b) {
  a += b;
  if (a >= md) a -= md;
}
 
int mul(int a, int b) {
  return (int) ((long long) a * b % md);
}
 
struct M1 {
  int mat[1024] = {};
  M1 operator * (M1 other) {
    M1 ret;
    for (int i = 0; i < msk; ++i) {
      for (int j = 0; j < msk; ++j) {
        add(ret.mat[i ^ j], mul(mat[i], other.mat[j]));
      }
    }
    return ret;
  };
};
 
struct M2 {
  int mat[100][100] = {};
  M2 operator * (M2 other) {
    M2 ret;
    for (int i = 0; i < nums; ++i) {
      for (int k = 0; k < nums; ++k) {
        for (int j = 0; j < nums; ++j) {
          add(ret.mat[i][k], mul(mat[i][j], other.mat[j][k]));
        }
      }
    }
    return ret;
  }
};
 
M1 f(long long k) {
  M1 ret, b;
  ret.mat[0] = 1;
  for (int i = 1; i < msk; i *= 2) {
    b.mat[i] = 1; 
  }
  while (k) {
    if (k & 1) {
      ret = ret * b;
    }
    b = b * b; 
    k >>= 1; 
  }
  return ret;
}
 
M2 f2(M2 b, long long k) {
  M2 ret;
  for (int i = 0; i < nums; ++i) {
    ret.mat[i][i] = 1; 
  }
  while (k) {
    if (k & 1) {
      ret = ret * b;
    }
    b = b * b;
    k >>= 1; 
  }
  return ret;
}
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  init();
  int m, x;
  long long n, k;
  cin >> m >> n >> k >> x;
  nums = (m == 1 ? 10 : 100); 
  msk = (m == 1 ? 32 : 1024);
  M1 m1 = f(k);
  M2 m2;
  for (int i = 0; i < nums; ++i) {
    for (int j = 0; j < nums; ++j) {
      m2.mat[i][j] = m1.mat[numToMask[i] ^ numToMask[j]];
    }
  }
  M2 m3 = f2(m2, n / k);
  m1 = f(n % k);
  for (int i = 0; i < nums; ++i) {
    for (int j = 0; j < nums; ++j) {
      m2.mat[i][j] = m1.mat[numToMask[i] ^ numToMask[j]];
    }
  }
  M2 m4 = m3 * m2;
  for (int i = 0; i < nums; ++i) {
    cout << m4.mat[x][i] << '\n';     
  }
  return 0;
}

