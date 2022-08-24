![image](https://user-images.githubusercontent.com/83324055/186306221-eb5af8a8-ed46-491b-9c15-8ee380cbf750.png)


# Taller de ejercicios usando Eigen

El presente repositorio contiene la implementación de los ejercicios propuestos de operaciones entre matrices utilizando la biblioteca Eigen a través del lenguaje de programación C++. 

## Descripción

Basado en los ejercicios propuestos en el siguiente enlace:

https://www.math-exercises.com/matrices/matrix-equations

Se requiere la realización de 15 de estos ejercicios, los cuales son de elección propia. Para este repositorio en particular, se eligió todos los presentes a excepción del ejercicio n.

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

* Any modifications needed to be made to files/folders

### Executing program

* How to run the program
* Step-by-step bullets
```
code blocks for commands
```

## Help

Any advise for common problems or issues.
```
command to run if program contains helper info
```

## Authors

Contributors names and contact info

ex. Dominique Pizzie  
ex. [@DomPizzie](https://twitter.com/dompizzie)

## Version History

* 0.2
    * Various bug fixes and optimizations
    * See [commit change]() or See [release history]()
* 0.1
    * Initial Release

## License

This project is licensed under the [NAME HERE] License - see the LICENSE.md file for details

## Acknowledgments

Inspiration, code snippets, etc.
* [awesome-readme](https://github.com/matiassingers/awesome-readme)
* [PurpleBooth](https://gist.github.com/PurpleBooth/109311bb0361f32d87a2)
* [dbader](https://github.com/dbader/readme-template)
* [zenorocha](https://gist.github.com/zenorocha/4526327)
* [fvcproductions](https://gist.github.com/fvcproductions/1bfc2d4aecb01a834b46)
