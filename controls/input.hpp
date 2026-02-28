// "pragma once" to specjalne polecenie kompilatora, które sprawia,
// że plik nie zostanie includowany dwa razy
#pragma once

// Prosty struct do przechowywania informacji o tym, jakie gracz 
// ma aktualnie wciśnięte przyciski. Na potrzeby tego kodu ograniczamy się
// na razie do WASD, ale można oczywiście dodać więcej jak potrzeba.
struct Keys {
  bool W = false;
  bool A = false;
  bool S = false;
  bool D = false;
};


Keys get_input();