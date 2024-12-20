///
/// \file Input.h
/// \brief The Input Handler
/// \author Bjathneas
/// \date 11/24/24
///
#pragma once

// Define all keys as ints
#define KEY_UNKNOWN ( -1 )
#define KEY_SPACE 32
#define KEY_APOSTROPHE 39
#define KEY_COMMA 44
#define KEY_MINUS 45
#define KEY_PERIOD 46
#define KEY_SLASH 47
#define KEY_0 48
#define KEY_1 49
#define KEY_2 50
#define KEY_3 51
#define KEY_4 52
#define KEY_5 53
#define KEY_6 54
#define KEY_7 55
#define KEY_8 56
#define KEY_9 57
#define KEY_SEMICOLON 59
#define KEY_EQUAL 61
#define KEY_A 65
#define KEY_B 66
#define KEY_C 67
#define KEY_D 68
#define KEY_E 69
#define KEY_F 70
#define KEY_G 71
#define KEY_H 72
#define KEY_I 73
#define KEY_J 74
#define KEY_K 75
#define KEY_L 76
#define KEY_M 77
#define KEY_N 78
#define KEY_O 79
#define KEY_P 80
#define KEY_Q 81
#define KEY_R 82
#define KEY_S 83
#define KEY_T 84
#define KEY_U 85
#define KEY_V 86
#define KEY_W 87
#define KEY_X 88
#define KEY_Y 89
#define KEY_Z 90
#define KEY_LEFT_BRACKET 91
#define KEY_BACKSLASH 92
#define KEY_RIGHT_BRACKET 93
#define KEY_GRAVE_ACCENT 96
#define KEY_WORLD_1 161
#define KEY_WORLD_2 162
#define KEY_ESCAPE 256
#define KEY_ENTER 257
#define KEY_TAB 258
#define KEY_BACKSPACE 259
#define KEY_INSERT 260
#define KEY_DELETE 261
#define KEY_RIGHT 262
#define KEY_LEFT 263
#define KEY_DOWN 264
#define KEY_UP 265
#define KEY_PAGE_UP 266
#define KEY_PAGE_DOWN 267
#define KEY_HOME 268
#define KEY_END 269
#define KEY_CAPS_LOCK 280
#define KEY_SCROLL_LOCK 281
#define KEY_NUM_LOCK 282
#define KEY_PRINT_SCREEN 283
#define KEY_PAUSE 284
#define KEY_F1 290
#define KEY_F2 291
#define KEY_F3 292
#define KEY_F4 293
#define KEY_F5 294
#define KEY_F6 295
#define KEY_F7 296
#define KEY_F8 297
#define KEY_F9 298
#define KEY_F10 299
#define KEY_F11 300
#define KEY_F12 301
#define KEY_F13 302
#define KEY_F14 303
#define KEY_F15 304
#define KEY_F16 305
#define KEY_F17 306
#define KEY_F18 307
#define KEY_F19 308
#define KEY_F20 309
#define KEY_F21 310
#define KEY_F22 311
#define KEY_F23 312
#define KEY_F24 313
#define KEY_F25 314
#define KEY_KP_0 320
#define KEY_KP_1 321
#define KEY_KP_2 322
#define KEY_KP_3 323
#define KEY_KP_4 324
#define KEY_KP_5 325
#define KEY_KP_6 326
#define KEY_KP_7 327
#define KEY_KP_8 328
#define KEY_KP_9 329
#define KEY_KP_DECIMAL 330
#define KEY_KP_DIVIDE 331
#define KEY_KP_MULTIPLY 332
#define KEY_KP_SUBTRACT 333
#define KEY_KP_ADD 334
#define KEY_KP_ENTER 335
#define KEY_KP_EQUAL 336
#define KEY_LEFT_SHIFT 340
#define KEY_LEFT_CONTROL 341
#define KEY_LEFT_ALT 342
#define KEY_LEFT_SUPER 343
#define KEY_RIGHT_SHIFT 344
#define KEY_RIGHT_CONTROL 345
#define KEY_RIGHT_ALT 346
#define KEY_RIGHT_SUPER 347
#define KEY_MENU 348
#define KEY_LAST KEY_MENU

