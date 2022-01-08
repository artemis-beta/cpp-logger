#ifndef __LOGGER__
#define __LOGGER__

#include "cpplogger/global.hxx"
#include <iostream>
#include <string>
#include <sstream>

namespace cpplogger {

class Logger
{
    private:
        std::string logger_name_;
        Level log_level_;
        bool level_override_ = false;
        const std::string tag_ = "%s";
        void _global_out(const Level& type, const std::string& type_str, const std::string& logger_name_, const std::string& msg, const std::vector<std::string>& vars);
    public:
        explicit Logger( const std::string_view& name ) : logger_name_(name ) { log_level_ = global_logger_level_; };
        void Error( const std::string& msg, const std::vector<std::string>& );
        void Warning( const std::string& msg, const std::vector<std::string>& );
        void Info( const std::string& msg, const std::vector<std::string>& );
        void Debug( const std::string& msg, const std::vector<std::string>& );
        void Critical( const std::string& msg, const std::vector<std::string>& );
        void Fatal( const std::string& msg, const std::vector<std::string>& );
        void setLogLevel( const Level& level ) { log_level_ = level; level_override_ = true; }
        Level getLogLevel() const { return log_level_; }
};

};

#endif
