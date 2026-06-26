//programa final videojuego Arduino

#include <Wire.h>            //Incluimos la libreria Wire necesaria para la comunicación I2C
#include <Adafruit_GFX.h>    //Incluimos la libreria GFX necesaria para trabajar con gráficos y textos en la OLED
#include <Adafruit_SSD1306.h>  //Incluimos la libreria SSD1306, requerida por el controlador de la OLED

#define SCREEN_WIDTH 128 // Definimos el ancho de la OLED en pixeles
#define SCREEN_HEIGHT 64 // Definimos la altura de la OLED en pixeles

#define OLED_RESET     4 // Se define el pin 4 como RESET, necesario para que trabaje correctamente la librería, pero se puede usar el pin para otros fines
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET); //Creamos un objeto llamado display, indicamos su ancho, alto y pin RESET 

const unsigned char myBitmap6[] PROGMEM = {               //Imagen ave pequeña
0x00, 0xf8, 0x00, 0x00, 0xfc, 0x00, 0x03, 0xee, 0x00, 0x03, 0xff, 0x00, 0x03, 0xdb, 0x80, 0x07, 
  0x01, 0xc0, 0x0e, 0x00, 0xe0, 0x0c, 0x00, 0x70, 0x78, 0x38, 0x30, 0xf8, 0x3e, 0xf0, 0xf0, 0x3f, 
  0xf0, 0xf0, 0x1f, 0xf0, 0x70, 0x1f, 0xf0, 0x30, 0x3e, 0xf0, 0x31, 0xff, 0xf0, 0x1b, 0xdf, 0xf0, 
  0x1f, 0x0f, 0xf0, 0x0f, 0x07, 0xe0, 0x03, 0xff, 0xc0
};

