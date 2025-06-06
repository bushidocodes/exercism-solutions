import java.time.DayOfWeek;
import java.time.LocalDate;
import java.time.YearMonth;

class Meetup {
    private YearMonth yearMonth;
    
    Meetup(int month, int year){
        this.yearMonth = YearMonth.of(year, month);
    }

    public LocalDate day(DayOfWeek day, MeetupSchedule schedule){
        LocalDate result = this.yearMonth.atDay(1);
        
        switch (schedule) {
            case FIRST -> result = this.yearMonth.atDay(1);
            case SECOND -> result = this.yearMonth.atDay(8);
            case TEENTH -> result = this.yearMonth.atDay(13);
            case THIRD -> result = this.yearMonth.atDay(15);
            case FOURTH -> result = this.yearMonth.atDay(22);
            case LAST -> result = this.yearMonth.atDay(this.yearMonth.lengthOfMonth() - 6);
        }

        while (result.getDayOfWeek() != day){
            result = result.plusDays(1);
        };

        return result;
    }
}