// map of commands to functions and also using class to make it modular
#include <string>
#include <functional>
#include <map>
#include <vector>
#include <filesystem>
#include <iostream>
#include <fstream>
using namespace std;
namespace fs = std::filesystem;
class command
{
private:
    std::map<std::string, std::function<int(std::vector<std::string>)>> shellBuiltins;
    std::map<string, string> externalCommands;
    std::string env = getenv("PATH");
    std::vector<std::string> envVars;

public:
    command()
    {
        char delimiter = ':';
        std::string s;
        for (int i = 0; i < env.size(); i++)
        {
            if (env[i] == delimiter)
            {
                envVars.push_back(s);
                s.clear();
            }
            else
            {
                s.push_back(env[i]);
            }
        }
        if (!s.empty())
        {
            envVars.push_back(s);
        }
        // for (auto i : envVars)
        // {
        //     cout << i << " ";
        // }
        // cout << endl;
        for (auto &path : envVars)
        {
            int cnt = 0;
            // cout << path << ": ";
            if (path.substr(0, 4) == "/tmp")
            {
                // cout << "Executing...." << endl;
                for (int i = 0; i < 10000000; i++)
                    ;
            }
            for (auto file : (fs::recursive_directory_iterator(path)))
            {
                string tmp = file.path().filename().string();
                cnt++;
                if (externalCommands.find(tmp) != externalCommands.end())
                {
                    continue;
                }
                externalCommands[tmp] = file.path().string();
                // if (path.substr(0, 4) == "/tmp")
                // {
                //     // cout << tmp << endl;
                //     string cmd = tmp + " alice";
                //     system(cmd.c_str());
                //     cout << (externalCommands.find(tmp) != externalCommands.end()) << endl;
                // }
            }

            // cout << cnt << endl;
        }
        // cout << externalCommands["cat"] << endl;
        // cout << endl;
        // for (auto i : externalCommands)
        // {
        //     cout << i.first << " ";
        // }
        // cout << endl;
    };
    void addCommand(std::string s, std::function<int(std::vector<std::string>)> f)
    {
        shellBuiltins[s] = f;
    }

    int executeCommand(std::vector<std::string> &v)
    {
        std::string c = v[0];
        // cout << c << endl;
        // if (externalCommands.find(c) != externalCommands.end())
        // {
        //     cout << ":')" << endl;
        // }
        // string s = "ls /tmp/pineapple";
        // system(s.c_str());
        if (c == "type")
        {
            if (shellBuiltins.find(v[1]) != shellBuiltins.end())
            {
                std::function<int(std::vector<std::string>)> f = shellBuiltins[c];
                v.erase(v.begin());
                return f(v);
            }
            else if (externalCommands.find(v[1]) != externalCommands.end())
            {
                cout << v[1] << " is " << externalCommands[v[1]] << endl;
                return 1;
            }
            v.erase(v.begin());
            return 0;
        }
        if (shellBuiltins.find(c) != shellBuiltins.end())
        {
            std::function<int(std::vector<std::string>)> f = shellBuiltins[c];

            int ret = f(v);
            return ret;
        }
        else if (externalCommands.find(c) != externalCommands.end())
        {

            string s;
            for (int i = 0; i < v.size(); i++)
            {
                s.append(v[i]);
                s.append(" ");
            }
            s.pop_back();
            system(s.c_str());
            return 1;
        }
        return 0;
    }
};