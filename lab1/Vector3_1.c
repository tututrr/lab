#include <stdio.h>
#include <stdlib.h>
#include "dialog.h"




const char *MSGS_1[] = {"****************************", "Hello! This program can do vectoral addition and return scalar vector product", "What type of vectors do you wish to process?", 
"0. Quit", "1. Real", "2. Complex\n", "****************************"};
const int MSGS_1_SIZE = sizeof(MSGS_1) / sizeof(MSGS_1[0]);

const char *MSGS_2[] = {"****************************", "What kind of operation do you want to do?", "1. Vectoral addition", "2. Scalar vector product\n", "****************************"};
const int MSGS_2_SIZE = sizeof(MSGS_2) / sizeof(MSGS_2[0]);


struct Vector3
{
	void* x;
	void* y;
	void* z;
};

typedef struct ComplexNumber
{
    float real;
    float imaginary;
} ComplexNumber;

struct Vector3* CreateVector(void* x_0, void* y_0, void* z_0)
{
    struct Vector3* v3 = (struct Vector3*)malloc(sizeof(struct Vector3));
    v3->x = x_0;
    v3->y = y_0;
    v3->z = z_0;

    return v3;
}

float GetRealX () {
    float x;
    printf("Enter x: ");
    scanf("%f", &x);
    //getchar();
    return x;
}

float GetRealY () {
    float y;
    printf("Enter y: ");
    scanf("%f", &y);
    //getchar();
    return y;
}

float GetRealZ () {
    float z;
    printf("Enter z: ");
    scanf("%f", &z);
    //getchar();
    return z;
}

ComplexNumber GetComplexX () {
    ComplexNumber x;
    printf("Enter real part of x: ");
    scanf("%f", &(x.real));
    getchar();
    printf("Enter imaginary part of x: ");
    scanf("%f", &(x.imaginary));
    getchar();
    return x;
}

ComplexNumber GetComplexY () {
    ComplexNumber y;
    printf("Enter real part of y: ");
    scanf("%f", &(y.real));
    getchar();
    printf("Enter imaginary part of y: ");
    scanf("%f", &(y.imaginary));
    getchar();
    return y;
}

ComplexNumber GetComplexZ () {
    ComplexNumber z;
    printf("Enter real part of z: ");
    scanf("%f", &(z.real));
    getchar();
    printf("Enter imaginary part of z: ");
    scanf("%f", &(z.imaginary));
    getchar();
    return z;
}


void PrintRealVector(struct Vector3 vector)
{
    printf("%f ", *((float *)vector.x));
    printf("%f ", *((float *)vector.y));
    printf("%f ", *((float *)vector.z));
}

void PrintComplexVector(struct Vector3 vector)
{
    ComplexNumber tempx = *(ComplexNumber *) vector.x;
    ComplexNumber tempy = *(ComplexNumber *) vector.y;
    ComplexNumber tempz = *(ComplexNumber *) vector.z;

    printf("%f %fi   ", tempx.real, tempx.imaginary);
    printf("%f %fi   ", tempy.real, tempy.imaginary);
    printf("%f %fi", tempz.real, tempz.imaginary);
}

void AdditionReal(struct Vector3* vector1, struct Vector3* vector2, struct Vector3* vector) {
    *(float*)(vector->x) = *(float*)(vector1->x) + *(float*)(vector2->x);
    *(float*)(vector->y) = *(float*)(vector1->y) + *(float*)(vector2->y);
    *(float*)(vector->z) = *(float*)(vector1->z) + *(float*)(vector2->z);
}

float ScalarReal(struct Vector3* vector1, struct Vector3* vector2) {
    float result;
    result = *(float*)(vector1->x) * *(float*)(vector2->x) + *(float*)(vector1->y) * *(float*)(vector2->y) + *(float*)(vector1->z) * *(float*)(vector2->z);
    return result;
}

void AdditionComplex(struct Vector3* vector1, struct Vector3* vector2, struct Vector3* vector) 
{

    (*(ComplexNumber *)(vector->x)).real = (*(ComplexNumber *) vector1->x).real + (*(ComplexNumber *) vector2->x).real;
    (*(ComplexNumber *)(vector->x)).imaginary = (*(ComplexNumber *) vector1->x).imaginary + (*(ComplexNumber *) vector2->x).imaginary;

    (*(ComplexNumber *)(vector->y)).real = (*(ComplexNumber *) vector1->y).real + (*(ComplexNumber *) vector2->y).real;
    (*(ComplexNumber *)(vector->y)).imaginary = (*(ComplexNumber *) vector1->y).imaginary + (*(ComplexNumber *) vector2->y).imaginary;

    (*(ComplexNumber *)(vector->z)).real = (*(ComplexNumber *) vector1->z).real + (*(ComplexNumber *) vector2->z).real;
    (*(ComplexNumber *)(vector->z)).imaginary = (*(ComplexNumber *) vector1->z).imaginary + (*(ComplexNumber *) vector2->z).imaginary;
    
}

