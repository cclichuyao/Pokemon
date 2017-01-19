#ifndef BATTLESYSTEM_H
#define BATTLESYSTEM_H
#include "Globals.h"
#include "statsSystem.h"
#include "GUI.h"
#include "pokedex.h"

byte modifier[4][4];

//Take in the types from statsystem and alters the modifier value depending on the type match up. 
//For example if FIRE against WATER water will do more damage.
//This modifiers value is then taken in and applied to the damage dealt equation
void initialiseTypes() {
  modifier[FIRE][FIRE]          = 100;
  modifier[FIRE][WATER]         = 75;
  modifier[FIRE][GRASS]         = 125;
  modifier[FIRE][ELECTRIC]      = 100;

  modifier[WATER][FIRE]         = 125;
  modifier[WATER][WATER]        = 100;
  modifier[WATER][GRASS]        = 75;
  modifier[WATER][ELECTRIC]     = 75;

  modifier[GRASS][FIRE]         = 75;
  modifier[GRASS][WATER]        = 125;
  modifier[GRASS][GRASS]        = 100;
  modifier[GRASS][ELECTRIC]     = 100;
  
  modifier[ELECTRIC][FIRE]      = 100;
  modifier[ELECTRIC][WATER]     = 125;
  modifier[ELECTRIC][GRASS]     = 100;
  modifier[ELECTRIC][ELECTRIC]  = 100;
}


int typeMultiplier(TypeID _attType, TypeID _defType)
{
    switch(_attType)
    {
        case POISON :
        {
            switch(_defType)
            {
                case GRASS    : return 200; break;
                case POISON   : return 50;  break;
                case GROUND   : return 50;  break;
                case BUG      : return 200; break;
                case ROCK     : return 50;  break;
                case GHOST    : return 50;  break;
                default       : return 100; break;
            }
        }break;
        case NORMAL :
        {
            switch(_defType)
            {
                case ROCK     : return 50; break;
                case GHOST    : return 50; break;
                default       : return 100; break;
            }
        }break;
        case GRASS :
        {
            switch(_defType)
            {
                case FIRE     : return 50;  break;
                case WATER    : return 200; break;
                case GRASS    : return 50;  break;
                case POISON   : return 50;  break;
                case GROUND   : return 200; break;
                case BUG      : return 50;  break;
                case ROCK     : return 200; break;
                case DRAGON   : return 50;  break;
                default       : return 100; break;
            }break;
        }break;
        case FIRE :
        {
            switch(_defType)
            {
                case FIRE     : return 50;  break;
                case WATER    : return 50;  break;
                case GRASS    : return 200; break;
                case ICE      : return 200; break;
                case BUG      : return 200; break;
                case ROCK     : return 50;  break;
                case DRAGON   : return 50;  break;
                default       : return 100; break;
            }
        }break;
        case ELECTRIC :
        {
            switch(_defType)
            {
                case WATER    : return 200; break;
                case GRASS    : return 50;  break;
                case ELECTRIC : return 50;  break;
                case GROUND   : return 0;   break;
                case DRAGON   : return 50;  break;
                default       : return 100; break;
            }
        }break;
        case GROUND :
        {
            switch(_defType)
            {
                case FIRE     : return 200; break;
                case ELECTRIC : return 200; break;
                case GRASS    : return 50;  break;
                case POISON   : return 200; break;
                case BUG      : return 50;  break;
                case ROCK     : return 200; break;
                default       : return 100; break;
            }
        }break;
        case ROCK :
        {
            switch(_defType)
            {
                case FIRE     : return 200; break;
                case ICE      : return 200; break;
                case FIGHTING : return 50;  break;
                case GROUND   : return 50;  break;
                case BUG      : return 200; break;
                default       : return 100; break;
            }
        }break;
        case ICE :
        {
            switch(_defType)
            {
                case WATER    : return 50;  break;
                case GRASS    : return 200; break;
                case ICE      : return 50;  break;
                case GROUND   : return 200; break;
                case DRAGON   : return 200; break;
                default       : return 100; break;
            }
        }break;
        case FIGHTING :
        {
            switch(_defType)
            {
                case NORMAL   : return 200; break;
                case ICE      : return 200; break;
                case POISON   : return 50;  break;
                case PSYCHIC  : return 50;  break;
                case BUG      : return 50;  break;
                case ROCK     : return 200; break;
                case GHOST    : return 0;   break;
                default       : return 100; break;
            }
        }break;
        case PSYCHIC :
        {
            switch(_defType)
            {
                case FIGHTING : return 200; break;
                case POISON   : return 200; break;
                case PSYCHIC  : return 50;  break;
                default       : return 100; break;
            }
        }break;
        case BUG :
        {
            switch(_defType)
            {
                case FIRE     : return 50;  break;
                case GRASS    : return 200; break;
                case FIGHTING : return 50;  break;
                case POISON   : return 200; break;
                case PSYCHIC  : return 200; break;
                default       : return 100; break;
            }
        }break;
        case DRAGON :
        {
            switch(_defType)
            {
                case DRAGON   : return 200; break;
                default       : return 100; break;
            }
        }break;
        case GHOST :
        {
            switch(_defType)
            {
                case GHOST    : return 200; break;
                case NORMAL   : return 0;   break;
                case PSYCHIC  : return 0;   break;
                default       : return 100; break;
            }
        }break;
        case WATER :
        {
            switch(_defType)
            {
                case DRAGON   : return 50;  break;
                case FIRE     : return 200; break;
                case GRASS    : return 50;  break;
                case WATER    : return 50;  break;
                case GROUND   : return 200; break;
                case ROCK     : return 200; break;
                default       : return 100; break;
            }
        }break;
        default : return 100; break;
    }
}


