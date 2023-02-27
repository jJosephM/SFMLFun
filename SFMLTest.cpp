#include <iostream>
#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(400, 400), "Color Squares");

    // Define the blue square
    sf::RectangleShape blueSquare(sf::Vector2f(200, 200));
    blueSquare.setFillColor(sf::Color::Blue);
    blueSquare.setPosition(0, 0);

    // Define the red square
    sf::RectangleShape redSquare(sf::Vector2f(200, 200));
    redSquare.setFillColor(sf::Color::Red);
    redSquare.setPosition(200, 0);

    // Define the green square
    sf::RectangleShape greenSquare(sf::Vector2f(200, 200));
    greenSquare.setFillColor(sf::Color::Green);
    greenSquare.setPosition(0, 200);

    // Define the yellow square
    sf::RectangleShape yellowSquare(sf::Vector2f(200, 200));
    yellowSquare.setFillColor(sf::Color::Yellow);
    yellowSquare.setPosition(200, 200);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::MouseButtonPressed)
            {
                // Check which square was clicked
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                if (blueSquare.getGlobalBounds().contains(mousePos.x, mousePos.y))
                    std::cout << "You clicked on the blue square" << std::endl;
                else if (redSquare.getGlobalBounds().contains(mousePos.x, mousePos.y))
                    std::cout << "You clicked on the red square" << std::endl;
                else if (greenSquare.getGlobalBounds().contains(mousePos.x, mousePos.y))
                    std::cout << "You clicked on the green square" << std::endl;
                else if (yellowSquare.getGlobalBounds().contains(mousePos.x, mousePos.y))
                    std::cout << "You clicked on the yellow square" << std::endl;
            }
        }

        window.clear();
        window.draw(blueSquare);
        window.draw(redSquare);
        window.draw(greenSquare);
        window.draw(yellowSquare);
        window.display();
    }

    return 0;
}

