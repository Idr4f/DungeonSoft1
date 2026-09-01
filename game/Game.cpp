#include "Game.h"
#include "direction/Direction.h"
#include <iostream>
#include "player/Player.h"

using std::cin;
using std::cout;
using std::endl;

Game::Game(): player(player), 
    entrance("Sala de Entrada", "Una sala oscura con 2 pasajes."),
    corridor("Corredor Oscuro", "Un pasaje angosto, se escuchan goteos de fondo"),
    treasure("Sala del Tesoro", "Una sala brillante llena de oro y joyas."),
    lucky(){};


void Game::run(){

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

        Room treasureRoom("Sala del Tesoro", "Una sala brillante llena de oro y joyas.");

        cout << "Te diriges la nueva sala: " << treasureRoom.getName() << endl;
        cout << treasureRoom.getDescription() << endl;


        cout << "Antes de pasar la puerta de entrada de la sala, te encuentras con el problema de q esta cerrada y no tienes la llave." << endl;
        if(player.hasLockpickItem()) {
            cout << "Usas la Ganzua para abrir la puerta? (S o N)" << endl;
            
            string userInput;

            cin >> userInput; 

            if( userInput == "s" && Lucky().throw_coin()) {

                cout << "Tienes suerte! La puerta se abre sin problemas." << endl;
                
                cout << "Al entrar sientes un aire tibio que revitaliza tu ser" << endl;
                player.fullHeal();
                cout << "recibees una curacion completa" << endl;

                cout << "Luteas la mazmorra con exito!" << endl;
                player.addScore(50);
                cout << "Has escapado de la mazmorra!" << endl;
                 
            } else if( userInput == "S") {

                cout << "La Ganzua se rompe al intentar abrir la puerta." << endl;
                player.takenDamage(10);
                player.displayStatus();
            }else {

                cout << "Decides no usar la Ganzua y buscar otra salida." << endl;
            }

        } else {
            cout << "Nesesitas algo para abrirla..." << endl;
        }

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
}