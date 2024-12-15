#include <iostream>
#include <vector>
#include <string>
#include <filesystem>
#include "util.h"
namespace fs = std::filesystem;
int echo(std::vector<std::string> v)
{
    for (int i = 1; i < v.size(); i++)
    {
        if (v[i][0] == '\'' || v[i][0] == '\"')
        {
            v[i].erase(v[i].begin());
            v[i].pop_back();
        }
        std::cout << (v[i]) << ((i == v.size() - 1) ? "" : " ");
    }
    std::cout << std::endl;
    return 1;
}

int myExit(std::vector<std::string> v)
{
    if (v.size() > 2)
    {
        return 0;
    }
    int code = stoi(v[1]);
    exit(code);
}

int type(std::vector<std::string> v)
{

    if (v.size() == 2)
    {
        std::cout << v[0] << " is " << v[1] << std::endl;
    }
    else if (v.size() == 1)
    {
        std::cout << v[0] << " is a shell builtin" << std::endl;
    }
    else
    {
        return 0;
    }
    return 1;
}

int pwd(vector<string> v)
{
    std::cout << fs::current_path().string() << std::endl;
    return 1;
}

int cd(vector<string> v)
{
    if (v[1][0] == '~')
    {
        string s = v[1].substr(1);
        string tmp = getenv("HOME");
        tmp.append(s);
        v[1] = tmp;
    }
    // std::cout << v[1] << std::endl;
    fs::path dir = v[1];
    fs::current_path(dir);
    return 1;
}