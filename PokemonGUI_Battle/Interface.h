#ifndef INTERFACE_H
#define INTERFACE_H

#include "Globals.h"
//#include "Globals.h"
#include "GUI.h"
#include "pokedex.h"
#include "Network.h"
#include "battleSystem.h"
#include "statsSystem.h"


//int getTypeColor(TypeID _type)
//{
//  int color[3]={};
//  switch(_type)
//  {
//    case POISON: color[0]=130; color[1]=0; color[3]=75; break; //purple
//    case NORMAL:color[0]=255; color[1]=255; color[3]=255; ;break;//white
//    case GRASS:color[0]=0; color[1]=255; color[3]=0; break;//green
//    case FIRE:color[0]=0; color[1]=0; color[3]=255; break;//red
//    case ELECTRIC:color[0]=0; color[1]=255; color[3]=255;break;//yellow
//    case GROUND:color[0]=65; color[1]=77; color[3]=90; break;//ground brown;
//    case ROCK:color[0]=98; color[1]=98; color[3]=98; break;//dark grey
//    case ICE:color[0]=230; color[1]=224; color[3]=176;break;//light blue
//    case FIGHTING:color[0]=48; color[1]=48; color[3]=129;break;//dark red
//    case PSYCHIC:color[0]=0; color[1]=204; color[3]=204;break;//greenish yellow
//    case BUG:color[0]=102; color[1]=255; color[3]=102;break;//light green
//    case DRAGON:color[0]=0; color[1]=0; color[3]=102;break; //dark red
//    case GHOST:color[0]=128; color[1]=128; color[3]=128;break;//grey
//    case WATER:color[0]=0; color[1]=0; color[3]=255;break;//blue
//  }
//  return color;
//}


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
 // unit8_t enemyPokemonColor[]={};
 // unit8_t myPokemonColor[]={};
  

   
  int enemyXP=100;
  String enemyLevelOut;
  enemyLevelOut=getLevel(enemyXP);
  String enemyXPOut;
  enemyXPOut=enemyXP;
  
  //String enemyPokemons=startPokemonID[0];

  int myXP=150;
  String myLevelOut;
  myLevelOut=getLevel(myXP);
  String myXPOut;
  myXPOut=enemyXP;


  
  //EsploraTFT.background(0,0,0);

  //Enemy stats
  EsploraTFT.setTextSize(1);

  //Enemy stats rect 
  // TODO: Change to color depending on a poketype
  EsploraTFT.stroke(enemyColor[0],enemyColor[1],enemyColor[2]);
  EsploraTFT.fill(enemyColor[0],enemyColor[1],enemyColor[2]);
  EsploraTFT.rect(enemyTextX - 5, enemyTextY - 5, 75, 30); 


    
  String enemyPokemon = loadData(startPokemonID[0], ' ', 40, "pokedex.TXT");                                                                    
  String enemyPokemons = getName(enemyPokemon);
  TypeID enemyType=getType(enemyPokemon);
  
  String myPokemon = loadData(startPokemonID[1], ' ', 40, "pokedex.TXT");                                                                    
  String myPokemons = getName(myPokemon);
  TypeID myType=getType(myPokemon);




  switch(enemyType)
    {
      case POISON:
        EsploraTFT.stroke(130,0,75); EsploraTFT.fill(130,0,75); break;//indigo
      case NORMAL:
        EsploraTFT.stroke(130,255,255);EsploraTFT.fill(130,255,255); break;//white
      case GRASS:
        EsploraTFT.stroke(0,255,0);EsploraTFT.fill(0,255,0); break;//green
      case FIRE:
        EsploraTFT.stroke(0,0,255);EsploraTFT.fill(0,0,255); break;//red
      case ELECTRIC:
        EsploraTFT.stroke(0,255,255); EsploraTFT.fill(0,255,255);break;//yellow
      case GROUND:
        EsploraTFT.stroke(65,77,90);EsploraTFT.fill(65,77,90); break;//ground brown
      case ROCK:
        EsploraTFT.stroke(98,98,98);EsploraTFT.fill(98,98,98); break;//dark grey
      case ICE:
        EsploraTFT.stroke(230,224,176); EsploraTFT.fill(230,224,176);break;//light blue
      case FIGHTING:
        EsploraTFT.stroke(48,48,129);EsploraTFT.fill(148,48,129); break;//dark red
      case PSYCHIC:
        EsploraTFT.stroke(0,204,204); EsploraTFT.fill(0,204,204);break;//greenish yellow
      case BUG:
        EsploraTFT.stroke(102,255,102); EsploraTFT.fill(102,255,102);break;//light green
      case DRAGON:
        EsploraTFT.stroke(0,0,102);EsploraTFT.fill(0,0,102);break; //dark red
      case GHOST:
        EsploraTFT.stroke(128,128,128);EsploraTFT.fill(128,128,128); break;//grey
      case WATER:
        EsploraTFT.stroke(0,0,255); EsploraTFT.fill(0,0,255); break;//blue
    }

  //Enemy image

