       IDENTIFICATION DIVISION.
       PROGRAM-ID. YACHT.
       DATA DIVISION.
       WORKING-STORAGE SECTION.
       01 WS-RESULT PIC 99 VALUE 0.
       01 WS-CATEGORY PIC X(15).
       01 WS-DICE PIC 9(5).
          PROCEDURE DIVISION.
          YACHT.

          EVALUATE WS-CATEGORY
              WHEN 'yacht'
                IF WS-RESULT = 11111 OR WS-RESULT = 22222 
                  OR WS-RESULT = 33333 OR WS-RESULT = 44444
                  OR WS-RESULT = 55555 OR WS-RESULT = 66666
                    MOVE 50 TO WS-RESULT
                END-IF
              WHEN 'ones'
              WHEN 'twos'
              WHEN 'threes'
              WHEN 'fours'
              WHEN 'fives'
              WHEN 'sixes'
              WHEN OTHER
                 CONTINUE
          END-EVALUATE
          
