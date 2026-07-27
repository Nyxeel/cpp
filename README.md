<div align="center">

# 🧊 cpp — 42 School C++ Piscine

**Ten modules of progressively harder exercises that walk from plain C-in-C++ up to templates, STL containers, and small full programs — the 42 School C++ curriculum (CPP00–CPP09).**

![Language](https://img.shields.io/badge/language-C%2B%2B-blue?logo=cplusplus&logoColor=white)
![Standard](https://img.shields.io/badge/standard-C%2B%2B98-informational)
![Status](https://img.shields.io/badge/status-finished-brightgreen)

</div>

---

## 📖 About

This repository holds my solutions to the 42 School C++ Piscine. Each `NN_module` folder is one module of the official curriculum, and each `exNN` inside it is one self-contained exercise: its own `Makefile`, its own sources, and its own `main.cpp` (or test file) to exercise the classes it builds.

The modules are ordered on purpose — each one only introduces the C++ features needed to fix what the previous module left artificially restricted (no STL, no exceptions, no templates, ...) until the full language is available by CPP09.

## 📚 Table of Contents

- [Repository Layout](#-repository-layout)
- [Modules](#-modules)
  - [00 — Namespaces, Classes, Member Functions](#00_module--namespaces-classes-member-functions)
  - [01 — Memory Allocation, Pointers, References](#01_module--memory-allocation-pointers-references)
  - [02 — Ad-hoc Polymorphism, Operator Overloading](#02_module--ad-hoc-polymorphism-operator-overloading)
  - [03 — Inheritance](#03_module--inheritance)
  - [04 — Subtype Polymorphism, Abstract Classes, Interfaces](#04_module--subtype-polymorphism-abstract-classes-interfaces)
  - [05 — Repetition and Exceptions](#05_module--repetition-and-exceptions)
  - [06 — C++ Casts](#06_module--c-casts)
  - [07 — Templates](#07_module--templates)
  - [08 — Templated Containers, Iterators, Algorithms](#08_module--templated-containers-iterators-algorithms)
  - [09 — STL Containers & Algorithms](#09_module--stl-containers--algorithms)
- [Build & Run](#-build--run)
- [Requirements](#️-requirements)
- [Author](#️-author)

## 📁 Repository Layout

```
cpp/
├── 00_module/ … 09_module/   one folder per module
│   └── exNN/                 one folder per exercise
│       ├── *.hpp / *.h       class / function declarations
│       ├── *.cpp             implementations
│       ├── main.cpp          driver program demonstrating the exercise
│       └── Makefile           build rules (name/relink/fclean per 42 norm)
├── .gitignore
└── README.md                  this file
```

Every exercise builds independently — there is no shared library between modules, matching how the piscine is meant to be graded (each `exNN` is dropped into its own eval).

## 🧩 Modules

### `00_module` — Namespaces, Classes, Member Functions
First contact with C++ over C: namespaces, classes, member functions, stdio streams, initialization lists, static members, `const`.

| Exercise | What it does |
|---|---|
| `ex00` | `megaphone.cpp` — a namespace-only program that yells whatever is passed on `argv`. |
| `ex01` | `PhoneBook` / `Contact` — a fixed-size (8 entries) address book with add/search/display, first real `class` split into `.hpp`/`.cpp`. |
| `ex02` | `Account` — a bank account class with static class-wide counters (total accounts, total balance) updated from every constructor/method. |

### `01_module` — Memory Allocation, Pointers, References
Stack vs. heap, `new`/`delete`, pointers vs. references, `switch`, and the first taste of composition between classes.

| Exercise | What it does |
|---|---|
| `ex00` | `Zombie` — heap-allocated (`newZombie`) vs. stack-allocated (`randomChump`) zombies, comparing lifetime and ownership. |
| `ex01` | `zombieHorde` — allocates an array of zombies with `new[]` and announces them all. |
| `ex02` | Pointer vs. reference to the same `string`, printing the value and address through both to show they refer to the same object. |
| `ex03` | `HumanA` / `HumanB` / `Weapon` — a weapon held by reference vs. by pointer, illustrating why references can't be reseated. |
| `ex04` | A file-based search & replace tool (`replaceInput.cpp`) reading a file and rewriting every occurrence of a string. |
| `ex05` / `ex06` | `Harl` — a class dispatching to private member functions by log level (`DEBUG`/`INFO`/`WARNING`/`ERROR`) via an array of member function pointers. |

### `02_module` — Ad-hoc Polymorphism, Operator Overloading
The Orthodox Canonical Form (default ctor, copy ctor, copy-assignment, dtor) and operator overloading, built around a fixed-point number type.

| Exercise | What it does |
|---|---|
| `ex00` | `Fixed` — fixed-point number backed by an `int` with a configurable fractional bit count; canonical form only. |
| `ex01` | `Fixed` gains `int`/`float` constructors, `toInt`/`toFloat`, and a raw-value constructor. |
| `ex02` | `Fixed` gains comparison, arithmetic, increment/decrement operators, and `min`/`max` helpers. |
| `ex03_not_finished` | `Point` built on top of `Fixed`, working towards a `BSP` point-in-triangle check (left incomplete). |

### `03_module` — Inheritance
Single and multiple inheritance, constructor/destructor call order, and diamond inheritance.

| Exercise | What it does |
|---|---|
| `ex00` | `ClapTrap` — base combat unit with hit points, energy points, and a damage/attack/repair loop. |
| `ex01` | `ScavTrap` — inherits `ClapTrap` with its own stats and a `guardGate` special ability. |
| `ex02` | `FragTrap` joins `ScavTrap`; both now inherit from `ClapTrap`, each with a distinct attack/HP/EP profile. |
| `ex03` | `DiamondTrap` — inherits from both `ScavTrap` and `FragTrap` (classic diamond), resolving the ambiguous `ClapTrap` base and `attack` via explicit scoping. |

### `04_module` — Subtype Polymorphism, Abstract Classes, Interfaces
Virtual functions, abstract base classes, and interfaces, moving from a "wrong" non-polymorphic hierarchy to a correct one.

| Exercise | What it does |
|---|---|
| `ex00` | `WrongAnimal`/`WrongCat` (no virtual destructor — demonstrates the polymorphism bug) alongside a correct `Animal`/`Cat`/`Dog` hierarchy with virtual `makeSound`. |
| `ex01` | Same hierarchy, deep copy semantics: `Cat`/`Dog` own a `Brain*` that must be cloned (not shared) on copy. |
| `ex02` | `AAnimal` — turns `Animal` into an abstract class (pure virtual `makeSound`), so only concrete `Cat`/`Dog` can be instantiated. |

### `05_module` — Repetition and Exceptions
Custom exception classes, `try`/`catch`, and an administrative hierarchy of bureaucrats approving forms.

| Exercise | What it does |
|---|---|
| `ex00` | `Bureaucrat` — has a grade (1–150) that throws `GradeTooHighException`/`GradeTooLowException` on invalid promotion/demotion. |
| `ex01` | `Form` — requires a minimum grade to be signed, throwing on an ungraded bureaucrat. |
| `ex02` | `AForm` made abstract; three concrete forms (`ShrubberyCreationForm`, `RobotomyRequestForm`, `PresidentialPardonForm`) each override `execute()`. |
| `ex03` | `Intern` — a factory that builds any of the three form types from its name string, without a giant `if`/`else` chain (uses an array of name/creator pairs). |

### `06_module` — C++ Casts
`static_cast`, `dynamic_cast`, `reinterpret_cast`, and safe scalar conversion.

| Exercise | What it does |
|---|---|
| `ex00` | `ScalarConverter` — converts a literal (`char`/`int`/`float`/`double`) to all the others, handling special values (`nan`, `inf`) and out-of-range/impossible conversions. |
| `ex01` | `Serializer` — round-trips a pointer through `reinterpret_cast` to a `uintptr_t` and back, proving the pointer survives the trip unchanged. |
| `ex02` | `Base`/`A`/`B`/`C` — identifies at runtime which derived type a `Base*`/`Base&` actually points/refers to using `dynamic_cast`, for both a random pointer and a reference (via exceptions for the reference case). |

### `07_module` — Templates
Function and class templates, replacing the type-specific code from earlier modules with generic versions.

| Exercise | What it does |
|---|---|
| `ex00` | Template functions `swap`, `min`, `max` (`whatever.hpp`) working over any comparable type. |
| `ex01` | `iter` — applies a function to every element of an array of any type, for both const and non-const arrays. |
| `ex02` | `Array<T>` — a fixed-size, bounds-checked generic array with copy semantics and `[]` access (`.tpp` template-implementation split). |

### `08_module` — Templated Containers, Iterators, Algorithms
Wrapping STL containers and iterators behind generic algorithms, plus a custom container that reuses `std::stack`'s internals.

| Exercise | What it does |
|---|---|
| `ex00` | `easyfind` — a template function returning an iterator to the first occurrence of a value in any STL container that supports `find`. |
| `ex01` | `Span` — collects up to N `int`s and computes the shortest/longest span between any two stored numbers. |
| `ex02` | `MutantStack<T>` — a `std::stack` subclass that additionally exposes iterators, letting a stack be traversed like any other container. |

### `09_module` — STL Containers & Algorithms
Three self-contained programs, each picking the STL container/algorithm best suited to the problem.

| Exercise | What it does |
|---|---|
| `ex00` | `BitcoinExchange` — reads a date/value CSV database (`data.csv`) and an input file, and prints each date's value converted at that day's (or nearest earlier) exchange rate. |
| `ex01` | `RPN` — a reverse Polish notation calculator built on `std::stack`. |
| `ex02` | `PmergeMe` — implements the merge-insertion sort (Ford-Johnson algorithm) on a sequence of positive integers, run over two different containers (e.g. `std::vector` and `std::deque`) to compare timing. |

## 🛠 Build & Run

Every exercise is built independently:

```sh
cd 0X_module/exNN
make
./<binary-name> [args...]
```

## ⚙️ Requirements

- A C++98-compliant compiler (`c++ -Wall -Wextra -Werror -std=c++98`)
- GNU Make

## ✍️ Author

**[@Nyxeel](https://github.com/Nyxeel)**
