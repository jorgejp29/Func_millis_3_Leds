//****************************************************************************************
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
//****************************************************************************************

#define CAMERA_MODEL_AI_THINKER

#define Led12 12


//Inicializar el tiempo del Led12.
unsigned long t0_12 = 0;


//  Variables correspondientes al tiempo siguiente
//  del Led12.
unsigned long t1_12 = 0;


byte Enc_12 = 1;


void setup() {
  //Configurando Leds12 como salida
  pinMode(Led12,OUTPUT);
}

void loop() {

//****************************************************
//  Bloque de progarma de blink del Led12
//****************************************************
     t1_12 = millis();                //Cargando tiempo actual
     t1_12 = t1_12 - t0_12;           //Determinando el tiempó transcurrido
     if (t1_12 >= 5000){              //Ya son 5 segundos...?
      if(Enc_12 ==1){                 //Sí, Encender...? SI
        digitalWrite(Led12,HIGH);     
        Enc_12 = 0;
        t0_12 = millis();             //Reiniciar t0_12
      }
      else {                          //Si, Apagar....? SI     
        digitalWrite(Led12,LOW);
        Enc_12 = 1;
        t0_12 = millis();             //Reiniciar t0_12
      }
     }

     //  Fin de Bloque de progarma de blink del Led12
//****************************************************    
    
}
