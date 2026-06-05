#include <raylib.h>

int main() {

    const int window_width = 800;
    const int window_height = 600;
    InitWindow(window_width, window_height, "look into the watch");

    ClearBackground(BLACK);
    HideCursor();

    while (!WindowShouldClose()) {
        BeginDrawing();
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
