       IDENTIFICATION DIVISION.
       PROGRAM-ID. GRADE-SCHOOL.
       ENVIRONMENT DIVISION.
       DATA DIVISION.
       WORKING-STORAGE SECTION.
       01 WS-STUDENTNAME       PIC X(60).
       01 WS-STUDENTGRADE      PIC 9.
       01 WS-RESULT            PIC X(5).
       01 WS-DESIREDGRADE      PIC 99.
       
       01 STUDENTROSTER.
          02 ROSTER OCCURS 10 TIMES.
             05 ST-NAME        PIC X(60).
             05 ST-GRADE       PIC 9.   
       01 STUDENTROSTER-COUNT  PIC 99    VALUE 0.
       01 I                    PIC 99    VALUE 0.
       01 J                    PIC 99    VALUE 0.
       01 IN-ROSTER-FLAG       PIC 9     VALUE 0.
          88 IN-ROSTER                   VALUE 1 FALSE 0.
       
       PROCEDURE DIVISION.
        
       INIT-ROSTER.
           INITIALIZE STUDENTROSTER
           INITIALIZE STUDENTROSTER-COUNT
           .


       ADD-STUDENT.
           SET IN-ROSTER TO FALSE
           PERFORM VARYING I FROM 1 BY 1 UNTIL I > STUDENTROSTER-COUNT
                   IF WS-STUDENTNAME = ST-NAME OF ROSTER(I)
                      SET IN-ROSTER TO TRUE
                   END-IF
           END-PERFORM

           IF STUDENTROSTER-COUNT < 10 AND NOT IN-ROSTER
      *       Advance to insertion point
              PERFORM VARYING I FROM 1 BY 1 UNTIL I >
                 STUDENTROSTER-COUNT
                 OR ST-GRADE OF ROSTER(I) > WS-STUDENTGRADE
                 OR (ST-GRADE OF ROSTER(I) = WS-STUDENTGRADE AND
                 ST-NAME OF ROSTER(I) > WS-STUDENTNAME)
                      CONTINUE
              END-PERFORM

      *       Shift elements to the right to make room
              PERFORM VARYING J FROM STUDENTROSTER-COUNT BY -1
                 UNTIL J < I
                      MOVE ROSTER(J) TO ROSTER(J + 1)
              END-PERFORM

      *       Insert
              MOVE WS-STUDENTNAME TO ST-NAME OF ROSTER(I)
              MOVE WS-STUDENTGRADE TO ST-GRADE OF ROSTER(I)
              ADD 1 TO STUDENTROSTER-COUNT
           END-IF 
           .


       GET-GRADE.
      *    Advance I to first element of target grade
           PERFORM VARYING I FROM 1 BY 1 UNTIL I >
              STUDENTROSTER-COUNT
              OR ST-GRADE OF ROSTER(I) >= WS-DESIREDGRADE
                   CONTINUE
           END-PERFORM

      *    Shift students of target grade left
           MOVE 1 TO J
           PERFORM UNTIL I > STUDENTROSTER-COUNT
              OR ST-GRADE OF ROSTER(I) > WS-DESIREDGRADE
                   MOVE ROSTER(I) TO ROSTER(J)
                   ADD 1 TO I
                   ADD 1 TO J
           END-PERFORM

      *    And remove remaining students
           MOVE J TO I
           PERFORM UNTIL J > STUDENTROSTER-COUNT
                   INITIALIZE ROSTER(J)
                   ADD 1 TO J
           END-PERFORM
           MOVE I TO STUDENTROSTER-COUNT


           .