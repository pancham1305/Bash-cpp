#pragma once
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <iomanip>
using namespace std;
std::string unquote(const std::string &s)
{
    std::string result;
    std::istringstream ss(s);
    ss >> quoted(result);
    return result;
}

vector<string> trim(vector<string> v)
{
    vector<string> t;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == "")
        {
            continue;
        }
        t.push_back(v[i]);
    }
    return t;
}
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
            if (input[i] == '\'' || input[i] == '\"')
            {
                char c = input[i];
                s.push_back(input[i]);
                i++;
                while (i < n && input[i] != c)
                {
                    s.push_back(input[i]);
                    i++;
                }
                s.push_back(input[i]);
                v.push_back(s);
                s.clear();
            }
            else
            {
                // if (input[i] == '\\')
                // {
                //     if (input[i + 1] == ' ')
                //     {
                //         s.push_back('#');
                //         i++;
                //     }
                //     continue;
                // }
                s.push_back(input[i]);
            }
        }
    }
    if (!s.empty())
    {
        v.push_back(s);
    }
    return v;
}
