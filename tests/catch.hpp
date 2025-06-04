#ifndef SIMPLE_CATCH_HPP
#define SIMPLE_CATCH_HPP
#include <vector>
#include <functional>
#include <iostream>
#include <cstdlib>

struct Test {
    std::function<void()> func;
    const char* name;
};

inline std::vector<Test>& getTests() {
    static std::vector<Test> tests;
    return tests;
}

struct TestRegistrar {
    TestRegistrar(const char* name, std::function<void()> func) {
        getTests().push_back({func, name});
    }
};

#define TEST_CASE(name) \
    void name(); \
    static TestRegistrar registrar_##name(#name, name); \
    void name()

#define REQUIRE(expr) do { \
    if(!(expr)) { \
        std::cerr << "Requirement failed: " #expr << " in test " << __FUNCTION__ << std::endl; \
        std::exit(1); \
    } \
} while(0)

inline int runTests() {
    int count = 0;
    for(const auto& t : getTests()) {
        t.func();
        ++count;
    }
    std::cout << count << " tests passed" << std::endl;
    return 0;
}

#define CATCH_CONFIG_MAIN \
int main() { return runTests(); }

#endif // SIMPLE_CATCH_HPP
