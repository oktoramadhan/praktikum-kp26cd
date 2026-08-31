# Panduan Kontribusi Dokumentasi Praktikum KP26

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

### Install Node.js

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

## 2. Clone Repository (Hanya Sekali di Awal)

Jika ini **pertama kali** kamu berkontribusi dan belum punya project ini di komputer, clone repository-nya:

```bash
git clone https://github.com/oktoramadhan/praktikum-kp26cd.git
```

Masuk ke project:

```bash
cd praktikum-kp26cd
```

Install dependencies:

```bash
npm install
```

> ⚠️ **Jangan clone ulang** jika kamu sudah pernah clone sebelumnya. Cukup masuk ke folder project yang sudah ada (`cd praktikum-kp26cd`) lalu lanjutkan ke langkah **Update main** di bawah. Clone berulang hanya akan membuat folder/copy project baru dan bikin bingung branch mana yang aktif.

---

## 3. Alur Kerja Kontribusi (Branch & Pull Request)

Setiap perubahan **wajib** dikerjakan di branch terpisah, bukan langsung di `main`.

### Update main

Pastikan `main` di lokal kamu sudah yang terbaru:

```bash
git switch main
git pull origin main
```

### Buat branch baru

```bash
git switch -c nama-branch-bebas
```

### Kerjakan perubahan

Edit dokumentasi atau kode sesuai kebutuhan.

### Test sebelum commit

```bash
npm run build
npm run serve
```

Pastikan build berhasil dan tampilan sudah sesuai sebelum lanjut.

### Commit perubahan

```bash
git add .
git commit -m "deskripsi perubahan"
```

### Push branch

```bash
git push -u origin nama-branch-bebas
```

### Buat Pull Request

1. Buka repository di GitHub.
2. Akan muncul notifikasi untuk branch yang baru saja di-push — klik **Compare & pull request**.
3. Isi judul dan deskripsi perubahan dengan jelas.
4. Klik **Create pull request**.
5. Setelah direview dan disetujui, klik **Merge pull request** untuk menggabungkan perubahan ke `main`.

> ⚠️ **Jangan lupa klik Merge pull request** setelah PR disetujui — perubahan tidak akan masuk ke `main` sebelum langkah ini dilakukan.

---

## ⚡ Alur Singkat

**Catatan:** clone (`git clone ...` + `npm install`) hanya dilakukan **sekali di awal**. Jika sudah pernah clone, langsung mulai dari `git switch main` di bawah ini — tidak perlu clone lagi.

```bash
git switch main
git pull origin main
git switch -c nama-branch-bebas

# edit dokumentasi ...

npm run build
npm run serve

git add .
git commit -m "deskripsi perubahan"
git push -u origin nama-branch-bebas
```

Lalu buka PR di GitHub → **Compare & pull request** → **Create pull request** → setelah disetujui, **Merge pull request**.