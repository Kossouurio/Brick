#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>

class Ball
{
public:
    Ball(int posX, int posY, int vectX, int vectY, int speed);

    void DrawBall();
    void Update();

private:
    int posX; /// GetScreenWidth() / 2
    int posY; /// GetScreenHeight() / 2
    int vectX; /// 5
    int vectY; /// 4
    float speed; /// 1.4f
    int ballRadius; /// 20
};

Ball::Ball(int posX, int posY, int vectX, int vectY, int speed):
    posX(posX),
    posY(posY),
    vectX(vectX),
    vectY(vectY),
    speed(speed)
{
}

//void Ball::DrawBall()
//{
//    DrawCircleV(ballPosition, ballRadius, color);
//
//}
//
//void Ball::Update()
//{
//    ballPosition.x += ballSpeed.x;
//    ballPosition.y += ballSpeed.y;
//
//    if ((ballPosition.x >= (GetScreenWidth() - ballRadius)) || (ballPosition.x <= ballRadius)) { ballSpeed.x *= -1.0f; }
//    if ((ballPosition.y >= (GetScreenHeight() - ballRadius)) || (ballPosition.y <= ballRadius)) { ballSpeed.y *= -1.0f; }
//}


int main()
{
    sf::Clock clock;
    float deltaTime = 0.0f;

    // window
    sf::RenderWindow window(sf::VideoMode(1200, 800), "Bricks");
    window.setMouseCursorVisible(0);

    // plate
    sf::RectangleShape plate({ 100, 10 });
    plate.setFillColor(sf::Color::White);
    plate.setPosition(window.getSize().x / 2, window.getSize().y - 40);

    // ball
    sf::CircleShape ball(10);
    ball.setFillColor(sf::Color::Cyan);
    ball.setPosition(plate.getPosition().x + plate.getSize().x / 2 - ball.getRadius(), plate.getPosition().y - plate.getSize().y - ball.getRadius());
    int vectX = -30; /// 5
    int vectY = -20; /// 4
    float speed = 20.3f; /// 1.4f

    while (window.isOpen())
    {
        deltaTime = clock.restart().asSeconds();

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        // update
        plate.setPosition(sf::Mouse::getPosition(window).x - 50, window.getSize().y - 40);
        ball.setPosition(ball.getPosition().x + vectX * speed * deltaTime, ball.getPosition().y + vectY * speed * deltaTime);
        if ((ball.getPosition().x >= (window.getSize().x - ball.getRadius())) || (ball.getPosition().x <= ball.getRadius())) { vectX *= -1.0f; };
        if ((ball.getPosition().y >= (window.getSize().y - ball.getRadius())) || (ball.getPosition().y <= ball.getRadius())) { vectY *= -1.0f; };


        window.clear();
        window.draw(plate);
        window.draw(ball);
        window.display();
    }

    return 0;
}

