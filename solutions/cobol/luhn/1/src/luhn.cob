       IDENTIFICATION DIVISION.
       PROGRAM-ID. LUHN.
       ENVIRONMENT DIVISION.
       CONFIGURATION SECTION.
       REPOSITORY. FUNCTION ALL INTRINSIC.
       DATA DIVISION.
       WORKING-STORAGE SECTION.
       01 WS-CARD-NUMBER      PIC X(32).
       01 I                   PIC 99.
       01 WS-CARD-DIGITS      PIC 9(32).
       01 WS-CARD-DIGITS-LEN  PIC 99.
       01 WS-CHECKSUM         PIC 9(2).
       01 WS-VALID            PIC X(5).
       77 TEMP                PIC 99.
       
       PROCEDURE DIVISION.
       LUHN.

           MOVE 0 TO WS-CARD-DIGITS-LEN
           MOVE "MAYBE" TO WS-VALID

           PERFORM VARYING I FROM 1 BY 1
              UNTIL I > LENGTH OF WS-CARD-NUMBER
                   EVALUATE TRUE
                   WHEN WS-CARD-NUMBER(I:1) IS NUMERIC
                        MOVE WS-CARD-NUMBER(I:1)
                           TO WS-CARD-DIGITS(WS-CARD-DIGITS-LEN + 1:1)
                        ADD 1 TO WS-CARD-DIGITS-LEN
                   WHEN WS-CARD-NUMBER(I:1) = ' '
                        CONTINUE
                   WHEN OTHER
                        MOVE "FALSE" TO WS-VALID
                        EXIT PERFORM 
                   END-EVALUATE
           END-PERFORM

           IF WS-VALID = "MAYBE" AND WS-CARD-DIGITS-LEN <= 1
              MOVE "FALSE" TO WS-VALID
           END-IF

           IF WS-VALID = "MAYBE"
      *       Calculate checksum using Luhn algorithm
      *       Double Every Second Digit from right, add all digits
              MOVE ZERO TO WS-CHECKSUM
              
      *       Add all digits, doubling every second digit from right
              PERFORM VARYING I FROM 1 BY 1 UNTIL I > WS-CARD-DIGITS-LEN
                      MOVE FUNCTION NUMVAL(WS-CARD-DIGITS(I:1)) TO TEMP
                      
      *               Check if this is second from right (even pos)
                      IF FUNCTION MOD(WS-CARD-DIGITS-LEN - I + 1, 2) = 0
                         COMPUTE TEMP = TEMP * 2
                         IF TEMP > 9
                            COMPUTE TEMP = TEMP - 9
                         END-IF
                      END-IF
                      
                      ADD TEMP TO WS-CHECKSUM
              END-PERFORM

              IF FUNCTION MOD(WS-CHECKSUM, 10) = 0
                 MOVE "VALID" TO WS-VALID
              ELSE 
                 MOVE "FALSE" TO WS-VALID
              END-IF
           END-IF
           .