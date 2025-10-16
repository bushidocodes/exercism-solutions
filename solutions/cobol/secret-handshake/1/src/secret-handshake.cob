       IDENTIFICATION DIVISION.
       PROGRAM-ID. SECRET-HANDSHAKE.
       ENVIRONMENT DIVISION.
       DATA DIVISION.
       WORKING-STORAGE SECTION.
       01 WS-INPUT       PIC 999.
       01 WS-RESULT      PIC X(60).
       77 WS-RESULT-PTR  PIC 99.

       PROCEDURE DIVISION.
       COMMANDS.
           INITIALIZE WS-RESULT
           MOVE 1 TO WS-RESULT-PTR

           IF FUNCTION MOD(FUNCTION INTEGER(WS-INPUT / 16), 2) = 0
              PERFORM TEST-WINK
              PERFORM TEST-DOUBLE-BLINK
              PERFORM TEST-CLOSE-YOUR-EYES
              PERFORM TEST-JUMP
           ELSE
              PERFORM TEST-JUMP
              PERFORM TEST-CLOSE-YOUR-EYES
              PERFORM TEST-DOUBLE-BLINK
              PERFORM TEST-WINK
           END-IF
           .

       TEST-WINK.
           IF FUNCTION MOD(WS-INPUT, 2) = 1
              PERFORM ADD-COMMA
              STRING "wink" DELIMITED BY SIZE
                 INTO WS-RESULT WITH POINTER WS-RESULT-PTR 
           END-IF
           .

       TEST-DOUBLE-BLINK.
           IF FUNCTION MOD(FUNCTION INTEGER(WS-INPUT / 2), 2) = 1
              PERFORM ADD-COMMA
              STRING "double blink" DELIMITED BY SIZE
                 INTO WS-RESULT WITH POINTER WS-RESULT-PTR 
           END-IF
           .

       TEST-CLOSE-YOUR-EYES.
           IF FUNCTION MOD(FUNCTION INTEGER(WS-INPUT / 4), 2) = 1
              PERFORM ADD-COMMA
              STRING "close your eyes" DELIMITED BY SIZE
                 INTO WS-RESULT WITH POINTER WS-RESULT-PTR 
           END-IF
           .
          
       TEST-JUMP.
           IF FUNCTION MOD(FUNCTION INTEGER(WS-INPUT / 8), 2) = 1
              PERFORM ADD-COMMA
              STRING "jump" DELIMITED BY SIZE
                 INTO WS-RESULT WITH POINTER WS-RESULT-PTR 
           END-IF
           .

       ADD-COMMA.
           IF WS-RESULT-PTR > 1
              STRING "," DELIMITED BY SIZE
                 INTO WS-RESULT WITH POINTER
                 WS-RESULT-PTR
           END-IF
           .