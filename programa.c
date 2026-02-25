#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
int button = 17;
int clearbtn = 16;
bool clearPressionado = false;

unsigned long inicio;
unsigned long fim;
String m = "";
bool pressionado = false;


void setup(){
  Serial.begin(115200);
  Wire.begin(19, 18); // SDA, SCL
  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0, 0);
  
  	pinMode(button, INPUT_PULLUP);
  	pinMode(clearbtn, INPUT_PULLUP);
}

void loop(){
  if (digitalRead(button) == LOW && !pressionado) {
    pressionado = true;
    inicio = millis();
    delay(200);
 }
  if (digitalRead(button) == HIGH && pressionado) {
  pressionado = false;
  fim = millis();


  unsigned long duracao = fim - inicio;


  if (duracao <= 400)
    m += ".";
  else
    m += "-";


  delay(200);
  Serial.println(m); //pra checar no terminal
 }


 if (!pressionado && m.length() > 0 && millis() - fim > 800) {
  lcd.print(traduzMorse(m));
  m = "";
 }
  
  if (digitalRead(clearbtn) == LOW && !clearPressionado){ 
    clearPressionado = true;
    lcd.clear(); 
    lcd.setCursor(0, 0);
  }
  if (digitalRead(clearbtn) == HIGH && clearPressionado)
  	clearPressionado = false;
}


char traduzMorse(String m){
    if (m == ".-") return 'A';
    if (m == "-...") return 'B';
    if (m == "-.-.") return 'C';
    if (m == "-..") return 'D';
    if (m == ".") return 'E';
    if (m == "..-.") return 'F';
    if (m == "--.") return 'G';
    if (m == "....") return 'H';
    if (m == "..") return 'I';
    if (m == ".---") return 'J';
    if (m == "-.-") return 'K';
    if (m == ".-..") return 'L';
    if (m == "--") return 'M';
    if (m == "-.") return 'N';
    if (m == "---") return 'O';
    if (m == ".--.") return 'P';
    if (m == "--.-") return 'Q';
    if (m == ".-.") return 'R';
    if (m == "...") return 'S';
    if (m == "-") return 'T';
    if (m == "..-") return 'U';
    if (m == "...-") return 'V';
    if (m == ".--") return 'W';
    if (m == "-..-") return 'X';
    if (m == "-.--") return 'Y';
    if (m == "--..") return 'Z';


    return '?';
}