//  int enemyColorFill[3];
//  *enemyColorFill=getTypeColor(enemyType);
//  EsploraTFT.stroke(enemyColorFill[0],enemyColorFill[1],enemyColorFill[2]);
//  EsploraTFT.fill(enemyColorFill[0],enemyColorFill[1],enemyColorFill[2]);
  EsploraTFT.rect(95, 5, 55, 55);
  PImage enemyPokemonImg1=getImage(10, 'f', 1);
  EsploraTFT.image(enemyPokemonImg1, 98, 9);
  enemyPokemonImg1.close();




  //Enemy healthbar
  EsploraTFT.fill(0, 255, 0);
  EsploraTFT.noStroke();
  EsploraTFT.rect(enemyTextX - 5, enemyTextY + 26, enemyHealth, 8);
  EsploraTFT.noFill();
  EsploraTFT.stroke(255, 255, 255);
  EsploraTFT.rect(enemyTextX - 5, enemyTextY + 26, healthbarSize, 8);




  //Host Stats
  EsploraTFT.stroke(hostColor[0],hostColor[1],hostColor[2]);
  EsploraTFT.fill(hostColor[0],hostColor[1],hostColor[2]);
  EsploraTFT.rect(hostTextX - 5, hostTextY-20, 75, 45);


  switch(myType)
    {
      case POISON:
        EsploraTFT.stroke(130,0,75); EsploraTFT.fill(130,0,75);break;//indigo
      case NORMAL:
        EsploraTFT.stroke(130,255,255);EsploraTFT.fill(130,255,255); break;//white
      case GRASS:
        EsploraTFT.stroke(0,255,0);EsploraTFT.fill(0,255,0); break;//green
      case FIRE:
        EsploraTFT.stroke(0,0,255);EsploraTFT.fill(0,0,255); break;//red
      case ELECTRIC:
        EsploraTFT.stroke(0,255,255); EsploraTFT.fill(0,255,255);break;//yellow
      case GROUND:
        EsploraTFT.stroke(65,77,90);EsploraTFT.fill(65,77,90); break;//ground brown
      case ROCK:
        EsploraTFT.stroke(98,98,98);EsploraTFT.fill(98,98,98); break;//dark grey
      case ICE:
        EsploraTFT.stroke(230,224,176); EsploraTFT.fill(230,224,176);break;//light blue
      case FIGHTING:
        EsploraTFT.stroke(48,48,129);EsploraTFT.fill(148,48,129); break;//dark red
      case PSYCHIC:
        EsploraTFT.stroke(0,204,204); EsploraTFT.fill(0,204,204);break;//greenish yellow
      case BUG:
        EsploraTFT.stroke(102,255,102); EsploraTFT.fill(102,255,102);break;//light green
      case DRAGON:
        EsploraTFT.stroke(0,0,102);EsploraTFT.fill(0,0,102);break; //dark red
      case GHOST:
        EsploraTFT.stroke(128,128,128);EsploraTFT.fill(128,128,128); break;//grey
      case WATER:
        EsploraTFT.stroke(0,0,255); EsploraTFT.fill(0,0,255);break;//blue
    }

    //Host image
