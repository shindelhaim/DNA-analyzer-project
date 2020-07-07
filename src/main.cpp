#include <iostream>
#include "system_manager.h"
#include "screen_writer.h"
#include "keyboard_reader.h"

int main() {
    SystemManager manager;
    KeyboardReader input;
    ScreenWriter output;
    manager.start(&input,&output);
    return 0;
}
