# Exercice 2
### 1. À l’aide de la commande hostname, déterminez l’identité de votre machine (son nom, son nom de domaine et son adresse réseau (IP)).
```bash
hostname
lulu
```

```bash
hostname -f
lulu.informatique.univ-paris-diderot.fr
```

```bash
hostname -i
fdc7:9dd5:2c66:be86:4849:43ff:fe49:79bf 192.168.70.236
```

### 2. Sur votre machine, utilisez la commande ping avec les arguments suivants www.google.com puis www.laplanete.uk et www. Qu’en déduisez-vous ?

```bash
ping www.google.com
PING www.google.com (142.250.75.228): 56 data bytes
64 bytes from 142.250.75.228: icmp_seq=0 ttl=115 time=3.869 ms
64 bytes from 142.250.75.228: icmp_seq=1 ttl=115 time=3.659 ms
64 bytes from 142.250.75.228: icmp_seq=2 ttl=115 time=3.527 ms
64 bytes from 142.250.75.228: icmp_seq=3 ttl=115 time=3.277 ms
64 bytes from 142.250.75.228: icmp_seq=4 ttl=115 time=3.673 ms
^C
--- www.google.com ping statistics ---
5 packets transmitted, 5 packets received, 0.0% packet loss
round-trip min/avg/max/stddev = 3.277/3.601/3.869/0.195 ms
```

```bash
ping www.laplanete.uk
ping: cannot resolve www.laplanete.uk: Unknown host
```
    
```bash
ping www
ping: cannot resolve www: Unknown host
```

Ping is a network utility that tests the reachability of a host on an Internet Protocol (IP) network. It measures the round-trip time for messages sent from the originating host to a destination computer that are echoed back to the source. The name resolution failure for www.laplanete.uk and www indicates that these hosts are not reachable or do not exist.

### 3. Pourquoi la commande ping www rend-elle des résultats différents sur lulu et sur votre machine personelle ?

```bash
ping www
PING trotinette.informatique.univ-paris-diderot.fr (194.254.199.80) 56(84) bytes of data.
^C
--- trotinette.informatique.univ-paris-diderot.fr ping statistics ---
13 packets transmitted, 0 received, 100% packet loss, time 12287ms
```

#### Firewall/Anti-DDoS Measures
The server or the network it's on might be protected by firewall rules or anti-DDoS measures that block ICMP packets (which are used by the ping command). Many servers disable ping responses to protect against potential attacks or to reduce unnecessary traffic.

#### NAT Gateway
trotinette.informatique.univ-paris-diderot.fr acts like a gateway between the local network and the internet. It is a server that is used to forward packets from the local network to the internet and vice versa.

#### ICMP Disabled
The server itself might have ICMP responses disabled. Some systems are configured this way for security or administrative reasons.

### 4. En utilisant successivement les commandes host et dig, déterminez les adresses IPv4 et IPv6 de www.informatique.univ-paris-diderot.fr, puis de www.free.fr. Quels sont les noms d’hôtes associés aux adresses obtenues ?

```bash
host www.informatique.univ-paris-diderot.fr
www.informatique.univ-paris-diderot.fr is an alias for trotinette.informatique.univ-paris-diderot.fr.
trotinette.informatique.univ-paris-diderot.fr has address 194.254.199.80
trotinette.informatique.univ-paris-diderot.fr has IPv6 address 2001:660:3301:8070::80
```

```bash
host www.free.fr
www.free.fr has address 212.27.48.10
www.free.fr has IPv6 address 2a01:e0c:1::1
```

```bash
dig www.informatique.univ-paris-diderot.fr +noall +answer
www.informatique.univ-paris-diderot.fr.	86400 IN CNAME trotinette.informatique.univ-paris-diderot.fr.
trotinette.informatique.univ-paris-diderot.fr. 86400 IN	A 194.254.199.80

dig www.informatique.univ-paris-diderot.fr AAAA +noall +answer
www.informatique.univ-paris-diderot.fr.	86400 IN CNAME trotinette.informatique.univ-paris-diderot.fr.
trotinette.informatique.univ-paris-diderot.fr. 86400 IN	AAAA 2001:660:3301:8070::80
```

```bash
dig www.free.fr +noall +answer
www.free.fr.		103	IN	A	212.27.48.10

dig www.free.fr AAAA +noall +answer
www.free.fr.		371	IN	AAAA	2a01:e0c:1::1
```

### 5. Déterminez à l’aide des commandes host et dig comment connaître les serveurs de courrier électronique d’un réseau. Pour cela, regardez sur la page du manuel ce que permet et comment s’utilise la requête MX (pour mail exchanger). Déterminez ensuite les serveurs de courrier électronique des réseaux informatique.univ-paris-diderot.fr et free.fr.

```bash
host -t MX informatique.univ-paris-diderot.fr
informatique.univ-paris-diderot.fr mail is handled by 10 potemkin.univ-paris7.fr.
informatique.univ-paris-diderot.fr mail is handled by 30 shiva.jussieu.fr.
informatique.univ-paris-diderot.fr mail is handled by 10 korolev.univ-paris7.fr.
```

```bash
host -t MX free.fr
free.fr mail is handled by 10 mx1.free.fr.
free.fr mail is handled by 20 mx2.free.fr.
```

```bash
dig informatique.univ-paris-diderot.fr MX +noall +answer
informatique.univ-paris-diderot.fr. 86400 IN MX	10 korolev.univ-paris7.fr.
informatique.univ-paris-diderot.fr. 86400 IN MX	10 potemkin.univ-paris7.fr.
informatique.univ-paris-diderot.fr. 86400 IN MX	30 shiva.jussieu.fr.
```

```bash
dig free.fr MX +noall +answer
free.fr.		9760	IN	MX	20 mx2.free.fr.
free.fr.		9760	IN	MX	10 mx1.free.fr.
```

### 6. De même déterminez les serveurs DNS des domaines informatique.univ-paris-diderot. fr et free.fr en utilisant l’option NS.

```bash

```bash
host -t NS informatique.univ-paris-diderot.fr
informatique.univ-paris-diderot.fr name server shiva.jussieu.fr.
informatique.univ-paris-diderot.fr name server potemkin.univ-paris7.fr.
informatique.univ-paris-diderot.fr name server korolev.univ-paris7.fr.
```

```bash
host -t NS free.fr
free.fr name server freens3-scw.free.fr.
free.fr name server freens2-g20.free.fr.
free.fr name server freens1-g20.free.fr.
```

```bash
dig informatique.univ-paris-diderot.fr NS +noall +answer
informatique.univ-paris-diderot.fr. 86400 IN NS	korolev.univ-paris7.fr.
informatique.univ-paris-diderot.fr. 86400 IN NS	potemkin.univ-paris7.fr.
informatique.univ-paris-diderot.fr. 86400 IN NS	shiva.jussieu.fr.
```

```bash
dig free.fr NS +noall +answer
free.fr.		3484	IN	NS	freens2-g20.free.fr.
free.fr.		3484	IN	NS	freens3-scw.free.fr.
free.fr.		3484	IN	NS	freens1-g20.free.fr.
```

### 7. Quelle est le nom complet de la machine avec l’IP 2a02:ec80:600:ed1a::3 ?

```bash
host 2a02:ec80:600:ed1a::3
3.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.a.1.d.e.0.0.6.0.0.8.c.e.2.0.a.2.ip6.arpa domain name pointer ncredir-lb.drmrs.wikimedia.org.
```