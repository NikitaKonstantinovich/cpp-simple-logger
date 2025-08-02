#include "../include/logger/ThreadSafeQueue.hpp"
#include "../include/logger/LogMessage.hpp"
#include <cassert>

int main() {
    logger::ThreadSafeQueue<int> q;

    q.push(33);
    assert(q.try_pop().value() == 33);

    logger::LogMessage m{"hello"};
    assert(m.to_string().find("hello") != std::string::npos);

    return 0;
}