#include <bits/stdc++.h>
using namespace std;
int main()
{
  // Flush after every cout / std:cerr
  cout << unitbuf;
  cerr << unitbuf;

  // Uncomment this block to pass the first stage
  set<string> st;
  st.insert("exit 0");
  while (1)
  {
    cout << "$ ";
    string input;
    getline(cin, input);
    if (!st.count(input))
    {
      cout << input << ": " << "not found" << endl;
    }
    else
    {
      break;
    }
  }
}
