#pragma once

#include "LogMessage.hpp"
#include "Singleton.hpp"
#include "ThreadPool.hpp"
#include "LogTask.hpp"

namespace dfs
{
    class Logger
    {
        public:
            Logger(const Logger &) = delete;
            Logger(Logger &&) = delete;
            Logger &operator=(const Logger &) = delete;
            Logger &operator=(Logger &&) = delete;

            Logger& Log(const LogMessage & msg_);
            Logger& SetLevel(LogLevel level_);

        private:
            Logger();
            ~Logger() = default;

            ThreadPool m_pool;
            LogLevel m_level;

            friend Singleton<Logger>;

    };
} 

