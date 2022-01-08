#include "cpplogger/logger.hxx"

void cpplogger::Logger::_global_out(const Level& type, const std::string& type_str, const std::string& logger_name, const std::string& msg, const std::vector<std::string>& vars)
{
    // If user has not manually set level for this logger, update
    // to global log level before printing (in case it has been changed)
    if(!level_override_) {
        log_level_ = global_logger_level_;
    }

    int n_filled_ = 0;

    std::string out_msg_ = msg;

    size_t tag_found_ = msg.find(tag_);

    while(tag_found_ != std::string::npos) {
        if(n_filled_ > vars.size()) {
            throw std::invalid_argument("Number of std::vector<std::string> does not match number of tags in log statement");
        }
        out_msg_.replace(tag_found_, tag_.size(), vars[n_filled_]);
        n_filled_ += 1;
        tag_found_ = msg.find(tag_, tag_found_+1);
    }
    
    if( type >= log_level_ )
    {
        std::cout << logger_name;
        std::cout << ":\t" << type_str << ":\t";
        std::cout << out_msg_ << std::endl;
    }
}

void cpplogger::Logger::Error( const std::string& msg, const std::vector<std::string>& vars )
{
    _global_out( cpplogger::Level::ERROR, "ERROR", logger_name_, msg, vars );
}

void cpplogger::Logger::Warning( const std::string& msg, const std::vector<std::string>& vars )
{
    _global_out( cpplogger::Level::WARNING, "WARNING", logger_name_, msg, vars );
}

void cpplogger::Logger::Info( const std::string& msg, const std::vector<std::string>& vars )
{
    _global_out( cpplogger::Level::INFO, "INFO", logger_name_, msg, vars );
}

void cpplogger::Logger::Critical( const std::string& msg, const std::vector<std::string>& vars )
{
    _global_out( cpplogger::Level::CRITICAL, "CRITICAL", logger_name_, msg, vars );
}

void cpplogger::Logger::Fatal( const std::string& msg, const std::vector<std::string>& vars )
{
    _global_out( cpplogger::Level::FATAL, "FATAL", logger_name_, msg, vars );
}

void cpplogger::Logger::Debug( const std::string& msg, const std::vector<std::string>& vars )
{
    _global_out( cpplogger::Level::DEBUG, "DEBUG", logger_name_, msg, vars );
}
