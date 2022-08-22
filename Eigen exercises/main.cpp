#include "bmi_lib.h"
#include <iostream>
#include <eigen3/Eigen/Dense>
#include <cmath>

/* Función que recibe cuatro matrices (a,b,c,x) y una variable numérica de trampa
 * Es un impresor de mensajes generalizado para imprimir las matrices de entrada
 * y el resultado */

void introductor(Eigen::MatrixXd a, Eigen::MatrixXd b, Eigen::MatrixXd x,Eigen::MatrixXd c, int chequeo){

    std::cout<<"Dado a: \n"<<a<<std::endl;
    std::cout<<"\n Dado b: \n"<<b<<std::endl;
    if (chequeo !=0){
        std::cout<<"\n Dado c: \n"<<c<<std::endl;
    }
    std::cout<<"La matriz resultante es: "<<std::endl;
    std::cout<<"\n"<<x<<std::endl;
}

/* Se crean tres matrices y se inicializan */

void punto_a(){ //good
    /* Se requiere satisfacer x = 3a - 4B */
    Eigen::Matrix2d a;
    Eigen::Matrix2d b;
    Eigen::Matrix2d x;
    a << 4,-2,1,-7;
    b << -1,2,6,-5;

    /* Se usa element wise para realizar
    operaciones matriciales con escalares */

    x = (3 * a.array()) - (4*b.array());

    std::cout<<"Se requiere satisfacer x = 3a - 4b"<<std::endl;
    introductor(a,b,x,a,0);
}

void punto_b(){ //good
    /* Se requiere satisfacer 2x + 4a = 3ba
       a y b son matrices conocidas.
       Despejando x queda:
       x = (3ba - 4a) / 2   */
    Eigen::Matrix2d a;
    Eigen::Matrix2d b;
    Eigen::Matrix2d x;
    a << 0,-1,
         2,1;
    b << 1,2,
         3,4;
    /* Se usa element wise para realizar
    operaciones matriciales con escalares */
    x = (((b*a).array()*3) - (a.array()*4))/2;

    std::cout<<"Se requiere satisfacer x = (3ba - 4a) / 2"<<std::endl;
    introductor(a,b,x,a,0);


}

void punto_c(){ //good

    Eigen::Matrix2d a;
    Eigen::Matrix2d b;
    Eigen::Matrix2d c;
    Eigen::Matrix2d x;

    /* AXB^T = C
     * X = C / (AB^T)
    */

    a << -3,-2,
         3, 3;
    b << 5,3,
         9,4;
    c << 1,1,
         0,0;
    /* Para invertir filas y columnas se usa la función transpose()
     * Para dividir una matriz por otra, se invierte la matriz denominador  */
    x = c*(a*b.transpose()).inverse();
    std::cout<<"Se requiere satisfacer x = c / ab^T"<<std::endl;
    introductor(a,b,x,c,1);

}

void punto_d(){ //good
    Eigen::Matrix2d a;
    Eigen::Matrix2d b;
    Eigen::Matrix2d x;

    a << 2,1,
         -4,-3;
    b << 2,2,
         6,4;
    //x = b.array()/ a.array();
    /* Para dividir una matriz por otra, se invierte la matriz denominador
     * Se pueden operar matrices directamente, sin hay necesidad de element wise. */
    x = b*a.inverse();
    std::cout<<"Se requiere satisfacer x = a / b"<<std::endl;
    introductor(a,b,x,a,0);
}

void punto_e(){ //good
    // x = 2(ab+c)
    /* Cuando la matriz resultado (x) tiene dimensión desconocida, es mejor
     * definir una matriz dinámica */

    typedef Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> MiMatrizd;
    //Cada una de estas matrices son de dimensiones nxm
    MiMatrizd a(2,3);
    MiMatrizd b(3,2);
    MiMatrizd c(2,2);
    MiMatrizd x;

    a << 3,0,-1,
         0,2,1;
    b << 1,2,
         1,0,
         0,6;
    c << -2,0,
         -2,-5;
    /* Primero se operan las matrices entre ellas. El .array() toma
     * elemento a elemento para operarlo con el escalar.
     * Note el orden jerárquico (o precedencia).
     * Primero se opera lo que hay dentro del paréntesis.
     * La condición que permite multiplicar matrices no cuadradas
     * establece que el tamaño de la fila y columna entre ambas debe ser
     * el mismo. Lo cual permite finalmente, la suma con c.
     * El resultado matricial es operado elemento a elemento con el escalar */
    x = 2*((a*b)+c).array();
    std::cout<<"Se requiere satisfacer x = 2(ab+c) "<<std::endl;
    introductor(a,b,x,c,1);
}

