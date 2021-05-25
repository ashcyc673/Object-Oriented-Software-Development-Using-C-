#include "catch.hpp"
#include "../LineManager.h"

struct StationMapper {
    std::string station;
    Workstation *stationLocation;
};

std::vector<StationMapper> mapStations(const std::vector<Workstation *> stations) {
    std::vector<StationMapper> result;
    result.reserve(stations.size());
    for (auto station : stations) {
        result.push_back(StationMapper{station->getItemName(), station});
    }
    return result;
}

TEST_CASE("Testing LineManager module", "[LineManager]") {
    std::vector<Workstation *> AssemblyLine;
    std::vector<CustomerOrder> ToBeFilled;
    Utilities::setDelimiter(',');

    auto *firstStation = new Workstation("CPU,123456,5,Central Processing Unit");
    auto *secondStation = new Workstation("Memory,654321,10,Basic Flash Memory");
    auto *thirdStation = new Workstation("GPU,56789,7,Graphic Processing Unit");
    auto *fourthStation = new Workstation("WiFi,887,5,Network Card with WiFi");

    Utilities::setDelimiter('|');
    auto *fifthStation = new Workstation("SSD|987654|5|Solid State Drive");
    auto *sixthStation = new Workstation("Power Supply|147852|20|Basic AC Power Supply");
    auto *seventhStation = new Workstation("Monitor|987|5|Monitor size 32 inches, 4K");

    auto *customerOrder = new CustomerOrder("Chris S.|Laptop|CPU|Memory|SSD|Power Supply|WiFi");

    AssemblyLine.push_back(firstStation);
    AssemblyLine.push_back(secondStation);
    AssemblyLine.push_back(thirdStation);
    AssemblyLine.push_back(fourthStation);
    AssemblyLine.push_back(fifthStation);
    AssemblyLine.push_back(sixthStation);
    AssemblyLine.push_back(seventhStation);
    ToBeFilled.push_back(std::move(*customerOrder));

    SECTION("Testing mapStations function") {
        std::vector<StationMapper> mapper = mapStations(AssemblyLine);
        REQUIRE(mapper[0].station == "CPU");
        REQUIRE(mapper[0].stationLocation == firstStation);
        REQUIRE(mapper[1].station == "Memory");
        REQUIRE(mapper[1].stationLocation == secondStation);
        REQUIRE(mapper[2].station == "GPU");
        REQUIRE(mapper[2].stationLocation == thirdStation);
        REQUIRE(mapper[3].station == "WiFi");
        REQUIRE(mapper[3].stationLocation == fourthStation);
        REQUIRE(mapper[4].station == "SSD");
        REQUIRE(mapper[4].stationLocation == fifthStation);
        REQUIRE(mapper[5].station == "Power Supply");
        REQUIRE(mapper[5].stationLocation == sixthStation);
        REQUIRE(mapper[6].station == "Monitor");
        REQUIRE(mapper[6].stationLocation == seventhStation);
    }

    SECTION("Testing LineManager custom constructor") {
        Utilities::setDelimiter('|');
        auto *lineManager = new LineManager("AssemblyLine.txt", AssemblyLine, ToBeFilled);
// Testing the first station
        REQUIRE(lineManager->checkFirstStation() != nullptr);
        REQUIRE(lineManager->checkFirstStation()->getItemName() == "Power Supply");
        REQUIRE(lineManager->checkFirstStation() == sixthStation);

// Testing the linker
        const Workstation *next = lineManager->checkFirstStation();
        REQUIRE(next == sixthStation);
        next = next->getNextStation();
        REQUIRE(next == firstStation);
        next = next->getNextStation();
        REQUIRE(next == thirdStation);
        next = next->getNextStation();
        REQUIRE(next == secondStation);
        next = next->getNextStation();
        REQUIRE(next == fifthStation);
        next = next->getNextStation();
        REQUIRE(next == seventhStation);
        next = next->getNextStation();
        REQUIRE(next == fourthStation);
        next = next->getNextStation();
        REQUIRE(next == nullptr);
// Testing number of orders in the line
        REQUIRE(lineManager->checkOrderCounter() == 1);
// Testing number of workstations in the line
        REQUIRE(lineManager->checkStationCounter() == 7);
// Testing number of iteration
        REQUIRE(lineManager->checkIterationCounter() == 0);
// Testing number of completed orders
        REQUIRE(lineManager->checkCompletedOrderCounter() == 0);
        delete lineManager;
    }

    SECTION("Testing run function") {
        Utilities::setDelimiter('|');
        auto *lineManager = new LineManager("AssemblyLine.txt", AssemblyLine, ToBeFilled);
        while (!lineManager->run(std::cout));
// Testing number of orders in the line
        REQUIRE(lineManager->checkOrderCounter() == 0);
// Testing number of iteration
        REQUIRE(lineManager->checkIterationCounter() == 5);
// Testing number of completed orders
        REQUIRE(lineManager->checkCompletedOrderCounter() == 1);
        delete lineManager;
    }

    for (auto &iterator : AssemblyLine) {
        delete iterator;
    }
    delete customerOrder;
}