// map of commands to functions and also using class to make it modular
#include <string>
#include <functional>
#include <map>
#include <vector>

class command
{
private:
    std::map<std::string, std::function<int(std::vector<std::string>)>> mp;

public:
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
            if (c == "type" && mp.find(v[1]) == mp.end())
            {
                v.erase(v.begin());
                return 0;
            }
            int ret = f(v);
            return ret;
        }
        return 0;
    }
};