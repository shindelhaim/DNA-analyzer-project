#include <iostream>
#include "Controller/system_manager.h"
#include "View/writer/screen_writer.h"
#include "View/reader/keyboard_reader.h"
#include "View/UI/terminal.h"

int main() {

    KeyboardReader input;
    ScreenWriter output;
    Terminal terminal;
    SystemManager manager;

    manager.start(&terminal, &input, &output);
    manager.end();
    return 0;
}
