//
// Created by Brandon on 11/9/2026.
//

#include "Platform.h"

#if defined(HUNTER_WINDOWS)
#include <windows.h>
int Platform::getScreenWidth() {
    HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO information{};
    if (!GetConsoleScreenBufferInfo(output, &information)) {
        return 80;
    }

    int width = information.srWindow.Right - information.srWindow.Left + 1;
    return width;
}
#elif defined(HUNTER_APPLE) || defined(HUNTER_LINUX)
#include <sys/ioctl.h>
#include <unistd.h>

int Platform::getScreenWidth() {
    winsize information{};
    if (ioctl(STDOUT_FILENO, TIOCWINSZ, &information) == -1 || !information.ws_col) {
        return 80;
    }

    return information.ws_col;

}
#endif
