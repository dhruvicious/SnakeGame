# 🐍 Snake Game (C++ / Raylib)

A modern take on the **classic Snake game**, built in **C++** with **Raylib** for rendering and **CMake** for build automation.  
The project features clean architecture, interactive UI, multiple levels, and robust **unit tests powered by Catch2**.

---

## ✨ Features

-   🎮 **Controls:** W, A, S, D
-   🍎 **Moving food** — makes gameplay more challenging
-   🔰 **3 levels with unique layouts**
-   🟢 **Rendering & UI with Raylib**
-   🧪 **Unit testing with Catch2**
-   🧱 **OOP Game Patterns**: Command, Game Loop
-   🧩 **Layered design** → `{core logic}` + `{render}` → `{game logic}` → game loop
-   📁 **Clean folder structure** with **CMake build system**
-   📄 **Doxygen documentation**
-   📑 **Clang formatting** for consistent code style

---

## Screen Capture

![Demo](GITPic/1.gif)

## 🛠 How to Build & Run

1. Clone the repository
2. Open a terminal in the project root
3. Run:
    ```bash
    cmake -S . -B ./build
    cmake --build ./build
    ./build/source/app/SnakeMain   # Run the game
    ```

## 🧪 Running the Tests

    ```bash
    cmake -S . -B ./build
    cmake --build ./build
    ctest --test-dir ./build/tests --verbose
    ```

---

## 📂 Project Structure

```
Snake/
├── Assets/           # Game textures
├── external/         # External libraries (Raylib)
├── source/
│   ├── core/         # Core game logic (Snake, Board, Food)
│   ├── render/       # Rendering code (Raylib)
│   └── app/          # Entry point & game logic
├── tests/            # Unit tests (Catch2)
├── CMakeLists.txt    # Build configuration
└── README.md         # Project documentation
```

## 🤓 Learnings & Highlights

-   🎮 Game patterns (Game Loop, Command)
-   🏗 S.O.L.I.D. principles and decoupled architecture
-   🧠 Smart pointers for memory safety
-   🌱 GitHub branch-based workflow
