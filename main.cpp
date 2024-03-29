#include <SFML/Graphics.hpp>
#include <iostream>
#include "src/MyText.hpp"
#include <string>

int main()
{

    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Window");
    window.setFramerateLimit(1);

    sf::Font f1;
    f1.loadFromFile("C:/Users/tamat/OneDrive/Desktop/lections/laba4/sfml_sample/Roboto-Italic.ttf");

    /// m_text.setColor(sf::Color(244, 169, 23));
    // m_text.setString(counterStering);
    // m_text.setCharacterSize(100);


    std::string word = "hello";
    sf::String text(word);
    float delay = 0.3f;

    ShowTime showTime(word.length(), f1);
    TypingEffect typingEffect(text, delay, f1);

    typingEffect.run(window);
    showTime.display(window);




    return 0;
}