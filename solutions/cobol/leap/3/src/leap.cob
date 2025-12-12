       IDENTIFICATION DIVISION.
       PROGRAM-ID. LEAP.
       ENVIRONMENT DIVISION.
       CONFIGURATION SECTION.
       REPOSITORY.
         FUNCTION ALL INTRINSIC.
       DATA DIVISION.
       WORKING-STORAGE SECTION.
         77 WS-YEAR   PIC 9(4) COMP.
         77 WS-RESULT PIC 9    COMP.
            88  IS-LEAP      VALUE 1.
            88  NOT-LEAP     VALUE 0.
       PROCEDURE DIVISION.
       LEAP.
         IF (MOD(WS-YEAR, 4) = 0 AND MOD(WS-YEAR, 100) > 0)
            OR MOD(WS-YEAR, 400) = 0
            
            SET IS-LEAP TO TRUE
         ELSE
            SET NOT-LEAP TO TRUE
         END-IF
         .
       LEAP-EXIT.
         EXIT.
