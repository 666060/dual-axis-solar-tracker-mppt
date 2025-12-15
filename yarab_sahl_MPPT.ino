// ----------- MPPT P&O for Arduino UNO -----------


const int voltagePin = A1;  
const int currentPin = A0;   
const int pwmPin = 9;       


const float VOLTAGE_DIVIDER_FACTOR = 5.54545; 
const float ACS_SENSITIVITY = 0.100;       
float offsetCurrent = 3.506;               


int dutyCycle = 128;   
int step = 5;


float V = 0, I = 0, P = 0;
float P_prev = 0, V_prev = 0;


float readCurrent() {
  float sum = 0;
  const int samples = 20;

  for (int i = 0; i < samples; i++) {
    sum += analogRead(currentPin) * (5.0 / 1023.0);
    delay(1);
  }

  float voltageCurrent = sum / samples;
  float current = (voltageCurrent - offsetCurrent) / ACS_SENSITIVITY;
  return current;
}


float readVoltage() {
  float sum = 0;
  const int samples = 10;

  for (int i = 0; i < samples; i++) {
    sum += analogRead(voltagePin) * (5.0 / 1023.0) * VOLTAGE_DIVIDER_FACTOR;
    delay(1);
  }

  return sum / samples;
}

// ---------------------------------------------
void setup() {
  pinMode(pwmPin, OUTPUT);
  analogWrite(pwmPin, dutyCycle);
  Serial.begin(9600);

 
  long sum = 0;
  for (int i = 0; i < 100; i++) {
    sum += analogRead(currentPin);
    delay(5);
  }
  offsetCurrent = (sum / 100.0) * (5.0 / 1023.0);
  Serial.print("Offset calibrated: "); Serial.println(offsetCurrent, 3);
}

// ---------------------------------------------
void loop() {
  
  V = readVoltage();
  I = -readCurrent(); 

  
  P = V * I;
  if (P > P_prev) {
    if (V > V_prev)
      dutyCycle += step;
    else
      dutyCycle -= step;
  } else {
    if (V > V_prev)
      dutyCycle -= step;
    else
      dutyCycle += step;
  }

  
  dutyCycle = constrain(dutyCycle, 20, 230);
  analogWrite(pwmPin, dutyCycle);

  
  P_prev = P;
  V_prev = V;

  
  Serial.print("V="); Serial.print(V, 2);
  Serial.print(" I="); Serial.print(I, 2);
  Serial.print(" P="); Serial.print(P, 2);
  Serial.print(" D="); Serial.println(dutyCycle);

  delay(200);
}
