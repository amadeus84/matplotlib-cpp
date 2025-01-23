//
// g++ -std=c++20 -g -Wall -o span $(python-config --includes) span.cpp $(python-config --ldflags --embed)
//
#include "../matplotlibcpp.h"

#include <map>
#include <span>
#include <vector>

using namespace std;
namespace plt = matplotlibcpp;

int main()
{
    // C-style arrays with multiple rows
    time_t t[]={1, 2, 3, 4};
    int data[]={
	3, 1, 4, 5,
	5, 4, 1, 3,
	3, 3, 3, 3
    };

    // vector<double> xticks {1, 2, 3, 4};
    // vector<string> xlabels {"a", "b", "c", "d"};
    vector<double> xticks {1, 1.5, 2, 2.5, 3, 3.5, 4};
    vector<string> xlabels {"aaa", "bbb", "ccc", "ddd", "eee", "fff", "ggg"};

    // https://matplotlib.org/stable/api/text_api.html#matplotlib.text.Text
    map<string, string> kwargs {{"rotation", "45"},
				{"fontsize", "xx-large"},
				{"color", "m"}
    };

    plt::plot(span(t, 4), span(data, 12));
    // plt::xticks(xticks, xlabels);
    plt::xticks(xticks, xlabels, kwargs);
    plt::grid(true);
    plt::show();

    plt::detail::_interpreter::kill();

    return 0;
}
