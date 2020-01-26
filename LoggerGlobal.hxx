#ifndef __GLOBALDEF__
#define __GLOBALDEF__

#include <string>
#include <iostream>

enum Level
{
    DEBUG,
    INFO,
    WARNING,
    ERROR,
    CRITICAL,
    FATAL
};

extern Level _global_logger_level;

void setLoggerLevel( std::string level_str );

#endif
