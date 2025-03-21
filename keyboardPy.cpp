#include <stdio.h>
#include <conio.h>
#include "keyboardPy.h"

int keyboard_layout()
{
    // ������������� ��������� ���������� (��������, ��� ���������� ���������)
    const char* layoutId = "00000409";

    // �������� ��������� ����������
    HKL hkl = LoadKeyboardLayoutA(layoutId, KLF_ACTIVATE);

    if (hkl == NULL) {
        // ��������� ������
        DWORD errorCode = GetLastError();
        printf("������ ��� �������� ���������: %d\n", errorCode);
        return 1;
    }

    // ��������� ����������� ���������
    HWND hWnd = GetForegroundWindow();
    if (!PostMessage(hWnd, WM_INPUTLANGCHANGEREQUEST, 0, (LPARAM)hkl)) {
        // ��������� ������
        DWORD errorCode = GetLastError();
        printf("������ ��� ��������� ���������: %d\n", errorCode);
        return 1;
    }

    return 0;
}
