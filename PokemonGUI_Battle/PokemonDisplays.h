#include <LiquidCrystal.h>

// include the necessary libraries
#include <Esplora.h>
#include <TFT.h>            // Arduino LCD library
#include <SPI.h>

void setup() {

 
  EsploraTFT.begin();

  // clear the screen with a black background
  EsploraTFT.background(0,0,0);

  

  handleDamage(10, 10);
}

void loop() {
  
  
}



void handleDamage(int _dmgDone, int _dmgTaken)
{
  
  char name1[]={"Pikachu"};
  char name2[]={"Ponyta"};
  char myMaxHP[]={"100"};
  char myHP[]={"0"};
  char enemyMaxHP[]={"100"};
  char enemyHP[]={"1"};
  int myHealth=0;
  int enemyHealth=0;
  int enemySpeed=0;
  int mySpeed=1;
  int damageTaken=40; //percentage
  int damageSent=40; //percentage

  switch(2)
  {
    
    case 1:
    //MY HEALTH AND ENEMY HEALTH
      EsploraTFT.setTextSize(1);
      EsploraTFT.stroke(255, 255, 255);
      EsploraTFT.text(name1,10 ,20);
      EsploraTFT.text("My health: ",10 ,10);
      EsploraTFT.text(myHP,10, 30);
      EsploraTFT.text("/",23, 30);
      EsploraTFT.text(myMaxHP, 30, 30);
    
      EsploraTFT.line(0,60, 160,60);
      
      EsploraTFT.text(name2,10 ,80);
      EsploraTFT.text("Enemy health: ",10 ,70);
      EsploraTFT.text(enemyHP,10, 90);
      EsploraTFT.text("/",23, 90);
      EsploraTFT.text(enemyMaxHP, 30, 90);
     
    break;

    case 2:
    {
    //TAKEN DAMAGE
      int typeMultipler=200;
      if(typeMultipler==50)
      { 
        
        EsploraTFT.setTextSize(2);
        EsploraTFT.stroke(255, 255, 255);
        EsploraTFT.text("It's not", 30, 30);
        delay(500);
        EsploraTFT.text("very", 50, 50);
        delay(500);
        EsploraTFT.text("effective!", 25, 70);
      }
      else if(typeMultipler==200)
      {
        EsploraTFT.setTextSize(2);
        EsploraTFT.stroke(255, 255, 255);
        EsploraTFT.text("It's", 55, 30);
        delay(500);
        EsploraTFT.text("SUPER", 50, 50);
        delay(500);
        EsploraTFT.text("effective!", 25, 70);
      }
     break;
    }
    case 3:
    
      //YOU LOST HEALTH & YOU LOST
      //if(myHealth<=0 && enemyHealth<=0 && mySpeed<enemySpeed)
      //if(myHealth<=0 && enemyHealth>0)
      ////if(myHealth<=0 && enemyHealth<=0 && mySpeed==enemySpeed && dice=0)

     
        EsploraTFT.setTextSize(2);
        EsploraTFT.stroke(255, 255, 255);
        EsploraTFT.text("A", 70, 30);
        delay(500);
        EsploraTFT.text("Critical", 30, 50);
        delay(500);
        EsploraTFT.text("Hit!", 55, 70);
        delay(1000);

        EsploraTFT.background(0,0,0);
        delay(500);
        EsploraTFT.stroke(0,0,255);
        EsploraTFT.text("YOU LOST!", 30, 50);
        delay(500);
        
      //}
      break;

      case 4:
        //if(myHealth<=0 && enemyHealth<=0 && mySpeed>enemySpeed)
        //if(myHealth<=0 && enemyHealth<=0 && mySpeed==enemySpeed && dice=1)
        EsploraTFT.setTextSize(2);
        EsploraTFT.stroke(255, 255, 255);
        EsploraTFT.text("A", 70, 30);
        delay(500);
        EsploraTFT.text("Critical", 30, 50);
        delay(500);
        EsploraTFT.text("Hit!", 55, 70);
        delay(1000);

        EsploraTFT.background(0,0,0);
        delay(500);
        EsploraTFT.stroke(0,255,0);
        EsploraTFT.text("YOU WIN!", 30, 50);
        //}
      break;

      case 5:
      //EXPERIENCE UP
      {
      int xp=256;
      String outXP;
      outXP = xp;

      EsploraTFT.setTextSize(2);
      EsploraTFT.stroke(255, 255, 255);
      EsploraTFT.text("You gained",15,35);
      EsploraTFT.text(outXP.c_str(), 65, 55);
      EsploraTFT.text("EXP. Points!",15,75);
      }
      break;

      case 6:
      {
      //LEVELS UP
      int lv=55;
      String outLV;
      outLV = lv;

      EsploraTFT.setTextSize(2);
      EsploraTFT.stroke(255, 255, 255);
      EsploraTFT.text("You grew to",15,40);
      delay(500);
      
      if(lv<10)
        {
          EsploraTFT.text("LV.",55,60);
          EsploraTFT.text(outLV.c_str(), 95, 60);
        }
        
      if(lv>9)
        {
          EsploraTFT.text("LV.",50,60);
          EsploraTFT.text(outLV.c_str(), 90, 60);
        }
      }
      break;

      case 7:
        char moves[] = "Poison beam!";

        int instLen=strlen(moves)*12;
        int xPos1 = (160/2)-(instLen/2);
        int xPos2 = (160/2)-(strlen(name1)*12/2);

        EsploraTFT.setTextSize(2);
        EsploraTFT.stroke(255, 255, 255);
        delay(300);
        EsploraTFT.text(name1,xPos2,30);
        delay(300);
        EsploraTFT.text("uses",60,50);
        delay(300);
        EsploraTFT.text(moves, xPos1,70);
      break;

      
  }
}
