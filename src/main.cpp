/**@brief 
   DDRX or data direction register controls the direction that data passes through the port, this essentially sets the pin to an input or an output.
  To set a pin to an output simply write the relevant register bit to 1.
  OUTPUT 1
  INPPUT 0

  The PORTx registers are the output buffers that we use to write to a specific IO pin or a complete port of pins. 
  The PORTx bit will set the value of the corresponding IO pin to 1 or 0. But it has first to be set as an output pin (TRIS is enabled) by setting the corresponding DDRx bit to 1.
*/

#define SET_PORT_MODE(port, ddr_cfg) (DDR ## port = ddr_cfg) //SET_PORT_MODE(B, 0x03);
#define PORT_SET_HIGH(port) (PORT ## port= B11111111) //set all pins to High
#define PORT_SET_LOW(port) (PORT ## port= B00000000 )
#define PORT_WRITE(port, data) (PORT ## port= data)
#define PORT_READ(port) PIN ## port

#define SET_PIN_MODE(port, pin, mode) \
  if (mode == INPUT) { \
    DDR ## port &= ~(1 << pin); \
  } else if (mode == OUTPUT) { \
    DDR ## port |= (1 << pin); \
  }

#define SET_PIN_LOW(port, pin) ((PORT ## port) &= ~(1 << (pin)))
#define SET_PIN_HIGH(port, pin) (PORT ## port |= (1 << pin))




void setup() {

  //DDRD |= (1<<DDD2); //pinMode(1,INPUT), equivalent to DDRD = B00000100
  //DDRD &= ~(1<<DDD2); //pinMode(1,OUTPUT)
  Serial.begin(9600);

  SET_PIN_MODE(D, 2, OUTPUT)
  

}

void loop() {
  SET_PIN_HIGH(D,2);
  delay(500);
  SET_PIN_LOW(D,2);
  delay(500);
  

}

