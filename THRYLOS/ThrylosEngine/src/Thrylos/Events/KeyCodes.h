#pragma once
#include "GLFW/glfw3.h"

namespace Thrylos
{
    inline uint32_t glfwToWindowsKeyCode(const int glfwKeyCode)
    {
        switch (glfwKeyCode)
        {
            case GLFW_KEY_TAB:
                return VK_TAB;
            case GLFW_KEY_APOSTROPHE:
                return VK_OEM_7;
            case GLFW_KEY_COMMA:
                return VK_OEM_COMMA;
            case GLFW_KEY_MINUS:
                return VK_OEM_MINUS;
            case GLFW_KEY_PERIOD:
                return VK_OEM_PERIOD;
            case GLFW_KEY_SLASH:
                return VK_OEM_2;
            case GLFW_KEY_0:
                return 0x30;
            case GLFW_KEY_1:
                return 0x31;
            case GLFW_KEY_2:
                return 0x32;
            case GLFW_KEY_3:
                return 0x33;
            case GLFW_KEY_4:
                return 0x34;
            case GLFW_KEY_5:
                return 0x35;
            case GLFW_KEY_6:
                return 0x36;
            case GLFW_KEY_7:
                return 0x37;
            case GLFW_KEY_8:
                return 0x38;
            case GLFW_KEY_9:
                return 0x39;
            case GLFW_KEY_SEMICOLON:
                return VK_OEM_1;
            case GLFW_KEY_EQUAL:
                return VK_OEM_PLUS;
            case GLFW_KEY_A:
                return 0x41;
            case GLFW_KEY_B:
                return 0x42;
            case GLFW_KEY_C:
                return 0x43;
            case GLFW_KEY_D:
                return 0x44;
            case GLFW_KEY_E:
                return 0x45;
            case GLFW_KEY_F:
                return 0x46;
            case GLFW_KEY_G:
                return 0x47;
            case GLFW_KEY_H:
                return 0x48;
            case GLFW_KEY_I:
                return 0x49;
            case GLFW_KEY_J:
                return 0x4A;
            case GLFW_KEY_K:
                return 0x4B;
            case GLFW_KEY_L:
                return 0x4C;
            case GLFW_KEY_M:
                return 0x4D;
            case GLFW_KEY_N:
                return 0x4E;
            case GLFW_KEY_O:
                return 0x4F;
            case GLFW_KEY_P:
                return 0x50;
            case GLFW_KEY_Q:
                return 0x51;
            case GLFW_KEY_R:
                return 0x52;
            case GLFW_KEY_S:
                return 0x53;
            case GLFW_KEY_T:
                return 0x54;
            case GLFW_KEY_U:
                return 0x55;
            case GLFW_KEY_V:
                return 0x56;
            case GLFW_KEY_W:
                return 0x57;
            case GLFW_KEY_X:
                return 0x58;
            case GLFW_KEY_Y:
                return 0x59;
            case GLFW_KEY_Z:
                return 0x5A;
            case GLFW_KEY_LEFT_BRACKET:
                return VK_OEM_4;
            case GLFW_KEY_BACKSLASH:
                return VK_OEM_5;
            case GLFW_KEY_RIGHT_BRACKET:
                return VK_OEM_6;
            case GLFW_KEY_GRAVE_ACCENT:
                return VK_OEM_3;
            case GLFW_KEY_ESCAPE:
                return VK_ESCAPE;
            case GLFW_KEY_ENTER:
                return VK_RETURN;
            case GLFW_KEY_BACKSPACE:
                return VK_BACK;
            case GLFW_KEY_INSERT:
                return VK_INSERT;
            case GLFW_KEY_DELETE:
                return VK_DELETE;
            case GLFW_KEY_RIGHT:
                return VK_RIGHT;
            case GLFW_KEY_LEFT:
                return VK_LEFT;
            case GLFW_KEY_DOWN:
                return VK_DOWN;
            case GLFW_KEY_UP:
                return VK_UP;
            case GLFW_KEY_PAGE_UP:
                return VK_PRIOR;
            case GLFW_KEY_PAGE_DOWN:
                return VK_NEXT;
            case GLFW_KEY_HOME:
                return VK_HOME;
            case GLFW_KEY_END:
                return VK_END;
            case GLFW_KEY_CAPS_LOCK:
                return VK_CAPITAL;
            case GLFW_KEY_SCROLL_LOCK:
                return VK_SCROLL;
            case GLFW_KEY_NUM_LOCK:
                return VK_NUMLOCK;
            case GLFW_KEY_PRINT_SCREEN:
                return VK_SNAPSHOT;
            case GLFW_KEY_PAUSE:
                return VK_PAUSE;
            case GLFW_KEY_F1:
                return VK_F1;
            case GLFW_KEY_F2:
                return VK_F2;
            case GLFW_KEY_F3:
                return VK_F3;
            case GLFW_KEY_F4:
                return VK_F4;
            case GLFW_KEY_F5:
                return VK_F5;
            case GLFW_KEY_F6:
                return VK_F6;
            case GLFW_KEY_F7:
                return VK_F7;
            case GLFW_KEY_F8:
                return VK_F8;
            case GLFW_KEY_F9:
                return VK_F9;
            case GLFW_KEY_F10:
                return VK_F10;
            case GLFW_KEY_F11:
                return VK_F11;
            case GLFW_KEY_F12:
                return VK_F12;
            case GLFW_KEY_F13:
                return VK_F13;
            case GLFW_KEY_F14:
                return VK_F14;
            case GLFW_KEY_F15:
                return VK_F15;
            case GLFW_KEY_F16:
                return VK_F16;
            case GLFW_KEY_F17:
                return VK_F17;
            case GLFW_KEY_F18:
                return VK_F18;
            case GLFW_KEY_F19:
                return VK_F19;
            case GLFW_KEY_F20:
                return VK_F20;
            case GLFW_KEY_F21:
                return VK_F21;
            case GLFW_KEY_F22:
                return VK_F22;
            case GLFW_KEY_F23:
                return VK_F23;
            case GLFW_KEY_F24:
                return VK_F24;
            case GLFW_KEY_KP_0:
                return VK_NUMPAD0;
            case GLFW_KEY_KP_1:
                return VK_NUMPAD1;
            case GLFW_KEY_KP_2:
                return VK_NUMPAD2;
            case GLFW_KEY_KP_3:
                return VK_NUMPAD3;
            case GLFW_KEY_KP_4:
                return VK_NUMPAD4;
            case GLFW_KEY_KP_5:
                return VK_NUMPAD5;
            case GLFW_KEY_KP_6:
                return VK_NUMPAD6;
            case GLFW_KEY_KP_7:
                return VK_NUMPAD7;
            case GLFW_KEY_KP_8:
                return VK_NUMPAD8;
            case GLFW_KEY_KP_9:
                return VK_NUMPAD9;
            case GLFW_KEY_KP_DECIMAL:
                return VK_DECIMAL;
            case GLFW_KEY_KP_DIVIDE:
                return VK_DIVIDE;
            case GLFW_KEY_KP_MULTIPLY:
                return VK_MULTIPLY;
            case GLFW_KEY_KP_SUBTRACT:
                return VK_SUBTRACT;
            case GLFW_KEY_KP_ADD:
                return VK_ADD;
            case GLFW_KEY_KP_ENTER:
                return VK_RETURN; // Not distinct from VK_RETURN, but used for numeric keypad enter
            case GLFW_KEY_KP_EQUAL:
                return VK_OEM_PLUS; // Assumes usage similar to standard equals key, may need customization
            case GLFW_KEY_LEFT_SHIFT:
                return VK_LSHIFT;
            case GLFW_KEY_LEFT_CONTROL:
                return VK_LCONTROL;
            case GLFW_KEY_LEFT_ALT:
                return VK_LMENU;
            case GLFW_KEY_LEFT_SUPER:
                return VK_LWIN;
            case GLFW_KEY_RIGHT_SHIFT:
                return VK_RSHIFT;
            case GLFW_KEY_RIGHT_CONTROL:
                return VK_RCONTROL;
            case GLFW_KEY_RIGHT_ALT:
                return VK_RMENU;
            case GLFW_KEY_RIGHT_SUPER:
                return VK_RWIN;
            case GLFW_KEY_MENU:
                return VK_APPS;
            case GLFW_MOUSE_BUTTON_1:
                return VK_LBUTTON;
            case GLFW_MOUSE_BUTTON_2:
                return VK_RBUTTON;
            case GLFW_MOUSE_BUTTON_3:
                return VK_MBUTTON;
            case GLFW_MOUSE_BUTTON_4:
                return VK_XBUTTON1;
            case GLFW_MOUSE_BUTTON_5:
                return VK_XBUTTON2;
            default:
                return glfwKeyCode; // No valid mapping found
        }
    }
    
