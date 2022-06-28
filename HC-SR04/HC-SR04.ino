bool out = false;
const byte sensor[2] = {5, 6}, mdelay[3] = {4, 10, 0};
byte c, i;
short dist = 0, cache = 0;
short trash[13] = {0};
long int time;

short getDistance()
{
    for (c = 0; c < (sizeof(trash) / sizeof(short)); c++)
    {
        for (i = 0; i < 3; i++)
        {
            digitalWrite(sensor[1], out);
            delayMicroseconds(mdelay[i]);
            out = !out;
        }
        time = pulseIn(sensor[0], HIGH);
        time = time * 10 / 579;
        if (time < 334 and time > 2)
        {
            if (c == 0)
                trash[c] = time;
            else if ((time - trash[c - 1] < 8) && (trash[c - 1] - time < 8))
                trash[c] = time;
            else
                trash[c] = trash[c - 1];
        }
    }
    time = 0;
    for (c = 0; c < (sizeof(trash) / sizeof(short)); c++)
        time += trash[c];
    time /= (sizeof(trash) / sizeof(short));
    return time;
}

void setup()
{
    Serial.begin(9600);
    pinMode(sensor[0], INPUT);
    pinMode(sensor[1], OUTPUT);
}

void loop()
{
    cache = dist;
    dist = getDistance();
    if (cache != dist)
        Serial.println("Distancia: " + String(dist) + "cm");
}