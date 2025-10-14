       IDENTIFICATION DIVISION.
       PROGRAM-ID. YACHT.
       DATA DIVISION.
       WORKING-STORAGE SECTION.
       01 WS-RESULT    PIC 99    VALUE 0.
       01 WS-CATEGORY  PIC X(15).
       01 WS-DICE      PIC 9(5)  VALUE 12345.
       01 DIGITS.
          05 D  OCCURS 5 TIMES
                       PIC 9.
       77 P            PIC 9     VALUE 1.

       01 COUNTS.
          05 VALCOUNT OCCURS 6 TIMES
                       PIC 9.

      * Temporary variables for SORT-DICE
       77 I            PIC 9(1).
       77 J            PIC 9(1).
       77 TEMP         PIC 9(1).

       PROCEDURE DIVISION.
       YACHT.
           INITIALIZE WS-RESULT
           INITIALIZE COUNTS

      * Validate dice input
           PERFORM VARYING I FROM 1 BY 1 UNTIL I > 5
                   IF WS-DICE(I:1) < '1' OR WS-DICE(I:1) > '6'
                      DISPLAY 'Error: Dice must be between 1 and 6'
                      STOP RUN
                   END-IF
           END-PERFORM

      * Sort dice
           PERFORM SORT-DICE

      * Count dice
           PERFORM VARYING I FROM 1 BY 1 UNTIL I > 5
                   ADD 1 TO VALCOUNT(FUNCTION NUMVAL(WS-DICE(I:1)))
           END-PERFORM
           PERFORM SORT-COUNTS

      * Calculate score based on category
           EVALUATE WS-CATEGORY
           WHEN 'yacht'
                IF WS-DICE = 11111 OR WS-DICE = 22222
                   OR WS-DICE = 33333 OR WS-DICE = 44444
                   OR WS-DICE = 55555 OR WS-DICE = 66666
                   MOVE 50 TO WS-RESULT
                END-IF
           WHEN 'ones'
                PERFORM VARYING I FROM 1 BY 1 UNTIL I > 5
                        IF WS-DICE(I:1) = 1
                           ADD 1 TO WS-RESULT
                        END-IF
                END-PERFORM
           WHEN 'twos'
                PERFORM VARYING I FROM 1 BY 1 UNTIL I > 5
                        IF WS-DICE(I:1) = 2
                           ADD 2 TO WS-RESULT
                        END-IF
                END-PERFORM
           WHEN 'threes'
                PERFORM VARYING I FROM 1 BY 1 UNTIL I > 5
                        IF WS-DICE(I:1) = 3
                           ADD 3 TO WS-RESULT
                        END-IF
                END-PERFORM
           WHEN 'fours'
                PERFORM VARYING I FROM 1 BY 1 UNTIL I > 5
                        IF WS-DICE(I:1) = 4
                           ADD 4 TO WS-RESULT
                        END-IF
                END-PERFORM
           WHEN 'fives'
                PERFORM VARYING I FROM 1 BY 1 UNTIL I > 5
                        IF WS-DICE(I:1) = 5
                           ADD 5 TO WS-RESULT
                        END-IF
                END-PERFORM
           WHEN 'sixes'
                PERFORM VARYING I FROM 1 BY 1 UNTIL I > 5
                        IF WS-DICE(I:1) = 6
                           ADD 6 TO WS-RESULT
                        END-IF
                END-PERFORM
           WHEN 'little straight'
                IF WS-DICE = 12345
                   ADD 30 TO WS-RESULT 
                END-IF 
           WHEN 'big straight'
                IF WS-DICE = 23456
                   ADD 30 TO WS-RESULT 
                END-IF
           WHEN 'four of a kind '
                IF VALCOUNT(6) >= 4
                   COMPUTE WS-RESULT = 4 * FUNCTION NUMVAL(WS-DICE(4:1)) 
                END-IF
           WHEN 'full house'
                IF VALCOUNT(6) = 3 AND VALCOUNT(5) = 2
                   PERFORM VARYING I FROM 1 BY 1 UNTIL I > 5
                           ADD FUNCTION NUMVAL(WS-DICE(I:1)) TO
                              WS-RESULT
                   END-PERFORM
                END-IF
           WHEN 'choice'
                PERFORM VARYING I FROM 1 BY 1 UNTIL I > 5
                        ADD FUNCTION NUMVAL(WS-DICE(I:1)) TO WS-RESULT
                END-PERFORM
           WHEN OTHER
                CONTINUE
           END-EVALUATE.
      
      * Subprogram: split, sort, rebuild
       SORT-DICE.
      * Split number into digits
           PERFORM VARYING I FROM 1 BY 1 UNTIL I > 5
                   MOVE FUNCTION NUMVAL(WS-DICE(I:1)) TO D(I)
           END-PERFORM

      *    Bubble sort dice
           PERFORM VARYING I FROM 1 BY 1 UNTIL I > 4
                   PERFORM VARYING J FROM 1 BY 1 UNTIL J > 5 - I
                           IF D(J) > D(J + 1)
                              MOVE D(J) TO TEMP
                              MOVE D(J + 1) TO D(J)
                              MOVE TEMP TO D(J + 1)
                           END-IF
                   END-PERFORM
           END-PERFORM

      * Rebuild number from sorted digits
           MOVE 1 TO P
           INITIALIZE WS-DICE
           PERFORM VARYING I FROM 1 BY 1 UNTIL I > 5
                   STRING D(I) DELIMITED BY SIZE INTO WS-DICE WITH
                      POINTER P
           END-PERFORM
           .

      * Subprogram: split, sort, rebuild
       SORT-COUNTS.
      *    Bubble sort dice
           PERFORM VARYING I FROM 1 BY 1 UNTIL I > 5
                   PERFORM VARYING J FROM 1 BY 1 UNTIL J > 6 - I
                           IF VALCOUNT(J) > VALCOUNT(J + 1)
                              MOVE VALCOUNT(J) TO TEMP
                              MOVE VALCOUNT(J + 1) TO VALCOUNT(J)
                              MOVE TEMP TO VALCOUNT(J + 1)
                           END-IF
                   END-PERFORM
           END-PERFORM
           .