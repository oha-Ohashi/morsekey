//byte bpMemory[16] = {0,0,0,0, 0,0,0,0 ,0,0,0,0, 0,0,0,0};
byte bpMemory[16] = {0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0};
byte bpStep = 0;
long lastbp = 0;

void Beep(){
  if(bpMemory[bpStep] > 0){
    if(bpMemory[bpStep] < 10
                 && (millis() - lastbp) > bp_span){
      if(!silent) tone(bp_pin, bp_freq);
      bpMemory[bpStep] += 10;
      lastbp = millis();
    }else if(bpMemory[bpStep] <20
              && (millis() - lastbp) 
                  > bpMemory[bpStep] %10 *bp_span){
        noTone(bp_pin);
        bpMemory[bpStep] = 0;
        lastbp = millis();
        bpStep++; if(bpStep > 15) bpStep = 0;
    }
  }
}

void insMem(byte ls){            //writing on bpMemory
  //dispMem();
  byte v = vacantM(bpStep);
  bpMemory [v] = ls;
  dispMem();
}

byte vacantM(byte x){
  if(bpMemory[x] == 0){
    return x;
  }else{
    if(x < 15){
       vacantM(x + 1);
    }else{
       vacantM(0);
    }
  }
}

void dispMem(){
  for( int i = 0; i < 4; i++){
    for(int c = 0; c < 4; c++){
      Serial.print(bpMemory[i*4 + c]);
    }
    Serial.print(' ');
  }
  Serial.println();
}

void  switchon (){
  tone(bp_pin, bp_freq, bp_span -10); 
  delay(bp_span );
  tone(bp_pin, bp_freq *1.5, bp_span -10);
}
