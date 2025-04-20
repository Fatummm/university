#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cstdint>
#include <set>
#include <cmath>

#define ll long long
#define ull unsigned long long

//#define MAXFLOAT 10000000.0f

std::vector<std::string> split(std::string s, char delimiter) {
    std::vector<std::string> v;
    std::string tmp = "";
    for (int i = 0; i != s.size(); ++i) {
        if (s[i] == delimiter) {
            if (tmp != " " && tmp != "\n" && !tmp.empty()) v.push_back(tmp);
            tmp = "";
        }
        else tmp += s[i];
        if (i + 1 == s.size()) if (tmp != " " && tmp != "\n" && !tmp.empty()) v.push_back(tmp);
    }
    return v;
}

int main() {
    ll n; std::cin >> n;
    std::map<std::string, std::pair<ll, ll>> coords;
    std::map<std::string, std::vector<std::string>> neighbours;
    std::vector<std::string> all_cities;
    for (int i = 0; i != n; ++i) {
        std::string city, others; std::cin >> city;
        ll x, y; std::cin >> x >> y;
        coords.insert({city, {x, y}});
        getline(std::cin, others);
        std::vector<std::string> cities = split(others, ' ');
        all_cities.push_back(city);
        neighbours.insert({city, cities});
    }
    std::string from, to; std::cin >> from >> to;
    std::set<std::pair<double, std::string>> q;
    std::map<std::string, double> distance;
    std::map<std::string, std::string> predecessor;
    for (auto elem: all_cities) {
        distance[elem] = MAXFLOAT;
        predecessor[elem] = elem;
    }
    distance[from] = 0;
    q.insert({0, from});
    double eps = 0.0001f;
    while (!q.empty()) {
        std::string s = q.begin()->second;
        q.erase(q.begin());
        for (auto elem: neighbours[s]) {
            double r = sqrt(pow(coords[elem].first - coords[s].first, 2) + pow(coords[elem].second - coords[s].second, 2));
            if (distance[elem] - (distance[s] + r) > eps) {
                q.erase({distance[elem], elem});
                distance[elem] = distance[s] + r;
                predecessor[elem] = s;
                q.insert({distance[elem], elem});
            }
        }
    }
    if (predecessor[to] == to) {
        std::cout << "Path:\nNo way";
        return 0;
    }

    std::cout << "Path is not greater than " << ceil(distance[to]) << '\n';
    std::vector<std::string> ans;
    std::string tmp_city = to;
    ans.push_back(to);
    while (tmp_city != from) {
        tmp_city = predecessor[tmp_city];
        ans.push_back(tmp_city);
    }
    std::cout << "Path:\n";
    while (!ans.empty()) {
        std::cout << ans.back() << ' ';
        ans.pop_back();
    }

}