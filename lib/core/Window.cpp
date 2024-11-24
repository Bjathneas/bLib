#include "bLib/core/Window.h"

#include <GLFW/glfw3.h>

#include <chrono>
#include <cmath>
#include <format>
#include <thread>

#include "bLib/core/Input.h"
#include "bLib/util/Logger.h"

namespace bLib {
    void init_window( uint width, uint height, const char *title ) {
        BLIB_DEBUG( std::format( "Initializing Window{{ width: {}, height: {}, title: {} }}", width, height, title )
                            .c_str() )

        // Initialize GLFW, abort and report if failed
        if ( !static_cast<bool>( glfwInit() ) ) {
            BLIB_FATAL( "GLFW could not intialize" )
            std::quick_exit( EXIT_FAILURE );
        }

        //glfwWindowHint( GLFW_CONTEXT_VERSION_MAJOR, 3 );
        //glfwWindowHint( GLFW_CONTEXT_VERSION_MAJOR, 3 );
        //glfwWindowHint( GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE );

        // create base window
        Window.glfw_window =
                glfwCreateWindow( static_cast<int>( width ), static_cast<int>( height ), title, nullptr, nullptr );

        // Check if Window.glfw_window was created, abort and report if not created
        if ( !static_cast<bool>( Window.glfw_window ) ) {
            BLIB_FATAL( "Window.glfw_window failed to be created" )
            std::quick_exit( EXIT_FAILURE );
        }

        glfwMakeContextCurrent( Window.glfw_window );

        // Initialize the input module
        init_input( Window.glfw_window );

        // Hide window until program is ready to show it
        hide_window();

        BLIB_INFO( "Window was created successfully" )
    }

    void hide_window() { glfwHideWindow( Window.glfw_window ); }

    void show_window() { glfwShowWindow( Window.glfw_window ); }

    bool should_window_close() { return static_cast<bool>( glfwWindowShouldClose( Window.glfw_window ) ); }

    void close_window() {
        BLIB_DEBUG( "Closing Window" )
        glfwTerminate();
    }

    void start_window( std::function<void( double )> &update, std::function<void()> &render ) {
        show_window();
        glfwSwapInterval( 0 );

        float last_time = get_time();
        float current_time{};

        while ( !should_window_close() ) {
            current_time = get_time();

            Window.delta_time = current_time - last_time;

            last_time = current_time;

            update( Window.delta_time );

            Window.fps = static_cast<uint>( std::round( 1.0F / Window.delta_time ) );

            render();

            glfwSwapBuffers( Window.glfw_window );

            update_input();

            glfwPollEvents();

            // Check if we are too efficient, and sleep if we are so cpu doesn't go brrr
            if ( Window.ftarget_fps > 0.0F ) {
                double sleep_time = Window.ftarget_fps - ( get_time() - current_time );

                if ( sleep_time > 0 ) {
                    std::this_thread::sleep_for( std::chrono::duration<double>( sleep_time ) );// Catching some Z's
                }
            }
        }
        close_window();
    }

    void set_window_size( uint width, uint height ) {
        glfwSetWindowSize( Window.glfw_window, static_cast<int>( width ), static_cast<int>( height ) );
    }

    uint get_window_width() { return get_window_size()[ 0 ]; }

    uint get_window_height() { return get_window_size()[ 1 ]; }

    std::array<uint, 2> get_window_size() {
        int width{};
        int height{};

        glfwGetWindowSize( Window.glfw_window, &width, &height );

        return { static_cast<uint>( width ), static_cast<uint>( height ) };
    }

    void set_target_fps( uint target_fps ) {
        Window.target_fps = target_fps;
        Window.ftarget_fps = 1.0F / static_cast<float>( target_fps );
    }

    float get_frame_time() { return Window.delta_time; }

    float get_time() { return static_cast<float>( glfwGetTime() ); }

    uint get_fps() { return Window.fps; }

}// namespace bLib
