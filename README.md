![image](https://user-images.githubusercontent.com/83324055/186306221-eb5af8a8-ed46-491b-9c15-8ee380cbf750.png)


# Taller de ejercicios usando Eigen

El presente repositorio contiene la implementación de los ejercicios propuestos de operaciones entre matrices utilizando la biblioteca Eigen a través del lenguaje de programación C++. 

## Descripción

Basado en los ejercicios propuestos en el siguiente enlace:

https://www.math-exercises.com/matrices/matrix-equations

Se requiere la realización de 15 de estos ejercicios, los cuales son de elección propia. Para este repositorio en particular, se eligió todos los presentes a excepción del ejercicio n.

En el código podrá encontrar algunos ficheros. 

* CMakeLists.txt (Archivo de ficheros pertenecientes al proyecto)
* eigen_lib.h (Biblioteca local)
* eigen_project.cpp (Contiene el disparador del programa)
* main.cpp (lógica del programa (funciones, implementación, etc.))

## Comienzo

### Dependencias

* Fedora 36 (Distribución utilizada).
* QT Creator (IDE)
* C++ (Lenguaje utilizado)
* Eigen3/Eigen/Dense (Biblioteca de operaciones matriciales) 

### Instalaciones

Tanto si se usa el IDE Qt Creator como si emplea únicamente la terminal, es requerido realizar la instalación previa de la biblioteca Eigen. A continuación, se describe el proceso, paso a paso. 

* Instalación de EIGEN

Primero, deberá abrir una terminal en su estación de trabajo y escribir lo siguiente: 

```
sudo apt install libeigen3-dev
```

* Instalación de Eigen para Fedora, CentOS o Redhat

```
su -c "yum install eigen3-devel"
```

Independientemente del tipo de distribución que esté usando, debe asegurarse de que las dependencias de su entorno estén actualizadas. Esto se realiza a través de:

```
sudo apt update
```
Seguidamente, es meritorio crear el enlace simbólico de la biblioteca Eigen, de tal manera que se pueda acceder de manera más fácil a estos recursos:

```
ln -sf  /usr/include/eigen3/Eigen Eigen
ln -sf  /usr/include/eigen3/unsupported unsupported
```

Nuevamente, actualice las dependencias de su sistema:

```
sudo apt update
```

### Utilización del repositorio 

* Terminal 

Si no dispone del IDE Qt Creator, puede clonar directamente este repositorio copiando el siguiente enlace: 

```
https://github.com/Colquida/Vectores_Matrices_Eigen.git
```
No necesitará autenticarse como usuario de Github ya que el presente repositorio es público, así que en su terminal deberá ejecutar:

```
git clone https://github.com/Colquida/Vectores_Matrices_Eigen.git
```

Si no dispone de Git, deberá descargarlo:

```
sudo apt install git
```

Ahora podrá manipular y/o ejecutar los archivos presentes en este repositorio. 

* Qt creator

Para usar este repositorio en Qt creator, deberá crear un nuevo proyecto y marcar la opción de importar proyecto. 

file:///home/Nevt/Pictures/Screenshots/Screenshot%20from%202022-08-23%2022-29-03.png![image](https://user-images.githubusercontent.com/83324055/186322292-216bfbba-a59c-49db-a9c6-f0fd93e18eb3.png)

Una vez realizado, deberá seleccionar la opción git clone, tras lo cual se le proporcionará una interfaz como esta:

file:///home/Nevt/Pictures/Screenshots/Screenshot%20from%202022-08-23%2022-36-04.png![image](https://user-images.githubusercontent.com/83324055/186323204-ae4adf30-fbff-4927-ba2f-3a461e66e950.png)

Como puede verse en la imagen anterior, se le debe proporcionar el enlace del presente repositorio. Al continuar, hará el respectivo proceso de importación:

file:///home/Nevt/Pictures/Screenshots/Screenshot%20from%202022-08-23%2022-38-49.png![image](https://user-images.githubusercontent.com/83324055/186323424-fd6ef0a7-cbe7-4a50-8c41-aae9ab861884.png)

Esto indica que los ficheros han sido correctamente descargados al equipo y el usuario deberá realizar la apertura de los mismos según su conveniencia. 

### Ejecutando el programa

* Qt creator
*
Debido a que se ha utilizado la compilación separada, deberá ejecutar el fichero eigen_project.cpp que contiene el disparador de todo el programa. Lo cual lo llevará a una interfaz como esta: 

file:///home/Nevt/Pictures/Screenshots/Screenshot%20from%202022-08-23%2022-49-24.png![image](https://user-images.githubusercontent.com/83324055/186324733-9f5968e9-937f-4671-89d8-55454e43bf5b.png)


La interfaz presentada en la terminal indica las acciones que, como usuario debe realizar. Por ejemplo, deberá presionar un número del 1 al 15 (99 para salir) ya que cada número identifica el punto que está realizando. Este mostrará las matrices iniciales del ejercicio planteado y la solución que se espera. 


## Autor

Jonathan Alexander Torres Benítez


## Historial de cambios

* 0.2
    * Correcciones de nombres de ficheros
    * Documentación adicional
* 0.1
    * Lanzamiento inicial
