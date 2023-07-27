#pragma once

#include <string>

#include "LogLevel.hpp"

namespace dfs
{
    class LogMessage
    {
        public:

            LogMessage(const std::string& s_,  LogLevel level_);
            virtual ~LogMessage() = default;

            virtual std::string GetMessage() const;
            virtual LogLevel GetLogLevel() const;

        private: 
            const std::string m_string;
            LogLevel m_level;
            
    };
}

