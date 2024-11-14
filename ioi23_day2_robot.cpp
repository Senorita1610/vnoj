#include <bits/stdc++.h>
 
using namespace std;
 
int Z = 5;
enum {
  BOUNDARY = -2,
  OBSTACLE = -1,
  CLEAN = 0,
  PATH = 1,
  WEST = 2,
  SOUTH = 3,
  EAST = 4,
  NORTH = 5
};
 
using I = pair<int, char>;
I invalid{-1, 'G'};
I get_instruction(int m, int w, int s, int e, int n) {
  auto Adj = [&](int x) {
    return (w == x) + (s == x) + (e == x) + (n == x);
  };
  auto Next = [&]  {
    int start = (m >= WEST ? m - WEST + 1 : 0);
    for (int i = 0; i < 4; ++i) {
      int cur = WEST + (start + i) % 4;
      if (cur == WEST && w == EAST) {
        return I{WEST, 'W'};
      }
      if (cur == SOUTH && s == NORTH) {
        return I{SOUTH, 'S'};
      }
      if (cur == EAST && e == WEST) {
        return I{EAST, 'E'};
      }
      if (cur == NORTH && n == SOUTH) {
        return I{NORTH, 'N'};
      }
    }
    return invalid;
  };
  auto Next_and_explore = [&] {
    int start = (m >= WEST ? m - WEST + 1 : 0);
    for (int i = 0; i < 4; ++i) {
      int cur = WEST + (start + i) % 4;
      if (cur == WEST && (w == EAST || w == CLEAN)) {
        return I{WEST, 'W'};
      }
      if (cur == SOUTH && (s == NORTH || s == CLEAN)) {
        return I{SOUTH, 'S'};
      }
      if (cur == EAST && (e == WEST || e == CLEAN)) {
        return I{EAST, 'E'};
      }
      if (cur == NORTH && (n == SOUTH || n == CLEAN)) {
        return I{NORTH, 'N'};
      }
    }
    return invalid;
  };
  
  auto Clean = [&] {
    if (m == WEST) return I{CLEAN, 'W'};
    if (m == SOUTH) return I{CLEAN, 'S'};
    if (m == EAST) return I{CLEAN, 'E'};
    if (m == NORTH) return I{CLEAN, 'N'}; 
    return invalid;
  };
  auto Path = [&] {
    if (m == WEST) return I{PATH, 'W'};
    if (m == SOUTH) return I{PATH, 'S'};
    if (m == EAST) return I{PATH, 'E'};
    if (m == NORTH) return I{PATH, 'N'}; 
    return invalid;
  };
  
  auto Is_betrayal = [&] {
    if (m == WEST && w != EAST) return true;
    if (m == SOUTH && s != NORTH) return true;
    if (m == EAST && e != WEST) return true;
    if (m == NORTH && n != SOUTH) return true;
    return false;
  };
  
  if (m < 0) return invalid;
  // 0 0 
  if (n == BOUNDARY && w == BOUNDARY) {
    if (m == CLEAN) {
      if (s == CLEAN) {
        return {SOUTH, 'S'};
      }
      if (e == CLEAN) {
        return {EAST, 'E'};
      }
      return invalid;
    }
    if (Is_betrayal()) {
      auto n = Next();
      if (n == invalid) return Path();
      else {
        n.first = m;
        return n;
      }
    }
  }
  // N - 1 N - 1
  if (s == BOUNDARY && e == BOUNDARY) {
    if (m == CLEAN) {
      auto go = Next();
      if (go == invalid) return invalid;
      go.first = EAST; //betrayal
      return go;
    } else {
      return {PATH, 'T'};
    }
  }
  //newly explored
  if (m == CLEAN) {
    return Next();
  }
  
  //start cleaning and painting 
  if (Is_betrayal()) {
      auto n = Next();
      if (n == invalid) {
        if (Adj(PATH)) return Path();
        else return Clean();
      } else {
        n.first = m;
        return n;
      }
    }
  //explore 
  return Next_and_explore();
}
 
void program_pulibot() {
  for (int me = -2; me <= Z; ++me) {
    for (int w = -2; w <= Z; ++w) {
      for (int s = -2; s <= Z; ++s) {
        for (int e = -2; e <= Z; ++e) {
          for (int n = -2; n <= Z; ++n) {
            auto i = get_instruction(me, w, s, e, n);
            if (i != invalid) {
              set_instruction({me, w, s, e, n}, i.first, i.second);
            }
          }
        }
      }
    }
  }
}

