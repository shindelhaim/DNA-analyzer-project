#include <iostream>
#include "Controller/system_manager.h"
#include "View/screen_writer.h"
#include "View/keyboard_reader.h"
#include "View/terminal.h"

int main() {

    KeyboardReader input;
    ScreenWriter output;
    Terminal terminal;
    SystemManager manager;

    manager.start(&terminal, &input, &output);
    manager.end();
    return 0;
}