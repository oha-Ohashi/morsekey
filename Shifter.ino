bool shift_flag = false;
void detechShift(){
  int gauge = 0;
  while(!shift_flag
         && digitalRead(sw_pins[2]) == LOW){
    gauge++;
    if(gauge > 1000){
      Serial.println('S');          
      shiftbuff++;                //buffering
      lastbtt_shift = millis();
      break;
    }
  }
  gauge = 0;
  if(digitalRead(sw_pins[2]) == LOW){
    shift_flag = true;
  }else{
    shift_flag = false;
  }    
}

void shiftEnter(){  
  if((millis() - lastbtt_shift) > bp_span *4
        && shiftbuff > 0){

    Serial.print("sss ");
    Serial.print(shiftbuff);
    shiftAct(shiftbuff);
    Serial.println(" sss");
    shiftbuff = 0;
  }  
}


bool caps = false;
void shiftAct(byte b){
  if(b == 1){
    Keyboard.press(129);
    sh_cap = true;
  }else if(b == 2){
    if(!caps){
      Keyboard.press(129);
      caps = !caps;
    }else{
      Keyboard.release(129);
      caps = !caps;
    }
  }else if(b == 3){
     silent = !silent;
     if(!silent) switchon();
  }else if(b == 4){
     Keyboard.print("sca00046");
  }else if(b == 5){
     Keyboard.print("qdp312QH");
  }
}
