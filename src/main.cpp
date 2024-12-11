#include <bits/stdc++.h>
using namespace std;

vector<string> split(string input)
{
  vector<string> v;
  string s;
  int n = input.size();
  for (int i = 0; i < n; i++)
  {
    if (input[i] == ' ')
    {
      v.push_back(s);
      s.clear();
    }
    else
    {
      s.push_back(input[i]);
    }
  }
  if (!s.empty())
  {
    v.push_back(s);
  }
  return v;
}

int main()
{
  // Flush after every cout / std:cerr
  cout << unitbuf;
  cerr << unitbuf;

  // Uncomment this block to pass the first stage
  set<string> st;
  st.insert("exit");
  st.insert("echo");
  while (1)
  {
    cout << "$ ";
    string input;
    getline(cin, input);
    vector<string> v = split(input);
    if (!st.count(v[0]))
    {
      cout << input << ": " << "not found" << endl;
    }
    else if (v[0] == "echo")
    {
      for (int i = 1; i < v.size(); i++)
      {
        cout << v[i] << ((i == v.size() - 1) ? "" : " ");
      }
      cout << endl;
    }
    else
    {
      break;
    }
    // else
    // {
    //   break;
    // }
  }
}
