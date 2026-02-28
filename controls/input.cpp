#include "input.hpp"
#include <SFML/Graphics.hpp>

// Za pomocą sf::Keyboard::isKeyPressed możemy sprawdzić, czy konkretne
// przyciski są akurat wciśnięte. 
// Wywołanie tej funkcji "sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)"
// zwraca "true" jeśli "W" jest akurat kliknięte, "false" jak nie jest
Keys get_input() {
  Keys keys;
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
    keys.W = true;
  }
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
    keys.A = true;
  }
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
    keys.S = true;
  }
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
    keys.D = true;
  }
  return keys;
}