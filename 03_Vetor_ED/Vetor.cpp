#include <iostream>

using namespace std;

int main()
{
    struct Vetor{
        int *data;//BLOCO DE DADOS
        int capacidade;//MAXIMO DO VETOR
        int size;//QTD ELEMENTOS DO VETOR

        Vetor(int capacidade){
            this->capacidade = capacidade;
            this->size = 0;
            //this->data = (int*) void * malloc(capacidade * 4);//EM C, RETORNA LIXO
            this->data = new int(capacidade);//C++, RETURN ZERADO
        }

        void push_back(int value){
            if(this->size == this->capacidade)
                return;
            this->data(this->size) = value;
            this->size += 1;
        }
        void pop_back(){
            if(this->size == 0)
                return;
            this->size -= 1;
        }
        int& at(int indice){
            return this->data(indice);
        }
        int& front(){
            return this->data[0];
        }
        int& back(){
            return this->data[this->size -1];
        }
        int begin(){
            return& this->data[0];
        }
        int end(){
            return& this->data[size - 1];
        }

        void reserve(int capacity){
            if(this->capacity < this->capacidade){
                return;
              this->capacidade = capacity;
            }
        /*SALVA O BLOCO ANTIGO EM ALGUM LUGAR
        PEDE UM NOVO BLOCO DE DADOS*/
        }
    };

    /*vector<int> v;
    v.push_back(1);
    v.push_back(3);
    v.push_back(5);

    v.begin();//INTERADOR PRO PRIMEIRO VALOR VALIDO
    v.end();//INTERADOR PRO PRIMEIRO VALOR INVALIDO

    list<int> l = {3, 5, 8, 1, 6};
    for(int x : l)
        cout << x << "";

    cout << "Hello world!" << endl;*/
    Vetor v(5);
    v.push_back(3);
    v.push_back(7);
    v.push_back(5);



    return 0;
}
