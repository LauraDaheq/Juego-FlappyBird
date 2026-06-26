# Flappy Bird - Juego Arduino 🎮

Versión interactiva del famoso juego Flappy Bird implementada en Arduino con pantalla OLED de 128x64 píxeles.

## Descripción del Proyecto

Este proyecto recrea el clásico juego Flappy Bird en un Arduino UNO con una pantalla OLED. El jugador controla un ave que debe evitar columnas de obstáculos navegan a través de la pantalla. Utiliza un potenciómetro para controlar la altura del ave y un botón para reiniciar el juego.

## Características

- ✅ Juego Flappy Bird totalmente funcional en OLED
- ✅ Control analógico del ave mediante potenciómetro (Pin A0)
- ✅ Gráficos bitmap personalizados
- ✅ Sistema de puntuación
- ✅ Dificultad progresiva (velocidad aumenta)
- ✅ Pantalla de Game Over con puntuación
- ✅ Cuenta regresiva antes de iniciar (3, 2, 1)
- ✅ Logo de Dynamo Electronics

## Componentes Utilizados

- **Arduino UNO**: Microcontrolador principal
- **Pantalla OLED SSD1306**: 128x64 píxeles, comunicación I2C
- **Potenciómetro 10kΩ**: Control del movimiento del ave
- **Botón pulsador**: Reinicio del juego
- **Protoboard**: Para las conexiones
- **Cables jumper**: Conexiones del circuito

## Pines Utilizados

| Componente | Pin Arduino |
|-----------|------------|
| SDA (OLED) | A4 (I2C) |
| SCL (OLED) | A5 (I2C) |
| Potenciómetro | A0 |
| Botón Reinicio | 2 |
| OLED RESET | 4 |

## Librerías Requeridas

```cpp
#include <Wire.h>            // Comunicación I2C
#include <Adafruit_GFX.h>    // Gráficos y textos
#include <Adafruit_SSD1306.h> // Driver para OLED SSD1306
```

**Instalación en Arduino IDE:**
- Sketch → Incluir librería → Administrador de librerías
- Busca "Adafruit SSD1306" e instala

## Cómo Jugar

1. **Carga el código** en tu Arduino UNO
2. **Realiza las conexiones** según el esquema proporcionado
3. **Alimenta el Arduino** (5V)
4. Espera la pantalla de inicio con el logo de Dynamo Electronics
5. **Mueve el potenciómetro** para controlar la altura del ave
6. **Evita las columnas** - El ave sube al mover el potenciómetro hacia arriba
7. **Maximiza tu puntuación** - Cada vez que pasas dos columnas obtienes 1 punto
8. **Si chocas**, aparecerá "Game Over" con tu puntuación
9. **Presiona el botón** para jugar de nuevo

## Mecánicas del Juego

### Movimiento
- **Potenciómetro A0**: Controla la posición vertical del ave (0-1023 → 0-45 píxeles)
- Rango: Límite superior (y=0) a límite inferior (y=45)

### Obstáculos
- **Columnas de obstáculos**: Aparecen aleatoriamente en la pantalla
- **Espaciado**: 30 píxeles entre la columna superior e inferior
- **Velocidad**: Aumenta 3 unidades por columna superada

### Colisión
- Se detectan colisiones en zona (x: -20 a 20, y: 0 a 64)
- Contacto con cualquier columna = Game Over

### Puntuación
- +1 punto por cada par de columnas superadas
- Se muestra al hacer Game Over
- La dificultad aumenta con la velocidad

## Estructura del Código

```
setup()        - Inicializa OLED, pines y muestra pantalla de inicio
loop()         - Bucle principal del juego
dibujoLogo()   - Dibuja el logo de inicio
conteo()       - Cuenta regresiva (3-2-1) antes de jugar
gameOver()     - Pantalla de fin de juego y reinicio
flashSequence()- (Ejemplo de función auxiliar)
```

## Gráficos Incluidos

- **myBitmap6**: Ave pequeña (20x19 píxeles)
- **myBitmap7**: Logo Dynamo Electronics (61x58 píxeles)
- **myBitmap**: Ave grande para pantalla de inicio (40x40 píxeles)

## Mejoras Posibles

- 🎵 Agregar sonidos con buzzer
- 🏆 Guardar puntuación máxima en EEPROM
- 🎨 Agregar más gráficos y animaciones
- 📊 Mostrar velocidad actual en pantalla
- 🎮 Agregar diferentes niveles de dificultad
- 📱 Control con acelerómetro/giroscopio

## Notas Técnicas

- **Dirección I2C OLED**: 0x3C (configurable en código)
- **Velocidad I2C**: 400 kHz (por defecto)
- **Velocidad inicial**: vel = 1 píxel/frame
- **Aumento de velocidad**: +3 por columna
- **Frecuencia actualización**: ~60-100 FPS según velocidad

## Troubleshooting

| Problema | Solución |
|----------|----------|
| OLED no se enciende | Verifica conexión I2C (SDA/SCL) |
| Ave no se mueve | Comprueba potenciómetro en A0 |
| No se reinicia el juego | Verifica botón en pin 2 |
| Imagen distorsionada | Reinicia Arduino (botón RESET) |

## Autor

Laura Daheq

---

**Proyecto creado:** 2026  
**Tecnología:** Arduino UNO + OLED SSD1306
