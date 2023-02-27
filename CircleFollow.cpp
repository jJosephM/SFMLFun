#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Circle Follows Cursor");
    window.setFramerateLimit(60); // Set maximum frame rate

    sf::CircleShape circle(50.f); // Create a circle
    circle.setFillColor(sf::Color::Red); // Set the circle color

    while (window.isOpen())
    {
        sf::Vector2i mousePosition = sf::Mouse::getPosition(window); // Get the mouse position

        sf::Vector2f circlePosition(mousePosition.x, mousePosition.y); // Set the circle position to the mouse position
        circle.setPosition(circlePosition);

        window.clear(sf::Color::White); // Clear the window
        window.draw(circle); // Draw the circle
        window.display(); // Display the window
    }

    return 0;
}

