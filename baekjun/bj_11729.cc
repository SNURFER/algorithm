#include <iostream>
using namespace std;

int countK(int N) {
  if (N == 1) return 1;
  return 2 * countK(N - 1) + 1;
}

int findMidStation(int start, int destination) {
  return (6 - start - destination);
}

void printPath(int N, int start, int destination) {
  if (N == 1) {
    cout << start << " " << destination << "\n";
    return ;
  }
  else {
    printPath(N - 1, start, findMidStation(start, destination));
    cout << start << " " << destination << "\n";
    printPath(N - 1, findMidStation(start, destination), destination);
    return ;
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  int N;
  cin >> N;
  cout << countK(N) << "\n";
  printPath(N, 1, 3);

  return 0;
}