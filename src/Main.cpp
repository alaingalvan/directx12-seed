#include "CrossWindow/CrossWindow.h"
#include "Renderer.h"

void xmain(int argc, const char** argv)
{
    // 🖼️ Create a window
    xwin::EventQueue eventQueue;
    xwin::Window window;

    xwin::WindowDesc windowDesc;
    windowDesc.name = "MainWindow";
    windowDesc.title = "Hello Triangle";
    windowDesc.visible = true;
    windowDesc.width = 1280;
    windowDesc.height = 720;
    //windowDesc.fullscreen = true;
    window.create(windowDesc, eventQueue);

    // 📸 Create a renderer
    Renderer renderer(window);

    // 🏁 Engine loop
    bool isRunning = true;
    while (isRunning)
    {
        bool shouldRender = true;

        // ♻️ Update the event queue
        eventQueue.update();

        // 🎈 Iterate through that queue:
        while (!eventQueue.empty())
        {
            //Update Events
            const xwin::Event& event = eventQueue.front();

            if (event.type == xwin::EventType::Resize)
            {
                const xwin::ResizeData data = event.data.resize;
                renderer.resize(data.width, data.height);
                shouldRender = false;
            }

            if (event.type == xwin::EventType::Close)
            {
                window.close();
                shouldRender = false;
                isRunning = false;
            }

            eventQueue.pop();
        }

        // ✨ Update Visuals
        if (shouldRender)
        {
            renderer.render();
        }
    }

}