// catch.hpp (minimal version of Catch2)
#ifndef CATCH_HPP_INCLUDED
#define CATCH_HPP_INCLUDED

#include <iostream>
#include <string>
#include <stdexcept>
#include <functional>
#include <vector>

namespace Catch {

    // Basic mechanism for test cases
    struct TestCase {
        std::string name;
        std::function<void()> func;
    };

    std::vector<TestCase>& getTestCases() {
        static std::vector<TestCase> testCases;
        return testCases;
    }

    void addTestCase(const std::string& name, std::function<void()> func) {
        getTestCases().push_back({ name, func });
    }

    void runTests() {
        for (const auto& testCase : getTestCases()) {
            try {
                testCase.func();
                std::cout << "[PASSED] " << testCase.name << std::endl;
            } catch (const std::exception& e) {
                std::cout << "[FAILED] " << testCase.name << " - " << e.what() << std::endl;
            }
        }
    }

} // namespace Catch

#define TEST_CASE(name) \
    static void test_case_##name(); \
    struct RegisterTestCase_##name { \
        RegisterTestCase_##name() { Catch::addTestCase(#name, test_case_##name); } \
    } registerTestCase_##name; \
    static void test_case_##name()

#define REQUIRE(condition) \
    if (!(condition)) throw std::runtime_error("Test failed: " #condition);

#define REQUIRE_FALSE(condition) \
    if (condition) throw std::runtime_error("Test failed: " #condition " is true");

#endif // CATCH_HPP_INCLUDED
