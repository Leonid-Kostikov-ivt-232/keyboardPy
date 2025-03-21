#include <stdio.h>
#include <conio.h>
#include "keyboardPy.h"

int keyboard_layout()
{
    // Идентификатор раскладки клавиатуры (например, для английской раскладки)
    const char* layoutId = "00000409";

    // Загрузка раскладки клавиатуры
    HKL hkl = LoadKeyboardLayoutA(layoutId, KLF_ACTIVATE);

    if (hkl == NULL) {
        // Обработка ошибки
        DWORD errorCode = GetLastError();
        printf("Ошибка при загрузке раскладки: %d\n", errorCode);
        return 1;
    }

    // Активация загруженной раскладки
    HWND hWnd = GetForegroundWindow();
    if (!PostMessage(hWnd, WM_INPUTLANGCHANGEREQUEST, 0, (LPARAM)hkl)) {
        // Обработка ошибки
        DWORD errorCode = GetLastError();
        printf("Ошибка при активации раскладки: %d\n", errorCode);
        return 1;
    }

    return 0;
}
