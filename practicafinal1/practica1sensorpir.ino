int dataPin = 4;
int latchPin = 5;
int clockPin = 6;
int ejex = 0;
int ejey = 0;
int mode = 0;
int delayxy = 200;
int cadena = B00000000;
int direccion = 0;
void setup()
{
    pinMode(0,INPUT);
    pinMode(11,INPUT_PULLUP);
    pinMode(latchPin, OUTPUT);
    pinMode(dataPin, OUTPUT);
    pinMode(clockPin, OUTPUT);
    Serial.begin(9600);
}

void loop()
{

    ejex =analogRead(A0);
    ejey =analogRead(A1);

    if(digitalRead(11) == LOW)
    {
        if(mode == 1)
        {
            mode = 0;
        }
        else if(mode == 0)
        {
            mode = 1;
        }
    }
    if(mode == 1)//modo joystick
    {

        delay(delayxy);
        if(ejex < 350)
        {
            delayxy = 100;
        }
        else if(ejex > 675)
        {
                delayxy = 1000;
        }

        if(ejey < 350)
        {
            direccion = 1;
        }
        else if(ejey > 675)
        {
            direccion = 0;
        }

        if (direccion == 0)
        {
            for(int i = 0; i < 8; i++)
            {
                bitSet(cadena,i);
                digitalWrite(latchPin, 0);
                shiftOut(dataPin, clockPin, LSBFIRST,cadena);
                digitalWrite(latchPin, 1);
                delay (delayxy);
                cadena=B00000000;

            }
        }
        else if(direccion == 1)
        {
            for(int i = 8; i >= 0; i--)
            {
                bitSet(cadena,i);
                digitalWrite(latchPin, 0);
                shiftOut(dataPin, clockPin, LSBFIRST,cadena);
                digitalWrite(latchPin, 1);
                delay (delayxy);
                 cadena=B00000000;

            }
        }
    }
    else if(mode == 0)
    {
        //sensor pir
            digitalWrite(latchPin, 0);
            shiftOut(dataPin, clockPin, LSBFIRST,B00000000);
            digitalWrite(latchPin, 1);
        if(digitalRead(0) == HIGH)
        {
            for(int i = 0; i<=3; i++)
                digitalWrite(latchPin, 0);
            shiftOut(dataPin, clockPin, LSBFIRST,B11111111);
            digitalWrite(latchPin, 1);
            delay(100);
            digitalWrite(latchPin, 0);
            shiftOut(dataPin, clockPin, LSBFIRST,B00000000);
            digitalWrite(latchPin, 1);
            delay(100);
        }
    }
}
