       IDENTIFICATION DIVISION.
       PROGRAM-ID. BINARY-TWO.
       ENVIRONMENT DIVISION.
       DATA DIVISION.
       WORKING-STORAGE SECTION.
       01 WS-BINARY      PIC X(60).
       01 WS-BINARY-LEN  PIC 99.
       01 WS-RESULT      PIC 9999.
       01 WS-ERROR       PIC X(60). 
       01 I              PIC 99.
       
       PROCEDURE DIVISION.
       
       DECIMAL.
           MOVE FUNCTION LENGTH(FUNCTION TRIM(WS-BINARY))
              TO WS-BINARY-LEN

           MOVE 0 TO WS-RESULT
           INITIALIZE WS-ERROR
           
           PERFORM VARYING I FROM 1 BY 1 UNTIL I > WS-BINARY-LEN
                   EVALUATE WS-BINARY(I:1)
                   WHEN '1'
                        COMPUTE WS-RESULT = WS-RESULT * 2 + 1
                   WHEN '0'
                        COMPUTE WS-RESULT = WS-RESULT * 2
                   WHEN '2' THROUGH '9'
                        MOVE "error: a number containing non-binary"
                             & " digits is invalid" TO WS-ERROR
                        EXIT PERFORM
                   WHEN OTHER
                        MOVE "error: a number containing non-binary"
                             & " characters is invalid" TO WS-ERROR
                        EXIT PERFORM
                   END-EVALUATE
           END-PERFORM
           .