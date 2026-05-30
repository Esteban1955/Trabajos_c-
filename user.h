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
    vector<User*> friends; // Lista de punteros a otros usuarios

public:
    // 1. Constructores
    User() {
        id = -1;
        name = "";
    }

    User(int _id, string _name) {
        id = _id;
        name = _name;
    }

    // Constructor de copia (básico)
    User(const User &other) {
        id = other.id;
        name = other.name;
        friends = other.friends;
    }

    // 2. Métodos de Acceso (Getters y Setters)
    int getId() { return id; }
    void setId(int _id) { id = _id; }

    string getName() { return name; }
    void setName(string _name) { name = _name; }

    vector<User*> getFriends() { return friends; }

    // 3. Métodos Operacionales
    void addFriend(User *u) {
        // Añadimos el puntero del amigo a nuestra lista
        friends.push_back(u);
    }

    void removeFriend(User *u) {
        // Buscamos al amigo en el vector y lo quitamos
        for (int i = 0; i < friends.size(); i++) {
            if (friends[i] == u) {
                friends.erase(friends.begin() + i);
                break; 
            }
        }
    }

    string toString() {
        string info = "ID: " + to_string(id) + " | Name: " + name + " | Friends: ";
        for (int i = 0; i < friends.size(); i++) {
            info += friends[i]->getName() + ", ";
        }
        return info;
    }
};

#endif
