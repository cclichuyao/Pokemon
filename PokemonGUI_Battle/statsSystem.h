#ifndef STATSSYSTEM_H
#define STATSSYSTEM_H

#include "Globals.h"
#include "pokedex.h"

//MyPokemons contains the nesscary information needed to alter the pokemons behaviour
//Each pokemon has a type which will determin a pokemon's weakness'/strengths
//XP scales after each won battle and will determine the pokemons level
//MoveID displays the moves the pokemon contains. Each pokemon can hold 4 individual ID's
//Once the ID's is filled the pokemon will be opted to replace a ID with a differnet ID
//Each time a pokemon learns/rejects a new move from levelling up the the MoveUsed array will change the move from 0 to 1
//To show that the move has been learnt/rejected
pokemon starterPokemon[] = 
{
  {
    "Charmander",                         // Name
    FIRE,                                 // Type
    90,                                    // Health
    0,                                    // EV
    0,                                    // XP
    {nullptr, nullptr, nullptr, nullptr}, // Move id's
    {0, 0, 0, 0, 0, 0, 0, 0},             // Used moves
    false                                     // Active
  },
  {
    "Squirtle",                           // Name
    WATER,                                // Type
    0,                                    // Health
    0,                                    // EV
    0,                                    // XP
    {nullptr, nullptr, nullptr, nullptr}, // Move id's
    {0, 0, 0, 0, 0, 0, 0, 0},             // Used moves
    false                                     // Active
  },
  {
    "Bulbasaur",                          // Name
    GRASS,                                // Type
    0,                                    // Health
    0,                                    // EV
    0,                                    // XP
    {nullptr, nullptr, nullptr, nullptr}, // Move id's
    {0, 0, 0, 0, 0, 0, 0, 0},             // Used moves
    false                                     // Active
  },
  
};




#endif
