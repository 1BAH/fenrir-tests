#include <iostream>
#include <optional>
#include <print>
#include <cstdio>

extern std::optional<std::string> parseLog(const std::string &log);

template <typename T, typename CharT>
struct std::formatter<std::optional<T>, CharT> : std::formatter<T, CharT> {
    auto format(const std::optional<T> &opt, auto &ctx) const {
        if (opt) {
            return std::formatter<T, CharT>::format(
                std::format("std::optional[{}]", *opt),
                ctx
            );
        }
        return std::format_to(ctx.out(), "std::nullopt[]");
    }
};

void test(const std::string &input, const std::optional<std::string> &expected) {
    if (const auto real = parseLog(input); real != expected) {
        std::print(stderr, "Expected {} but got {}\n", expected, real);
        exit(1);
    }
}

int main() {
    std::cout << "== Running C++ tests ==\n";

    std::cout << "Empty string >> .." << std::flush;
    test("", std::nullopt);
    std::cout << " Done\n";

    std::cout << "Unquoted >> .." << std::flush;
    test("sn:qwe nm:qwe", std::nullopt);
    std::cout << " Done\n";

    std::cout << "SN-NM >> .." << std::flush;
    test(R"(sn:"1" nm:"2")", "2-1");
    std::cout << " Done\n";

    std::cout << "NM-SN >> .." << std::flush;
    test(R"(nm:"2" sn:"1")", "2-1");
    std::cout << " Done\n";

    std::cout << "SN-SN >> .." << std::flush;
    test(R"(sn:"1" sn:"2")", std::nullopt);
    std::cout << " Done\n";

    std::cout << "NM-NM >> .." << std::flush;
    test(R"(nm:"1" nm:"2")", std::nullopt);
    std::cout << " Done\n";

    std::cout << "Garbage >> .." << std::flush;
    test(R"(qwkb, asd;foa;kf sn:"1" aklsdfpqb;avisy234- nm:"2" al;ij;wb[an)", "2-1");
    std::cout << " Done\n";

    std::cout << "Empty value >> .." << std::flush;
    test(R"(sn:"" nm:"")", std::nullopt);
    test(R"(sn:"" nm:"a")", std::nullopt);
    test(R"(sn:"a" nm:"")", std::nullopt);
    std::cout << " Done\n";

    std::cout << "Non word chars >> .." << std::flush;
    test(R"(sn:"ё" nm:"q")", std::nullopt);
    test(R"(sn:"q" nm:"ё")", std::nullopt);
    std::cout << " Done\n";

    std::cout << "Quotes >> .." << std::flush;
    test(R"(nm:"2" " sn:"1")", "2-1");
    test(R"(nm:"2" " sn:"1" ")", "2-1");
    test(R"(sn:"1" " nm:"2")", "2-1");
    test(R"(sn:"1" " nm:"2" ")", "2-1");
    std::cout << " Done\n";

    std::cout << "Prefix >> .." << std::flush;
    test(R"(asn:"1" nm:"2")", std::nullopt);
    test(R"(sn:"1" anm:"2")", std::nullopt);
    test(R"(anm:"2" sn:"1")", std::nullopt);
    test(R"(nm:"2" asn:"1")", std::nullopt);
    std::cout << " Done\n";

    std::cout << "== COMPLETED ==\n";
    return 0;
}
