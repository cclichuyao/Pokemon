#ifndef POKEDEX_H
#define POKEDEX_H


#include <TFT.h>
#include <Esplora.h>
#include <SPI.h>

#include "Globals.h"
//#define STEP 40


//struct pokemon
//{
//  char * name;
//  TypeID type;
//  int health;
//  int EV;
//  int xp;
// // moves_t *moves[4];
//  byte moveUsed[8];
//  bool active;
//};


String loadData(int _id, char _lastElement, int _step, char * _filename)
{
  Serial.println("Start Loading Pokemon");
  String ret;
  File f = SD.open(_filename,FILE_READ);
  f.seek(_step*_id);
  ret = f.readStringUntil(_lastElement);
  //Serial.println(ret);
  //Serial.println("Done Loading");
  f.close();
  return ret;
}

PImage getBackImage(int _pokemonNum)
{
  if(_pokemonNum < 1)
    _pokemonNum = 1;
  else if(_pokemonNum > 151)
    _pokemonNum = 151;
  else
    _pokemonNum -= 1;
  String filename;
  filename += "b_";
  filename += _pokemonNum;
  filename += ".bmp";

  return EsploraTFT.loadImage(filename.c_str());
}

PImage getFrontImage(int _pokemonNum)
{
  if(_pokemonNum < 1)
    _pokemonNum = 1;
  else if(_pokemonNum > 151)
    _pokemonNum = 151;
  else
    _pokemonNum -= 1;
  String filename;
  filename += "f_";
  filename += _pokemonNum;
  filename += ".bmp";

  return EsploraTFT.loadImage(filename.c_str());
}

String getType_str(String &_PokemonData)
{
  int typeNum;
  String type = _PokemonData.substring(0,2);
  typeNum = type.toInt();
  switch(typeNum)
  {
    case 0  : return "Poison";   break;
    case 1  : return "Normal";   break;
    case 2  : return "Grass";    break;
    case 3  : return "Fire";     break;
    case 4  : return "Electric"; break;
    case 5  : return "Ground";   break;
    case 6  : return "Rock";     break;
    case 7  : return "Ice";      break;
    case 8  : return "Fighting"; break;
    case 9  : return "Psychic";  break;
    case 10 : return "Bug";      break;
    case 11 : return "Dragon";   break;
    case 12 : return "Ghost";    break;
    case 13 : return "Water";    break;
    defualt : return "BAD INPUT";break;  
  }
}

//enum TypeID { POISON, NORMAL, GRASS, FIRE, ELECTRIC, GROUND, ROCK, ICE, FIGHTING, PSYCHIC, BUG, DRAGON, GHOST, WATER };

TypeID getType(String &_PokemonData)
{
  int typeNum;
  String type = _PokemonData.substring(0,2);
  typeNum = type.toInt();
  switch(typeNum)
  {
    case 0  : return POISON;   break;
    case 1  : return NORMAL;   break;
    case 2  : return GRASS;    break;
    case 3  : return FIRE;     break;
    case 4  : return ELECTRIC; break;
    case 5  : return GROUND;   break;
    case 6  : return ROCK;     break;
    case 7  : return ICE;      break;
    case 8  : return FIGHTING; break;
    case 9  : return PSYCHIC;  break;
    case 10 : return BUG;      break;
    case 11 : return DRAGON;   break;
    case 12 : return GHOST;    break;
    case 13 : return WATER;    break;
    defualt : return NORMAL;   break;  
  }
}

String getHP_str(String &_PokemonData)
{
  return _PokemonData.substring(3,6);
}

int getHP(String &_PokemonData)
{
  return _PokemonData.substring(3,6).toInt();
}

String getAttack_str(String &_PokemonData)
{
  return _PokemonData.substring(7,10);
}

int getAttack(String &_PokemonData)
{
  return _PokemonData.substring(7,10).toInt();
}

String getDefence_str(String &_PokemonData)
{
  return _PokemonData.substring(11,14);
}

int getDefence(String &_PokemonData)
{
  return _PokemonData.substring(11,14).toInt();
}

String getSpecialAttack_str(String &_PokemonData)
{
  return _PokemonData.substring(15,18);
}

int getSpecialAttack(String &_PokemonData)
{
  return _PokemonData.substring(15,18).toInt();
}

String getSpecialDefence_str(String &_PokemonData)
{
  return _PokemonData.substring(19,22);
}

int getSpecialDefence(String &_PokemonData)
{
  return _PokemonData.substring(19,22).toInt();
}

String getSpeed_str(String &_PokemonData)
{
  return _PokemonData.substring(23,26);
}

int getSpeed(String &_PokemonData)
{
  return _PokemonData.substring(23,26).toInt();
}

String getName(String &_PokemonData)
{
  return _PokemonData.substring(27,38);
}

pokemon getPokemon(String &_PokemonData)
{
  pokemon retPokemon;
  retPokemon.name = (char *) getName(_PokemonData).c_str();
  retPokemon.type = getType(_PokemonData); 
  return retPokemon; 
}

stats_t getStats_t(String &_PokemonData)
{
  stats_t retStats_t;
  retStats_t.HP = getHP(_PokemonData);
  retStats_t.Att = getAttack(_PokemonData);
  retStats_t.Def = getDefence(_PokemonData);
  retStats_t.Speed = getSpeed(_PokemonData);
  return retStats_t;
}

///////////////////// MENU DATA
int getElementsNumber(String &_MenuData)
{
  return _MenuData.substring(0,2).toInt();
}

int getPreviousElement(String &_MenuData)
{
  return _MenuData.substring(3,5).toInt();
}

byte getMenuElement(int _id, String &_MenuData)
{
  // the id tells which element of the menu you are trying to load,
  // then I use a switch to load a specific one
  // the ID should be from 0 to 3
  switch(_id)
  {
    case 0: return (byte) _MenuData.substring(6,8).toInt(); break;
    case 1: return (byte) _MenuData.substring(9,11).toInt(); break;
    case 2: return (byte) _MenuData.substring(12,14).toInt(); break;
    case 3: return (byte) _MenuData.substring(15,17).toInt(); break;
    default : return 0;
  }
}

String getMenuElementName(int _id, String &_MenuData)
{
  switch(_id)
  {
    case 0: return _MenuData.substring(18,28); break;
    case 1: return _MenuData.substring(29,39); break;
    case 2: return _MenuData.substring(40,50); break;
    case 3: return _MenuData.substring(51,61); break;
    
  }
}
#endif


