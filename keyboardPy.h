#ifndef _KEYBOARDPY_H
#define _KEYBOARDPY_H

#include <windows.h>

#define EXPORT extern "C" __declspec(dllexport)

// «десь определ€ютс€ прототипы экспортируемых функций
EXPORT int keyboard_layout();

#endif // _KEYBOARDPY_H
