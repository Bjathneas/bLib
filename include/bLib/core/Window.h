///
/// \file Window.h
/// \brief GLFW wrapper
/// \author Bjathneas
/// \date 11/24/24
///
#pragma once

// clang-format off
// DO NOT REORDER
#include <GLFW/glfw3.h>
// clang-format on

#include <array>
#include <functional>

///
/// \typedef uint
/// \brief An unsigned int
///
using uint = unsigned int;

///
/// \namespace bLib
/// \brief root namespace
///
namespace bLib {
    ///
    /// \struct Window
    /// \brief Single Instance struct that stores all variables related to window module
    ///
    struct {
        ///
        /// \var Window::glfw_window
        /// \brief The GLFWwindow*
        ///
        GLFWwindow *glfw_window{};
        ///
        /// \var Window::fps
        /// \brief The current running fps of the window
        ///
        uint fps{ 0 };
        ///
        /// \var Window::target_fps
        /// \brief The fps_limit as a whole number
        ///
        uint target_fps{ 0 };
        ///
        /// \var Window::ftarget_fps
        /// \brief target_fps represented as 1.0F / target_fps
        ///
        float ftarget_fps{ 0.0F };
        ///
        /// \var Window::delta_time
        /// \brief The time in seconds for last frame drawn
        ///
        float delta_time{ 0.0F };
    } Window;

    ///
    /// \brief Initialize glfw and glfw_window instance
    /// \param width Width of the Window
    /// \param height Height of the Window
    /// \param title Title of the Window
    ///
    void init_window( uint width, uint height, const char *title );
    ///
    /// \brief Hides the current Window Instance
    ///
    void hide_window();
    ///
    /// \brief Reveals the current Window Instance
    ///
    void show_window();
    ///
    /// \brief Ask is window is set to close
    /// \return Whether the window is set to close or not
    ///
    bool should_window_close();
    ///
    /// \brief Terminates GLFW and window instance
    ///
    void close_window();
    ///
    /// \brief Start main loop, handle fps, and call update/render when required
    /// \param update  The function to call when updating window
    /// \param render The function to call when ready for draw calls
    ///
    void start_window( std::function<void( double )> &update, std::function<void()> &render );
    ///
    /// \brief Set the size of the window
    /// \param width The width to set the window to
    /// \param height The height to set the window to
    ///
    void set_window_size( uint width, uint height );
    ///
    /// \brief Return the width of the window
    /// \return The width of the window
    ///
    uint get_window_width();
    ///
    /// \brief Return the height of the window
    /// \return The height of the window
    ///
    uint get_window_height();
    ///
    /// \brief Get the Window's size
    /// \return The Window's size represented as a 2d array
    ///
    std::array<uint, 2> get_window_size();
    ///
    /// \brief Set the fps limit
    /// \param target_fps The new fps limit
    ///
    void set_target_fps( uint target_fps );
    ///
    /// \brief Get the delta_time
    /// \return Window.delta_time
    ///
    float get_frame_time();
    ///
    /// \brief Get the time elapsed since window started
    /// \return The time elapsed in seconds
    ///
    float get_time();
    ///
    /// \brief Get the current running FPS
    /// \return Window.fps
    ///
    uint get_fps();
}// namespace bLib
