///*****************************************************************************************
//                                  Func_Millis_3_Leds
//
//    Autor: Jorge Miguel Jaimes Ponce
//    Diplomado: Internet de las cosas
//
//    Este programa es una tarea, la cual consiste en utilizar la funcuón millis() para 
// realizar pausas en bloques de programa, sin detener la ejecución del programa en
// general.
//    Se tienen tres leds, en los pines 12, 13 y 14, los cuales se encenderán y apagarán
// con frecuencias distintas.
//    LOs leds cambian de estado con los siguientes tiempos:
//      Led12 cada 5 segundos.
//      Led13 cada 3 segundos.
//      Led14 cada 0.5 segundos  (Este led utiliza este intrvalo de tiempo para utilizrlo
//    como base de tiempo para monitorear visualmente los leds Led12 y Led13.
//
//    En esta nueva versión, la atención a el parpadeo de los leds, se ha modificado 
//  con el llamado a funiones, cada una atiende el blink de cada led.
//                                       12/10/2021
//
//*****************************************************************************************

#define CAMERA_MODEL_AI_THINKER
#define Led12 12
#define Led13 13
#define Led14 14

//Inicializar los tiempos de los leds Led12, Led13 y Led14
unsigned long t0_12 = 0;
unsigned long t0_13 = 0;
unsigned long t0_14 = 0;

//  Variables correspondientes a lo tiempos siguientes
//  de los leds Led12, Led13 y Led14
unsigned long t1_12 = 0;
unsigned long t1_13 = 0;
unsigned long t1_14 = 0;

bool Led1 = false;
bool Led2 = false;
bool Led3 = false;


void setup() {
  //Configurando los LedsXX como salidas
  pinMode(Led12,OUTPUT);
  pinMode(Led13,OUTPUT);
  pinMode(Led14,OUTPUT);
  
  //Inicializando estado lógico de las salidas
  digitalWrite(Led12,Led1);
  digitalWrite(Led13,Led2);
  digitalWrite(Led14,Led3);

  //Inicializando t0 paa cada led
  t0_12 = millis();
  t0_13 = t0_12;
  t0_14 = t0_12;
  
}


void loop() {
  blink_Led12(5000);    //Blink de Led12 con intervalo de 5 seg de encndido y 5 seg apagado
  blink_Led13(3000);    //Blink de Led13 con intervalo de 3 seg de encndido y 3 seg apagado
  blink_Led14(500);     //Blink de Led14 con intervalo de 0.5 seg de encndido y 0.5 seg apagado
}



//****************************************************
//  Funciones de blink de leds Led12, Led13 y Led14
//****************************************************

void blink_Led12(int tiempo){

   t1_12 = millis();                //Cargando tiempo actual
    //Determinando el tiempó transcurrido
     if (t1_12 - t0_12 >= tiempo){              //Ya son 5 segundos...?
        t0_12 = millis();
        Led1 = !Led1;
        digitalWrite(Led12,Led1);      
     }
}


void blink_Led13(int tiempo){
     t1_13 = millis();                //Cargando tiempo actual
    //Determinando el tiempó transcurrido
     if (t1_13 = t1_13 - t0_13 >= tiempo){              //Ya son 3 segundos...?
        t0_13 = millis();
        Led2 = !Led2;
        digitalWrite(Led13,Led2);
     }
}

void blink_Led14(int tiempo){
  t1_14 = millis();                //Cargando tiempo actual
     //Determinando el tiempó transcurrido
     if (t1_14 - t0_14 >= tiempo){               //Ya son 500 mili segundos...?  
        t0_14 = millis();  
        Led3 = !Led3;
        digitalWrite(Led14,Led3);
     
     }
}
