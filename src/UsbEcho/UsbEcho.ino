void setup()
{
  Serial.begin(9600);
}

void loop()
{
  if (Serial.available() > 0)
  {
    auto in = Serial.read();
    Serial.print(static_cast<char>(in));
  }
}