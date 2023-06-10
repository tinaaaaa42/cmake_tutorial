#include "answer/answer.hpp"

#include <wolfram/alpha.hpp>

namespace answer {
    namespace v1 {
        int expected_answer() {
            return 42;
        }
    }
    
    namespace v2 {
        std::string expected_answer() {
            // use curl to get the answer from the internet
            return wolfram::simple_query(WOLFRAM_APIID, "What is the ultimate answer?");
        }
    }
}
