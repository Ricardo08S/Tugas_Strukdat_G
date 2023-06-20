#include <iostream>
#include <stack>

using namespace std;
void sortStack(stack<int>& stack1) {
  stack<int> st_tmp;

  while (!stack1.empty()) {
    int temp = stack1.top();
    stack1.pop();

    while (!st_tmp.empty() && st_tmp.top() > temp) {
      stack1.push(st_tmp.top());
      st_tmp.pop();
    }

    st_tmp.push(temp);
  }

  while (!st_tmp.empty()) {
    stack1.push(st_tmp.top());
    st_tmp.pop();
  }
}

int main() {
  stack<int> stack1;

  stack1.push(100);
  stack1.push(190);
  stack1.push(5);
  stack1.push(3);
  stack1.push(8);
  stack1.push(1);
  stack1.push(2);

  sortStack(stack1);

  while (!stack1.empty()) {
    cout << stack1.top() << " ";
    stack1.pop();
  }
  cout << endl;

  return 0;
}
