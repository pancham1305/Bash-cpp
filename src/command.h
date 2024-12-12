// map of commands to functions and also using class to make it modular
#include <string>
#include <functional>
#include <map>
#include <vector>
#include <filesystem>
#include <iostream>
using namespace std;
namespace fs = std::filesystem;
class command
{
private:
    std::map<std::string, std::function<int(std::vector<std::string>)>> mp;
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
        //     std::cout << i << " ";
        // }
        // cout << endl;
    };
    void addCommand(std::string s, std::function<int(std::vector<std::string>)> f)
    {
        mp[s] = f;
    }

    int executeCommand(std::vector<std::string> &v)
    {
        std::string c = v[0];
        if (mp.find(c) != mp.end())
        {
            std::function<int(std::vector<std::string>)> f = mp[c];
            if (c == "type")
            {
                if (mp.find(v[1]) != mp.end())
                {
                    v.erase(v.begin());
                    return f(v);
                }
                // The game begins
                for (auto &path : envVars)
                {
                    std::string s = path + "/" + v[1];
                    // cout << s << endl;
                    if (fs::is_regular_file(s))
                    {
                        v.clear();
                        v.push_back(v[1]);
                        v.push_back(s);
                        return f(v);
                    }
                }
                v.erase(v.begin());
                return 0;
            }
            int ret = f(v);
            return ret;
        }
        return 0;
    }
};