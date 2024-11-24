#include "bLib/util/Logger.h"

#include <cstdio>
#include <ctime>
#include <filesystem>

namespace bLib {
    void log( LOG_LEVEL level, const char* file, int line, const char* message ) {
        std::string log_level{};

        switch ( level ) {
            case LOG_LEVEL::Trace: log_level = "TRACE"; break;
            case LOG_LEVEL::Debug: log_level = "DEBUG"; break;
            case LOG_LEVEL::Info: log_level = "INFO"; break;
            case LOG_LEVEL::Warn: log_level = "WARN"; break;
            case LOG_LEVEL::Error: log_level = "ERROR"; break;
            case LOG_LEVEL::Fatal: log_level = "FATAL"; break;
            default: log_level = "UNKNOWN"; break;
        };

        std::time_t time = std::time( nullptr );
        std::filesystem::path path( file );

        std::printf( "[%.24s] [%s] %s:%i -> %s\n", ctime( &time ), log_level.c_str(), path.filename().c_str(), line,
                     message );
    }
}// namespace bLib
