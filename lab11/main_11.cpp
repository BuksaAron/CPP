#include <iostream>
#include <vector>
#include "SettlementStatisticsImpl.h"

int main() {
        // 1. Adatbetöltés
        SettlementStatisticsImpl stats("telepulesek.csv");

        std::cout << "=== Telepules statisztikak ===\n\n";

        // 2. Összes település száma
        std::cout << "Telepulesek szama: "
                  << stats.numSettlements() << "\n";

        // 3. Megyék száma
        std::cout << "Megyek szama: "
                  << stats.numCounties() << "\n";

        // 4. Lekérdezés megyére
        std::string county = "AB";
        auto settlementsInCounty = stats.findSettlementsByCounty(county);

        std::cout << "\nTelepulesek " << county << " megyeben ("
                  << stats.numSettlementsByCounty(county) << " db):\n";

        for (const auto& s : settlementsInCounty) {
            std::cout << "  - " << s << "\n";
        }

        // 5. Lekérdezés név + megye szerint
        std::string name = "Plaiuri";
        try {
            auto bp = stats.findSettlementsByNameAndCounty(name, county);
            std::cout << "\nKereses nev es megye alapjan: "
                      << bp << "\n";
        } catch (const std::exception& ex) {
            std::cout << "\nNincs talalat " << name
                      << " (" << county << ")\n";
        }

        // 6. Maximális népességű település
        auto maxPop = stats.maxPopulationBySettlement();
        std::cout << "\nLegnagyobb nepessegu telepules:\n"
                  << "  " << maxPop << "\n";

        // 7. Minimális népességű település
        auto minPop = stats.minPopulationBySettlement();
        std::cout << "\nLegkisebb nepessegu telepules:\n"
                  << "  " << minPop << "\n";

        // 8. Keresés csak név alapján
        std::string searchName = "Plaiuri";
        auto foundByName = stats.findSettlementsByName(searchName);

        std::cout << "\nKereses nev alapjan (" << searchName << "):\n";
        if (foundByName.empty()) {
            std::cout << "  Nincs talalat.\n";
        } else {
            for (const auto& s : foundByName) {
                std::cout << "  - " << s << "\n";
            }
        }

        std::cout << "\n=== Program vege ===\n";

    return 0;
}