void punto_f(){ //good
    Eigen::Matrix3d a;
    Eigen::Matrix3d b;
    Eigen::Matrix3d x;
    //Eigen::Map<Matrix<double,3,3,

    //x = A+3B

    a << 1,5,-1,
         -1,2,2,
         0,-3,3;
    b << -1,-4,3,
         1,-2,-2,
         -3,3,-5;

    x = a.array()+(3*b.array());
    std::cout<<"Se requiere satisfacer x = a+3b "<<std::endl;
    introductor(a,b,x,a,0);
}

void punto_g(){ //good

    Eigen::Matrix3d a;
    Eigen::Matrix3d b;
    Eigen::Matrix3d x;
    //x = b/a

    a << 2,7,3,
         3,9,4,
         1,5,3;
    b << 1,0,2,
         0,1,0,
         0,0,1;
    //x = b.array()/a.array();
    std::cout<<"Se requiere satisfacer x = b / a "<<std::endl;
    /* Multiplicar una matriz a por una matriz inversa b, es equivalente
     * a dividir a entre b */
    x = b*a.inverse();
    introductor(a,b,x,a,0);
}

void punto_h(){ //good
    // x = B/A
    Eigen::Matrix3d a;
    Eigen::Matrix3d b;
    Eigen::Matrix3d x;

    a << 1,1,1,
         6,5,4,
         13,10,8;
    b << 0,1,2,
         1,0,2,
         1,2,0;
    /* Operación directa entre matrices */
    x = a.inverse()*b;
    std::cout<<"Se requiere satisfacer x = b / a "<<std::endl;
    introductor(a,b,x,a,0);
}

void punto_i(){ //good
    Eigen::Matrix2d a;

    a << 3,-1,
         0,2;
    a = (a.transpose()*a).array() - (a.array()*2);
    std::cout<<"Se requiere satisfacer x = aa^T - 2ab "<<std::endl;
    std::cout<<"Caso especial donde sólo se usa a"<<std::endl;
    std::cout<<"La matriz solución es \n"<<std::endl;
    std::cout<<a<<std::endl;
}

void punto_j(){
    // x = a**3
    Eigen::Matrix2d a;

    a << 4,2,
        -1,0;

    std::cout<<"Se requiere satisfacer x = a³ "<<std::endl;
    std::cout<<"La matriz solución es \n"<<std::endl;
    /* Eigen tiene una biblioteca conocida como <unsupported/Eigen/MatrixFunctions>
     * la cual permite el uso explícito de funciones matemáticas. En este caso se usó
     * Dense que no incluye estas funciones, por lo cual, se implementó la potencia
     * cúbica como tres veces el producto de a */
    std::cout<<a*a*a<<std::endl;

}

void punto_k(){ //good

    // c / A^t * B
    Eigen::Matrix2d a;
    Eigen::Matrix2d b;
    Eigen::Matrix2d c;
    Eigen::Matrix2d x;

    a << 2,4,
         3,2;
    b << 1,0,
         2,1;
    c << 7,5,
         6,1;
    x = c*(a.transpose()*b).inverse();
    std::cout<<"Se requiere satisfacer x = c / a^t * b "<<std::endl;
    introductor(a,b,x,c,1);
}

void punto_l(){ //good
    // x = aa^t - 2ab,
    typedef Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> MiMatrizd;
    MiMatrizd a(2,3);
    MiMatrizd b(3,2);
    MiMatrizd x;

    a << 1,0,-2,
         2,-1,3;
    b << 2,-3,
         -2,0,
         -1,-2;
    x = (a*a.transpose()).array() - ((a*b).array()*2);
    std::cout<<"Se requiere satisfacer x = aa^t - 2ab "<<std::endl;
    introductor(a,b,x,a,0);

}

