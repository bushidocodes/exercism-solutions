       IDENTIFICATION DIVISION.
       PROGRAM-ID. HIGH-SCORES.

       DATA DIVISION.
       WORKING-STORAGE SECTION.
       01 WS-PROPERTY         PIC A(20).
       01 WS-SCORES.
          02 SCORES           PIC X(3) OCCURS 20 TIMES
                INDEXED BY IDX.
                
       01 WS-TOP-INDICES      PIC 99 OCCURS 3 TIMES.
       01 WS-TOP-INDICES-LEN  PIC 99.



       01 SCORES-LEN          PIC 99.
       01 PTR                 PIC 99.

       01 WS-RESULT-STRING    PIC X(60).
       01 WS-RESULT-VALUE     PIC 999.
       01 MAX                 PIC 999.
       01 MAX-IDX             PIC S999.

       PROCEDURE DIVISION.
       HIGH-SCORES.

           MOVE 0 TO SCORES-LEN
           PERFORM VARYING IDX FROM 1 BY 1 UNTIL SCORES(IDX) = SPACES 
                   ADD 1 TO SCORES-LEN
           END-PERFORM


           EVALUATE WS-PROPERTY
           WHEN "scores"
                INITIALIZE WS-RESULT-STRING
                MOVE 1 TO PTR
                PERFORM VARYING IDX FROM 1 BY 1 UNTIL IDX > SCORES-LEN
                        STRING SCORES(IDX) DELIMITED BY SIZE
                           INTO WS-RESULT-STRING
                           WITH POINTER PTR
                        END-STRING
                END-PERFORM
           WHEN "latest"
                MOVE SCORES(SCORES-LEN) TO WS-RESULT-VALUE
           WHEN "personalBest"
                MOVE 0 TO WS-RESULT-VALUE
                PERFORM VARYING IDX FROM 1 BY 1 UNTIL IDX > SCORES-LEN
                        IF SCORES(IDX) > WS-RESULT-VALUE
                           MOVE SCORES(IDX) TO WS-RESULT-VALUE
                        END-IF
                END-PERFORM
           WHEN "personalTopThree"
                INITIALIZE WS-RESULT-STRING

      *         Cache indices to filter out what we've already added
                MOVE 0 TO WS-TOP-INDICES(1)
                MOVE 0 TO WS-TOP-INDICES(2)
                MOVE 0 TO WS-TOP-INDICES(3)
                MOVE 0 TO WS-TOP-INDICES-LEN 

                MOVE 1 TO PTR
      *         Just doing a linear search three times since the list
      *         is only 20 items long.
                PERFORM 3 TIMES
                        MOVE 0 TO MAX
                        MOVE -1 TO MAX-IDX
                        PERFORM VARYING IDX FROM 1 BY 1
                           UNTIL IDX > SCORES-LEN

      *                         We don't ever need to check idx 3
      *                         because we run 3x. It's okay to have 
      *                         spurious checks because 0 is a sentinel
                                IF IDX NOT = WS-TOP-INDICES(1) AND
                                   IDX NOT = WS-TOP-INDICES(2) AND
                                   (MAX-IDX = -1 OR
                                   FUNCTION NUMVAL(SCORES(IDX)) > MAX)
                                   
                                   MOVE SCORES(IDX) TO MAX
                                   MOVE IDX TO MAX-IDX
                                END-IF
                        END-PERFORM

                        IF MAX-IDX NOT = -1
                           STRING SCORES(MAX-IDX) DELIMITED BY SIZE
                              INTO WS-RESULT-STRING
                              WITH POINTER PTR
                           END-STRING
                           ADD 1 TO WS-TOP-INDICES-LEN
                           MOVE MAX-IDX TO WS-TOP-INDICES
                              (WS-TOP-INDICES-LEN)
                        END-IF
                END-PERFORM
           WHEN OTHER
                CONTINUE
           END-EVALUATE
           .