//
// Created by buksa on 11/26/2025.
//

#ifndef LAB11_SETTLEMENTSTATISTICS_H
#define LAB11_SETTLEMENTSTATISTICS_H

#include <string>
#include <vector>
#include "Settlement.h"

struct SettlementStatistics {

    virtual int numSettlements() const = 0;
    virtual int numCounties() const = 0;

    virtual int numSettlementsByCounty(const std::string& county) const = 0;
    virtual std::vector<Settlement> findSettlementsByCounty(const std::string& county) const = 0;

    virtual Settlement findSettlementsByNameAndCounty(
        const std::string& name, const std::string& county) const = 0;

    virtual Settlement maxPopulationBySettlement() const = 0;
    virtual Settlement minPopulationBySettlement() const = 0;

    virtual std::vector<Settlement> findSettlementsByName(const std::string& name) const = 0;

    virtual ~SettlementStatistics() = default;
};

#endif //LAB11_SETTLEMENTSTATISTICS_H