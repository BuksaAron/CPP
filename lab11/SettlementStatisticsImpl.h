//
// Created by buksa on 11/26/2025.
//

#ifndef LAB11_SETTLEMENTSTATISTICSIMPL_H
#define LAB11_SETTLEMENTSTATISTICSIMPL_H

#include "SettlementStatistics.h"
#include <map>
#include <string>
using namespace std;
class SettlementStatisticsImpl : public SettlementStatistics {

    std::multimap<std::string, Settlement> data;

public:
    SettlementStatisticsImpl(const string& filename);

    int numSettlements() const override;
    int numCounties() const override;

    int numSettlementsByCounty(const string& county) const override;
    vector<Settlement> findSettlementsByCounty(const string& county) const override;

    Settlement findSettlementsByNameAndCounty(const string& name, const string& county) const override;

    Settlement maxPopulationBySettlement() const override;
    Settlement minPopulationBySettlement() const override;

    vector<Settlement> findSettlementsByName(const string& name) const override;
};


#endif //LAB11_SETTLEMENTSTATISTICSIMPL_H