#include <PS4Controller.h>
#include <cstdint>

void setup() {
  Serial.begin(115200);
  PS4.begin("");
}

void loop() {
  if (PS4.isConnected()) {
    if (PS4.LStickX()) {

      int8_t num[3] = {PS4.LStickX(),PS4.LStickY(),PS4.RStickX()};
      for(int i = 0;i <= 2;i++){
        // int i = 0;
        String str1 = String(static_cast<int>(num[i] + i*256));
        Serial.print(str1 + "\n");
      }
    }
    if(PS4.Right()){
      Serial.write("k");
    }else if(PS4.Left()){
      Serial.write("q");
    }
    
    if(PS4.L1()){
      if(PS4.Circle()){
        Serial.write("l");
      }else{
        Serial.write("m");
      }
    }else if(PS4.R1()){
      if(PS4.Circle()){
        Serial.write("r");
      }else{
        Serial.write("s");
      }      
    }else {
      Serial.write("n");
    }

    if(PS4.Up()){
      Serial.write("u");
    }else if(PS4.Down()){
      Serial.write("d");
    }else{
      Serial.write("o");
    }

    if(PS4.Triangle()){
      Serial.write("t");
    }
    if(PS4.Cross()){
      Serial.write("c");
    }

    if(PS4.Square()){
      Serial.write("a");
    }else{
      Serial.write("b");
    }
    delay(100);
  }
}