// 'logo_Dynamo_64x64', 61x58px
const unsigned char myBitmap7[] PROGMEM = {              //Imagen logo 
  0x00, 0x00, 0x03, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xff, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x3c, 0x07, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x70, 0x01, 0xc0, 0x00, 0x00, 0x00,
  0x00, 0x00, 0xe0, 0x00, 0x60, 0x00, 0x00, 0x00, 0x00, 0x01, 0xc0, 0x06, 0x74, 0x00, 0x00, 0x00,
  0x00, 0x01, 0x80, 0x1f, 0xbc, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x3f, 0xd8, 0x00, 0x00, 0x00,
  0x00, 0x03, 0x00, 0x7f, 0xd8, 0x00, 0x00, 0x00, 0x00, 0x07, 0x00, 0x7f, 0xec, 0x00, 0x00, 0x00,
  0x00, 0x06, 0x00, 0x79, 0xec, 0x00, 0x00, 0x00, 0x00, 0x06, 0x00, 0x79, 0xec, 0x00, 0x00, 0x00,
  0x00, 0x06, 0x00, 0x79, 0xec, 0x00, 0x00, 0x00, 0x00, 0x06, 0x00, 0x79, 0xec, 0x00, 0x00, 0x00,
  0x00, 0x06, 0x00, 0x7f, 0xec, 0x00, 0x00, 0x00, 0x00, 0x03, 0x30, 0x7f, 0xcc, 0x00, 0x00, 0x00,
  0x00, 0x03, 0xc0, 0x3f, 0xd8, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x80, 0x3f, 0x98, 0x00, 0x00, 0x00,
  0x01, 0xf9, 0x80, 0x0f, 0x30, 0x00, 0x00, 0x00, 0x03, 0xff, 0xff, 0xc0, 0x70, 0x00, 0x00, 0x00,
  0x03, 0xfc, 0xe0, 0x00, 0xe0, 0x00, 0x00, 0x00, 0x03, 0xc0, 0x78, 0x03, 0xc0, 0x00, 0x00, 0x00,
  0x01, 0x80, 0x3f, 0x0f, 0x80, 0x00, 0x00, 0x00, 0x01, 0x80, 0x0f, 0xfe, 0x00, 0x00, 0x00, 0x00,
  0x01, 0x80, 0x01, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x01, 0x80, 0x00, 0x18, 0x00, 0x00, 0x00, 0x00,
  0x01, 0x80, 0x00, 0x38, 0x00, 0x00, 0x00, 0x00, 0x01, 0x80, 0x00, 0x78, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x80, 0x00, 0x7c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x3e, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x80, 0x00, 0x3f, 0x80, 0x00, 0x00, 0x00, 0x02, 0x80, 0x00, 0x03, 0xc0, 0x00, 0x0e, 0x00,
  0x03, 0x80, 0x00, 0x00, 0xf0, 0x01, 0xf0, 0x00, 0x01, 0xc0, 0x00, 0x00, 0x3c, 0x1f, 0x00, 0x00,
  0x00, 0xe0, 0x00, 0x00, 0x0f, 0xf8, 0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x03, 0xc0, 0x00, 0x00,
  0x00, 0x38, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0xfc, 0x20, 0x47, 0x87, 0xc3, 0xc7, 0x83, 0xe0, 0x47, 0x20, 0xcd, 0xce, 0xc6, 0x6c, 0xc6, 0x30,
  0x41, 0xa0, 0xd0, 0x48, 0x2c, 0x38, 0x6d, 0xd0, 0x41, 0xa0, 0xd0, 0x78, 0x2c, 0x10, 0x2b, 0x58,
  0x41, 0xb1, 0x90, 0x78, 0x38, 0x10, 0x2a, 0x78, 0x41, 0x9f, 0x10, 0x78, 0x38, 0x10, 0x2b, 0xd0,
  0x43, 0x04, 0x10, 0x3f, 0xf8, 0x10, 0x2c, 0x30, 0xfc, 0x04, 0x10, 0x38, 0x38, 0x10, 0x27, 0xe0,
  0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x04, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x04, 0xff, 0xfe, 0xe0, 0x00, 0x00, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

// 'angry4040_Ave_grande', 40x40px
const unsigned char myBitmap[] PROGMEM = {  //Imagen ave grande
  0x00, 0x00, 0x3e, 0x00, 0x00, 0x00, 0x00, 0xff, 0xc0, 0x00, 0x00, 0x00, 0xc1, 0xc0, 0x00, 0x00,
  0x00, 0xc0, 0x60, 0x00, 0x00, 0x0f, 0xf0, 0x78, 0x00, 0x00, 0x0f, 0xf8, 0x18, 0x00, 0x00, 0x08,
  0x18, 0x08, 0x00, 0x00, 0x0f, 0x0f, 0x0c, 0x00, 0x00, 0x07, 0xc0, 0x0c, 0x00, 0x00, 0x0f, 0xc0,
  0x0f, 0x00, 0x00, 0x18, 0x00, 0x03, 0x80, 0x00, 0x38, 0x00, 0x01, 0xc0, 0x00, 0x70, 0x00, 0x00,
  0x60, 0x00, 0x60, 0x00, 0x00, 0x70, 0x00, 0xc0, 0x00, 0x00, 0x38, 0x01, 0xc0, 0x00, 0x00, 0x1c,
  0x31, 0x80, 0x07, 0x00, 0x0e, 0x39, 0x00, 0x0f, 0xc0, 0x1e, 0x09, 0x00, 0x0c, 0xc0, 0x3a, 0xcd,
  0x00, 0x0c, 0x60, 0x73, 0xff, 0x00, 0x0f, 0xfd, 0xff, 0xff, 0x00, 0x03, 0xcf, 0x79, 0xfe, 0x00,
  0x06, 0x66, 0x79, 0x3e, 0x00, 0x06, 0x7d, 0xd9, 0x3e, 0x00, 0x03, 0xef, 0xf9, 0x6e, 0x00, 0x07,
  0xff, 0xf9, 0x0e, 0x00, 0x00, 0x70, 0xc1, 0x0e, 0x00, 0x00, 0x40, 0x63, 0x06, 0x00, 0x0f, 0xc0,
  0x7b, 0x06, 0x00, 0x7f, 0xf8, 0x1b, 0x03, 0x01, 0xe1, 0xff, 0xce, 0x03, 0x03, 0x81, 0x8f, 0xfe,
  0x01, 0x0f, 0x01, 0xdc, 0x7e, 0x01, 0xdc, 0x00, 0xfb, 0xdc, 0x00, 0x70, 0x00, 0x3f, 0x38, 0x00,
  0x70, 0x00, 0x0e, 0x70, 0x00, 0x3c, 0x00, 0x04, 0xe0, 0x00, 0x0f, 0x00, 0x01, 0xc0, 0x00, 0x03,
  0xf8, 0x1f, 0x80, 0x00, 0x00, 0x7f, 0xfc, 0x00
};

const int analogInPin = A0;   //Definimos el pin Analogico A0 con el nombre analogInPin
int yB = 0;                   //Creamos el punto en y yB, a partir del cual se empieza a dibujar el ave del juego  
int xP;                       //Creamos el punto en x xP, a partir del cual se empiezan a dibujar las columnas
int yP;                       //Creamos el punto en y yP, que indica la altura de la columna superior               
int puntaje = 0;              //Se crea la variable puntaje donde se guardará el puntaje del jugador

int vel=1;                   //Se crea la variable vel que indica la velocidad con la que se mueven las columnas

void setup() {
    if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Se inicializa la OLED, indicando su dirección I2C
        Serial.println(F("SSD1306 allocation failed"));  //Si no se inicializa la OLED nos dará un mensaje en el monitor serie 
        for (;;); // El programa se queda en este punto si no se inicializa correctamente la OLED
    }

    delay(2000); // Pausa de 2 segundos

 
    display.clearDisplay();  //Limpiamos la OLED
    display.display();

    pinMode(2, INPUT_PULLUP);   //Definimos el pin 2 como entrada con Pull_Up

    yB = analogRead(analogInPin);  //Leemos el pin Analógico A0 y guardamos este dato en la variable yB
    yB = map(yB, 0, 1023, 45, 0);  // Ajustamos el valor de yB para que esté en el rango de 45 a 0

    dibujoLogo();                 //El programa va a ejecutar la rutina dibujoLogo
    delay(3000);                  //Pausa de 3 segundos
    conteo();                     //El programa va a ejecutar la rutina conteo
    
    display.clearDisplay();       //Limpiamos el display
    display.display();            
}



