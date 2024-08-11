#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <algorithm>
#include <thread>
#include <vector>
#include <chrono>
#include "Component.h"
#include "GameObjects.h"
#include "CollisionCounter.h"

#include "GameState.h"
#include "GameWorld.h"
#include "GameStateManager.h"
#include "WindowHelper.h"
#include "Graph.h"

#include "Map.h"

bool showTime = false;

void handleSystemEvents(sf::RenderWindow& window)
{

    sf::Event event;
    while (window.pollEvent(event))
    {
        switch (event.type)
        {
        case sf::Event::Closed:
            window.close();
            break;
        case sf::Event::KeyPressed:
            if (event.key.code == sf::Keyboard::Key::Escape)
                window.close();
        default:
            break;
        }
    }
}

void graphTest() {
    Graph g(6);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(2, 4);
    g.addEdge(3, 5);
    g.addEdge(4, 5);

    unsigned start = 0;
    unsigned destination = 5;
    std::vector<unsigned> path = g.bfs(start, destination);

    if (!path.empty()) {
        std::cout << "Path from " << start << " to " << destination << ": ";
        for (unsigned v : path) {
            std::cout << v << " ";
        }
        std::cout << std::endl;
    }
    else {
        std::cout << "No path found from " << start << " to " << destination << std::endl;
    }
}

int main()
{
    graphTest();

    srand(time(0));

    sf::RenderWindow& window = WindowHelper::Instance().GetRenderWindow();

    GameWorld::createInstance(&window);
    GameWorld::Instance()->PostInit();

    GameWorld* gameWorld = GameWorld::Instance();
    GameStateManager gameStateManager(gameWorld, GameStateId::Playing);

    sf::Clock clock;

    while (window.isOpen())
    {
        const float deltaTime = clock.restart().asSeconds();

        handleSystemEvents(window);


        auto start = std::chrono::high_resolution_clock::now();
        gameStateManager.getCurrentGameState()->update(deltaTime);


        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed = end - start;

        std::cout << "\rUpdate execution time: " << elapsed.count() << " seconds\n";

        gameStateManager.getCurrentGameState()->draw(&window);
        gameStateManager.getCurrentGameState()->updateState();

        window.display();
    }

    GameWorld::destroyInstance();

    return 0;
}
