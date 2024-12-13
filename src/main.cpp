#include <bits/stdc++.h>
#include "command.h"
#include "commands.h"
#include "error.h"
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

  command *bash = new command();
  bash->addCommand("echo", echo);
  bash->addCommand("exit", myExit);
  bash->addCommand("type", type);
  bash->addCommand("pwd", pwd);
  while (1)
  {
    cout << "$ ";
    string input;
    getline(cin, input);
    vector<string> v = split(input);
    switch (bash->executeCommand(v))
    {
    case 0:
      error(v);
      break;
    }
  }
  return 0;
}