///
/// \file Logger.h
/// \brief System for logging to the console
/// \author Bjathneas
/// \date 11/24/24
///
#pragma once

// MACROS for logging
///
/// \brief Call Log Function with LOG_LEVEL::Trace
///
#define BLIB_TRACE( message ) bLib::log( bLib::LOG_LEVEL::Trace, __FILE__, __LINE__, message );
///
/// \brief Call Log Function with LOG_LEVEL::Debug
///
#define BLIB_DEBUG( message ) bLib::log( bLib::LOG_LEVEL::Debug, __FILE__, __LINE__, message );
///
/// \brief Call Log Function with LOG_LEVEL::Info
///
#define BLIB_INFO( message ) bLib::log( bLib::LOG_LEVEL::Info, __FILE__, __LINE__, message );
///
/// \brief Call Log Function With LOG_LEVEL::Warn
///
#define BLIB_WARN( message ) bLib::log( bLib::LOG_LEVEL::Warn, __FILE__, __LINE__, message );
///
/// \brief Call Log Function With LOG_LEVEL::Error
///
#define BLIB_ERROR( message ) bLib::log( bLib::LOG_LEVEL::Error, __FILE__, __LINE__, message );
///
/// \brief Call Log Function With LOG_LEVEL::Fatal
///
#define BLIB_FATAL( message ) bLib::log( bLib::LOG_LEVEL::Fatal, __FILE__, __LINE__, message );
///
/// \brief Call Log Function With LOG_LEVEL::Unknown
///
#define BLIB_LOG( message ) bLib::log( bLib::LOG_LEVEL::Unknown, __FILE__, __LINE__, message );

///
/// \namespace bLib
/// \brief root namespace
///
namespace bLib {
    ///
    /// \enum LOG_LEVEL
    /// \brief Define the Log Level
    ///
    enum LOG_LEVEL {
        ///
        /// \brief Set Log Level to "TRACE"
        ///
        Trace,
        ///
        /// \brief Set Log Level to "DEBUG"
        ///
        Debug,
        ///
        /// \brief Set Log Level to "INFO"
        ///
        Info,
        ///
        /// \brief Set Log Level to "WARN"
        ///
        Warn,
        ///
        /// \brief Set Log Level to "ERROR"
        ///
        Error,
        ///
        /// \brief Set Log Level to "FATAL"
        ///
        Fatal,
        ///
        /// \brief Set Log Level to "UNKNOWN"
        ///
        Unknown,
    };
    ///
    /// \brief Ouput a log message to the console
    /// \param level The Log Level
    /// \param file The file that is calling the function
    /// \param line The line in the file that is calling the function
    /// \param message The message to log
    ///
    void log( LOG_LEVEL level, const char* file, int line, const char* message );
}// namespace bLib
