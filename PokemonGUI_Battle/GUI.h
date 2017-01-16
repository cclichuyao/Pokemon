#ifndef GUI_H
#define GUI_H

#include "Globals.h"
#include "pokedex.h"


void clearScreen()
{
  EsploraTFT.background(0,0,0);
}

void renderMenu(menu_t m)
{ 
  int row = 0;

  EsploraTFT.stroke(255,255,255);
  EsploraTFT.setTextSize(2);

  for(int i = 0; i < m.elements; i++)
  {
    
      // draw i element of the menu
    EsploraTFT.text(m.element[i].c_str(),25,row);

    // draws next element on next row
    row+=30;
  }
}

void switchRow(menu_t m)
{
   // save the height of the screen
  int myHeight = EsploraTFT.height();

  // map the paddle's location to the joystick's position 
 
  yAxis = map(Esplora.readJoystickY(), -512, 512, 0, myHeight);

  // use joystick position to move cursor up and down menu
 if( yAxis>120 && m.elements>3 )
 {
  cursorRow=90;
 }
 // if there are less then 2 rows the cursor wont go past row 2
 else if(yAxis>=100 && yAxis<120 && m.elements>2)
 {
  cursorRow=60;
 }
 else if(yAxis>=80 && yAxis<100 && m.elements>1)
 {
  cursorRow=30;
 }
 else if(yAxis>=64 && yAxis<80)
 {
  cursorRow=0;
 }

 //initial position 64

 // draws cursor
 EsploraTFT.setTextSize(2);
 EsploraTFT.stroke(255,255,255);
 EsploraTFT.text("->",0,cursorRow);

 EsploraTFT.stroke(0,0,0);
 EsploraTFT.text("->",0,cursorRow);
  
}

void buildMenu(int _id, menu_t * m)
{
    String loadedMenu = loadData(_id, '|', 64, "menuDB.TXT");
    char * data = (char*)loadedMenu.c_str();
  
    m->elements = getElementsNumber(loadedMenu);;
    
    for(int i = 0; i < m->elements; ++i)
    {
      m->element[i] = getMenuElementName(i, loadedMenu);
      m->next[i] = getMenuElement(i, loadedMenu);
    
    }
    m->lineID=_id;
}




  
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
  int startPokemonID[]={1,2,3,65,78,149};
  
  
  

  int yPos=10;
  String pokemons[6];
  TypeID type[6];


  //PRINT OUT PLAYER AND POKEMON INFORMATION
  for(int i=0;i<6;++i)
  {
   
    pokemon_data[i] =loadData(startPokemonID[i]-1, ' ', 40, "pokedex.TXT");
    type[i]=getType(pokemon_data[i]);
    pokemons[i]= getName(pokemon_data[i]);


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
      case 110: idNum=6;break;
    }
     PImage myPokemonImg=getFrontImage(startPokemonID[idNum]);
     EsploraTFT.image(myPokemonImg,10,60);
     myPokemonImg.close();

    //if(cursorRow<10) cursorRow=10;
    //if(cursorRow>110) cursorRow=110;
  
}
#endif
