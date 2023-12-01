
# EPSS - Enterprise Applications Simulation System

## Introduction

This project aims to simulate an enterprise application system for managing students, their grades, and courses. The system is implemented in C and focuses on inputting and processing student data, course information, and grades. The program allows users to input student and course data, record grades, and generate reports.

## Table of Contents

- [Requirements](#requirements)
- [Usage](#usage)
- [Data Structures](#data-structures)
- [Functions](#functions)
- [Usage Examples](#usage-examples)

## Requirements

To compile and run this program, ensure you have a C compiler installed on your system.

## Usage

1. Clone the repository to your local machine.
2. Compile the program using a C compiler.
3. Run the compiled executable.

## Data Structures

### 1. Student Structure (`ucenik`)

```
typedef struct ucenik {
    int index, brojpredmeta;
    char ime[30], prezime[30];
    struct ucenik *sledeci;
} ucenik;

```
2. Course Structure (predmet)
```
typedef struct predmet {
    int sifra;
    char nazivpredmeta[30];
    int brojstudenata;
    struct predmet *sledeci;
} predmet;
```
3. Grade Submission Structure (prijava)
```
typedef struct prijava {
    int brojindeksa, sifra_pred, ocena;
    struct prijava *sledeci;
} prijava;
```

## Functions

- **dodaj_na_pocetak:** Adds a new element at the beginning of a linked list.
- **dodaj_na_kraj:** Adds a new element at the end of a linked list.
- **unosucenik:** Takes user input for student information and adds it to the student list.
- **unospredmet:** Takes user input for course information and adds it to the course list.
- **unosprijava:** Takes user input for grade submission and adds it to the grade list.
- **proveriimepredmeta:** Checks if a course with the given name exists in the course list.
- **proveriimeucenika:** Checks if a student with the given name and surname exists in the student list.
- **zameni:** Swaps two grade submission elements.
- **sort:** Sorts the course list based on the number of students in descending order.
- **ispis_prijava:** Prints the grade submissions.
