# VS-DTP-WORD
> **Professional Desktop Publishing (DTP) &amp; AI Translation Word Processor software built with C++ and Qt 6. 
---

## 📌 Project Overview
**VS DTP WORD** is a high-performance, offline-first Desktop Publishing and AI-powered word processor designed specifically for complex Indian multilingual text composition, real-time transliteration, and document management. Built using C++20 and Qt 6, it delivers a fast, MS Word-like desktop environment for high-speed typing and translation.

---

## ✨ Key Features

### 🌐 Multilingual AI Translation & Transliteration
* **18 Supported Languages:** English, Hindi, Marathi, Urdu, Bengali, Tamil, Kannada, Malayalam, Telugu, Odia, Punjabi, Gujarati, Sanskrit, Kashmiri, Konkani, Nepali, Assamese, Manipuri.
* **Dual English Input Translation Modes:**
  1. **Original English Translation:** Standard English to any target Indian language.
  2. **Roman English Transliteration:** Phonic Roman typing directly converting into native script (e.g., `BHARAT EK MAHAN DESH AAHE` $\rightarrow$ `भारत एक महान देश आहे`).
* **Offline AI Core:** Integrates ONNX Runtime with NLLB-200 / M2M100 models.
* **Hybrid Context Resolver:** Context-aware and ambiguous word resolution.

### 📄 DTP & Document Processing
* **MS Word Canvas Experience:** WYSIWYG editor supporting custom `.dtpx` format alongside `.docx`, `.pdf`, `.rtf`, and `.txt`.
* **Complex Script Rendering:** HarfBuzz + FreeType engine for seamless Indian script typesetting.
* **Quality Check Engine:** Automated detection for missing lines, numbers, dates, and punctuation.
* **Licensing System:** Built-in 5-day free trial timer and hardware key activation logic.

---

## 🛠️ Technology Stack
* **Language:** C++20
* **GUI Framework:** Qt 6 (Widgets, Gui, PrintSupport)
* **Build System:** CMake (3.16+)
* **Compiler Target:** Microsoft Visual Studio (MSVC) 64-bit

---

## 🚀 How to Build Locally

### Prerequisites
* Visual Studio 2022 / C++ Build Tools
* CMake 3.16+
* Qt 6.5+ (MSVC 2019/2022 64-bit)

### Build Commands
```bash
# Clone the repository
git clone [https://github.com/cgthete91/VS-DTP-WORD.git](https://github.com/cgthete91/VS-DTP-WORD.git)
cd VS-DTP-WORD

# Configure the project
cmake -B build -S . -DCMAKE_BUILD_TYPE=Release -G "Visual Studio 17 2022" -A x64

# Build the executable
cmake --build build --config Release
