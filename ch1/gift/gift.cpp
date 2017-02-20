/*
ID: adiecha1
PROG: gift
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;


void update_balance(string, int);

int n, balance[200];
char names[200][200];


int main() {          
    
    int amount, amount_individual, rem, p;
    string name, opp;

    ofstream fout ("gift.out");
    ifstream fin ("gift.in");

    fin >> n;

    for (int i = 0; i < n; ++i)
    {
      fin >> names[i];
      balance[i] = 0;
    }

    for (int i = 0; i < n; ++i)
    {
      fin >> name;
      fin >> amount >> p;

      rem = amount % p;

      cout << name;
      printf(" %d (%d)\n", amount, p);
      amount_individual = (amount - rem) / p;

      for (int j = 0; j < p; ++j)
      {
        fin >> opp;
        cout << " - " << opp << "\n";
        update_balance(opp, amount_individual);
      }

      update_balance(name, -1 * amount);
      update_balance(name, rem);

    }

    for (int i = 0; i < n; ++i)
    {
      fout << names[i] << " " << balance[i] << "\n";
    }

    return 0;
}

void update_balance(string name, int amount) {
  
  int i;
  
  for (i = 0; i < n; ++i) if(name == names[i]) break;

  cout << "index -- " << i << "\n";
  balance[i] += amount;
}
