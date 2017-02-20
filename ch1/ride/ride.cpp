/*
ID: adiecha1
PROG: ride
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int get_processed_ans(string);

int main() {
    string first, second;
    int f = 1, s = 1;

    ofstream fout ("ride.out");
    ifstream fin ("ride.in");

    fin >> first;
    fin >> second;

    f = get_processed_ans(first);
    s = get_processed_ans(second);

    fout << (f == s? "GO": "STAY") << endl;
    return 0;
}

int get_processed_ans(string str) {
  char val;
  int mul = 1;
  for (int i = 0; i < str.length(); ++i) {
    val = str.at(i);
    if(val >= 'A' && val <= 'Z') {
      mul *= (val - 'A' + 1);
      mul %= 47;
    }
  }
  return mul;
}