#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <chrono>
#include <thread>


/*

  Отвечает за отображение слова

*/



class TypingEffect {
public:
    sf::String m_text;
    sf::Font m_font;
    float m_delay;

    TypingEffect(const sf::String& text, float delay, sf::Font font)
        : m_text(text), m_delay(delay), m_font(font) {}

    void run(sf::RenderWindow& window) {


        sf::Text displayText("", m_font, 30);
        displayText.setPosition(50, 100);

        sf::String currentText;

        for (size_t i = 0; i < m_text.getSize(); ++i) {
            currentText += m_text[i];
            displayText.setString(currentText);

            window.clear();
            window.draw(displayText);
            window.display();

            std::this_thread::sleep_for(std::chrono::seconds(1)); // Дополнительная пауза после завершения эффекта
        }


    }



};
/*

  Отвечает за отображение счетчика

*/

class ShowTime
{
    ShowTime() = default;

public:

    int m_counter;
    sf::Font m_font;
    sf::Text m_text;

    ShowTime(int startValue, sf::Font& font) : m_counter(startValue), m_font(font)
    {
        m_counter = startValue;
        m_text.setFont(m_font);
        m_text.setCharacterSize(24);
        m_text.setFillColor(sf::Color::White);
        m_text.setPosition(750, 10);

    }

    void display(sf::RenderWindow& window)
    {
        while (m_counter > 0)
        {
            window.clear();
            m_text.setString(std::to_string(m_counter));
            window.draw(m_text);
            window.display();
            std::this_thread::sleep_for(std::chrono::seconds(1));
            --m_counter;
        }
    }

};