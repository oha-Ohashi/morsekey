#include <Keyboard.h>

///////////////adjust for your own build///////////////////
const int sw_pins[3] = {7,8,9.};  // right, left, shifter
const int bp_pin = 6;             //pin for speaker
const int bp_freq = 880;          //speaker frequency
const int paris_m = 10;           //how many PARIS(50dots) per min.
                                  //check Wikipedia.
const int bp_span = 60000 / (50*paris_m);
                                  //how many milliseconds a dot is.
////////////////////////////////////////////////////////////

long lastbtt, lastbtt_shift;
byte charbuffI = 0;
char charbuffC[24];
byte shiftbuff = 0;
bool sh_cap = false;
bool silent;

void setup(){
  Keyboard.begin();
  Serial.begin(9600);
  for(int i = 0; i < 3; i++){
    pinMode(sw_pins[i], INPUT_PULLUP);  
  }
  silent = !digitalRead(sw_pins[2]);
  if(!silent) switchon();
  //lastbtt = false;
}
//

void loop() {
  detectPaddles();
  charEnter();
  detectPRepeat();
  charEnter();

  detechShift();
  shiftEnter();

  Beep();
  delay(10);
}

bool paddle_flag[2] = {false, false};
char tontsu[2] = {'.', '-'};
void detectPaddles(){
  for(int i = 0; i < 2; i++){
    int gauge = 0;
    while(!paddle_flag[i] && digitalRead(sw_pins[i]) == LOW){
         
        gauge++;
        if(gauge > 1000){
          gauge = 0;
          Serial.println(i);          //buffering
          insMem((i+1)*2 -1);         //{0,1] into [1,3]
          charbuffC[charbuffI] = tontsu[i];
          charbuffI++;                //count up index
          lastbtt = millis();
          break;
        }
    }
    paddle_flag[i] = !digitalRead(sw_pins[i]);
  }
}

void detectPRepeat(){
  for(int i = 0; i < 2; i++){
    if(digitalRead(sw_pins[i]) == LOW
          &&(millis() - lastbtt) > hl_Wait("repeat")){
         
      insMem((i+1)*2 -1);         //{0,1] into [1,3]
      charbuffC[charbuffI] = tontsu[i];
      charbuffI++;                //count up index
      lastbtt = millis();
    }
  }
}

void charEnter(){  
  if((millis() - lastbtt) > hl_Wait("char")
        && charbuffI > 0){

    Serial.print("~~~");
    char ch = CONVtoCHAR(reverseBuff());
    Serial.print(ch);
    Keyboard.write(ch);
    if(sh_cap){
      Keyboard.release(129);
      sh_cap = false;
    }
    Serial.println("~~~");
    charbuffI = 0;
  }//
}

String reverseBuff(){
  String res = "";
  for(int i = 0; i < charbuffI; i++){
    //res += charbuffC[charbuffI - (i+1)];
    res += charbuffC[i];
  }
  return res;
}

int hl_Wait(String mode){
  if(mode == "repeat"){
    if(charbuffC[charbuffI - 1] == '.'){     //char timeout
      return bp_span *2;
    }else{                             
      return bp_span *4;
    }
  }else if(mode == "char"){
    if(charbuffC[charbuffI - 1] == '.'){     //char timeout
      return bp_span *4;
    }else{                             
      return bp_span *6;
    }
  }
}
