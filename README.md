# SANJAC
### Enterprise Applications Simulation System Introduction

This project aims to simulate an enterprise application system for managing students, their grades, and courses. The system is implemented in C and focuses on inputting and processing student data, course information, and grades. The program allows users to input student and course data, record grades, and generate reports.
Table of Contents

    Requirements
    Usage
    Data Structures
    Functions
    Usage Examples

Requirements

To compile and run this program, ensure you have a C compiler installed on your system.
Usage

    Clone the repository to your local machine.
    Compile the program using a C compiler.
    Run the compiled executable.

Data Structures
1. Student Structure (ucenik)

c

typedef struct ucenik {
    int index, brojpredmeta;
    char ime[30], prezime[30];
    struct ucenik *sledeci;
} ucenik;

2. Course Structure (predmet)

c

typedef struct predmet {
    int sifra;
    char nazivpredmeta[30];
    int brojstudenata;
    struct predmet *sledeci;
} predmet;

3. Grade Submission Structure (prijava)

c

typedef struct prijava {
    int brojindeksa, sifra_pred, ocena;
    struct prijava *sledeci;
} prijava;

Functions

    dodaj_na_pocetak: Adds a new element at the beginning of a linked list.
    dodaj_na_kraj: Adds a new element at the end of a linked list.
    unosucenik: Takes user input for student information and adds it to the student list.
    unospredmet: Takes user input for course information and adds it to the course list.
    unosprijava: Takes user input for grade submission and adds it to the grade list.
    proveriimepredmeta: Checks if a course with the given name exists in the course list.
    proveriimeucenika: Checks if a student with the given name and surname exists in the student list.
    zameni: Swaps two grade submission elements.
    sort: Sorts the course list based on the number of students in descending order.
    ispis_prijava: Prints the grade submissions.

Usage Examples
Adding Students

c

int bru;
printf("Enter the number of students (0 to exit): ");
scanf("%d", &bru);
glavaucenik = unosucenik(bru, glavaucenik);

Adding Courses

c

int brp;
printf("Enter the number of courses (0 to exit): ");
scanf("%d", &brp);
glavapredmet = unospredmet(brp, glavapredmet);

Grade Submission

printf("Enter new grade:\n");
printf("\tEnter student's name: ");
scanf("%s", imestudenta);
printf("\tEnter student's last name: ");
scanf("%s", prezime);
printf("\tEnter grade: ");
scanf("%d", &ocena);
printf("\tEnter course name: ");
scanf("%s", ppredmet);

ucenik *tmp_u = proveriimeucenika(imestudenta, prezime, glavaucenik);
predmet *tmp_p = proveriimepredmeta(ppredmet, glavapredmet);

if (ocena < 11 && ocena > 4 && tmp_p != NULL && tmp_u != NULL)
    glava = unosprijava(glava, ocena, tmp_p, tmp_u);
else
    printf("Error\n");

Generating Reports 

c

printf("Generate report\n");
glavapredmet = sort(glavapredmet);

Feel free to modify and extend the code to suit your specific requirements.
