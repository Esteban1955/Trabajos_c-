#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <vector>
#include "user.h"

using namespace std;

const int SIZE = 100;
int counter = 0;
vector<User> users(SIZE);

// Función para cargar los datos del archivo TXT
bool loadFile(string filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Error: No se pudo abrir el archivo." << endl;
        return false;
    }

    int n;
    file >> n; // Leer cantidad de usuarios (15 en tu ejemplo)

    // Primera pasada: Crear los usuarios con ID y Nombre
    for (int i = 0; i < n; i++) {
        int id;
        string name;
        file >> id >> name;
        users[i] = User(id, name);
        counter++; 
    }

    // Segunda pasada: Crear las conexiones de amigos
    for (int i = 0; i < n; i++) {
        int userId, numFriends;
        file >> userId >> numFriends;
        for (int j = 0; j < numFriends; j++) {
            int friendId;
            file >> friendId;
            // Agregamos el puntero del usuario amigo
            users[userId].addFriend(&users[friendId]);
        }
    }

    file.close();
    return true;
}

// Función para mostrar todos los usuarios
void displayUsers() {
    for (int i = 0; i < counter; i++) {
        cout << users[i].toString() << endl;
    }
}

// Función para añadir un nuevo usuario manualmente
void addAUser() {
    if (counter >= SIZE) {
        cout << "Memoria llena." << endl;
        return;
    }
    string name;
    cout << "Name? ";
    getline(cin, name);

    // Usamos el 'counter' actual como ID y posición
    users[counter] = User(counter, name);
    counter++;
    cout << "Usuario agregado con exito." << endl;
}

// Función para conectar dos amigos
void addFriendToUser() {
    int id1, id2;
    cout << "--- Lista de usuarios ---" << endl;
    displayUsers();
    
    cout << "Which user do you want to add a friend to? ";
    cin >> id1;
    cout << "Which user do you want to add as a friend? ";
    cin >> id2;

    if (id1 < counter && id2 < counter) {
        users[id1].addFriend(&users[id2]);
        cout << "Ahora " << users[id1].getName() << " es amigo de " << users[id2].getName() << endl;
    } else {
        cout << "IDs invalidos." << endl;
    }
}

// Función para quitar una amistad
void deleteFriendFromUser() {
    int id1, id2;
    displayUsers();
    cout << "Which user do you want to unfriend? ";
    cin >> id1;
    cout << "Which user do you want to remove? ";
    cin >> id2;

    if (id1 < counter && id2 < counter) {
        users[id1].removeFriend(&users[id2]);
        cout << "Amistad eliminada." << endl;
    } else {
        cout << "IDs invalidos." << endl;
    }
}

int main(int argc, char* argv[]) {
    int option;

    // Intentar cargar el archivo al inicio
    if (!loadFile("users.txt")) {
        return -1;
    }

    do { 
        cout << "\n--- MENU FRIENDS CONNECTED ---\n";
        cout << "1. Add a new User\n";
        cout << "2. Display all users\n";
        cout << "3. Add a new Friend to a User\n";
        cout << "4. Remove a Friend from a User\n";
        cout << "5. Exit\n";
        cout << "What do you want to do? ";
        cin >> option;
        
        cin.ignore(); // Limpiar el buffer para el siguiente getline

        switch (option) {
            case 1 : addAUser(); break;
            case 2 : cout << "Users:\n"; displayUsers(); break;
            case 3 : addFriendToUser(); break;
            case 4 : deleteFriendFromUser(); break;
            case 5 : cout << "Saliendo...\n"; break;
            default: cout << "Opcion no valida.\n";
        }
    } while (option != 5);

    return 0;
}
