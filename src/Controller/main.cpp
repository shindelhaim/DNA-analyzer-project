#include <iostream>
#include "system_manager.h"
#include "../View/screen_writer.h"
#include "../View/keyboard_reader.h"

int main() {
    SystemManager manager;
    KeyboardReader input;
    ScreenWriter output;
    manager.start(&input,&output);
    return 0;
}
