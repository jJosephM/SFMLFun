#include <SFML/Graphics.hpp>
#include <cmath>

int main() {
    // Set up the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "Pendulum");
    window.setFramerateLimit(30); // Set maximum frame rate


    // Set up the pendulum
    sf::Vector2f attachmentPoint(400, 100);
    float rodLength = 200;
    float mass = 20;
    float angle = M_PI / 4.0;
    float angularVelocity = 0;
    float gravity = 9.81;
    sf::Vector2f massPosition(attachmentPoint.x + rodLength * sin(angle), attachmentPoint.y + rodLength * cos(angle));

    // Set up the mass sprite
    sf::CircleShape massShape(mass);
    massShape.setFillColor(sf::Color::Blue);
    massShape.setOrigin(mass, mass);
    massShape.setPosition(massPosition);

    // Game loop
    while (window.isOpen()) {
        // Handle events
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            } else if (event.type == sf::Event::MouseButtonPressed) {
                // Check if the mouse is over the mass
                if (massShape.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)))) {
                    // Compute the new angle based on the mouse position
                    sf::Vector2f mousePosition = window.mapPixelToCoords(sf::Mouse::getPosition(window));
                    angle = atan2(mousePosition.x - attachmentPoint.x, mousePosition.y - attachmentPoint.y);
                }
            } else if (event.type == sf::Event::MouseButtonReleased) {
                // Reset the angular velocity
                angularVelocity = 0;
            }
        }

        // Update the pendulum position
        float angularAcceleration = -gravity / rodLength * sin(angle);
        angularVelocity += angularAcceleration;
        angle += angularVelocity;
        massPosition.x = attachmentPoint.x + rodLength * sin(angle);
        massPosition.y = attachmentPoint.y + rodLength * cos(angle);
        massShape.setPosition(massPosition);

        // Clear the window
        window.clear(sf::Color::White);

        // Draw the pendulum
        sf::VertexArray line(sf::Lines, 2);
        line[0].position = attachmentPoint;
        line[1].position = massPosition;
        line[0].color = sf::Color::Black;
        line[1].color = sf::Color::Black;
        window.draw(line);
        window.draw(massShape);

        // Display the window
        window.display();
    }

    return 0;
}

