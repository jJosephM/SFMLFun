#include <SFML/Graphics.hpp>
#include <cmath>

int main()
{
    // set up the window
    sf::RenderWindow window(sf::VideoMode(800, 800), "Chladni Plate");

    // set up the plate dimensions
    int rows = 20;
    int cols = 20;
    float width = 800.0f / cols;
    float height = 800.0f / rows;

    // set up the nodes on the plate
    float nodes[cols][rows] = {};
    float frequency = 3.0f;
    float velocity = 300.0f;
    float time = 0.0f;

    // update the nodes over time
    while (window.isOpen())
    {
        // handle events
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        // update the nodes
        time += 0.01f;
        for (int i = 0; i < cols; i++)
        {
            for (int j = 0; j < rows; j++)
            {
                float x = i * width;
                float y = j * height;
                float displacement = sin(frequency * time) * sin((float)i * M_PI / (cols - 1)) * sin((float)j * M_PI / (rows - 1));
                nodes[i][j] = displacement;
            }
        }

        // clear the window
        window.clear();

        // draw the nodes
        for (int i = 0; i < cols; i++)
        {
            for (int j = 0; j < rows; j++)
            {
                float x = i * width;
                float y = j * height;
                float displacement = nodes[i][j];
                sf::CircleShape circle(2.0f);
                circle.setOrigin(circle.getRadius(), circle.getRadius());
                circle.setPosition(x + width / 2.0f, y + height / 2.0f);
                circle.setFillColor(sf::Color::White);
                window.draw(circle);
            }
        }

        // display the window
        window.display();
    }

    return 0;
}
