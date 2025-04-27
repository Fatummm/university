#include <exception>
#include <functional>
#include <optional>

template <typename Result, typename Exception = std::exception>
std::optional<Result> DoWithRetry(std::function<Result()> func,
    int retryCount, int sleepTime, bool throwLast) {
    for (int i = 0; i != retryCount + 1; ++i) {
        try {
            return func();
        } catch (Exception) {
            if (i == retryCount) {
                if (throwLast) throw;
            }
            else Sleep(sleepTime);
        }
    }
    return std::optional<Result>();
}