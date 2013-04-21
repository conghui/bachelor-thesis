#include <iostream>
#include <sstream>
#include <cstdlib>
#include <cmath>
#include <string>

using namespace std;

int main()
{
  float in;
  string buffer;

  while (getline(cin, buffer)) {
    istringstream iss(buffer);
    int cnt = 0;
    while (iss >> in) {
      if (cnt++ > 0) {
        cout << log2(in) << '\t';
      }
      else {
        cout << in << '\t';
      }
    }
    cout << endl;
  }

  return 0;
}

