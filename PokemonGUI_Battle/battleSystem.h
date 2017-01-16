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





#endif
