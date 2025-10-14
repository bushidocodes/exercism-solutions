       IDENTIFICATION DIVISION.
       PROGRAM-ID. ROTATIONAL-CIPHER.
       DATA DIVISION.
       WORKING-STORAGE SECTION.
       01 WS-KEY     PIC 9(2).
       01 WS-TEXT    PIC X(128).
       01 WS-CIPHER  PIC X(128).
       01 I          PIC 9(3)   VALUE 1.
       01 C          PIC X.
       PROCEDURE DIVISION.
       ROTATIONAL-CIPHER.
           INITIALIZE WS-CIPHER 
           MOVE FUNCTION UPPER-CASE(WS-TEXT) TO WS-TEXT
           PERFORM VARYING I FROM 1 BY 1 UNTIL I > LENGTH OF WS-TEXT
                   MOVE WS-TEXT(I:1) TO C
                   IF C >= 'A' AND C <= 'Z'
                      MOVE FUNCTION CHAR(FUNCTION ORD('A') +
                         FUNCTION MOD(
                         FUNCTION ORD(C) -
                         FUNCTION ORD('A') + WS-KEY, 26))
                         TO WS-CIPHER(I:1)
                   ELSE
                      MOVE C TO WS-CIPHER(I:1)
                   END-IF
           END-PERFORM.