#pragma once

#include <mutex>
#include <queue>
#include <condition_variable>
#include <optional>

namespace logger {
    /// Минимальная потокобезопасная очередь (blocking pop).
    template <typename T>
    class ThreadSafeQueue {
        public:
            void push (T value) {
                {
                    std::lock_guard lk{m_};
                    q_.push(std::move(value));
                } cv_.notify_one();
            }

            /// Блокируется, пока не получит элемент.
            [[nodiscard]]
            T pop() {
                std::unique_lock lk{m_};
                cv_.wait(lk, [&]{ return !q_.empty(); });
                T val = std::move(q_.front());
                q_.pop();
                return val;
            }

            /// Немедленная попытка забрать элемент (non-blocking).
            [[nodiscard]]
            std::optional<T> try_pop() {
                std::lock_guard lk{m_};
                if (q_.empty()) return std::nullopt;
                T val = std::move(q_.front());
                q_.pop();
                return val;
            }

            [[nodiscard]]
            bool empty() const {
                std::lock_guard{m_};
                return q_.empty();
            }
        private:
            mutable std::mutex m_;
            std::queue<T> q_;
            std::condition_variable cv_;
    };

} // namespace logger 