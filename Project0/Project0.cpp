
#include <iostream>
#include "Trainer.h"


void printPets(Trainer& trainer) {
    cout << "Printing pets for " << trainer.getName() << endl;
    for (int index = 0; index < trainer.getCurrentNumberOfFightingPets(); index++) {
        cout << trainer.getFightingPet(index).getName() << endl;
    }
}

int main()
{
    Trainer trainer;
    trainer.setName("Eric");
    FightingPet pet(1, "fire pet", 10);
    trainer.addFightingPet(pet);

    Trainer trainer2;
    trainer2.setName("Jeb");
    FightingPet otherPet(2, "water pet", 20);
    trainer2.addFightingPet(otherPet);

    Trainer trainer3(trainer);
    trainer3.setName("Eric copy");
    FightingPet morePet(3, "grass pet", 30);
    trainer3.addFightingPet(morePet);

    printPets(trainer);
    printPets(trainer2);
    printPets(trainer3);
    printPets(trainer);

    cout << "assign trainer 3 to trainer 2" << endl;
    trainer2 = trainer3;

    trainer2.setName("Eric copy copy");

    cout << "Add electric pet to trainer 2" << endl;
    FightingPet electricPet(5, "electric pet", 50);
    trainer2.addFightingPet(electricPet);

    printPets(trainer2);
    printPets(trainer3);

    

}