ComplexNumber ScalarComplex(struct Vector3* vector1, struct Vector3* vector2)
{
    ComplexNumber result;
    float a; //z = a + bi
    float b;
    //(a1 + b1i)(a2 + b2i)
    a = ((*(ComplexNumber *) vector1->x).real)*((*(ComplexNumber *) vector2->x).real) + ((*(ComplexNumber *) vector1->y).real)*((*(ComplexNumber *) vector2->y).real) + ((*(ComplexNumber *) vector1->z).real)*((*(ComplexNumber *) vector2->z).real);
    a += (-1) * (((*(ComplexNumber *) vector1->x).imaginary) * ((*(ComplexNumber *) vector2->x).imaginary) + ((*(ComplexNumber *) vector1->y).imaginary)*((*(ComplexNumber *) vector2->y).imaginary) + ((*(ComplexNumber *) vector1->z).imaginary)*((*(ComplexNumber *) vector2->z).imaginary));
    b = ((*(ComplexNumber *) vector1->x).real)*((*(ComplexNumber *) vector2->x).imaginary) + ((*(ComplexNumber *) vector1->y).real)*((*(ComplexNumber *) vector2->y).imaginary) + ((*(ComplexNumber *) vector1->z).real)*((*(ComplexNumber *) vector2->z).imaginary);
    b += ((*(ComplexNumber *) vector1->x).imaginary)*((*(ComplexNumber *) vector2->x).real) + ((*(ComplexNumber *) vector1->y).imaginary)*((*(ComplexNumber *) vector2->y).real) + ((*(ComplexNumber *) vector1->z).imaginary)*((*(ComplexNumber *) vector2->z).real);
    result.real = a;
    result.imaginary = b;

    return result;

}


void menu(struct Vector3* vp1, struct Vector3* vp2, struct Vector3* vp)
{
    int type;
    int operation;
    do {
        type = dialog(MSGS_1, MSGS_1_SIZE);

        switch(type) {
        case 0:
            break;
        case 1:
            operation = dialog(MSGS_2, MSGS_2_SIZE);
            switch(operation) {
                case 1:
                    printf("Enter first vector \n");
                    float x_1 = GetRealX();
                    float y_1 = GetRealY();
                    float z_1 = GetRealZ();
                    vp1 = CreateVector(&x_1, &y_1, &z_1);

                    printf("Enter second vector \n");
                    float x_2 = GetRealX();
                    float y_2 = GetRealY();
                    float z_2 = GetRealZ();
                    vp2 = CreateVector(&x_2, &y_2, &z_2);

                    float tempx;
                    float tempy;
                    float tempz;
                    vp = CreateVector(&tempx, &tempy, &tempz);
                    AdditionReal(vp1, vp2, vp);

                    PrintRealVector(*vp); 

                    break;

                case 2:
                    printf("Enter first vector \n");
                    float x1 = GetRealX();
                    float y1 = GetRealY();
                    float z1 = GetRealZ();
                    vp1 = CreateVector(&x1, &y1, &z1);

                    printf("Enter second vector \n");
                    float x2 = GetRealX();
                    float y2 = GetRealY();
                    float z2 = GetRealZ();
                    vp2 = CreateVector(&x2, &y2, &z2);

                    float ans = ScalarReal(vp1, vp2);
                    printf("%f", ans);

                    break;
            }
            break;
        case 2:
            operation = dialog(MSGS_2, MSGS_2_SIZE);
            switch(operation) {
                case 1:
                printf("Enter first vector \n");
                ComplexNumber x_1 = GetComplexX();
                ComplexNumber y_1 = GetComplexY();
                ComplexNumber z_1 = GetComplexZ();
                vp1 = CreateVector(&x_1, &y_1, &z_1);

                printf("Enter second vector \n");
                ComplexNumber x_2 = GetComplexX();
                ComplexNumber y_2 = GetComplexY();
                ComplexNumber z_2 = GetComplexZ();
                vp2 = CreateVector(&x_2, &y_2, &z_2);

                ComplexNumber tempx;
                ComplexNumber tempy;
                ComplexNumber tempz;
                vp = CreateVector(&tempx, &tempy, &tempz);
                AdditionComplex(vp1, vp2, vp);

                PrintComplexVector(*vp);

                break;

                case 2:
                printf("Enter first vector \n");
                ComplexNumber x1 = GetComplexX();
                ComplexNumber y1 = GetComplexY();
                ComplexNumber z1 = GetComplexZ();
                vp1 = CreateVector(&x1, &y1, &z1);

                printf("Enter second vector \n");
                ComplexNumber x2 = GetComplexX();
                ComplexNumber y2 = GetComplexY();
                ComplexNumber z2 = GetComplexZ();
                vp2 = CreateVector(&x2, &y2, &z2);

                ComplexNumber ans = ScalarComplex(vp1, vp2);
                printf("%f %fi", ans.real, ans.imaginary);

                break;
            }

            break;
        }

    } while (type != 0);
}


int main()
{   
    struct Vector3* vp1;
    struct Vector3* vp2;
    struct Vector3* vp; //result vector

    menu(vp1, vp2, vp);

    return 0;
}

