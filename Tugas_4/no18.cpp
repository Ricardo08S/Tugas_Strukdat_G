#include <iostream>
#include <stack>

using namespace std;
void sortStack(stack<int>& S1) {
  stack<int> S2;

  while (!S1.empty()) {
    int temp = S1.top();
    S1.pop();

    while (!S2.empty() && S2.top() > temp) {
      S1.push(S2.top());
      S2.pop();
    }

    S2.push(temp);
  }

  while (!S2.empty()) {
    S1.push(S2.top());
    S2.pop();
  }
}

int main() {
  stack<int> S1;

  S1.push(100);
  S1.push(5);
  S1.push(3);
  S1.push(8);
  S1.push(1);
  S1.push(2);

  sortStack(S1);

  while (!S1.empty()) {
    cout << S1.top() << " ";
    S1.pop();
  }
  cout << endl;

  return 0;
}