void loop() {

    display.drawBitmap(0, yB, myBitmap6, 20, 19, INVERSE);  //Dibujamos el ave pequeña a partir de las coordenadas 0, yB
    yP = random(0, 34);                                        //Se genera la coordenada yB (valor aleatorio entre 0 y 34)  


    for (xP = 127; xP >= -21; xP--) {             //Rutina de desplazamiento de las columnas a través de la pantalla

        display.fillRect(xP, 0, vel, yP, SSD1306_WHITE);    //  Dibujamos la columna superior (franja a la izquierda dimensiones vel x yP)
        display.fillRect(xP + 20, 0, vel, yP, SSD1306_INVERSE);  //  Borramos a la derecha una franja igual a la dibujada en la izquierda
        display.display();                                       //Enviamos la orden a la OLED


        display.fillRect(xP, yP + 30, vel, 34 - yP, SSD1306_WHITE);  //  Dibujamos la columna inferior (franja a la izquierda dimensiones vel x (34 - yP))
        display.fillRect(xP + 20, yP + 30, vel, 34 - yP, SSD1306_INVERSE);  //Borramos a la derecha una franja igual a la dibujada en la izquierda
        display.display();                                          //Enviamos la orden a la OLED


        display.drawBitmap(0, yB, myBitmap6, 20, 19, INVERSE);   //Dibujamos el ave pequeña a partir de las coordenadas 0, yB
       
        yB = analogRead(analogInPin);                           //Leemos el pin Analógico A0 y guardamos este dato en la variable yB
        yB = map(yB, 0, 1023, 45, 0);                           // Ajustamos el valor de yB para que esté en el rango de 45 a 0


        display.drawBitmap(0, yB, myBitmap6, 20, 19, WHITE);  //Dibujamos el ave pequeña a partir de las coordenadas 0, yB en color inverso al que se dibujó anteriormente (efecto de Borrar)
        display.display();                                     //Enviamos la orden a la OLED

        if (xP >= -20 && xP <= 20) {   //area de choque en x
            if (yB <= yP) {            //choque con la columna superior
                gameOver();            //El programa va a ejecutar la rutina gameOver
            }

            if (yB >= yP + 11) {       //choque con la columna inferior
                gameOver();            //El programa va a ejecutar la rutina gameOver
            }
        }
       
        xP=xP-(vel-1);                //Se modifica el valor de xP para dibujar el siguiente par de columnas
        
    }
    puntaje = puntaje + 1;            //Incrementamos en 1 el puntaje obtenido cuando las 2 columnas realizan el recorrido completo en la OLED
    vel=vel+3;                        //Se aumenta la velocidad con que se desplazan las columnas
    display.clearDisplay();           //Se limpia la OLED

}

void dibujoLogo(){                    //Dibujamos el logo de Dynamo Electronics SAS
  display.drawBitmap(33, 6, myBitmap7, 61, 58, WHITE); // Se dibuja a partir de las coordenadas x=33 y=6
  display.display();                  //Enviamos la orden a la OLED
  
}

void gameOver() {                      //Rutina de Game Over
    display.clearDisplay();           //Limpiamos el display
    display.display();                //Enviamos la orden a la OLED
    display.setTextSize(2);           // Definimos tamaño 2 para los caracteres         
    display.setTextColor(SSD1306_WHITE);        // Definimos color blanco
    display.setCursor(15, 20);             // Definimos las coordenadas desde donde se empieza a escribir
    display.println(F("Game Over"));       //Escribimos Game Over

    display.setTextSize(1);             // Definimos tamaño 1 para los caracteres
    display.setTextColor(SSD1306_WHITE);        // Definimos color blanco
    display.setCursor(15, 50);             //  Definimos las coordenadas desde donde se empieza a escribir
    display.print(F("Puntaje :"));         //Escribimos Puntaje

    display.println(puntaje);              //Escribimos el valor de la variable puntaje


    display.display();                    // Mostramos en el display los mensajes
    while (digitalRead(2)) {              //condición para que se quede el programa mostrando Game Over 

    }

    xP = -22;                            //ajustamos xP para que nos saque del for (movimiento de las columnas)
    puntaje = -1;                        //ajustamos puntaje para que nos saque del for (movimiento de las columnas)
    vel=0;                               //Reiniciamos la velocidad, para que el juego inicie a la velocidad minima

    display.clearDisplay();              //Limpiamos la pantalla
    display.display();                   //Enviamos la orden a la OLED
    dibujoLogo();                        //El programa va a ejecutar la rutina dibujoLogo
    delay(3000);                         //Pausa de 3 segundos
    conteo();                            //El programa va a ejecutar la rutina conteo
}

