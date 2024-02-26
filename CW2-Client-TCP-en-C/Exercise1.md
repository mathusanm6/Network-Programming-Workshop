# Exercise 1 - Déterminer le « boutisme » (endianness) d’une machine

### 1. En regardant si la fonction htonl est l’identité (ce qui veut dire que host order et network order sont identiques) ou non. Tester un seul entier suffit.

[ex1_htonl.c](./ex1_htonl.c)

### 2. En regardant comment sont encodés les entiers en mémoire sur votre machine. Pour cela on peut convertir un entier codé sur 32 bits, par exemple uint32_t witness = 0x01020304; en un tableau de 4 unsigned char, et les afficher dans l’ordre.

[ex1_endianness.c](./ex1_endianness.c)