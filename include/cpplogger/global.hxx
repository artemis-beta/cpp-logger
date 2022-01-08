#ifndef __GLOBALDEF__
#define __GLOBALDEF__

#include <string>
#include <iostream>
#include <vector>


namespace cpplogger {

enum class Level {
    DEBUG,
    INFO,
    WARNING,
    ERROR,
    CRITICAL,
    FATAL
};

inline Level global_logger_level_ = cpplogger::Level::WARNING;

void setGlobalLogLevel( const std::string& level_str );
void setGlobalLogLevel( const Level& level );

};

#endif
