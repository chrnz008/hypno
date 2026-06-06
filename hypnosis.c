#include <raylib.h>
#include <math.h>
#include <stdio.h>

#define WAVE_NO 60
#define WAVE_SPACING 10
#define WAVE_SPEED 1

int waves[WAVE_NO]; // each wave contains radius

void wave_state() {
    for (int i = 0; i < WAVE_NO; i++) {
        printf("%d ", waves[i]);
    }
    printf("\n");
}

int main() {

    const int window_width = 800;
    const int window_height = 600;
    InitWindow(window_width, window_height, "look into the watch");
    SetTargetFPS(60);

    ClearBackground(BLACK);
    HideCursor();

    const int src_rad = 5;

    struct Vector2 center = {window_width / 2, window_height / 2};

	const int wave_limit = sqrt(window_width*window_width + window_height*window_height)/2;

    int child_waves = 1;
    /* waves[0] = 1; */
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);

        /* DrawCircleV(center, src_rad, WHITE); */

        int newchilds = 0;
        for (int idx = 0; idx < child_waves; idx++) {
            waves[idx] += WAVE_SPEED;

            if (idx==0 && child_waves < WAVE_NO && waves[0] % WAVE_SPACING == 0) {
                newchilds++;
            }

            DrawCircleLinesV(center, waves[idx], WHITE);
            waves[idx] %= wave_limit; //trim the wave when hits limit
        }
        child_waves += newchilds;
        wave_state();

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
