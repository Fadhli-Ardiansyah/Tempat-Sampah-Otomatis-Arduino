#include <Servo.h>

Servo tutupSampah;

const int trigPin = 9;
const int echoPin = 8;
const int servoPin = 3;

long duration;
int distance;

void setup() {
  tutupSampah.attach(servoPin);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
  tutupSampah.write(0); // Tutup dalam posisi tertutup saat mulai
}

void loop() {
  // Mengirim trigger pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Membaca waktu pantulan echo
  duration = pulseIn(echoPin, HIGH);

  // Menghitung jarak
  distance = duration * 0.034 / 2;

  Serial.print("Jarak: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Cek jarak, kalau dekat buka tutup
  if (distance < 20) {
    tutupSampah.write(90); // Buka tutup
    delay(3000); // Tunggu 3 detik
    tutupSampah.write(0); // Tutup kembali
  }

  delay(500); // Delay sedikit supaya lebih stabil (nilai bisa diganti sesuai kebutuhan)
}
