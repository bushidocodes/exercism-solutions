       IDENTIFICATION DIVISION.
       PROGRAM-ID. RAINDROPS.
       DATA DIVISION.
       WORKING-STORAGE SECTION.
       01 WS-NUMBER        PIC 9(4).
       01 WS-RESULT        PIC X(20).
       01 WS-POINTER       PIC 99    VALUE 1.
       01 WS-SOUND-FLAG    PIC X     VALUE 'N'.
          88 WS-HAS-SOUND            VALUE 'Y' FALSE 'N'.

       PROCEDURE DIVISION.
       RAINDROPS.
           INITIALIZE WS-RESULT
           MOVE 1 TO WS-POINTER
           SET WS-HAS-SOUND TO FALSE

           IF FUNCTION MOD(WS-NUMBER, 3) = 0
              STRING "Pling" DELIMITED BY SIZE
                 INTO WS-RESULT
                 WITH POINTER WS-POINTER
              END-STRING
              SET WS-HAS-SOUND TO TRUE
           END-IF
           
           IF FUNCTION MOD(WS-NUMBER, 5) = 0
              STRING "Plang" DELIMITED BY SIZE
                 INTO WS-RESULT
                 WITH POINTER WS-POINTER
              END-STRING
              SET WS-HAS-SOUND TO TRUE
           END-IF
           
           IF FUNCTION MOD(WS-NUMBER, 7) = 0
              STRING "Plong" DELIMITED BY SIZE
                 INTO WS-RESULT
                 WITH POINTER WS-POINTER
              END-STRING
              SET WS-HAS-SOUND TO TRUE
           END-IF
           
           IF NOT WS-HAS-SOUND
              MOVE WS-NUMBER TO WS-RESULT
           END-IF
           .