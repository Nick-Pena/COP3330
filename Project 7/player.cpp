#include "player.h"

Player::Player()
{
    maxSize = 6;
    currentSize = 3;

    coins = 0;
    potions = 0;

    //GrassMonster* grass = new GrassMonster(0);
    //FireMonster* fire = new FireMonster(1);
    //WaterMonster* water = new WaterMonster(2);

    monsterList = new Monster*[maxSize];

    monsterList[0] = new GrassMonster(0);
    monsterList[1] = new FireMonster(1);
    monsterList[2] = new WaterMonster(2);
    
    x_coord = 0;
    y_coord = 0;
}

Player::Player(int x_in, int y_in)
{
    maxSize = 6;
    currentSize = 3;

    coins = 0;
    potions = 0;

    //GrassMonster* grass = new GrassMonster(0);
    //FireMonster* fire = new FireMonster(1);
    //WaterMonster* water = new WaterMonster(2);

    monsterList = new Monster*[maxSize];

    monsterList[0] = new GrassMonster(0);
    monsterList[1] = new FireMonster(1);
    monsterList[2] = new WaterMonster(2);

    x_coord = x_in;
    y_coord = y_in;
}

Player::~Player()
{
    //cout << "Destroying player's list of monsters" << endl;
    for(int i = 0; i < currentSize; i++)
    {
        delete monsterList[i];
    }
}

int Player::GetX() const
{
    return x_coord;
}

int Player::GetY() const
{
    return y_coord;
}

void Player::SetX(int x_in)
{
    x_coord = x_in;
}

void Player::SetY(int y_in)
{
    y_coord = y_in;
}

int Player::GetCoinCount() const
{
    return coins;
}

int Player::GetMonsterCount() const
{
    return currentSize;
}

int Player::GetPotionCount() const
{
    return potions;
}

void Player::AddMonster(Monster*& newMon)
{
    if(currentSize == maxSize)
        Grow();
    
    //cout << endl << endl << endl;
    //cout << "!!!!!!!!!!!!ADDING MONSTER\n";
    char typeG[] = "Grass";
    char typeF[] = "Fire";
    char typeW[] = "Water";


    
    if (strcmp(typeG, newMon->GetType()) == 0){


        Monster* tempGrass = new GrassMonster(currentSize, newMon->GetSize());
       // tempGrass = newMon;
        monsterList[currentSize] = tempGrass;
    }
    else if (strcmp(typeF, newMon->GetType()) == 0){


        Monster* tempFire = new FireMonster(currentSize, newMon->GetSize());

        monsterList[currentSize] = tempFire;
    }
    else if (strcmp(typeW, newMon->GetType()) == 0){

        Monster* tempW = new WaterMonster(currentSize, newMon->GetSize());
        monsterList[currentSize] = tempW;
    }
    currentSize++;
    //cout << endl << endl << endl;
    //cout << "!!!!!!!!!!!Monster is added.\n";

    //cout << "Print All monsters" << endl;

    //PrintMonList();

    

    
}

/*void Player::RemoveMonster(Monster*& remMon)
{
    cout << "Shifting monster array down one\n";
    cout << "Passed index " << remMon->GetNumber() << '\n';
    cout << "Current monster size array " << currentSize << '\n';
    //delete monsterList[remMon->GetNumber()];
    cout << "Deleting monster: " << endl;
    PrintMonData(remMon->GetNumber());
    for(int i = remMon->GetNumber() + 1; i < currentSize; i++)
    {
        monsterList[i - 1] = monsterList[i];
    }
    monsterList[currentSize - 1] = NULL;

    currentSize--;
}
*/

void Player::RemoveMonster(int ind){
    PrintMonData(ind);
    for(int i = ind + 1; i < currentSize; i++)
    {
        monsterList[i - 1] = monsterList[i];
    }
    monsterList[currentSize - 1] = NULL;

    currentSize--;
}

bool Player::PlayerMonSpAtk(int index, Monster* wildMon)
{
    monsterList[index]->SpecialAttack(wildMon);
    if(wildMon->GetHealth() > 0)
        return true;   // IF IT IS ALIVE
    else
        return false;  // IF IT IS DEAD
}

bool Player::PlayerMonPhysAtk(int index, Monster* wildMon)
{
    monsterList[index]->PhysicalAttack(wildMon);
    if(wildMon->GetHealth() > 0)
        return true;   // IF IT IS ALIVE
    else
        return false;  // IF IT IS DEAD
}

void Player::PrintMonList() ////////////////made some changes (need to delete them)
{
    for(int i = 0; i < currentSize; i++)
    {
        cout << "Monster # " << i << '\n';
        monsterList[i]->PrintMonsterData();
        cout << "\n";
    }
}

void Player::PrintMonData(int ind) const{
    monsterList[ind]->PrintMonsterData();
}

void Player::Grow()
{
    // Grows the pairs array if needed
    // Increase max size of the array
    maxSize = currentSize + 1;
    // Create a new temporary pair array with the size of the new max size
    Monster** tempList = new Monster*[maxSize];

    // Copy all elements from old array to the new array
    for(int i = 0; i < currentSize; i++)
    {
        tempList[i] = monsterList[i];
    }

    // De-allocate the old array
    delete [] monsterList;

    // Re-point to the newly sized array
    monsterList = tempList;
}

Monster** Player::GetMonsterList() const
{
    return monsterList;
}

Monster* Player::GetPlayerMon(int index) const
{
    return monsterList[index];
}

void Player::AddCoin()
{
    coins++;
}

void Player::AddPotion()
{
    potions++;
}

void Player::RemovePotion()
{
    potions--;
}

void Player::MovePlayer(char char_in, int mapSide)
{
    switch(char_in)
    {
        case 'W':
            if(y_coord > 1)
                y_coord--;
                
            break;

        case 'S':
            if(y_coord < (mapSide - 2))
                y_coord++;

            break;

        case 'D':
            if(x_coord < (mapSide - 2))
                x_coord++;

            break;

        case 'A':
            if(x_coord > 1)
                x_coord--;

            break;
    }
}