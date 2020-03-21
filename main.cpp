#include <iostream>
#include <set>

using namespace std;

int *find_diff(int *a, int a_size, int *b, int b_size, int *size);

int main() {
  int arr1[] = { 1, 2, 3, 4, 5 };
  int arr2[] = { 4, 5, 6, 7, 8 };

  int arr1_size = sizeof(arr1) / sizeof(int);
  int arr2_size = sizeof(arr2) / sizeof(int);

  int *size = new int;

  int * result = find_diff(arr1, arr1_size, arr2, arr2_size, size);

  for (int i = 0; i < *size; i++) {
    cout << result[i] << " ";
  }

  cout << endl;

  delete result;
  return 0;
}

int *find_diff(int a[], int a_size, int b[], int b_size, int *size) {
  set<int> final_set;

  for (int i = 0; i < a_size; i++) {
    final_set.insert(a[i]);
  }

  for (int i = 0; i < b_size; i++) {
    if (final_set.find(b[i]) == final_set.end()) {
      final_set.insert(b[i]);
    } else {
      final_set.erase(b[i]);
    }
  }

  set<int>::iterator it = final_set.begin();
  int *result = new int[final_set.size()];
  *size = final_set.size();

  for (int i = 0; it != final_set.end(); it++) {
    result[i++] = *it;
  }

  return result;
}
