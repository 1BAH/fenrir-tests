#include <iostream>
#include <vector>
#include <print>
#include <cstdio>

extern std::vector<std::string> getNumbers(const std::string &data);

template <typename T>
struct std::formatter<std::vector<T>> {
    constexpr auto parse(std::format_parse_context &ctx) {
        return ctx.begin();
    }

    auto format(const std::vector<T> &vec, std::format_context &ctx) const {
        auto out = std::format_to(ctx.out(), "[");
        for (size_t i = 0; i < vec.size(); ++i) {
            out = std::format_to(out, "{}{}", vec[i], (i + 1 < vec.size() ? ", " : ""));
        }
        return std::format_to(out, "]");
    }
};

std::string input_no_numbers = R"(
        123
        \w{100}
        
\t\u1234
        фываёлацз)";

std::string input_hard = R"(
        +380 80
        +23424
         +385555888333
        ++3333
        ++33333
        +45 333 333 +45 3333333 +45 33333333333333
        +7 7777777777
        +380999999999
        +381 999999999
        382 999999999
        ++387 123456789
        +49 12345678
        +33333333333 \
        
        8+391234567890=56
        8 + 391234567890 = 56
        )";

std::vector<std::string> numbers_hard = {
    "+385555888333",
    "+7 7777777777",
    "+380999999999",
    "+381 999999999",
    "+49 12345678",
    "+33333333333"
};

void test(const std::string &input, const std::vector<std::string> &expected) {
    if (const auto real = getNumbers(input); real != expected) {
        std::print(stderr, "Expected {} but got {}\n", expected, real);
        exit(1);
    }
    std::cout << " Done\n";
}

int main() {
    std::cout << "== Running C++ tests ==\n";

    std::cout << "Empty string >> .." << std::flush;
    test("", {});

    std::cout << "No valid numbers >> .." << std::flush;
    test(input_no_numbers, {});

    std::cout << "Stress test >> .." << std::flush;
    test(input_hard, numbers_hard);

    std::cout << "== COMPLETED ==\n";
    return 0;
}
