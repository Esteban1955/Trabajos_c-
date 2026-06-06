#ifndef SPELL_H
#define SPELL_H

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <sstream>

using namespace std;


// La clase Spell define la estructura general de todos los hechizos ademas de contener métodos virtuales de cada hechizo que se va a implementar
class Spell {
public:
    // Aca regresa el poder base del hechizo
    virtual int getPower() const = 0;

    // Se calcula el efecto real del hechizo con una variación aleatoria
    virtual void launch() = 0;

    // Aca se regresa una descripción del hechizo como una cadena de texto
    virtual string toString() const = 0;

    // Este destructor virtual es más que nada para poder liberar memoria a las clases derivadas
    virtual ~Spell() {}

    // Operador boleano "<" es para hacer una comparación de los dos hechizos por su poder base
    bool operator<(const Spell& other) const {
        return this->getPower() < other.getPower();
    }

    // Operador boleano "==" es para hacer una verificación de si los dos hechizos tienen el mismo poder base
    bool operator==(const Spell& other) const {
        return this->getPower() == other.getPower();
    }
};


// Hechizo de ataque con daño básico y daño real con una variación aleatoria.
class AttackSpell : public Spell {
private:
    int basicDamage;  // Este sería el daño base del hechizo de ataque
    int realDamage;   // Este sería el daño real calculandolo con la variación aleatoria en "launch()"

public:
    // Constructor que está por defecto que inicializa daño a 1
    AttackSpell() {
        basicDamage = 1;
        realDamage = 1;
        srand(time(0));  // Aca inicia lo que es el generador de números aleatorios
    }

    // Constructor de copia, y que lo que hace es que copia los valores de otro "AttackSpell"
    AttackSpell(const AttackSpell& other) {
        basicDamage = other.basicDamage;
        realDamage = other.realDamage;
        srand(time(0));
    }

    // Constructor con parámetro, y lo que hace es el inicializar el daño con el valor dado
    AttackSpell(int damage) {
        basicDamage = damage;
        realDamage = damage;
        srand(time(0));
    }

    // Aca se regresa el daño base del hechizo
    int getPower() const override {
        return basicDamage;
    }

    // Aqui se calcula el daño real al sumar una variación aleatoria entre -10 y 10
    void launch() override {
        int variation = (rand() % 21) - 10;  // Aca se le pone el rango de -10 a 10
        realDamage = basicDamage + variation;
    }

    // Regresa una cadena con el daño real causado por el hechizo
    string toString() const override {
        ostringstream oss;
        oss << "AttackSpell: real damage = " << realDamage;
        return oss.str();
    }
};

// Este sería un hechizo defensivo con defensa una básica y una defensa real e igual con una variación aleatoria.
class DefenseSpell : public Spell {
private:
    int basicDefense;  // Este sería la defensa base del hechizo
    int realDefense;   // Este sería la defensa real al ser calculada con la variación aleatoria en "launch()"

public:
    // Constructor que esta por defecto que inicializa defensa a 1 como en el de hechizo de ataque
    DefenseSpell() {
        basicDefense = 1;
        realDefense = 1;
        srand(time(0));
    }

    // Constructor de copia, y pues basicamente copia los valores de otro "DefenseSpell"
    DefenseSpell(const DefenseSpell& other) {
        basicDefense = other.basicDefense;
        realDefense = other.realDefense;
        srand(time(0));
    }

    // Constructor con parámetro, y este inicializaría la defensa con el valor dado
    DefenseSpell(int defense) {
        basicDefense = defense;
        realDefense = defense;
        srand(time(0));
    }

    // Aca se regresa la defensa base del hechizo
    int getPower() const override {
        return basicDefense;
    }

    // Aqui se calcula la defensa real al sumar una variación aleatoria entre -5 y 5
    void launch() override {
        int variation = (rand() % 11) - 5;  // Aca se le pone el rango que sería -5 a 5
        realDefense = basicDefense + variation;
    }

    // Aca se regresa una cadena con la defensa real proporcionada por el hechizo
    string toString() const override {
        ostringstream oss;
        oss << "DefenseSpell: real defense = " << realDefense;
        return oss.str();
    }
};

// Este sería el hechizo de curación con puntos de vida básicos y reales e igual con una variación aleatoria.
class HealingSpell : public Spell {
private:
    int basicHealing;  // Este sería la curación base del hechizo
    int realHealing;   // Este sería la curación real al ser otra vez calculada con su variación aleatoria en "launch()"

public:
    // Constructor por defecto, que inicializa la curación a 1
    HealingSpell() {
        basicHealing = 1;
        realHealing = 1;
        srand(time(0));
    }

    // Constructor de copia, que copia´ra los valores de otro "HealingSpell"
    HealingSpell(const HealingSpell& other) {
        basicHealing = other.basicHealing;
        realHealing = other.realHealing;
        srand(time(0));
    }

    // Constructor con parámetro, que inicializará la curación con el valor dado
    HealingSpell(int healing) {
        basicHealing = healing;
        realHealing = healing;
        srand(time(0));
    }

    // Aca se regresa la curación base del hechizo
    int getPower() const override {
        return basicHealing;
    }

    // Aqui nuevamente se calcula la curación real al sumar una variación aleatoria entre -8 y 8
    void launch() override {
        int variation = (rand() % 17) - 8;  // Este sería el rango -8 a 8
        realHealing = basicHealing + variation;
    }

    // Aca se regresa una cadena con los puntos de vida restaurados por el hechizo
    string toString() const override {
        ostringstream oss;
        oss << "HealingSpell: real healing = " << realHealing;
        return oss.str();
    }
};

#endif
