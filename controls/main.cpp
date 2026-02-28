#include <SFML/Graphics.hpp>

#include "input.hpp"

int main() {
  sf::RenderWindow window(sf::VideoMode({800, 800}), "Okno");
  sf::Texture texture("flower.png");

  sf::Sprite gracz(texture);
  // Ustawiamy pozycję początkową "gracza" (czyli naszego kwiatka) na środek ekranu
  gracz.setPosition({400, 400});

  float playerSpeed = 300; // Prędkość gracza w pikselach na sekundę

  sf::Clock clock; // Zegar do mierzenia czasu między klatkami

  while(window.isOpen()) {
    while(const std::optional event = window.pollEvent()) {
      if(event->is<sf::Event::Closed>()) {
        window.close();
      }
    }
    // Liczymy czas od ostatniej klatki w sekundach
    float deltaTime = clock.restart().asSeconds();
    // Pobieramy aktualny stan klawiatury (które przyciski są wciśnięte)
    Keys keys = get_input();

    // Na podstawie tego, które przyciski są wciśnięte, przesuwamy naszego gracza
    float distance = playerSpeed * deltaTime;
    if(keys.W) {
      gracz.move({0, -distance});
    }
    if(keys.A) {
      gracz.move({-distance, 0});
    }
    if(keys.S) {
      gracz.move({0, distance});
    }
    if(keys.D) {
      gracz.move({distance, 0});
    }
    window.clear();
    window.draw(gracz);
    window.display();
  }
}