# Memorix 📚💡

**Memorix** is a flashcard-based learning app, that I am currently developing just for fun.

---

## Features ✨

- 🧠 **Flashcards**: Create and flashcards with front and back view.
- 🔄 **Card Navigation**: Move between cards.
- 📂 **File Integration**: Load cards from json files for quick setup (other formats will be added later).

---

## Installation 🛠️

1. Clone the repository:

   ```bash
   git clone https://github.com/xirzo/Memorix.git
   ```

2. Build the project using CMake:

   ```bash
   mkdir build && cd build
   cmake ..
   make
   ```

3. Run the application:

   ```bash
   ./Memorix
   ```

---

## Usage 💻

1. Start the app and load your flashcards from a file.
2. Write following commands to the console:
   - `n` ➡️: Move to the next card.
   - `p` ⬅️: Go back to the previous card.
   - `f` 🔄: Flip the card to view the other side.

---

## Example 📝

Assuming you have a `cards.json` file in your working directory, here is a sample interactive session:

```json
[
  {
    "front": "What is the capital of France?",
    "back": "Paris"
  },
  {
    "front": "Which planet is the largest in the Solar System?",
    "back": "Jupiter"
  },
  {
    "front": "Who wrote \"Hamlet\"?",
    "back": "William Shakespeare"
  }
]
```

```bash
$ ./memorix_app
What is the capital of France?
> f
Paris
> n
Which planet is the largest in the Solar System?
> f
Jupiter
> n
Who wrote "Hamlet"?
> f
William Shakespeare
> p
> q
```
