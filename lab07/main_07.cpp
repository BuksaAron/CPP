#include <algorithm>
#include <iostream>
#include <map>
#include <random>
#include <vector>

using namespace std;

int main() {
    cout << "EX1"<< endl;
    vector<string> fruits { "melon", "strawberry", "raspberry","apple", "banana", "walnut", "lemon" };
    string substring = "berry";
    auto it = find_if(fruits.begin(), fruits.end(), [substring](const string& fruit) {
        return fruit.find(substring) != string::npos;
    });
    if (it != fruits.end()) {
        cout << "Van olyan gyumolcs, ami tartalmazza a \"" << substring << "\" szot: "
             << *it << endl;
    } else {
        cout << "Nincs olyan gyümölcs, ami tartalmazza a \"" << substring << "\" szot." << endl;
    }

    cout << "EX.2" << endl;
    vector<int>numbers{1,2,3,4,5,6,7,8,9,10,11,42324,2545,5469};
    bool paros = all_of(numbers.begin(),numbers.end(),[](const int& nr)
    {return  nr%2 == 0;});
    if (paros) cout<<"Az osszes paros" << endl;
    else cout << "Van paratlan is" << endl;

    cout << "EX.3" << endl;
    numbers.clear();
    numbers = {1,2,3,4,5,6,7,8,9,10};
    vector<int>::iterator it2 = numbers.begin();
    for_each(numbers.begin(), numbers.end(), [&it2](const int& a) {
        *(it2++) = a * 2;
    });
    cout << "NUMBERS:" << endl;
    for (int i : numbers) {
        cout << i << " ";
    }
    cout << endl;

    cout << "EX.4" << endl;
    vector<string> months { "January", "February", "March", "April", "May", "June",  "July", "August", "September", "October", "November", "December" };
    int nr1 = 0;
    for_each(months.begin(), months.end(), [&nr1](const string &s) {
        if(s.size() == 5) nr1++;
    });
    cout << "5 betus honapok szama " << nr1 << endl;

    cout << "EX.5" << endl;
    numbers.clear();
    numbers = {1,9,4,7,3,9,8,11,10,32};
    cout << "A tomb alaphelyzete: " << endl;
    for (int i : numbers) {
        cout << i << " ";
    }
    cout << endl;
    sort(numbers.begin(), numbers.end(), [](int a, int b) {
        return a > b;
    });
    cout << "A tomb sort utan: " << endl;
    for (int i : numbers) {
        cout << i << " ";
    }
    cout << endl;
    random_device rd;
    default_random_engine gen(rd());
    shuffle(numbers.begin(), numbers.end(), gen);
    sort(numbers.begin(), numbers.end(), greater<int>());
    cout << "A tomb sort utan: " << endl;
    for (int i : numbers) {
        cout << i << " ";
    }
    cout << endl;

    cout << "EX.6:" << endl;
    vector<pair<string, double>> months2 = {
        {"Januar", -1.5},
        {"Februar", 0.0},
        {"Marcius", 5.5},
        {"Aprilis", 10.2},
        {"Majus", 15.8},
        {"Junius", 19.5},
        {"Julius", 22.3},
        {"Augusztus", 21.8},
        {"Szeptember", 17.0},
        {"Oktober", 11.2},
        {"November", 5.0},
        {"December", -0.8}
    };
    cout << "Eredeti homersekletek: " << endl;
    for (const pair<string, double> &p : months2) {
        cout << p.first << " - " << p.second << endl;;
    }
    sort(months2.begin(), months2.end(), [](const pair<string, double>& a, const pair<string, double>& b) {
        return a.second < b.second;
    });
    cout << "Rendezett homersekletek: " << endl;
    for (const pair<string, double> &p : months2) {
        cout << p.first << " - " << p.second << endl;;
    }

    cout << "EX.7" << endl;
    vector<double> num = {-1.2, 6.4, -11.8, 5.3, -2.0, -11.9, 5.9};
    cout << "Eredeti: " << endl;
    for (double i : num) {
        cout << i << " ";
    }
    sort(num.begin(), num.end(), [](const double &a, const double &b) {
        return abs(a) < abs(b);
    });
    cout << "Rendezett: " << endl;
    for (double i : num) {
        cout << i << " ";
    }

    cout << "EX.8" << endl;
    cout << "Honaplos tomb:" << endl;
    for (string &s: months) {
        cout << s << " ";
    }
    cout << endl;
    for_each(months.begin(), months.end(), [](string &s) {
        transform(s.begin(), s.end(), s.begin(), [](char c) {
            return tolower(c);
        });
    });
    cout << "Honaplos tomb kisbetukkel:" << endl;
    for (string &s: months) {
        cout << s << " ";
    }
    cout << endl;

    cout << "EX.9" << endl;
    vector<string> months5 = {
        "january", "february", "march", "april", "may", "june",
        "july", "august", "september", "october", "november", "december"
    };
    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    shuffle(alphabet.begin(), alphabet.end(), gen);
    cout << "Furcsa abc: " << alphabet << endl;
    pmr::map<char, int> rank;
    for (int i = 0; i < (int)alphabet.size(); ++i)
        rank[alphabet[i]] = i;
    sort(months5.begin(), months5.end(), [&](const string &a, const string &b) {
        for (size_t i = 0; i < min(a.size(), b.size()); ++i) {
            if (a[i] != b[i])
                return rank[a[i]] < rank[b[i]];
        }
        return a.size() < b.size();
    });
    cout << "Honapok a furcsa abece szerint rendezve: " << endl;;
    for (const auto& m : months5)
        cout << m << " ";
    cout << endl;

}