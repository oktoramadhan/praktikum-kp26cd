# Panduan Update Dokumentasi Praktikum KP26

Repository:

```text
https://github.com/oktoramadhan/praktikum-kp26cd
```

## 1. Prerequisite

Install **Git**:

```text
https://git-scm.com/downloads
```

Install **NVM (Node Version Manager)**.

### Linux / macOS

Gunakan NVM dari repository resminya:

```bash
curl -o- https://raw.githubusercontent.com/nvm-sh/nvm/v0.40.3/install.sh | bash
```

Tutup dan buka kembali Terminal, kemudian cek:

```bash
nvm --version
```

### Windows

Gunakan **NVM for Windows**:

```text
https://github.com/coreybutler/nvm-windows
```

Setelah instalasi selesai, buka kembali PowerShell / Terminal dan cek:

```bash
nvm version
```

---

## 2. Install Node.js

Gunakan Node.js LTS:

```bash
nvm install --lts
nvm use --lts
```

Cek:

```bash
node --version
npm --version
```

---

## 3. Clone Repository

Pilih lokasi project, kemudian:

```bash
git clone https://github.com/oktoramadhan/praktikum-kp26cd.git
```

Masuk ke project:

```bash
cd praktikum-kp26cd
```

---

## 4. Install Dependencies

```bash
npm install
```

---

## 5. Ambil Update Terbaru

Sebelum mengedit:

```bash
git pull origin main
```

---

## 6. Edit Dokumentasi

Masuk ke folder:

```bash
cd docs
```

Edit atau tambahkan file `.md`.

Setelah selesai:

```bash
cd ..
```

---

## 7. Cek Website

Jalankan:

```bash
npm run start
```

Buka:

```text
http://localhost:3000
```

Untuk menghentikan server:

```text
Ctrl + C
```

---

## 8. Cek Build

```bash
npm run build
```

Pastikan build berhasil tanpa error.

---

## 9. Push ke GitHub

```bash
git add .
git commit -m "Update dokumentasi"
git push origin main
```

Setelah berhasil push, **Vercel akan otomatis memperbarui website**.

---

## ⚡ Alur Singkat

Setelah setup pertama selesai:

```bash
git pull origin main
```

Edit:

```text
docs/
```

Kemudian:

```bash
npm run build
git add .
git commit -m "Update dokumentasi"
git push origin main
```

Selesai.