void conteo() {                          //Rutina conteo
   
    display.clearDisplay();              //Limpiamos la OLED
    display.fillRect(0, 54, 128, 10, SSD1306_INVERSE);  //Dibujamos una franja de 128 pixeles x 10 pixeles a partir de las coordenas x=0 y=54
    display.display(); //Enviamos la orden a la OLED

    display.fillRect(0, 0, 128, 8, SSD1306_INVERSE);  //Dibujamos una franja de 128 pixeles x 8 pixeles a partir de las coordenas x=0 y=0
    display.display(); //Enviamos la orden a la OLED

    display.setTextSize(1);      // Definimos tamaño 1 para los caracteres
    display.setCursor(10, 55);     // Definimos los puntos desde donde se empieza a escribir
    display.write("dynamo electronics");  //Escribimos el mensaje dynamo electronics
    display.display();                    //Enviamos la orden a la OLED

    display.setTextSize(1);      // Definimos tamaño 1 para los caracteres
    display.setTextColor(SSD1306_INVERSE); // Definimos el color inverso para los caracteres
    display.setCursor(0, 0);     // Definimos los puntos desde donde se empieza a escribir
    display.write("score");      //Escribimos el mensaje score
    display.display();           //Enviamos la orden a la OLED


    display.drawBitmap(0, 12, myBitmap, 40, 40, WHITE);  //Dibujamos el ave grande en color blanco a partir de las coordenadas x=0 y=12 
    display.display();           //Enviamos la orden a la OLED

    display.setTextSize(4);      // Definimos tamaño 4 para los caracteres
    display.setTextColor(SSD1306_WHITE); // Definimos el color blanco para los caracteres
    display.setCursor(70, 15);     // Definimos los puntos desde donde se empieza a escribir
    display.write("3");            //Escribimos el numero 3
    display.display();              //Enviamos la orden a la OLED
    delay(1000);                    //Mostramos el número 3 durante 1 segundo

    display.setTextSize(4);      // Definimos tamaño 4 para los caracteres
    display.setTextColor(SSD1306_INVERSE); // Definimos el color inverso para los caracteres  (Borrar el número 3 antes dibujado)
    display.setCursor(70, 15);     // Definimos los puntos desde donde se empieza a escribir
    display.write("3");            //Escribimos el numero 3
    display.display();             //Enviamos la orden a la OLED
    delay(500);                    //Pausa de 500ms


    display.setTextSize(4);      // Definimos tamaño 4 para los caracteres
    display.setTextColor(SSD1306_WHITE); // Definimos el color blanco para los caracteres
    display.setCursor(70, 15);      // Definimos los puntos desde donde se empieza a escribir
    display.write("2");              //Escribimos el numero 2
    display.display();               //Enviamos la orden a la OLED
    delay(1000);                      //Mostramos el número 2 durante 1 segundo

    display.setTextSize(4);      // Definimos tamaño 4 para los caracteres
    display.setTextColor(SSD1306_INVERSE); // Definimos el color inverso para los caracteres
    display.setCursor(70, 15);     // Definimos los puntos desde donde se empieza a escribir
    display.write("2");            //Escribimos el numero 2
    display.display();             //Enviamos la orden a la OLED
    delay(500);                    //Pausa de 500ms

    display.setTextSize(4);      // Definimos tamaño 4 para los caracteres
    display.setTextColor(SSD1306_WHITE); // Definimos el color blanco para los caracteres
    display.setCursor(70, 15);     // Definimos los puntos desde donde se empieza a escribir
    display.write("1");            //Escribimos el numero 1
    display.display();             //Enviamos la orden a la OLED
    delay(1000);                    //Mostramos el número 1 durante 1 segundo

    display.setTextSize(4);      // Definimos tamaño 4 para los caracteres
    display.setTextColor(SSD1306_INVERSE); // Definimos el color inverso para los caracteres
    display.setCursor(70, 15);     // Definimos los puntos desde donde se empieza a escribir
    display.write("1");            //Escribimos el numero 1
    display.display();             //Enviamos la orden a la OLED
    delay(500);                    //Pausa de 500ms
}
