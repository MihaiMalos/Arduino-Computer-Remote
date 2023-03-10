#include <IRremote.h>
#include <Keyboard.h>
#include <Mouse.h>

// -=-=-=-=-=-=-= COMMANDS -=-=-=-=-=-=-=

const long VOLUME_UP = 0x617050AF;
const long VOLUME_DOWN = 0x6170D02F;
const long Pause = 0x617028D7;
const long netflix = 0x6170D827;
const long youtube = 0x6170649B;
const long l_arrow = 0x61708877;
const long r_arrow = 0x6170C837;
const long u_arrow = 0x617008F7;
const long d_arrow = 0x617048B7;
const long mod_1 = 0x617000FF;
const long mod_2 =0x6170807F;
const long mod_3 = 0x617040BF;
const long mod_4 = 0x6170C03F;
const long n_track = 0x617030CF;
const long p_track = 0x6170B04F;
const long fullscreen = 0x6170847B;
const long pauza_spotify = 0x6170906F;
const long MUTE = 0x617004FB;
const long spongebob = 0x6170EC13;
const long switch_monitor = 0x6170D22D;
const long speed_state_back = 0x617034CB;
const long speed_state_exit = 0x6170A857;
const long shut_down = 0xE0E040BF;

// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=


const int RECV_PIN = 10;
IRrecv irrecv(RECV_PIN);
decode_results results;


void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn();
  Keyboard.begin();
  Mouse.begin();

}
int invizibil=0;
int state = 1;
int delay_sageti = 30;
int delay_ = 65;
int delay_pauza = 600;

