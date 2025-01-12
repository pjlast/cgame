#include "raylib.h"
#include <stdbool.h>

typedef enum { LOGO = 0, TITLE, GAMEPLAY, ENDING } GameScreen;

bool draw_logo() {
  static int frameCounter = 0;
  frameCounter++;

  if (frameCounter > 120) {
    return true;
  }

  BeginDrawing();

  ClearBackground(WHITE);
  DrawText("Hello", 190, 190, 20, LIGHTGRAY);

  EndDrawing();

  return false;
}

void draw_title() {
  BeginDrawing();

  ClearBackground(BLUE);
  DrawText("TITLE SCREEN", 120, 120, 30, BLACK);

  EndDrawing();
}

int main(void) {
  const int screenWidth = 800;
  const int screenHeight = 450;

  InitWindow(screenWidth, screenHeight, "raylib core [example]");

  GameScreen currentScreen = LOGO;

  SetTargetFPS(60);

  while (!WindowShouldClose()) {
    switch (currentScreen) {
    case LOGO: {
      bool logo_done = draw_logo();
      if (logo_done) {
        currentScreen = TITLE;
      }
    } break;
    case TITLE: {
      draw_title();
    } break;
    case GAMEPLAY: {
    } break;
    case ENDING: {
    } break;
    }
  }

  CloseWindow();

  return 0;
}
