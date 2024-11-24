#include <cstdlib>

#include "bLib/core/Window.h"

int main() {
    bLib::init_window( 800, 600, "bLib" );

    bLib::show_window();
    while ( !bLib::should_window_close() ) { glfwPollEvents(); }

    bLib::close_window();

    return EXIT_SUCCESS;
}
