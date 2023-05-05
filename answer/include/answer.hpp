#pragma once
#include <string>

namespace answer {
    namespace v1 {
        int expected_answer();
    }

    namespace v2 {
        std::string expected_answer();
    }

    using namespace v2;
    
}
