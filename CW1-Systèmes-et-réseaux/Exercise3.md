# Exercise 3

### 1. Déterminez le port associé au service discard (Indication : vous avez vu en cours où trouver la liste des services).

```bash
grep discard /etc/services
discard		9/tcp		sink null
discard		9/udp		sink null
```

### 2. À l’aide de la commande telnet,déterminez l’heure (service daytime,dont la documentation est RFC 867) qu’il est sur la machine lulu. Appelez ce service à la fois par son nom et par son numéro de port et profitez en aussi pour aller voir la page Wikipedia de "Requests For Comments" pour connaître ce que sont les RFC. Consultez ensuite la documentation RFC 867.

```bash
grep daytime /etc/services
daytime		13/tcp
daytime		13/udp
```

```bash
telnet lulu 13
Trying fdc7:9dd5:2c66:be86:4859:43ff:fe49:79bf...
Connected to lulu.
Escape character is '^]'.
Sun Feb 25 10:13:52 2024
Connection closed by foreign host.
```

```bash
telnet lulu daytime
Trying fdc7:9dd5:2c66:be86:4859:43ff:fe49:79bf...
Connected to lulu.
Escape character is '^]'.
Sun Feb 25 10:14:08 2024
Connection closed by foreign host.
```

### 3. À l’aide de la commande telnet, accédez au service echo (RFC 862) sur la machine lulu. Tapez alors du texte avec des retours à la ligne. Comment pouvez quitter l’application telnet ? Faire de même avec la commande nc.

```bash
telnet lulu echo
Trying fdc7:9dd5:2c66:be86:4849:43ff:fe49:79bf...
Connected to lulu.
Escape character is '^]'.
```

- Control + ] to open the telnet prompt, then type `quit` and press enter (US keyboard layout).
- Control + § to open the telnet prompt, then type `quit` and press enter (FR keyboard layout).

```bash
nc lulu echo
```