    enum class Th_Key
    {
        Tab = VK_TAB
        , Apostrophe = VK_OEM_7
        , Comma = VK_OEM_COMMA
        , Minus = VK_OEM_MINUS
        , Period = VK_OEM_PERIOD
        , Slash = VK_OEM_2
        , Zero = 0x30
        , One = 0x31
        , Two = 0x32
        , Three = 0x33
        , Four = 0x34
        , Five = 0x35
        , Six = 0x36
        , Seven = 0x37
        , Eight = 0x38
        , Nine = 0x39
        , Semicolon = VK_OEM_1
        , Equal = VK_OEM_PLUS
        , A = 0x41
        , B = 0x42
        , C = 0x43
        , D = 0x44
        , E = 0x45
        , F = 0x46
        , G = 0x47
        , H = 0x48
        , I = 0x49
        , J = 0x4A
        , K = 0x4B
        , L = 0x4C
        , M = 0x4D
        , N = 0x4E
        , O = 0x4F
        , P = 0x50
        , Q = 0x51
        , R = 0x52
        , S = 0x53
        , T = 0x54
        , U = 0x55
        , V = 0x56
        , W = 0x57
        , X = 0x58
        , Y = 0x59
        , Z = 0x5A
        , LeftBracket = VK_OEM_4
        , Backslash = VK_OEM_5
        , RightBracket = VK_OEM_6
        , GraveAccent = VK_OEM_3
        , Escape = VK_ESCAPE
        , Enter = VK_RETURN
        , Backspace = VK_BACK
        , Insert = VK_INSERT
        , Delete = VK_DELETE
        , Right = VK_RIGHT
        , Left = VK_LEFT
        , Down = VK_DOWN
        , Up = VK_UP
        , PageUp = VK_PRIOR
        , PageDown = VK_NEXT
        , Home = VK_HOME
        , End = VK_END
        , CapsLock = VK_CAPITAL
        , ScrollLock = VK_SCROLL
        , NumLock = VK_NUMLOCK
        , PrintScreen = VK_SNAPSHOT
        , Pause = VK_PAUSE
        , F1 = VK_F1
        , F2 = VK_F2
        , F3 = VK_F3
        , F4 = VK_F4
        , F5 = VK_F5
        , F6 = VK_F6
        , F7 = VK_F7
        , F8 = VK_F8
        , F9 = VK_F9
        , F10 = VK_F10
        , F11 = VK_F11
        , F12 = VK_F12
        , F13 = VK_F13
        , F14 = VK_F14
        , F15 = VK_F15
        , F16 = VK_F16
        , F17 = VK_F17
        , F18 = VK_F18
        , F19 = VK_F19
        , F20 = VK_F20
        , F21 = VK_F21
        , F22 = VK_F22
        , F23 = VK_F23
        , F24 = VK_F24
        , Kp0 = VK_NUMPAD0
        , Kp1 = VK_NUMPAD1
        , Kp2 = VK_NUMPAD2
        , Kp3 = VK_NUMPAD3
        , Kp4 = VK_NUMPAD4
        , Kp5 = VK_NUMPAD5
        , Kp6 = VK_NUMPAD6
        , Kp7 = VK_NUMPAD7
        , Kp8 = VK_NUMPAD8
        , Kp9 = VK_NUMPAD9
        , KpDecimal = VK_DECIMAL
        , KpDivide = VK_DIVIDE
        , KpMultiply = VK_MULTIPLY
        , KpSubtract = VK_SUBTRACT
        , KpAdd = VK_ADD
        , KpEnter = VK_RETURN
        , KpEqual = VK_OEM_PLUS
        , LeftShift = VK_LSHIFT
        , LeftControl = VK_LCONTROL
        , LeftAlt = VK_LMENU
        , LeftSuper = VK_LWIN
        , RightShift = VK_RSHIFT
        , RightControl = VK_RCONTROL
        , RightAlt = VK_RMENU
        , RightSuper = VK_RWIN
        , Menu = VK_APPS
        , LeftMouse = VK_LBUTTON
        , RightMouse = VK_RBUTTON
        , MiddleMouse = VK_MBUTTON
        , Mouse4 = VK_XBUTTON1
        , Mouse5 = VK_XBUTTON2
    };
    
}