//  int myColor[3];
//  *myColor=getTypeColor(myType);
//  EsploraTFT.stroke(myColor[0],myColor[1],myColor[2]);
//  EsploraTFT.fill(myColor[0],myColor[1],myColor[2]);
  EsploraTFT.rect(10, 68, 55, 55);
  PImage myPokemonImg2=getImage(4, 'f', 1);
  EsploraTFT.image(myPokemonImg2, 13, 71);
  myPokemonImg2.close();


 

  //Host healthbar
  EsploraTFT.fill(0, 255, 0);
  EsploraTFT.noStroke();
  EsploraTFT.rect(hostTextX - 5, hostTextY - 30, hostHealth, 8);
  EsploraTFT.noFill();
  EsploraTFT.stroke(255, 255, 255);
  EsploraTFT.rect(hostTextX - 5, hostTextY - 30, healthbarSize, 8);





  
 



  EsploraTFT.setTextSize(1); 
  EsploraTFT.stroke(255,255,255);
  //ENEMY INFORMATION
  EsploraTFT.text(enemyPokemons.c_str(),enemyTextX, enemyTextY);
  EsploraTFT.text("Lv", enemyTextX, enemyTextY + 12);
  EsploraTFT.text(enemyLevelOut.c_str(), enemyTextX+15, enemyTextY + 12);
  EsploraTFT.text("XP", enemyTextX+35, enemyTextY + 12);
  EsploraTFT.text("XP", enemyTextX+35, enemyTextY + 12);

  //HOST INFORMATION
  EsploraTFT.text("Lv", hostTextX, hostTextY + 12);
  EsploraTFT.text(myLevelOut.c_str(), hostTextX+15, hostTextY+12);
  EsploraTFT.text("XP", hostTextX+35, hostTextY + 12);
  EsploraTFT.text("SELECTION", hostTextX, hostTextY -12);
  EsploraTFT.text(myPokemons.c_str(), hostTextX, hostTextY );


}

void flashingSelection()
{
  bool flashing=0;
    if(Esplora.readButton(SWITCH_RIGHT) == LOW)
    {
       flashing =1;
    }
    
    while(flashing==1)
    {
     EsploraTFT.setTextSize(1); 
     EsploraTFT.stroke(0,0,255);
     delay(500);
     EsploraTFT.text("SELECTION", 85,  86);
     delay(500);
     EsploraTFT.stroke(255,255,255);
     EsploraTFT.text("SELECTION", 85,  86);
      if(Esplora.readButton(SWITCH_DOWN) == LOW )
        flashing=0;
    }
}


void renderBattleInterfaceRoutine()
{
  if(initialising==1)
  {
    renderBattleDisplay();
    initialising=0;
  }
  flashingSelection();
   if(Esplora.readButton(SWITCH_DOWN) == LOW)
        initialising=1;
}



//-----------------------------------------------------------------------------------------------------------------------------------------------------------