#define MOUSE_1 0
#define MOUSE_2 1
#define MOUSE_3 2
#define MOUSE_4 3
#define MOUSE_5 4
#define MOUSE_6 5
#define MOUSE_7 6
#define MOUSE_8 7
#define MOUSE_LEFT MOUSE_1
#define MOUSE_RIGHT MOUSE_2
#define MOUSE_MIDDLE MOUSE_3

#include <GLFW/glfw3.h>

#include <array>
#include <unordered_map>

///
/// \namespace bLib
/// \brief root namespace
///
namespace bLib {
    ///
    /// \struct InputData
    /// \brief Single Instance struct that stores all variables related to Input module
    ///
    struct {
        ///
        /// \var InputDat::changed_key_states
        /// \brief A Map of all keys that have changed states since last frame
        ///
        std::unordered_map<int, int> changed_key_states;
        ///
        /// \var InputData::changed_button_states
        /// \brief A Map of all mouse buttons that have changed states since last frame
        ///
        std::unordered_map<int, int> changed_button_states;
        ///
        /// \var InputData::mouse_position
        /// \brief The last tracked position of the mouse, use get_mouse_position() for the current location
        ///
        std::array<double, 2> mouse_position{};
        ///
        /// \var InputData::mouse_pos_changed
        /// \brief Boolean that tracks whether or not the cursor has moved since the last frame
        ///
        bool mouse_pos_changed{ false };
    } InputData;
    ///
    /// \brief Set GLFW Input related Callbacks for the window instance
    /// \param window The GLFWwindow* to set the callbacks for
    ///
    void init_input( GLFWwindow* window );
    ///
    /// \brief Clear the current cache of states
    ///
    void update_input();
    ///
    /// \brief Check is key is in the pressed state
    /// \param key The key to check current state
    /// \return Whether the key is pressed or not
    ///
    bool key_pressed( int key );
    ///
    /// \brief Check if the key's state changed to pressed in the frame
    /// \param key The key to check changed state
    /// \return If the key's state changed to pressed or not
    ///
    bool key_just_pressed( int key );
    ///
    /// \brief Check if the key's state changed to released in the frame
    /// \param key The key to check changed state
    /// \return If the key's state was changed to released or not
    ///
    bool key_just_released( int key );
    ///
    /// \brief Check if a mouse button is in the pressed state
    /// \param button The Button to check current state
    /// \return Whether the button is currently in the pressed state
    ///
    bool mouse_pressed( int button );
    ///
    /// \brief Check if a mouse button's state has changed to pressed within the frame
    /// \param button The button to check changed state
    /// \return If the mouse button's state changed to pressed
    ///
    bool mouse_just_pressed( int button );
    ///
    /// \brief Check if a mouse button's state has changed to released within the frame
    /// \param button The button to check changed state
    /// \return If the mouse button's state changed to released
    ///
    bool mouse_just_released( int button );
    ///
    /// \brief Check if the mouse has moved within the frame
    /// \return Whether the mouse has moved within the frame
    ///
    bool mouse_moved();
    ///
    /// \brief Get the Mouse X position
    /// \return The Mouse's X position
    ///
    double get_mouse_x();
    ///
    /// \brief Get the Mouse Y position
    /// \return The Mouse's Y position
    ///
    double get_mouse_y();
    ///
    /// \brief Get the Mouse's current position
    /// \return The Mouse's current position represented as a 2d array
    ///
    std::array<double, 2> get_mouse_position();
    ///
    /// \brief Update InputData for changed key states
    /// \param window The window that received a key input
    /// \param key The key that has changed states
    /// \param scancode UNUSED
    /// \param action The new key state
    /// \param mods UNUSED
    ///
    static void key_callback( GLFWwindow* window, int key, int scancode, int action, int mods );
    ///
    /// \brief Update InputData for changed mouse button states
    /// \param window The window that received a mouse button input
    /// \param button The button that changed states
    /// \param action The new mouse button state
    /// \param mods UNUSED
    ///
    static void mouse_button_callback( GLFWwindow* window, int button, int action, int mods );
}// namespace bLib
