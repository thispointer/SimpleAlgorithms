#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() 
{
  int n = 0;
  cin >> n;  
  std::vector<unsigned long> numbers(n);
  
  for (int i = 0; i < n; ++i) 
  {
   cin >> numbers[i];
  }  
  sort(numbers.begin(), numbers.end(), std::greater<unsigned long>());
  unsigned long product =0; 
  product = numbers[0] * numbers[1];
  cout << product << "\n";

  return 0;
}