#include "catch.hpp"
#include "../CustomerOrder.h"

TEST_CASE("Testing CustomerOrder module", "[CustomerOrder]") {
    Utilities::setDelimiter('|');

    SECTION("Testing default constructor") {
        auto *orderEmpty = new CustomerOrder();
        REQUIRE(orderEmpty->checkCustomerName().empty());
        REQUIRE(orderEmpty->checkProductName().empty());
        REQUIRE(orderEmpty->checkItemCounter() == 0);
        REQUIRE(orderEmpty->checkItemList() == nullptr);
        delete orderEmpty;
    }

    SECTION("Testing exception of copy constructor") {
        auto *orderWithData = new CustomerOrder("Chris S.|Laptop|CPU|Memory|SSD|Power Supply|WiFi");
        REQUIRE_THROWS_AS(CustomerOrder(*orderWithData), std::string);
        delete orderWithData;
    }

    SECTION("Testing custom constructor") {
        auto *orderWithData = new CustomerOrder("Chris S.|Laptop|CPU|Memory|SSD|Power Supply|WiFi");
        REQUIRE(orderWithData->checkCustomerName() == "Chris S.");
        REQUIRE(orderWithData->checkProductName() == "Laptop");
        REQUIRE(orderWithData->checkItemCounter() == 5);
        REQUIRE(orderWithData->checkItemList() != nullptr);
        Item **TEST_LIST = orderWithData->checkItemList();
        for (size_t cnt = 0u; cnt < 5; ++cnt) {
            REQUIRE(TEST_LIST[cnt]->m_isFilled == false);
            REQUIRE(TEST_LIST[cnt]->m_serialNumber == 0);
        }
        REQUIRE(TEST_LIST[0]->m_itemName == "CPU");
        REQUIRE(TEST_LIST[1]->m_itemName == "Memory");
        REQUIRE(TEST_LIST[2]->m_itemName == "SSD");
        REQUIRE(TEST_LIST[3]->m_itemName == "Power Supply");
        REQUIRE(TEST_LIST[4]->m_itemName == "WiFi");
        delete orderWithData;
    }

    SECTION("Testing move constructor") {
        auto *firstOrder = new CustomerOrder("Chris S.|Laptop|CPU|Memory|SSD|Power Supply|WiFi");
        auto *secondOrder = new CustomerOrder(std::move(*firstOrder));
        Item **TEST_LIST = secondOrder->checkItemList();
        for (size_t cnt = 0u; cnt < 5; ++cnt) {
            REQUIRE(!TEST_LIST[cnt]->m_isFilled);
            REQUIRE(!TEST_LIST[cnt]->m_serialNumber);
        }
        REQUIRE(TEST_LIST[0]->m_itemName == "CPU");
        REQUIRE(TEST_LIST[1]->m_itemName == "Memory");
        REQUIRE(TEST_LIST[2]->m_itemName == "SSD");
        REQUIRE(TEST_LIST[3]->m_itemName == "Power Supply");
        REQUIRE(TEST_LIST[4]->m_itemName == "WiFi");

        REQUIRE(secondOrder->checkCustomerName() == "Chris S.");
        REQUIRE(secondOrder->checkProductName() == "Laptop");
        REQUIRE(secondOrder->checkItemCounter() == 5);
        REQUIRE(secondOrder->checkItemList() != nullptr);

        REQUIRE(firstOrder->checkCustomerName().empty());
        REQUIRE(firstOrder->checkProductName().empty());
        REQUIRE(firstOrder->checkItemCounter() == 0);
        REQUIRE(firstOrder->checkItemList() == nullptr);

        delete firstOrder;
        delete secondOrder;
    }

    SECTION("Testing move operator") {
        auto *firstOrder = new CustomerOrder("Chris S.|Laptop|CPU|Memory|SSD|Power Supply|WiFi");
        auto *secondOrder = new CustomerOrder("Chris T.|Micro Controller|GPU|WiFi|GPU|Power Supply|SSD");
        *secondOrder = std::move(*firstOrder);
        Item **TEST_LIST = secondOrder->checkItemList();
        for (size_t cnt = 0u; cnt < 5; ++cnt) {
            REQUIRE(!TEST_LIST[cnt]->m_isFilled);
            REQUIRE(!TEST_LIST[cnt]->m_serialNumber);
        }
        REQUIRE(TEST_LIST[0]->m_itemName == "CPU");
        REQUIRE(TEST_LIST[1]->m_itemName == "Memory");
        REQUIRE(TEST_LIST[2]->m_itemName == "SSD");
        REQUIRE(TEST_LIST[3]->m_itemName == "Power Supply");
        REQUIRE(TEST_LIST[4]->m_itemName == "WiFi");

        REQUIRE(secondOrder->checkCustomerName() == "Chris S.");
        REQUIRE(secondOrder->checkProductName() == "Laptop");
        REQUIRE(secondOrder->checkItemCounter() == 5);
        REQUIRE(secondOrder->checkItemList() != nullptr);

        REQUIRE(firstOrder->checkCustomerName().empty());
        REQUIRE(firstOrder->checkProductName().empty());
        REQUIRE(firstOrder->checkItemCounter() == 0);
        REQUIRE(firstOrder->checkItemList() == nullptr);

        delete firstOrder;
        delete secondOrder;
    }

    SECTION("Testing isOrderFilled function") {
        auto *customerOrder = new CustomerOrder("Chris S.|Laptop|CPU|Memory|SSD|Power Supply|WiFi");
        Item **TEST_LIST = customerOrder->checkItemList();
        for (size_t cnt = 0u; cnt < 5; ++cnt) {
            TEST_LIST[cnt]->m_isFilled = true;
        }
        REQUIRE(customerOrder->isOrderFilled());
        delete customerOrder;
    }

    SECTION("Testing isItemFilled function") {
        auto *customerOrder = new CustomerOrder("Chris S.|Laptop|CPU|Memory|SSD|Power Supply|WiFi");
        REQUIRE(!customerOrder->isItemFilled("CPU"));
        Item **TEST_LIST = customerOrder->checkItemList();
        for (size_t cnt = 0u; cnt < 5; ++cnt) {
            TEST_LIST[cnt]->m_isFilled = true;
        }
        REQUIRE(customerOrder->isItemFilled("CPU"));
        delete customerOrder;
    }

    SECTION("Testing fillItem function") {
        Utilities::setDelimiter('|');
        auto *customerOrder = new CustomerOrder("Chris S.|Laptop|CPU|Memory|SSD|Power Supply|WiFi");
        Utilities::setDelimiter(',');
        auto *station = new Station("CPU,123456,5,Central Processing Unit");
        customerOrder->fillItem(*station, std::cout);
        REQUIRE(customerOrder->isItemFilled("CPU"));
        delete customerOrder;
        delete station;
    }
}