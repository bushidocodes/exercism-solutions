       IDENTIFICATION DIVISION.
       PROGRAM-ID. DIAMOND.
       ENVIRONMENT DIVISION.
       DATA DIVISION.
       WORKING-STORAGE SECTION.
       01 WS-INPUTVARS. 
          05 WS-LETTER    PIC X.
          05 WS-ROWS      PIC 99.
       01 WS-OUTPUTTABLE.
          05 WS-TABLEROW OCCURS 1 TO 51 DEPENDING ON WS-ROWS.
             10 WS-LINE   PIC X(60).
       01 GAP             PIC 99.
       01 I               PIC S99.
       01 J               PIC S99.
       01 PTR             PIC 99.

       PROCEDURE DIVISION.
       DIAMOND.
           COMPUTE GAP = FUNCTION ORD(WS-LETTER) - FUNCTION ORD('A')
           COMPUTE WS-ROWS = 2 *(FUNCTION ORD(WS-LETTER)
              - FUNCTION ORD('A')) + 1

           PERFORM VARYING I FROM 1 BY 1 UNTIL I > WS-ROWS
                   MOVE SPACES TO WS-TABLEROW(I)
                   MOVE 1 TO PTR
                   IF I < GAP + 2
                      PERFORM VARYING J FROM 0 BY 1 UNTIL J + I - 1 =
                         GAP
                              STRING " " DELIMITED BY SIZE
                                 INTO WS-TABLEROW(I) WITH POINTER PTR
                              END-STRING
                      END-PERFORM
                      STRING FUNCTION CHAR(
                         FUNCTION ORD('A') +
                         I - 1) DELIMITED BY SIZE
                         INTO WS-TABLEROW(I) WITH POINTER PTR
                      END-STRING
                      IF I > 1
                         PERFORM VARYING J FROM 0 BY 1
                            UNTIL J =(2 *(I - 1)) - 1
                                 STRING " " DELIMITED BY SIZE
                                    INTO WS-TABLEROW(I) WITH POINTER PTR
                                 END-STRING
                         END-PERFORM
                         STRING FUNCTION CHAR(
                            FUNCTION ORD('A') +
                            I - 1) DELIMITED BY SIZE
                            INTO WS-TABLEROW(I) WITH POINTER PTR
                         END-STRING
                      END-IF
                   ELSE
                      PERFORM VARYING J FROM 0 BY 1 UNTIL J =
                         FUNCTION ABS(GAP - I) - 1
                              STRING " " DELIMITED BY SIZE
                                 INTO WS-TABLEROW(I) WITH POINTER PTR
                              END-STRING
                      END-PERFORM

                      STRING FUNCTION CHAR(
                         FUNCTION ORD('A') + GAP
                         - FUNCTION ABS(GAP - I) + 1)
                         DELIMITED BY SIZE
                         INTO WS-TABLEROW(I) WITH POINTER PTR
                      END-STRING 
                      IF I < WS-ROWS
                         PERFORM VARYING J FROM 0 BY 1 UNTIL J =
                            (WS-ROWS - (2 *(I - GAP)))
                                 STRING " " DELIMITED BY SIZE
                                    INTO WS-TABLEROW(I) WITH POINTER PTR
                                 END-STRING
                         END-PERFORM
                         STRING FUNCTION CHAR(
                            FUNCTION ORD('A') + GAP
                            - FUNCTION ABS(GAP - I) + 1)
                            DELIMITED BY SIZE
                            INTO WS-TABLEROW(I) WITH POINTER PTR
                         END-STRING 
                      END-IF
                   END-IF
           END-PERFORM
           .