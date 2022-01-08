#include "cpplogger/global.hxx"

void cpplogger::setGlobalLogLevel( const std::string& level_str )
{ 
    if( level_str == "INFO" )
    {
        global_logger_level_ = cpplogger::Level::INFO;
    }
    else if( level_str == "DEBUG" )
    {
        global_logger_level_ = cpplogger::Level::DEBUG;
    }
    else if( level_str == "WARNING" )
    {
        global_logger_level_ = cpplogger::Level::WARNING;
    }
    else if( level_str == "ERROR" )
    {
        global_logger_level_ = cpplogger::Level::ERROR; 
    }
    else if( level_str == "FATAL" )
    {
        global_logger_level_ = cpplogger::Level::FATAL;
    }
    else if( level_str == "CRITICAL" )
    {
        global_logger_level_ = cpplogger::Level::CRITICAL;
    }
    else
    {
        std::cout << "Invalid logger level option '" << level_str << "'\n";
        std::cout << ". Using default." << std::endl;
    }
}

void cpplogger::setGlobalLogLevel( const Level& level ) {
    global_logger_level_ = level;
}
