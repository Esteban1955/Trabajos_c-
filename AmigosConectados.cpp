#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <vector>
#include "user.h"

using namespace std;

const int SIZE = 100; //máximo de los usuarios porque no hay memoria
int counter = 0; // esto nos dice cuantos usuarios hay realmente
vector<User> users(SIZE);

// Función para cargar los datos del archivo TXT proporcionado por el maestro y llamado "users.txt"
bool loadFile(string filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Error: No se pudo abrir el archivo." << endl;
        return false;
    }

    int n;
    file >> n; // esto hace que lea el numero que dice cuanta gente hay en el archivo

    // primeramente se crea a los usuarios con su id y el nombre
    for (int i = 0; i < n; i++) {
        int id;
        string name;
        file >> id >> name;
        users[i] = User(id, name);
        counter++; 
    }

    // luego aca se conecta los amigos
    for (int i = 0; i < n; i++) {
        int userId, numFriends;
        file >> userId >> numFriends;
        for (int j = 0; j < numFriends; j++) {
            int friendId;
            file >> friendId;
            // le damos aca la direccion del amigo para la funcion "addFriend"
            users[userId].addFriend(&users[friendId]);
        }
    }

    file.close(); //aqui cerramos el archivo para no gastar mas memoria
    return true;
}

// función para mostrar todos los usuarios
void displayUsers() {
    for (int i = 0; i < counter; i++) {
        cout << users[i].toString() << endl;
    }
}

// función para añadir un nuevo usuario manualmente
void addAUser() {
    if (counter >= SIZE) {
        cout << "Memoria llena." << endl;
        return;
    }
    string name;
    cout << "Name? ";
    getline(cin, name);

    // usamos el 'counter' actual como ID y posición en el arrreglo
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

    // checamos que los ids si existan antes de hacer la conexión porque haria error si no me equivoco
    if (id1 < counter && id2 < counter) {
        users[id1].addFriend(&users[id2]);
        cout << "Ahora " << users[id1].getName() << " es amigo de " << users[id2].getName() << endl;
    } else {
        cout << "IDs invalidos." << endl;
    }
}

// función para quitar una amistad o amigo de la lista que tenemos en la lista de usuarios
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

    // Intentar cargar el archivo al inicio, porque sino no tiene ni sentido seguirle
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
        
        cin.ignore(); // aca se limpia lo que nos muestra  cin para que el getline no me falle
        switch (option) {
            case 1 : addAUser(); break;
            case 2 : cout << "Users:\n"; displayUsers(); break;
            case 3 : addFriendToUser(); break;
            case 4 : deleteFriendFromUser(); break;
            case 5 : cout << "Saliendo...\n"; break;
            default: cout << "Opcion no valida.\n";
        }
    } while (option != 5); // aca simplemente la funcion es un bucle que se repide indefinidamente hasta que escojamos salir de el

    return 0;
}
