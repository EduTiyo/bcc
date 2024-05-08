#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Veiculo{
    public:
        virtual ~Veiculo(){}
        virtual Veiculo* clone() const = 0;
        virtual void printInfo() const = 0;
};

class Carro : public Veiculo {
    private:
        string marca_;
        string modelo_;
    public:
        Carro(string marca, string modelo) : marca_(marca), modelo_(modelo) {}
        Veiculo* clone() const override {
            return new Carro(*this);
        }
        void printInfo() const override {
            cout << "Carro - Marca: " << marca_ << ", Modelo: " << modelo_ << endl;
        }
};

class Moto : public Veiculo {
    private:
        string marca_;
        string modelo_;
    public:
        Moto(string marca, string modelo) : marca_(marca), modelo_(modelo) {}
        Veiculo* clone() const override {
            return new Moto(*this);
        }
        void printInfo() const override {
            cout << "Moto - Marca: " << marca_ << ", Modelo: " << modelo_ << endl;
        }
};

class FabricaVeiculo{
    private:
        unordered_map<string, Veiculo*> prototipos_;
    public:
        ~FabricaVeiculo(){
            for(auto it : prototipos_){
                delete it.second;
            }
            prototipos_.clear();
        }

        void registrarPrototipos(const string& key, Veiculo* prototipo){
            prototipos_[key] = prototipo;
        }
        Veiculo* criar(const string& key){
            if(prototipos_.find(key) != prototipos_.end()){
                return prototipos_[key]->clone();
            }
            return nullptr;
        }
};

int main(){
    FabricaVeiculo fabrica;

    fabrica.registrarPrototipos("Carro", new Carro("Toyota", "Corolla"));
    fabrica.registrarPrototipos("Moto", new Moto("Honda", "CBR"));

    Veiculo* carro = fabrica.criar("Carro");
    Veiculo* moto = fabrica.criar("Moto");

    if(carro){
        carro->printInfo();
        delete carro;
    }
    if(moto){
        moto->printInfo();
        delete moto;
    }

    return 0;
    
}