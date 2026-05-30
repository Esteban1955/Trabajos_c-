#ifndef USER_H
#define USER_H

#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class User {
private:
    int id;
    string name;
    // esta cosa guarda como flechitas (punteros) que apuntan a otros usuarios
    vector<User*> friends; // lista de punteros a otros usuarios

public:
    // Constructor que sin esto no hay datos
    User() {
        id = -1;
        name = "";
    }
    // este es para cuando ya vas directo a crear el usuario con su nombre
    User(int _id, string _name) {
        id = _id;
        name = _name;
    }

    // constructor de copia, por si se ocupa una copia del usuario
    User(const User &other) {
        id = other.id;
        name = other.name;
        friends = other.friends;
    }

    // los "getters" que son solo para poder sacar la info privada desde afuera basicamente
    int getId() { return id; }
    void setId(int _id) { id = _id; }

    string getName() { return name; }
    void setName(string _name) { name = _name; }

    vector<User*> getFriends() { return friends; }

    // aca es donde agregamos los supuestos amigos usando punteros
    void addFriend(User *u) {
        // aqui metemos la dirección del amigo al vector 
        friends.push_back(u);
    }

    // esta funcion es para quitar a los amigos guardados en la lista de amigos
    void removeFriend(User *u) {
        // se busca al amigo en el vector y se quita ese amigo de la lista de amigos
        for (int i = 0; i < friends.size(); i++) {
            if (friends[i] == u) {
                //ahora aca es que si lo encontramos lo quitamos del vector y poco mas
                friends.erase(friends.begin() + i);
                break; 
            }
        }
    }

    //en esta función se junta todo lo del usuario en un solo texto para poderlo imprimir en pantalla
    string toString() {
        string info = "ID: " + to_string(id) + " | Name: " + name + " | Friends: ";
        for (int i = 0; i < friends.size(); i++) {
            // usamos esto porque se estan moviendo punteros
            info += friends[i]->getName() + ", ";
        }
        return info;
    }
};

#endif
