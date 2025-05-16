// joystick_reader.cpp

#include <iostream>
#include <windows.h>     // Para Sleep
#include <Xinput.h>       // Para XInput
#pragma comment(lib, "Xinput.lib") // Enlazar automáticamente Xinput.lib

void printJoystickState(XINPUT_STATE& state)
{
    std::cout << "🔵 Joystick State:" << std::endl;
    std::cout << "    Left Thumbstick: (" << state.Gamepad.sThumbLX << ", " << state.Gamepad.sThumbLY << ")" << std::endl;
    std::cout << "    Right Thumbstick: (" << state.Gamepad.sThumbRX << ", " << state.Gamepad.sThumbRY << ")" << std::endl;
    std::cout << "    Left Trigger: " << (int)state.Gamepad.bLeftTrigger << std::endl;
    std::cout << "    Right Trigger: " << (int)state.Gamepad.bRightTrigger << std::endl;
    std::cout << "    Buttons pressed: " << state.Gamepad.wButtons << std::endl;
}

int main()
{
    XINPUT_STATE state;
    DWORD dwResult;

    std::cout << "🎮 Iniciando lectura de Joystick (presiona Ctrl+C para salir)..." << std::endl;

    while (true)
    {
        ZeroMemory(&state, sizeof(XINPUT_STATE));

        // Consultar el primer joystick (Player 1 -> index 0)
        dwResult = XInputGetState(0, &state);

        if (dwResult == ERROR_SUCCESS)
        {
            printJoystickState(state);
        }
        else
        {
            std::cout << "🚫 Controlador no conectado." << std::endl;
        }

        Sleep(1000); // Espera 1 segundo
    }

    return 0;
}


//  g++ -Wall -Wextra -g3 -O0 "Joystick\Joystick.cpp" -L "C:\Users\Responsable\Documents\Proyectos_C++\Joystick\lib\" -lXinput -o "C:\Users\Responsable\Documents\Proyectos_C++\Build\output.exe"
// g++ "Joystick\Joystick.cpp" -o "C:\Users\Responsable\Documents\Proyectos_C++\Build\output.exe"

// g++ Joystick\Joystick.cpp -o joystick_reader.exe -lXinput



