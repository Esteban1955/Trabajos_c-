#ifndef SPELL_H
#define SPELL_H

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <sstream>

using namespace std;

// ============================================================
// Clase abstracta base: Spell
// Define la estructura general de todos los hechizos.
// Contiene métodos virtuales puros que cada hechizo debe implementar.
// ============================================================
class Spell {
public:
    // Retorna el poder base del hechizo
    virtual int getPower() const = 0;

    // Calcula el efecto real del hechizo con variación aleatoria
    virtual void launch() = 0;

    // Retorna una descripción del hechizo como cadena de texto
    virtual string toString() const = 0;

    // Destructor virtual para liberar memoria correctamente en clases derivadas
    virtual ~Spell() {}

    // Operador < para comparar dos hechizos por su poder base
    bool operator<(const Spell& other) const {
        return this->getPower() < other.getPower();
    }

    // Operador == para verificar si dos hechizos tienen el mismo poder base
    bool operator==(const Spell& other) const {
        return this->getPower() == other.getPower();
    }
};


// ============================================================
// Clase derivada: AttackSpell
// Hechizo de ataque con daño básico y daño real con variación aleatoria.
// ============================================================
class AttackSpell : public Spell {
private:
    int basicDamage;  // Daño base del hechizo de ataque
    int realDamage;   // Daño real calculado con variación aleatoria en launch()

public:
    // Constructor por defecto: inicializa daño a 1
    AttackSpell() {
        basicDamage = 1;
        realDamage = 1;
        srand(time(0));  // Inicializa el generador de números aleatorios
    }

    // Constructor de copia: copia los valores de otro AttackSpell
    AttackSpell(const AttackSpell& other) {
        basicDamage = other.basicDamage;
        realDamage = other.realDamage;
        srand(time(0));
    }

    // Constructor con parámetro: inicializa el daño con el valor dado
    AttackSpell(int damage) {
        basicDamage = damage;
        realDamage = damage;
        srand(time(0));
    }

    // Retorna el daño base del hechizo
    int getPower() const override {
        return basicDamage;
    }

    // Calcula el daño real sumando una variación aleatoria entre -10 y 10
    void launch() override {
        int variation = (rand() % 21) - 10;  // Rango: -10 a 10
        realDamage = basicDamage + variation;
    }

    // Retorna una cadena con el daño real causado por el hechizo
    string toString() const override {
        ostringstream oss;
        oss << "AttackSpell: real damage = " << realDamage;
        return oss.str();
    }
};


// ============================================================
// Clase derivada: DefenseSpell
// Hechizo defensivo con defensa básica y defensa real con variación aleatoria.
// ============================================================
class DefenseSpell : public Spell {
private:
    int basicDefense;  // Defensa base del hechizo
    int realDefense;   // Defensa real calculada con variación aleatoria en launch()

public:
    // Constructor por defecto: inicializa defensa a 1
    DefenseSpell() {
        basicDefense = 1;
        realDefense = 1;
        srand(time(0));
    }

    // Constructor de copia: copia los valores de otro DefenseSpell
    DefenseSpell(const DefenseSpell& other) {
        basicDefense = other.basicDefense;
        realDefense = other.realDefense;
        srand(time(0));
    }

    // Constructor con parámetro: inicializa la defensa con el valor dado
    DefenseSpell(int defense) {
        basicDefense = defense;
        realDefense = defense;
        srand(time(0));
    }

    // Retorna la defensa base del hechizo
    int getPower() const override {
        return basicDefense;
    }

    // Calcula la defensa real sumando una variación aleatoria entre -5 y 5
    void launch() override {
        int variation = (rand() % 11) - 5;  // Rango: -5 a 5
        realDefense = basicDefense + variation;
    }

    // Retorna una cadena con la defensa real proporcionada por el hechizo
    string toString() const override {
        ostringstream oss;
        oss << "DefenseSpell: real defense = " << realDefense;
        return oss.str();
    }
};


// ============================================================
// Clase derivada: HealingSpell
// Hechizo de curación con puntos de vida básicos y reales con variación aleatoria.
// ============================================================
class HealingSpell : public Spell {
private:
    int basicHealing;  // Curación base del hechizo
    int realHealing;   // Curación real calculada con variación aleatoria en launch()

public:
    // Constructor por defecto: inicializa la curación a 1
    HealingSpell() {
        basicHealing = 1;
        realHealing = 1;
        srand(time(0));
    }

    // Constructor de copia: copia los valores de otro HealingSpell
    HealingSpell(const HealingSpell& other) {
        basicHealing = other.basicHealing;
        realHealing = other.realHealing;
        srand(time(0));
    }

    // Constructor con parámetro: inicializa la curación con el valor dado
    HealingSpell(int healing) {
        basicHealing = healing;
        realHealing = healing;
        srand(time(0));
    }

    // Retorna la curación base del hechizo
    int getPower() const override {
        return basicHealing;
    }

    // Calcula la curación real sumando una variación aleatoria entre -8 y 8
    void launch() override {
        int variation = (rand() % 17) - 8;  // Rango: -8 a 8
        realHealing = basicHealing + variation;
    }

    // Retorna una cadena con los puntos de vida restaurados por el hechizo
    string toString() const override {
        ostringstream oss;
        oss << "HealingSpell: real healing = " << realHealing;
        return oss.str();
    }
};

#endif
