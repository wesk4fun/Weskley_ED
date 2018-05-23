#include <iostream>
#include <list>
#include <sstream>
#include <SFML/Graphics.hpp>
#include "sftext.h"

using namespace std;

struct Ambiente{
    list<char> texto;
    list<char>::iterator cursor;
    Ambiente(){
        cursor = texto.end();
    }

    string toString(){
        stringstream ss;
        for(auto it = texto.begin(); it != texto.end(); it++){
            if(it == cursor)
                ss << " ";
            ss << (*it);
        }
        if(cursor == texto.end())
            ss << " ";
        return ss.str();
    }
};

int main()
{
    Ambiente amb;
    amb.texto.push_back('a');
    amb.texto.push_back('m');
    amb.texto.push_back('o');
    amb.texto.push_back('r');

    sf::RenderWindow janela(sf::VideoMode(800, 600), "Janela");

    while(janela.isOpen()){

        sf::Event event;
        while(janela.pollEvent(event)){
            if(event.type == sf::Event::Closed)
                janela.close();
            if(event.type == sf::Event::KeyPressed){
                if(event.key.control && event.key.code == sf::Keyboard::Z){
                        cout << "control z" << endl;
                }
                else if(event.key.control && event.key.code == sf::Keyboard::R){
                        cout << "control r" << endl;
                }
                else if((event.key.code >= sf::Keyboard::A) &&
                   (event.key.code <= sf::Keyboard::Z)){
                    char tecla = (event.key.code - sf::Keyboard::A) + 'a';
                    cout << tecla << endl;
                    amb.texto.insert(amb.cursor, tecla);                }
                else if((event.key.code == sf::Keyboard::Space)){
                    amb.texto.insert(amb.cursor,' ');
                    cout << "espaco" << endl;
                }
                else if((event.key.code == sf::Keyboard::Return)){
                    amb.texto.insert(amb.cursor,'\n');
                    cout << "enter" << endl;
                }


                else if(event.key.code == sf::Keyboard::BackSpace){

                    if(amb.texto.begin()!=amb.cursor){
                    amb.texto.erase(amb.cursor++,amb.cursor--);
                    }
                    cout << "backspace" << endl;
                }
                else if(event.key.code == sf::Keyboard::Delete){
                    cout << "delete" << endl;
                    if(amb.texto.end() != amb.cursor)
                        amb.texto.erase(amb.cursor++);
                }
                else if(event.key.code == sf::Keyboard::Left){
                    amb.cursor--;
                }
                else if(event.key.code == sf::Keyboard::Right){
                    amb.cursor++;
                }
            }
        }

        auto pos = sf::Vector2f(30, 50);
        janela.clear();
        janela.draw(sfText(pos, amb.toString(), sf::Color::White, 30));
        janela.display();
    }
    return 0;
}

