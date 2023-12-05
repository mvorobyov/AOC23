#include <iostream>
#include <sstream>
#include <map>

using namespace std;

int main ()
{
    string line;
    auto sum = 0ULL;
    while (cin.good())
    {
        map<char,size_t> cubes = {{'r',0},{'g',0},{'b',0}};
        getline (cin, line);
        istringstream is(line);
        int id = 0;
        is >> line >> id >> line; // "Game 1:"
        while(is.good())
        {
            int num = 0;
            char color = 0;
            is >> num >> color >> line; // "1 green,"
            if (num > cubes[color])
            {
                cubes[color] = num;
            }
        }
        sum += cubes['r'] * cubes['g'] * cubes['b'];
    }
    
    cout << sum;
    return 0;
}
