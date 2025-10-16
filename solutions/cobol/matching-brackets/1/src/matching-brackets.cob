       IDENTIFICATION DIVISION.
       PROGRAM-ID. MATCHING-BRACKETS.
       ENVIRONMENT DIVISION.
       DATA DIVISION.
       WORKING-STORAGE SECTION.
       01 WS-INPUT          PIC X(100).
       01 WS-INPUT-LEN      PIC 999.
       01 WS-RESULT         PIC 9.
          88 IS-MATCHED                VALUE 1 FALSE 0.
       77 I                 PIC 999.

       01 WS-STACK.
          05 WS-STACK-ELEM  PIC X OCCURS 100 TIMES.
       77 WS-STACK-TOP      PIC 999.

       PROCEDURE DIVISION.
       ISPAIRED.
           MOVE FUNCTION LENGTH(FUNCTION TRIM(WS-INPUT)) TO WS-INPUT-LEN 
           MOVE 1 TO I
           MOVE 0 TO WS-STACK-TOP

           SET IS-MATCHED TO TRUE
           PERFORM VARYING I FROM 1 BY 1 UNTIL I > WS-INPUT-LEN
              OR NOT IS-MATCHED
                   EVALUATE WS-INPUT(I:1)
                   WHEN '['
                   WHEN '{'
                   WHEN '('
                        ADD 1 TO WS-STACK-TOP
                        MOVE WS-INPUT(I:1) TO WS-STACK-ELEM
                           (WS-STACK-TOP)
                   WHEN ']'
                        IF WS-STACK-TOP = 0
                           OR WS-STACK-ELEM(WS-STACK-TOP) NOT = '['
                           SET IS-MATCHED TO FALSE
                        ELSE
                           SUBTRACT 1 FROM WS-STACK-TOP
                        END-IF
                   WHEN '}'
                        IF WS-STACK-TOP = 0
                           OR WS-STACK-ELEM(WS-STACK-TOP) NOT = '{'
                           SET IS-MATCHED TO FALSE
                        ELSE
                           SUBTRACT 1 FROM WS-STACK-TOP
                        END-IF
                   WHEN ')'
                        IF WS-STACK-TOP = 0
                           OR WS-STACK-ELEM(WS-STACK-TOP) NOT = '('
                           SET IS-MATCHED TO FALSE
                        ELSE
                           SUBTRACT 1 FROM WS-STACK-TOP
                        END-IF
                   END-EVALUATE
           END-PERFORM

           IF WS-STACK-TOP NOT = 0
              SET IS-MATCHED TO FALSE
           END-IF
           .