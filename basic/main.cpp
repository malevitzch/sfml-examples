#include <SFML/Graphics.hpp>

int main() {
  // Program jest na podstawie tutorialu na oficjalnej stronie biblioteki SFML
  // https://www.sfml-dev.org/documentation/3.0.2/


  // Tworzymy okno
  sf::RenderWindow window(sf::VideoMode({800, 600}), "Okno");

  // Tworzymy teksturę z obrazka "flower.png". 
  // Obrazek musi być w tym samym katalogu co plik wykonywalny (.exe)
  // Więcej informacji: https://www.sfml-dev.org/documentation/3.0.2/classsf_1_1Texture.html
  // Tekstura to po prostu grafika załadowana z pliku do pamięci programu, można używać tej samej
  // tekstury dla wielu spritów. Nie chcemy wiele razy mieć tego samego obrazka w ramie, bo to niepotrzebne
  // i marnuje pamięć, dlatego ładujemy kwiatek tylko raz.
  sf::Texture texture("flower.png");

  // Sprite to obrazek, który ma swoją pozycję na ekranie i inne ciekawe rzeczy, można go przesuwać, obracać,
  // i wykonywać inne podobne czynności.
  // Dokumentacja: https://www.sfml-dev.org/documentation/3.0.2/classsf_1_1Sprite.html
  sf::Sprite kwiatek(texture);
  sf::Sprite kwiatek2(texture);
  kwiatek2.setPosition({400, 300});
  kwiatek2.setScale({5, 5});

  // Z okienkami jest tak samo, jak ze zmiennymi w normalnym programie.
  // Jak zmienna "window" zniknie (skończy się program), to okno się zamknie.
  // Robimy pętlę while, w której będziemy opisywać jak okno się zachowuje
  while(window.isOpen()) {

    /*
      Jest to dziwna składnia pętli while, ogólna idea jest następująca:
      Wszystko co robimy w okienku (kliknięcia, przesuwanie myszki, pisanie na klawiaturze)
      jest rejestrowane jako wydarzenie ("event"). 
      W poniższej pętli przetwarzamy eventy dopóki są jakieś.
    */

    while(const std::optional event = window.pollEvent()) {
      // Jeśli event który mamy, to jest event zamknięcia okienka, to je zamykamy.
      // Event zamknięcia okienka jest wysyłany gdy klikniemy "x" w prawym górnym rogu.
      if(event->is<sf::Event::Closed>()) {
        window.close();
      }
      window.clear();
    }

    // Aby nasze kwiatki pojawiły się na ekranie, musimy wywołać funkcję "draw".
    // Można myśleć o tym tak, że draw po prostu wkleja rysunek na ekran, jak Ctrl-C Ctrl-V w paincie
    window.draw(kwiatek);
    window.draw(kwiatek2);

    // Window.display() służy do akutalizacji okienka widzianego przez użytkownika. W ten sposób nigdy 
    // nie widać takiego "połowicznego narysowania", dopóki nie zrobimy window.display() to okienko się nie aktualizuje
    window.display();
  }
}