#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

using std::vector;

struct KnapsackItem {
  int value;
  int weight;
  double valuePerWeight;

  KnapsackItem (int v, int w): value(v), weight(w) {
      valuePerWeight = double(v)/double(w);
  }

  KnapsackItem (): value(0), weight(0), valuePerWeight(0.0) {
  }

  bool operator < (const KnapsackItem& ksItem) const {
    return (valuePerWeight < ksItem.valuePerWeight);
  }

  bool operator > (const KnapsackItem& ksItem) const {
    return (valuePerWeight > ksItem.valuePerWeight);
  }

};

double get_optimal_value(int capacity, vector<KnapsackItem> knapsack) {
  double totalValue = 0.0;

  std::sort (knapsack.begin(), knapsack.end(), std::greater<KnapsackItem>());

/*   std::cout << "--- sorted ---" << std::endl;
  for (int i = 0; i < knapsack.size(); ++i) {

      std::cout << i << ". " << "weight: " << knapsack[i].weight << " - " << "value: " << knapsack[i].value << " - v/w: " << std::setprecision (4) << std::fixed << knapsack[i].valuePerWeight << std::endl;
  } */
  
  for (int i = 0; i < knapsack.size(); ++i) {
    if (capacity == 0) {
      return totalValue;
    }
    else {
      int whatToTake = std::min (knapsack[i].weight, capacity);
      capacity -= whatToTake;
      totalValue += whatToTake * knapsack[i].valuePerWeight;
    }
    
  }

  return totalValue;
}

int main() {
  int n;
  int capacity;
  int value, weight;

  std::cin >> n >> capacity;

  vector<KnapsackItem> knapsack;
  
  for (int i = 0; i < n; i++) {
    std::cin >> value >> weight;
    knapsack.push_back (KnapsackItem(value, weight));
  }

/* 
  std::cout << "n: " << n << std::endl;
  std::cout << "capacity rucksack: " << capacity << std::endl;

  for (int i = 0; i < knapsack.size(); ++i) {

    std::cout << i << ". " << "weight: " << knapsack[i].weight << " - " << "value: " << knapsack[i].value << " - v/w: " << std::setprecision (4) << std::fixed << knapsack[i].valuePerWeight << std::endl;
  }
 */
  double optimal_value = get_optimal_value(capacity, knapsack);

  std::cout.precision(4);
  std::cout << std::setprecision (4) << std::fixed << optimal_value << std::endl;
  return 0;
}