
#include "Globals.h"
#include "GUI.h"
#include "pokedex.h"
//#include "statsSystem.h"
//PImage img;
int _currentMenu;
int _nextMenu;



void setup() 
{
  Serial.begin(9600);
  SPI.begin();
  EsploraTFT.begin(); 

  EsploraTFT.background(0,0,0);  // clear the screen with black
 _currentMenu = 0;
 _nextMenu = 1;

  if (!SD.begin(SD_card)) 
  {
    Serial.println("Failed");
    return;
  }
  Serial.println("Succeded");


  buildMenu(0, &masterMenu);
  renderMenu(masterMenu);
}

void loop() 
{

    

    if(Esplora.readButton(SWITCH_RIGHT) == LOW)
    {
      clearScreen();
      
      buildMenu(masterMenu.next[cursorRow/30], &masterMenu);
        

      renderMenu(masterMenu);
    }

    if(Esplora.readButton(SWITCH_DOWN) == LOW)
    {
      clearScreen();
      
      buildMenu(masterMenu.prev, &masterMenu);
      
      renderMenu(masterMenu);
    }


    
    
    if(masterMenu.lineID>2)
    {
      byte infoMenuCheck=1;
      drawInfoMenu();
      while(infoMenuCheck)
      {
//        static bool testy = false; 
//        if(testy==false) testy=true;
//        else testy=false;
        
    //if(testy) Esplora.writeRGB(255,255,255);
    //else Esplora.writeRGB(0,0,0);
        infoMenuCursor();
        if(Esplora.readButton(SWITCH_DOWN) == LOW)
          infoMenuCheck=0;
      }
    }




    
     switchRow(masterMenu);

  
}




