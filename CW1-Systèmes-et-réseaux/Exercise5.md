# Exercise 5

### 3. Envoyez votre requête au serveur sur le port 53 et récupérez la réponse avec la commande suivante :

```bash
grep " 53/" /etc/services
domain           53/udp     # Domain Name Server
domain           53/tcp     # Domain Name Server
```

```bash
cat requete | nc -u 2a04:cb08:972:ea01:46d4:54ff:fe34:9671 53 | hexdump -C
```

```bash
cat requete | nc -u 2a04:cb08:972:ea01:46d4:54ff:fe34:9671 53 | hexdump -C
00000000  de 82 81 80 00 01 00 01  00 00 00 00 03 77 77 77  |.............www|
00000010  09 77 69 6b 69 70 65 64  69 61 02 66 72 00 00 01  |.wikipedia.fr...|
00000020  00 01 c0 0c 00 01 00 01  00 00 20 18 00 04 8d 5e  |.......... ....^|
```