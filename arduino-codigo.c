#include <LiquidCrystal.h>
#include <math.h>
#define PALAVRA 11
LiquidCrystal lcd(12, 11, 10, 9, 8, 7);

String X;
String Y;
String entrada;
String saida;


String converteDecimalString(int dado){
  String resultado = "";
  int j=pow(2,PALAVRA-1);
  for (int i=0;i<PALAVRA;i++){
    if (dado<j){
      resultado = resultado + "0";
    }
    else {
      resultado = resultado + "1";
      dado = dado - j;
    }
    j = j/2;  
  }
  
  return resultado;
}


void geraSaida(String dado){ 
  lcd.setCursor(0, 1); 
  lcd.print(dado);
}


String complemento1(String dado){
  String resultado = "";
  for (int i=3;i<PALAVRA;i++){
    if (dado[i] == '1') resultado = resultado + "0"; 
    else resultado = resultado + "1";
  }
  resultado = "0" + resultado.substring(0);
  return resultado;
}

String adicao(String dado){ 
  int num1,num2;
  String resultado;
  num1 = (dado[3] - 48) * 8 + (dado[4] - 48) * 4 + (dado[5] - 48) * 2 + (dado[6] - 48); 
  num2 = (dado[7] - 48) * 8 + (dado[8] - 48) * 4 + (dado[9] - 48) * 2 + (dado[10] - 48); 
  resultado = converteDecimalString(num1 + num2);
  resultado = "0" + resultado.substring(3);
  return resultado;
}

String adicao_imediata(String dado){
  int num1, num2;
  String resultado;
  num1 = (dado[3] - 48) * 128 + (dado[4] - 48) * 64 + (dado[5] - 48) * 32 + (dado[6] - 48) * 16 + 
  (dado[7] - 48) * 8 + (dado[8] - 48) * 4 + (dado[9] - 48) * 2 + (dado[10] - 48);
  num2 = (X[1] - 48) * 128 + (X[2] - 48) * 64 + (X[3] - 48) * 32 + (X[4] - 48) * 16 + 
  (X[5] - 48) * 8 + (X[6] - 48) * 4 + (X[7] - 48) * 2 + (X[8] - 48);
    if (X[0] == "1"){
      resultado = converteDecimalString(num1 - num2);
      resultado = "0" + resultado.substring(3);
    }
    else {
      resultado = converteDecimalString(num1 - num2);
      resultado = "0" + resultado.substring(3);
    }

  return resultado;
}

String subtracao(String dado){
  int num1,num2;
  String neg = "1";
  String pos = "0";  
  String resultado;
  num1 = (dado[3] - 48) * 8 + (dado[4] - 48) * 4 + (dado[5] - 48) * 2 + (dado[6] - 48); 
  num2 = (dado[7] - 48) * 8 + (dado[8] - 48) * 4 + (dado[9] - 48) * 2 + (dado[10] - 48); 
  if (num1 > num2) 
    resultado = pos + converteDecimalString(num1 - num2);
  else
    resultado = neg + converteDecimalString(num2 - num1);  
  if (resultado.startsWith(neg)) {
    resultado = "1" + resultado.substring(4);
  }
  else if (resultado.startsWith(pos)) {
    resultado = "0" + resultado.substring(4);
  }
  return resultado;
}


String subtracao_imediata(String dado){
  int num1, num2;
  String resultado;
  String neg;
  String pos = "0";
  num1 = (dado[3] - 48) * 128 + (dado[4] - 48) * 64 + (dado[5] - 48) * 32 + (dado[6] - 48) * 16 + 
  (dado[7] - 48) * 8 + (dado[8] - 48) * 4 + (dado[9] - 48) * 2 + (dado[10] - 48);
  num2 = (X[1] - 48) * 128 + (X[2] - 48) * 64 + (X[3] - 48) * 32 + (X[4] - 48) * 16 + 
  (X[5] - 48) * 8 + (X[6] - 48) * 4 + (X[7] - 48) * 2 + (X[8] - 48);

  if (num1 > num2) {
    if(X[0] == "1") {
      resultado = pos + converteDecimalString(num1 + num2);
    }  
    else {
      resultado = neg + converteDecimalString(num1 - num2);
    }
  }

  else if (num2 > num1){
    if(X[0] == "1") {
      resultado = neg + converteDecimalString(num1 + num2);
  }
    else {
      resultado = pos + converteDecimalString(num2 - num1);
  }
}

  if (resultado.startsWith(neg)) {
    resultado = "1" + resultado.substring(3);
 }
  else if (resultado.startsWith(pos)) {
    resultado = "0" + resultado.substring(3);
}

  return resultado;
}



int converteStringDecimal(String dado){
  int decimal = 0;
  int pot = 1;
  for (int i=0;i<PALAVRA;i++){
    decimal += (dado[PALAVRA - 1 - i] - 48) * pot;
    pot = pot * 2;
  }
  
  return decimal;
}

void leitura(String dado){
  if (dado[3] == '0' && dado[4] == '0' && dado[5] == '0' && dado[6] == '0' && dado[7] == '0' && dado[8] == '0'
  && dado[9] == '0' && dado[10] == '0')
      geraSaida(X);
  else
      geraSaida(Y);
}

String armazena(String dado) {
    char operando[9]; 
    const char* dado_str = dado.c_str(); 
    strncpy(operando, dado_str + 3, 8); 
    operando[8] = '\0'; 
    String resultado = "0";
    resultado += operando;
    while(resultado.length() < 9) {
        resultado = "0" + resultado;
    }
    return resultado;
}

void transfere(String dado){
  Y = X;
}




int selecaoOp(String dado){
  if (dado[0] == '0' && dado[1] == '0' && dado[2] == '0') 
    X = complemento1(entrada);
  else if (dado[0] == '0' && dado[1] == '0' && dado[2] == '1') 
    X = adicao(entrada);
  else if (dado[0] == '0' && dado[1] == '1' && dado[2] == '0')
    X = adicao_imediata(entrada);
  else if (dado[0] == '0' && dado[1] == '1' && dado[2] == '1')
    X = subtracao(entrada);
  else if (dado[0] == '1' && dado[1] == '0' && dado[2] == '0')         
    X = subtracao_imediata(entrada);
  else if (dado[0] == '1' && dado[1] == '0' && dado[2] == '1')  
    leitura(entrada);
  else if (dado[0] == '1' && dado[1] == '1' && dado[2] == '0')
    X = armazena(entrada);
  else if (dado[0] == '1' && dado[1] == '1' && dado[2] == '1') 
    transfere(entrada);     
  else
    Serial.println("Repita a entrada");
}

void setup() {
  lcd.begin(16, 2); 
  lcd.print("AP1 - Arq. Comp."); 
  Serial.begin(9600); 
}

void loop() {
  Serial.println("Input:");
  while (Serial.available() == 0) {}     
  entrada = Serial.readString();  
  selecaoOp(entrada);
  Serial.println(X + " e " +entrada);
  
}
