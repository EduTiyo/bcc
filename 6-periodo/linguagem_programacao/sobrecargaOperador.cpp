#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Vector2D{
  private:
    float x, y;
  public:
    Vector2D(float x, float y): x(x), y(y) {}
    Vector2D operator+(const Vector2D& other){
      return Vector2D(this->x + other.x, this->y + other.y);
    }
    float getX() const { return x; }
    float getY() const { return y; }
};

class Pessoa {
  private:
    string nome;
    int idade;
  public: 
    Pessoa(string nome, int idade): nome(nome), idade(idade) {}

    bool operator<(const Pessoa& other) const {
      return this->idade < other.idade;
    }

    friend ostream& operator<<(ostream& os, const Pessoa& pessoa) {
      os << pessoa.nome << ": " << pessoa.idade << " anos";
      return os;
    }

};

int main()
{
  Vector2D v1(1.0f, 2.0f);
  Vector2D v2(3.0f, 4.0f);
  Vector2D v3 = v1 + v2;
  cout << "v3: (" << v3.getX() << ", " << v3.getY() << ")" << endl;

  vector<Pessoa> pessoas = {
    {"Alice", 30},
    {"Bob", 25},
    {"Charlie", 35}
  };

  sort(pessoas.begin(), pessoas.end());

  for(const auto& pessoa : pessoas) {
    cout << pessoa << endl;
  }
  
  return 0;
}
