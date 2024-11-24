#include "bLib/core/Input.h"

#include <GLFW/glfw3.h>


namespace bLib {
    void init_input( GLFWwindow* window ) {
        glfwSetKeyCallback( window, key_callback );
        glfwSetMouseButtonCallback( window, mouse_button_callback );
    }

    void update_input() {
        InputData.changed_button_states.clear();
        InputData.changed_key_states.clear();

        //Check if Mouse position has changed based on previous position
        InputData.mouse_pos_changed = !std::equal( InputData.mouse_position.begin(), InputData.mouse_position.end(),
                                                   get_mouse_position().begin() );

        InputData.mouse_position = get_mouse_position();
    }

    bool key_pressed( int key ) { return glfwGetKey( glfwGetCurrentContext(), key ) == GLFW_PRESS; }

    bool key_just_pressed( int key ) {
        if ( InputData.changed_key_states.find( key ) == InputData.changed_key_states.end() ) { return false; }

        return InputData.changed_key_states[ key ] == GLFW_PRESS;
    }

    bool key_just_released( int key ) {
        if ( InputData.changed_key_states.find( key ) == InputData.changed_key_states.end() ) { return false; }

        return InputData.changed_key_states[ key ] == GLFW_RELEASE;
    }

    bool mouse_pressed( int button ) { return glfwGetMouseButton( glfwGetCurrentContext(), button ) == GLFW_PRESS; }

    bool mouse_just_pressed( int button ) {
        if ( InputData.changed_button_states.find( button ) == InputData.changed_button_states.end() ) { return false; }

        return InputData.changed_button_states[ button ] == GLFW_PRESS;
    }

    bool mouse_just_released( int button ) {
        if ( InputData.changed_button_states.find( button ) == InputData.changed_button_states.end() ) { return false; }

        return InputData.changed_button_states[ button ] == GLFW_RELEASE;
    }

    bool mouse_moved() { return InputData.mouse_pos_changed; }

    double get_mouse_x() { return get_mouse_position()[ 0 ]; }

    double get_mouse_y() { return get_mouse_position()[ 1 ]; }

    std::array<double, 2> get_mouse_position() {
        double mouse_x{};
        double mouse_y{};

        glfwGetCursorPos( glfwGetCurrentContext(), &mouse_x, &mouse_y );

        return { mouse_x, mouse_y };
    }

    static void key_callback( [[maybe_unused]] GLFWwindow* window, int key, [[maybe_unused]] int scancode, int action,
                              [[maybe_unused]] int mods ) {
        InputData.changed_key_states[ key ] = action;
    }

    static void mouse_button_callback( [[maybe_unused]] GLFWwindow* window, int button, int action,
                                       [[maybe_unused]] int mods ) {
        InputData.changed_button_states[ button ] = action;
    }


}// namespace bLib
