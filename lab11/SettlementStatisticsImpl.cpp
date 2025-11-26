//
// Created by buksa on 11/26/2025.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include "SettlementStatisticsImpl.h"

#include <algorithm>

#include "Settlement.h"

using namespace std;

SettlementStatisticsImpl::SettlementStatisticsImpl(const string &filename) {
    ifstream f(filename);
    if (!f) {
        throw runtime_error("File not found");
    }
    string line;
    getline(f, line);
    while (getline(f, line)) {
        if (line.empty()) continue;
        stringstream ss(line);
        string name, country, popStr;
        if (!getline(ss, name, ',') || !getline(ss, country, ',') || !getline(ss, popStr)) {
            continue;
        }
        int pop = std::stoi(popStr);
        data.insert({country, Settlement{name, country, pop}});
    }
}

int SettlementStatisticsImpl::numSettlements() const {
    return data.size();
}

int SettlementStatisticsImpl::numCounties() const {
    map<string, bool> countries;
    for (const auto& p : data) {
        countries[p.first] = true;
    }
    return countries.size();
}

int SettlementStatisticsImpl::numSettlementsByCounty(const string &county) const {
    return data.count(county);
}

vector<Settlement> SettlementStatisticsImpl::findSettlementsByCounty(const string &county) const {
    vector<Settlement> result;
    auto range = data.equal_range(county);
    for (auto it = range.first; it != range.second; ++it)
        result.push_back(it->second);

    return result;
}

Settlement SettlementStatisticsImpl::findSettlementsByNameAndCounty(const string &name, const string &county) const {
    auto range = data.equal_range(county);
    for (auto it = range.first; it != range.second; ++it) {
        if (it->second.GetName() == name)
            return it->second;
    }

    throw std::runtime_error("Settlement not found: " + name + " in " + county);
}

Settlement SettlementStatisticsImpl::maxPopulationBySettlement() const {
    if (data.empty())
        throw runtime_error("No settlements in database.");

    auto it = std::max_element(
        data.begin(),
        data.end(),
        [](const auto& a, const auto& b) {
            return a.second.GetPopulation() < b.second.GetPopulation();
        }
    );

    return it->second;
}

Settlement SettlementStatisticsImpl::minPopulationBySettlement() const {
    if (data.empty())
        throw runtime_error("No settlements in database.");

    auto it = std::min_element(
        data.begin(),
        data.end(),
        [](const auto& a, const auto& b) {
            return a.second.GetPopulation() < b.second.GetPopulation();
        }
    );

    return it->second;
}

vector<Settlement> SettlementStatisticsImpl::findSettlementsByName(const string &name) const {
    vector<Settlement> result;

    for (const auto& p : data)
        if (p.second.GetName() == name)
            result.push_back(p.second);

    return result;
}
