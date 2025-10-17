      *================================================================
      * PROGRAM: MEETUP
      * PURPOSE: Calculate meetup dates based on descriptive criteria
      * AUTHOR:  Sean McBride
      * DATE:    10/12/2025
      *
      * DESCRIPTION:
      *   This program calculates the date of meetups based on:
      *   - Year and month
      *   - Week descriptor (first, second, third, fourth, teenth, last)
      *   - Day of week (Monday, Tuesday, etc.)
      *
      *   Examples:
      *   - "first Monday" = 1st Monday of the month
      *   - "teenth Friday" = Friday between 13th-19th of month
      *   - "last Sunday" = last Sunday of the month
      *
      * ALGORITHM:
      *   Uses a day-of-week calculation algorithm based on the formula
      *   from GeeksforGeeks to determine the first day of any month,
      *   then applies search logic to find the target date.
      *================================================================
       IDENTIFICATION DIVISION.
       PROGRAM-ID. MEETUP.
       ENVIRONMENT DIVISION.
       DATA DIVISION.
       WORKING-STORAGE SECTION.
      *----------------------------------------------------------------
      * INPUT/OUTPUT VARIABLES
      *----------------------------------------------------------------
      * Input: Target year (e.g., 2013)
       01 WS-YEAR              PIC 9999.
      * Input: Target month (1-12)
       01 WS-MONTH             PIC 99.
      * Input: Week descriptor 
      * ("first","second", "third", "fourth", "teenth", "last")
       01 WS-WEEK              PIC X(10).
      * Input: Day of week ("Sunday", "Monday", "Tuesday", etc.)
       01 WS-DAYOFWEEK         PIC X(10).
      * Output: Date in YYYY-MM-DD format
       01 WS-RESULT            PIC X(40).
       
      *----------------------------------------------------------------
      * WORKING VARIABLES
      *----------------------------------------------------------------
       01 WS-TEMP-VARS.
      * Number of days in the target month (28-31)
          05 WS-DAYS-IN-MONTH  PIC 99.
      * Final calculated day of the meetup (1-31)
          05 WS-TARGET-DAY     PIC 99.
      * Numeric representation of target weekday (0=Sun, 1=Mon.., 6=Sat)
          05 WS-DAY-NUM        PIC 9.
      * Day of week for the 1st of the month (0=Sun, 1=Mon, ..., 6=Sat)
          05 WS-FIRST-DAY-NUM  PIC 9.
      * Loop variable for iterating through dates
          05 WS-TEMP-DATE      PIC 99.
      * Start of week range for "teenth" searches (13)
          05 WS-WEEK-START     PIC 99.
      * End of week range for "teenth" searches (19)
          05 WS-WEEK-END       PIC 99.
      * General purpose calculation variable
          05 WS-TEMP-CALC      PIC S999.
      * Secondary calculation variable for nth occurrence counting
          05 WS-TEMP-CALC2     PIC 99.
      * Day of week for current date being checked (0-6)
          05 WS-DATE-DOW       PIC 9.
      * Adjusted year for day-of-week calculation
          05 WS-TEMP-YEAR      PIC 9999.
      * Month value for calculations
          05 WS-TEMP-MONTH     PIC 99.
      * Month value for result formatting
          05 WS-RESULT-MONTH   PIC 99.
      * Day value for result formatting  
          05 WS-RESULT-DAY     PIC 99.
      * Unused variable (kept for compatibility)
          05 WS-CURRENT-DATE   PIC 99.
      * Unused variable (kept for compatibility)
          05 WS-CURRENT-DOW    PIC 9.
      * Lookup table value for day-of-week calculation
          05 WS-TABLE-VALUE    PIC 99.
       
      *----------------------------------------------------------------
      * LOOKUP TABLES FOR DAY-OF-WEEK CALCULATION
      *----------------------------------------------------------------
      * Month offset table for day-of-week algorithm
      * Based on algorithm from GeeksforGeeks
      * Values: Jan=0, Feb=3, Mar=2, Apr=5, May=0, Jun=3,
      *         Jul=5, Aug=1, Sep=4, Oct=6, Nov=2, Dec=4
       01 WS-MONTH-TABLE.
      * January
          05 FILLER            PIC 99    VALUE 0.
      * February  
          05 FILLER            PIC 99    VALUE 3.
      * March
          05 FILLER            PIC 99    VALUE 2.
      * April
          05 FILLER            PIC 99    VALUE 5.
      * May
          05 FILLER            PIC 99    VALUE 0.
      * June
          05 FILLER            PIC 99    VALUE 3.
      * July
          05 FILLER            PIC 99    VALUE 5.
      * August
          05 FILLER            PIC 99    VALUE 1.
      * September
          05 FILLER            PIC 99    VALUE 4.
      * October
          05 FILLER            PIC 99    VALUE 6.
      * November
          05 FILLER            PIC 99    VALUE 2.
      * December
          05 FILLER            PIC 99    VALUE 4.
       01 WS-MONTH-ARRAY REDEFINES WS-MONTH-TABLE.
          05 WS-MONTH-VALUES   PIC 99 OCCURS 12 TIMES.

       PROCEDURE DIVISION.

      *================================================================
      * MAIN PROCEDURE - MEETUP DATE CALCULATION
      *================================================================
      * Controls the overall flow of the meetup date calculation:
      * 1. Convert day name to numeric value
      * 2. Calculate what day of week the 1st of the month falls on
      * 3. Determine number of days in the target month
      * 4. Find the specific meetup date based on week descriptor
      * 5. Format the result as YYYY-MM-DD
      *================================================================
       MEETUP.
           PERFORM GET-TARGET-DAY-NUMBER
           PERFORM GET-FIRST-DAY-OF-MONTH
           PERFORM GET-DAYS-IN-MONTH
           PERFORM CALCULATE-MEETUP-DATE
           PERFORM FORMAT-RESULT
           EXIT PARAGRAPH.
           
      *================================================================
      * CONVERT DAY NAME TO NUMERIC VALUE
      *================================================================
      * Converts the input day name (e.g., "Monday") to a numeric
      * representation where Sunday=0, Monday=1, ..., Saturday=6.
      * This numeric value is used in day-of-week calculations.
      *================================================================
       GET-TARGET-DAY-NUMBER.
           EVALUATE WS-DAYOFWEEK
           WHEN "Sunday"
                MOVE 0 TO WS-DAY-NUM
           WHEN "Monday"
                MOVE 1 TO WS-DAY-NUM
           WHEN "Tuesday"
                MOVE 2 TO WS-DAY-NUM
           WHEN "Wednesday"
                MOVE 3 TO WS-DAY-NUM
           WHEN "Thursday"
                MOVE 4 TO WS-DAY-NUM
           WHEN "Friday"
                MOVE 5 TO WS-DAY-NUM
           WHEN "Saturday"
                MOVE 6 TO WS-DAY-NUM
           END-EVALUATE
           EXIT PARAGRAPH.
           
      *================================================================
      * CALCULATE FIRST DAY OF MONTH
      *================================================================
      * Uses the day-of-week algorithm from GeeksforGeeks to determine
      * what day of the week the 1st of the target month falls on.
      * 
      * Algorithm: (y + y/4 - y/100 + y/400 + t[m-1] + d) % 7
      * where:
      *   - y = year (adjusted for Jan/Feb)
      *   - t = month offset table {0,3,2,5,0,3,5,1,4,6,2,4}
      *   - d = day of month (1 for first day)
      *   - Result: 0=Sunday, 1=Monday, ..., 6=Saturday
      *
      * Special handling: For January and February, the year is
      * decremented by 1 as part of the algorithm.
      *================================================================
       GET-FIRST-DAY-OF-MONTH.
           
           MOVE WS-YEAR TO WS-TEMP-YEAR
           MOVE WS-MONTH TO WS-TEMP-MONTH
           
      * Step 1: Adjust year for January/February per algorithm rules
           IF WS-TEMP-MONTH < 3
              SUBTRACT 1 FROM WS-TEMP-YEAR
           END-IF
           
      * Step 2: Get month offset value from lookup table
           MOVE WS-MONTH-VALUES(WS-TEMP-MONTH) TO WS-TABLE-VALUE
           
      * Step 3: Apply the day-of-week formula
      * Formula: (y + y/4 - y/100 + y/400 + t[m-1] + 1) % 7
      * Start with the year
           MOVE WS-TEMP-YEAR TO WS-TEMP-CALC
      * Add leap year adjustments: y/4
           DIVIDE WS-TEMP-YEAR BY 4 GIVING WS-TEMP-CALC2
           ADD WS-TEMP-CALC2 TO WS-TEMP-CALC
      * Subtract century adjustments: y/100
           DIVIDE WS-TEMP-YEAR BY 100 GIVING WS-TEMP-CALC2
           SUBTRACT WS-TEMP-CALC2 FROM WS-TEMP-CALC
      * Add 400-year cycle adjustments: y/400
           DIVIDE WS-TEMP-YEAR BY 400 GIVING WS-TEMP-CALC2
           ADD WS-TEMP-CALC2 TO WS-TEMP-CALC
      * Add month offset from lookup table
           ADD WS-TABLE-VALUE TO WS-TEMP-CALC
      * Add day (1 for first of month)
           ADD 1 TO WS-TEMP-CALC
           
      * Step 4: Handle negative results by adding multiples of 7
           PERFORM UNTIL WS-TEMP-CALC >= 0
                   ADD 7 TO WS-TEMP-CALC
           END-PERFORM
           
      * Step 5: Get final day-of-week (0-6) and adjust for our numbering 
      * system
           COMPUTE WS-FIRST-DAY-NUM = FUNCTION MOD(WS-TEMP-CALC, 7) + 1

           IF WS-FIRST-DAY-NUM = 7
              MOVE 0 TO WS-FIRST-DAY-NUM
           END-IF
           
           EXIT PARAGRAPH.
           
      *================================================================
      * CALCULATE DAYS IN MONTH
      *================================================================
      * Determines the number of days in the target month, accounting
      * for leap years in February. Uses standard calendar rules:
      * - Leap year: divisible by 4, except centuries divisible by 400
      * - February: 28 days (29 in leap years)
      * - April, June, September, November: 30 days
      * - All other months: 31 days
      *================================================================
       GET-DAYS-IN-MONTH.
           EVALUATE WS-MONTH
           WHEN 1
                MOVE 31 TO WS-DAYS-IN-MONTH
           WHEN 2
      * February: Check for leap year
      * Leap year: divisible by 4, except centuries divisible by 400
                IF FUNCTION MOD(WS-YEAR, 4) = 0 AND
                   (FUNCTION MOD(WS-YEAR, 100) NOT = 0 OR
                   FUNCTION MOD(WS-YEAR, 400) = 0)
                   MOVE 29 TO WS-DAYS-IN-MONTH
                ELSE
                   MOVE 28 TO WS-DAYS-IN-MONTH
                END-IF
           WHEN 3
                MOVE 31 TO WS-DAYS-IN-MONTH
           WHEN 4
                MOVE 30 TO WS-DAYS-IN-MONTH
           WHEN 5
                MOVE 31 TO WS-DAYS-IN-MONTH
           WHEN 6
                MOVE 30 TO WS-DAYS-IN-MONTH
           WHEN 7
                MOVE 31 TO WS-DAYS-IN-MONTH
           WHEN 8
                MOVE 31 TO WS-DAYS-IN-MONTH
           WHEN 9
                MOVE 30 TO WS-DAYS-IN-MONTH
           WHEN 10
                MOVE 31 TO WS-DAYS-IN-MONTH
           WHEN 11
                MOVE 30 TO WS-DAYS-IN-MONTH
           WHEN 12
                MOVE 31 TO WS-DAYS-IN-MONTH
           END-EVALUATE
           EXIT PARAGRAPH.
           
      *================================================================
      * CALCULATE MEETUP DATE BASED ON WEEK DESCRIPTOR
      *================================================================
      * Routes to the search method based on week descriptor:
      * - "first", "second", "third", "fourth": Find nth occurrence
      * - "teenth": Find occurrence between 13th-19th of month  
      * - "last": Find last occurrence in month
      *================================================================
       CALCULATE-MEETUP-DATE.
           EVALUATE WS-WEEK
           WHEN "first"
                MOVE 1 TO WS-TEMP-CALC
                PERFORM FIND-NTH-OCCURRENCE
           WHEN "second"
                MOVE 2 TO WS-TEMP-CALC
                PERFORM FIND-NTH-OCCURRENCE
           WHEN "third"
                MOVE 3 TO WS-TEMP-CALC
                PERFORM FIND-NTH-OCCURRENCE
           WHEN "fourth"
                MOVE 4 TO WS-TEMP-CALC
                PERFORM FIND-NTH-OCCURRENCE
           WHEN "teenth"
                MOVE 13 TO WS-WEEK-START
                MOVE 19 TO WS-WEEK-END
                PERFORM FIND-DAY-IN-WEEK-RANGE
           WHEN "last"
                PERFORM FIND-LAST-OCCURRENCE
                EXIT PARAGRAPH
           END-EVALUATE
           EXIT PARAGRAPH.
           
      *================================================================
      * FIND DAY IN SPECIFIC WEEK RANGE (FOR "TEENTH")
      *================================================================
      * Searches for the target weekday within a specific date range.
      * Used specifically for "teenth" which looks between the 13th 
      * and 19th of the month (the only week where all dates end in 
      * "teen").
      * 
      * Input: WS-WEEK-START and WS-WEEK-END define the search range
      * Output: WS-TARGET-DAY contains the found date
      *================================================================
       FIND-DAY-IN-WEEK-RANGE.
           PERFORM VARYING WS-TEMP-DATE FROM WS-WEEK-START BY 1
              UNTIL WS-TEMP-DATE > WS-WEEK-END
      * Calculate what day of week this date falls on
                   COMPUTE WS-DATE-DOW = FUNCTION MOD(
                      WS-FIRST-DAY-NUM + WS-TEMP-DATE - 1, 7)
      * If this matches our target weekday, we found our date
                   IF WS-DATE-DOW = WS-DAY-NUM
                      MOVE WS-TEMP-DATE TO WS-TARGET-DAY
                      EXIT PERFORM
                   END-IF
           END-PERFORM
           EXIT PARAGRAPH.
           
      *================================================================
      * FIND NTH OCCURRENCE OF WEEKDAY
      *================================================================
      * Finds the nth occurrence of the target weekday in the month.
      * For example, "second Tuesday" finds the 2nd Tuesday.
      * 
      * Method: Iterates through all days of the month, counting
      * occurrences of the target weekday until reaching the nth one.
      * 
      * Input: WS-TEMP-CALC contains which occurrence to find (1-4)
      * Output: WS-TARGET-DAY contains the found date
      *================================================================
       FIND-NTH-OCCURRENCE.
      * Initialize occurrence counter and start from first day
           MOVE 0 TO WS-TEMP-CALC2
           MOVE 1 TO WS-TEMP-DATE
           PERFORM UNTIL WS-TEMP-DATE > WS-DAYS-IN-MONTH
      * Calculate what day of week this date falls on
                   COMPUTE WS-DATE-DOW = FUNCTION MOD(
                      WS-FIRST-DAY-NUM + WS-TEMP-DATE - 1, 7)
      * If this matches our target weekday, increment counter
                   IF WS-DATE-DOW = WS-DAY-NUM
                      ADD 1 TO WS-TEMP-CALC2
      * If we've reached the desired occurrence, we found our date
                      IF WS-TEMP-CALC2 = WS-TEMP-CALC
                         MOVE WS-TEMP-DATE TO WS-TARGET-DAY
                         EXIT PERFORM
                      END-IF
                   END-IF
                   ADD 1 TO WS-TEMP-DATE
           END-PERFORM
           EXIT PARAGRAPH.
           
      *================================================================
      * FIND LAST OCCURRENCE OF WEEKDAY
      *================================================================
      * Finds the last occurrence of the target weekday in the month.
      * For example, "last Monday" finds the final Monday of the month.
      * 
      * Method: Starts from the end of the month and works backwards
      * until finding the first occurrence of the target weekday.
      * 
      * Output: WS-TARGET-DAY contains the found date
      *================================================================
       FIND-LAST-OCCURRENCE.
      * Start from last day of month and work backwards
           PERFORM VARYING WS-TEMP-DATE FROM WS-DAYS-IN-MONTH BY -1
              UNTIL WS-TEMP-DATE < 1
      * Calculate what day of week this date falls on
                   COMPUTE WS-DATE-DOW = FUNCTION MOD(
                      WS-FIRST-DAY-NUM + WS-TEMP-DATE - 1, 7)
      * If this matches our target weekday, we found the last occurrence
                   IF WS-DATE-DOW = WS-DAY-NUM
                      MOVE WS-TEMP-DATE TO WS-TARGET-DAY
                      EXIT PERFORM
                   END-IF
           END-PERFORM
           EXIT PARAGRAPH.
           
      *================================================================
      * FORMAT RESULT AS YYYY-MM-DD
      *================================================================
      * Formats the calculated meetup date into ISO date format
      * (YYYY-MM-DD).
      * Handles edge case where no valid date was found by using 99 as
      * an error indicator.
      * 
      * Input: WS-YEAR, WS-MONTH, WS-TARGET-DAY
      * Output: WS-RESULT contains formatted date string
      *================================================================
       FORMAT-RESULT.
      * Handle edge case where no valid date was found
           IF WS-TARGET-DAY = 0
              MOVE 99 TO WS-TARGET-DAY
           END-IF
           
      * Copy values to formatting variables to preserve originals
           MOVE WS-MONTH TO WS-RESULT-MONTH
           MOVE WS-TARGET-DAY TO WS-RESULT-DAY
           
      * Construct ISO date format: YYYY-MM-DD with zero padding
           STRING WS-YEAR DELIMITED BY SIZE
                  "-" DELIMITED BY SIZE
                  WS-RESULT-MONTH(1:2) DELIMITED BY SIZE
                  "-" DELIMITED BY SIZE
                  WS-RESULT-DAY(1:2) DELIMITED BY SIZE
              INTO WS-RESULT
           
           EXIT PARAGRAPH.

      *================================================================
      * END OF PROGRAM
      *================================================================
      * ALGORITHM SUMMARY:
      * 
      * This program successfully calculates meetup dates using a 
      * combination of:
      * 
      * 1. DAY-OF-WEEK CALCULATION: Uses a well-established mathematical
      *    algorithm (from GeeksforGeeks) with a lookup table to 
      *    determine what day of the week any date falls on. This 
      *    replaces complex date libraries with pure arithmetic.
      *
      * 2. SEARCH STRATEGIES: Three different approaches depending on
      *    the week descriptor:
      *    - Nth occurrence: Count instances of target weekday
      *    - Teenth: Search within days 13-19 (has "teen" suffix)  
      *    - Last: Reverse search from end of month
      *
      * 3. CALENDAR LOGIC: Proper handling of leap years and varying
      *    month lengths using standard calendar rules.
      *
      * The solution is fully algorithmic with no hardcoded date tables,
      * making it maintainable and extensible for any year.
      *================================================================