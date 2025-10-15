       IDENTIFICATION DIVISION.
       PROGRAM-ID. TRIANGLE.
       DATA DIVISION.
       WORKING-STORAGE SECTION.
      *Incoming
       01 WS-SIDES            PIC X(20).
       01 WS-PROPERTY         PIC X(11).
      *Outgoing
       01 WS-RESULT           PIC 9.
      *Temporaries for parsing WS-SIDES
       01 WS-PARSING_DONE     PIC 9     VALUE 0.
          88 IS-DONE                    VALUE 1 FALSE 0.
       77 WS-POS              PIC 99.
      *Parsed Values
       01 WS-SIDES-ARR COMP-2 OCCURS 3 TIMES.
       77 WS-SIDES-ARR-COUNT  PIC 9     VALUE 0.
      *Bubble Sort Temporaries
       77 I                   PIC 9     VALUE 1.
       77 J                   PIC 9     VALUE 1.
       77 TEMP COMP-2.
       
       PROCEDURE DIVISION.
       TRIANGLE.
           MOVE 0 TO WS-SIDES-ARR-COUNT
           MOVE 0 TO WS-RESULT

      *    Parse
           SET IS-DONE TO FALSE
           PERFORM UNTIL IS-DONE OR WS-SIDES-ARR-COUNT = 3
      *            It seems like TALLYING doesn't zero out the count
                   MOVE 0 TO WS-POS
                   INSPECT WS-SIDES TALLYING WS-POS
                      FOR CHARACTERS BEFORE INITIAL ","
                   IF WS-POS = 0
                      MOVE FUNCTION NUMVAL(WS-SIDES)
                         TO WS-SIDES-ARR(WS-SIDES-ARR-COUNT + 1)
                      ADD 1 TO WS-SIDES-ARR-COUNT
                      SET IS-DONE TO TRUE
                   ELSE
                      MOVE FUNCTION NUMVAL(WS-SIDES(1:WS-POS)) TO
                         WS-SIDES-ARR(WS-SIDES-ARR-COUNT + 1)
                      ADD 1 TO WS-SIDES-ARR-COUNT
                      MOVE WS-SIDES(WS-POS + 2:) TO WS-SIDES
                   END-IF
           END-PERFORM

      *    Sort
           PERFORM VARYING I FROM 1 BY 1 UNTIL I > 2
                   PERFORM VARYING J FROM 1 BY 1 UNTIL J > 3 - I
                           IF WS-SIDES-ARR(J) > WS-SIDES-ARR(J + 1)
                              MOVE WS-SIDES-ARR(J) TO TEMP
                              MOVE WS-SIDES-ARR(J + 1) TO WS-SIDES-ARR
                                 (J)
                              MOVE TEMP TO WS-SIDES-ARR(J + 1)
                           END-IF
                   END-PERFORM
           END-PERFORM

      *    Evaluate if not degenerate
           IF NOT ((WS-SIDES-ARR(1) = 0 AND WS-SIDES-ARR(2) = 0
              AND WS-SIDES-ARR(3) = 0) OR WS-SIDES-ARR-COUNT < 3
              OR WS-SIDES-ARR(1) + WS-SIDES-ARR(2) < WS-SIDES-ARR(3))
     
              EVALUATE WS-PROPERTY
              WHEN "equilateral"
                   IF WS-SIDES-ARR(1) = WS-SIDES-ARR(2)
                      AND WS-SIDES-ARR(2) = WS-SIDES-ARR(3)
                      MOVE 1 TO WS-RESULT
                   END-IF
              WHEN "isosceles"
                   IF WS-SIDES-ARR(1) = WS-SIDES-ARR(2)
                      OR WS-SIDES-ARR(2) = WS-SIDES-ARR(3)
                      OR WS-SIDES-ARR(1) = WS-SIDES-ARR(3)
                      MOVE 1 TO WS-RESULT
                   END-IF 
              WHEN "scalene"
                   IF WS-SIDES-ARR(1) NOT = WS-SIDES-ARR(2)
                      AND WS-SIDES-ARR(2) NOT = WS-SIDES-ARR(3)
                      AND WS-SIDES-ARR(1) NOT = WS-SIDES-ARR(3)
                      MOVE 1 TO WS-RESULT
                   END-IF 
              WHEN OTHER
                   DISPLAY "ASSERTION FAILED: Unknown property"
                   STOP RUN
              END-EVALUATE
           END-IF
           .