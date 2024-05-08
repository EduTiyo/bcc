#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

class Aluno {
    private:
        string ra;
        string nome;
    public:
        Aluno(){
            this->ra = "0";
            this->nome = "undefined";
        }
        Aluno(string ra, string nome){
            this->ra = ra;
            this->nome = nome;
        }
        ~Aluno(){/*cout << "Destruindo..." << endl;*/}
        void setRa(string ra){
            this->ra = ra;
        }
        string getRa(){
            return this->ra;
        }
        void setNome(string nome){
            this->nome = nome;
        }
        string getNome(){
            return this->nome;
        }
        void imprimir(){
            cout << "(" << this->getRa() << ", " << this->getNome() << ")" << endl;
        }
};

class Turma{
    private:
        string codigoDisciplina;
        string codigoTurma;
        string semestre;

        Aluno** alunos;
        int tamVet;
        int qtde;
    
    public:
        Turma(string codigoDisciplina, string codigoTurma, int tamVet){
            this->codigoDisciplina = codigoDisciplina;
            this->codigoTurma = codigoTurma;
            this->semestre = "2024-1";
            this->tamVet = tamVet;
            this->qtde = 0;
            this->alunos = new Aluno*[tamVet];
        }
        ~Turma(){}
        void setDisciplina(string disciplina){
            this->codigoDisciplina = disciplina;
        }
        void setTurma(string turma){
            this->codigoTurma = turma;
        }
        void setSemestre(){
            this->semestre = "2024-1";
        }
        void setQtde(int qtde){
            this->qtde = qtde;
        }
        string getDisciplina(){
            return this->codigoDisciplina;
        }
        string getTurma(){
            return this->codigoTurma;
        }
        string getSemestre(){
            return this->semestre;
        }
        int getQtde(){
            return this->qtde;
        }
        void imprimir(){
            cout << "(" << this->getDisciplina() << ", " << this->getTurma() << ", " << this->getSemestre() << ", " << this->getQtde() << ")" << endl;
        }
        bool matricula(Aluno* aluno){
            if(this->qtde == this->tamVet){
                return false;
            }
            this->alunos[this->qtde] = aluno;
            qtde++;
            return true;
        }
        int cancelarMatricula(string ra){
            if(this->tamVet == this->qtde) return this->qtde--;
            int idx = 0;
            while(alunos[idx]->getRa() != ra){
                idx++;
            }

            this->alunos[idx]->~Aluno();

            while(idx < this->qtde){
                this->alunos[idx] = this->alunos[idx+1];
                idx++;
            }

            return this->qtde--;
        }
        void imprimirAlunos(){
            int idx = 0;
            while (idx < this->qtde){
                this->alunos[idx]->imprimir();
                idx++;
            }
        }
};

