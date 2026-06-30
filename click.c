#include <Windows.h>
#include <tchar.h>

char Lenabled = 0;
char Renabled = 0;
char listern = 0;
char _run = 1;

extern void th_stop();
extern void th_start();


int main() {
    FreeConsole();
    MessageBoxA(0, "PRESS [-] FOR STOP PROGRAM", "INFO", MB_OK);
    th_start();
    while (_run) {
        if (((GetAsyncKeyState(VK_OEM_MINUS) >> 16)) & 1 && ((GetAsyncKeyState(VK_OEM_3) >> 16) & 1)) {
            _run = 0;
        }
        if ((GetAsyncKeyState(VK_OEM_3) >> 16) & 1) {
            Lenabled = 0;
            Renabled = 0;
            listern = !listern;
        }
        if ((GetAsyncKeyState(82) >> 16) & 1) { // 82 = R
           if (listern) Lenabled = 1;
        }
        if ((GetAsyncKeyState(71) >> 16) & 1) { // 71 = G
            if (listern) Renabled = 1;
        }
    }
    th_stop();
    MessageBoxA(0, "PROGRAM STOPPED", "INFO", MB_OK);
    return 0;
}