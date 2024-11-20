#include <Servo.h>
#include<ArduinoJson.h>
#define led 13
#define ldrSupEsq A0
#define ldrSupDir A1
#define ldrInfEsq A2
#define ldrInfDir A3
Servo Vertical;
Servo Horizontal;

int LimiteServoHorizontalMax = 180;  // Estabele os limites de rotação
int LimiteServoHorizontalMin = 0;   // Estabele os limites de rotação
int LimiteServoVerticalMax = 180;    
int LimiteServoVerticalMin = 0;     

int ServoVertical = 45; 
int ServoHorizontal = 45; 

void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(ldrSupEsq, INPUT);
  pinMode(ldrSupDir, INPUT);
  pinMode(ldrInfEsq, INPUT);
  pinMode(ldrInfDir, INPUT);
  Vertical.attach(6);
  Horizontal.attach(5);
  Vertical.write(45);
  Horizontal.write(45);
  delay(2000);

}

void loop() {

  int LDR_TOLERANCE = 50;

  int LSE_VALUE = analogRead(ldrSupEsq); // LSE = LDR SUPERIOR ESQUERDO
  int LSD_VALUE = analogRead(ldrSupDir);
  int LIE_VALUE = analogRead(ldrInfEsq);
  int LID_VALUE = analogRead(ldrInfDir);

  int LDR_SUP_VALUE = (LSE_VALUE + LSD_VALUE) / 2;  //media dos valores superiores
  int LDR_INF_VALUE = (LIE_VALUE + LID_VALUE) / 2;  //media dos valores inferiores
  int LDR_DIR_VALUE = (LSD_VALUE + LID_VALUE) / 2;
  int LDR_ESQ_VALUE = (LSE_VALUE + LIE_VALUE) / 2;

  int DIF_SUP_INF = LDR_SUP_VALUE - LDR_INF_VALUE;      // Diferença entre LED superior e inferior
  int DIF_DIR_ESQ = LDR_DIR_VALUE - LDR_ESQ_VALUE;      // Diferença entre LED superior e inferior


    if (-1 * LDR_TOLERANCE > DIF_SUP_INF || DIF_SUP_INF > LDR_TOLERANCE){
      if(LDR_SUP_VALUE > LDR_INF_VALUE){
        ServoVertical++;
        if (ServoVertical > LimiteServoVerticalMax){
          ServoVertical = LimiteServoVerticalMax;
        }
      }
      else{
        ServoVertical--;
        if (ServoVertical < LimiteServoVerticalMin){
          ServoVertical = LimiteServoVerticalMin;
        }      
      }
      Vertical.write(ServoVertical);
    }

    delay(1000);

    if (-1 * LDR_TOLERANCE > DIF_DIR_ESQ || DIF_DIR_ESQ > LDR_TOLERANCE){
      if(LDR_DIR_VALUE > LDR_ESQ_VALUE){
        ServoHorizontal++;
        if (ServoHorizontal > LimiteServoHorizontalMax){
          ServoHorizontal = LimiteServoHorizontalMax;
        }
      }
      else{
        ServoHorizontal--;
        if (ServoHorizontal < LimiteServoHorizontalMin){
          ServoHorizontal = LimiteServoHorizontalMin;
        }      
      }
      Horizontal.write(ServoHorizontal);
    }

    StaticJsonDocument<100>json;
    json["LDR_SUP_ESQ"] = LSE_VALUE;
    json["LDR_SUP_DIR"] = LSD_VALUE;
    json["LDR_INF_ESQ"] = LIE_VALUE;
    json["LDR_INF_DIR"] = LID_VALUE;
    json["ANGULO_SERVO_HORIZONTAL"] = ServoHorizontal;
    json["ANGULO_SERVO_VERTICAL"] = ServoVertical;

    serializeJson(json, Serial);
    Serial.println();

  }


