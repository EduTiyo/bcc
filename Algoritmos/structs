#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

    struct contact {
        int id;
        char name[51];
        char email[51];
        int type;
    };
    typedef struct contact Contact;


    struct point {

        float x;
        float y;
    };
    typedef struct point Point;

    struct employee {
        char name[50];
        float salary;
        int type; // 0 - developer, 1 - designer, 2 - manager, 3 - support
    };
    typedef struct employee Employee;

// 1. Escreva uma função que recebe dois pontos x,y (Point) e devolve a distância entre os mesmos.

float distance2D(Point p1, Point p2){

   float d = sqrt(pow((p2.x - p1.x), 2) + pow((p2.y - p1.y), 2));
   return d;

}

// 2. Considerando a estrutura Point do exercício anterior, escreva uma função que recebe um vetor de
// pontos, bem como seu tamanho, e informa a distância a cada dois pontos consecutivos do vetor.

void distance_vector(int n, Point v[]){

    for (int i = 0; i < n-1; i++){

        float d = distance2D(v[i], v[i+1]);
        printf("%.2f\n", d);
    }
}

// 3. Escreva uma função que recebe um vetor de Point e os inicia com valores float aleatórios -50 e 50.

void random_points(int n, Point v[]){

    for (int i = 0; i < n; i++)
    {
        v[i].x = (rand()/(float) RAND_MAX) * 100 - 100/2.0f;
        v[i].y = (rand()/(float) RAND_MAX) * 100 - 100/2.0f;
        printf("points[%d].x = %f\n", i, v[i].x);
        printf("points[%d].y = %f\n\n", i, v[i].y);
    }
    printf("\n");
    
}

// 4. Escreva uma função que recebe um vetor de Point e encontra os dois pontos mais próximos, isto é,
// aqueles que possuem a menor distância. A função deve imprimir os dois de pontos mais próximos -
// (X1,Y1) e (X2,Y2) -, além da distância. Obviamente, você não deve considerar a distância de um
// ponto a ele mesmo, que será sempre zero.

float nearest_points(int n, Point v[]){

    float distance;/* code */
    float nearPoint = distance2D(v[0], v[1]);
    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < n-1; j++)
        {
            if (i==j)
                continue;
            distance = distance2D(v[i], v[i+1]);
            if (distance < nearPoint)
                nearPoint = distance;
        }
        
    }
    return nearPoint;
}

// 5. Escreva uma função que recebe um Contact (ver struct abaixo) e imprime seu conteúdo. A função
// também recebe um vetor de strings contendo os nomes dos tipos, chamado type_names. O
// campo type do contato deve ser utilizado como índice no vetor type_names.

void print_contact(Contact c, int size, char types[size][50]){

    printf(" Id: %d\n Name: %s\n Email: %s\n Type: %s\n", c.id, c.name, c.email, types[c.type]);
}

// 6. Escreva uma função que recebe um vetor de Contact e imprime os contatos agrupados pelo seu tipo

void print_contact_list(int contactsSize, Contact list[contactsSize], int typesize, char types[typesize][50]){
    
    for (int i = 0; i < typesize; i++)
    {
        int hasContacts = 0;
        for (int j = 0; j < contactsSize; j++)
        {
            if(list[j].type == i){
                hasContacts = 1;
                break;
            }
        }


        if (hasContacts == 1) printf("%s:\n", types[i]);

        for (int j = 0; j < contactsSize; j++)
        {
            if (list[j].type == i){
                printf("  %s\n", list[j].name);
            }
        }
        
        
    }
    
}

// 7. Escreva uma função que recebe uma lista de empregados (Employee) e seu tamanho. A função
// deve calcular e imprimir: o total dos salários, a média dos salários e as médias dos salários por tipo
// de empregado (“Developer”, “Designer”, “Manager” ou “Support”).

void employees_report(int n, Employee v[n]){

    float TotalSalary = 0;
    float salaryByType[4] = {0};
    float employeesByType[4] = {0};

    for (int i = 0; i < n; i++)
    {
        TotalSalary += v[i].salary;
        salaryByType[v[i].type] += v[i].salary;
        employeesByType[v[i].type] += 1;       
    }

    printf("Total Salary: %.2f\n", TotalSalary);
    printf("Average Salary: %.2f\n", TotalSalary/n);
    printf("Average Salary Dev: %.2f\n", salaryByType[0] / employeesByType[0]);
    printf("Average Salary Designer: %.2f\n", salaryByType[1] / employeesByType[1]);
    printf("Average Salary Manager: %.2f\n", salaryByType[2] / employeesByType[2]);
    printf("Average Salary Support: %.2f\n", salaryByType[3] / employeesByType[3]);
}

// 8. Escreva uma função que recebe um vetor de empregados (Employee) e seu tamanho. A função
// deve imprimir os nomes dos três empregados de maiores salários, ou seja, as pessoas que
// recebem os três maiores salários

