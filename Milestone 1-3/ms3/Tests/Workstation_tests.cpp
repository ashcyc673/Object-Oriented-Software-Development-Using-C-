#include "catch.hpp"
#include "../Workstation.h"

TEST_CASE("Testing Workstation module", "[Workstation]") {
    SECTION("Testing workstation custom constructor") {
        Utilities::setDelimiter(',');
        auto *workstation = new Workstation("CPU,123456,5,Central Processing Unit");
        REQUIRE(workstation->getNextStation() == nullptr);
        REQUIRE(workstation->getItemName() == "CPU");
        REQUIRE(workstation->checkDescription() == "Central Processing Unit");
        REQUIRE(workstation->checkCurrentSerialNumber() == 123456);
        REQUIRE(workstation->checkStockNumber() == 5);
        delete workstation;
    }

    SECTION("Testing add new customer order operator function") {
        Utilities::setDelimiter('|');
        auto *order = new CustomerOrder("Chris S.|Laptop|CPU|Memory");
        Utilities::setDelimiter(',');
        auto *firstStation = new Workstation("CPU,123456,5,Central Processing Unit");

        REQUIRE(firstStation->emptyOrders() == true);
        *firstStation += std::move(*order);
        REQUIRE(firstStation->emptyOrders() == false);

        delete order;
        delete firstStation;
    }

    SECTION("Testing workstation runProcess function") {
        Utilities::setDelimiter('|');
        auto *order = new CustomerOrder("Chris S.|Laptop|CPU");
        Utilities::setDelimiter(',');
        auto *workstation = new Workstation("CPU,123456,5,Central Processing Unit");

// Checking the completion of order before testing the run process
// This is needed to ensure all the data is correct
        auto *completedOrder = new CustomerOrder();
        REQUIRE(workstation->getIfCompleted(*completedOrder) == false);
        delete completedOrder;

// Testing run process function
        *workstation += std::move(*order);
        workstation->runProcess(std::cout);
        completedOrder = new CustomerOrder();
        REQUIRE(workstation->getIfCompleted(*completedOrder));
        delete completedOrder;

        delete order;
        delete workstation;
    }

    SECTION("Testing getIfCompleted function") {
        Utilities::setDelimiter('|');
        auto *order = new CustomerOrder("Chris S.|Laptop|CPU");
        Utilities::setDelimiter(',');
        auto *workstation = new Workstation("CPU,123456,5,Central Processing Unit");
        auto *completedOrder = new CustomerOrder();
        *workstation += std::move(*order);
        workstation->runProcess(std::cout);
        REQUIRE(workstation->getIfCompleted(*completedOrder) == true);
        delete completedOrder;
        delete order;
        delete workstation;
    }

    SECTION("Testing setNextStation and getNextStation function") {
        Utilities::setDelimiter(',');
        auto *firstStation = new Workstation("CPU,123456,5,Central Processing Unit");
        auto *secondStation = new Workstation("Memory,654321,10,Basic Flash Memory");
// Testing getNextStation function
        REQUIRE(firstStation->getNextStation() == nullptr);
        REQUIRE(secondStation->getNextStation() == nullptr);
// Testing setNextStation function
        firstStation->setNextStation(*secondStation);
        REQUIRE(firstStation->getNextStation() == secondStation);
        REQUIRE(secondStation->getNextStation() == nullptr);
        delete firstStation;
        delete secondStation;
    }

    SECTION("Testing moveOrder function") {
        Utilities::setDelimiter('|');
        auto *order = new CustomerOrder("Chris S.|Laptop|CPU|Memory|WiFi");
        Utilities::setDelimiter(',');
        auto *firstStation = new Workstation("CPU,123456,5,Central Processing Unit");
        auto *secondStation = new Workstation("Memory,654321,10,Basic Flash Memory");
        auto *thirdStation = new Workstation("GPU,56789,7,Graphic Processing Unit");
        auto *fourthStation = new Workstation("WiFi,887,5,Network Card with WiFi");

        *firstStation += std::move(*order);

        REQUIRE(firstStation->getNextStation() == nullptr);
        REQUIRE(secondStation->getNextStation() == nullptr);
        REQUIRE(thirdStation->getNextStation() == nullptr);
        firstStation->setNextStation(*secondStation);
        secondStation->setNextStation(*thirdStation);
        thirdStation->setNextStation(*fourthStation);
        REQUIRE(firstStation->moveOrder() == false);
        firstStation->runProcess(std::cout);
        REQUIRE(firstStation->moveOrder() == true);
        REQUIRE(secondStation->moveOrder() == false);
        secondStation->runProcess(std::cout);
        REQUIRE(secondStation->moveOrder() == true);
        auto *completedOrder = new CustomerOrder;
        REQUIRE(thirdStation->getIfCompleted(*completedOrder) == false);
        delete completedOrder;
        completedOrder = new CustomerOrder;
        REQUIRE(thirdStation->moveOrder() == true);
        fourthStation->runProcess(std::cout);
        REQUIRE_THROWS_AS(fourthStation->moveOrder(), std::string);
        REQUIRE(fourthStation->getIfCompleted(*completedOrder) == true);

        delete order;
        delete completedOrder;
        delete firstStation;
        delete secondStation;
        delete thirdStation;
        delete fourthStation;
    }
}