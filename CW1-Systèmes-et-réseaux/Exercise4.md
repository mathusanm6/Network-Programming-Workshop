# Exercise 4

### 1. Depuis la machine lulu, en vous connectant directement au port SMTP de la machine d’ip 192.168.70.73 (qui correspond à l’adresse ip de nivose sur le réseau local de l’UFR d’informatique) à l’aide de la commande « telnet », envoyez un mail à l’un de vos collègues.

```bash
telnet 192.168.70.73 smtp
Trying 192.168.70.73...
Connected to 192.168.70.73.
Escape character is '^]'.
220 nivose.informatique.univ-paris-diderot.fr ESMTP Sendmail 8.15.1+Sun/8.14.1; Sun, 25 Feb 2024 10:53:00 +0100 (CET)
HELO lulu
250 nivose.informatique.univ-paris-diderot.fr Hello selvakum@lulu.informatique.univ-paris-diderot.fr [192.168.70.236], pleased to meet you
MAIL FROM: selvakumar@lulu
250 2.1.0 selvakumar@lulu... Sender ok
RCPT TO: selvakum
250 2.1.5 selvakum... Recipient ok
DATA
354 Enter mail, end with "." on a line by itself
From: selvakum@lulu
To: selvakum
Subject: Test
Hello Selvakum!
.
250 2.0.0 41P9r0b5027046 Message accepted for delivery
QUIT
221 2.0.0 nivose.informatique.univ-paris-diderot.fr closing connection
Connection closed by foreign host.
```

```bash
From selvakumar@lulu.informatique.univ-paris-diderot.fr Sun Feb 25 10:53:50 2024
Return-Path: <selvakumar@lulu.informatique.univ-paris-diderot.fr>
Received: from lulu (selvakum@lulu.informatique.univ-paris-diderot.fr [192.168.70.236])
        by nivose.informatique.univ-paris-diderot.fr (8.15.1+Sun/8.14.1) with SMTP id 41P9r0b5027046
        for selvakum; Sun, 25 Feb 2024 10:53:14 +0100 (CET)
Date: Sun, 25 Feb 2024 10:53:00 +0100 (CET)
Message-Id: <202402250953.41P9r0b5027046@nivose.informatique.univ-paris-diderot.fr>
From: selvakum@lulu.informatique.univ-paris-diderot.fr
To: selvakum@nivose.informatique.univ-paris-diderot.fr
Subject: Test
Content-Length: 16

Hello Selvakum!
```

### 2. Répétez l’expérience précédente en donnant des adresses différentes dans l’enveloppe (commande « RCPT TO: » de SMTP) et dans le message (entête « To: » de RFC 822). Que se passe-t-il ?

```bash
telnet 192.168.70.73 smtp
Trying 192.168.70.73...
Connected to 192.168.70.73.
Escape character is '^]'.
220 nivose.informatique.univ-paris-diderot.fr ESMTP Sendmail 8.15.1+Sun/8.14.1; Sun, 25 Feb 2024 11:05:15 +0100 (CET)
HELO lulu
250 nivose.informatique.univ-paris-diderot.fr Hello selvakum@lulu.informatique.univ-paris-diderot.fr [192.168.70.236], pleased to meet you
MAIL FROM: selvakum@lulu
250 2.1.0 selvakum@lulu... Sender ok
RCPT TO: selvakum
250 2.1.5 selvakum... Recipient ok
DATA
354 Enter mail, end with "." on a line by itself
From: selvakum@lulu
To: lucette
Subject: Hi
Hi, LUCETTE!
.
250 2.0.0 41PA5F4F028747 Message accepted for delivery
QUIT
221 2.0.0 nivose.informatique.univ-paris-diderot.fr closing connection
Connection closed by foreign host.
```

```bash
From selvakum@lulu.informatique.univ-paris-diderot.fr Sun Feb 25 11:07:24 2024
Return-Path: <selvakum@lulu.informatique.univ-paris-diderot.fr>
Received: from lulu (selvakum@lulu.informatique.univ-paris-diderot.fr [192.168.70.236])
        by nivose.informatique.univ-paris-diderot.fr (8.15.1+Sun/8.14.1) with SMTP id 41PA5F4F028747
        for selvakum; Sun, 25 Feb 2024 11:06:26 +0100 (CET)
Date: Sun, 25 Feb 2024 11:05:15 +0100 (CET)
Message-Id: <202402251006.41PA5F4F028747@nivose.informatique.univ-paris-diderot.fr>
From: selvakum@lulu.informatique.univ-paris-diderot.fr
To: lucette@nivose.informatique.univ-paris-diderot.fr
Subject: Hi
Content-Length: 13

Hi, LUCETTE!

```

Lorsque vous utilisez des adresses différentes dans la commande SMTP `RCPT TO:` et dans l'entête `To:` d'un email, le message est acheminé à l'adresse spécifiée par `RCPT TO:`, qui détermine le routage réel du message, tandis que l'adresse dans l'entête `To:` est celle affichée au destinataire dans son client de messagerie. Cette fonctionnalité permet des usages comme l'envoi en copie cachée, mais peut aussi être exploitée de manière abusive. 
