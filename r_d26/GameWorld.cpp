#include <thread>
#include <mutex>
#include <algorithm>
#include "GameWorld.h"
#include "GameObjects.h"
#include "Map.h"

GameWorld* GameWorld::ms_gameWorld = nullptr;

GameWorld::GameWorld(sf::RenderWindow* window)
{
    //TODO, Bohdan: MAKE IT DATA-DRIVEN

    NPC* npc1 = new NPC("stone.png", NPC_Behavior::AI_BestRoute);
    NPC* npc2 = new NPC("ball.png", NPC_Behavior::AI_BestRoute);
    NPC* npc3 = new NPC("banana.png", NPC_Behavior::AI_BestRoute); //center of the game window

    m_gameObjects.push_back(&player);
    m_gameObjects.push_back(npc1);
    m_gameObjects.push_back(npc2);
    m_gameObjects.push_back(npc3);

    m_collidableObjects.push_back(npc1);
    m_collidableObjects.push_back(npc2);
    m_collidableObjects.push_back(npc3);
}

void GameWorld::PostInit()
{
    for (auto gameObject : m_gameObjects)
    {
        gameObject->PostInit();
    }
}

GameWorld::~GameWorld()
{
    //TODO, Bohdan: Delete memory used
}

void GameWorld::blur()
{
    m_blurred = true;
}

void GameWorld::unblur()
{
    m_blurred = false;
}

bool checkCollision(const sf::Sprite* sprite1, const sf::Sprite* sprite2)
{
    if (sprite1 && sprite2)
    {
        return sprite1->getGlobalBounds().intersects(sprite2->getGlobalBounds());
    }

    assert(false && "Invalid sprites passed for the collision check");
    return false;
}

//void GameWorld::update(float DeltaTime)
//{
//    //Update all game objects
//    for (GameObject* object : m_gameObjects)
//    {
//        object->update(DeltaTime);
//    }
//
//    //Check Collisions
//    bool isAnyOfCollided = false;
//
//    for (GameObject* box : m_collidableObjects)
//    {
//        if (checkCollision(player.getSprite(), box->getSprite()))
//        {
//            isAnyOfCollided = true;
//            box->getSprite()->setColor(sf::Color::Red);
//        }
//        else
//        {
//            // This color is modulated (multiplied) with the sprite's texture.
//            box->getSprite()->setColor(sf::Color::White);
//        }
//    }
//    m_collisionCounter.update(isAnyOfCollided);
//}

void GameWorld::update(float DeltaTime)
{
    size_t numObjects = m_gameObjects.size();
    size_t numCollidables = m_collidableObjects.size();
    size_t numThreads = 2; // Number of threads to use or std::thread::hardware_concurrency();
    std::vector<std::thread> threads;
    std::mutex collisionMutex;
    bool isAnyOfCollided = false;

    // Divide work for updating game objects
    for (size_t i = 0; i < numThreads; ++i) {
        size_t start = i * (numObjects / numThreads);
        size_t end = (i == numThreads - 1) ? numObjects : (i + 1) * (numObjects / numThreads);
        threads.emplace_back(&GameWorld::updateGameObjects, this, DeltaTime, start, end);
    }
    for (auto& t : threads) {
        t.join();
    }

    threads.clear();

    // Divide work for checking collisions
    for (size_t i = 0; i < numThreads; ++i) {
        size_t start = i * (numCollidables / numThreads);
        size_t end = (i == numThreads - 1) ? numCollidables : (i + 1) * (numCollidables / numThreads);
        threads.emplace_back([this, start, end, &isAnyOfCollided, &collisionMutex]() {
            bool localCollision = false;
            checkCollisions(start, end, localCollision);
            std::lock_guard<std::mutex> lock(collisionMutex);
            isAnyOfCollided = isAnyOfCollided || localCollision;
            });
    }
    for (auto& t : threads) {
        t.join();
    }

    m_collisionCounter.update(isAnyOfCollided);
}

void GameWorld::updateGameObjects(float DeltaTime, size_t start, size_t end)
{
    for (size_t i = start; i < end; ++i) {
        m_gameObjects[i]->update(DeltaTime);
    }
}

void GameWorld::checkCollisions(size_t start, size_t end, bool& isAnyOfCollided)
{
    for (size_t i = start; i < end; ++i) {
        if (checkCollision(player.getSprite(), m_collidableObjects[i]->getSprite())) {
            isAnyOfCollided = true;
            m_collidableObjects[i]->getSprite()->setColor(sf::Color::Red);
        }
        else {
            m_collidableObjects[i]->getSprite()->setColor(sf::Color::White);
        }
    }
}



void GameWorld::draw(sf::RenderWindow* window)
{
    Map::GetInstance().draw(window);

    for (GameObject* object : m_gameObjects)
    {
        object->draw(window);
    }
    
    m_collisionCounter.draw(window);

    if (m_blurred)
    {
        window->draw(m_rectangle);
    }
}