void drawInfoMenu()
{
  char playerName[]={"ASH"};
  int winNum=10;
  int lostNum=5;


  String winOut;
  winOut = winNum;
  String lostOut;
  lostOut = lostNum;
  
  EsploraTFT.setTextSize(1);
  EsploraTFT.stroke(255, 255, 255);
  EsploraTFT.text(playerName,10,10);
  EsploraTFT.text("Battles",10,20);
  EsploraTFT.text("won:",10,30);
  EsploraTFT.text(winOut.c_str(),35,30);
  EsploraTFT.text("lost:",10,40);
  EsploraTFT.text(lostOut.c_str(),40,40);

  //if you are using starterPokemon in globals using the code below
  //String pokemons[6]={starterPokemon[0].name,starterPokemon[1].name,starterPokemon[2].name,starterPokemon[3].name,starterPokemon[4].name,starterPokemon[5].name};


  int levels[6]={1,22,3,4,5,6};
  //I initialize some pokemons, which you can put your start pokemon here
  
  
  
  String pokemon_data[6];

  int yPos=10;
  String pokemons[6];
  TypeID type[6];


  //PRINT OUT PLAYER AND POKEMON INFORMATION
  for(int i=0;i<6;++i)
  {
   
    pokemon_data[i] =loadData(startPokemonID[i]-1, ' ', 40, "pokedex.TXT");
    type[i]=getType(pokemon_data[i]);
    pokemons[i]= getName(pokemon_data[i]);

    int color[3];
//    *color=getTypeColor(type[i]);
//    EsploraTFT.stroke(color[0],color[1],color[2]);
    switch(type[i])
    {
      case POISON:
        EsploraTFT.stroke(130,0,75); break;//indigo
      case NORMAL:
        EsploraTFT.stroke(130,255,255); break;//white
      case GRASS:
        EsploraTFT.stroke(0,255,0); break;//green
      case FIRE:
        EsploraTFT.stroke(0,0,255); break;//red
      case ELECTRIC:
        EsploraTFT.stroke(0,255,255); break;//yellow
      case GROUND:
        EsploraTFT.stroke(65,77,90); break;//ground brown
      case ROCK:
        EsploraTFT.stroke(98,98,98); break;//dark grey
      case ICE:
        EsploraTFT.stroke(230,224,176); break;//light blue
      case FIGHTING:
        EsploraTFT.stroke(48,48,129); break;//dark red
      case PSYCHIC:
        EsploraTFT.stroke(0,204,204); break;//greenish yellow
      case BUG:
        EsploraTFT.stroke(102,255,102); break;//light green
      case DRAGON:
        EsploraTFT.stroke(0,0,102);break; //dark red
      case GHOST:
        EsploraTFT.stroke(128,128,128); break;//grey
      case WATER:
        EsploraTFT.stroke(0,0,255); break;//blue

    }
   
    EsploraTFT.text(pokemons[i].c_str(),65,yPos);

    int instLen=strlen(pokemons[i].c_str())*6;
    int xPos=80+instLen;
    String levelOut;
    levelOut=levels[i];
    EsploraTFT.stroke(255, 255, 255);
    EsploraTFT.text("Lv",xPos-9,yPos);
    EsploraTFT.text(levelOut.c_str(),xPos+4,yPos);
   
    yPos+=20;
  }

  EsploraTFT.rect(6,6, 48, 45);

  EsploraTFT.rect(55,6, 104, 120);






}

void infoMenuCursor()
{
 
  static int cursorRow=10;
  // save the height of the screen
  int myHeight = EsploraTFT.height();
  // map the paddle's location to the joystick's position 
  int yAxis = map(Esplora.readJoystickY(), -512, 512, 0, myHeight);
  
  EsploraTFT.stroke(0,0,0);
  EsploraTFT.text(">",57,cursorRow);

  EsploraTFT.stroke(255,255,255);
  EsploraTFT.text(">",57,cursorRow);
    
    if(yAxis>80 && cursorRow<110)
    {
      EsploraTFT.stroke(0,0,0);
      EsploraTFT.text(">",57,cursorRow);
      cursorRow+=20;
        
      EsploraTFT.stroke(255,255,255);
      EsploraTFT.text(">",57,cursorRow);
      delay(100);
    }

    else if(yAxis<20 && cursorRow>10)
    {
      EsploraTFT.stroke(0,0,0);
      EsploraTFT.text(">",57,cursorRow);
      cursorRow-=20;
      
      EsploraTFT.stroke(255,255,255);
      EsploraTFT.text(">",57,cursorRow);

      delay(100);
    }

    int idNum=0;
    switch(cursorRow)
    {
      case 10: idNum=0;break;
      case 30: idNum=1; break;
      case 50: idNum=2;break;
      case 70: idNum=3;break;
      case 90: idNum=4;break;
      case 110: idNum=5;break;
    }
     
     //if new selcetion
     
     if(selection!=cursorRow)
     {
     PImage myPokemonImg=getImage(startPokemonID[idNum],'f',1);
     EsploraTFT.image(myPokemonImg,0,60);
     myPokemonImg.close();
     selection=cursorRow;
     }
     //endif

    //if(cursorRow<10) cursorRow=10;
    //if(cursorRow>110) cursorRow=110;
  
}

void infoMenuRoutine()
{
  byte infoMenuCheck=1;
      drawInfoMenu();
      while(infoMenuCheck)
      {

        infoMenuCursor();
        if(Esplora.readButton(SWITCH_DOWN) == LOW)
          infoMenuCheck=0;
      }
}

//  if(masterMenu.lineID==7)
//  {
//     renderBattleInterfaceRoutine();
//     
//  }
//
//    if(masterMenu.lineID==10)
//    {
//      infoMenuRoutine();
//     
//    }
//PLEASE ADD THE CODE ABOVE TO THE INO FILE IN RODER FOR IT TO RUN


#endif
