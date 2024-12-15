#include <bits/stdc++.h>
#include "command.h"
#include "commands.h"
#include "error.h"
#include "util.h"
using namespace std;

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
  bash->addCommand("cd", cd);
  while (1)
  {
    cout << "$ ";
    string input;
    getline(cin, input);
    vector<string> v = split(input);
    vector<string> t = trim(v);

    // for (auto i : t)
    // {
    //   cout << i << "|";
    // }
    // cout << endl;
    // cout << "Printing vector now::" << endl;
    switch (bash->executeCommand(t))
    {
    case 0:
      error(t);
      break;
    }
  }
  return 0;
}