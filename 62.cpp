#include <bits/stdc++.h>

using namespace std;
#define endl '\n'

bool sol = false;

bool line(vector<vector<int>> &vl, int &x, int &y) { // 直行橫列判定
  int tar = vl[x][y];
  for (int k = 0; k < 9; k++) {
    if (k != x) {
      if (vl[k][y] == tar) {
        return false;
      }
    }
    if (k != y) {
      if (vl[x][k] == tar) {
        return false;
      }
    }
  }
  return true;
}

bool block(vector<vector<int>> &vb, int &x, int &y) {
  int tar = vb[x][y], strx = (x / 3) * 3, stry = (x / 3) * 3;
  for (int i = strx; i < strx + 3; i++) {
    for (int j = stry; j < stry + 3; i++) {
      if (i != x && j != y) {
        if (vb[i][j] == tar) {
          return false;
        }
      }
    }
  }
  return true;
}

void mege(vector<vector<int>> &vm, vector<pair<int, int>> &dot, int num) {
  if (num == dot.size()) {
    sol = true;
    for (auto &a : vm) {
      for (auto &b : a) {
        cout << b;
      }
    }
    return;
  } else if (num == 0) {
    sol = false;
    for (int i = 1; i <= 9; i++) {
      vm[dot[num].first][dot[num].second] = i;
      if (line(vm, dot[num].first, dot[num].second) &&
          block(vm, dot[num].first, dot[num].second)) {
        mege(vm, dot, num + 1);
      }
    }
    if (!sol) {
      cout << "No solution.";
      return;
    }
  } else {
    for (int i = 1; i <= 9; i++) {
      vm[dot[num].first][dot[num].second] = i;
      if (line(vm, dot[num].first, dot[num].second) &&
          block(vm, dot[num].first, dot[num].second)) {
        mege(vm, dot, num + 1);
      }
    }
  }
}

int main() {
  int n;
  cin >> n;
  while (n--) {
    // 宣告儲存
    vector<vector<int>> v(9, vector<int>(9));
    vector<pair<int, int>> dot;
    string s;
    cin >> s;
    int index = 0; // 存入字串之地幾項
    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
        if (s[index] != '.') {
          v[i][j] = s[index] - '0';
        } else {
          v[i][j] = -1;
          dot.push_back(make_pair(i, j));
        }
        index++;
      }
    }
    // 宣告儲存
    mege(v, dot, 0);
  }
}
