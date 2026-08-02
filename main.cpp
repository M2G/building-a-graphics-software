#include <cstdio>
#include <iostream>
#include <ostream>

extern "C" {
    void init_canvas();
}

int main() {
    init_canvas();

    return 0;
}