void loop() {  
  
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);
    switch (results.value)
    {
      
      // -----Media-----
        case VOLUME_UP:
            Keyboard.press(KEY_RIGHT_SHIFT);
            Keyboard.press(KEY_F2);
            Keyboard.releaseAll();
            delay(delay_);
            break;
       
        case VOLUME_DOWN:
            Keyboard.press(KEY_RIGHT_SHIFT);
            Keyboard.press(KEY_F1);
            Keyboard.releaseAll();
            delay(delay_);
            break;
        
        case MUTE:
            Keyboard.press(KEY_RIGHT_SHIFT);
            Keyboard.press(KEY_F7);
            Keyboard.releaseAll();
            delay(400);
            break;
        
        //Content
        case netflix:
            Keyboard.press(KEY_RIGHT_SHIFT);
            Keyboard.press(KEY_F4);
            Keyboard.releaseAll();
            delay(delay_);
            break;
        
        case youtube:
            Keyboard.press(KEY_RIGHT_SHIFT);
            Keyboard.press(KEY_F3);
            Keyboard.releaseAll();
            delay(delay_);
            break;

        case spongebob:
            Keyboard.press(KEY_RIGHT_SHIFT);
            Keyboard.press(KEY_F5);
            Keyboard.releaseAll();
            delay(delay_);
            break;
        
        //  ----Sageti----
        
        //stanga
        case l_arrow:
            if (state==1)
            {
            Keyboard.press(KEY_LEFT_ARROW);
            Keyboard.releaseAll();
            delay(delay_sageti);
            }
            else if (state==2)
            {
            Keyboard.press(KEY_RIGHT_SHIFT);
            Keyboard.press(KEY_LEFT_ARROW);
            Keyboard.releaseAll();
            }
            else if(state==3)
            {
              Keyboard.press(KEY_RIGHT_SHIFT);
              Keyboard.press(KEY_TAB);
              Keyboard.releaseAll();
              delay(delay_);
            }
            delay(delay_sageti);
            break;
        
        //dreapta
        case r_arrow:
            if (state==1)
            {
            Keyboard.press(KEY_RIGHT_ARROW);
            Keyboard.releaseAll();
            delay(delay_sageti);
            }
            else if (state==2)
            {
            Keyboard.press(KEY_RIGHT_SHIFT);
            Keyboard.press(KEY_RIGHT_ARROW);
            Keyboard.releaseAll();
            }
            else if(state==3)
            {
              Keyboard.press(KEY_TAB);
              Keyboard.releaseAll();
              delay(delay_);
            }
            delay(delay_sageti);
            break;
        
        //sus
        case u_arrow:
            if (state==1)
            {
            Keyboard.press(KEY_UP_ARROW);
            Keyboard.releaseAll();
            delay(delay_sageti);
            }
            else if (state==2)
            {
            Keyboard.press(KEY_RIGHT_SHIFT);
            Keyboard.press(KEY_UP_ARROW);
            Keyboard.releaseAll();
            }
            delay(delay_sageti);
            break;
        
        //jos
        case d_arrow:
            if (state==1)
            {
            Keyboard.press(KEY_DOWN_ARROW);
            Keyboard.releaseAll();
            delay(delay_sageti);
            }
            else if (state==2)
            {
            Keyboard.press(KEY_RIGHT_SHIFT);
            Keyboard.press(KEY_DOWN_ARROW);
            Keyboard.releaseAll();
            }
            delay(delay_sageti);
            break;

        // ----Pauza----
        case Pause:
            if (state==1)
            {
              Keyboard.print(' ');
              Keyboard.releaseAll();
            delay(delay_pauza);
            }
            else if (state==2)
            {
            Mouse.click();
            Keyboard.releaseAll();
            delay(400);
            }
            else if (state==3)
            {
            Keyboard.press(KEY_RETURN);
            Keyboard.releaseAll();
            delay(delay_pauza);
            }
            break;

        //Next track and previous AND BACK AND FORWARD MUSIC
        case n_track:
            if (state==1)
            {
            Keyboard.press(KEY_RIGHT_SHIFT);
            Keyboard.print('N');
            Keyboard.releaseAll();
            } else {
            Keyboard.press(KEY_RIGHT_SHIFT);
            Keyboard.press(KEY_F9);
            Keyboard.releaseAll();
            }
            delay(500);
            break;
        
        case p_track:
            if (state==1)
            {
            Keyboard.press(KEY_RIGHT_SHIFT);
            Keyboard.print('P');
            Keyboard.releaseAll();
            } else if (state==2) {
            Keyboard.press(KEY_RIGHT_SHIFT);
            Keyboard.press(KEY_F8);
            Keyboard.releaseAll();
            }
            delay(500);
            break;

        //Switch Monitor
        case switch_monitor:
            Keyboard.press(KEY_LEFT_GUI);
            Keyboard.press(KEY_LEFT_SHIFT);
            Keyboard.press(KEY_LEFT_ARROW);
            Keyboard.releaseAll();
            delay(delay_);
            break;
        
        //Fullscreen
        case fullscreen:
            Keyboard.print('F');
            Keyboard.releaseAll();
            delay(delay_pauza);
            break;

        //Pauza Spotify
        case pauza_spotify:
            Keyboard.press(KEY_RIGHT_SHIFT);
            Keyboard.press(KEY_F6);
            Keyboard.releaseAll();
            delay(500);
            break;

        //Moduri
        case mod_1:
            state=1;
            break;
        case mod_2:
            state=2;
            break;
        case mod_3:
            state=3;
            break;
        case mod_4:
            state=4;
            break;

        case speed_state_exit:
        case speed_state_back:
            Keyboard.press(KEY_RIGHT_SHIFT);
            Keyboard.press(KEY_F10);
            Keyboard.releaseAll();
            delay(250);
            break;
            
            /*
        case shut_down:
            if (invizibil==0)
            {
              invizibil=1;
              Keyboard.press(KEY_LEFT_SHIFT);
              Keyboard.press(KEY_F11);
              Keyboard.releaseAll();
              delay(600);
            } else if (invizibil==1)
            {
              invizibil=0;
              Keyboard.press(KEY_LEFT_SHIFT);
              Keyboard.press(KEY_F12);
              Keyboard.releaseAll();
              delay(600);
            }
            */
        case shut_down:
            if (state==3)
            {
              Keyboard.press(KEY_RIGHT_SHIFT);
              Keyboard.press(KEY_F11);
              Keyboard.releaseAll();
              delay(1500);
              break;               
            }
            
            

        //Shutdown
        /*case shut_down:
        Keyboard.press(KEY_RIGHT_SHIFT);
        Keyboard.press(KEY_RIGHT_CTRL);
        delay(2000);
        break;
        */

        
        
        
    };
    Keyboard.releaseAll();
    
    irrecv.resume();
  }

  
}

