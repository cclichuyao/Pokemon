#include <LiquidCrystal.h>

// include the necessary libraries
#include <Esplora.h>
#include <TFT.h>            // Arduino LCD library
#include <SPI.h>

void setup() {

 
  EsploraTFT.begin();

  // clear the screen with a black background
  EsploraTFT.background(0,0,0);

  

  
}

void loop() {
  
  infoMenu();
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





  static int cursorRow=10;
  // save the height of the screen
  int myHeight = EsploraTFT.height();
  // map the paddle's location to the joystick's position 
  int yAxis = map(Esplora.readJoystickY(), -512, 512, 0, myHeight);

    EsploraTFT.stroke(0,0,0);
    EsploraTFT.text("->",50,cursorRow);
    if(yAxis>80)
    {
      EsploraTFT.stroke(0,0,0);
      EsploraTFT.text("->",50,cursorRow);
      cursorRow+=20;
        
      EsploraTFT.stroke(255,255,255);
      EsploraTFT.text("->",50,cursorRow);
      delay(200);
    }

    else if(yAxis<20)
    {
      EsploraTFT.stroke(0,0,0);
      EsploraTFT.text("->",50,cursorRow);
      cursorRow-=20;
      
      EsploraTFT.stroke(255,255,255);
      EsploraTFT.text("->",50,cursorRow);

      delay(100);
    }

    if(cursorRow<10) cursorRow=10;
    if(cursorRow>110) cursorRow=110;

  


  
}
    
