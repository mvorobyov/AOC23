#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
    const map<string, size_t> digits_map = {{"zero",0},{"one",1},{"two",2},{"three",3},{"four",4},{"five",5},{"six",6},{"seven",7},{"eight",8},{"nine",9}};
    const auto digits = "0123456789";
    string line;
    auto sum = 0;
    while (!cin.eof())
    {
        cin >> line;
        auto first_pos = line.find_first_of(digits);
        auto first = line[first_pos] - '0';
        for_each(digits_map.cbegin(), digits_map.cend(), [&line, &first_pos, &first](const auto& digit_pair) mutable {
            const auto pos = line.find(digit_pair.first);
            if (pos < first_pos)
            {
                first_pos = pos;
                first = digit_pair.second;
            }
        });

        auto last_pos = line.find_last_of(digits);
        auto last = line[last_pos] - '0';
        for_each(digits_map.cbegin(), digits_map.cend(), [&line, &last_pos, &last](const auto& digit_pair) mutable {
            const auto pos = line.rfind(digit_pair.first);
            if (pos != string::npos && pos > last_pos)
            {
                last_pos = pos;
                last = digit_pair.second;
            }
        });

        sum += first * 10 + last;
    }
    cout << sum;
    return 0;
}