void printBest3(int n, Employee v[n]){

    float max[3] = {0};
    char name1[50] = {"null"};
    char name2[50] = {"null"};
    char name3[50] = {"null"};

    for (int i = 0; i < n; i++)
    {
        if (v[i].salary > max[0]){
            max[0] = v[i].salary;
            strcpy(name1, v[i].name);

        }
    }


    for (int i = 0; i < n; i++)
    {
        if (v[i].salary > max[1] && v[i].salary < max[0]){
            max[1] = v[i].salary;
            strcpy(name2, v[i].name);

        }
    }

    for (int i = 0; i < n; i++)
    {
        if (v[i].salary > max[2] && v[i].salary < max[1]){
            max[2] = v[i].salary;
            strcpy(name3, v[i].name);
        }


    }

    printf("Maior salario: %s - %.2f\n", name1, max[0]);
    printf("Segundo maior salario: %s - %.2f\n", name2, max[1]);
    printf("Segundo maior salario: %s - %.2f\n", name3, max[2]);   
}

// 9. Escreva uma função que recebe um nome, o verifica e corrige, se necessário. Um nome deve
// conter apenas letras, com as iniciais de cada nome em maiúscula e o restante em minúsculas.
// Deve haver somente um espaço entre cada nome e não devem haver espaços no início e final.


void fix_name (char name[]){

    int namesQuantity = 0;
    int word = 0;
    int hasSpace = 0;

    for (int i = 0; name[i] != 0; i++)
    {
        if ((name[i] < 65 || name[i] > 90) && (name[i] < 97 || name[i] > 122)){
            name[i] = 32;
        }
    }

    for (int i = 0; name[i] != 0; i++)
    {
        if (word == 0 && name[i]!=32){
            word=1;
            if (name[i] > 64 && name[i] < 91){
                continue;
            }
            if (name[i] > 96 && name[i] < 123) name[i]-=32;
                continue;
        }
        
        if (word == 1 && name[i] > 64 && name[i] < 91) name[i]+=32;
        
        if (name[i]==32) word=0;
    }

    int j = 0;

    char name2[50] = {0};

    word = 0;
    for (int k = 0; name[k]!=0; k++)
    {
        if (name[k]!=32) word = 1;
        if (name[k]!=32 && word == 1) name2[j] = name[k], j++;
        if(name[k]==32 && word == 1) word = 0, name2[j]=32, j++;
    }
    name[j]=0;
    
    
    
    

    


    
    printf("\n%s\n\n", name2);
}


// 10. Escreva uma função que preenche e devolve um Contact (struct do exercício 5), definindo os
// campos da seguinte forma:
    // a. id: definido pelo parâmetro id;
    // b. name: definido pelo parâmetro name. Deve ser verificado e corrigido, se necessário. Para
    // tanto, utilize a função do exercício anterior.
    // c. email: deve ser gerado com base no nome e respeitando as seguintes características
        // i. Todas as letras minúsculas;
        // ii. Espaço deve ser substituído por “.” (ponto);
        // iii. Acrescentar o sufixo “@mail.br”.
    // d. type: definido pelo parâmetro type.

void createContact(int id, char name[], int type){

    
}


int main(){

    // /* ex 1 */

    // Point p1 = {1, 1};
    // Point p2 = {5, 4};
    // float dist = distance2D(p1,p2);
    // printf("%.2f \n", dist);(int k = 0; k < namesQuantity; k++)
    // {
        
    // }

    /* ex 2 */

    // Point pontos[] = { {1.0, 2.0}, {4.0, 6.0}, {7.0, 9.0}, {3.0, 1.0} };
    // distance_vector(4, pontos);

    /* ex 3 */

    // Point v[4] = {0};
    // random_points(4, v);
    
    /* ex 4 */

    // Point v[] = { {1.0, 2.0}, {4.0, 6.0}, {7.0, 9.0}, {3.0, 1.0} };
    // float distance = nearest_points(4, v);
    // printf("menor distancia: %f\n", distance);

    /* ex 5 */
    // char types[][50] = {"familia", "amigo", "trabalho", "escola", "outros"};
    // Contact c = {1, "Tico", "tiyo@utfpr.alunos.edu.br", 1};
    // print_contact(c, 5, types);

    /* ex 6 */

    // char types[][50] = {"Família","Amigo","Trabalho","Escola","Outros"};
    // Contact list[] = {
    //     {1, "Marcus Fenix", "fenix@gow.com", 2},
    //     {41, "Blue Mary", "mary@ff3snk.net", 0},
    //     {17, "Barry Burton", "bburton@re.cap", 0},
    //     {8, "Charlie Nash", "nash@ssz.com", 2},
    //     {2, "Ada Wong", "wong@re2.net", 4},
    //     {5, "Chris Redfield", "crfield@re.cap", 0}
    //     };
    // print_contact_list(6, list, 5, types);

    /* ex 7 */

    // char types[][50] = {"developer", "designer", "manager", "support"};
    // Employee v[] = {
    //     {"Alice", 50000.0, 0}, // Developer
    //     {"Bob", 60000.0, 0},   // Developer
    //     {"Charlie", 45000.0, 1}, // Designer
    //     {"David", 75000.0, 2},  // Manager
    //     {"Eve", 40000.0, 3}     // Support
    // };
    // employees_report(5, v);

    /* ex 8 */

    // Employee v[] = {
    //     {"Alice", 50000.0, 0}, // Developer
    //     {"Bob", 60000.0, 0},   // Developer
    //     {"Charlie", 45000.0, 1}, // Designer
    //     {"David", 75000.0, 2},  // Manager
    //     {"Eve", 40000.0, 3}     // Support
    // };
    // printBest3(5, v);

    /* ex 9 */

    char name[] = "eduardo";
    fix_name(name);


    
    return 0;
}
