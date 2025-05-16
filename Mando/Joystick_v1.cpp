#include <Xinput.h>
#include <iostream>
#include <windows.h>

#pragma comment(lib, "Xinput.lib")

int main()
{
    XINPUT_STATE state;
    DWORD dwResult;

    while (true) {
        ZeroMemory(&state, sizeof(XINPUT_STATE));

        dwResult = XInputGetState(0, &state);

        if (dwResult == ERROR_SUCCESS) {
            // Controlador conectado
            std::cout << "Thumb LX: " << state.Gamepad.sThumbLX 
                      << " Thumb LY: " << state.Gamepad.sThumbLY << std::endl;
            std::cout << "Button Pressed: " << state.Gamepad.wButtons << std::endl;
        } else {
            std::cout << "Controller not connected!" << std::endl;
        }

        Sleep(100);
    }

    return 0;
}
