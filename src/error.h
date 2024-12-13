#include <iostream>
#include <vector>
#include <string>
void error(std::vector<std::string> v)
{
    if (v[0] == "cd")
    {
        cout << "cd: " << v[1] << ": No such file or directory" << endl;
        return;
    }
    std::cout << v[0] << ": " << "not found" << std::endl;
}
