#include <windows.h>
#include <thread>

void fakeKeyRight() {
    INPUT input;
    input.type = INPUT_MOUSE;
    POINT p;
    GetCursorPos(&p);
    input.mi.dx = p.x;
    input.mi.dy = p.y;
    input.mi.dwFlags = (MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_RIGHTDOWN | MOUSEEVENTF_RIGHTUP);
    input.mi.mouseData = 0;
    input.mi.dwExtraInfo = NULL;
    input.mi.time = 0;
    SendInput(1, &input, sizeof(INPUT));
}

void fakeKeyLeft() {
    INPUT input;
    input.type = INPUT_MOUSE;
    POINT p;
    GetCursorPos(&p);
    input.mi.dx = p.x;
    input.mi.dy = p.y;
    input.mi.dwFlags = (MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP);
    input.mi.mouseData = 0;
    input.mi.dwExtraInfo = NULL;
    input.mi.time = 0;
    SendInput(1, &input, sizeof(INPUT));
}

char _tha = 1;

extern "C" {
    extern char Lenabled;
    extern char Renabled;

	void th_start() {
        _tha = 1;
	}
}

void thraR() {
    while (_tha) {
        Sleep(2);
        if (Renabled) fakeKeyRight();
    }
}

void thraL() {
    while (_tha) {
        Sleep(4);
        if (Lenabled) fakeKeyLeft();
    }
}

std::thread thra(thraL);
std::thread thrb(thraR);

extern "C" {

    void th_stop() {
        _tha = 0;
        thra.join();
        thrb.join();
    }
}