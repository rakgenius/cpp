#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int find_itinerary(unordered_map <string, string> fromTo)
{
    unordered_map <string, string> toFrom;
    string start;

    unordered_map <string, string>:: iterator it;

    for (it = fromTo.begin(); it != fromTo.end(); it++) {
        toFrom[it->second] = it->first;
    }

    for (it = fromTo.begin(); it != fromTo.end(); it++) {
        if (toFrom.find(it->first) == toFrom.end()) {
            start = it->first;
            break;
        }
    }

    if (start.empty()) {
        cout << "Invalid ticket" << endl;
        return 0;
    }

    it = fromTo.find(start);
    while (it != fromTo.end()) {
        cout << it->first << "->" << it->second << endl;
        it = fromTo.find(it->second);
    }
    return 1;
}

int main()
{
    unordered_map <string, string> from;
    from["Chennai"] = "Bangalore";
    from["Bombay"] = "Delhi";
    from["Goa"] = "Chennai";
    from["Delhi"] = "Goa";

    find_itinerary(from);
    return 0;
}
