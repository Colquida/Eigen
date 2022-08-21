#include <iostream>
#include <eigen3/Eigen/Dense>
#include <cmath>
void punto_a(){ //good
    /* Se requiere satisfacer x = 3a - 4B */
    Eigen::Matrix2d a;
    Eigen::Matrix2d b;
    Eigen::Matrix2d x;
    a << 4,-2,1,-7;
    b << -1,2,6,-5;

    x = (3 * a.array()) - (4*b.array());

    std::cout<<"\n"<<x<<std::endl;
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

    x = (((b*a).array()*3) - (a.array()*4))/2;
    std::cout<<x<<std::endl;

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

    x = c*(a*b.transpose()).inverse();
    std::cout<<x<<std::endl;

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
    x = b*a.inverse();
    std::cout<<x<<std::endl;
}

void punto_e(){ //good
    // x = 2(ab+c)
    typedef Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> MiMatrizd;
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
    x = 2*((a*b)+c).array();
    std::cout<<x<<std::endl;
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
    std::cout<<x<<std::endl;
}

void punto_g(){ //good

    Eigen::Matrix3d a;
    Eigen::Matrix3d b;
    Eigen::Matrix3d x;
    //Eigen::Map<Matrix<double,3,3,

    //x = b/a

    a << 2,7,3,
         3,9,4,
         1,5,3;
    b << 1,0,2,
         0,1,0,
         0,0,1;
    //x = b.array()/a.array();
    x = b*a.inverse();
    std::cout<<x<<std::endl;
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
    x = a.inverse()*b;
    std::cout<<x<<std::endl;
}

void punto_i(){ //good
    Eigen::Matrix2d a;

    a << 3,-1,
         0,2;
    a = (a.transpose()*a).array() - (a.array()*2);
    std::cout<<a<<std::endl;
}

void punto_j(){
    // x = a**3
    Eigen::Matrix2d a;

    a << 4,2,
        -1,0;
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
    std::cout<<x<<std::endl;
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
    std::cout<<x<<std::endl;
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

    //x = b*c;
    x = b.array().colwise()*a.array(); //multiplicar matrix by vector
    //x.colwise().sum(); //simplify the results

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
    std::cout<<x<<std::endl;
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
    std::cout<<x<<std::endl;
}
int main()
{

    punto_p();
    return 0;
}
