#include <cstdlib>

// i hate this include syntax but i cant change it so im just gonna stick with this :/
#include "raylib.h"

#include "Logger.class/Logger.h"
#include "Renderer/Renderer.h"
#include "Renderer/UI/UIElement.abstract/UIElement.h"
#include "Renderer/UI/Button.class/Button.h"

int main()
{
    auto *logger = new Snowflake::Logger();
    auto *raylibLogger = new Snowflake::Logger("raylib");
    raylibLogger->initRaylibLogger();

    auto *renderer = new Snowflake::Renderer();

    renderer->CreateWindow(800, 600, "Snowflake", 60);

    Snowflake::GameScene gameScene{};
    gameScene.addUIElement(new Snowflake::UI::Button({100, 100}, {400, 300}));

    renderer->loadGameScene(&gameScene);
    renderer->gameLoop();

    renderer->DestroyWindow();
    delete renderer;
    delete logger;
    delete raylibLogger;

    return 0;
}
