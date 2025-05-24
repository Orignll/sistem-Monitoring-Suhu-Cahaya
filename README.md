### 📌 **Deskripsi Maksud dan Tujuan dari Kode Arduino Ini**

---

#### 🔍 **Maksud dari Kode**

Kode ini dibuat untuk **membaca data dari dua jenis sensor**, yaitu:

* **Sensor suhu** (dihubungkan ke pin A0), dan
* **Sensor cahaya (LDR)** (dihubungkan ke pin A1),

...kemudian **mengirimkan hasil pembacaan** tersebut ke aplikasi Android melalui **modul Bluetooth HC-05/HC-06**. Namun, pengiriman data hanya akan dilakukan **jika aplikasi Android memberikan izin** (dikirim dalam bentuk perintah melalui Bluetooth).

---

#### 🎯 **Tujuan dari Kode**

1. **Monitoring lingkungan secara real-time**:

   * Memantau suhu dan intensitas cahaya di sekitar sensor.
   * Data dapat dilihat dari aplikasi Android secara berkala.

2. **Menggunakan Bluetooth sebagai jalur komunikasi**:

   * Data dikirim secara **nirkabel** menggunakan modul Bluetooth (misalnya HC-05).
   * Aplikasi Android dapat mengontrol apakah data sensor perlu dikirim atau dihentikan.

3. **Meningkatkan akurasi data**:

   * Setiap data yang dikirim merupakan **rata-rata dari beberapa pembacaan** untuk mengurangi noise atau fluktuasi nilai sensor.

4. **Memberikan kontrol dari pengguna aplikasi**:

   * Pengguna aplikasi Android dapat mengirim perintah `0` atau `1`:

     * `0`: Menghentikan pengiriman data sensor.
     * `1`: Mengizinkan pengiriman data sensor.

---

#### 📱 **Contoh Penerapan Nyata**

* **Sistem monitoring suhu dan pencahayaan ruangan** dari jarak jauh.
* **Smart green house** (rumah kaca pintar) di mana pengguna bisa melihat kondisi tanaman dari aplikasi Android.
* **Proyek edukasi IoT**, yang mengajarkan bagaimana sensor dikombinasikan dengan komunikasi nirkabel.

---

Jika kamu ingin menambahkan fitur lain, seperti:

* Menampilkan data di LCD,
* Menyimpan data ke SD Card,
* Atau menambahkan alarm saat suhu terlalu tinggi,

Silakan beri tahu, saya bisa bantu sesuaikan kodenya.
