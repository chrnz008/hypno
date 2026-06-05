#include <raylib.h>

#define WAVE_NO 100
#define WAVE_SPACING 10
#define WAVE_SPEED 1

int waves[WAVE_NO]; // each wave contains radius

int main() {

    const int window_width = 800;
    const int window_height = 600;
    InitWindow(window_width, window_height, "look into the watch");

    ClearBackground(BLACK);
    HideCursor();

    const int src_rad = 5;

    struct Vector2 center = {window_width / 2, window_height / 2};

    while (!WindowShouldClose()) {
        BeginDrawing();

        DrawCircleV(center, src_rad, WHITE);

        int idx = 0;
        do {

            if ( waves[idx] > window_width)
            	waves[idx] = 10;

            DrawCircleLinesV(center, waves[idx], WHITE);
            waves[idx] += 10; // increment wave radius

			idx++;

        } while (waves[idx] - 10 != 0 && idx < WAVE_NO); // till next child wave 
														// (-1 because we are incrementing previously)

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