int calcDamage(moves_t* attack, pokemon _myPokemon, pokemon _enemyPokemon)
{
  if ( random(0, 100) > attack->acc ) 
  {
    return 0;
  } 
  else 
  {
    return ((2 * getLevel(_myPokemon.xp) + 10) / 250.0f * statSystem(_myPokemon).Att / (float)statSystem(_enemyPokemon).Def * attack->power + 2) * (typeMultiplier(_myPokemon.type, _enemyPokemon.type) / 100.f);
  }
}



void renderBattleText(char *first, char *second, char *third)
{
    int xPos1 = (160 / 2) - (strlen(first) * 12 / 2);
    int xPos2 = (160 / 2) - (strlen(second) * 12 / 2);
    int xPos3 = (160 / 2) - (strlen(third) * 12 / 2);
    EsploraTFT.setTextSize(2);
    EsploraTFT.stroke(255, 255, 255);
    EsploraTFT.text(first, xPos1, 30);
    delay(500);
    EsploraTFT.text(second, xPos2, 50);
    delay(500);
    EsploraTFT.text(third, xPos3, 70);
}

void renderBattleDisplay()
{
  bool enemyTurn = true; 
  bool hostTurn = true;

  // When the function will be added need to change to the map from 0 to 80.
  
  uint8_t healthbarSize = 75;
  
  uint8_t enemyHealth = map(80, 0, 100, 0, healthbarSize); 
  uint8_t hostHealth = map(39, 0, 100, 0, healthbarSize); 

  uint8_t enemyTextX = 10;
  uint8_t enemyTextY = 10;

  uint8_t hostTextX = 85;
  uint8_t hostTextY = 98;

  uint8_t textColor[3] = {255,255,255};
  uint8_t enemyColor[3] = {255,0,0};
  uint8_t hostColor[3] = {0,0,255};
  

  EsploraTFT.background(0,0,0);

  //Enemy stats
  EsploraTFT.setTextSize(1);

  //Enemy stats rect 
  // TODO: Change to color depending on a poketype
  EsploraTFT.stroke(enemyColor[0],enemyColor[1],enemyColor[2]);
  EsploraTFT.fill(enemyColor[0],enemyColor[1],enemyColor[2]);
  EsploraTFT.rect(enemyTextX - 5, enemyTextY - 5, 75, 30); 

    //Enemy image
  EsploraTFT.rect(95, 5, 55, 55);

  //Enemy healthbar
  EsploraTFT.fill(0, 255, 0);
  EsploraTFT.noStroke();
  EsploraTFT.rect(enemyTextX - 5, enemyTextY + 26, enemyHealth, 8);
  EsploraTFT.noFill();
  EsploraTFT.stroke(255, 255, 255);
  EsploraTFT.rect(enemyTextX - 5, enemyTextY + 26, healthbarSize, 8);


  // Host poke name
  EsploraTFT.stroke(textColor[0],textColor[1],textColor[2]);
  EsploraTFT.text("ENEMY!",enemyTextX, enemyTextY);
  // Host stats 
  EsploraTFT.text("Lv08 male", enemyTextX, enemyTextY + 12);



  //Host Stats
  EsploraTFT.stroke(hostColor[0],hostColor[1],hostColor[2]);
  EsploraTFT.fill(hostColor[0],hostColor[1],hostColor[2]);
  EsploraTFT.rect(hostTextX - 5, hostTextY - 5, 75, 30);

    //Host image
  EsploraTFT.rect(5, 58, 65, 65);

    //Host healthbar
  EsploraTFT.fill(0, 255, 0);
  EsploraTFT.noStroke();
  EsploraTFT.rect(hostTextX - 5, hostTextY - 14, hostHealth, 8);
  EsploraTFT.noFill();
  EsploraTFT.stroke(255, 255, 255);
  EsploraTFT.rect(hostTextX - 5, hostTextY - 14, healthbarSize, 8);
   
  // Host name
  EsploraTFT.setTextSize(1); 
  EsploraTFT.stroke(textColor[0],textColor[1],textColor[2]);
  EsploraTFT.text(starterPokemon[selectedPokemon].name, hostTextX, hostTextY);
  // Host stats 
  EsploraTFT.text("Lv08 woman", hostTextX, hostTextY + 12);
}





#endif
