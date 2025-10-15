       IDENTIFICATION DIVISION.
       PROGRAM-ID. NUCLEOTIDE-COUNT.
       ENVIRONMENT DIVISION.
       CONFIGURATION SECTION.
       REPOSITORY. FUNCTION ALL INTRINSIC.
       DATA DIVISION.
       WORKING-STORAGE SECTION.
       01 WS-DNA    PIC X(128).
       01 WS-A      PIC 9(4).
       01 WS-C      PIC 9(4).
       01 WS-G      PIC 9(4).
       01 WS-T      PIC 9(4).
       01 WS-ERROR  PIC X(36).

       77 I         PIC 9(3)   VALUE 1.
       77 LEN       PIC 9(3).

       PROCEDURE DIVISION.
       NUCLEOTIDE-COUNT.
           INITIALIZE WS-A 
           INITIALIZE WS-C 
           INITIALIZE WS-G 
           INITIALIZE WS-T 
           INITIALIZE WS-ERROR 

           MOVE FUNCTION UPPER-CASE(WS-DNA) TO WS-DNA 
           COMPUTE LEN = FUNCTION LENGTH(FUNCTION TRIM(WS-DNA))
           
           PERFORM VARYING I FROM 1 BY 1 UNTIL I > LEN
                   EVALUATE WS-DNA(I:1)
                   WHEN 'A'
                        ADD 1 TO WS-A
                   WHEN 'C'
                        ADD 1 TO WS-C
                   WHEN 'G'
                        ADD 1 TO WS-G
                   WHEN 'T'
                        ADD 1 TO WS-T
                   WHEN OTHER
                        MOVE "ERROR: Invalid nucleotide in strand" TO
                           WS-ERROR
                        EXIT PERFORM
                   END-EVALUATE
           END-PERFORM
           .