#include <iostream>

using namespace std;

template <typename T>
T soma(T a, T b) {
  return a + b;
}

int main(int argc, char const *argv[])
{
  cout << soma(2, 3) << endl;
  cout << soma(1.5, 2.7) << endl;
  return 0;
}
