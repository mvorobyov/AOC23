#include <iostream>
#include <algorithm>
#include <sstream>
#include <list>
#include <iterator>

using namespace std;

int main()
{
    const string digits = "0123456789";
    auto sum = 0ULL;
    list<string> lines;
    while (cin.good())
    {
        string line;
        cin >> line;
        lines.push_back(line);
    }
    copy(lines.cbegin(), lines.cend(), ostream_iterator<string>(cout, "\n"));
    auto it = lines.cbegin();
    while(it != lines.cend())
    {
        string line(*it);
        replace_if(line.begin(), line.end(), [&digits](const auto ch){ return digits.find_first_of(ch) == string::npos; }, ' ');
        cout << line << endl;

        istringstream is(line);
        while(is.good())
        {
            int n = 0;
            is >> n;
            cout << n << &endl;
        }
        
        ++it;
    }
    return 0;
}
