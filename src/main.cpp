#include <bits/stdc++.h>
using namespace std;
int main()
{
  // Flush after every cout / std:cerr
  cout << unitbuf;
  cerr << unitbuf;

  // Uncomment this block to pass the first stage
  while (1)
  {
    cout << "$ ";
    set<string> st;
    string input;
    getline(cin, input);
    if (!st.count(input))
    {
      cout << input << ": " << "not found" << endl;
    }
  }
}
