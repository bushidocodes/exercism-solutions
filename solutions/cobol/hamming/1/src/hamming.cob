       IDENTIFICATION DIVISION.
       PROGRAM-ID. HAMMING.
       DATA DIVISION.
       WORKING-STORAGE SECTION.
       01 WS-DNA-1      PIC X(32).
       77 WS-DNA-1-LEN  PIC 99.
       01 WS-DNA-2      PIC X(32).
       77 WS-DNA-2-LEN  PIC 99.
       01 WS-HAMMING    PIC 9(2).
       01 WS-ERROR      PIC X(31).
       77 I             PIC 99.

       PROCEDURE DIVISION.
       HAMMING.
           MOVE FUNCTION LENGTH(FUNCTION TRIM(WS-DNA-1)) TO WS-DNA-1-LEN 
           MOVE FUNCTION LENGTH(FUNCTION TRIM(WS-DNA-2)) TO WS-DNA-2-LEN

           MOVE 00 TO WS-HAMMING 
           INITIALIZE WS-ERROR

           IF WS-DNA-1-LEN = WS-DNA-2-LEN
              PERFORM VARYING I FROM 1 BY 1 UNTIL I > WS-DNA-1-LEN
                      IF WS-DNA-1(I:1) NOT = WS-DNA-2(I:1)
                         ADD 1 TO WS-HAMMING
                      END-IF
              END-PERFORM
           ELSE
              MOVE 00 TO WS-HAMMING 
              MOVE "Strands must be of equal length" TO WS-ERROR
           END-IF
           .