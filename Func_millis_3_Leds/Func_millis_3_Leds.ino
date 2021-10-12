//*****************************************************************************************
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

byte Enc_12 = 1;
byte Enc_13 = 1;
byte Enc_14 = 1;



void setup() {
  //Co0nfigurando los LedsXX como salidas
  pinMode(Led12,OUTPUT);
  pinMode(Led13,OUTPUT);
  pinMode(Led14,OUTPUT);
}

void loop() {

//****************************************************
//  Bloque de progarma de blink del Led12
//****************************************************
     t1_12 = millis();                //Cargando tiempo actual
     t1_12 = t1_12 - t0_12;           //Determinando el tiempó transcurrido
     if (t1_12 >= 5000){              //Ya son 5 segundos...?
      if(Enc_12 ==1){                 //Sí son 5 segundos, Encender...
        digitalWrite(Led12,HIGH);     
        Enc_12 = 0;
        t0_12 = millis();             //Reiniciar t0_12
      }
      else {                          //Sí son 5 segundos, Apagar....    
        digitalWrite(Led12,LOW);
        Enc_12 = 1;
        t0_12 = millis();             //Reiniciar t0_12
      }
     }

     //  Fin de Bloque de progarma de blink del Led12
//****************************************************    

//****************************************************
//  Bloque de progarma de blink del Led13
//****************************************************
     t1_13 = millis();                //Cargando tiempo actual
     t1_13 = t1_13 - t0_13;           //Determinando el tiempó transcurrido
     if (t1_13 >= 3000){              //Ya son 3 segundos...?
      if(Enc_13 ==1){                 //Sí, Encender... 
        digitalWrite(Led13,HIGH);     
        Enc_13 = 0;
        t0_13 = millis();             //Reiniciar t0_13
      }
      else {                          //Si, Apagar....     
        digitalWrite(Led13,LOW);
        Enc_13 = 1;
        t0_13 = millis();             //Reiniciar t0_13
      }
     }

     //  Fin de Bloque de progarma de blink del Led13
//****************************************************  


//****************************************************
//  Bloque de progarma de blink del Led14
//****************************************************
     t1_14 = millis();                //Cargando tiempo actual
     t1_14 = t1_14 - t0_14;           //Determinando el tiempó transcurrido
     if (t1_14 >= 500){               //Ya son 500 mili segundos...?
      if(Enc_14 ==1){                 //Sí, Encender...
        digitalWrite(Led14,HIGH);     
        Enc_14 = 0;
        t0_14 = millis();             //Reiniciar t0_14
      }
      else {                          //Si, Apagar....   
        digitalWrite(Led14,LOW);
        Enc_14 = 1;
        t0_14 = millis();             //Reiniciar t0_14
      }
     }

     //  Fin de Bloque de progarma de blink del Led14
//****************************************************  

    
}
