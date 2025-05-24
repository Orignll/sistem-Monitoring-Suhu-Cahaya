
#include <SoftwareSerial.h> // Jika Anda menggunakan modul Bluetooth HC-05/HC-06
SoftwareSerial BTSerial(10, 11); // RX, TX (pin sesuai dengan koneksi Anda)


const int sensorSuhu = A0; // Pin sensor suhu
const int sensorLDR = A1;  // Pin sensor cahaya (LDR)
int izin = 0;              // Status izin (0 = tidak diizinkan, 1 = diizinkan)
int jml_nilai = 5;         // Jumlah nilai untuk menghitung rata-rata


void setup() {
  Serial.begin(9600);      // Untuk debugging melalui Serial Monitor
  BTSerial.begin(9600);    // Untuk komunikasi dengan Bluetooth
  pinMode(sensorSuhu, INPUT);
  pinMode(sensorLDR, INPUT);
}
void loop() {
  // Periksa apakah ada data dari aplikasi Android
  if (BTSerial.available()) {
    int command = BTSerial.read(); // Membaca byte perintah
    switch (command) {
      case 48: // Tidak diizinkan
        izin = 0;
        Serial.println("Data sensor dihentikan.");
        break;
      case 49: // Diizinkan
        izin = 1;
        Serial.println("Data sensor diizinkan.");
        break;
      default:
        Serial.println("Perintah tidak dikenali.");
        break;
    }
  }


  // Jika izin diberikan, kirim data sensor
  if (izin == 1) {
    kirimDataSensor();
    delay(1000); // Interval pengiriman data (2 detik, dapat disesuaikan)
  }
}
// Fungsi untuk membaca sensor suhu dan cahaya lalu mengirimkan rata-rata ke aplikasi
void kirimDataSensor() {
  int totalSuhu = 0, totalLDR = 0;

  // Hitung rata-rata berdasarkan jumlah nilai (jml_nilai)
  for (int i = 0; i < jml_nilai; i++) {
    int nilaiSuhu = analogRead(sensorSuhu); // Membaca nilai sensor suhu
    int nilaiLDR = analogRead(sensorLDR);   // Membaca nilai sensor LDR
    totalSuhu += nilaiSuhu;
    totalLDR += nilaiLDR;
    delay(10); // Beri jeda kecil untuk pengukuran yang stabil
  }

  // Hitung rata-rata
  float rataRataSuhu = totalSuhu / (float)jml_nilai;
  float rataRataLDR = totalLDR / (float)jml_nilai;
  // Kirimkan data ke aplikasi dalam format yang mudah diolah
  BTSerial.print("Interval:");
  BTSerial.println(jml_nilai);
  BTSerial.print("Suhu:");
  BTSerial.println(rataRataSuhu);
  BTSerial.print("LDR:");
  BTSerial.println(rataRataLDR);
  // Debugging ke Serial Monitor
  Serial.print("Interval: ");
  Serial.print(jml_nilai);
  Serial.print(" | Suhu: ");
  Serial.print(rataRataSuhu);
  Serial.print(" | LDR: ");
  Serial.println(rataRataLDR);
}
