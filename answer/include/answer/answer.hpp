#pragma once

#include <string>

#include <wolfram/alpha.hpp>

// header-only lib contains all the implementation details

namespace answer {
    namespace v1 {
        int expected_answer() {
            return 42;
        }
    } // namespace v1

    namespace v2 {
        std::string expected_answer() {
            return wolfram::simple_query(WOLFRAM_APIID, "what is the ultimate answer?");
        }

        // Below are two fancy functions，using auto return type in C++14
        // if constexpr in C++17 and constraints in C++20

        namespace impl {
            template <typename T>
            auto to_string(T &&t) {
                if constexpr (requires { std::to_string(t); }) {
                    return std::to_string(std::forward<T>(t));
                } else if constexpr (requires { std::string(t); }) {
                    return std::string(std::forward<T>(t));
                }
            }
        } // namespace impl

        template <typename T, typename U>
        requires requires(T &&t, U &&u) {
            impl::to_string(std::forward<T>(t));
            impl::to_string(std::forward<U>(u));
        }
        auto check_the_answer(T &&given, U &&expected) {
            return impl::to_string(std::forward<T>(given)) == impl::to_string(std::forward<U>(expected));
        }
    } // namespace v2

    using namespace v2;
} // namespace answer
