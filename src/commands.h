#include <iostream>
#include <vector>
#include <string>
int echo(std::vector<std::string> v)
{
    for (int i = 1; i < v.size(); i++)
    {
        std::cout << v[i] << ((i == v.size() - 1) ? "" : " ");
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
    if (v.size() > 2)
    {
        return 0;
    }
    std::cout << v[1] << " is a shell builtin" << std::endl;
    return 1;
}