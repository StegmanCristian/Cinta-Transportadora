# TP MAQUINAS DE ESTADO - INFORMATICA II - 2º12
### Profesores
- Prof. Viard, Gustavo
- JTP. Corbalan, Damian

### Alumno 
- Stegman Cristian

## MEMORIA DESCRIPTIVA
 
### Descripcion del funcionamiento
El proyecto consiste en un sistema de seleccion para una cinta transportadora que, de acuerdo al peso del objeto, determina la direccion del mismo.
El sistema posee:
- Un sensor de peso
- Un selector de direccion.

##### Funcionamiento
Mediante el reconocimiento del peso de las cosas a transportar se realiza una selección, con el criterio de separar por peso en tres grupos. Con ese fin, se le otorga a cada grupo un destino distianto (es decir, una dirección):
- Livianos (izquierda)
- Poco pesadas (Recto)
- Pesadas (Derecha)

### Diagrama de Estados y Transiciones

![alt text]( https://github.com/StegmanCristian/Cinta-Transportadora/blob/main/Recursos/diagrama%20de%20%20estados%20y%20transiciones%20.jpeg)

##### Donde:
- **p** : Peso leido
- **p_set1** : Peso seteado donde deja de ser "Liviano" y pasa a ser "Poco Pesado"
- **p_set2** : Peso seteado donde deja de ser "Poco Pesado" y pasa a ser "Pesado"

