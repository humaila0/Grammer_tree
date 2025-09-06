# 🧠 Grammar Parser in C++
My DSA Project

![C++](https://img.shields.io/badge/C++-Grammar--Tree-blue)  

This project builds a basic grammar tree from a user-input sentence using predefined arrays of determiners, adjectives, nouns, verbs, and prepositions. It parses the sentence into subject, verb, and object components, and further breaks down each part into its grammatical elements.

---

## 📌 Project Objective

To demonstrate how a sentence can be structurally parsed using a custom tree-like data structure (`GrammerNode`) in C++. The program identifies and separates:
- Subject phrase (determiner, adjectives, noun)
- Verb
- Object phrase (preposition, determiner, adjective, noun)

---

## 🧪 Input Format

The program expects a sentence with **exactly 9 words**, structured as:

```
Determiner Adjective Adjective Noun Verb Preposition Determiner Adjective Noun
```

Example:
```
the energetic excited dog Adapt above the sad fox
```

---

## 🧰 Data Arrays Used

- **Verbs**: Accept, Achieve, Act, Adapt, jumps, Add, Boil, Borrow, Break  
- **Determiners**: a, theirs, an, this, that, these, whose, ours, the  
- **Adjectives**: Happy, sad, excited, quick, Boring, brown, energetic, lazy, sweet  
- **Nouns**: Movie, fox, Beach, Camera, phone, rain, dog, Dream, sky  
- **Prepositions**: about, above, along, after, over, around, at, against, between

---

## 📁 Code Structure

- `GrammerNode`: A custom class representing nodes in the grammar tree  
- `main()`: Accepts input, parses sentence, builds tree, and prints components  
- Sentence is split into:
  - `subjectLeft[0]`: Full subject phrase
  - `VerbBtw[0]`: Verb
  - `ObjectRight[0]`: Full object phrase
- Each phrase is further broken down into:
  - Determiner
  - Adjective(s)
  - Noun
  - Preposition (for object)

---

## 🖥️ How to Run

1. Compile the code using a C++ compiler:
   ```bash
   g++ -o grammar_parser grammar_parser.cpp
   ```

2. Run the executable:
   ```bash
   ./grammar_parser
   ```

3. Enter a sentence in the required format when prompted.

---

## 📤 Output Example

For input:
```
the energetic excited dog Adapt above the sad fox
```

The output will display:
- Full sentence
- Subject phrase
- Verb
- Object phrase
- Individual grammatical components (determiner, adjectives, noun, etc.)



## 🤝 Contributing

Feel free to fork the repo, suggest improvements, or extend the parser to support more complex sentence structures.

---

Let me know if you'd like to add diagrams, sample outputs, or even convert this into a visual grammar tree using a GUI or web-based frontend.
