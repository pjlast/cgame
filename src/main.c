#include "raylib.h"
#include <stdbool.h>
#include <stdio.h>

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

void drawMenu(int xOffset, int yOffset, int numOptions, char **options,
              int selectedMenuOption) {
  for (int i = 0; i < numOptions; i++) {
    if (i == selectedMenuOption) {
      char buf[256];
      snprintf(buf, sizeof(buf), "> %s", options[selectedMenuOption]);
      DrawText(buf, xOffset, yOffset + (16 * i), 16, WHITE);
    } else {
      DrawText(options[i], xOffset, yOffset + (16 * i), 16, WHITE);
    }
  }
}

void draw_title() {
  static int selectedMenuOption = 0;

  if (IsKeyPressed(KEY_UP)) {
    selectedMenuOption--;
    if (selectedMenuOption < 0) {
      selectedMenuOption = 1;
    }
  }

  if (IsKeyPressed(KEY_DOWN)) {
    selectedMenuOption++;
    if (selectedMenuOption > 1) {
      selectedMenuOption = 0;
    }
  }

  if (IsKeyPressed(KEY_ENTER)) {
    if (selectedMenuOption == 1) {
      CloseWindow();
    }
  }

  BeginDrawing();

  ClearBackground(BLUE);
  DrawText("TITLE SCREEN", 120, 120, 30, BLACK);

  char *options[] = {
      "Start Game",
      "Quit",
  };

  drawMenu(120, 140, 2, options, selectedMenuOption);

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
