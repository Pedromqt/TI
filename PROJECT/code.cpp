unsigned long lastdebouncetime = 0;
unsigned long debouncedelay = 50;
unsigned long tempoderesposta=7000;
unsigned long tempobotaoresetar=1000;
unsigned long tempo;
unsigned long tempodosmodosWeL=5000;
int ultimoestadobotao=LOW;
int estadobotao;
bool flag;
int botao=2;
int numverde;
int numvermelho;
int RED=5;
int BLUE=4;
int GREEN=3;
int operadorbitwise;
int num=0;
int numcorreto;
int n1=0b1000;
int n2=0b0100;
int n3=0b0010;
int n4=0b0001;
int nvarrimento=1;
void setup()
{
  Serial.begin(9600);
  pinMode(botao,INPUT_PULLUP);
  for (int pin=6;pin<=13;pin++)
  {
	  pinMode(pin, OUTPUT);
    }
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
  Serial.println("Jogo BIT MATH - Boa sorte!"); //mostra a mensagem quando se incia o programa pela primeira vez
  Serial.println("Clica no botao para dar inicio ao jogo ! ");
}


void loop() 
{
  flag=true;
  while(flag) //o programa fica aqui "preso" enquanto nao for dado o primeiro clique
  {
    int leitura = digitalRead(botao);
    if(leitura != ultimoestadobotao)
    {
      lastdebouncetime = millis();
    }
    if ((millis()-lastdebouncetime)<debouncedelay)
    {
      if (leitura != estadobotao)
      {
        estadobotao=leitura;
        if (estadobotao==LOW)
        { 
          flag=false; //apos o primeiro clique, o programa sai deste while porque a flag é falsa e continua a percorrer o codigo
        }    
      }
    }
    ultimoestadobotao=leitura;
  }
  Serial.println("---------------");
  Serial.println("O JOGO COMECOU!");
  Serial.println("---------------");
  int numverde=random(0,16);
  int numvermelho=random(0,16);
  	digitalWrite(13,(numverde & n1)); //serve para ligar manter desligado os leds consoantes os numeros
  	digitalWrite(12,(numverde & n2));
  	digitalWrite(11,(numverde & n3));
  	digitalWrite(10,(numverde & n4));
  	digitalWrite(9,(numvermelho & n1));
  	digitalWrite(8,(numvermelho & n2));
  	digitalWrite(7,(numvermelho & n3));
  	digitalWrite(6,(numvermelho & n4));
  int operadorbitwise=random(1,4);	
  int numerocorreto;
  if (operadorbitwise==1) //Liga o rgb consoante o operador and or xor
  {  
    digitalWrite(RED, HIGH);
    numerocorreto = numverde & numvermelho ;  	
  }
  else if (operadorbitwise==2)
  {
    digitalWrite(GREEN, HIGH);
    numerocorreto = numverde ^ numvermelho ;
  }
  else if (operadorbitwise==3)
  {
    digitalWrite(BLUE, HIGH);
    numerocorreto = numverde | numvermelho ;
  }
  unsigned long tempo=millis();
  while((millis()-tempo)<tempoderesposta)
  {
    if ((millis()-tempo)==5250) //75% do tempo (7segundos)
    {
      Serial.println("Ja passou 75% do tempo! ");
    }
    if ((millis()-tempo)==3500) // 50% do tempo (7segundos)
    {
      Serial.println("Ja passou metade do tempo! ");
    }
    
    int leitura = digitalRead(botao);
    if (leitura != ultimoestadobotao)
    {
      lastdebouncetime = millis();
    }
    if ((millis()-lastdebouncetime)<debouncedelay)
    {
      if (leitura != estadobotao)
      {
        estadobotao=leitura;
        if (estadobotao == LOW)
        {
          Serial.println("NUMERO - "+String(num));
          num=num+1;
        }
      }
    }
    ultimoestadobotao=leitura;
    if ((millis()-lastdebouncetime)>tempobotaoresetar) // se o tempo a pressionar o botao for superior a 1s, da reset
    {
      if (estadobotao == LOW)
      {
        num=0;
        Serial.println("|---------------------|");
        Serial.println("|JOGO A SER REINICIADO|");
        Serial.println("|---------------------|");
    while(nvarrimento<4)
    {
      for (int i=0 ; i<=3 ; i++)
      {
        digitalWrite(10+i, HIGH);
        digitalWrite(9-i, HIGH);
        delay(100);
        digitalWrite(10+i, LOW);
        digitalWrite(9-i, LOW);
        delay(100);
      if (operadorbitwise==1)
      {
        digitalWrite(RED, HIGH);
        delay(150);
        digitalWrite(RED, LOW);
        delay(150);
      }
      if (operadorbitwise==2)
      {
        digitalWrite(GREEN, HIGH);
        delay(150);
        digitalWrite(GREEN, LOW);
        delay(150);
      }
      if (operadorbitwise==3)
      {
        digitalWrite(BLUE, HIGH);
        delay(150);
        digitalWrite(BLUE, LOW);
        delay(150);
      }
      }
      nvarrimento = nvarrimento + 1;
    }
    num=0;
    setup(); //serve para chamar a funcao setup, uso para voltar a configurar os pinos e para aparecer as 2 mensagems iniciais
    loop(); //voltamos ao inicio do loop
      }
    }
    ultimoestadobotao=leitura;
  }
  Serial.println("ACABOU O TEMPO! ");
  if ((num-1) == numerocorreto) //o num-1 inclui o zero, pois o numerocorreto pode ser 0
  {
    Serial.println("Parabens! Acertaste no numero correto! ");
    unsigned long tempo=millis();
    while ((millis()-tempo) < tempodosmodosWeL)
    {
      ledsdavitoria();
    }
    while(nvarrimento<4)
    {
      for (int i=0 ; i<=3 ; i++)
      {
        digitalWrite(10+i, HIGH);
        digitalWrite(9-i, HIGH);
        delay(100);
        digitalWrite(10+i, LOW);
        digitalWrite(9-i, LOW);
        delay(100);
      if (operadorbitwise==1)
      {
        digitalWrite(RED, HIGH);
        delay(150);
        digitalWrite(RED, LOW);
        delay(150);
      }
      if (operadorbitwise==2)
      {
        digitalWrite(GREEN, HIGH);
        delay(150);
        digitalWrite(GREEN, LOW);
        delay(150);
      }
      if (operadorbitwise==3)
      {
        digitalWrite(BLUE, HIGH);
        delay(150);
        digitalWrite(BLUE, LOW);
        delay(150);
      }
      }
      nvarrimento = nvarrimento + 1;
    }
    num=0;
    setup(); //serve para chamar a funcao setup, uso para voltar a configurar os pinos e para aparecer as 2 mensagems iniciais
    loop(); //voltamos ao inicio do loop
  }
  else
  {
    Serial.println("Nao acertaste no numero correto! ");
    unsigned long tempo1=millis();
    for (int pin=6 ; pin<=13 ; pin++)
    {
      digitalWrite(pin, LOW);
    }
    while ((millis()-tempo1) < tempodosmodosWeL)
    {
      if (operadorbitwise==1)
      {
        digitalWrite(RED, HIGH);
        delay(150);
        digitalWrite(RED, LOW);
        delay(150);
      }
      if (operadorbitwise==2)
      {
        digitalWrite(GREEN, HIGH);
        delay(150);
        digitalWrite(GREEN, LOW);
        delay(150);
      }
      if (operadorbitwise==3)
      {
        digitalWrite(BLUE, HIGH);
        delay(150);
        digitalWrite(BLUE, LOW);
        delay(150);
      }
    }
    num=0;
    setup();//serve para chamar a funcao setup, principalmente uso para voltar a aparece as 2 mensagems iniciais
    loop();// voltamos ao inicio do loop
  }  
}
    
void ledsdavitoria() //Serve para ligar e desligar alternadamente os leds
{
  for (int pin=6 ; pin<=13 ; pin++)
  {
    digitalWrite(pin, HIGH);
  }
  delay(200);

  for (int pin=6 ; pin<=13 ; pin++)
  {
    digitalWrite(pin, LOW);
  }
  delay(200);

  return;         
}