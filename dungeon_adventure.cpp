#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::cin;
using std::string;

class Direction {
private:
    char directionKey;
    string directionName;

public:
    Direction(char key){

        if (key == 'W' || key == 'w') {
            directionName = "Arriba";
        } else if (key == 'A' || key == 'a') {
            directionName = "Izquierda";
        } else if (key == 'S' || key == 's') {
            directionName = "Abajo";
        } else if (key == 'D' || key == 'd') {
            directionName = "Derecha";
        } else {
            directionName = "Dirección invalida";
        }
        directionKey = key;
    }

    char getKey() const{ return directionKey; }
    string getDirection() const { return directionName; }
    bool isValid() const { return directionName != "Dirección invalida"; }
};

class Player {
private:
    string playerName;
    int playerHealth;
    bool playerHasLockpick;
    bool playerHasCompass;
    int playerScore;

public:
    Player(string name)
        : playerName(name),
          playerHealth(73),
          playerHasLockpick(false),
          playerHasCompass(false),
          playerScore(0) {}

    string getName() const { return playerName; }
    int getHealth() const { return playerHealth; }
    bool hasLockpickItem() const { return playerHasLockpick; }
    bool hasCompassItem() const { return playerHasCompass; }
    int getScore() const { return playerScore; }

    void setHealth(int health) { playerHealth = health; }
    void heal(int amount) { playerHealth += amount; }
    void takenDamage(int damage) { playerHealth -= damage; }
    void addScore(int score) { playerScore += score; }

    void pickupLockpick() {
        playerHasLockpick = true;
        playerScore++;
        cout << "Has recogido una Ganzua." << endl;
    }

    void pickupCompass() {
       cout << "Has recogido la Brujula." << endl;
        playerHasCompass = true;
    }

    void displayStatus() const {
        cout << "\n---" << playerName << "---" << endl;
        cout << "Salud: " << playerHealth << endl;
        cout << "Puntos: " << playerScore << endl;
        cout << (hasLockpickItem() ? " [Ganzua]" : "") << " | " << (hasCompassItem() ? "[Brujula]" : "") << endl;
    }
};

class Room {
private:
    string roomName;
    string roomDescription;

public:
    Room(string name, string description)
        : roomName(name), roomDescription(description) {}

    string getName() const {
        return roomName;
    }

    string getDescription() const {
        return roomDescription;
    }
};

int main()
{
    Player player("idr4");
    Room entrance("Sala de Entrada", "Una sala oscura con 2 pasajes.");
    Room corridor("Corredor Oscuro", "Un pasaje angosto, se escuchan goteos de fondo");

    // Backstory
    cout << "\n========================================" << endl;
    cout << "  UN PROFESOR DE GEOGRAFIA PERDIDA EN LAS MAZMORRAS" << endl;
    cout << "========================================" << endl;
    cout << "\nLa profesor idr4 despierta en una mazmorra oscura..." << endl;
    cout << "\n--- RETROSPECTIVA ---" << endl;
    cout << "idr4, de 42 a" << char(164) << "os, es profesor de geografia en la" << endl;
    cout << "Secundaria Riverside. La semana pasada, llevo a sus alumnos" << endl;
    cout << "a una excursion para estudiar formaciones de cuevas." << endl;
    cout << "Durante la expedicion, resbalo y cayo en un pasaje oculto." << endl;
    cout << "Desperto aqui, herido y sola, sin memoria de cuanto tiempo" << endl;
    cout << "ha estado inconsciente." << endl;
    cout << "\nSus heridas:" << endl;
    cout << "  - Esguince del tobillo izquierdo" << endl;
    cout << "  - Cortaduras y moretones en los brazos" << endl;
    cout << "  - Un golpe en la cabeza" << endl;
    cout << "\nDebe encontrar la salida antes de que sus alumnos" << endl;
    cout << "y colegas dejen de buscarla." << endl;
    cout << "========================================" << endl;


    //entrada

    cout << "\n----" << entrance.getName() << "----" << endl;
    cout << entrance.getDescription() << endl;
    cout << "\nVes: " << endl;
    cout << " W - Arriba - Corredor oscuro" << endl;
    cout << " S - Abajo - Muro Bloqueado" << endl;

    char entranceChoice;
    cout << "\nQue direccion tomas?: ";
    cin >> entranceChoice;


    Direction entranceDir(entranceChoice);

    if(entranceDir.isValid() && entranceDir.getKey() == 'W' || entranceDir.getKey() == 'w') {

        cout << "Te diriges hacia: " << entranceDir.getDirection() << " Vas a entrar al corredor oscuro" << endl;

        cout << "\n----" << corridor.getName() << "----" << endl;
        cout << corridor.getDescription() << endl;

        //switch para direccion dentro de room
        cout << "\nVes 4 esquinas a que direccion vas? (W/A/S/D) " << endl;
        
        char corridorChoice;
        cin >> corridorChoice;
        
        Direction corridorDir(corridorChoice);

        switch(corridorDir.getKey()) {
            case 'W':
            case 'w':
                cout << "Te diriges hacia: " << corridorDir.getDirection() << endl;
                cout << "Encuentras una Brujula en el suelo." << endl;
                player.pickupCompass();
                player.addScore(10);
                break;
            case 'A':
            case 'a':
                cout << "Te diriges hacia: " << corridorDir.getDirection() << endl;
                cout << "encuentras una Ganzua oxidada en el suelo." << endl;
                player.pickupLockpick();
                player.addScore(5);
                break;
            case 'S':
            case 's':
                cout << "Sientes un frio penetrante: " << corridorDir.getDirection() << endl;
                cout << "recibes -5 por ventisca de articuno." << endl;
                player.takenDamage(5);

                break;
            case 'D':
            case 'd':
                cout << "Te diriges hacia: " << corridorDir.getDirection() << endl;
                cout << "Encuentras una puerta bloqueada." << endl;
                if(player.hasLockpickItem()) {
                    cout << "Usas la Ganzua para abrir la puerta." << endl;
                    cout << "Has escapado de la mazmorra!" << endl;
                } else {
                    cout << "Nesesitas algo para abrirla..." << endl;
                }
                break;

        }
        player.displayStatus();
        cout << "\nA la espera de mas aventura!" << endl;
    }
    else if(entranceDir.isValid() && (entranceDir.getKey() == 'S' || entranceDir.getKey() == 's')) {
        cout << "Te diriges hacia: " << entranceDir.getDirection() << endl;
        cout << "La pared esta bloqueada, cuida tu salud." << endl;
        player.takenDamage(3);
        player.displayStatus();
    }
    else {
        cout << "Direccion invalida. No puedes avanzar." << endl;
    }

    cout << "\nAventura terminada!" << endl;
    player.displayStatus();

    cout << "\nPresiona enter para finalizar!" << endl;
    cin.ignore();
    cin.get();

    return 0;
}