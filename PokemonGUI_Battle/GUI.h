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


void infoMenu()
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


  int levels[6]={1,22,3,4,5,6};
  String pokemons[6]={"Pikachu","Electabuzz","Mew","Zubat","Pidgeotto","Charmander"};
  int yPos=10;



  //PRINT OUT PLAYER AND POKEMON INFORMATION
  for(int i=0;i<6;++i)
  {
   
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

    //if(cursorRow<10) cursorRow=10;
    //if(cursorRow>110) cursorRow=110;
  
}
#endif
