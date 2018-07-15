#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

using std::vector;

struct SortedVector {
  signed long value;

  SortedVector  (signed long v): value(v) {
  }

  SortedVector  (): value(0) {
  }

  bool operator < (const SortedVector & svItem) const {
    return (value < svItem.value);
  }

  bool operator > (const SortedVector & svItem) const {
    return (value > svItem.value);
  }

};

signed long get_optimal_value(int capacity, vector<SortedVector> profitPerClick, vector<SortedVector> avgClicks) {
  signed long totalValue = 0.0;

  std::sort (profitPerClick.begin(), profitPerClick.end(), std::greater<SortedVector>());
  std::sort (avgClicks.begin(), avgClicks.end(), std::greater<SortedVector>());

/*   std::cout << "--- sorted ---" << std::endl;
  for (int i = 0; i < profitPerClick.size(); ++i) {

      std::cout << i << ". " << "weight: " << profitPerClick[i].weight << " - " << "value: " << profitPerClick[i].value << " - v/w: " << std::setprecision (4) << std::fixed << profitPerClick[i].valuePerWeight << std::endl;
  } */
  
  for (unsigned long i = 0; i < capacity; ++i) {
    if (capacity == 0) {
      return totalValue;
    }
    else {
      totalValue +=  profitPerClick[i].value * avgClicks[i].value;
      // std::cout << i << ". " << "profitPerClick: " << profitPerClick[i].value << " - " << "avgClicks: " << avgClicks[i].value << " - cum. value " << totalValue << std::endl;
    }
    
  }

  return totalValue;
}

int main() {
  unsigned long n;
  signed long profit, clicks;

  std::cin >> n;

  vector<SortedVector> profitPerClick;
  vector<SortedVector> avgClicks;
  
  for (unsigned long i = 0; i < n; i++) {
    std::cin >> profit;
    profitPerClick.push_back (SortedVector(profit));
  }

  for (unsigned long i = 0; i < n; i++) {
    std::cin >> clicks;
    avgClicks.push_back (SortedVector(clicks));
  }

/* 
  std::cout << "n: " << n << std::endl;
  std::cout << "capacity rucksack: " << capacity << std::endl;

  for (int i = 0; i < profitPerClick.size(); ++i) {

    std::cout << i << ". " << "weight: " << profitPerClick[i].weight << " - " << "value: " << profitPerClick[i].value << " - v/w: " << std::setprecision (4) << std::fixed << profitPerClick[i].valuePerWeight << std::endl;
  }
 */
  signed long optimal_value = get_optimal_value(n, profitPerClick, avgClicks);

  std::cout << optimal_value << std::endl;

  return 0;
}