void punto_m(){
    // x = abc
    Eigen::VectorXd a(3);
    Eigen::MatrixXd b(3,2);
    Eigen::MatrixXd c(2,1);
    Eigen::MatrixXd x;

    a << 4,8,12;
    b << 3,2,
         0,1,
         -1,0;
    c << 3,-1;

    /* Para multiplicar un vector por una matriz, este debe
     * multiplicar cada valor del vector columna de la matriz.
     * Esto lo garantiza .array() (dato por dato) para cada columna (colwise)
     * La función .sum() permite simplificar la matriz haciendo la sumatoria
     * de estos elementos para cada columna (por eso se integró con colwise) */

    x = b.array().colwise()*a.array(); //multiplicar matrix por vector
    //x.colwise().sum(); //simplify los resultados para cada columna
    std::cout<<"Se requiere satisfacer x = abc "<<std::endl;
    std::cout<<"La matriz resultante es"<<std::endl;
    std::cout<<(x.colwise().sum())*c<<std::endl;
}

void punto_n(){ //nope
    Eigen::Matrix3d a;
    Eigen::Matrix3d b;
    Eigen::Matrix3d x;

    a << 3,4,1,
         -1,-3,3,
         2,3,0;
    b << 3,9,7,
         1,11,7,
         7,5,7;
    x = b*a.transpose().inverse();
    std::cout<<a.transpose().determinant()<<std::endl;
    std::cout<<x.real()<<std::endl;
    //como el determinante es 0, a no tiene inversa puesto que es singular
}

void punto_o(){ //good
    Eigen::Matrix3d a;
    Eigen::Matrix3d b;
    Eigen::Matrix3d x;

    a << 2,5,7,
         6,3,4,
         5,-2,-3;
    b << -1,1,0,
          0,1,1,
          1,0,-1;

    x = b*a.inverse();
    std::cout<<"Se requiere satisfacer x = b / a "<<std::endl;
    introductor(a,b,x,a,0);
}

void punto_p(){ //good
    Eigen::Matrix4d a;
    Eigen::Matrix4d b;
    Eigen::Matrix4d x;

    a << 1,1,1,1,
         1,1,-1,-1,
         1,-1,1,-1,
         1,-1,-1,1;
    b << 1,1,0,0,
         1,0,1,0,
         1,0,0,1,
         1,0,1,1;
    x = b*a.inverse();
    std::cout<<"Se requiere satisfacer x = b / a "<<std::endl;
    introductor(a,b,x,a,0);
}

/* Función que contextualiza al usuario acerca del programa y le
 * indica un curso de acciones a seguir */
void menu(){
    int numero = 0;
    do {


    std::cout<<"************************************************************"<<std::endl;
    std::cout<<"    Solución de matrices usando Eigen   "<<std::endl;
    std::cout<<"    Ingrese un número para ver la solución del ejercicio         "<<std::endl;
    std::cout<<"************************************************************"<<std::endl;
    std::cout<<"    Recuerde que hay un total de 15 ejercicios (1-15)   "<<std::endl;
    std::cout<<"    Puede ver Colquida en Github para ver más información"<<std::endl;
    std::cout<<"************************************************************"<<std::endl;
    std::cin>>numero;
    std::cout<<"************************************************************"<<std::endl;
    std::cout<<"    Si ha terminado, escriba 99 para salir"<<std::endl;
    std::cout<<"************************************************************"<<std::endl;
    switch (numero) {
    case 1:
        punto_a();
        break;
    case 2:
        punto_b();
        break;
    case 3:
        punto_c();
        break;
    case 4:
        punto_d();
        break;
    case 5:
        punto_e();
        break;
    case 6:
        punto_f();
        break;
    case 7:
        punto_g();
        break;
    case 8:
        punto_h();
        break;
    case 9:
        punto_i();
        break;
    case 10:
        punto_j();
        break;
    case 11:
        punto_k();
        break;
    case 12:
        punto_l();
        break;
    case 13:
        punto_m();
        break;
    case 14:
        punto_o();
        break;
    case 15:
        punto_p();
        break;
    default:
        break;
    }
    std::cout<<"************************************************************"<<std::endl;
    } while (numero!=99);
}
