// Definindo os pinos
const int INFRAVERMELHO_PIN = A0;      // Sensor IR - Usado para infrvermelhor
const int TRIG_DISTANCIA_PIN = 9;            // Trigger pin for ultrasonic sensor
const int ECHO_DISTANCIA_PIN = 10;           // Echo pin for ultrasonic sensor
const int VELOCIDADE_PIN = A1;            // Analog pin for potentiometer
const int CONTROLADOR_DIST_PIN = 6;           // PWM pin for motor control

void setup() {
  // Initialize serial communication
  Serial.begin(9600);
  
  // Initialize pins
  pinMode(INFRAVERMELHO_PIN, INPUT);
  pinMode(TRIG_DISTANCIA_PIN, OUTPUT);
  pinMode(ECHO_DISTANCIA_PIN, INPUT);
  pinMode(VELOCIDADE_PIN, INPUT);
  pinMode(CONTROLADOR_DIST_PIN, OUTPUT);
}

void loop() {
  // Simulando densidade de óleo na água
  int infraValor = analogRead(INFRAVERMELHO_PIN);
  int porcent = map(infraValor, 0, 1023, 0, 100);
  Serial.print("valor do infravermelho: ");
  Serial.print(infraValor);
  Serial.print(" (");
  Serial.print(porcent);
  Serial.println("%)");

  // Distância
  long duracao, dist;
  digitalWrite(TRIG_DISTANCIA_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_DISTANCIA_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_DISTANCIA_PIN, LOW);
  duracao = pulseIn(ECHO_DISTANCIA_PIN, HIGH);
  dist = (duracao / 2) / 29.1;  // Convertendo para centimetros
  Serial.print("Distância: ");
  Serial.print(dist);
  Serial.println(" cm");

  // Potenciometro lendo, mapeando para CONTROLADOR_DIST_PIN
  int potValue = analogRead(VELOCIDADE_PIN);
  int velocidadeMotor = map(potValue, 0, 1023, 0, 255);
  analogWrite(CONTROLADOR_DIST_PIN, velocidadeMotor);
  Serial.print("Velocidade do motor: ");
  Serial.println(velocidadeMotor);

  // Checando obstaculos
  if (dist < 10) {
    Serial.println("Objeto a frente detectado! Parando os motores");
    analogWrite(CONTROLADOR_DIST_PIN, 0);  // Parando o motor caso algo foi detectado
  }

  // Delay before next reading
  delay(500);
}
