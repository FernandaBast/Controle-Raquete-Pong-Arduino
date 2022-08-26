#define pinoBotao1 21
#define pinoPotenciometro 32

int ValorPotenciometro;
int Porcentagem;
int Botao1 = 0;
int Potenciometro1 = 0;

void setup() {
  pinMode(pinoBotao1, INPUT_PULLUP);
  Serial.begin(115200);
}

void loop() {
  if(digitalRead(pinoBotao1) == LOW && Botao1 == 0){
   Serial.print("Pula\n");
    Botao1 = 1;
    delay(1);
    
  }else if (digitalRead(pinoBotao1) == HIGH && Botao1 == 1){
     Botao1 = 0;
     delay(1);
          
  } 
  
    ValorPotenciometro = analogRead(pinoPotenciometro);
    Porcentagem = map(ValorPotenciometro, 0, 4095, 0 ,100);

    if (Porcentagem < 30){
      Serial.print ("Esquerda\n");
      delay(68);
    }else if (Porcentagem > 70){
      Serial.print("Direita\n");
      delay(68);
    }
    
}
